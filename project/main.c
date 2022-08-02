#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

int main()
{
    char a[1000];
    while (1)
    {
        printf("Enter the expression : ");
        scanf("%s", a);
        list L1, L2;
        evaluate(L1, L2, a);
    }
    return 0;
}