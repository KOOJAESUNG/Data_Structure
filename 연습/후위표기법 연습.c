#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 30

typedef struct _stack stack;
struct _stack {
	char data[size];
	int top;
};

void init(stack* stack);
int is_empty(stack* stack);
int is_full(stack* stack);
void push(char chr, stack* stack);
char pop(stack* stack);
int ConvToRPNExp(char exp[]);
int WhoPrecOp(char op1, char op2);
int GetOpPrec(char op);
char is_top(stack* stack);


void init(stack* stack) {
	stack->top = 0;
}

int is_empty(stack *stack) {
	if (stack->top == 0)
		return 1;
	else
		return 0;
}

int is_full(stack *stack) {
	if (stack->top == size)
		return 1;
	else
		return 0;
}

void push(char chr,stack*stack) {
	if (is_full(&stack) == 1) {
		printf("스택이 꽉 찼습니다.");
		return;
	}
	stack->data[stack->top] = chr;
	stack->top++;
}

char pop(stack *stack) {
	if (is_empty(&stack) == 1) {
		printf("스택이 비어있습니다.");
		return;
	}
	stack->top--;
	return stack->data[stack->top];
}

char is_top(stack *stack) {
	if (is_empty(&stack) == 1) {
		printf("스택이 비어있습니다.");
		return;
	}
	char pop_data;
	stack->top--;
	pop_data = stack->data[stack->top];
	stack->top++;
	return pop_data;
}

int ConvToRPNExp(char exp[]) {
	stack stack;
	int expLen = strlen(exp);
	char * convExp=(char*)malloc(expLen+1);

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen +1); //\0 고려
	init(&stack);

	for (i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(tok)) {
			convExp[idx++] = tok;  //숫자면 convExp에 저장
		}
		else {
			switch (tok) {
			case '(':
				push(tok, &stack);
				break;
			case ')':
				while (1) {
					popOp = pop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			case '+': case '-':
			case '*': case '/':
				while (!is_empty(&stack) && WhoPrecOp(is_top(&stack), tok) >= 0)
					convExp[idx++] = pop(&stack);
				push(tok, &stack);
				break;
				}
			}
		}
	while (!is_empty(&stack))
		convExp[idx++] = pop(&stack);
	strcpy(exp, convExp);
	free(convExp);
}

int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
 }

int GetOpPrec(char op) {
	switch (op) 
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}

int main() {
	char exp[] = "(4+3/2-3)*2+3-2*(4/3+1)";
	ConvToRPNExp(exp);
	printf("%s", exp);
}
