#include <iostream>
#include <string>
#include <vector>



std::vector<int> find_all(std::string text, std::string term){
    std::vector<int> positions;
    int found = text.find(term);
    positions.push_back(found);
    while (found!=std::string::npos){
        found = text.find(term,found+1);
        if (found!=std::string::npos){
            positions.push_back(found);
        }
    }
    return positions;
}


int main (){
    std::string texto,term;
    int count;
    std::getline (std::cin,texto);

    std::cout << "Qual o termo que deseja contar" << "\n";
    std::cin >> term;

    std::vector<int> vetor = find_all(texto,term);
    count = vetor.size();

    std::cout << "A quantidade de aparicoes"<< term << "eh : " << count << "\n";
    for (std::vector<int>::iterator i = vetor.begin(); i != vetor.end(); ++i){
        std::cout << "Posicao"<< *i << "\n";
    }
    return 0;
}