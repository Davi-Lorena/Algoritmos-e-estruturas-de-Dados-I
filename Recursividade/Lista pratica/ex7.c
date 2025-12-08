#include <stdio.h>
#include <string.h>

int palindroma(char *string, int i, int n) {
if(i >= n) return 1;
if (string[i] != string[n]) return 0;
return palindroma(string, i+1, n-1);
}


int main() {

    char pal[20];
    int n, i = 0;
    
    printf("Digite a palavra: ");
    scanf(" %s", pal);
n = strlen(pal);

if(palindroma(pal, i, n - 1)) printf("A palavra e palindroma\n");
else printf("A palavra nao e palindroma\n");


    return 0;
}