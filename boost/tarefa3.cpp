#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream> 
#include <boost/timer.hpp>
#include <boost/foreach.hpp>
#include <boost/random.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>  
#include <boost/program_options.hpp>

int main(int argc, const char *argv[]) {

    // Faz a analise dos dados passados na linha de comando
    boost::program_options::options_description desc{"Options"};
    desc.add_options() ("gravar,g", "grava dados") ("ler,l", "le dados");
    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);

    // cria o stream de saida com o apoio do Boost
    std::ofstream ostr(filename.c_str(),std::ios::binary);
    boost::archive::binary_oarchive oa(ostr);

    // calcula o termo do fibonaci
    for i in range(0,argc)


    // envia os dados para o arquivo
    oa << myVec;
    std::cout << "Dados gravados" << std::endl;

    // fecha o arquivo que recebeu os dados
    ostr.close();