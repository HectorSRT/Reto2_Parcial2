#include <stdio.h>
#include <stdlib.h>

void leer_arreglo(int n, int arr[]);
void mezclar_arreglos(int n, int m, int arr1[], int arr2[], int arrRes[]);
void quicksort(int arr[], int l, int r);
int particion(int arr[], int l, int r);
void swap(int *arr, int *arrG);
void imprime_arr(int lim, int arrRes[]);

int main()
{
    int arr1[100], arr2[100], arrRes[100],n,m,lim;
    scanf("%d%d", &n,&m);
    lim=n+m;
    leer_arreglo(n,arr1);
    leer_arreglo(m,arr2);
    mezclar_arreglos(n,m,arr1,arr2,arrRes);
    quicksort(arrRes,0,lim-1);
    imprime_arr(lim,arrRes);
    return 0;
}

void leer_arreglo(int n, int arr[]){
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
}

void mezclar_arreglos(int n, int m, int arr1[], int arr2[], int arrRes[]){
    int lim=m+n,i=0,j=0;
    while(lim>0){
        arrRes[j]=arr1[i];
        j++;
        arrRes[j]=arr2[i];
        j++;
        i++;
        lim--;
    }
}

void quicksort(int arr[], int l, int r){
    if(r<=l){
        return;
    }
    int p=particion(arr, l, r);
    quicksort(arr,l,p-1);
    quicksort(arr,p+1,r);
}

int particion(int arr[], int l, int r){
    int i=l;
    for (int j=l;j<=r-1;j++){
        if(arr[j]<=arr[r]){
            swap(&arr[j],&arr[i]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

void swap(int *arr, int *arrG){
    int t=*arr;
    *arr=*arrG;
    *arrG=t;
}

void imprime_arr(int lim, int arrRes[]){
    for(int i=0;i<lim;i++){
        printf("%d ", arrRes[i]);
    }
}
