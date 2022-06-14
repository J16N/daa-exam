#include <stdio.h>
#define INF 999999

void prims(int, int v, int [], double [], double [][v]);
int  minWeight(int, double [], int []);

int main(void)
{
    int vertices;
    scanf("%d", &vertices);
    
    double graph[vertices][vertices];
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j)
            scanf("%lf", &graph[i][j]);
    }
    
    int start = 0;
    double weight[vertices];
    int parent[vertices];
    
    prims(start, vertices, parent, weight, graph);
    
    // print the minimum spanning tree along with
    // the given weight
    double total_wt = 0;
    for (int i = 0; i < vertices; ++i) {
        if (i == start) continue; 
        
        printf("%c <-> %c = %.2lf\n", 
                'A' + parent[i], 'A' + i, weight[i]);
        total_wt += weight[i];
    }
    
    printf("\nTotal Weight: %.2lf\n", total_wt);
    return 0;
}


// @description
//   Find the minimum spanning tree using prims algorithm
//
// @parameter
//   s        : The starting vertex
//   v        : Total number of vertices
//   p[]      : Array containing the parent of every vertex
//   weight[] : Array containing the weights of every vertex
//   g[][]    : The given graph
//
// @return
//   This function does not return anything
void prims(int s, int v, int p[], double weight[], double g[][v])
{
    int visited[v];
    for (int i = 0; i < v; ++i) {
        visited[i] = 0;
        weight[i] = INF;
        p[i] = -1;
    }
    
    weight[s] = 0;
    
    for (int i = 0; i < v; ++i) {
        s = minWeight(v, weight, visited);
        visited[s] = 1;
        
        for (int j = 0; j < v; ++j) {
            if (!visited[j] && g[s][j] && g[s][j] < weight[j]) {
                p[j] = s;
                weight[j] = g[s][j];
            }
        }
    }
}


// @description
//   This function finds the node with minimum weight
//
// @parameter
//   v         : Total number of vertices in the graph
//   weight[]  : Array containing the weights of every vertex
//   visited[] : Array which keeps track of visited vertices
//
// @return
//   Returns the node with the minimum weight
int minWeight(int v, double weight[], int visited[])
{
    int minIdx = -1;
    double minWt = INF;
    
    for (int i = 0; i < v; ++i) {
        if (!visited[i] && weight[i] < minWt) {
            minIdx = i;
            minWt = weight[i];
        }
    }
    return minIdx;
}
