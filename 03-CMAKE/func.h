#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <random>
#include <vector>
#include <functional>
#include <stdlib.h>

std::vector<double> gera_vetor(int n);
void log_vetor(std::vector<double> &vetor);
void sqrt_vetor(std::vector<double> &vetor);
void pow3_vetor(std::vector<double> &vetor);
void pow2Manual_vetor(std::vector<double> &vetor);
double sum_vetor(std::vector<double> &vetor);
std::vector<double> teste_incremental(std::function<void(std::vector<double>&)> func);

#endif