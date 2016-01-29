/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials
*/
//#include "simpletools.h"                      // Include simple tools
//#include "abdrive.h"
#include <stdlib.h>
#include <stdio.h>

int main()                                    // Main function
{
    int numOfElem;

    printf("Enter the number of elements:\n");
    scanf("%i", &numOfElem);
    int numbers[numOfElem];
    printf("\nEnter %i integers\n", numOfElem);

    int i;
    for (i = 0; i < numOfElem; i++)
    {
        scanf("%i", &numbers[i]);
    }

    bubbleSort(numbers, numOfElem);
    printf("Sorted array: ");
    printArray(numbers);

}

int bubbleSort(int numbers[], int numOfElem)
{
    int swapped = 1,
        i,
        temp,
        n = numOfElem,
        iterCount = 0;
    while(swapped)
    {
        swapped = 0;
        for (i = 1; i < n; i++)
        {
            iterCount++;
            if (numbers[i - 1] > numbers[i])
            {
                temp = numbers[i - 1];
                numbers[i - 1] = numbers[i];
                numbers[i] = temp;
                swapped = 1;
//                printf(")
            }
            printf("Iteration %i: ", iterCount);
            printArray(numbers, numOfElem);
        }
        n = n - 1;

    }
//    return *numbers;
}

int printArray(int numbers[], int numOfElem)
{
    int i;
    for (i = 0; i < numOfElem; i++)
    {
        printf("%i", numbers[i]);
    }
    printf("\n");
}
