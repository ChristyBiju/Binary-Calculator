#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

void init(list L){
    L = NULL;
    return;
}

node *append(list L,char d){
    node * np = malloc(sizeof(node));
    np->data = d;
    np->prev = NULL;
    np->next = NULL;
    if (L == NULL)
    {
        L = np;
    }
    else{
        list p=L;
        while (p->next!=NULL)
        {
            p = p->next;
        }
        p->next = np;
        np->prev = p;
    }
    return L;
}

node* insertbeg(list L,char d){
    node * np = malloc(sizeof(node));
    np->data = d;
    np->prev = NULL;
    np->next = NULL;
    if (L == NULL)
    {
        L = np;
    }
    else{
        np->next = L;
        L->prev = np;
        L = np;
    }
    return L;
    
}

void traverse(list L)
{
    if (L == NULL)
    {
        printf("%d",0);
    }
    else
    {
        list p = L;
        while (p != NULL)
        {
            if (p->data == '-')
            {
                printf("%c", p->data);
                p = p->next;
            }
            else
            {
                printf("%d", p->data);
                p = p->next;
            }
        }
    }
}

node* destroy(list L){
    if (L==NULL)
    {
        return L;
    }
    else{
        node*temp = L;
        while (L!=NULL)
        {
            L = L->next;
            free(temp);
            temp = L;
        }
        return L;  
    }
    
}

node *tail(node *head)
{
    node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    return t;
}
