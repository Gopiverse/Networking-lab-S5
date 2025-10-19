#include <stdio.h>

void printTable(int n, int m, int allocation[n][m], int max[n][m], int need[n][m], int available[m]) {
    printf("\nProcess | Allocation | Max | Need\n");
    printf("---------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("P%d      | ", i);
        for(int j = 0; j < m; j++) printf("%d ", allocation[i][j]);
        printf("| ");
        for(int j = 0; j < m; j++) printf("%d ", max[i][j]);
        printf("| ");
        for(int j = 0; j < m; j++) printf("%d ", need[i][j]);
        printf("\n");
    }
    printf("Available: ");
    for(int j = 0; j < m; j++) printf("%d ", available[j]);
    printf("\n---------------------------------\n");
}


int isSafe(int n, int m, int allocation[n][m], int need[n][m], int available[m], int safeSeq[n]) {
    int finish[n], work[m];
    for (int i = 0; i < m; i++) work[i] = available[i];
    for (int i = 0; i < n; i++) finish[i] = 0;

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int canRun = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canRun = 0;
                        break;
                    }
                }
                if (canRun == 1) {
                    for (int j = 0; j < m; j++) work[j] += allocation[i][j];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
            return 0;  // unsafe
    }
    return 1;  // safe
}

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m], available[m];
    int safeSeq[n];

    // Input allocation and max
    for (int i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i);
        for (int j = 0; j < m; j++) {
            printf("Allocation for R%d: ", j);
            scanf("%d", &allocation[i][j]);
        }
        for (int j = 0; j < m; j++) {
            printf("Max for R%d: ", j);
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Available
    printf("\nEnter available resources:\n");
    for (int j = 0; j < m; j++) {
        printf("Available for R%d: ", j);
        scanf("%d", &available[j]);
    }

    printf("\n--- INITIAL STATE ---");
    printTable(n, m, allocation, max, need, available);

    // Check initial safety
    if (isSafe(n, m, allocation, need, available, safeSeq)) {
        printf("\nSystem is initially in a SAFE STATE.\nSafe Sequence: ");
        for (int i = 0; i < n; i++) printf("P%d ", safeSeq[i]);
    } else {
        printf("\nSystem is NOT in a safe state initially!\n");
        return 0;
    }

    // RESOURCE REQUEST
    int req_proc;
    printf("\n\nEnter process number making a new request: ");
    scanf("%d", &req_proc);

    int request[m];
    printf("Enter resource request for P%d:\n", req_proc);
    for (int j = 0; j < m; j++) {
        printf("Request for R%d: ", j);
        scanf("%d", &request[j]);
    }

    // Check Request ≤ Need
    for (int j = 0; j < m; j++) {
        if (request[j] > need[req_proc][j]) {
            printf("\nError: Process has exceeded its maximum need\n");
            return 0;
        }
    }

    // Check Request ≤ Available
    for (int j = 0; j < m; j++) {
        if (request[j] > available[j]) {
            printf("\nResources not available now\n");
            return 0;
        }
    }

    // Pretend to allocate
    for (int j = 0; j < m; j++) {
        available[j] -= request[j];
        printf("%d", available[j]);
        allocation[req_proc][j] += request[j];
        printf("%d", allocation[req_proc][j]);
        need[req_proc][j] -= request[j];
        printf("%d", need[req_proc][j]);
    }
        printTable(n, m, allocation, max, need, available);


    // Re-check Safety
    if (isSafe(n, m, allocation, need, available, safeSeq)) {
        printf("\nRequest can be GRANTED safely.\nNew Safe Sequence: ");
        for (int i = 0; i < n; i++) printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("\nRequest leads to UNSAFE state");
    }

    printf("\n--- FINAL STATE ---");
    printTable(n, m, allocation, max, need, available);

    return 0;
}
