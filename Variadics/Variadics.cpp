#include <iostream>

template <typename T , typename... args>
T add(T data, args... tuple){
    (data += ... += tuple);
    return data;
}

template <typename T , typename... args>
T mul(T data, args... tuple){
    (data *= ... *= tuple);
    return data;
}


int main(){
    int sum = add(1, 3, 4, 5, 6, 3, 2, 1);
    std::cout << sum << std::endl;

    int val = mul(3, 3, 2, 1);
    std::cout << val << std::endl;

    return 0;
}