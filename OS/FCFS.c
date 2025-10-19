 //FCFS
 #include<stdio.h>
 
 void swap(int n, int arr[], int j) {
 	int temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;
 }
 
 
 int main() {
 	int n, comp=0;
 	printf("Enter the no of processes : ");
 	scanf("%d", &n);
 	int process[n], at[n], bt[n], ct[n], tat[n], wt[n];
 	for(int i=0; i<n; i++) {
 		printf("Enter the process no, arriving time and burst time for process%d : ", i+1);
 		scanf("%d", &process[i]);
 		scanf("%d", &at[i]);
 		scanf("%d", &bt[i]);
 	}
 	//sorting
 	for(int i=0; i<n-1; i++) {
 		for(int j=0; j<n-i-1; j++) {
 			if (at[j]>at[j+1]) {
 				swap(n, process, j);
 				swap(n, at, j);
 				swap(n, bt, j);
 			}
 		}
 	}
 	
 	for(int i=0; i<n; i++) {
 		if(comp < at[i]) {
 			printf("IDLE : %d - %d\n", comp, at[i]);
 			comp = at[i];
 		}
 		printf("P%d : %d - %d\n", process[i], comp, comp+bt[i]);
 		comp += bt[i];
 		ct[i] = comp;
 		tat[i] = ct[i] - at[i];
 		wt[i] = tat[i] - bt[i];

 	}
 	
 	printf("Pid\tAT\tBt\tCT\tTAT\tWT\n");
 	printf("--------------------------------------------\n");
 	for(int i=0; i<n; i++) {
 		printf("%d\t%d\t%d\t%d\t%d\t%d\n", process[i], at[i], bt[i], ct[i], tat[i], wt[i]);
 	}
 }