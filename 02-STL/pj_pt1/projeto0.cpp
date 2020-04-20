#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <random>
#include <vector>
#include <functional>
#include <stdlib.h>
using namespace std::chrono;


std::vector<double> gera_vetor(int n){
    std::vector<double> vetor;
    std::default_random_engine eng(100);
    std::normal_distribution<double> distr(5,27);
    
    for(int i =0;i<n;i++){
        float r = distr(eng);
        vetor.push_back(r);
    }
    return vetor;
}


void log_vetor(std::vector<double> &vetor){
    for(int i =0;i<vetor.size();i++){
        vetor[i]=log(vetor[i]);
    }
}

void sqrt_vetor(std::vector<double> &vetor){
    for(int i =0;i<vetor.size();i++){
        vetor[i]=(sqrt(vetor[i]));
    }
}


void pow3_vetor(std::vector<double> &vetor){
    for(int i =0;i<vetor.size();i++){
        vetor[i]=(pow(vetor[i],3));
    }
}

void pow2Manual_vetor(std::vector<double> &vetor){
    for(int i =0;i<vetor.size();i++){
        vetor[i]=(vetor[i]*vetor[i]*vetor[i]);
    }
}

double sum_vetor(std::vector<double> &vetor){
    double soma=0;
    for(int i =0;i<vetor.size();i++){
        soma=soma+vetor[i];
    }
    return soma;
}



std::vector<double> teste_incremental(std::function<void(std::vector<double>&)> func){
    std::vector<double> tempo;
    
    int max = 1000000000;
    for(int i=100;i<max;i=i*10){
        std::vector<double> vetor = gera_vetor(i);

        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        func(vetor);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();

        duration<double> time = duration_cast<duration<double>>(t2 - t1);

        tempo.push_back(time.count());
    }
    return tempo;
}


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