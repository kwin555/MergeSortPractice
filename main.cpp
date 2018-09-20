//
//  main.cpp
//  MergeSortPractice
//
//  Created by Kevin Nguyen on 9/19/18.
//  Copyright © 2018 Kevin Nguyen. All rights reserved.
//

#include <iostream>
void merge(int array[], int left, int middle, int right);
void mergeSort(int array[], int left, int right);
void printArray(int[], int);

int main(int argc, const char * argv[]) {
    std::cout << (1/2) << std::endl;
    int array[] = {12, 11, 13 ,2, 19, 44};
    int arraySize = sizeof(array) / sizeof(array[0]);
    printf("Given array is \n");
    printArray(array, arraySize);
    mergeSort(array, 0, arraySize - 1);
    printf("\nsorted arrray is \n");
    printArray(array, arraySize);
    return 0;
}

void merge(int array[], int leftStart, int middle, int rightEnd) {
    int leftIndex;
    int rightIndex;
    int mergedIndex;
    //getting the left and right sizes for the left and right arrays
    int leftSize = middle - leftStart + 1;
    int rightSize = rightEnd - middle;
    
    //creating temp arrays
    int leftArray[leftSize], rightArray[rightSize];
    //copy data to temp arrays Left and Right
    for(leftIndex = 0; leftIndex < leftSize; leftIndex++) {
        leftArray[leftIndex] = array[leftStart + leftIndex];
    }
    
    for (rightIndex = 0; rightIndex < rightSize; rightIndex++ ) {
        rightArray[rightIndex] = array[middle + 1  + rightIndex];
    }
    
    //merged the temp arrays back into array [left .... right]
    leftIndex = 0;
    rightIndex = 0;
    mergedIndex = leftStart;
    
    while(leftIndex < leftSize && rightIndex < rightSize) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            array[mergedIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            array[mergedIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }
    //filling what is left of the leftArray and rightArray
    while(leftIndex < leftSize) {
        array[mergedIndex] = leftArray[leftIndex];
        leftIndex++;
        mergedIndex++;
    }
    
    while(rightIndex < rightSize) {
        array[mergedIndex] = rightArray[rightIndex];
        rightIndex++;
        mergedIndex++;
    }
    
}

void mergeSort(int array[], int left, int right) {
    //conditon to break the recursion
    if (left < right) {
        //same thing as (l + r) / 2
        int middle = left + (right - left) / 2;
        //splits up the left side of the array
        mergeSort(array, left, middle);
        std::cout << "bye-bye" << " ";
        //splits up the right side of the array
        mergeSort(array, middle + 1, right);
        //merges the left and right sides
        std::cout << "bye-bye" << " ";
        merge(array, left, middle, right);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
