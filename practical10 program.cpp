
#include <stdio.h>

#define MAX 100

int parent[MAX];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

int main()
{
    int cost[MAX][MAX];
    int n, i, j;
    int min, u, v;
    int edges = 0;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n - 1)
    {
        min = 9999;
        u = -1;
        v = -1;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if(u == -1 || v == -1)
            break;

        if(find(u) != find(v))
        {
            printf("%d - %d : %d\n", u + 1, v + 1, min);

            totalCost += min;
            unionSet(u, v);
            edges++;
        }

        cost[u][v] = 9999;
        cost[v][u] = 9999;
    }

    if(edges != n - 1)
        printf("Graph is not connected!\n");
    else
        printf("\nMinimum Cost = %d\n", totalCost);

    return 0;
}
