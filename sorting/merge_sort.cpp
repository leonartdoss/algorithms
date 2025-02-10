/**
 * This program implements the Merge Sort algorithm to sort an array of integers.
 * Merge Sort is a divide-and-conquer algorithm that works by recursively dividing
 * the array into two halves, sorting each half, and then merging the sorted halves
 * to produce the sorted array.
 *
 * To compile:
 * $ g++ merge_sort.cpp -o <executable_name>.bin
 *
 * To run:
 * $ ./<executable_name>.bin
 *
 * The program will prompt the user to input the size of the array and the elements
 * of the array, which will then be sorted using the Merge Sort algorithm.
 */

 #include <iostream>
 #include <cstdio>
 
 using namespace std;
 
 void merge(int *array,int array_size){
     if(array_size > 0){
         int i = 0, mid = array_size / 2, j = mid, k = 0;
         int *array_aux = new int[array_size];
         // Merge the two halves into array_aux
         while(i < mid && j < array_size){
             (array[i] <= array[j] ? array_aux[k] = array[i ++] : array_aux[k] = array[j ++]);
             ++k;
         }
         // Copy any remaining elements from the left half
         if(i == mid)
             while(j < array_size) array_aux[k ++] = array[j ++];
         else 
             while(i < mid) array_aux[k ++] = array[i ++];
         
         for(int i = 0;i < array_size;i ++)
             array[i] = array_aux[i];
             
         delete(array_aux);
     }
 }
 
 void merge_sort(int *array, int array_size){
     int mid;
     if(array_size > 1){
         mid = array_size/2;
         merge_sort(array, mid);
         merge_sort(array + mid, array_size - mid);
         merge(array,array_size);
     }
 }
 
 int main(){
     int size;
     cin >> size;
     int array[size];
     for(int i = 0; i < size; i ++)
         cin >> array[i];
     merge_sort(array, size);
     for(int i = 0; i < size; i ++)
         cout << array[i] << " ";
     cout << endl;
     return 0;
 }