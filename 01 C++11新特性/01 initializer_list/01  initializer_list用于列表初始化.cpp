#include <iostream>
#include <vector>
#include <cstring>
#include <initializer_list>
 
template<size_t arrSize>
class Array {
public:
    Array(std::initializer_list<int> initList) {
        if (initList.size() > arrSize){
            throw std::string("Too many initialization parameters");
        }

        memset(reinterpret_cast<char*>(arr),0,sizeof(int) * arrSize);
        size_t index = 0;
        for (auto ite = initList.begin();ite != initList.end();++ite){
            this->arr[index] = *ite ;
            ++index;
        }        
    }

    int* begin() {
        return arr;
    }

    int* end() {
        return arr + arrSize;
    }
private:
    int arr[arrSize];
};

int main(){
    Array<5> arr1 = {1,2,3};
    for (auto ite = arr1.begin(); ite != arr1.end(); ++ite){
        std::cout << *ite << " ";
    }std::cout << std::endl;
    
    return 0;
}