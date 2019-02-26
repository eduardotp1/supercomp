// Paralelize o código para calcular a soma mais rapido em vários cores
// Compilar: g++ atividade1.cpp -std=c++14 -lboost_thread -lboost_chrono -lboost_system -lboost_timer
// Referencia: https://theboostcpplibraries.com/boost.thread-management

#include <boost/thread.hpp>
#include <boost/timer/timer.hpp>
#include <iostream>
#include <cstdint>

int main() {

    boost::timer::cpu_timer timer;

    const std::uint64_t size = 2'147'483'647;
    std::uint64_t total = 0;
    for (std::uint64_t i = 0; i < size; ++i)
        total += i+1;
        std::cout << "saindo da thread" << 1 << std::endl;

    std::cout << timer.format();
    std::cout << total << '\n';
}