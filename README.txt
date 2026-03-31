==================================================================
        PROJETO EM C - SISTEMA DE CÁLCULOS
==================================================================

Autor: Henrique Kaio 

------------------------------------------------------------------
1. FUNCIONALIDADES IMPLEMENTADAS
------------------------------------------------------------------

O programa apresenta um menu principal com as seguintes funcionalidades implementadas:

- **Utilitários Aritméticos:**
  - Verificação de número primo.
  - Cálculo de Fatorial (limitado a n=20).

- **Sequência de Fibonacci:**
  - Geração dos 'n' primeiros termos.
  - Cálculo da soma, maior termo, média dos termos gerados.

- **Séries Matemáticas:**
  - Cálculo da Série Harmônica.

- **Estatísticas de Vetor:**
  - Leitura de um vetor de 'n' números.
  - Cálculo do valor mínimo, máximo, média e a contagem de valores acima da média

------------------------------------------------------------------
2. FÓRMULAS E LIMITES
------------------------------------------------------------------

- **Série Harmônica:** A série escolhida foi a Série Harmônica (Hn), que é a soma dos inversos dos n primeiros números inteiros positivos. A fórmula é: Hn = 1 + 1/2 + 1/3 + ... + 1/n.

- **Limite do Fatorial:** O cálculo de fatorial foi limitado para entradas de no máximo 20 para evitar 'overflow' (estouro de capacidade) do tipo de dado `unsigned long long`, garantindo a correção numérica do resultado.

------------------------------------------------------------------
3. COMPILAÇÃO E EXECUÇÃO
------------------------------------------------------------------
- A respeito da execução, o programa aparente ter algumas limitações/peculiaridades, pois como o programa inicia Fibonacci em 1 + 0, ele faz a contagem de 5 termos da seguinte forma (11235) ao invés de (01123).
- O programa possuí verificador em todas as partes, ele impede a entrada de letras ou números de opções inexistentes, mas, infelizmente em algumas partes específicas do programa ao digitar um número e uma letra em seguida causa um bug.
- O tempo de programação, infelizmente levou mais tempo que o esperado, não conseguirei incluir as funções adicionais solicitadas como extra; 
- Foram realizados no total 71 testes desde o início. 
- O programa teve sua plataforma feita inicialmente completa, as funções foram adicionadas aos poucos, sempre realizando testes. 
- Uma questão também é sobre a biblioteca MATH, eu não a conheço bem, mas eu suponho que no meu projeto ela não teve utilidade, mas mantive. 
- Para organização foi necessário adicionar a biblioteca padrão do windows (windows.h) para comandos como Sleep e System.
- Ainda sobre a biblioteca do Windows, me faz pensar que o projeto em outros OS pode ter alguma complicação.
- O primeiro problema que tive no início do projeto foi a linguagem que o terminal abria, portanto, a biblioteca do windows também força a linguagem que carrega os acentos e etc... no início do código.  

4. CÓDIGO 

- As Funções:

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


Testes (seis funções):

- Primeira função, a dos números primos:

Supondo que entre o número 10, será feita a divisão do número 10 com todos que estão antes dele, portanto, é previsto que seja liberado uma saída "FALSA" caso tenha mais de 2 divisores ou 1 divisor (caso de uma entrada 1). No caso do 10, a sáida será falsa. (não é primo).


- Segunda função, a dos fatoriais: 

Supondo que entre 5, há um laço que fará esse número ser multiplicado por todos que estão antes dele. A saída será um retorno do valor de fatorial no ultimo loop. Resultado esperado é 120.


- Terceira função, Fibonacci:

Uma das mais complicadas pela troca de informações entre as variáveis, mas supondo que entre o número 3, c = a + b, 3 define "n" vezes que o loop se repetirá, começando o cálculo em 0 + 1, portanto C = 0 + 1 inicialmente, que se torna 1 = 0 + 1,
que se torna a = b, b = c, portanto agora b = 1, a = 1, e c se torna 2. Assim a sequência em "a" ficará 1,1,2,3,5,8.... É esperado que os números 1,1,2 sejam gerados e somados. A sáida irá ter o Maior, Soma e a Média, sendo Maior o ultimo "a", a Soma a adição de todos os elementos,
e a Média, a Soma dividido pelo "n" de elementos que foram gerados.Esperado que resulte em Maior = 2, Média = 1,33, Soma = 4. 


- Quarta função, a sequência Harmônica:

Muito mais simples que Fibonacci, há um loop que irá dividir e somar até que a condição seja falsa. Se entra 6, o laço irá dividir 1 por 1/1 + 1/2 + 1/3... até 1/6, a saída esperada é 2,45. 


- Quinta e Sexta função, trabalham juntas:

A Quinta irá ler os vetores e o tamanho, após ler o tamanho, ele inicia um loop que se repete "tamanho" vezes lendo cada um dos vetores e guardando essa informação.

A Sexta irá ler as informações guardadas pela Quinta para poder trabalhar. Os laços da Sexta utilizando o tamanho para definir quantas vezes se repetem, foi necessário dois laços, pois o segundo depende do resultado do primeiro e dá média para verificar quantos são acima da média. 
Também há o verificador constante enquando ocorrer a soma para o maior e menor vetor.
É esperado que entrada 2, gere duas caixas para serem preenchidas, se entrar os números 2 e -6, eles serão guardados. As informações serão trocadas e passadas a Sexta função pelo Main.c, A entrada na sexta função de tamanho 2, e vetores 2 e -6 resulta em: Vetor Máximo:2; Vetor Mínimo:-6; Média dos Vetores:-2.00; Vetores Acima da Média:1. 











