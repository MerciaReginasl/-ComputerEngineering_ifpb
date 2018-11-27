//Codigo por: Ruan Delgado Gomes

//Exemplopessoa_2



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

typedef struct {
    char str[51];
    int po;
} strpo;

int compare(const void *a, const void *b) {
    strpo *p1 = (strpo*)a;
    strpo *p2 = (strpo*)b;
    int sp1 = strlen(p1->str);
    int sp2 = strlen(p2->str);
    if(sp1 == sp2) {
        return (p1->po - p2->po);
    }
    else {
        return sp2 - sp1;
    }
}


int n;
scanf("%d",&n);

strpo palavras[51];

char s[2550];
scanf("%[^\n]s", s);
int ci = 0;
char saux[51];
for...
    //separar as strings
    palavras[ci].po = ci;
    strcpy(palavras[ci].str, saux);






int compareIdade(const void *a, const void *b) {
    Pessoa *p1 = (Pessoa*)a;
    Pessoa *p2 = (Pessoa*)b;
    return (p1->idade - p2->idade);
}

int compareNome(const void *a, const void *b) {
    Pessoa *p1 = (Pessoa*)a;
    Pessoa *p2 = (Pessoa*)b;
    return strcmp(p1->nome, p2->nome);
}

int main() {
    Pessoa vp[] = { {"pedro", 20}, 
                    {"joao", 40},
                    {"maria", 30},
                    {"jose", 22}
    };
   
    qsort(vp, 4, sizeof(Pessoa), compareNome);
    
    for(int i = 0; i < 4; i++) {
        printf("Nome: %s\n", vp[i].nome);
        printf("Idade: %d\n\n",vp[i].idade);
    }
    return 0;
}
