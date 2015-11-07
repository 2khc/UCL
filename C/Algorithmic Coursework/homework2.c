#include <stdio.h>
#include <limits.h>

#define V 5

int main(void)
{

}

// A utility function to find the vertex with minimum key value,
// from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // initialise min value
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++)
    {
        if(mstSet[v] == false && key[v] < min)
        {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], int n, int graph[V][V])
{
    printf("Edge  Weight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d      %d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// a function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
    int parent[V]; // array to store constructed MST
    int key[V];    // key values used to pick minimum weight edge in cut
    bool mstSet[V] // to represent set of vertices not yet included in MST

    // initialise all keys as infinite
    for (int count = 0; count < V - 1; count++)
    {
        // pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // add the picked vertex to the MST set
        mstSet[u] = true;

        // update the key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in the MST
        for (int v = 0; v < V; v++)
        {
            // graph[u][v] is non-zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
            // print the constructed MST
            printMST(parent, V, graph);
        }
    }
}
