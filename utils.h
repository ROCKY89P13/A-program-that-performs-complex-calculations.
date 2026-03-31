#ifndef UTILS_H
#define UTILS_H
#include <stdbool.h>

/////////////////////////////////////////////////////////

bool primo(unsigned int n); // Para calcular os números primos em true e false
unsigned long long fatorial_calc(unsigned int n); //Para calcular o fatorial dos números até 20
void fibonacci(unsigned int n, unsigned long long *soma, unsigned long long *maior, double *media); // Para calculos relacionados a sequência de Fibonacci
void harmonica(unsigned int n, double *soma); // Para calcular a soma da Sequência Harmônica
void ler_vetor ( int* vetor, int tamanho); 
void calcular_vetor(const int* vetor, unsigned int tamanho, long long *max, long long *min, double *media, long long *acima_da_media);

/////////////////////////////////////////////////////////
#endif 