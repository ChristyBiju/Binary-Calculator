#include"list.h"

// Stack for storing the numbers
typedef struct node1{
    list d;
    struct node1*next;
}node1;

//Stack for storing the operators
typedef struct node2{
    char d;
    struct node2*next;
}node2;

typedef node1 * Num_Stack;
typedef node2* char_Stack;

void init_Num(Num_Stack s);
void init_char(char_Stack s);
void push_Num(Num_Stack s,list d);
void push_char(char_Stack s,char d);
list pop_Num(Num_Stack s);
char pop_char(char_Stack s);
list peek_num(Num_Stack s);
char peek_op(char_Stack s);
int isEmpty_num(Num_Stack s);
int isEmpty_op(char_Stack s);