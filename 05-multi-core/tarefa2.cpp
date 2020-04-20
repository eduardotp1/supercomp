#include <thread>
#include <iostream>

void funcao_rodando_em_paralelo(int a) {
    std::cout << "Thread=" << a << std::endl;
}


int main() {
    std::thread t1(funcao_rodando_em_paralelo, 0);

    std::thread t2(funcao_rodando_em_paralelo, 1);

    std::thread t3(funcao_rodando_em_paralelo, 2);

    std::thread t4(funcao_rodando_em_paralelo, 3);

    
    
    // Espera até que a função acabe de executar.
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
