#include <stdio.h>
#include <stdlib.h>

void quicksort(long long int list[], long long int m, long long int n);
void find(long long int tickets[], long long int numOfElements, long long int target);
long long int populateTickets (long long int* tickets, long long int initTicketNum, long long int nthPerson);
long long int binarySearch(long long int tickets[], long long int target, long long int start, long long int end);
long long int getResult(long long int tickets[], long long int numOfPeople, long long int start);



int main(void)
{
    long long int initTicketNum, finalTicket;
    long long int nthPerson;

    printf("Enter the initial ticket number: ");
    scanf("%llu", &initTicketNum);
    printf("\nHow many people are there? ");
    scanf("%llu", &nthPerson);

    long long *tickets = calloc(nthPerson + 1, sizeof * tickets);

    finalTicket = populateTickets(tickets, initTicketNum, nthPerson);

    printf("Final ticket is %llu\n", finalTicket);
    quicksort(tickets, 0, nthPerson - 1);

    long long int i;

    long long int answer = getResult(tickets, nthPerson, binarySearch(tickets, finalTicket, 0, nthPerson - 1));

    printf("Your answer should be: %llu\n", answer + 1);
}

long long int getResult(long long int tickets[], long long int numOfPeople, long long int start)
{
    long long int i;
    for (i = start; i < numOfPeople; i++)
    {
        if (tickets[i] != tickets[i + 1])
        {
            return i;
        }
    }
}

long long int calcTicket(long long int prevTicket)
{
    return (prevTicket * 31334) % 31337;
}

long long int populateTickets (long long int* tickets, long long int initTicketNum, long long int nthPerson)
{
    long long int index, finalTicketNum;
    long long int currentTicket = initTicketNum;
    tickets[0] = currentTicket;

    for (index = 1; index < nthPerson; index++)
    {
        currentTicket = calcTicket(currentTicket);
        tickets[index] = currentTicket;
        if (index == nthPerson - 1)
            finalTicketNum = currentTicket;
        printf("%llu\n", currentTicket);
    }

    return finalTicketNum;
}


long long int pivot(long long int i, long long int j)
{
    return (i + j) / 2;
}

void swap(long long int *x, long long int *y)
{
    long long int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(long long int list[], long long int m, long long int n)
{
    long long int key, i, j, k;

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

long long int binarySearch(long long int tickets[], long long int target, long long int start, long long int end)
{
    if (start > end)
    {
        return -1;
    }

    long long int middle = (start + end) / 2;
    long long int value = tickets[middle];

    if (value > target)
    {
        return binarySearch(tickets, target, start, middle - 1);
    }
    if (value < target)
    {
        return binarySearch(tickets, target, middle + 1, end);
    }

    return middle; //found
}


