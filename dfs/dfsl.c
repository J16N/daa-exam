#include <stdio.h>

void dfs(int, int v, int [][v]);

int main(void)
{
    int v; // number of vertices in graph
    scanf("%d", &v);
    
    int graph[v][v];
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j)
            scanf("%d", &graph[i][j]);
    }
    
    int start;
    scanf("%d", &start);
    
    dfs(start, v, graph);
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
//   g[][]     : The given graph
//
// @return
//   This function does not return anything
void dfs(int s, int v, int g[][v])
{
    int visited[v];
    for (int i = 0; i < v; ++i)
        visited[i] = 0;
        
    // initialize the stack
    int stack[v];
    int top = -1;
    
    // insert s into stack
    stack[++top] = s;
    
    while (top >= 0) {
        s = stack[top--];
        if (visited[s]) continue;
        
        printf("%c ", 'A' + s);
        visited[s] = 1;
        
        for (int i = 0; i < v; ++i) {
            // if there is an edge between
            // vertex s and vertex i and the
            // vertex i is not visited then
            // put it into stack
            if (!visited[i] && g[s][i])
                stack[++top] = i;
        }
    }
}
