#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

// function declarations
void calcAdjMatrix(int* values, size_t size, int adjMatrix[size][size]);
void calcResult(size_t adjSize, int adjMatrix[adjSize][adjSize]);
int minKey(size_t adjSize, int edge[], bool vertices[]);
void printAdj(size_t adjSize, int adjMatrix[adjSize][adjSize]);



int main(void)
{
    // Paste in the array from question here.
    int values[] = {5, 5, 9, 6, 3, 8, 6, 8, 4, 5};

    // Get the size of values and store it in valuesSize
    size_t valuesSize = sizeof(values) / sizeof(values[0]);

    // Divide by 2 to get the adjacency matrix size, which is equivalent
    // to the number of vertices we have.
    size_t adjSize = valuesSize / 2;

    // Declare the adjacency matrix of size adjSize x adjSize
    int adjMatrix[adjSize][adjSize];

    int i, j;

    // Calculate adj. matrix and write into adjMatrix defined above.
    calcAdjMatrix(values, adjSize, adjMatrix);

    // Prints out adjMatrix.
    printAdj(adjSize, adjMatrix);

    // Run Prim's algorithm
    calcResult(adjSize, adjMatrix);
}

void printAdj(size_t adjSize, int adjMatrix[adjSize][adjSize])
{
    int i, j;
    for(i = 0; i < adjSize; i++)
    {
        for(j = 0; j < adjSize; j++)
        {
            if (j == adjSize - 1)
            {
                printf("%i\n", adjMatrix[i][j]);
            }
            else
            {
                printf("%i  ", adjMatrix[i][j]);
            }
        }
    }
}

void calcAdjMatrix(int* values, size_t adjSize, int adjMatrix[adjSize][adjSize])
{
    int i, j;

    for (i = 0; i < adjSize; i++)
    {
        for(j = 0; j < adjSize; j++)
        {
            // Calculate the the weighted edges for each edge.
            if (i == j)
            {
                adjMatrix[i][j] = 0;
            }
            else
            {
                adjMatrix[i][j] = abs(values[i * 2] - values[j * 2]) + abs(values[i * 2 + 1] - values[j * 2 + 1]);
            }
        }
    }
}

void calcResult(size_t adjSize, int adjMatrix[adjSize][adjSize])
{
    bool vertices[adjSize]; // to show what vertices have or haven't bee included into the MST
    int i, j;
    int edge[adjSize];      // used to help pick minimum edge
    int sum = 0;            // sum of edges
    int parent[adjSize];
    for (i = 0; i < adjSize; i++)
    {
        edge[i] = INT_MAX;   // Set every value in edge to max integer value.
        vertices[i] = false; // Set all values to false, as no vertices added to tree yet.
    }

    edge[0] = 0;            // set to 0 to initialise tree.

    for (i = 0; i < adjSize - 1; i++)
    {
        // minKey returns the un-added vertex which has the lowest weighted edge.
        // In the first iteration, the lowest key is 0 as we set edge[0] = 0
        int u = minKey(adjSize, edge, vertices);
        vertices[u] = true;                         // set the vertex retrieved from minKey() to 0, to signify it being added to tree

        for(j = 0; j < adjSize; j++)
        {
            if (adjMatrix[u][j] && vertices[j] == false && adjMatrix[u][j] < edge[j])
            {
                edge[j] = adjMatrix[u][j];
                parent[j] = u;                  // add vertex number to parent, which is a list of connected vertices in the order they are added.
            }
        }


    }
    // print results
    printResult(adjSize, parent, adjMatrix);
}

int minKey(size_t adjSize, int edge[], bool vertices[])
{
    int min = INT_MAX, minIndex, i;

    for(i = 0; i < adjSize; i++)
    {
        if(vertices[i] == false && edge[i] < min)
        {
            min = edge[i];
            minIndex = i;
        }
    }
    return minIndex;
}
int printResult(int adjSize, int parent[adjSize],  int adjMatrix[adjSize][adjSize])
{
    int i;
    int value = 0;
    printf("Edge   Weight\n");

    // This loop begins on i = 1 because i = 0 is the first vertex which contains a value we don't want to include.
    for ( i = 1; i < adjSize; i++)
    {
        printf("%d - %d    %d \n", parent[i], i, adjMatrix[i][parent[i]]);
        value += adjMatrix[i][parent[i]];                                     // Add the weighted edge to value.
    }

    printf("The sum of all is : %d.", value);
}
