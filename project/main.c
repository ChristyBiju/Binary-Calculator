#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

int main()
{
    char a[1000];
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t**********************************************\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t Christy Biju\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t MIS : 112003031\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t DSA-I Project\n");
    printf("\t\t\t\t\t\t\t\t\t**********************************************\n\n");

    while (1)
    {
        printf("\n >> ");
        scanf("%s", a);
        if(strcmp(a,"q") == 0 || strcmp(a,"quit") == 0){
            break;
        }
        eval_exp(a);
        printf("\n");
    }
    return 0;
}