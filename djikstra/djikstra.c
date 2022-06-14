#include <stdio.h>
#define INF 999999

void djikstra(int, int v, int [], double [], double [][v]);
int minDistance(int, int [], double []);
void printPath(int, int, int []);

int main(void)
{
    int vertices;
    scanf("%d", &vertices);
    
    double graph[vertices][vertices];
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) 
            scanf("%lf", &graph[i][j]);
    }
    
    int start;
    scanf("%d", &start);
    
    int parent[vertices];
    double distance[vertices];
    
    djikstra(start, vertices, parent, distance, graph);
    
    for (int i = 0; i < vertices; ++i) {
        if (i == start) continue;
        printPath(0, i, parent);
        printf("%.2lf\n", distance[i]);
    }
    
    return 0;
}


// @description
//   This function finds the minimum node.
//
// @parameter
//   v         : Total number of vertices in the given graph
//   visited[] : Array keeping track of which nodes 
//               are already visited.
//   dist[]    : Array containing the minimum distance to the
//               particular node
//
// @return
//   Returns the node with the minimum distance that
//   is not yet visited.
int minDistance(int v, int visited[], double dist[])
{
    int minIdx = -1;
    double minDist = INF;
    
    for (int i = 0; i < v; ++i) {
        if (dist[i] < minDist && !visited[i]) {
            minIdx = i;
            minDist = dist[i];
        }
    }
    
    return minIdx;
}


// @description
//   Find the shortest path from source to destination using
//   djikstra algorithm.
//
// @parameter
//   s        : The starting vertex
//   v        : Total number of vertices
//   parent[] : Array containing the parent of all the nodes
//   dist[]   : Array containing the minimum distance to the
//              particular node
//   g[][]    : The given graph
//
// @return
//   This function does not return anything
void djikstra(int s, int v, int parent[], double dist[], double g[][v])
{
    int visited[v];
    
    for (int i = 0; i < v; ++i) {
        parent[i] = -1;
        dist[i] = INF;
        visited[i] = 0;
    }
    
    dist[s] = 0;
    
    for (int i = 0; i < v; ++i) {
        // get the node with minimum distance
        s = minDistance(v, visited, dist);
        visited[s] = 1; // set visited to true
        
        for (int j = 0; j < v; ++j) {
            //    3 conditions:
            // a. The graph has a path from s to j.
            // b. The node j is not visited.
            // c. Distance of j through s is less than the
            //    present distance of j
            if (!visited[j] && g[s][j] && dist[s] + g[s][j] < dist[j]) {
                parent[j] = s;
                dist[j] = dist[s] + g[s][j];
            }
        }
    }
}


// @description
//   Print the shortest path from the source to the description.
//
// @parameter
//   count    : Keeps track of current vertex. If it is the last
//              last vertex then print '='
//   v        : Current vertex
//   parent[] : Array where the parent of all the vertices
//              are stored.
//
// @return
//   This function does not return anything.
void printPath(int count, int v, int parent[])
{
    if (v == -1) return;
    printPath(count + 1, parent[v], parent);
    printf("%c%s", 'A' + v, count ? " -> " : " = ");
}
