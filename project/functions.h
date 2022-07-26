#include"stack.h"

int prec(char a);
node* rem_zeros(node*head);
int operat(char a);
int count(list L);
int compare(list L1, list L2);
node* addition(list a, list b);
node *substract(list a, list b);
node* multiply(list a,list b);
node* division(node*a,node*b);
node * modulo(node*a,node*b);
node* power(node*base, node*exp);
void evaluate(list L1, list L2, char*a);
void eval_exp(char*a);