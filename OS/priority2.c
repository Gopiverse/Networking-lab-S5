#include<stdio.h>

void swap(int n, int arr[], int j) {
	int temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;
}

int main() {
	int n, comp=0, completed=0;
	printf("Enter no: of preocesses : ");
	scanf("%d", &n);
	int process[n], at[n], bt[n], ct[n], tat[n], wt[n], done[n], priority[n];
	for(int i=0; i<n; i++) {
		printf("Enter process no:, at, bt ,priority of process %d : ",i+1);
		scanf("%d%d%d%d", &process[i], &at[i], &bt[i], &priority[i]);
		done[i] = 0;
	}
	
	
	while(completed < n) {
		int highPr = 9999;
		int idx = -1;
		for(int i=0; i<n; i++) {
			if (!done[i] && at[i]<=comp && priority[i]<highPr) {
				highPr = priority[i];
				idx = i;
			}
		}
		if(idx == -1) {
			printf("IDLE - %d - %d\n", comp, comp+1);
			comp++;
		}
				
		else {
			printf("P%d - %d - %d\n",process[idx], comp, comp+bt[idx]);
			comp = comp + bt[idx];
			ct[idx] = comp;
			tat[idx] = ct[idx] - at[idx];
			wt[idx] = tat[idx] - bt[idx];
			done[idx] = 1;
			completed++;
 
		}
	}
	printf("PId\tAT\tBT\tCT\tTAT\tWT\n");
	printf("------------------------------------\n");
	for(int i=0; i<n; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", process[i], at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
	}
}











