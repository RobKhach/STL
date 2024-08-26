#ifndef TYPE_TRAITS_H
#define TYPE_TRAITS_H

#include <iostream>
#include <type_traits>

namespace tt{

template <typename T, T v>
struct integral_constant{
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant;
    constexpr operator value_type() const noexcept { return value; }
    constexpr value_type operator()() const noexcept {return value; }
};

template <bool B>
using bool_constant = integral_constant<bool,B>;

using false_type = integral_constant<bool,false>;
using true_type = integral_constant<bool,true>;


template <typename T, typename U>
struct is_same : false_type{};

template <typename T>
struct is_same<T,T> : true_type{};

template <typename T>
struct is_const : false_type{};

template <typename T>
struct is_const<const T> : true_type{};

template <typename T>
struct remove_const{
    using type = T;
};

template <typename T>
struct remove_const<const T>{
    using type = T;
};

template<bool B, typename T, typename F>
struct conditional{
    using type = T;
};

template <typename T, typename F>
struct conditional<false,T,F>{
    using type = F;
};

template <typename T>
struct is_integral : false_type{};

template <>
struct is_integral<char> : true_type{};

template <>
struct is_integral<signed char> : true_type{};

template <>
struct is_integral<unsigned char> : true_type{};

template <>
struct is_integral<short int> : true_type{};

template <>
struct is_integral<unsigned short int> : true_type{};

template <>
struct is_integral<int> : true_type{};

template <>
struct is_integral<unsigned int> : true_type{};

template <>
struct is_integral<long int> : true_type{};

template <>
struct is_integral<unsigned long int> : true_type{};

template <>
struct is_integral<long long int> : true_type {};

template <>
struct is_integral<unsigned long long int> : true_type {};

template <>
struct is_integral<wchar_t> : true_type {};

template <>
struct is_integral<char16_t> : true_type {};

template <>
struct is_integral<char32_t> : true_type {};

template <>
struct is_integral<bool> : true_type {};

template <>
struct is_integral<std::byte> : true_type {};

template <typename T>
struct is_floating_point : false_type{};

template <>
struct is_floating_point<float> : true_type{};

template <>
struct is_floating_point<double> : true_type{};

template <>
struct is_floating_point<long double> : true_type{};

template <typename T>
struct is_pointer : false_type{};

template <typename T>
struct is_pointer<T*> : true_type{};

template <typename T>
struct is_reference : false_type{};

template <typename T>
struct is_reference<T&> : true_type{};

template <typename T>
struct is_reference<T&&> : true_type{};

template <typename T>
struct is_array : false_type{};

template <typename T>
struct is_array<T[]> : true_type{};

template <typename T , std::size_t N>
struct is_array<T[N]> : true_type{};

template<class>
struct is_function : false_type {};

template <typename Ret, typename... Args>
struct is_function<Ret (*)(Args...)> : false_type {};

template <typename Ret, typename... Args>
struct is_function<Ret (*)(Args..., ...)> : false_type {};
 
template<class Ret, class... Args>
struct is_function<Ret(Args...)> : true_type {};
 
template<class Ret, class... Args>
struct is_function<Ret(Args...,...)> : true_type {};
 
template<class Ret, class... Args>
struct is_function<Ret(Args...) const> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) volatile> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const volatile> : true_type {};
 
template<class Ret, class... Args>
struct is_function<Ret(Args...) &> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const &> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile &> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile &> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) &> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const &> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) volatile &> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const volatile &> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) &&> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const &&> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile &&> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile &&> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) &&> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const &&> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) volatile &&> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const volatile &&> : true_type {};
 
template<class Ret, class... Args>
struct is_function<Ret(Args...) noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) volatile noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const volatile noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) & noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const & noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile & noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile & noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) & noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const & noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) volatile & noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const volatile & noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) && noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const && noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile && noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile && noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) && noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const && noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) volatile && noexcept> : true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...,...) const volatile && noexcept> : true_type {};


template <typename T>
struct is_class : integral_constant<bool, __is_class(T)> {};

template <typename T>
struct is_union : integral_constant<bool, __is_union(T)> {};

template <typename T>
struct is_enum : integral_constant<bool,  __is_enum(T)>{};

template <typename T>
struct is_lvalue_reference : false_type{};

template <typename T>
struct is_lvalue_reference<T&> : true_type{};

template <typename T>
struct is_rvalue_reference : false_type{};

template <typename T>
struct is_rvalue_reference<T&&> : true_type{};

template<class T> struct remove_volatile { typedef T type; };
template<class T> struct remove_volatile<volatile T> { typedef T type; };

