#include <stdio.h>
#define INF 999999

void matChainMul(int n, int[], int [][n], int [][n]);
void printMatOrder(int, int, int n, int [][n]);

int main(void)
{
    int n;
    scanf("%d", &n);
    
    // p stores the dimension of i-th matrix
    // a p[i-1] x p[i]. 
    int p[n + 1];
    for (int i = 0; i < n + 1; ++i)
        scanf("%d", p + i);
    
    // cost stores all the lowest possible cost
    // for multiplying matrices taking 2, 3, ..., n
    // at a time.
    //
    // s stores the optimal parenthesizing position
    // while multiplying matrices taking 2, 3, ..., n
    // at a time.
    int cost[n][n], s[n][n];
    // Initialize cost to infinity except the 
    // diagonal elements and initialize s to 0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cost[i][j] = i == j ? 0 : INF;
            s[i][j] = 0;
        }
    }
    matChainMul(n, p, cost, s);
    printMatOrder(0, n - 1, n, s);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", s[i][j]);
        printf("\n");
    }
    printf("\nTotal Operations = %d\n", cost[0][n - 1]);
    return 0;
}


// @description
//   This function finds minimum number of operations required
//   to multiply the given matrix chain
//
// @parameter
//   n        : number of matrix
//   p[]      : array containing all the dimension of the matrix chain.
//              the dimension of ith matrix is p[i-1] x p[i]
//   cost[][] : cost of all matrices stored where cost[i][j]
//              denotes the operations required for multiplying
//              A-ith to A-jth matrices
//   s[][]    : array containing partition of every possible
//              matrix multiplication. This partition is used 
//              for optimal parenthesizing
void matChainMul(int n, int p[], int cost[][n], int s[][n])
{
    for (int len = 1; len < n; ++len) {
        for (int j = len; j < n; ++j) {
            int i = j - len;
            for (int k = i; k < j; ++k) {
                int new_cost = (
                    cost[i][k] + 
                    cost[k + 1][j] +
                    p[i] * p[k + 1] * p[j + 1]
                );
                if (new_cost < cost[i][j]) {
                    cost[i][j] = new_cost;
                    s[i][j] = k;
                }
            }
        }
    }
}


// @description
//   Print matrix chain with optimal parenthesization.
//
// @parameter
//   i     : start index
//   j     : end index
//   n     : number of matrices
//   s[][] : array containing partition of every possible
//           matrix multiplication. This partition is used 
//           for optimal parenthesizing
//
// @return
//   This function doesn't return anything
void printMatOrder(int i, int j, int n, int s[][n])
{
    if (i == j) {
        printf("A%d", i + 1);
        return;
    }
    printf("(");
    printMatOrder(i, s[i][j], n, s);
    printMatOrder(s[i][j] + 1, j, n, s);
    printf(")");
}
