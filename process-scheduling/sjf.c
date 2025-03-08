#include<stdio.h>
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
};

int main() 
{
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);

	int bt[n], wt[n], tat[n], p[n];
	printf("Enter the burst time: ");
	for(int i = 0; i< n; i++){
		scanf("%d", &bt[i]);
		p[i] = i + 1;
	}
	//sorting by burst time
	for(int i = 0; i< n-1; i++){
		for(int j = 0; j< n; j++){
			if(bt[i] > bt[j]) {
				swap(&bt[i], &bt[j]);
				swap(&p[i], &p[j]);
			}
		}
	}
	wt[0] = 0;

	for(int i = 0; i< n; i++){
		wt[i] = wt[i-1] + bt[i-1];
	}

	for(int i = 0; i< n; i++) {
		tat[i] = wt[i] + bt[i];
	}
	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for (int i = 0; i < n; i++) {
    		printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
	}
	return 0;

}
