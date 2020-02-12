#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
    int n;
    double m,desvioPadrao,variancia,s,sub;
    std::cin >> n;
    double *x= new double [n];
    s=0;

    for(int i=0;i<n;i++){
        std::cin >> x[i];
        s=s+x[i];
    }

    m=s/n;
    for(int j=0;j<n;j++){
        sub=pow(x[j]-m,2);
    }
    desvioPadrao=sqrt((sub)/n);
    variancia=(sub)/n;
    delete[] x;
    std::cout << std::setprecision(10) << variancia << std::endl;
}