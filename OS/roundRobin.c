#include <stdio.h>

int main() {
    int n, timeQuantum;
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], remaining[n];
    int waiting[n], turnaround[n];

    for(int i=0; i<n; i++){
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &arrival[i], &burst[i]);
        remaining[i] = burst[i]; 
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &timeQuantum);

    int completed = 0, currentTime = 0;
    int flag; 
    float totalWT = 0, totalTAT = 0;

    printf("\nProcess | Turnaround Time | Waiting Time\n");

    while(completed < n){
        flag = 0;
        for(int i=0; i<n; i++){
            if(remaining[i] > 0 && arrival[i] <= currentTime){
                if(remaining[i] <= timeQuantum){
                    currentTime += remaining[i];
                    remaining[i] = 0;
                    flag = 1;
                } else {
                    remaining[i] -= timeQuantum;
                    currentTime += timeQuantum;
                }

                if(flag){
                    turnaround[i] = currentTime - arrival[i];
                    waiting[i] = turnaround[i] - burst[i];
                    totalTAT += turnaround[i];
                    totalWT += waiting[i];
                    completed++;
                    printf("P%d\t|\t%d\t|\t%d\n", i+1, turnaround[i], waiting[i]);
                    flag = 0;
                }
            }
        }

        int idleFound = 1;
        for(int i=0; i<n; i++){
            if(remaining[i] > 0 && arrival[i] <= currentTime){
                idleFound = 0;
                break;
            }
        }
        if(idleFound){
            currentTime++; 
        }
    }

    printf("\nAverage Turnaround Time = %.2f\n", totalTAT/n);
    printf("Average Waiting Time = %.2f\n", totalWT/n);

    return 0;
}
