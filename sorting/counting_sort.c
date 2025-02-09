#include <stdio.h>
#include <stdlib.h>

/**
 * In computer science, counting sort is an algorithm for sorting a collection
 * of objects according to keys that are small integers; that is, it is an
 * integer sorting algorithm.
 * 
 * It operates by counting the number of objects that have each distinct
 * key value, and using Arithmetic on those counts to determine the
 * positions of each key value in the output sequence.
 * 
 * Its running time is linear in the number of items and the difference
 * between the maximum and minimum key values, so it is only suitable for
 * direct use in situations where the variation in keys 
 * is not significantly greater than the number of items.
 * 
 * However, it is often used as a subroutine in another sorting algorithm,
 * radix sort, that can handle larger keys more efficiently.
 *
 * To compile:
 * $ gcc count_sort.c -o <executable_name>.bin
 * 
 * Example of array:
 * n = 6
 * A = [10, 90, 65, 76, 1, 32]
 * Smaller key = 1
 * Bigger key = 90
 * 
 * Input example:
 * 		$ ./<executable_name>.bin 6 1 90 10 90 65 75 1 32
 * Output:
 * 		1 10 32 65 75 92
 * */

int main(int argc, char **argv){
	int i;
	int smaller_key;
	int nA = atoi(argv[1]);
	int nB = atoi(argv[3]) - atoi(argv[2]) + 1;
	int A[nA],B[nB],C[nA];
	
	smaller_key = atoi(argv[2]);

	for(i = 0;i < nA;i ++)
		A[i] = atoi(argv[i + 4]);
	
	for(i = 0;i < nB;i ++)
		B[i] = 0;
	
	for(i = 0;i < nA;i ++)
		B[A[i] - smaller_key] ++;
	
	for(i = 1;i < nB;i ++)
		B[i] = B[i] + B[i - 1];
		
	for(i = nA - 1;i >= 0;i --){
		C[--B[A[i] - smaller_key]] = A[i];
	}
		
	for(i = 0;i < nA;i ++)
		printf("%d ",C[i]);
	
	printf("\n");
	return 0;
}
