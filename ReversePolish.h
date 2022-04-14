#define N 50

// DECLARATION OF DATA STRUCT
struct data{
	float NUMBER;		// Declaration of struct elements 
};

typedef struct element* Stack;		// Default name for Stack pointer 

// BASIC STACK FUNCTIONS 
Stack* createStack();
void freeStack(Stack* ST);
int accessTopStack(Stack* ST, struct data *DT);
int insertStack(Stack* ST, struct data DT);
int removeStack(Stack* ST);

// REVERSE POLISH NOTATION FUNCTIONS
float operations(float A, float B, int OP);
float expression(Stack* ST, char EXP[]);