#include <stdio.h>            

void imprimir(int n) {
if(n == 1)
 printf("1\n");
else {
    imprimir(n - 1);
    printf("%d\n", n);
}
}

int main() {
int n;

printf("Digite n: ");
scanf("%d", &n);

imprimir(n);

return 0;
}