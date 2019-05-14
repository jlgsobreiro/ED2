#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <afxres.h>

#define TAM 100


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


int* shuffle(int* vet,int size){
    int *shuffle_vet = calloc(size, sizeof(int));
    int i = size;
    int random;
    while (i>0){
        random = rand()%(size+1);
        if (isNULL(shuffle_vet[random])){
            i--;
            shuffle_vet[random] = vet[i];
        }
    }
    return shuffle_vet;
}

long long timeInMilliseconds(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}
int main() {

    srand(time(NULL));
    int* vet = shuffle(makeSequence(TAM),TAM);

    for (int i = 0; i < TAM; ++i) {
        printf("%i : %i\n", i, vet[i]);
    }
    int* min = calloc(1, sizeof(int));
    int* max = calloc(1, sizeof(int));
    printf("%llo: time",timeInMilliseconds());
    MinMax1(vet, min, max);
    printf("%llo: time",timeInMilliseconds());
    MinMax2(vet, min, max);
    printf("%llo: time",timeInMilliseconds());
    MinMax3(vet, min, max);
    printf("%llo: time",timeInMilliseconds());
    printf("\n%i", 0);


    printf("Hello, World!\n");
    return 0;
}
