#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>

int fib(int n) {
    int x,y;
    if(n<2) return n;
    x=fib(n-1);
    y=fib(n-2);
    return(x+y);
}

int fib_par1(int n) {
    int x,y;
    if(n<2) return n;
    #pragma omp task shared(x)
        x=fib_par1(n-1);
    #pragma omp task shared(y)
        y=fib_par1(n-2);

    #pragma omp taskwait
    return(x+y);
}

int fib_par2(int n, int nivel) {
    int x,y;
    if(n<2) return n;
    if(nivel > log(omp_get_max_threads())){
        x=fib(n-1);
        y=fib(n-2);
        return(x+y);
    }
    #pragma omp task shared(x)
        x=fib_par2(n-1,nivel+1);
    #pragma omp task shared(y)
        y=fib_par2(n-2,nivel+1);

    #pragma omp taskwait
    return(x+y);
}

int main() {
    int NW=15;

    auto start_time = std::chrono::high_resolution_clock::now();    
    int f=fib(NW);
    std::cout << f << std::endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count();
    std::cout << runtime << " segundos" << std::endl;
    

    start_time = std::chrono::high_resolution_clock::now();    
    #pragma omp parallel
    {
        #pragma omp master
        {
            int f_par=fib_par1(NW);
            std::cout << f_par << std::endl;
        }
    }
    end_time = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count();
    std::cout << runtime << " segundos" << std::endl;

    start_time = std::chrono::high_resolution_clock::now();    
    #pragma omp parallel
    {
        #pragma omp master
        {
            int f_par2=fib_par2(NW,0);
            std::cout << f_par2 << std::endl;
        }
    }
    end_time = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count();
    std::cout << runtime << " segundos" << std::endl;

}