#include <stdio.h>

void BinarySort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i+1; j < size - i - 1; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {4, 9, 2, 7, 6, 15, 9, 32};
    int size = sizeof(arr) / sizeof(arr[0]);
    BinarySort(arr, size);
    printf("The sorted array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
