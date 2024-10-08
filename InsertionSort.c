
#include<stdio.h>

void insertionSort(int arr[], int size) {
    int key, i, j;
    for (i = 0; i < size; i++)
    {
        key = arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
    }
    
}

int main()
{
    int arr[] = {5, 7, 6, 13, 1, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size - 1);
    printf("Sorted Array is \t");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}
