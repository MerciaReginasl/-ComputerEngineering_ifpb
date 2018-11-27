//Código por: Ruan Delgado Gomes


include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b) {
    int *va = (int*)a;
    int *vb = (int*)b;
    
    if(*va%2 == 1 && *vb%2 == 0) {
        return -1;
    }
    else if(*vb%2 == 1 && *va%2 == 0) {
        return 1;
    }
    else {
        return (*va - *vb);
    }
 
}

int main() {
    int vet[] = {4,3,5,1,2,3,6,7,8,5};
    qsort(vet, 10, sizeof(int), compare);
    for(int i = 0; i < 10; i++) {
        printf("%d ",vet[i]);
    }
    return 0;
}
