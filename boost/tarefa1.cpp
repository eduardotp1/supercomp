// Esse código está com um problema de vazamento de memória,
// use os recursos do BOOST para evitar que isso se repita.
// Não é para resolver na mão, use os recursos do BOOST.

#include <iostream>
#include <boost/scoped_ptr.hpp>

int main() {
  boost::scoped_ptr<int> ptr{new int(0)};
  //int *ptr = new int(0);
  for(int f=0;f<1024*1024*1024;f++) {
    ptr.reset(new int(f));
  }
  std::cout << "ptr : " << *ptr.get() << std::endl;
  ptr.reset();
}
