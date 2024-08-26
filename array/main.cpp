#include "array.h"
#include <iostream>

int main() {
    // Test initializer list constructor and size function
    array<int, 5> arr = {1, 2, 3, 4};
    std::cout << "Array size: " << arr.get_size() << std::endl;

    // Test operator[]
    std::cout << "arr[0]: " << arr[0] << std::endl;
    std::cout << "arr[3]: " << arr[3] << std::endl;

    // Test at() with valid index
    std::cout << "arr.at(2): " << arr.at(2) << std::endl;

    // Test at() with invalid index (should throw an exception)
    try {
        std::cout << "arr.at(5): " << arr.at(5) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected out_of_range exception: " << e.what() << std::endl;
    }

    // Test front() and back()
    std::cout << "arr.front(): " << arr.front() << std::endl;
    std::cout << "arr.back(): " << arr.back() << std::endl;

    // Test data()
    std::cout << "arr.data(): " << arr.data() << std::endl;
    std::cout << "arr[0] (via data): " << *arr.data() << std::endl;

    // Test isempty()
    std::cout << "Array is empty: " << std::boolalpha << arr.isempty() << std::endl;

    // Test max_size()
    std::cout << "Array max_size: " << arr.max_size() << std::endl;

    // Test assignment operator
    array<int, 5> arr2;
    arr2 = arr;
    std::cout << "arr2 size after assignment: " << arr2.get_size() << std::endl;
    std::cout << "arr2[0] after assignment: " << arr2[0] << std::endl;

    // Test begin(), end(), cbegin(), cend()
    std::cout << "Iterating over array using begin() and end():" << std::endl;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating over array using cbegin() and cend():" << std::endl;
    for (auto it = arr.cbegin(); it != arr.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test reverse iterators rbegin(), rend(), crbegin(), crend()
    std::cout << "Iterating over array using rbegin() and rend():" << std::endl;
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating over array using crbegin() and crend():" << std::endl;
    for (auto it = arr.crbegin(); it != arr.crend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
