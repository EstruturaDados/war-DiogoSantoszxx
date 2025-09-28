// Novato 

```c
#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Essa struct agrupa os dados relacionados a um território:
// nome, cor do exército e quantidade de tropas.
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Vetor que armazenará até 5 territórios
    Territorio territorios[5];

    // Entrada de dados dos territórios
    printf("=== Cadastro de Territórios ===\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do território %d: ", i + 1);
        scanf(" %[^\n]", territorios[i].nome); // Lê string com espaços

        printf("Digite a cor do exército do território %d: ", i + 1);
        scanf(" %[^\n]", territorios[i].cor);

        printf("Digite a quantidade de tropas do território %d: ", i + 1);
        scanf("%d", &territorios[i].tropas);

        printf("\n"); // Quebra de linha para separar os cadastros
    }

    // Exibição dos dados cadastrados
    printf("\n=== Lista de Territórios Cadastrados ===\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Território %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].cor);
        printf("Quantidade de Tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    return 0;
}
```
