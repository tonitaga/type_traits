    #pragma once

namespace s21 {
    /*
    Primary type categories
    */

    //TODO ...
   
    /*
    Type relationships
    */

   /**
    * @brief checks if two types are the same
    */
    template <typename T1, typename T2>
    struct is_same {
        static const bool value = false; 
    };

    template <typename T>
    struct is_same<T, T> {
        static const bool value = true;
    };

    template <typename T1, typename T2>
    const bool is_same_v = is_same<T1, T2>::value;

    /*
    Const-volatility specifiers
    */

   /**
    * @brief removes const specifiers from the given type
    */
    template <typename T>
    struct remove_const {
        using type = T;
    };

    template <typename T>
    struct remove_const<const T> {
        using type = T;
    };

    template <typename T>
    using remove_const_t = typename remove_const<T>::type;

    /**
     * @brief removes volatile specifiers from the given type
     */
    template <typename T>
    struct remove_volatile {
        using type = T;
    };

    template <typename T>
    struct remove_volatile<volatile T> {
        using type = T;
    };

    template <typename T>
    using remove_volatile_t = typename remove_volatile<T>::type;

    /**
     * @brief removes const and volatile specifiers from the given type
     */
    template <typename T>
    struct remove_cv {
        using type = T;
    };

    template <typename T>
    struct remove_cv<const volatile T> {
        using type = T;
    };

    template <typename T>
    using remove_cv_t = typename remove_cv<T>::type;

    /**
     * @brief adds const specifiers to the given type 
     */
    template <typename T>
    struct add_const {
        using type = const remove_const_t<T>; 
    };

    template <typename T>
    using add_const_t = typename add_const<T>::type;

    /**
     * @brief adds volatile specifiers to the given type
     */
    template <typename T>
    struct add_volatile {
        using type = volatile remove_volatile_t<T>;
    };

    template <typename T>
    using add_volatile_t = typename add_volatile<T>::type;

    /**
     * @brief adds const and volatile specifiers to the given type
     */
    template <typename T>
    struct add_cv {
        using type = const volatile remove_cv_t<T>;
    };

    template <typename T>
    using add_cv_t = typename add_cv<T>::type;

    /*
    References
    */

    /**
     * @brief removes a reference from the given type 
     */
    template <typename T>
    struct remove_reference {
        using type = T;
    };

    template <typename T>
    struct remove_reference<T&> {
        using type = T;
    };

    template <typename T>
    using remove_reference_t = typename remove_reference<T>::type;

    /**
     * @brief adds an lvalue reference to the given type
     */
    template <typename T>
    struct add_lvalue_reference {
        using type = remove_reference_t<T> &;
    };

    template <typename T>
    using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

    /**
     * @brief adds an rvalue reference to the given type
     */
    template <typename T>
    struct add_rvalue_reference {
        using type = remove_reference_t<T> &&;
    };

    template <typename T>
    using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

    /*
    Pointers
    */

    /**
     * @brief removes a pointer from the given type
     */
    template <typename T>
    struct remove_pointer {
        using type = T;
    };

    template <typename T>
    struct remove_pointer<T *> {
        using type = T;
    };

    template <typename T>
    using remove_pointer_t = typename remove_pointer<T>::type;

    /**
     * @brief adds a pointer to the given type
     */
    template <typename T>
    struct add_pointer {
        using type = remove_pointer_t<T> *;
    };

    template <typename T>
    using add_pointer_t = typename add_pointer<T>::type;
}