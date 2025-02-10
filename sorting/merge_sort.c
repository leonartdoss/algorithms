/*
 * This program implements the Merge Sort algorithm to sort an array of integers.
 * Merge Sort is a divide-and-conquer algorithm that works by recursively dividing
 * the array into two halves, sorting each half, and then merging the sorted halves
 * to produce the sorted array.
 *
 *
 * The program consists of three main functions:
 * 1. merge: Merges two sorted halves of the array into a single sorted array.
 * 2. mergeSort: Recursively divides the array into halves and sorts each half.
 * 3. main: Initializes the array, calls mergeSort, and prints the sorted array.
 *
 * To compile the program, use the following command:
 * gcc merge_sort.c -o <executable_name>.bin
 *
 * To execute the compiled program, use the following command:
 * ./<executable_name>.bin
 */

#include <stdio.h>
#include <stdlib.h>

// void merge(int *array,int *auxArray, int begin, int mid, int end){
// 	int i,j,k;
// 	for(i = begin,j = mid,k = 0; k < end - begin; k++){
// 		if(array[j] < array[i])
// 			auxArray[k] = array[j++];
// 		else
// 			auxArray[k] = array[i++];
// 	}
// 	for(i = 0; i < k; i++)
// 		array[i + begin] = auxArray[i];
// }

void merge(int *array, int *auxArray, int begin, int mid, int end) {
    int i = begin, j = mid, k = begin;
    while (i < mid && j < end) {
        if (array[i] <= array[j]) {
            auxArray[k++] = array[i++];
        } else {
            auxArray[k++] = array[j++];
        }
    }
    while (i < mid) {
        auxArray[k++] = array[i++];
    }
    while (j < end) {
        auxArray[k++] = array[j++];
    }
    for (i = begin; i < end; i++) {
        array[i] = auxArray[i];
    }
}

void mergeSort(int *array, int *auxArray, int left, int right){
	int mid;
	if(left < right - 1){
		mid = (left + right) / 2;
		mergeSort(array, auxArray, left, mid);
		mergeSort(array, auxArray, mid, right);
		merge(array, auxArray, left, mid, right);
	}
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *array = (int *) malloc(n * sizeof(int));
    int *auxArray = (int *) malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    mergeSort(array, auxArray, 0, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    free(auxArray);

    return 0;
}
