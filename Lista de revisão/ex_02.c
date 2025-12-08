#include <stdio.h>
#include <string.h>

void imprimir_reversa(char S1[]) {
    for (int i = strlen(S1) - 1; i >= 0; i--) {
        printf("%c", S1[i]);
    }
    printf("\n");
}

int contar_caractere(char S1[], char c) {
    int cont = 0;
    for (int i = 0; S1[i] != '\0'; i++) {
        if (S1[i] == c) {
            cont++;
        }
    }
    return cont;
}

void substituir_primeira(char S1[], char c1, char c2) {
    for (int i = 0; S1[i] != '\0'; i++) {
        if (S1[i] == c1) {
            S1[i] = c2;
            break;
        }
    }
}

int main() {
    char S1[21], S2[21];
    int opcao;
    scanf("%20s", S1);

    do {
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("%lu\n", strlen(S1));
                break;

            case 2:
                scanf("%20s", S2);
                strcat(S1, S2);
                printf("%s\n", S1);
                break;

            case 3:
                imprimir_reversa(S1);
                break;

            case 4: {
                char c;
                scanf(" %c", &c);
                printf("%d\n", contar_caractere(S1, c));
                break;
            }

            case 5: {
                char c1, c2;
                scanf(" %c %c", &c1, &c2);
                substituir_primeira(S1, c1, c2);
                printf("%s\n", S1);
                break;
            }

            case 6:
                scanf("%20s", S2);
                if (strstr(S1, S2) != NULL)
                    printf("S\n");
                else
                    printf("N\n");
                break;

            case 7:
                scanf("%20s", S1);
                break;

            case 8:
                break;
        }

    } while (opcao != 8);

    return 0;
}
