// Esse código está com um problema de vazamento de memória,
// use os recursos do BOOST para evitar que isso se repita.
// Não é para resolver na mão, use os recursos do BOOST.

#include <iostream>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>

int foo(int x) {
	boost::shared_ptr<int> vec1{new int(8)};
	//int *vec1 = new int[8];
	for(int f=0;f<8;f++) ptr1.reset(new int(f*x));
	boost::shared_ptr<int> vec2{vec1};
	//int *vec2 = vec1;
	int tmp = vec1[0]+vec1[4]+vec1[7]-vec1[5];
	return tmp;
}

int main() {
	long int tmp = 0;
	for(int f=0;f<1024*1024*512;f++)  tmp += foo(f);
	std::cout << tmp << std::endl;
}