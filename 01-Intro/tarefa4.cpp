#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>

int main(){
    int n;
    double m,desvioPadrao,variancia,s,sub;
    std::cin >> n;
    double *x= new double [n];
    s=0;

    for(int i=0;i<n;i++){
        std::cin >> x[i];
    }
    using namespace std::chrono;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for(int i=0;i<n;i++){
        s=s+x[i];
    }
    m=s/n;

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    for(int j=0;j<n;j++){
        sub=pow(x[j]-m,2);
    }
    variancia=(sub)/n;
    high_resolution_clock::time_point t3 = high_resolution_clock::now();


    duration<double> time_media = duration_cast<duration<double>>(t2 - t1);
    duration<double> time_variancia = duration_cast<duration<double>>(t3 - t2);
    std::cout << "Calcular media demorou: " << time_media.count() << " seconds.";
    std::cout << std::endl;
    std::cout << "Calcular variancias demorou: " << time_variancia.count() << " seconds.";
    std::cout << std::endl;

    desvioPadrao=sqrt((sub)/n);
    delete[] x;
    std::cout << std::setprecision(10) << variancia << std::endl;
}