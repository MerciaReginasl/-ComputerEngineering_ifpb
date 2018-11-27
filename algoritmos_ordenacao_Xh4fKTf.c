#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define SIZE 1000 //tamanho do vetor

int intcmp(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

void printArray(int *v, int n) {
    int i = 0;
    for(i = 0; i < n; i++) {
        printf("%d ",v[i]);
    }
    printf("\n");
}

void insertionsort(int *v, int n) {
    int i,j,atual;
    for(i = 1; i < n; i++) {
        atual = v[i];
        j = i-1;
        while(j >= 0 && v[j] > atual) { //compare(&v[j], &atual) <= 0
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = atual;
    }
}

void merge(int *v, int i, int f) {
    int m = (i+f)/2;
    int it1 = i,it2 = m+1;
    int *vaux = (int*)malloc((f-i+1)*sizeof(int));
    int itaux = 0;
        
    while(it1 <= m && it2 <= f) {
        if(v[it1] < v[it2]) {
            vaux[itaux] = v[it1];
            it1++;
        }
        else {
            vaux[itaux] = v[it2];
            it2++;
        }
        itaux++;
    }
    while (it1 <= m) { //insere os elementos restantes da primeira metade, se houver        
        vaux[itaux] = v[it1];
        it1++;
        itaux++;
    }
    while (it2 <= f) { //insere os elementos restantes da segunda metade, se houver        
        vaux[itaux] = v[it2];
        it2++;
        itaux++;
    }
    int a;
    for(a = i; a <= f; a++) { //coloca os valores ordenados de volta no vetor original
        v[a] = vaux[a-i];
    }
    free(vaux);
}

void mergeSort(int *v, int i, int f) {
    int m;
    if(i == f) { //so tem um elemento
        return;
    }
    else if((f-i) == 1) { //so tem dois elementos
        if(v[f] < v[i]) { //verifica se precisa inverter os valores
            int aux = v[i];
            v[i] = v[f];
            v[f] = aux;
        }
    }
    else {
        m = (i+f)/2;
        mergeSort(v,i,m);
        mergeSort(v,m+1,f);
        merge(v,i,f);
    }
}


int particiona(int *v, int n) {
    int p = rand()%n, e = 1, d = n-1;
    int aux = v[p];
    v[p] = v[0];
    v[0] = aux;
    p = 0;
    while(e <= d) {
        while(e < n && v[e] <= v[p]) e++;
        while(d >= 0 && v[d] > v[p]) d--;
        if(e < d) {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
            e++;
            d--;
        }
    }
    aux = v[d];
    v[d] = v[p];
    v[p] = aux;
    return d;
}

int particiona_mediana(int *v, int n) {
    int p, e = 1, d = n-1;
    
    if((v[0] <= v[n-1] && v[0] >= v[n/2]) || (v[0] >= v[n-1] && v[0] <= v[n/2])) {
        p = 0;
    }
    else if ((v[n/2] <= v[n-1] && v[n/2] >= v[0]) || (v[n/2] >= v[n-1] && v[n/2] <= v[0])) {
        p = n/2;
    }
    else {
        p = n-1;
    }
   // printf("Pivo: %d\n",p);
    int aux = v[p];
    v[p] = v[0];
    v[0] = aux;
    p = 0;
    while(e <= d) {
        while(e < n && v[e] <= v[p]) {
            e++;
        }
        while(d >= 0 && v[d] > v[p]) {
            d--;
        }
        if(e < d) {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
            e++;
            d--;
        }
    }
    aux = v[d];
    v[d] = v[p];
    v[p] = aux;
    return d;
}

void quicksort(int *v, int n) {
    if(n <= 1) return;
    else if(n < 300) {
        insertionsort(v,n);
    }
    else {
        int p = particiona_mediana(v, n);
        quicksort(v, p);
        quicksort(v+p+1, (n - p - 1));
    }
}

void preencheArray(int *v, int *v2, int *v3,  int *v4, int n) {
    int i = 0;
    for(i = 0; i < n; i++) {
        v[i] = rand()%100; //sorteia valor entre 0 e 99 e atribui ao elemento do vetor
        v2[i] = v[i];
        v3[i] = v[i];
    }
}

int checkSort(int *v, int n) {
    if(n <= 0) return -1;
    int ant = v[0];
    int i;
    for(i = 1; i < n; i++) {
        if(v[i] < ant) return 0;
        ant = v[i];
    }
    return 1;
}

int main() {
    int SIZE;
    
    printf("Informe o tamanho do array:\n");
    scanf("%d",&SIZE);
    
    srand(time(NULL)); //inicializa semente aleatoria
    
    int v[SIZE], v2[SIZE], v3[SIZE], v4[SIZE];
    preencheArray(v,v2,v3,v4,SIZE);
   // printArray(v, SIZE);
    
    clock_t ticks[2];
    
    ticks[0] = clock();
    mergeSort(v,0,SIZE-1);
    ticks[1] = clock();
    double tempo1 = (double)(ticks[1] - ticks[0])/ CLOCKS_PER_SEC;   
   // printf("Tempo gasto - merge: %lf s.\n", tempo1);
       
    ticks[0] = clock();
    insertionsort(v2, SIZE);
    ticks[1] = clock();
    double tempo2 = (double)(ticks[1] - ticks[0])/ CLOCKS_PER_SEC;
  //  printf("Tempo gasto - insertion: %lf s.\n", tempo2);
    
    ticks[0] = clock();
    quicksort(v3, SIZE);
   // qsort(v3, SIZE, sizeof(int), intcmp);
    ticks[1] = clock();
    double tempo3 = (double)(ticks[1] - ticks[0])/ CLOCKS_PER_SEC;
    
   /* ticks[0] = clock();
    qsort(v4, SIZE, sizeof(int), &intcmp);
    ticks[1] = clock();
    double tempo4 = (double)(ticks[1] - ticks[0])/ CLOCKS_PER_SEC;*/
    
   // printf("%lf %lf %lf %lf\n",tempo1, tempo2, tempo3, tempo4);
    printf("%lf %lf %lf\n",tempo1, tempo2, tempo3);
    
    
    int r = checkSort(v,SIZE);
    printf("Check merge: %d\n",r);
    r = checkSort(v2,SIZE);
    printf("Check insertion: %d\n",r);
    r = checkSort(v3,SIZE);
    printf("Check quick: %d\n",r);
   /* r = checkSort(v4,SIZE);
    printf("Check qsort: %d\n",r);*/
        
    return 0;
}
