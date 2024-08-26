#include "type_traits.h"
#include <iostream>
#include <string>
#include <type_traits>

int main() {
    std::cout << std::boolalpha;

    // Testing integral_constant, true_type, and false_type
    std::cout << "integral_constant test: " << tt::integral_constant<int, 42>::value << std::endl;
    std::cout << "true_type test: " << tt::true_type::value << std::endl;
    std::cout << "false_type test: " << tt::false_type::value << std::endl;

    // Testing is_same
    std::cout << "is_same<int, int>: " << tt::is_same<int, int>::value << std::endl;  // true
    std::cout << "is_same<int, float>: " << tt::is_same<int, float>::value << std::endl;  // false

    // Testing is_const
    std::cout << "is_const<const int>: " << tt::is_const<const int>::value << std::endl;  // true
    std::cout << "is_const<int>: " << tt::is_const<int>::value << std::endl;  // false

    // Testing remove_const
    std::cout << "remove_const<const int>: " << std::is_same<int, tt::remove_const<const int>::type>::value << std::endl;  // true

    // Testing is_integral
    std::cout << "is_integral<int>: " << tt::is_integral<int>::value << std::endl;  // true
    std::cout << "is_integral<float>: " << tt::is_integral<float>::value << std::endl;  // false

    // Testing is_floating_point
    std::cout << "is_floating_point<float>: " << tt::is_floating_point<float>::value << std::endl;  // true
    std::cout << "is_floating_point<int>: " << tt::is_floating_point<int>::value << std::endl;  // false

    // Testing is_pointer
    std::cout << "is_pointer<int*>: " << tt::is_pointer<int*>::value << std::endl;  // true
    std::cout << "is_pointer<int>: " << tt::is_pointer<int>::value << std::endl;  // false

    // Testing is_reference
    std::cout << "is_reference<int&>: " << tt::is_reference<int&>::value << std::endl;  // true
    std::cout << "is_reference<int>: " << tt::is_reference<int>::value << std::endl;  // false

    // Testing is_array
    std::cout << "is_array<int[]>: " << tt::is_array<int[]>::value << std::endl;  // true
    std::cout << "is_array<int[10]>: " << tt::is_array<int[10]>::value << std::endl;  // true
    std::cout << "is_array<int>: " << tt::is_array<int>::value << std::endl;  // false

    // Testing is_function
    std::cout << "is_function<void(int) noexcept>: " << tt::is_function<void(int) noexcept>::value << std::endl;  // true
    std::cout << "is_function<int>: " << tt::is_function<int>::value << std::endl;  // false

    // Testing is_class
    std::cout << "is_class<std::string>: " << tt::is_class<std::string>::value << std::endl;  // true
    std::cout << "is_class<int>: " << tt::is_class<int>::value << std::endl;  // false

    // Testing is_union
    union U { int a; float b; };
    std::cout << "is_union<U>: " << tt::is_union<U>::value << std::endl;  // true
    std::cout << "is_union<int>: " << tt::is_union<int>::value << std::endl;  // false

    // Testing is_enum
    enum E { A, B, C };
    std::cout << "is_enum<E>: " << tt::is_enum<E>::value << std::endl;  // true
    std::cout << "is_enum<int>: " << tt::is_enum<int>::value << std::endl;  // false

    // Testing is_lvalue_reference and is_rvalue_reference
    std::cout << "is_lvalue_reference<int&>: " << tt::is_lvalue_reference<int&>::value << std::endl;  // true
    std::cout << "is_rvalue_reference<int&&>: " << tt::is_rvalue_reference<int&&>::value << std::endl;  // true

    // Testing is_void
    std::cout << "is_void<void>: " << tt::is_void<void>::value << std::endl;  // true
    std::cout << "is_void<int>: " << tt::is_void<int>::value << std::endl;  // false

    // Testing is_null_pointer
    std::cout << "is_null_pointer<std::nullptr_t>: " << tt::is_null_pointer<std::nullptr_t>::value << std::endl;  // true
    std::cout << "is_null_pointer<int>: " << tt::is_null_pointer<int>::value << std::endl;  // false

    // Testing is_member_pointer
    struct S { int x; void func() {}; };
    std::cout << "is_member_pointer<int S::*>: " << tt::is_member_pointer<int S::*>::value << std::endl;  // true
    std::cout << "is_member_pointer<void(S::*)()>: " << tt::is_member_pointer<void(S::*)()>::value << std::endl;  // true
    std::cout << "is_member_pointer<int>: " << tt::is_member_pointer<int>::value << std::endl;  // false

    // Testing is_member_function_pointer
    std::cout << "is_member_function_pointer<void(S::*)()>: " << tt::is_member_function_pointer<void(S::*)()>::value << std::endl;  // true
    std::cout << "is_member_function_pointer<int S::*>: " << tt::is_member_function_pointer<int S::*>::value << std::endl;  // false

    // Testing is_signed and is_unsigned
    std::cout << "is_signed<int>: " << tt::is_signed<int>::value << std::endl;  // true
    std::cout << "is_unsigned<unsigned int>: " << tt::is_unsigned<unsigned int>::value << std::endl;  // true

    // Testing is_bounded_array and is_unbounded_array
    std::cout << "is_bounded_array<int[10]>: " << tt::is_bounded_array<int[10]>::value << std::endl;  // true
    std::cout << "is_unbounded_array<int[]>: " << tt::is_unbounded_array<int[]>::value << std::endl;  // true

    // Testing add_cv, add_const, and add_volatile
    std::cout << "add_const<int>: " << std::is_same<const int, typename tt::add_const<int>::type>::value << std::endl;  // true
    std::cout << "add_volatile<int>: " << std::is_same<volatile int, typename tt::add_volatile<int>::type>::value << std::endl;  // true
    std::cout << "add_cv<int>: " << std::is_same<const volatile int, typename tt::add_cv<int>::type>::value << std::endl;  // true

    // Testing remove_reference
    std::cout << "remove_reference<int&>: " << std::is_same<int, typename tt::remove_reference<int&>::type>::value << std::endl;  // true
    std::cout << "remove_reference<int&&>: " << std::is_same<int, typename tt::remove_reference<int&&>::type>::value << std::endl;  // true

    // Testing remove_pointer
    std::cout << "remove_pointer<int*>: " << std::is_same<int, typename tt::remove_pointer<int*>::type>::value << std::endl;  // true
    std::cout << "remove_pointer<int* const>: " << std::is_same<int, typename tt::remove_pointer<int* const>::type>::value << std::endl;  // true

    // Testing enable_if
    std::cout << "enable_if<true, int>::type: " << std::is_same<int, typename tt::enable_if<true, int>::type>::value << std::endl;  // true

    // Testing is_empty
    struct Empty {};
    struct NonEmpty { int x; };
    std::cout << "is_empty<Empty>: " << tt::is_empty<Empty>::value << std::endl;  // true
    std::cout << "is_empty<NonEmpty>: " << tt::is_empty<NonEmpty>::value << std::endl;  // false

    return 0;
}
