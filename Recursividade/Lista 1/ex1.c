#include <stdio.h>

int misterio(int a, int b) {
if(a < b){  
printf("0 ");
return 0;
}
else {
    int x = 1 + misterio(a-b, b);
    printf("%d ", x);
    return x;
}

}

int main() {

int a, b;

printf("Digite a e b: ");
scanf("%d %d", &a, &b);

misterio(a, b);

return 0;
}