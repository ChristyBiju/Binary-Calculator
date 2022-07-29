#include<stdio.h>
#include<stdlib.h>
#include"stack.h"


void init_Num(Num_Stack *s){
    *s = NULL;
}

void init_char(char_Stack *s){
    *s = NULL;
}

void push_Num(Num_Stack *s,list d){
    Num_Stack np = malloc(sizeof(node1));
    np->d = d;
    np->next = NULL;
    if (*s == NULL)
    {
        *s = np;
    }
    else
    {
        np->next = *s;
        *s = np;
    }
    return;
}

void push_char(char_Stack *s,char d){
    char_Stack np = malloc(sizeof(node2));
    np->d = d;
    np->next = NULL;
    if (*s == NULL)
    {
        *s = np;
    }
    else
    {
        np->next = *s;
        *s = np;
    }
    return;
}

list pop_Num(Num_Stack *s){
    list a;
    if (isEmpty_num(*s))
    {
        printf("Stack Underflow");
    }
    else{
        Num_Stack temp = *s;
        a = temp->d;
        *s = (*s)->next;
        free(temp);
    }
   return a; 
}

char pop_char(char_Stack *s){
    char a;
    if (isEmpty_op(*s))
    {
        printf("Stack Underflow");
    }
    else{
        char_Stack temp = *s;
        a = temp->d;
        *s = (*s)->next;
        free(temp);
    }
    return a;
}

list peek_num(Num_Stack s){
    return s->d;
}

char peek_op(char_Stack s){
    return s->d;
}

int isEmpty_num(Num_Stack s){
    if (s==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

int isEmpty_op(char_Stack s){
    if (s==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

