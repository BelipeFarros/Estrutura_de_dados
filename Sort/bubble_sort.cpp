#include <iostream>
#include <cstdlib>
#include <ctime>

#define fim '\n'

using namespace std;

/**
 * Função: imprimeVetor
 * Descrição: imprime um vetor dado
 * Parâmetros: vetor - Um vetor a ser imprimido
 *             tam - tamanho do vetor
 */
void imprimeVetor(int* vetor, int tam);

/**
 * Função: troca
 * Descrição: Troca os dois valores recebidos como parâmetro
 * Parâmetros: a e b - valores a serem trocados
 */
void troca (int &a, int &b) {int c = a; a = b; b = c;};

/**
 * Função: Bubble sort
 * Descrição: Ordena um vetor em ordem crescente 
 * Parâmetros: vetor - vetor a ser ordenado
 *             p - inicio do vetor
 *             r - fim do vetor
 */
void bubbleSort(int* vetor, int p, int r);

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
    cout << "Vetor ordenado pelo bubble sort" << fim;
    bubbleSort(vetor, 0, N - 1);
    imprimeVetor(vetor, N);

    //Deletando o vetor
    delete [] vetor;

    return 0;
}

void imprimeVetor(int* vetor, int tam){
    cout << "------------------------------" << fim;
    for(int i = 0; i < tam; i++){
        cout << vetor[i] << ' ';
    }
    cout << fim;
    cout << "------------------------------" << fim;
}

void bubbleSort(int* vetor, int p, int r){
    while (true){
        bool stop = true;
        for(int i = p; i < r; i++){
            if(vetor[i] > vetor[i + 1]){
                troca(vetor[i], vetor[i + 1]);
                stop = false;
            }
        }
        if(stop) break;
    }
}
