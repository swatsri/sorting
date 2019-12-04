#include <stdio.h>
#include <stdlib.h>
 
void merge (int *a, int *a_l, int *a_r, int lengthL,int lengthR) {
    int i = 0,j=0;
    int k= 0;
    while(i < lengthL && j < lengthR){
        if( a_l[i] <= a_r[j]) {
            a[k] = a_l[i];
            i++;
            k++;
        } else {
            a[k] = a_r[j];
            k++;
            j++;
        }
    }
    while(i < lengthL){
            a[k] = a_l[i];
            i++;
            k++;
    }
    while(j < lengthR){
            a[k] = a_r[j];
            j++;
            k++;
    }
    free(a_r);
    free(a_l);
}
 
void merge_sort (int *a, int n) {
    if (n < 2)
        return;
    int m = (n / 2);
    int *left = malloc(m * sizeof (int));
    int *right = malloc((n-m) * sizeof (int));
    for(int i =0;i < m;i++){
        left[i] = a[i];   
    }
    for(int x =0,j=m;j < n;x++){
        right[x] = a[j];   
        j++;
    }
    /*for(int j=0;j < m;j++){
        printf("%d ",left[j]);
        
    }
    printf("\n");
    for(int k=0;k < n-m;k++){
        printf("%d ",right[k]);
        
    }*/
    printf("\n");
    
    merge_sort(left, m);
    merge_sort(right, n - m);
    merge(a, left, right,m,n-m);
}
 
int main () {
    int a[] = { 5, 2, 1, 0, 9, 2, 8, 7, 1};
    int n = sizeof a / sizeof a[0];
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    merge_sort(a, n);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
