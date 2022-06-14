#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int    id;
    double profit;
    int    deadline;
} Job;

int JSD(int, Job [], int []);
void insertionSort(int, Job []);

int main(void)
{
    int n; // number of jobs
    scanf("%d", &n);
    Job jobs[n];
    int result[n];
    
    for (int i = 0; i < n; ++i) {
        double profit;
        int deadline;
        scanf("%lf%d", &profit, &deadline);
        
        jobs[i].id       = i + 1;
        jobs[i].profit   = profit;
        jobs[i].deadline = deadline;
    }
    
    int count = JSD(n, jobs, result);
    double total_profit = 0;
    printf("ID\tDEADLINE\tPROFIT\n");
    
    while (count) {
        Job job = jobs[result[--count]];
        printf("%02d\t%4d\t\t%6.2lf\n", 
                job.id, job.deadline, job.profit);
        total_profit += job.profit;
    }
    
    printf("\nTotal Profit = %.2lf\n", total_profit);
    return 0;
}


// @description
//   Job Scheduling algorithm based on Gnatt chart
//
// @parameter
//   n        : Total number of jobs
//   jobs[]   : Array containg all the jobs
//   result[] : Array containing the position of
//              the job in jobs array
//
// @return
//   Total number of job in the result. 
int JSD(int n, Job jobs[], int result[])
{
    int sequenced[n];
    for (int i = 0; i < n; ++i)
        sequenced[i] = 0;
        
    // sort the jobs according to the non-increasing 
    // order of their profit
    insertionSort(n, jobs);
    int count = 0; // number of jobs successfully sequenced
    
    for (int i = 0; i < n; ++i) {
        Job job = jobs[i];
        for (int j = MIN(n, job.deadline) - 1; j >= 0; --j) {
            if (!sequenced[j]) {
                result[count++] = i;
                sequenced[j] = 1;
                break;
            }
        }
    }
    
    return count;
}


// @description
//   Sorts the given array using insertion Sort
//
// @parameter
//   n      : the length of the array
//   jobs[] : Array containg all the jobs
//
// @returns
//   This function does not return anything.
void insertionSort(int n, Job jobs[])
{
    for (int i = 1; i < n; ++i) {
        int j = i;
        // check whether j > 0 and profit of (j-1)-th job
        // is less than the profit of the j-th job
        while (j && jobs[j-1].profit < jobs[j].profit) {
            Job temp = jobs[j-1];
            jobs[j-1] = jobs[j];
            jobs[j] = temp;
            --j;
        }
    }
}
