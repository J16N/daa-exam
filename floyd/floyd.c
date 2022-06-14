#include <stdio.h>
#define INF 999999

int floydWarshall(int v, int [][v], double [][v]);
void printPath(int, int, int []);

int main(void)
{
    int v; //number of vertices
    scanf("%d", &v);
    
    int    parent[v][v];
    double distance[v][v];
    
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
           double dist = INF;
           scanf("%lf", &dist);
           
           distance[i][j] = dist;
           // if the distance is 0 or infinity then the parent
           // of that vertex is set to NULL.
           parent[i][j] = !dist || (int) dist == INF ? -1 : i; 
        }
    }
    
    int cycle = floydWarshall(v, parent, distance);
    // if there is no cycle print all pair of 
    // shortest path
    if (!cycle) {
        // print all pair of shortest path
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                printPath(0, j, parent[i]);
                printf("%.2lf\n", distance[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("This graph contains negative cycle.\n");
    return 0;
}


// @description
//   Finds all source shortest path in the 
//   graph using floyd-warshall algorithm.
//
// @parameter
//   v     : total number of vertices
//   p[][] : array used to store parent
//           of every vertices
//   d[][] : array used to store minimum
//           distances to reach every vertex
//
// @return
//   Returns whether the graph contains 
//   cycle or not.
int floydWarshall(int v, int p[][v], double d[][v])
{
    for (int j = 0; j < v; ++j) {
        // Here j is the intermediate vertex
        for (int i = 0; i < v; ++i) {
            // Here i is the source vertex.
            // Going from source vertex through
            // intermediate vertex when they are same
            // will give the same outcome. 
            // So we skip it.
            if (i == j) continue;
            
            for (int k = 0; k < v; ++k) {
                // Here k is the destination vertex
                // Going to the destination vertex via
                // the same intermediate vertex produces
                // the same outcome so we skip it.
                if (k == j) continue;
                
                double new_d = d[i][j] + d[j][k];
                if (new_d < d[i][k]) {
                    d[i][k] = new_d;
                    p[i][k] = p[j][k];
                }
            }
        }
    }
    
    int cycle = 0;
    // check for the negative cycle if present
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            // if the diagonal elements are
            // non-zero then there is a cycle
            if (i == j && d[i][j]) {
                cycle = 1;
                break;
            }
        }
    }
    
    return cycle;
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
        printf("%d -> %d = ", 
            i + 1, i + 1);
        return;
    }
    
    printPath(c + 1, p[i], p);
    printf("%d%s", i + 1, c ? " -> " : " = ");
}
