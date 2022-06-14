#include <stdio.h>
#include <stdbool.h>
#define ABS(a) ((a) < 0 ? -(a) : (a))

void nQueen(int, int, int [], int *);
bool place(int, int, int []);
void display(int, int, int []);

int main(void)
{
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n;
        scanf("%d", &n);
        
        printf("\n\t\t%d QUEEN\n", n);
        int board[n];
        int count = 0;
        nQueen(0, n, board, &count);
        if (!count) printf("There is no solution.\n\n\n");
    }
    
    return 0;
}


// @description
//   Recursively finds all possible solution to
//   the n-queen problem
//
// @parameter
//   i       : current row
//   n       : total rows or total columns
//   board[] : Array where each index denotes
//             rows and their corresponding
//             values denotes columns
//   count   : pointer to the total solution count
//             passed by reference from the caller
//
// @return
//   This function does not returns anything
void nQueen(int i, int n, int board[], int *count)
{
    if (i == n) {
        display(++(*count), n, board);
        return;
    }
    for (int j = 0; j < n; ++j) {
        if (place(i, j, board)) {
            board[i] = j;
            nQueen(i + 1, n, board, count);
        }
    }
}


// @description
//   Check whether the given position is valid or not
//
// @parameter
//   i       : current row
//   j       : current column
//   board[] : Array where each index denotes
//             rows and their corresponding
//             values denotes columns
//
// @return
//   If the position is valid return true, otherwise false
bool place(int i, int j, int board[])
{
    for (int r = 0; r < i; ++r) {
        if (board[r] == j || ABS(i - r) == ABS(j - board[r]))
            return false;
    }
    return true;
}


// @description
//   Display the solution of N-Queen problem
//   in a n x n board
//
// @parameter
//   count   : Total solution count
//   n       : Number of rows or number of columns
//   board[] : Array where each index denotes
//             rows and their corresponding
//             values denotes columns
//
// @return
//   This function does not returns anything
void display(int count, int n, int board[])
{
    printf("    Solution-%d\n", count);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%c ", board[i] == j ? 'Q' : '_');
        printf("\n");
    }
    
    printf("\n\n");
}
