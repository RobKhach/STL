#include <iostream>
#include <type_traits>

// Base classes
class A {
public:
    char name = 'A';
};

class B {
public:
    char name = 'B';
};

class C {
public:
    char name = 'C';
};

// Derived classes
class D : public A {};

class E : public A, public B {};

class F : public C {};

// Template function overloads
template <typename T>
typename std::enable_if<std::is_base_of_v<A, T> && !std::is_base_of_v<B, T> && !std::is_base_of_v<C, T>>::type
foo(T obj) {
    std::cout << "foo with A-derived class: " << obj.name << std::endl;
}

template <typename T>
typename std::enable_if<!std::is_base_of_v<A, T> && std::is_base_of_v<B, T> && !std::is_base_of_v<C, T>>::type
foo(T obj) {
    std::cout << "foo with B-derived class: " << obj.name << std::endl;
}

template <typename T>
typename std::enable_if<!std::is_base_of_v<A, T> && !std::is_base_of_v<B, T> && std::is_base_of_v<C, T>>::type
foo(T obj) {
    std::cout << "foo with C-derived class: " << obj.name << std::endl;
}

int main() {
    D d;
    E e;
    F f;

    foo(e);

    foo(d);  // Should match the first overload: derived from A but not B or C.
    // foo(e);  // This will cause a compilation error because it matches none of the overloads exactly.
    foo(f);  // Should match the third overload: derived from C but not A or B.

    return 0;
}
