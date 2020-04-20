#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <random>
#include <vector>
#include <functional>
#include <stdlib.h>
using namespace std::chrono;

#include "func.h"



int main(){
    std::vector<double> time_log = teste_incremental(log_vetor);
    for(int i = 0; i<time_log.size();i++){
        std::cout << "Log " << time_log[i] << "\n";
    }

    std::vector<double> time_sqrt = teste_incremental(sqrt_vetor);
    for(int i = 0; i<time_sqrt.size();i++){
        std::cout << "Sqrt " << time_sqrt[i] << "\n";
    }

    std::vector<double> time_pow3 = teste_incremental(pow3_vetor);
    for(int i = 0; i<time_pow3.size();i++){
        std::cout << "Pow3 " << time_pow3[i] << "\n";
    }

    std::vector<double> time_pow2Manual = teste_incremental(pow2Manual_vetor);
    for(int i = 0; i<time_pow2Manual.size();i++){
        std::cout << "Pow2Manual " << time_pow2Manual[i] << "\n";
    }

    std::vector<double> time_sum = teste_incremental( [=](std::vector<double>& vetor){sum_vetor(vetor);});
    for(int i = 0; i<time_sum.size();i++){
        std::cout << "Sum " << time_sum[i] << "\n";
    }
    return 0;
}