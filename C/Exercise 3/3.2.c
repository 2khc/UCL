#include <stdio.h>

void rPower(int num,int * result, int power, int depth);
int iPower(int num, int power);

int main(void)
{
    int num, power;
    int method;
    printf("Enter your number: ");
    scanf("%i", &num);
    printf("\nEnter your power: ");
    scanf("%i", &power);

    printf("\nCalculate by recursion (0) or iteration (1)? ");
    scanf("%i",&method);
    int result = num;
    if (method == 0)
    {
        rPower(num,&result,power,0);
    }
    else if (method==1)
    {
        result = iPower(num,power);
    }

    printf("\nThe answer is: %i", result);

    return 0;
}

// iterative power method;s
int iPower(int num, int power)
{
    int i, result = num;
    if (power == 0)
    {
        return 1;
    }

    for (i = 1; i < power; i++)
    {
        result = result * num;
    }
    return result;
}

//recursive power method
void rPower(int num,int *result,  int power, int depth)
{
    depth++;

    int value;
    if (power == 0 )
    {
        *result = 1;
    }
    if (depth < power)
    {
        *result = *result * num;
         rPower(num,result, power, depth);
    }
}
