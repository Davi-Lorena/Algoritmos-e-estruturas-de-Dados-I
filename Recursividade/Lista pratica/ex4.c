#include <stdio.h>
#include <math.h> 

int potencia(int x, int y) {
if(y == 0) 
return 1;
else {
return x * potencia(x, y - 1);
}
}

int main() {

int x, y;

printf("Digite x e y: ");
scanf("%d %d", &x, &y);

printf("%d", potencia(x, y));

    return 0;
}