#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "utils.h"


bool primo(unsigned int n) { // CALCULO DOS PRIMOS
    int contador = 0;
    for ( int i = 1 ;i <= n ; i++){
    if(n % i == 0){
        contador++;
    } // Essa parte verifica quantos divisores o número tem
 }
return (contador == 2); // Caso tenha menos ou mais de 2 divisores, retorna falso
}

unsigned long long fatorial_calc(unsigned int n) { // CALCULO DOS FATORIAIS

 unsigned long long fatorial = 1;


    for (int i = 1; i <= n; i++) {
        fatorial *= i;// Multiplica o resultado da multiplicação pelo número que antecede. 
    }
    return fatorial; // Retorna o valor final do loop
}

void fibonacci(unsigned int n, unsigned long long *soma, unsigned long long *maior, double *media) { // CALCULO DE FIBONACCI
    unsigned long long a = 0, b = 1; // Primeira sequência
    *soma = 0;
    *maior = 0;
    for (unsigned int i = 1; i <= n; i++) { // Laço feito para fazer a adição de "A" e "B", após isto, sempre que
        unsigned long long c = a + b;       // o laço voltar ao inicio, o resultado que é "C", vira "B" e "A" vira "B".
        a = b;                              // "A" sempre vai ser o último termo resultante do cálculo.
        b = c;
        *soma += a; // Aqui está sendo realizado a adição do ultímo termo com o anterior. 
        *maior = a; // Como é crescente os termos, o último sempre será o maior. 
    }
if (n > 0) { // Para não ter erro de dividir 0 por 0. 

        *media = (double)*soma / n; // Tive que transformar em double para previnir do resultado sair somente inteiro.
    } else {
        *media = 0.0; 
    }
}

void harmonica (unsigned int n, double *soma){  //CALCULOS DA SERIE HARMONICA

    
    *soma = 0; // valor inicial, importante. 
     

     for (int i = 1; i <= n; i++) { // Um laço que tem o dever de somar 0 com a divisão de 1 por i (que nesse será 1,2,3...) "n" vezes.
        *soma += 1.0 / i;
} 
if (n == 0) { // Para não ter erro de dividir 0 por 0. 

   *soma = 0;

}
}

void ler_vetor(int* vetor, int tamanho){
    puts("\n ---- ESTATÍSTICAS DE VETOR ---- \n");
    printf("Por favor, digite %d números inteiros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Número %d: ", i + 1);
        while (scanf("%d", &vetor[i]) != 1) {
            printf("Entrada inválida. Por favor, digite um número: ");
            int c;
        while ((c = getchar()) != '\n' && c != EOF);
        }
        
    }
}

void calcular_vetor(const int* vetor, unsigned int tamanho,  long long *max,  long long *min, double *media,  long long *acima_da_media){

    *min = vetor[0];
    *max = vetor[0];
    long long soma = 0;

    
    for (unsigned int i = 0; i < tamanho; i++) {
        soma += vetor[i];

       
        if (vetor[i] < *min) {
            *min = vetor[i];
        }


        if (vetor[i] > *max) {
            *max = vetor[i];
        }
    }
    *media = (double)soma / tamanho;

    *acima_da_media = 0;
    for (unsigned int i = 0; i < tamanho; i++) {
       
        if (vetor[i] > *media) {
            (*acima_da_media)++;
        }
    }

}

