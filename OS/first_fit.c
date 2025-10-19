#include<stdio.h>

void first_fit(int blocks[], int b_size, int process[], int p_size) {
	int allocation[p_size];
	for(int i=0; i<p_size; i++) {
		allocation[i] = -1;
	}
	for(int i=0; i<p_size; i++) {
		for(int j=0; j<b_size; j++) {
			if(blocks[j] >= process[i]) {
				blocks[j] -= process[i];
				allocation[i] = j;
				break;
			}
		}
	}
	
	printf("Process\tProcess size\tBlock allocated\n");
	printf("---------------------------------------------------\n");
	for(int i=0; i<p_size; i++) {
		printf("%d\t%d\t\t",i+1, process[i]);
		if(allocation[i] != -1) {
			printf("B%d\n", allocation[i]+1);
		} else {
			printf("Not allocated");
		}
	}
	
}

int main() {
    int block_size, process_size;

    printf("Enter number of memory blocks: ");
    scanf("%d", &block_size);
    int blocks[block_size];
    for (int i = 0; i < block_size; i++) {
        printf("Enter size of Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &process_size);
    int process[process_size];
    for (int i = 0; i < process_size; i++) {
        printf("Enter size of Process %d: ", i + 1);
        scanf("%d", &process[i]);
    }

    first_fit(blocks, block_size, process, process_size);
    return 0;
}
