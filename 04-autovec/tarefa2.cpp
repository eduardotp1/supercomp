#include <iostream>
#include <chrono>
#include <random>
using namespace std::chrono;

double soma_positivos1(std::vector<double> &a){
    double soma=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>0){
            soma=soma+a[i];
        }
    }    
    return soma;
}

double soma_positivos2(std::vector<double> &a){
    double soma=0;
    for(int i=0;i<a.size();i++){
        soma += (a[i]>0)?a[i]:0;
    }    
    return soma;
}


int main(){
    int size=10000000;
    std::vector<double> vetor;
    std::default_random_engine eng(100);
    std::normal_distribution<double> distr(-10,10);
    
    for(int i =0;i<size;i++){
        float r = distr(eng);
        vetor.push_back(r);
    }

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    double soma = soma_positivos1(vetor);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    double soma2 = soma_positivos2(vetor);
    high_resolution_clock::time_point t3 = high_resolution_clock::now();

    std::cout << "Soma: " <<  soma<< "\n";
    std::cout << "Soma2: " <<  soma2<< "\n";
    duration<double> time_soma = duration_cast<duration<double>>(t2 - t1);
    duration<double> time_soma2 = duration_cast<duration<double>>(t3 - t2);
    std::cout << "Calcular soma demorou: " <<  time_soma.count() << " seconds."<< "\n";
    std::cout << "Calcular soma2 demorou: " <<  time_soma2.count() << " seconds."<< "\n";

}