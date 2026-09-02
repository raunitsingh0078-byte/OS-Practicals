#include <stdio.h>

typedef struct
{
    int id;
    int bt;
    int wt;
    int tat;
    int rt;
    int ct;
} process;

int i;
int tq, at = 0;

void rr(process p[10], int n)
{
    int sum_wt = 0, sum_tt = 0;
    int count = 0, wt = 0;
    float avg_wt, avg_tat;

    while (count < n)
    {
        for (i = 0; i < n; i++)
        {
            if (p[i].rt > 0)
            {
                if (p[i].rt <= tq)
                {
                    wt += p[i].rt;
                    p[i].ct = wt;
                    p[i].rt = 0;
                    count++;
                }
                else
                {
                    wt += tq;
                    p[i].rt -= tq;
                }
            }
        }
    }

    // Calculate Turnaround Time
    for (i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - at;
    }

    // Calculate Waiting Time
    for (i = 0; i < n; i++)
    {
        p[i].wt = p[i].tat - p[i].bt;
    }

    printf("\nPID\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);

        sum_wt += p[i].wt;
        sum_tt += p[i].tat;
    }

    avg_wt = (float)sum_wt / n;
    avg_tat = (float)sum_tt / n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
}

int main()
{
    process p[10];
    int n;

    printf("\nEnter no of jobs: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;

        printf("Enter burst time of job %d: ", i + 1);
        scanf("%d", &p[i].bt);

        p[i].rt = p[i].bt;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    rr(p, n);

    return 0;
}
