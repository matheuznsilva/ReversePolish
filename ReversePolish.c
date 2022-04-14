#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReversePolish.h"

// DECLARATION OF STACK STRUCT
struct element{
	struct data DATA;		// Data type field
	struct element *next;		// Pointer that stores next stack position
};

typedef struct element Elem;		// Default name for struct element

// BASIC STACK FUNCTIONS 
Stack* createStack(){       // Stack creation function
    Stack* ST = (Stack*) malloc(sizeof(Stack));
    if (ST != NULL){
        *ST = NULL;
    }
    return ST;
}

void freeStack(Stack* ST){      // Stack destruction function
    if (ST != NULL){
        Elem* NO;
        while ((*ST)!= NULL){
            NO = *ST;
            *ST = (*ST)->next;
            free(NO);
        }
        free(ST);
    }
}

int insertStack(Stack* ST, struct data DT){     // Stack insertion function (Remembering that stack is LIFO)
    if(ST == NULL){
        return 0;
    }
    Elem* NO;
    NO = (Elem*) malloc(sizeof(Elem));
    if(NO == NULL){
        return 0;
    }
    NO->DATA = DT;
    NO->next = (*ST);
    *ST = NO;
    return 1;
}

int removeStack(Stack* ST){     // Stack removal function (Removal always happens from the top)
    if(ST == NULL){
        return 0;
    }
    if((*ST) == NULL){
        return 0;
    }
    Elem *NO = *ST;
    *ST = NO->next;
    free(NO);
    return 1;
}

int accessTopStack(Stack* ST, struct data *DT){     // Top of stack access function
    if(ST == NULL){
        return 0;
    }if((*ST) == NULL){
        return 0;
    }
    *DT = (*ST)->DATA;
    removeStack(ST);
    return 1;
}

// REVERSE POLISH NOTATION FUNCTIONS
float operations(float A, float B, int OP){     // Function where operations take place
    switch (OP){
    case '+':{
        return A + B;
        break;
    }
    case '-':{
        return A - B;
        break;
    }
    case '*':{
        return A * B;
        break;
    }
    case '/':{
        return A / B;
        break;
    }
    default:
        return 0;
    }
}

float expression(Stack* ST, char EXP[]){        // Expression decoding function  
    char *auxP;
    struct data DT, DATA_1, DATA_2;
    auxP = strtok(EXP, " ");
    while (auxP){
        if(auxP[0] == '+' || auxP[0] == '-' || auxP[0] == '*' || auxP[0] == '/'){
            accessTopStack(ST, &DATA_1);
            accessTopStack(ST, &DATA_2); 
            DT.NUMBER = operations(DATA_2.NUMBER, DATA_1.NUMBER, auxP[0]); 
            insertStack(ST, DT);
        } else{
            DT.NUMBER = strtol(auxP, NULL, 10);
            insertStack(ST, DT);
        }
        auxP = strtok(NULL, " ");
    }
    accessTopStack(ST, &DT);
    free(auxP);
    return DT.NUMBER;
}