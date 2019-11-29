
/*  Insertion Sort  */



#include <stdio.h>

void printArr(int arr[],int size);
void insertionArr(int arr[],int size);

int main()
{
    int arr[] = {2,7,6,9,1,3,0};
    printf("Array before Sorting: \n");
    printArr(arr,7);
    insertionArr(arr,7);
    printf("Array after Sorting: \n");
    printArr(arr,7);
    return 0;
}


void printArr(int arr[],int size){
    int i=0;
    for(i=0;i < size;++i){
        printf("%d ",arr[i]);
        
    }
    printf("\n");
}

void insertionArr(int arr[],int size){
    int value =0;
    int hole = 0;
    for(int i=1;i < size;i++){
        value = arr[i];
        hole = i;
        printf("value = %d i = %d hole = %d \n",value,i,hole);
        while(hole > 0 && arr[hole -1] >  value){
            arr[hole] = arr[hole-1];
            hole = hole-1;
        }
        arr[hole] = value;
    }
}
