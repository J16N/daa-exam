#include <stdio.h>

void heapify(int, int []);
void heapsort(int, int, int []);
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
            
        heapsort(n, n, arr);
        display("Sorted :: ", n, arr);
        printf("\n");
    }
    
    return 0;
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
//   Sort the given array using heap.
// 
// @parameter
//   n      : length of the array after 
//            every pass
//   length : original length of the array
//   arr[]  : the given array
//
// @return
//   This function returns nothing.
void heapsort(int n, int length, int arr[])
{
    // base case for recursion
    // is length is 0
    if (!n) return;
    heapify(n, arr);
    display("Pass   :: ", length, arr);
    interchange(0, n - 1, arr);
    return heapsort(n - 1, length, arr);
}


// @description
//   Create a max heap out of given array
//
// @parameter
//   n     : length of the array
//   arr[] : the given array
//
// @return
//   This function returns nothing
void heapify(int n, int arr[])
{
    for (int i = n / 2 - 1; i >= 0; --i) {
        int a = 2 * i + 1;
        int b = a + 1;
        // check if the last element exist
        if (b == n) {
            // if the i-th element is less
            // than the j-th element then
            // interchange their position
            if (arr[i] < arr[a])
                interchange(i, a, arr);
        }
        else {
            // select whichever of a-th or b-th 
            // element is maximum
            int maxIdx = arr[a] > arr[b] ? a : b;
            // now compare the maximum element
            // with the parent
            if (arr[i] < arr[maxIdx])
                interchange(i, maxIdx, arr);
        }
    }
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
