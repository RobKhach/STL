#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <limits>       
#include <new>          
#include <type_traits>  

template <typename T>
class allocator {
public:
   
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using propagate_on_container_move_assignment = std::true_type;

    constexpr allocator() noexcept = default;
    constexpr allocator(const allocator& other) noexcept = default;
    ~allocator() = default;

    constexpr pointer allocate(size_type n);
    void deallocate(pointer p, size_type n) noexcept;
};

template <typename T>
constexpr typename allocator<T>::pointer allocator<T>::allocate(size_type n) {

    if (n > std::numeric_limits<size_type>::max() / sizeof(T)) {
        throw std::bad_alloc();
    }

    T* ptr = static_cast<T*>(::operator new(n * sizeof(T)));

    return ptr;
}

template <typename T>
void allocator<T>::deallocate(pointer p, size_type n) noexcept {
    ::operator delete(p);
}

#endif