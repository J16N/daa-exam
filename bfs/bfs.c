#include <stdio.h>

void bfs(int, int v, int [][v]);

int main(void)
{
    int v; // total number of vertices in graph
    scanf("%d", &v);
    
    int graph[v][v];
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j)
            scanf("%d", &graph[i][j]);
    }
    
    int start;
    scanf("%d", &start);
    
    bfs(start, v, graph);
    printf("\n");
    return 0;
}


// @description
//   Printing a graph from starting vertex using
//   Breadth First Search
//
// @parameter
//   s         : Starting vertex
//   v         : Total number of vertices in the graph
//   g[][]     : The given graph
//
// @return
//   This function does not return anything
void bfs(int s, int v, int g[][v])
{
    int visited[v];
    for (int i = 0; i < v; ++i)
        visited[i] = 0;
        
    // initialize the queue
    int queue[v * v];
    int front = -1, rear = -1;
    
    // put the vertex into queue
    queue[++rear] = s;
    
    while (front <= rear) {
        s = queue[++front];
        if (visited[s]) continue;
        
        printf("%c ", 'A' + s);
        visited[s] = 1;
        
        for (int i = 0; i < v; ++i) {
            if (!visited[i] && g[s][i])
                queue[++rear] = i;
        }
    }
}
