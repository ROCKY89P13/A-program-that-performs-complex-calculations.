#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <windows.h> //Biblioteca padrão windows

// Statics do MAIN
static void menu() {
puts("\n ---- Menu Matemático ---- \n");
        puts("1. Utilitários Aritméticos\n");
        puts("2. Cálculos relacionados a Fibonacci\n");
        puts("3. Série Harmônica\n");
        puts("4. Estatísticas de vetor\n");
        puts("0. Sair\n");
        puts("Escolha uma opção. ");
    }
static void erro() {
 system("cls");
    puts ("Opção Inválida\n\n");
    puts ("Retornando ao Menu Principal.");
 Sleep(1500);
 system ("cls");
 puts ("Opção Inválida\n\n");
    puts ("Retornando ao Menu Principal..");
 Sleep(1500);
 system ("cls");
 puts ("Opção Inválida\n\n");
    puts ("Retornando ao Menu Principal...");
 Sleep (1500);
 system("cls");
}

static unsigned int verificador_de_letras() {
    unsigned int numero_digitado_da_funcao; 
    int resultado;

    do {
        puts("Digite um número válido:");
        resultado = scanf("%u", &numero_digitado_da_funcao);

        if (resultado != 1) {
            puts("Erro: entrada inválida! Digite apenas números.\n");
            while (getchar() != '\n'); // Limpa buffer de entrada
        }
    } while (resultado != 1);
    system("cls");
    return numero_digitado_da_funcao;
    
}
void pausa() {
    printf("\nPressione Enter para continuar...\n");
    getchar(); 
        int c;
    while ((c = getchar()) != '\n' && c != EOF);
    system("cls");
}
// INICIO
int main(void){
SetConsoleOutputCP(65001); // Força a mudança de linguagem do terminal
unsigned int opcao; 

do
{
    menu();
       
       opcao = verificador_de_letras();

switch (opcao) { // INICIO DA OPÇÃO 1

case 1:    system("cls"); // limpar a tela 
puts("\n ---- UTILITÁRIOS NUMÉRICOS ---- \n");
puts ("Escolha a funcionalidade disponível\n\n");
puts ("1. Verifica se o número é primo");
puts ("2. Calcula o fatorial de um número\n");

unsigned int sub_opcao;

sub_opcao = verificador_de_letras();

switch (sub_opcao) {
    case 1: // NUMEROS PRIMOS
    system("cls");
    unsigned int numero_calculo_primo;

    puts("\n ---- VERIFICAR SE O NÚMERO É PRIMO ---- \n");

numero_calculo_primo = verificador_de_letras();

system("cls");

bool resultado_primo = primo(numero_calculo_primo);
printf("\nO número %u %s primo.", numero_calculo_primo, resultado_primo ? "é" : "não é"); // Caso resultado verdadeiro (é), caso contrário (não é)
       pausa();
    break;

    case 2: // FATORIAL
system("cls");
    unsigned int numero_calculo_fatorial;
puts("\n ---- CALCULA O FATORIAL DE UM NUMERO ---- \n");
puts ("Limite até o número 20\n");

numero_calculo_fatorial = verificador_de_letras();

system("cls");

if( numero_calculo_fatorial >= 21){
    system("cls");
    puts ("Limite excedido\n");
    pausa();
    break;
} else{

long long int resultado_fatorial_final = fatorial_calc(numero_calculo_fatorial);

printf ("O fatorial de %u é %llu\n", numero_calculo_fatorial, resultado_fatorial_final);
       pausa();
       break;
}
    default: 
system("cls");
   erro();
    break;}
    break;
// FINAL DA OPÇÃO 1

//INICIO DA OPÇÃO 2

case 2: 

    system("cls");
     puts("\n ---- CÁLCULOS RELACIONADOS A FIBONACCI ---- \n");
      puts ("Digite a quantidade de termos de Fibonacci a serem gerados ");

    unsigned int quantidade_fibonacci;
    quantidade_fibonacci = verificador_de_letras();
    
    unsigned long long fibo_maior, fibo_soma; 
    double fibo_media; 

        fibonacci(quantidade_fibonacci, &fibo_soma, &fibo_maior, &fibo_media);
  system("cls");
    puts("\n ---- CÁLCULOS RELACIONADOS A FIBONACCI ---- \n");
    puts ("Selecione o resultado relacionado a sequência de Fibonacci\n");
    puts ("1. Soma dos termos\n");
    puts ("2. O maior termo\n");
    puts ("3. A mèdia dos termos\n");

    unsigned int sub_opcao_fibonacci;
    sub_opcao_fibonacci = verificador_de_letras();
    switch(sub_opcao_fibonacci){

case 1:
printf("A Soma dos termos é: %llu\n", fibo_soma);
      pausa();
break;
case 2:
printf("O maior termo é: %llu\n", fibo_maior);
       pausa();
break;
case 3:
printf("A média do termos é: %.2f \n", fibo_media);
      pausa();
break;

default:
system("cls");
   erro();
    break;
    }   
    
break;
 // FINAL DA OPÇÃO 2

 //INICIO DA OPÇÃO 3
case 3:
system ("cls");
puts("\n ---- SÉRIE HARMÔNICA ---- \n");
puts ("Quantos termos da sequência harmônica a serem somados?");
unsigned int quantidade_sequencia_harmonica;
double soma_das_harmonicas;

quantidade_sequencia_harmonica = verificador_de_letras();

harmonica(quantidade_sequencia_harmonica, &soma_das_harmonicas);

printf ("A soma de %u termos das sequência harmônica é: %.2f\n", quantidade_sequencia_harmonica, soma_das_harmonicas);

 pausa();
       system("cls");
break;
// FINAL DA OPÇÃO 3

// INICIO DA OPÇÃO 4

case 4:
system("cls");
puts("\n ---- ESTATÍSTICAS DE VETOR ---- \n");
puts ("Tamanho do vetor");
unsigned int tamanho = verificador_de_letras();

 if (tamanho == 0) {
        puts("O tamanho do vetor não pode ser zero.");
        pausa();
        break;
    }

unsigned int *vetores = malloc(tamanho * sizeof(unsigned int));
if (vetores == NULL) {
        puts("Falha ao alocar memória!");
        pausa();
        break;}
ler_vetor ( vetores, tamanho);

long long max_vetor, min_vetor, acima_da_media_vetor;
double media_vetor;

calcular_vetor(vetores, tamanho, &max_vetor, &min_vetor, &media_vetor, &acima_da_media_vetor); 

system ("cls");
puts("\n ---- ESTATÍSTICAS DE VETOR ---- \n");
printf ("Vetor Máximo:%lld\n", max_vetor );
printf ("Vetor Mínimo:%lld\n", min_vetor);
printf ("Média dos Vetores:%.2f\n", media_vetor );
printf ("Vetores Acima da Média:%llu\n\n", acima_da_media_vetor);

pausa();

free(vetores);
system("cls");
break;
//FINAL DA OPÇÃO 4


case 0:
   system("cls");
    puts ("Encerrando");
   for (int i = 0; i < 3; i++) {
    puts(".");
    Sleep(500);
    
}
break;

default:
    erro();
system ("cls");
break;

}
}
while ( opcao != 0); // verificador
} // FIM
