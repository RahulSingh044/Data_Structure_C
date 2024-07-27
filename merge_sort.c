#include<stdio.h>
void merge(int arr[], int s, int mid, int e) {
    int l1 = mid-s+1;
    int l2 = e-mid;

    int arr1[l1], arr2[l2];

    for(int i=0; i<l1; i++) 
       arr1[i] = arr[s+i];
    
    for(int i=0; i<l2; i++)
      arr2[i] = arr[mid+1+i];

    for(int i=0,j=0,k=s; k<=e; k++) {
        if(j>=l1 || (i<l1 && arr1[i] <= arr2[j])) {
            arr[k] = arr1[i++];
        }
        else {
            arr[k] = arr2[j++];
        }
    }
}

void sort(int arr[], int s, int e) {
    if(s>=e){
        return;
    }

    int mid = s+(e-s)/2;

    // left side sorting
    sort(arr,s,mid);

    //right side sorting
    sort(arr,mid+1,e);

    merge(arr,s,mid,e);
}

int main() {
    int arr[] = {18,6,1,5,7,2,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    sort(arr,0,size-1);

    printf("The sorted array are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
    }
    
}
