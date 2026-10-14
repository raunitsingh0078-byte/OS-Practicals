#include <stdio.h>

int main() {
    int n, i;
    int bt[100], wt[100], tat[100];

    printf("enter no of processes");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nenter burst time of %d process\n", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
