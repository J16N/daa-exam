#include <stdio.h>
#define INF 999999
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void maxmin(int, int, int [], int *, int *);

int main(void)
{
    int T; // total number of testcases 
    scanf("%d", &T);
    
    while (T--) {
        int n; // total number of elements in the array
        scanf("%d", &n);
        
        int arr[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        
        int maxEl = -INF, minEl = INF;
        maxmin(0, n - 1, arr, &maxEl, &minEl);
        printf("Maximum Element: %d\n", maxEl);
        printf("Minimum Element: %d\n\n", minEl);
    }
    
    return 0;
}


// @description
//   Finds the maximum and minimum elements in the array 
//   from index low to index high.
//
// @parameter
//   low   : lowest index
//   high  : highest index
//   arr[] : the given array
//   maxEl : global maximum element
//   minEl : global minimum element
//
// @return
//   This function does not return anything.
void maxmin(int low, int high, int arr[], int *maxEl, int *minEl)
{
    if (low == high) {
        *maxEl = MAX(*maxEl, arr[low]);
        *minEl = MIN(*minEl, arr[low]);
        return;
    }
    
    if (low + 1 == high) {
        int tmax = MAX(arr[low], arr[high]);
        int tmin = MIN(arr[low], arr[high]);
        // check between temporary maximum and 
        // temporary minimum elements with the
        // global maximum and global minimum 
        // elements and set accordingly.
        *maxEl = MAX(*maxEl, tmax);
        *minEl = MIN(*minEl, tmin);
        
        return;
    }
    
    int mid = low + (high - low) / 2;
    maxmin(low, mid, arr, maxEl, minEl);
    maxmin(mid + 1, high, arr, maxEl, minEl);
}
