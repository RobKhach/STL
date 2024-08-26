#include <iostream>

std::unordered_map<int, int> fibonachi_cache = {{0,0},{1,1}};

int fibonachi(int index_of_num)
{

    auto it = fibonachi_cache.find(index_of_num);
    if(it != fibonachi_cache.end()){
        return it->second;
    }else{
        fibonachi_cache[index_of_num] = fibonachi(index_of_num - 1) + fibonachi(index_of_num - 2);
        return fibonachi_cache[index_of_num];
    }
}

int main(){

    int n = 10;
    int i = 0;
    while(i <= n){
        std::cout << fibonachi(i) << " ";
        ++i;
    }
    std::cout << std::endl;

    return 0;
}