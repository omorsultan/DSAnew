#include<stdio.h>
void swap(int *a, int *b){
    int temp=*a;*a=*b; *b=temp; 
}
int partition(int array[],int low , int high){
    int pivot=array[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(array[j]<=pivot) swap(&array[j],&array[++i]);
    }
    swap(&array[high],&array[i+1]);
    return (i+1);
}
void quickSort(int array[],int low, int high){
    if(low<high){
        int pi= partition(array, low ,high);
        quickSort(array, low ,pi-1);
        quickSort(array, pi+1, high);
    }
}
void printArray(int arr[],int size){
    for(int i=0;i<size;i++)printf("%d ",arr[i]);
    printf("\n");
}
int main(){
    int data[] = {20, 12, 10, 15, 2 , 8 , 7 , 9};
    int size=sizeof(data)/sizeof(data[0]);
    quickSort(data,0,size-1);
    printArray(data,size);
}