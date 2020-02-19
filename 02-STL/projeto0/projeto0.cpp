#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <random>
#include <vector>
#include <stdlib.h>


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

std::vector<double> log_vetor(std::vector<double> &vetor){
    std::vector<double> vetorLog;
    for(int i =0;i<vetor.size();i++){
        vetorLog.push_back(log(vetor[i]));
    }
    return vetorLog;
}

std::vector<double> sqrt_vetor(std::vector<double> &vetor){
    std::vector<double> vetorSqrt;
    for(int i =0;i<vetor.size();i++){
        vetorSqrt.push_back(sqrt(vetor[i]));
    }
    return vetorSqrt;
}


//rever esta parte
std::vector<double> pow3_vetor(std::vector<double> &vetor){
    std::vector<double> vetorPow3;
    for(int i =0;i<vetor.size();i++){
        vetorPow3.push_back(pow(vetor[i],3));
    }
}

std::vector<double> pow2Manual_vetor(std::vector<double> &vetor){
    std::vector<double> vetorPow3Manual;
    for(int i =0;i<vetor.size();i++){
        vetorPow3Manual.push_back(vetor[i]*vetor[i]*vetor[i]);
    }
    return vetorPow3Manual;
}

double sum_vetor(std::vector<double> &vetor){
    double soma=0;
    for(int i =0;i<vetor.size();i++){
        soma=soma+vetor[i];
    }
    return soma;
}


int main(){
    using namespace std::chrono;

    int max = 1000000000;
    std::vector<double> vetor;
    for(int i=100;i<max;i=i*100){

        vetor=gera_vetor(i);

        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        log_vetor(vetor);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        sqrt_vetor(vetor);
        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        pow3_vetor(vetor);
        high_resolution_clock::time_point t4 = high_resolution_clock::now();
        // pow2Manual_vetor(vetor);
        // high_resolution_clock::time_point t5 = high_resolution_clock::now();
        // sum_vetor(vetor);
        // high_resolution_clock::time_point t6 = high_resolution_clock::now();



        duration<double> time_log = duration_cast<duration<double>>(t2 - t1);
        duration<double> time_sqrt = duration_cast<duration<double>>(t3 - t2);
        duration<double> time_pow3 = duration_cast<duration<double>>(t4 - t3);
        // duration<double> time_pow3Manual = duration_cast<duration<double>>(t5 - t4);
        // duration<double> time_sum = duration_cast<duration<double>>(t6 - t5);

        std::cout << "Para o tamanho do vetor: " << i << "\n";
        std::cout << "Calcular log demorou: " <<  time_log.count() << " seconds."<< "\n";
        std::cout << "Calcular sqrt demorou: " << time_sqrt.count() << " seconds."<< "\n";
        std::cout << "Calcular pow3 demorou: " << time_pow3.count() << " seconds."<< "\n";
        // std::cout << "Calcular pow3Manual demorou: " << time_pow3Manual.count() << " seconds."<< "\n";
        // std::cout << "Calcular sum demorou: " << time_sum.count() << " seconds."<< "\n"<< "\n";
    }


    return 0;
}