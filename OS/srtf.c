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
	int process[n], at[n], bt[n], ct[n], tat[n], wt[n], rem[n];
	for(int i=0; i<n; i++) {
		printf("Enter process no:, at, bt of process %d : ",i+1);
		scanf("%d%d%d", &process[i], &at[i], &bt[i]);
		rem[i] = bt[i];
	}
	
	
	while(completed < n) {
		int minBT = 9999;
		int idx = -1;
		for(int i=0; i<n; i++) {
			if (rem[i]>0 && at[i]<=comp && rem[i]<minBT) {
				minBT = rem[i];
				idx = i;
			}
		}
		if(idx == -1) {
			comp++;
		} else {
			rem[idx]--;
			comp++;
			
			if(rem[idx] == 0) {
				ct[idx] = comp;
				tat[idx] = ct[idx] - at[idx];
				wt[idx] = tat[idx] - bt[idx];
				completed++;
 			}
		}
	}
	printf("PId\tAT\tBT\tCT\tTAT\tWT\n");
	printf("------------------------------------\n");
	for(int i=0; i<n; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", process[i], at[i], bt[i], ct[i], tat[i], wt[i]);
	}
}











