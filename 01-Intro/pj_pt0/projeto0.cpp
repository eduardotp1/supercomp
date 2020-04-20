#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <random>
#include <stdlib.h>


double *gera_vetor(int n){
    double *vetor=new double [n];
    std::default_random_engine eng(100);
    std::normal_distribution<double> distr(10,2);
    
    for(int i =0;i<n;i++){
        float r = distr(eng);
        vetor[i] = r;
    }
    return vetor;
}

double *log_vetor(int n, double *vetor){
    double *vetorLog=new double [n];
    for(int i =0;i<n;i++){
        vetorLog[i] = log(vetor[i]);
    }
    return vetorLog;
}

double *sqrt_vetor(int n, double *vetor){
    double *vetorSqrt=new double [n];
    for(int i =0;i<n;i++){
        vetorSqrt[i] = sqrt(vetor[i]);
    }
    return vetorSqrt;
}

double *pow3_vetor(int n, double *vetor){
    double *vetorPow3=new double [n];
    for(int i =0;i<n;i++){
        vetorPow3[i] = pow(vetor[i],3);
    }
}

double *pow2Manual_vetor(int n, double *vetor){
    double *vetorPow3Manual=new double [n];
    for(int i =0;i<n;i++){
        vetorPow3Manual[i] = vetor[i]*vetor[i]*vetor[i];
    }
    return vetorPow3Manual;
}

double sum_vetor(int n, double *vetor){
    double soma=0;
    for(int i =0;i<n;i++){
        soma=soma+vetor[i];
    }
    return soma;
}


int main(){
    using namespace std::chrono;

    int max = 1000000000;
    for(int i=100;i<max;i=i*100){
        double *vetor=new double [i];

        vetor=gera_vetor(i);   

        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        double *vetorAux = log_vetor(i,vetor);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        vetorAux = sqrt_vetor(i,vetor);
        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        vetorAux = pow3_vetor(i,vetor);
        high_resolution_clock::time_point t4 = high_resolution_clock::now();
        vetorAux = pow2Manual_vetor(i,vetor);
        high_resolution_clock::time_point t5 = high_resolution_clock::now();
        double soma = sum_vetor(i,vetor);
        high_resolution_clock::time_point t6 = high_resolution_clock::now();

        delete[] vetor;
        delete[] vetorAux;


        duration<double> time_log = duration_cast<duration<double>>(t2 - t1);
        duration<double> time_sqrt = duration_cast<duration<double>>(t3 - t2);
        duration<double> time_pow3 = duration_cast<duration<double>>(t4 - t3);
        duration<double> time_pow3Manual = duration_cast<duration<double>>(t5 - t4);
        duration<double> time_sum = duration_cast<duration<double>>(t6 - t5);

        std::cout << "Para o tamanho do vetor: " << i << "\n";
        std::cout << "Calcular log demorou: " <<  time_log.count() << " seconds."<< "\n";
        std::cout << "Calcular sqrt demorou: " << time_sqrt.count() << " seconds."<< "\n";
        std::cout << "Calcular pow3 demorou: " << time_pow3.count() << " seconds."<< "\n";
        std::cout << "Calcular pow3Manual demorou: " << time_pow3Manual.count() << " seconds."<< "\n";
        std::cout << "Calcular sum demorou: " << time_sum.count() << " seconds."<< "\n"<< "\n";
    }


    return 0;
}