#include <stdio.h>

int soma(int *arr, int n){
if(n == 0)
return 0;
else {
return arr[n - 1] + soma(arr, n-1);
}
 }


int main() {

    int arr[5]= {2, 4, 6, 8, 10};
int n = 5;

printf("%d\n", soma(arr, n));

    return 0;
}