#include <stdio.h>

void quicksort(int, int, int, int []);
int partition(int, int, int []);
void display(char *, int, int []);
void interchange(int, int, int []);

int main(void)
{
    int T; // total number of testcases
    scanf("%d", &T);
    
    while (T--) {
        int n; // length of the given array
        scanf("%d", &n);
        
        int arr[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
            
        quicksort(0, n - 1, n, arr);
        display("Sorted :: ", n, arr);
        printf("\n");
    }
    
    return 0;
}


// @description
//   Sort the given array from low to high using
//   Quick Sort Algorithm.
//
// @parameter
//   low   : lowest index
//   high  : highest index
//   n     : length of the array
//   arr[] : the given array
//
// @return
//   This function does not return anything.
void quicksort(int low, int high, int n, int arr[])
{
    if (low < high) {
        int mid = partition(low, high, arr);
        display("Pass   :: ", n, arr);
        quicksort(low, mid - 1, n, arr);
        quicksort(mid + 1, high, n, arr);
    }
}


// @description
//   Partition the array taking first element
//   as pivot such that all the elements smaller
//   than pivot is placed its left and all the 
//   element greater than it is placed to its right
//
// @parameter
//   low   : lowest index
//   high  : highest index
//   arr[] : the given array
//
// @return
//   Returns the index of the pivot
int partition(int low, int high, int arr[])
{
    int i = low, j = high + 1;
    int pivot = arr[low];
    
    while (i < j) {
        do ++i; while (i < j && arr[i] < pivot);
        do --j; while (arr[j] > pivot);
        if (i < j) interchange(i, j, arr);
    }
    
    interchange(low, j, arr);
    return j;
}


// @description
//   Print the array.
//
// @parameter
//   label : additional string to print
//           before the array
//   n     : length of the array
//   arr[] : the given array
//
// @return
//   This function returns nothing.
void display(char *label, int n, int arr[])
{
    printf("%s", label);
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


// @description
//   Interchange elements between two index of the array.
//
// @parameter
//   i     : index i
//   j     : index j
//   arr[] : the given array
//
// @return
//   This function returns nothing.
void interchange(int i, int j, int arr[])
{
    if (i == j) return;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
