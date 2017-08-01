#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void change(int k, int* arr) {
	int temp;
	if (arr[k - 1] > arr[k]) {
		temp = arr[k - 1];
		arr[k - 1] = arr[k];
		arr[k] = temp;
		change(k - 1, arr);
	}
	else
		return;
}
int main() {
	
	int arr[10000];
	int arr2[10000];
	int arr3[10000];
	int i, k, temp;
	clock_t start, end;

	srand((unsigned int)time(NULL));
	for (i = 0; i < 10000; i++) {
		arr[i] = rand() % 10000;
		arr2[i] = arr[i];
	}

	//////////////////////////1. BUBBLE////////////////////////////////////

	start = clock();
	for (i = 0; i < 10000 - 1 ; i++)
	{
		for (k = 1; k < 10000 - i; k++)
		{
			if (arr2[k-1] > arr2[k])
			{
				temp = arr2[k-1];
				arr2[k-1] = arr2[k];
				arr2[k] = temp;				
			}
		}
	}
	end = clock();
	printf("bubble : %.3lf√ \n", (double)end - start, (end - start) /(double)10000);
	
	/////////////////2. CHANGED NOT RECURSIVE - SUCCESS //////////////////
	start = clock();
	k = 1;
	if (arr[k - 1] > arr[k]) {
		temp = arr[k - 1];
		arr[k - 1] = arr[k];
		arr[k] = temp;
	}
	for (i = 2; i < 10000; i++)
	{
		//change(i, arr);
		for (k = i; arr[k - 1] > arr[k]; k--) {
			//if (arr[k - 1] > arr[k]) {
				temp = arr[k - 1];
				arr[k - 1] = arr[k];
				arr[k] = temp;
			//}
			//else
				//return;
		}
		
	}
	end = clock();
	printf("jungin : %.3lf√ \n", (double)end - start, (end - start) / (double)10000);
	
	//////////////////3. RECURSIVE - FAILED//////////////////////
	
	// it makes error when i =10000, but not when i =1000  
	srand((unsigned int)time(NULL));
	for (i = 0; i < 1000; i++) {
		arr3[i] = rand() % 1000;
	}
	start = clock();
	k = 1;
	if (arr3[k - 1] > arr3[k]) {
		temp = arr3[k - 1];
		arr3[k - 1] = arr3[k];
		arr3[k] = temp;
	}
	for (i = 2; i < 1000; i++)
	{
		change(i, arr3);
	}
	end = clock();
	//printf("jungin : %.3lf√ \n", (double)end - start, (end - start) / (double)10000);
}