/**
 * This program implements the Quick Sort algorithm to sort an array of integers.
 * Quick Sort is a divide-and-conquer algorithm that works by selecting a 'pivot'
 * element from the array and partitioning the other elements into two sub-arrays,
 * according to whether they are less than or greater than the pivot. The sub-arrays
 * are then sorted recursively.
 *
 * To compile:
 * $ gcc quick_sort.c -o <executable_name>.bin
 *
 * To run:
 * $ ./<executable_name>.bin <number of elements> <element1> <element2> ... <elementN>
 *
 * Example:
 * $ ./<executable_name>.bin 5 3 6 8 10 1
 * Output:
 * 1 3 6 8 10
 */

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int divide(int *array, int a, int b);
void quick_sort(int *array,int a,int b);
void print_array(int *array, int a, int b);

int main(int argc, char **argv){
    // Read the number of elements from the command line arguments
	int n = atoi(argv[1]);
	int i;
	int array[n];
	
    // Read the elements into the array
	for(i = 0;i < n;i ++)
		array[i] = atoi(argv[i + 2]);	
	
	quick_sort(array,0,n - 1);
	
	for(i = 0;i < n;i ++)
		printf("%d ",array[i]);
		
	printf("\n");
	
	return 0;
	
}

// Function to partition the array and return the pivot index
int divide(int *array, int a, int b){
	int left = a, right = b;
	int v = array[left];
	int aux;
	
    // Partition the array around the pivot
	while(left < right){
		while((array[left] <= v) && (left <= b))
			left ++;
		while((array[right] > v) && (right >= a))
			right --;
		if(left < right){
			aux = array[left];
			array[left] = array[right];
			array[right] = aux;
		}
	}
	array[a] = array[right];
	array[right] = v;
	
	return right;
}	
			
void quick_sort(int *array, int a, int b){
	if(a < b){
        // Partition the array and get the pivot index
		int p = divide(array,a,b);
		print_array(array,a,b);
        // Recursively sort the subarrays
		quick_sort(array,a,p - 1);
		quick_sort(array,p + 1,b);
	}
}

void print_array(int *array, int a, int b){
	int i;
	for(i = a;i <= b;i ++)
		printf("%d ",array[i]);
	printf("\n");
}