template<class T> struct remove_cv { typedef T type; };
template<class T> struct remove_cv<const T> { typedef T type; };
template<class T> struct remove_cv<volatile T> { typedef T type; };
template<class T> struct remove_cv<const volatile T> { typedef T type; };

template <typename T>
struct is_void : integral_constant<bool, is_same<void, typename remove_cv<T>::type>::value>{};

template <typename T>
struct is_null_pointer : integral_constant<bool, is_same<std::nullptr_t , typename remove_cv<T>::type>::value>{};

template <class T>
struct is_member_pointer_helper : false_type{};

template<class T, class U>
struct is_member_pointer_helper<T U::*> : true_type {};

template<class T>
struct is_member_pointer : is_member_pointer_helper<typename remove_cv<T>::type> {};

template <class T>
struct is_member_function_pointer_helper : false_type{};

template <class T, class U>
struct is_member_function_pointer_helper<T U::*> : is_function<T>{};

template<class T>
struct is_member_function_pointer 
    : is_member_function_pointer_helper<typename remove_cv<T>::type> {};

template <typename T>
struct is_member_object_pointer : integral_constant<bool, is_member_pointer<T>::value && ! is_member_function_pointer<T>::value>{};

template <typename T>
struct is_arithmetic : integral_constant<bool, is_integral<T>::value || is_floating_point<T>::value>{};

template <typename T>
struct is_fundamental : integral_constant<bool, is_arithmetic<T>::value || is_void<T>::value || is_same<std::nullptr_t, typename remove_cv<T>::type>::value>{};

template <typename T>
struct is_scalar : integral_constant<bool, is_arithmetic<T>::value || is_enum<T>::value || is_pointer<T>::value || is_member_pointer<T>::value || is_null_pointer<T>::value>{};

template <typename T>
struct is_object : integral_constant<bool, is_scalar<T>::value || is_array<T>::value || is_class<T>::value || is_union<T>::value>{};

template <typename T>
struct is_compound : integral_constant<bool, !is_fundamental<T>::value>{};

template <typename T>
struct is_volatile : false_type{};

template <typename T>
struct is_volatile<volatile T> : true_type{};

namespace polymorphic{
    template<class T>
    true_type detect_is_polymorphic(
        decltype(dynamic_cast<const volatile void*>(static_cast<T*>(nullptr)))
    );
    template<class T>
    false_type detect_is_polymorphic(...);
};
 
template<class T>
struct is_polymorphic : decltype(polymorphic::detect_is_polymorphic<T>(nullptr)) {};


namespace tt_signed{

    template<typename T, bool = is_arithmetic<T>::value>
    struct signed_num : integral_constant<bool, (T(-1) < T(0))>{};

    template <typename T>
    struct signed_num<T,false> : false_type{};
};

template <typename T>
struct is_signed : tt_signed::signed_num<T> {};

namespace tt_unsigned{

    template<typename T, bool = is_arithmetic<T>::value>
    struct unsigned_num : integral_constant<bool, (T(-1) > T(0))> {};

    template <typename T>
    struct unsigned_num<T,false> : false_type{};
};

template <typename T>
struct is_unsigned : tt_unsigned::unsigned_num<T> {};

template<class T>
struct is_bounded_array : false_type {};
 
template<class T, std::size_t N>
struct is_bounded_array<T[N]> : true_type {};

template<class T>
struct is_unbounded_array: false_type {};
 
template<class T>
struct is_unbounded_array<T[]> : true_type {};

template <typename T>
struct add_cv { using type = const volatile T;};

template <typename T>
struct add_const { using type = const T;};

template <typename T>
struct add_volatile { using type = volatile T;};

template<class T> struct remove_reference { using type = T; };
template<class T> struct remove_reference<T&> { using type = T; };
template<class T> struct remove_reference<T&&> { using type = T; };

template<class T> struct remove_pointer { using type = T; };
template<class T> struct remove_pointer<T*> { using type = T; };
template<class T> struct remove_pointer<T* const> { using type = T; };
template<class T> struct remove_pointer<T* volatile> { using type = T; };
template<class T> struct remove_pointer<T* const volatile> { using type = T; };

template <typename T>
struct remove_cvref {using type = remove_cv<remove_reference<T>>;};

template <bool b,typename T = void>
struct enable_if{};

template <typename T>
struct enable_if<true, T>{using type = T;};

template <typename T>
struct is_empty{
    struct derived : public T{ char x;};
    static constexpr bool value = (sizeof(derived) == sizeof(char));
};

};


#endif