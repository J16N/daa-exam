#include <stdio.h>
#define INF 999999

typedef struct {
    int start;
    int end;
    double dist;
} Edge;

int bellmanFord(int, int, int, int [], double [], Edge []);
void printPath(int, int, int []);

int main(void)
{
    // total no. of vertices and
    // total no. of edges
    int v, e;
    scanf("%d%d", &v, &e);
    
    int parent[v];  // parent array
    double dist[v]; // distance array
    Edge edges[e];  // edges array
    
    for (int i = 0; i < e; ++i) {
        char v1, v2;
        double weight;
        // get the input
        scanf(" %c %c%lf", &v1, &v2, &weight);
        // store it in the array
        edges[i].start = v1 - 'A';
        edges[i].end   = v2 - 'A';
        edges[i].dist  = weight;
    }
    
    char start;
    scanf(" %c", &start);
    
    int cycle = bellmanFord(start - 'A', e, v, parent, dist, edges);
    // if there is no cycle then print the shortest parths
    // to all the vertices from the source
    if (!cycle) {
        for (int i = 0; i < v; ++i) {
            printPath(0, i, parent);
            printf("%.2lf\n", dist[i]);
        }
    }
    else
        printf("There is a negative edge cycle in this graph.\n");
    return 0;
}


// @description
//   Find the single source shortest path using 
//   bellmanford algorithm
//
// @parameter
//   s       : starting vertex
//   e       : total number of edges
//   v       : total number of vertices
//   p[]     : array containing all the parent of every vertex
//   d[]     : array containing all the minimum distances 
//             of every vertex
//   edges[] : array containing the edges
//
// @return
//   Returns whether the graph contains cycle or not
int bellmanFord(int s, int e, int v, int p[], double d[], Edge edges[])
{
    // initialize all the parent to NULL
    // and all the distance to INFINITY
    for (int i = 0; i < v; ++i) {
        p[i] = -1;
        d[i] = INF;
    }
    
    // set distance of the starting vertex to 0
    d[s] = 0;
    
    for (int i = 0; i < v - 1; ++i) {
        for (int j = 0; j < e; ++j) {
            Edge edge = edges[j];
            double new_dist = d[edge.start] + edge.dist;
            
            // if the new distance is less than
            // the original distance then update
            // the distance and the parent
            if (new_dist < d[edge.end]) {
                d[edge.end] = new_dist;
                p[edge.end] = edge.start;
            }
        }
    }
    
    // check for the negative cycle
    for (int j = 0; j < e; ++j) {
        Edge edge = edges[j];
        double new_dist = d[edge.start] + edge.dist;
        
        // even after v - 1 times, we can
        // relax an edge so there must be
        // a negative cycle associated with
        // this edge
        if (new_dist < d[edge.end])
            return 1;
    }
    
    return 0;
}


// @description
//   Print the the path from source to vertex
//
// @parameter
//   c   : an arbitrary variable that is used
//         to keep track of the last vertex 
//         and prints "->" or "=" accordingly
//   i   : destination vertex
//   p[] : parent array
//
// @return
//   This function does not return anything
void printPath(int c, int i, int p[])
{
    if (i == -1) return;
    
    // when the i is the source vertex 
    // as well as the destination
    if (p[i] == -1 && !c) {
        printf("%c -> %c = ", 
            'A' + i, 'A' + i);
        return;
    }
    
    printPath(c + 1, p[i], p);
    printf("%c%s", 'A' + i, c ? " -> " : " = ");
}
