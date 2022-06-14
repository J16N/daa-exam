#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int    v1;
    int    v2;
    double wt;
} Edge;

int kruskal(int, Edge [], Edge []);
int compare(const void *, const void *);
int setFind(int, int []);
void setUnion(int, int, int []);

int main(void)
{
    int e; // total number of edges
    scanf("%d", &e);
    
    Edge edges[e];
    for (int i = 0; i < e; ++i) {
        char v1, v2;
        double weight;
        scanf(" %c %c%lf", &v1, &v2, &weight);
        
        edges[i].v1 = v1 - 'A';
        edges[i].v2 = v2 - 'A';
        edges[i].wt = weight;
    }
    
    Edge result[e];
    int total_edges = kruskal(e, edges, result);
    double total_wt = 0;
    
    for (int i = 0; i < total_edges; ++i) {
        Edge e = result[i];
        printf("%c <-> %c = %.2lf\n", 
                'A' + e.v1, 'A' + e.v2, e.wt);
        total_wt += e.wt;
    }
    
    printf("\nTotal Weight = %.2lf\n", total_wt);
    return 0;
}


// @description
//   Finds the minimum spanning tree using 
//   kruskal's algorithm
//
// @parameter
//   e       : Total number of edges in the graph
//   edges[] : Array containing all the edges in the graph
//   result[] : Array that will contain necessary edges 
//              to create the minimum spanning tree
//
// @return
//   This function returns the total numbers of edges
//   in the result array.
int kruskal(int e, Edge edges[], Edge result[])
{
    // arrange all the edges in ascending order
    // according to their weights
    qsort(edges, e, sizeof(Edge), compare);
    
    int set[e];
    for (int i = 0; i < e; ++i)
        set[i] = -1;
    
    int count = 0; // initial count of edges in result;
    for (int i = 0; i < e; ++i) {
        Edge e = edges[i];
        if (setFind(e.v1, set) != setFind(e.v2, set)) {
            setUnion(e.v1, e.v2, set);
            result[count++] = e;
        }
    }
    
    return count;
}


// @description
//   Comparator function for sorting elements
//   int the array in ascending order.
//
// @parameter
//   a : One element in array
//   b : Another element in the array
//
// @return
//   If a < b returns -1.
//   If a = b returns 0.
//   If a > b returns 1.
int compare(const void *a, const void *b)
{
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    int result = 0;
    if (e1->wt < e2->wt) result = -1;
    else if (e1->wt > e2->wt) result = 1;
    return result;
}


// @description
//   Add elements to the set, ie, make 
//   one element child of other
//
// @parameter
//   a     : Given element
//   b     : Given another element
//   set[] : Array containg the elements as its index
//
// @return
//   This function does not return anything
void setUnion(int a, int b, int set[])
{
    int pa = setFind(a, set); // parent of a
    int pb = setFind(b, set); // parent of b
    int count = set[pa] + set[pb];
    
    // Since root nodes store the count
    // of all nodes connected to itself
    // in negative, so a lower count
    // usually means a higher value.
    if (set[pa] < set[pb]) {
        set[pa] = count;
        set[pb] = pa;
    }
    else {
        set[pb] = count;
        set[pa] = pb;
    }
}


// @description
//   Find the parent of the given element
//
// @parameter
//   a     : Given element
//   set[] : Array containg the elements as its index
//
// @return
//   Returns the parent of the given element
int setFind(int a, int set[])
{
    if (set[a] < 0) return a;
    set[a] = setFind(set[a], set);
    return set[a];
}
