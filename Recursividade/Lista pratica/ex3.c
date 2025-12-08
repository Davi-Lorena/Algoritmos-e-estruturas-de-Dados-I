#include <stdio.h>            

void imprimir(int n) {
if(n == 1)
 printf("1\n");
else {
    printf("%d\n", n);
    imprimir(n - 1);
}
}

int main() {
int n;

printf("Digite n: ");
scanf("%d", &n);

imprimir(n);

return 0;
}