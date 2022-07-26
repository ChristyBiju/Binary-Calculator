#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

int prec(char a)
// this function checks the precedence of the operators
{
    if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

node *rem_zeros(node *head)
// this function is used to remove the zeros which is at the front of the number
//eg : 000563 == 563
{
    if (head == NULL)
    {
        return head;
    }
    else if (head->data != 0)
    {
        return head;
    }
    else
    {
        node *temp;
        while (head->data == 0 && head != NULL)
        {
            temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
        return head;
    }
}

int operat(char a)
// this function is used to check is the character is an operator or not
{
    if (a == '/' || a == '*' || a == '+' || a == '-' || a == '%' || a == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int count(list L)
// this function is used to count the number of nodes
{
    int n = 0;
    list p = L;
    while (p != NULL)
    {
        p = p->next;
        n++;
    }
    return n;
}

int compare(list L1, list L2)
// this function is used to compare the two numbers
// when first number is greater then the function returns 4 and 2, if the second number is greater then it return 3 and 1 
//whereas if both the numbers are same the it returns 0.
{
    int n1 = count(L1);
    int n2 = count(L2);
    if (n1 > n2)
    {
        return 4;
    }
    else if (n2 > n1)
    {
        return 3;
    }
    else
    {
        node *p1 = L1;
        node *p2 = L2;
        while (p1 != NULL || p2 != NULL)
        {
            if (p1->data > p2->data)
            {
                return 2;
                break;
            }
            else if (p2->data > p1->data)
            {
                return 1;
                break;
            }
            else
            {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        if (p1 == NULL || p2 == NULL)
        {
            return 0;
        }
    }
}

node *addition(list a, list b)
// to add two numbers
{
    // tail function to make a pointer point to the last node
    list t1 = tail(a);
    list t2 = tail(b);
    list c1 = NULL;
    int sum = 0;
    int carry = 0;
    while (t1 != NULL || t2 != NULL)
    {
        if (t1 != NULL && t2 != NULL)
        {
            sum = ((t1->data) + (t2->data) + carry) % 10;
            carry = ((t1->data) + (t2->data) + carry) / 10;
            t1 = t1->prev;
            t2 = t2->prev;
        }
        else if (t1 != NULL && t2 == NULL)
        {
            sum = ((t1->data) + carry) % 10;
            carry = ((t1->data) + carry) / 10;
            t1 = t1->prev;
        }
        else if (t2 != NULL && t1 == NULL)
        {
            sum = ((t2->data) + carry) % 10;
            carry = ((t2->data) + carry) / 10;
            t2 = t2->prev;
        }
        c1 = insertbeg(c1, sum);
    }
    // when the final carry is not zero add it to the number
    if (carry != 0)
    {
        c1 = insertbeg(c1, carry);
    }
    return c1;
}

node *substract(list a, list b)
// to substact two numbers
{
    // c1 stores the final output
    list c1 = NULL;
    int i;
    i = compare(a, b);
    int c = 0;
    int s = 0;
    node *t1 = tail(a);
    node *t2 = tail(b);
    while (t1 != NULL || t2 != NULL)
    {
        //when the first number is greater than the second number
        if ((i == 4 || i == 2) && t1 != NULL)
        {
            if (t1 != NULL && t2 != NULL)
            {
                int d1 = t1->data - t2->data;
                if (d1 >= 0)
                {
                    s = d1 + c;
                    c = 0;
                }
                else
                {
                    s = (t1->data + 10 + c) - t2->data;
                    c = -1;
                }
                t1 = t1->prev;
                t2 = t2->prev;
                c1 = insertbeg(c1, s);
            }
            else if (t1 != NULL && t2 == NULL)
            {
                s = t1->data + c;
                c = 0;
                t1 = t1->prev;
                c1 = insertbeg(c1, s);
            }
        }
        // when the second number is greater
        else if ((i == 3 || i == 1) && t2 != NULL)
        {
            if (t1 != NULL && t2 != NULL)
            {
                int d2 = t2->data - t1->data;
                if (d2 >= 0)
                {
                    s = d2 + c;
                    c = 0;
                }
                else
                {
                    s = (t2->data + 10 + c) - t1->data;
                    c = -1;
                }
                t1 = t1->prev;
                t2 = t2->prev;
                c1 = insertbeg(c1, s);
            }
            else if (t2 != NULL && t1 == NULL)
            {
                s = t2->data + c;
                c = 0;
                t2 = t2->prev;
                c1 = insertbeg(c1, s);
            }
        }
        // when both the numbers are equal
        else if ((i == 0))
        {
            c1 = NULL;
            t1 = t1->prev;
            t2 = t2->prev;
        }
    }
    c1 = rem_zeros(c1);
    // if the second number is greater then adding neg sign in front of the number
    if ((i == 3 || i == 1))
    {
        c1 = insertbeg(c1, '-');
    }
    return c1;
}

node *multiply(list a, list b)
// to multiply two numbers
{
    list t1 = tail(a);
    list t2 = tail(b);
    //c1 is used to store the final output
    list c1 = NULL;
    list c2 = NULL;
    list c3 = NULL;
    int n = 0;
    int m = 0;
    int c = 0;
    while (t2 != NULL)
    {
        node *p1 = t1;
        if (c1 == NULL)
        {
            while (p1 != NULL)
            {
                m = ((p1->data * t2->data) + c) % 10;
                c = ((p1->data * t2->data) + c) / 10;
                p1 = p1->prev;
                c1 = insertbeg(c1, m);
            }
            if (c != 0)
            {
                c1 = insertbeg(c1, c);
                c = 0;
            }
            t2 = t2->prev;
            n++;
        }
        else
        {
            while (p1 != NULL)
            {
                m = ((p1->data * t2->data) + c) % 10;
                c = ((p1->data * t2->data) + c) / 10;
                p1 = p1->prev;
                c2 = insertbeg(c2, m);
            }
            int i = n;
            while (i)
            {
                c2 = append(c2, 0);
                i--;
            }
            if (c != 0)
            {
                c2 = insertbeg(c2, c);
                c = 0;
            }
            c3 = addition(c1, c2);
            c1 = destroy(c1);
            c1 = c3;
            c3 = NULL;
            t2 = t2->prev;
            n++;
        }
    }
    return c1;
}

node *division(node *a, node *b)
// to divide two numbers
{
    // r is to temporarily store the substracted term
    list r = NULL;
    // q is the list to store the final quotient
    list q = NULL;
    //p1 and p2 are the two numbers
    node *p1 = a;
    node * p2 = b;
    // mp is the list to temporarily store the quotient
    list mp = NULL;
    // pr is the list to temporarily store the product of divisor and current quotient
    list pr = NULL;
    int a1 = 0;
    int n = compare(a, b);
    int n1;
    // if the divisor is zero
    if (count(b) == 1 && b->data == 0)
    {
        printf("Error");
    }
    // if the divisor is bigger than the dividend
    else if (n == 3 || n == 1)
    {
        q = append(q, 0);
    }
    // if both numbers are equal
    else if (n == 0)
    {
        q = append(q, 1);
    }
    else
    {
        // to bring down the digits from dividend according to the divisor
        for (int i = 0; i < count(b); i++)
        {
            r = append(r, p1->data);
            p1 = p1->next;
        }
        // to check for a number which is just greater than the divisor
        for (int i = 1; i < 10; i++)
        {
            mp = append(mp, i);
            pr = multiply(p2, mp);
            n1 = compare(r, pr);
            a1++;
            if (n1 == 3 || n1 == 1)
            {
                break;
            }
            mp = destroy(mp);
            pr = destroy(pr);
        }
        mp = destroy(mp);
        pr = destroy(pr);
        mp = append(mp, a1 - 1);
        pr = multiply(p2, mp);
        r = substract(r, pr);
        q = append(q, a1 - 1);
        mp = destroy(mp);
        pr = destroy(pr);
        a1 = 0;
        while (p1 != NULL)
        {
            r = append(r, p1->data);
            for (int i = 1; i <= 10; i++)
            {
                mp = append(mp, i);
                pr = multiply(p2, mp);
                n1 = compare(r, pr);
                a1++;
                if (n1 == 3 || n1 == 1)
                {
                    break;
                }
                mp = destroy(mp);
                pr = destroy(pr);
            }
            mp = destroy(mp);
            pr = destroy(pr);
            mp = append(mp, a1 - 1);
            pr = multiply(p2, mp);
            r = substract(r, pr);
            q = append(q, a1 - 1);
            mp = destroy(mp);
            pr = destroy(pr);
            p1 = p1->next;
            a1 = 0;
        }
// to remove the zeros in front of the actual numbers
        q = rem_zeros(q);
    }
    return q;
}

list modulo(list a, list b)
// to find the remainder of two numbers
{
    list q = division(a, b);
    list pr = multiply(q, b);
    list r = substract(a, pr);
    return r;
}

list power(list base, list exp)
// to find the power of the number
{
    node *t = tail(exp);
    int n = count(exp);
    int num = 0;
    // to convert the list of exponent to a number
    for (int i = 0; i < n; i++)
    {
        num += (t->data) * pow(10, i);
        t = t->prev;
    }
    list c1, c2;
    c1 = NULL;
    c2 = NULL;
    for (int j = 0; j < num - 1; j++)
    {
        if (c1 == NULL)
        {
            c1 = multiply(base, base);
        }
        else
        {
            c2 = multiply(c1, base);
            c1 = NULL;
            c1 = c2;
            c2 = NULL;
        }
    }
    return c1;
}

void evaluate(list L1, list L2, char *a)
// for evaluating an expression which contaons two numbers
{
    L1 = NULL;
    L2 = NULL;
    list ans;
    int i = 0;
    char op;
    while (a[i] != '\0')
    {
        if (!operat(a[i]))
        {
            L1 = append(L1, a[i] - '0');
            i++;
        }
        else
        {
            op = a[i];
            i++;
            while (a[i] != '\0')
            {
                L2 = append(L2, a[i] - '0');
                i++;
            }
        }
    }
    switch (op)
    {
    case '+':
        ans = addition(L1, L2);
        break;
    case '-':
        ans = substract(L1, L2);
        break;
    case '*':
        ans = multiply(L1, L2);
        break;
    case '/':
        ans = division(L1, L2);
        break;
    case '%':
        ans = modulo(L1, L2);
        break;
    case '^':
        ans = power(L1, L2);
        break;
    default:
        printf("Operator not identified");
        break;
    }
    traverse(ans);
}

void eval_exp(char *a)
// to evaluate an expression
{
    list c1 ;
    init(c1);
    list c2 ;
    init(c2);
    list c3 ;
    init(c3);
    list c4 ;
    init(c4);
    // s1 and s2 are two stacks used to store doubly linked list of number and operator
    Num_Stack s1;
    char_Stack s2;
    init_Num(s1);
    init_char(s2);
    int i = 0;
    char op;
    while (a[i] != '\0')
    {
        if (!operat(a[i]))
        {
            c1 = append(c1, a[i] - '0');
            i++;
        }
        else
        {
            push_Num(s1, c1);
            c1 = NULL;
            if (prec(a[i]) > prec(peek_op(s2)))
            {
                push_char(s2, a[i]);
                i++;
            }
            else
            {
                op = pop_char(s2);
                c2 = pop_Num(s1);
                c3 = pop_Num(s1);
                switch (op)
                {
                case '+':
                    c4 = addition(c3, c2);
                    break;
                case '-':
                    c4 = substract(c3, c2);
                    break;
                case '*':
                    c4 = multiply(c3, c2);
                    break;
                case '/':
                    c4 = division(c3, c2);
                    break;
                case '%':
                    c4 = modulo(c3, c2);
                    break;
                case '^':
                    c4 = power(c3, c2);
                    break;
                default:
                    printf("Operator not identified.");
                    break;
                }
                push_Num(s1, c4);
                c2 = NULL;
                c3 = NULL;
                c4 = NULL;
            }
        }
    }
    while (!isEmpty_op(s2))
    // when are operators remaining in the stack
    {
        push_Num(s1, c1);
        op = pop_char(s2);
        c2 = pop_Num(s1);
        c3 = pop_Num(s1);
        switch (op)
        {
        case '+':
            c4 = addition(c3, c2);
            break;
        case '-':
            c4 = substract(c3, c2);
            break;
        case '*':
            c4 = multiply(c3, c2);
            break;
        case '/':
            c4 = division(c3, c2);
            break;
        case '%':
            c4 = modulo(c3, c2);
            break;
        case '^':
            c4 = power(c3, c2);
            break;
        default:
            printf("Operator not identified.");
            break;
        }
        push_Num(s1, c4);
        c2 = NULL;
        c3 = NULL;
        c4 = NULL;
    }
    traverse(pop_Num(s1));
}
