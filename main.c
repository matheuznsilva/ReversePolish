#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReversePolish.h"

int main(){
    Stack *ST = createStack();
    char EXP[N];
    int i = 0;

    FILE *F = fopen("expression.txt", "r");

    while ((EXP[i] = fgetc(F)) != EOF){
        i++;
    }
    
    printf("\nO RESULTADO DA EXPRESSÃO É: %.2f\n\n", expression(ST, EXP));
    return 0;
}