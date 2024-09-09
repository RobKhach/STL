#include <iostream>
#include "allocator.h"

int main(){

    allocator<int> alloc;
    int* arr = alloc.allocate(5);
    alloc.deallocate(arr,5);

    std::cout << "hello";

    return 0;
}