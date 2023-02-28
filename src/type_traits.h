#pragma once

#include <iostream>

namespace s21 {
    /************************************************************/
    /*                                                          */
    /*                     HELPER CLASSES                       */
    /*                                                          */
    /************************************************************/

    template <typename T, T val>
    struct integral_constant {
        static const T value = val;
        using value_type = T;
        using type = integral_constant;

        operator bool() const { return value; }
        bool operator()() const { return value; }
    };

    struct true_type : integral_constant<bool, true> {};
    struct false_type : integral_constant<bool, false> {};

    template <typename T1, typename T2> struct is_same;
    template <typename T> struct remove_cv;

    /************************************************************/
    /*                                                          */
    /*                 PRIMARY TYPE CATEGORIES                  */
    /*                                                          */
    /************************************************************/

    /**
     * @brief Checks whether T is a void type.
     * Provides the member constant value that is equal to true,
     * if T is the type void, const void, volatile void, or const volatile void.
     * Otherwise, value is equal to false.
     */
    template <typename T> struct is_void : is_same <void, typename remove_cv<T>::type> {};
    template <typename T> const bool is_void_v = is_void<T>::value;

    /**
     * @brief Provides the member constant value that is equal to true,
     * if T is the type std::nullptr_t,const std::nullptr_t, volatile std::nullptr_t,
     * or const volatile std::nullptr_t. Otherwise, value is equal to false.
     */
    template <typename T> struct is_null_pointer : is_same <std::nullptr_t, typename remove_cv<T>::type> {};
    template <typename T> const bool is_null_pointer_v = is_null_pointer<T>::value;

    /**
     * @brief Checks whether T is an array type.
     * Provides the member constant value which is equal to true,
     * if T is an array type. Otherwise, value is equal to false.
     */
    template <typename T> struct is_array : false_type {};
    template <typename T> struct is_array<T[]> : true_type {};
    template <typename T, std::size_t S> struct is_array<T[S]> : true_type {};
    template <typename T> const bool is_array_v = is_array<T>::value;

    /**
     * @brief checks if a type is an lvalue reference
     */
    template <typename T> struct is_lvalue_reference : false_type {};
    template <typename T> struct is_lvalue_reference<T&> : true_type {};
    template <typename T> const bool is_lvalue_reference_v = is_lvalue_reference<T>::value;

    /**
     * @brief checks if a type is an rvalue reference
     */
    template <typename T> struct is_rvalue_reference : false_type {};
    template <typename T> struct is_rvalue_reference<T&> : true_type {};
    template <typename T> const bool is_rvalue_reference_v = is_rvalue_reference<T>::value;

    /**
     * @brief if T is a const-qualified type (that is, const, or const volatile),
     * provides the member constant value equal to true.
     * For any other type, value is false.
     */
    template <typename T> struct is_const : false_type {};
    template <typename T> struct is_const<const T> : true_type {};
    template <typename T> struct is_const<const volatile T> : true_type {};
    template <typename T> const bool is_const_v = is_const<T>::value;

    /**
     * @brief If T is a volatile-qualified type (that is, volatile, or const volatile),
     * provides the member constant value equal to true.
     * For any other type, value is false.
     */
    template <typename T> struct is_volatile : false_type {};
    template <typename T> struct is_volatile<volatile T> : true_type {};
    template <typename T> struct is_volatile<const volatile T> : true_type {};
    template <typename T> const bool is_volatile_v = is_volatile<T>::value;
   

    /************************************************************/
    /*                                                          */
    /*                    TYPE RELATIONSHIPS                    */
    /*                                                          */
    /************************************************************/

   /**
    * @brief checks if two types are the same
    */
    template <typename T1, typename T2>
    struct is_same {
        static const bool value = false;

        operator bool() { return value; }
        bool operator()() { return value; }
    };

    template <typename T>
    struct is_same<T, T> {
        static const bool value = true;

        operator bool() { return value; }
        bool operator()() { return value; }
    };

    template <typename T1, typename T2> const bool is_same_v = is_same<T1, T2>::value;


    /************************************************************/
    /*                                                          */
    /*                 CONST-VOLATILE SPECIFIERS                */
    /*                                                          */
    /************************************************************/

   /**
    * @brief removes const specifiers from the given type
    */
    template <typename T> struct remove_const { using type = T; };
    template <typename T> struct remove_const<const T> { using type = T; };
    template <typename T> using remove_const_t = typename remove_const<T>::type;

    /**
     * @brief removes volatile specifiers from the given type
     */
    template <typename T> struct remove_volatile { using type = T; };
    template <typename T> struct remove_volatile<volatile T> { using type = T; };
    template <typename T> using remove_volatile_t = typename remove_volatile<T>::type;

    /**
     * @brief removes const and volatile specifiers from the given type
     */
    template <typename T> struct remove_cv { using type = remove_const_t<remove_volatile_t<T>>; };
    template <typename T> using remove_cv_t = typename remove_cv<T>::type;

    /**
     * @brief adds const specifiers to the given type 
     */
    template <typename T> struct add_const { using type = const remove_const_t<T>; };
    template <typename T> using add_const_t = typename add_const<T>::type;

    /**
     * @brief adds volatile specifiers to the given type
     */
    template <typename T> struct add_volatile { using type = volatile remove_volatile_t<T>; };
    template <typename T> using add_volatile_t = typename add_volatile<T>::type;

    /**
     * @brief adds const and volatile specifiers to the given type
     */
    template <typename T> struct add_cv { using type = const volatile remove_cv_t<T>; };
    template <typename T> using add_cv_t = typename add_cv<T>::type;


    /************************************************************/
    /*                                                          */
    /*                        REFERENCES                        */
    /*                                                          */
    /************************************************************/

    /**
     * @brief removes a reference from the given type 
     */
    template <typename T> struct remove_reference { using type = T; };
    template <typename T> struct remove_reference<T&> { using type = T; };
    template <typename T> struct remove_reference<T&&> { using type = T; };
    template <typename T> using remove_reference_t = typename remove_reference<T>::type;

    /**
     * @brief adds an lvalue reference to the given type
     */
    template <typename T> struct add_lvalue_reference { using type = remove_reference_t<T> &; };
    template <typename T> using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

    /**
     * @brief adds an rvalue reference to the given type
     */
    template <typename T> struct add_rvalue_reference { using type = remove_reference_t<T> &&; };
    template <typename T> using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;


    /************************************************************/
    /*                                                          */
    /*                         POINTERS                         */
    /*                                                          */
    /************************************************************/

    /**
     * @brief removes a pointer from the given type
     */
    template <typename T> struct remove_pointer { using type = T; };
    template <typename T> struct remove_pointer<T *> { using type = T; };
    template <typename T> using remove_pointer_t = typename remove_pointer<T>::type;

    /**
     * @brief adds a pointer to the given type
     */
    template <typename T> struct add_pointer { using type = remove_pointer_t<T> *; };
    template <typename T> using add_pointer_t = typename add_pointer<T>::type;
}