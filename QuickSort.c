#include<stdio.h>

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int l, int h){
    int pivot = arr[h];
    int i = (l-1);
    for(int j=l; j<h;j++) {
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[h]);
    return i+1;
}

void quick(int arr[],int l, int h){
    if(l>h)
      return;

    int p = partition(arr,l,h);

    //right side
    quick(arr,l,p-1);

    //left side
    quick(arr,p+1,h);
}
int main(){
    int arr[] = {5,7,6,13,1,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    quick(arr,0,size-1);
    printf("Sorted Array is \t");
    for(int i=0; i<size; i++) {
        printf("%d  ",arr[i]);
    }
    return 0;
}
