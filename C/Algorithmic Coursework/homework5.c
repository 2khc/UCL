#include <stdio.h>
#define MAX 50



int main(void)
{
    int size = 3;
    int board[size][size];
    int initLocations[] = {};

int front = -1, rear = -1;


    int queue[MAX];
    insert(queue, 20,&front, &rear);
    display(queue, &front, &rear);




    return 0;
}


void breadthFirstSearch(int size, int Edge, int x)
{
    int seen[size], i;
    int Q[MAX];
    int rear = - 1;
int front = - 1;

    for (i=0;i<size;i++)
    {
        seen[i] = 0;
    }
    insert(Q,x);
    seen[x] = 1;

    while (!isEmpty(Q,front))
    {

    }
}



void insert(int queue_array[],int add_item, int * front, int * rear)
{
//    int add_item;
    if (*rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (*front == - 1)
        /*If queue is initially empty */
        front = 0;
//        printf("Inset the element in queue : ");
//        scanf("%d", &add_item);
        *rear = *rear + 1;
        queue_array[*rear] = add_item;
    }
} /*End of insert()*/

void delete(int queue_array[],int front,int rear)
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} /*End of delete() */
void display(int queue_array[],int * front, int * rear)
{
    int i;
    if (*front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = *front; i <= *rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} /*End of display() */

int isEmpty(int queue_array[], int front)
{
    int i;
    if (front == -1)
        return 1;
    else
    {
        return 0;
    }
}

