#include <stdio.h>

int BinarySearch(int Arr[], int key, int start, int end) {

    while (start <= end)
    {
        int mid = start + (end-start) / 2;
        if (Arr[mid] == key)
        {
            return mid;
        }
        if (Arr[mid] > key)
        {
            end = mid - 1;
        }
        if (Arr[mid] < key)
        {
            start = mid + 1;
        }
    }
    return -1;
}

int InterpolianSearch(int Arr[], int key, int low, int high)
{

    //this condition check whether the key value falls within the array or not 
    while (low <= high && Arr[low]<=key && key<=Arr[high])
    {
        if(low == high) {
            if(Arr[low] == key) {
                return low;
            }
            return -1;
        }

        int pos = low + ((key - Arr[low]) * (high - low)) / (Arr[high] - Arr[low]);

        if(Arr[pos] == key) {
            return pos;
        }
        if(Arr[pos] < key) {
            low = pos + 1;
        }
        else if(Arr[pos] > key) {
            high = pos - 1;
        }
    }
    return -1;
}

int main()
{

    int key;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\nEnter the element to be searched:\t");
    scanf("%d", &key);

    int result = BinarySearch(arr, key, 0, size-1);
    int res = InterpolianSearch(arr, key, 0, size-1);

    if (result == -1)
    {
        printf("%d is not found in the array", key);
    }
    else
    {
        printf("%d is found at %d by binary search.",key,result);
    }

    // Searching by Interpolian Search
    if (result == -1)
    {
        printf("%d is not found in the array", key);
    }
    else
    {
        printf("%d is found at %d by binary search.",key,result);
    }

    return 0;
}
