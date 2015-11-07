#include <stdio.h>
#include <stdbool.h>
void generate(long sum, long numOfDigits, long currNum, long currLen, long * permCount);


int main(void)
{
    long permCount = 0, sum, digits;

    printf("Enter the number of digits: ");
    scanf("%ld", &digits);
    printf("\nEnter the total sum: ");
    scanf("%ld", &sum);

    generate(sum, digits, 0, 0, &permCount);
    printf("The final count is: %ld\n", permCount);

    return 0;
}

void generate(long sum, long numOfDigits, long currNum, long currLen, long *permCount)
{
    currLen++;
    bool maxDepth = currLen == numOfDigits;

    long i = 0;
    for (i = 0; i < 10; i++)
    {
        int currentSum = currNum + i;

        if (maxDepth)
        {
            if (currentSum == sum)
            {
                (*permCount)++;
                printf("%ld\n", *permCount);
                break;
            }

            if (currentSum < sum) continue;

            if (currentSum > sum) return;
        }

        if (!maxDepth)
        {
            if (currentSum <= sum)
            {
                generate(sum, numOfDigits, currentSum, currLen, permCount);
            }
        }
    }
}
