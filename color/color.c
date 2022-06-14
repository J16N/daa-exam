#include <stdio.h>
#include <stdbool.h>

void display(int, int, int []);
bool check(int, int n, int [], int [][n]);
void mColoring(int, int, int n, int[], int [][n], int *);

int main(void)
{
    int n; // number of vertices
    scanf("%d", &n);
    
    int color[n], graph[n][n];
    // get input of the graph
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &graph[i][j]);
    }
    
    int T; // number of test cases
    scanf("%d", &T);
    
    while (T--) {
        int m; // total number of colors
        scanf("%d", &m);
        printf("\n\t\t%d Colors\n", m);
        int count = 0;
        mColoring(0, m, n, color, graph, &count);
        if (!count)
            printf("Not possible to color the given graph with %d color%s.\n", 
                    m, m > 1 ? "s" : "");
    }
    
    return 0;
}


// @description
//   Prints all possible ways to properly color the graph with a given
//   number of colors. Proper coloring means no two adjacent vertices
//   having same color.
//
// @parameter
//   i         : Current vertex
//   m         : Total number of colors
//   n         : Total number of vertices
//   color[]   : Array to store all the colors of the vertices
//   graph[][] : Given graph
//   count     : Total solution count. This variable is passed by reference
//               from the caller.
//
// @return
//   This function does not return anything.
void mColoring(int i, int m, int n, int color[], int graph[][n], int *count)
{
    if (i == n) {
        display(++(*count), n, color);
        return;
    }
    
    for (int j = 1; j <= m; ++j) {
        color[i] = j;
        if (check(i, n, color, graph))
            mColoring(i + 1, m, n, color, graph, count);
    }
}


// @description
//   Check the proper coloring of the graph
//
// @parameter
//   i         : Current vertex of the graph
//   n         : Total vertex of the graph
//   color[]   : Array that holds all the unique colors
//               to the vertices
//   graph[][] : Given graph
//
// @return
//   If all the vertices upto the current vertex is 
//   properly colored, returns true otherwise false
bool check(int i, int n, int color[], int graph[][n])
{
    for (int j = 0; j < i; ++j) {
        if (graph[i][j] && color[i] == color[j])
            return false;
    }
    return true;
}


// @description
//   Display all possible colors of the graph
//
// @parameter
//   count   : Total count of the solution
//   n       : Number of vertices
//   color[] : Array that holds all the unique colors
//             to the vertices
//
// @return
//   This function does not return anything
void display(int count, int n, int color[])
{
    printf("%3d.  ", count);
    for (int i = 0; i < n; ++i)
        printf("%d ", color[i]);
    printf("\n");
}
