#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <dos.h>
#include <afxres.h>

#define TAM 200000000


void MinMax1(int *vet, int *min, int *max)
{
    int i;
    *min = *max = vet[0];
    for (i = 1; i < TAM; i++)
    {
        if (vet[i] > *max) *max = vet[i];
        if (vet[i] < *min) *min = vet[i];
    }
}

void MinMax2(int *vet, int *min, int *max)
{
    int i;
    *min = *max = vet[0];
    for (i = 1; i < TAM; i++)
    {
        if (vet[i] > *max) *max = vet[i];
        else if (vet[i] < *min) *min = vet[i];
    }
}


void MinMax3(int *vet, int *min, int *max)
{
    int i, cont;
    if (TAM % 2 > 0)
    { vet[TAM] = vet[TAM - 1]; cont = TAM; }
    else cont = TAM - 1;
    if (vet[0] > vet[1])
    { *max = vet[0]; *min = vet[1]; }
    else
    { *max = vet[1]; *min = vet[0]; }
    i = 3;

    while (i <= cont)
    {
        if (vet[i - 1] > vet[i])
        { if (vet[i - 1] > *max) *max = vet[i - 1];
            if (vet[i] < *min) *min = vet[i]; }
        else
        { if (vet[i - 1] < *min) *min = vet[i - 1];
            if (vet[i] > *max) *max = vet[i]; }
        i += 2;
    }
}

int* makeSequence (int size){
    int* vet = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        vet[i] = i;
    }
    return vet;
}

int isNULL(int* item){
    if (item == NULL)
        return 1;
    return 0;
}

int isIn(int* item,int* vet, int size){
    for (int i = 0; i < size; i++) {
        if (item == vet[i]){
            return 1;
        }
    }
    return 0;
}


int* shuffle(int* vet,int size){
    int *shuffle_aux;
    int i = size;
    int random;
    while (i>0){
        i--;
        random = rand()%(size+1);
        shuffle_aux = vet[i];
        vet[i] = vet[random];
        vet[random] = shuffle_aux;
    }
    return vet;
}

int main() {


    __int64 freq,start,stop;

    double tempo;


    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&start);

    int* vet = shuffle(makeSequence(TAM),TAM);

    QueryPerformanceCounter((LARGE_INTEGER *)&stop);
    tempo = ((double)stop-(double)start) / (double)CLOCKS_PER_SEC;
    printf("tempo total em milisegundos: %f \n",tempo/10000);

    int* min = calloc(1, sizeof(int));
    int* max = calloc(1, sizeof(int));

    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&start);

    MinMax1(vet, min, max);

    QueryPerformanceCounter((LARGE_INTEGER *)&stop);
    tempo = ((double)stop-(double)start) / (double)CLOCKS_PER_SEC;
    printf("tempo total em milisegundos: %f \n",tempo/10000);

    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&start);

    MinMax2(vet, min, max);

    QueryPerformanceCounter((LARGE_INTEGER *)&stop);
    tempo = ((double)stop-(double)start) / (double)CLOCKS_PER_SEC;
    printf("tempo total em milisegundos: %f \n",tempo/10000);

    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&start);

    MinMax3(vet, min, max);

    QueryPerformanceCounter((LARGE_INTEGER *)&stop);
    tempo = ((double)stop-(double)start) / (double)CLOCKS_PER_SEC;
    printf("tempo total em segundos: %f \n",tempo/10000);

    printf("\n%i", 0);


    printf("Hello, World!\n");
    return 0;
}
