#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>
#include <random>

template <typename... Args>
std::ostream& print(std::ostream& os, Args... data){
    ((os << data << " "),...);
    os << "\n";
    return os;
}



int main(){

    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 6};

    int a = 0;

    std::for_each(arr.begin(), arr.end(), [&a](int b){ a += b; });

    std::cout << "foe_each sum of all elements "<<a << std::endl;

     a = 0;

    std::for_each_n(arr.begin(), 3, [&a](int b){ a += b; });

    std::cout << "foe_each_n sum of 3 elements "<< a << std::endl;

    std::cout << "All_of is odd number --> " <<  std::all_of(arr.begin(), arr.end(), [](int b){return b % 2;}) <<std::endl;
    std::cout << "any_of is odd number --> " <<  std::any_of(arr.begin(), arr.end(), [](int b){return b % 2;}) <<std::endl;
    std::cout << "none_of is odd number --> " <<  std::none_of(arr.begin(), arr.end(), [](int b){return b % 2;}) <<std::endl;


    std::cout << "Vector value --> ";
    for(const auto& it : arr){
        std::cout << it << " ";
    }
    std::cout << "\n";

    int array[3] = {3, 4, 5};


    std::cout << "Array values ---> ";
    for(int i = 0; i < 3; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";


    // auto result = std::ranges::contains_subrange(arr, array);
    // std::cout << "Does Vector contains Array --- > " <<  result << std::endl;

    auto it = std::adjacent_find(arr.begin(), arr.end(), std::greater<int>{});

    if(it == arr.end()){
        print(std::cout, "sorted");
    }else{
        print(std::cout, "not sorted");
    }

    auto result = std::search(arr.begin(), arr.end(), array, array + 3, [](int a , int b){ return a == b;});
    std::cout << "Search subarray -- > " << *result << std::endl;

    std::vector<int> arr2(arr);


    auto func = [](auto a){return a % 2 != 0;};
    std::copy_if(arr.begin(), arr.end(), arr2.begin(), func);

    std::cout << "Copy from arr to arr2 all odd numbers --> ";
    for(const auto& it : arr2){
        std::cout << it << " ";
    }

    std::transform(arr.begin(), arr.end(), arr2.begin(), [](auto a){if (a % 2 != 0){return a * a;}else{ return a;}} );
    std::cout << "Transform from arr to arr2 odd = a * a --> " ;
    for(auto it : arr2){
        std::cout << it << " ";
    }
    std::cout << std::endl;


    std::vector<int> arr3(arr2);

    int n = 99;
    std::generate(arr2.begin(), arr2.end(), [&n](){return n += n;});
    std::cout << "Transform from arr2  a  = 99 += 99 ... --> ";
    for(auto it : arr2){
        std::cout << it << " ";
    }
    std::cout << std::endl;


    auto iter = std::remove(arr2.begin(), arr2.end(), 198);
    arr2.erase(iter, arr2.end());
    std::cout << "Remove 198 --> ";
    for(auto it : arr2){
        std::cout << it << " ";
    }
    std::cout << std::endl;


    iter = std::remove_if(arr2.begin(), arr2.end(), [](auto a){return a % 2 == 0;});
    arr2.erase(iter, arr2.end());
    std::cout << "Remove if is even number --> ";
    for(auto it : arr2){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    iter = std::unique(arr.begin(), arr.end());
    arr.erase(iter, arr.end());
    std::cout << "Unique --> ";
    for(auto it : arr){
        std::cout << it << " ";
    }
    std::cout << std::endl;


    arr.push_back(99);
    arr.push_back(99);
    std::cout << "Added two same elements --> ";
    for(auto it : arr){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    arr2.resize(std::distance(arr.begin(), arr.end()));
    iter = std::unique_copy(arr.begin(), arr.end(), arr2.begin());
    //arr2.resize(std::distance(arr2.begin(), iter));
    std::cout << "All unique element copy from arr to arr2 --> ";
    for(auto it : arr2){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    std::reverse(arr.begin(), arr.end());
    std::cout << "Reversed arr --> ";
    for(auto it : arr){
        std::cout << it << " ";
    }
    std::cout << std::endl;


    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(arr.begin(), arr.end(), g);
    std::cout << "Shuffled arr --> ";
    for(auto it : arr){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    arr.push_back(88888);
    arr.push_back(88888);
    arr.push_back(88888);
    
    iter = std::sample(arr.begin(), arr.end(), arr2.begin(), 4, g);
    std::cout << "4 random numbers copied from arr to arr2  --> ";
    for(auto it : arr2){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    std::cout << std::boolalpha;
    
    std::cout << "Arr2 not partiition --> " << std::is_partitioned(arr2.begin(), arr2.end(), [](auto a){return a % 4 == 0;}) << std::endl;
    for(auto it : arr2){
        std::cout << it << " ";
    }

    std::cout << std::endl;

    std::cout << "Arr2 partiitioning \n";
    std::partition(arr2.begin(), arr2.end(), [](auto a){return a % 4 == 0;});

    std::cout << "Arr2 not partiition --> " << std::is_partitioned(arr2.begin(), arr2.end(), [](auto a){return a % 4 == 0;}) << std::endl;
    for(auto it : arr2){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    std::cout << "Sort arr by ranges --> ";
    std::ranges::sort(arr);
    for(auto it : arr){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    std::iota(arr.begin(), arr.end(), 0);
    std::cout << "Array after iota using with 0 --> ";
    for(auto it : arr){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    int res = 0;
    res = std::accumulate(arr.begin(), arr.end(), res);
    std::cout << "Accamulate all element of arr in res --> " << res << std::endl;
    
    return 0;
}