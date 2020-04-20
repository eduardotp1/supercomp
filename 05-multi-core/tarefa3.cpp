#include <thread>
#include <iostream>
#include <vector>


void funcao_rodando_em_paralelo(int a, int *b) {
    std::cout << "Thread=" << a << std::endl;
    *b=a*a;
}


int main() {
    int soma;
    int n_threads = std::thread::hardware_concurrency();
    std::vector<std::thread> v(n_threads);
    std::vector<int> b(n_threads);
    std::cout << "Number of Threads: " << n_threads << std::endl;


    for(int i =0; i<n_threads;i++){
        v[i]=std::thread(funcao_rodando_em_paralelo, i, &b[i]);
    }
    for(int i =0; i<n_threads;i++){
        v[i].join();

        soma = soma+b[i];
        std::cout << "b=" << b[i] << std::endl;
    }
    std::cout << "Soma" << soma << std::endl;
}
