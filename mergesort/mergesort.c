#include <stdio.h>
#define INF 999999

void mergesort(int, int, int, int []);
void merge(int, int, int, int []);
void display(char *, int, int[]);

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
            
        mergesort(0, n - 1, n, arr);
        display("Sorted :: ", n, arr);
        printf("\n");
    }
    
    return 0;
}


// @description
//   Sort the given array using merge sort algorithm
//
// @parameter
//   low   : lowest index
//   high  : highest index
//   n     : length of the array
//   arr[] : the given array
//
// @return
//   This function does not return anything
void mergesort(int low, int high, int n, int arr[])
{
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergesort(low, mid, n, arr);
        mergesort(mid + 1, high, n, arr);
        merge(low, mid, high, arr);
        display("Pass   :: ", n, arr);
    }
}


// @description
//   Merge the two arrays given such that
//   L[low : mid] and H[mid+1 : high]. The final
//   array A[low : high] is sorted.
//
// @parameter
//   low   : lowest index
//   mid   : middle index
//   high  : highest index
//   arr[] : the given array
//
// @return
//   This function does not return anything
void merge(int low, int mid, int high, int arr[])
{
    // number of elements in left and right array
    int n1 = mid - low + 1, n2 = high - mid;
    // initialize the left array and right array
    // left array contains elements from low to mid
    // right array contains elements from mid+1 to high
    int left[n1 + 1], right[n2 + 1];
    // the last elements are intialized to infinity
    left[n1] = INF;
    right[n2] = INF;
    // copy elements to left and right array
    for (int i = 0; i < n1; ++i) 
        left[i] = arr[low + i];
    for (int i = 0; i < n2; ++i) 
        right[i] = arr[mid + 1 + i];
    
    // copy the elements from low to high back to the
    // original array
    for (int i = 0, j = 0, k = low; k <= high; ++k)
        arr[k] = left[i] < right[j] ? left[i++] : right[j++];
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
