#include <math.h>
#include <chrono>
#include <iostream>
#include <vector>



double sum_positive(double *a, unsigned long n) {
    double s = 0;
    for (unsigned long i = 0; i < n; i++) {
        if (a[i] > 0) {
            s += a[i];
        }
    }
    return s;
}

void sqrt_element(double *a, unsigned long n) {
    for (unsigned long i = 0; i < n; i++) {
        a[i] = sqrt(a[i]);
    }
}

void exp_element(double *a, unsigned long n) {
    for (unsigned long i = 0; i < n; i++) {
        a[i] = exp(a[i]);
    }
}

void log_element(double *a, unsigned long n) {
    for (unsigned long i = 0; i < n; i++) {
        a[i] = log(a[i]);
    }
}

void gauss(double *a, double *b, unsigned long n) {
    double p = 1 / sqrt(2.0 * M_PI);
    for (unsigned long i = 0; i < n; i++) {
        b[i] = p * exp(-a[i]*a[i]/2);
    }
}

double inner_prod(double *a, double *b, unsigned long n) {
    double sum = 0;
    for (unsigned long i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sqrt(sum);
}

#define n (4)

int main(){
    int i
    unsigned int size[n] = [10,100,1000,10000];
    a = new double [];
    b = new double [];

    for (unsigned long i = 0; i < n; i++){
        std::srand(std::time(nullptr)); // use current time as seed for random generator
        int random_variable = std::rand();
        a.push_back(random_variable);
        std::srand(std::time(nullptr)); // use current time as seed for random generator
        int random_variable = std::rand();
        b.push_back(random_variable);
    }

    auto now = high_resolution_clock::now();
    auto end_time = duration_cast<duration<double>>(high_resolution_clock::now() - now).count();

    inner_prod(a,b,n);
}