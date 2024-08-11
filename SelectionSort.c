#include <stdio.h>

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min_indx = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                {
                    min_indx = j;
                }
            }
            swap(&arr[i],&arr[min_indx]);
        }
    }
}

int main()
{
    int arr[] = {5, 7, 6, 13, 1, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, size - 1);
    printf("Sorted Array is \t");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}
