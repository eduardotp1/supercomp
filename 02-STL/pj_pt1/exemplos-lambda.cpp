#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <random>
#include <vector>
#include <functional>
#include <stdlib.h>

int main(){
    int c = 2;
    std::function <double(int)> by_two = [=](int n) {
        return double(n) / c; 
    };
    std::cout << by_two(10) << "\n";

    c = 2;
    std::function<double(int)> by_c = [&](int n) {
        return double(n) / c; 
    };
    std::cout << by_c(7) << "\n";
    c = 3;
    std::cout << by_c(7) << "\n";
}