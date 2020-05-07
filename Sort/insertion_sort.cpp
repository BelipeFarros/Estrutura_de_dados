#include <iostream>
#include <stdlib.h>
#include <ctime>

#define fim '\n'

using namespace std;

/***
 * Função: insertion Sort 
 * Descrição: Ordena um vetor em ordem crescente
 * Parâmetros: vetor - Um vetor de inteiros a ser ordenado
 *             p - inicio do vetor
 *             r - final do vetor
 */
void insertionSortCresc(int *vetor, int p, int r);
void insertionSortDecresc(int *vetor, int p, int r);
void insertionSort(int *vetor, int p, int r, bool cresc);

/**
 * Função: imprimeVetor
 * Descrição: imprime um vetor dado
 * Parâmetros: vetor - Um vetor a ser imprimido
 *             tam - tamanho do vetor
 */
void imprimeVetor(int* vetor, int tam);

int main(){
    int N = 10;
    int* vetor = new int[N];

    //Gerando o vetor
    srand(time(NULL));
    for(int i = 0; i < N; i++) vetor[i] = rand() % 100;

    //Mostrando vetor em tela
    cout << "Vetor de entrada:" << fim;
    imprimeVetor(vetor, N);
    cout << fim;
    cout << "Vetor ordenado pelo insertion sort" << fim;
    insertionSort(vetor,0,N-1, true);
    imprimeVetor(vetor, N);
    insertionSort(vetor,0,N-1, false);
    imprimeVetor(vetor, N);

    //Deletando o vetor
    delete [] vetor;

    return 0;
}

//FUNÇÔES:

void insertionSort(int *vetor, int p, int r, bool cresc){
    if(cresc) insertionSortCresc(vetor, p, r);
    else insertionSortDecresc(vetor, p, r); 
}

void insertionSortCresc(int* vetor, int p, int r){
    int chave, i;
    for(int j = p + 1; j <= r; j++){
        chave = vetor[j];
        i = j - 1;
        while( i >= p and vetor[i] > chave){
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = chave;
    }
}

void insertionSortDecresc(int* vetor, int p, int r){
    int chave, i;
    for(int j = p + 1; j <= r; j++){
        chave = vetor[j];
        i = j - 1;
        while( i >= p and vetor[i] < chave){
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = chave;
    }
}

void imprimeVetor(int* vetor, int tam){
    cout << "------------------------------" << fim;
    for(int i = 0; i < tam; i++){
        cout << vetor[i] << ' ';
    }
    cout << fim;
    cout << "------------------------------" << fim;
}