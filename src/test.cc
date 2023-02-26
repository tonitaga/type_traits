#include "type_traits.h"

#include <iostream>

const std::string SUCCESS("SUCCESS");
const std::string ERROR("ERROR");

template <typename T1, typename T2>
void is_same_test(T1, T2, bool answer) {
    if (s21::is_same_v<T1, T2> == answer) {
        std::cout << "is_same_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "is_same_test: " << ERROR << std::endl;
    }
}

template <typename T, typename CheckType>
void remove_const_test() {
    if (s21::is_same_v<s21::remove_const_t<T>, CheckType>) {
        std::cout << "remove_const_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "remove_const_test: " << ERROR << std::endl;
    }
}

template <typename T, typename CheckType>
void remove_volatile_test() {
    if (s21::is_same_v<s21::remove_volatile_t<T>, CheckType>) {
        std::cout << "remove_volatile_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "remove_volatile_test: " << ERROR << std::endl;
    }
}

template <typename T, typename CheckType>
void remove_cv_test() {
    if (s21::is_same_v<s21::remove_cv_t<T>, CheckType>) {
        std::cout << "remove_cv_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "remove_cv_test: " << ERROR << std::endl;
    }
}

template <typename T, typename CheckType>
void add_const_test() {
    if (s21::is_same_v<s21::add_const_t<T>, CheckType>) {
        std::cout << "add_const_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "add_const_test: " << ERROR << std::endl;
    }
}

template <typename T, typename CheckType>
void add_volatile_test() {
    if (s21::is_same_v<s21::add_volatile_t<T>, CheckType>) {
        std::cout << "add_volatile_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "add_volatile_test: " << ERROR << std::endl;
    }
}

template <typename T, typename CheckType>
void add_cv_test() {
    if (s21::is_same_v<s21::add_cv_t<T>, CheckType>) {
        std::cout << "add_cv_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "add_cv_test: " << ERROR << std::endl;
    }
}

template <typename T, typename CheckType>
void remove_reference_test() {
    if (s21::is_same_v<s21::remove_reference_t<T>, CheckType>) {
        std::cout << "remove_reference_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "remove_reference_test: " << ERROR << std::endl;
    }
}

template <typename T, typename CheckType>
void add_lvalue_reference_test() {
    if (s21::is_same_v<s21::add_lvalue_reference_t<T>, CheckType>) {
        std::cout << "add_lvalue_reference_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "add_lvalue_reference_test: " << ERROR << std::endl;
    }
}

template <typename T, typename CheckType>
void add_rvalue_reference_test() {
    if (s21::is_same_v<s21::add_rvalue_reference_t<T>, CheckType>) {
        std::cout << "add_rvalue_reference_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "add_rvalue_reference_test: " << ERROR << std::endl;
    }
}

template <typename T, typename CheckType>
void remove_pointer_test() {
    if (s21::is_same_v<s21::remove_pointer_t<T>, CheckType>) {
        std::cout << "remove_pointer_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "remove_pointer_test: " << ERROR << std::endl;
    }
}

template <typename T, typename CheckType>
void add_pointer_test() {
    if (s21::is_same_v<s21::add_pointer_t<T>, CheckType>) {
        std::cout << "add_pointer_test: " << SUCCESS << std::endl;
    } else {
        std::cout << "add_pointer_test: " << ERROR << std::endl;
    }
}

int main() {
    is_same_test(1, 1, true);
    is_same_test(1, 1., false);
    remove_const_test<const int, int>();
    remove_const_test<int, int>();
    remove_volatile_test<volatile int, int>();
    remove_volatile_test<int, int>();
    remove_cv_test<const volatile int, int>();
    remove_cv_test<volatile const int, int>();
    remove_cv_test<int, int>();
    add_const_test<int, const int>();
    add_const_test<const int, const int>();
    add_volatile_test<int, volatile int>();
    add_volatile_test<volatile int, volatile int>();
    add_cv_test<int, const volatile int>();
    add_cv_test<const volatile int, const volatile int>();
    remove_reference_test<int &, int>();
    remove_reference_test<int, int>();
    add_lvalue_reference_test<int, int&>();
    add_rvalue_reference_test<int, int&&>();
    remove_pointer_test<int *, int>();
    remove_pointer_test<int, int>();
    add_pointer_test<int, int*>();
    add_pointer_test<int *, int *>();
}