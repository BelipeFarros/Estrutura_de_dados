#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>

#define infinito INT_MAX
#define fim '\n';
using namespace std;

/***
 * Função: Merge 
 * Descrição: Subrotina do merge sort que realiza a intercalação
 *            de dois subvetores
 * Parâmetros: vetor - Um vetor de inteiros a ser ordenado
 *             p - inicio do vetor
 *             q - meio do vetor
 *             r - final do vetor
 */
void merge(int* vetor, int p, int q, int r);

/***
 * Função: Merge Sort 
 * Descrição: Ordena um vetor em ordem crescente recursivamente
 * Parâmetros: vetor - Um vetor de inteiros a ser ordenado
 *             p - inicio do vetor
 *             r - final do vetor
 */
void mergeSort(int* vetor, int p, int r);

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
    cout << "Vetor ordenado pelo merge sort" << fim;
    mergeSort(vetor, 0, N-1);
    imprimeVetor(vetor, N);

    //Deletando o vetor
    delete [] vetor;
    return 0;
}

//Funções

void merge(int* vetor, int p, int q, int r){
    //Calculando o tamanho dos vetores
    int n1 = q - p + 1;
    int n2 = r - q;
    
    //Criando os subvetores
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];

    //Alocando os subvetores
    for(int i = 0; i < n1; i++) L[i] = vetor[p + i];
    for(int j = 0; j < n2; j++) R[j] = vetor[q + j + 1];
    L[n1] = infinito;
    R[n2] = infinito;

    //Realizando o merge (intercalação)
    int i = 0, j = 0;

    for(int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
    }

    delete [] L;
    delete [] R;
    }

    void mergeSort(int* vetor, int p, int r){
        //Condiçãp de saida
        if(p>=r) return;

        //Obtendo o valor do meio do vetor
        int q = (p + r)/2;

        //Ordenando o subvetor esquerdo
        mergeSort(vetor, p, q);

        //Ordenando o subvetor direito
        mergeSort(vetor, q + 1, r);

        //Fazendo o merge (intercalação) dos subvetores
        merge(vetor, p, q, r);
    }

    void imprimeVetor(int* vetor, int tam){
    cout << "------------------------------" << fim;
    for(int i = 0; i < tam; i++){
        cout << vetor[i] << ' ';
    }
    cout << fim;
    cout << "------------------------------" << fim;
}
