#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double weight;
    double profit;
    double ppw; // profit per unit weight
} Item;

double fracKnap(int, double, Item []);
int compare(const void *, const void *);


int main(void)
{
    int n;    // total number of items
    double w; // total weight of the knapsack
    scanf("%d%lf", &n, &w);
    
    Item items[n];
    
    for (int i = 0; i < n; ++i) {
        double profit, weight;
        scanf("%lf%lf", &profit, &weight);
        
        items[i].profit = profit;
        items[i].weight = weight;
        items[i].ppw    = profit / weight;
    }
    
    printf("Maximum Profit = %.2lf\n", fracKnap(n, w, items));
    return 0;
}


// @description
//   Finding maximum profit given list of items
//   having their profits and weights each and
//   a fixed knapsack size using greedy algorithm
//
// @parameter
//   n       : Number of items
//   w       : Knapsack size
//   items[] : Array of items
//
// @return
//   Maximum profit taking all the items the 
//   knapsack can hold.
double fracKnap(int n, double w, Item items[])
{
    // sort items in non-increasing order of its
    // profit per unit weight
    qsort(items, n, sizeof(Item), compare);
    double maxProfit = 0;
    
    for (int k = 0; k < n; ++k) {
        Item i = items[k];
        
        if (i.weight > w) {
            maxProfit += (w / i.weight * i.profit);
            break;
        }
        
        maxProfit += i.profit;
        w -= i.weight;
    }
    
    return maxProfit;
}


// @description
//   Comparator function for sorting elements 
//   based on non-increasing order of their 
//   profit per unit weight.
//
// @parameter
//   a : Item from the items array
//   b : Another item from the items array
//
// @return
//   If a < b returns  1
//   If a > b returns -1
//   If a = b returns  0
int compare(const void *a, const void *b)
{
    Item *i1 = (Item *) a;
    Item *i2 = (Item *) b;
    int result = 0;
    
    if (i1->ppw < i2->ppw) result = 1;
    else if (i1->ppw > i2->ppw) result = -1;
    return result;
}
