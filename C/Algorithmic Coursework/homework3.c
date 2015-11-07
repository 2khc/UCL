#include <stdio.h>
#include <stdlib.h>

void quicksort(int list[], int m, int n);
void find(int tickets[], int numOfElements, int target);
int populateTickets (int* tickets, int initTicketNum, int nthPerson);


int main(void)
{
    int initTicketNum, finalTicket;
//    int index;
long nthPerson;

    printf("Enter the initial ticket number: ");
    scanf("%i", &initTicketNum);
    printf("\nHow many people are there? ");
    scanf("%ld", &nthPerson);

    int tickets[nthPerson];
    finalTicket = populateTickets(tickets, initTicketNum, nthPerson);

    printf("Final ticket is %i\n", finalTicket);
    quicksort(tickets, 0, nthPerson - 1);

    int i;
    for (i = 0; i < nthPerson; i++)
        printf("%i\n", tickets[i]);

    find(tickets, nthPerson, finalTicket);
}

void find(int tickets[], int numOfElements, int target)
{
    int i;

    for (i = 0; i < numOfElements; i++)
    {
//        printf("function runs fine");
        if (strcmp(&tickets[i], &target) == 0 && strcmp(&tickets[i+1],&target)!=0)
        {
            printf("Found at %i\n", i+1);
            break;
        }

    }
    if (i >= numOfElements)
    {
        printf("Not found\n");
    }
}

int calcTicket(int prevTicket)
{
    return (prevTicket * 31334) % 31337;
}

int populateTickets (int* tickets, int initTicketNum, int nthPerson)
{
//    tickets[index] = currTicket;
    int index, finalTicketNum;
    int currentTicket = initTicketNum;
    tickets[0] = currentTicket;

    for (index = 1; index < nthPerson; index++)
    {
        currentTicket = calcTicket(currentTicket);
        tickets[index] = currentTicket;
        if (index == nthPerson - 1)
            finalTicketNum = currentTicket;
        printf("%i\n", currentTicket);
    }

    return finalTicketNum;
}


int pivot(int i, int j)
{
    return (i + j) / 2;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int list[], int m, int n)
{
    int key, i, j, k;

    if (m < n)
    {
        k = pivot(m, n);
        swap(&list[m], &list[k]);
        key = list[m];
        i = m + 1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
                swap(&list[i], &list[j]);
        }

        swap(&list[m], &list[j]);

        quicksort(list, m, j - 1);
        quicksort(list, j + 1, n);
    }
}


