// C code to implement Kruskal's algorithm

#include <stdio.h>
#include <stdlib.h>

// Comparator function to use in sorting
int comparator(const int p1[], const int p2[])
{
    return p1[2] - p2[2];
}

// Initialization of parent[] and rank[] arrays
void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Function to find the parent of a node
int findParent(int parent[], int component)
{
    if (parent[component] == component)
        return component;

    return parent[component]
           = findParent(parent, parent[component]);
}

// Function to unite two sets
void unionSet(int u, int v, int parent[], int rank[], int n)
{
    // Finding the parents
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;

        // Since the rank increases if
        // the ranks of two sets are same
        rank[u]++;
    }
}

// Function to find the MST
int kruskalAlgo(int n, int edge[n][3])
{
    // First we sort the edge array in ascending order
    // so that we can access minimum distances/cost
    qsort(edge, n, sizeof(edge[0]), comparator);

    int parent[n];
    int rank[n];

    // Function to initialize parent[] and rank[]
    makeSet(parent, rank, n);

    // To store the minimun cost
    int minCost = 0;
    for (int i = 0; i < n; i++) {
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];

        // If the parents are different that
        // means they are in different sets so
        // union them
        if (v1 != v2) {
            unionSet(v1, v2, parent, rank, n);
            minCost += wt;
        }
    }

    return minCost;
}

// Insert an edge
void insertEdge(int edge[][3], int *n, int u, int v, int weight)
{
    edge[*n][0] = u;
    edge[*n][1] = v;
    edge[*n][2] = weight;

    (*n)++;
}

// Delete an edge
void deleteEdge(int edge[][3], int *n, int u, int v)
{
    for (int i = 0; i < *n; i++) {
        if ((edge[i][0] == u && edge[i][1] == v) ||
            (edge[i][0] == v && edge[i][1] == u)) {

            // Shift remaining edges left
            for (int j = i; j < *n - 1; j++) {
                edge[j][0] = edge[j + 1][0];
                edge[j][1] = edge[j + 1][1];
                edge[j][2] = edge[j + 1][2];
            }

            (*n)--;
            return;
        }
    }

    printf("Edge not found\n");
}

// Driver code
int main()
{
    int edge[10][3] = {
        { 0, 1, 10 },
        { 0, 2, 6 },
        { 0, 3, 5 },
        { 1, 3, 15 },
        { 2, 3, 4 }
    };

    int n = 5;

    // Insert edge: 1 -- 2 with weight 7
    insertEdge(edge, &n, 1, 2, 7);

    // Delete edge: 0 -- 3
    deleteEdge(edge, &n, 0, 3);

    printf("Minimum cost = %d\n", kruskalAlgo(n, edge));

    return 0;
}
