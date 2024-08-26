#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <initializer_list>


template <typename T, std::size_t N = 0>
class array{
    private:
        T arr[N];
        std::size_t size = 0;
    public:

        array(){}

        array(std::initializer_list<T> init){
            int i = 0;
            for(auto it  = init.begin();it != init.end() && i < N; ++i, ++it){
                arr[i] = *it;
            }
            size = i;
        }

        const array& operator=(const array& other){
            if(&other == this){
                return *this;
            }

            int i = 0;
            for(int j = 0; j < other.get_size() && i < N; ++i, ++j){
                arr[i] = other.arr[j];
            }
            size = i;

            return *this;
        }

        T& at(int index){
            if(index >= 0 && index < N){
                return arr[index];
            }else{
                throw std::out_of_range("Invalid index");
            }
        }
        T& operator[](int index){
            if(index >= 0 && index < N){
                return arr[index];
            }else{
                throw std::out_of_range("Invalid index");
            }
        }

        T& front(){
            if(!isempty()){
                return arr[0];
            }else{
                throw std::runtime_error("Array is empty");
            }
        }

        T& back(){
            if(!isempty()){
                return arr[size - 1];
            }else{
                throw std::runtime_error("Array is empty");
            }
        }
        
        T* data() noexcept{
            return arr;
        }

        bool isempty(){
            return size == 0;
        }

        std::size_t get_size() const{
            return size;
        }

        std::size_t max_size(){
            return N;
        }

        T* begin() noexcept{
            return arr;
        }

        const T* cbegin() const noexcept{
            return arr;
        }

        T* end() noexcept{
            return arr + size;
        }

        const T* cend() const noexcept{
            return arr + size;
        }

        std::reverse_iterator<T*> rbegin() noexcept{
            return std::reverse_iterator<T*>(end());
        }

        std::reverse_iterator<const T*> crbegin() const noexcept{
            return std::reverse_iterator<const T*>(cend());
        }
        std::reverse_iterator<T*> rend() noexcept{
            return std::reverse_iterator<T*>(begin());
        }

        std::reverse_iterator<const T*> crend() const noexcept{
            return std::reverse_iterator<const T*>(cbegin());
        }
        

        ~array(){}

};

#endif