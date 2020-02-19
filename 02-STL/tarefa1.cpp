#include <iostream>
#include <memory>

int main() {
    // int *ptr = new int(0);
    auto ptr = std::unique_ptr<int> (new int);
    
    for(int f=0;f<1024*1024*1024;f++) {
        // ptr = new int(f);
        ptr.reset(new int(f));
    }
    std::cout << "valor final = " << ptr.get() << std::endl;
    // delete ptr;
}
