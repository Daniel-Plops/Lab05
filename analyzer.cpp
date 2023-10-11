#include <iostream>
#include <vector>
#include <chrono>
#include "StringData.h"
using namespace std;

int linear_Search(std::vector<std::string> container, string search){
    for(int i = 0; i < container.size(); i++){
        if(container[i] == search){
            return i;
        }
    }
    return -1;
}

int binary_search(std::vector<std::string> container, string search){
    int l = container.size();
    int mid = l / 2;
    int low = 0;
    int high = l-1;
    while(low<=high){
        if(container[mid] < search)
            low = mid + 1;
        else if(container[mid] > search)
            high = mid - 1;
        else
            return mid;
        mid = (high - low) / 2 + low;
    }
    return -1;
}

int main() {
    std::vector<std::string> dataset = getStringData();

    auto t1 = std::chrono::system_clock::now();
    linear_Search(dataset, "not_here");
    auto t2 = std::chrono::system_clock::now() - t1;
    auto t3 = std::chrono::system_clock::now();
    int test = binary_search(dataset, "not_here");
    auto t4 = std::chrono::system_clock::now() - t3;
    std::cout << "Index: " << test << endl;
    std::cout << "Time for \'not_here\'\n Linear: " << t2.count()/1000000000.0f << " sec \n Binary: " << t4.count()/1000000000.0f << " sec \n" << endl;

    auto t5 = std::chrono::system_clock::now();
    linear_Search(dataset, "mzzzz");
    auto t6 = std::chrono::system_clock::now() - t5;
    auto t7 = std::chrono::system_clock::now();
    test = binary_search(dataset, "mzzzz");
    auto t8 = std::chrono::system_clock::now() - t7;
    std::cout << "Index: " << test << endl;
    std::cout << "Time for \'mzzzz\'\n Linear: " << t6.count()/1000000000.0f << " sec \n Binary: " << t8.count()/1000000000.0f << " sec \n" << endl;

    auto t9 = std::chrono::system_clock::now();
    linear_Search(dataset, "aaaaa");
    auto t10 = std::chrono::system_clock::now() - t9;
    auto t11 = std::chrono::system_clock::now();
    test = binary_search(dataset, "aaaaa");
    auto t12 = std::chrono::system_clock::now() - t11;
    std::cout << "Index: " << test << endl;
    std::cout << "Time for \'aaaaa\'\n Linear: " << t10.count()/1000000000.0f << " sec \n Binary: " << t12.count()/1000000000.0f << " sec \n" << endl;

    return 0;
}
