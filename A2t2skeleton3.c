//t2_skeleton.c


#include <stdio.h>
#include "t2.h"

int number_comparisons = 0;
int number_swaps = 0;

void selectionSort(int arr[], int size)
{
    
    for(int i = 0 ; i< size-1; i++){//looking at every element; maybe don't needa look
        //at the last one tho? size-1?
        
        
        int min_pos = i; //letting first element be the minimum
        for(int j = i+1; j<size; j++){
            //inner loop that finds the minimum in the unsorted portion of the array^^
            if (arr[j] < arr[min_pos])
                min_pos = j; //setting new minimum
            //this is a comparison so;
            number_comparisons++;
            
        }
        if(min_pos!= i){
                int temp = arr[i];
                arr[i] = arr[min_pos];
                arr[min_pos] = temp; //temp variable to store
            //new minimum swapped
                number_swaps++;
        }
        
        
    }
}

void insertionSort(int arr[], int size)
{
    for(int i =1; i <size; i++){ //outer loop looking thru each element of my array
        int element = arr[i];
        int j = i-1; //element on the left of i
        
        //shifting part; this inner loop shifts the element over to the right position in the left hand portion of the array that remains
        
        while(j>= 0 && arr[j] > element){
            arr[j+1] = arr[j];
            j = j-1; //goes leftwards
            number_swaps++;
            number_comparisons++;
            
        }
        number_comparisons++;
        arr[j+1] = element; //insertion part
    }
    
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    
}

void quickSort(int arr[], int size) //more of a wrapper function
{
 
    //initally want to sort the entire array so our bounds are first index to last index
    //AKA 0 to size-1
    quickSort_Recursion(arr, 0, size-1);
    
}

void quickSort_Recursion(int arr[], int l, int h){ //where L and H are low and high
//L = lower bound of the portion of the array we wanna sort
//and H = the higher bound of the portion of the array we wanna sort
    
//here applying the DIVIDE-CONQUER process
    if(l<h){
    int pivot_i = partition(arr, l, h);
    quickSort_Recursion(arr, l, pivot_i-1); //left portion of the array
    quickSort_Recursion(arr, pivot_i+1, h);
}
}

int partition(int arr[], int l, int h){
    //step 1 get pivot; in this case im just setting it to the HIGH bound
    int pivot_val = arr[h];
    
    int i = l;
    
    for(int j = l; j<h ; j++){ //iterating through array
        //comparing each value...
        number_comparisons++;
        if(arr[j] <= pivot_val){ //if item on the left is less than or eq to pivot, swap with i which is
            //the current index of left partition elements (left portion with lesser elements)
            swap(&arr[i], &arr[j]);
            number_swaps += 1;
            i++;
            
        }
    }
    swap(&arr[i], &arr[h]); //after all this is done to put pivot at correct position
    number_swaps += 1;
    return i;
}

