#include <iostream>

int fib(int n) {
  int x,y;
  if(n<2) return n;
  #pragma omp task
    x=fib(n-1);
  #pragma omp task
    y=fib(n-2);
  #pragma omp taskwait
  return(x+y);
}

int main() {
  int NW=15,f;
  #pragma omp parallel
    #pragma omp master
      f=fib(NW);
  std::cout << f << std::endl;
}