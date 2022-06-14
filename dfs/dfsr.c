#include <stdio.h>

void dfs(int, int v, int [], int [][v]);

int main(void)
{
    int v; // number of vertices
    scanf("%d", &v);
    
    int graph[v][v];
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j)
            scanf("%d", &graph[i][j]);
    }
    
    int start; //starting vertex
    scanf("%d", &start);
    
    int visited[v]; // initialize to all false
    for (int i = 0; i < v; ++i) visited[i] = 0;
    
    dfs(start, v, visited, graph);
    printf("\n");
    return 0;
}


// @description
//   Printing a graph from starting vertex using
//   Depth First Search
//
// @parameter
//   s         : Starting vertex
//   v         : Total number of vertices in the graph
//   visited[] : Array that keeps track of which 
//               vertices are already visited
//   g[][]     : The given graph
//
// @return
//   This function does not return anything
void dfs(int s, int v, int visited[], int g[][v])
{
    printf("%c ", 'A' + s);
    visited[s] = 1;
    
    for (int i = 0; i < v; ++i) {
        // if there is an edge between
        // vertex s and vertex i and the
        // vertex i is not visited then
        // recurse
        if (!visited[i] && g[s][i]) 
            dfs(i, v, visited, g);
    }
}
