#include <stdio.h>


void inverte(int *arr, int i, int n) {
if(i >= n) return; 

int aux = arr[i];
arr[i] = arr[n];
arr[n] = aux;
inverte(arr, i + 1, n - 1);
}



int main() {

int arr[6] = {5, 3, 7, 9, 1, 2};
int i = 0, n = 5;

inverte(arr, i, n);

for(int i = 0; i < 6; i++) {
    printf("%d ", arr[i]);
}

    return 0;
}