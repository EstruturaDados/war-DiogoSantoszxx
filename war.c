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

//Intermediario

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da struct Territorio
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função para cadastrar os territórios
void cadastrarTerritorios(Territorio* mapa, int n) {
    printf("=== Cadastro de Territórios ===\n\n");
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do território %d: ", i + 1);
        scanf(" %[^\n]", mapa[i].nome);

        printf("Digite a cor do exército do território %d: ", i + 1);
        scanf(" %[^\n]", mapa[i].cor);

        printf("Digite a quantidade de tropas do território %d: ", i + 1);
        scanf("%d", &mapa[i].tropas);

        printf("\n");
    }
}

// Função para exibir os territórios
void exibirTerritorios(Territorio* mapa, int n) {
    printf("\n=== Territórios no Mapa ===\n\n");
    for (int i = 0; i < n; i++) {
        printf("Território %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
        printf("-----------------------------\n");
    }
}

// Função de ataque: atacante vs defensor
void atacar(Territorio* atacante, Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("\n[ERRO] Você não pode atacar um território da mesma cor!\n");
        return;
    }
    if (atacante->tropas < 2) {
        printf("\n[ERRO] O território atacante precisa ter pelo menos 2 tropas!\n");
        return;
    }

    // Rolagem de dados (1 a 6)
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("\n=== Batalha ===\n");
    printf("%s (Atacante) rolou: %d\n", atacante->nome, dadoAtacante);
    printf("%s (Defensor) rolou: %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("\n>> O atacante venceu a batalha!\n");

        // O defensor muda de cor
        strcpy(defensor->cor, atacante->cor);

        // Tropas do defensor são reduzidas à metade do atacante
        defensor->tropas = atacante->tropas / 2;

        // Atacante perde metade das tropas no processo
        atacante->tropas /= 2;
    } else {
        printf("\n>> O defensor resistiu ao ataque!\n");
        atacante->tropas--; // Atacante perde 1 tropa
    }
}

// Função para liberar a memória
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

int main() {
    srand(time(NULL)); // Garante aleatoriedade

    int n;
    printf("Digite o número de territórios a cadastrar: ");
    scanf("%d", &n);

    // Alocação dinâmica de memória para os territórios
    Territorio* mapa = (Territorio*) calloc(n, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Cadastro dos territórios
    cadastrarTerritorios(mapa, n);
    exibirTerritorios(mapa, n);

    // Escolha de ataque
    int iAtacante, iDefensor;
    printf("\nEscolha o número do território atacante: ");
    scanf("%d", &iAtacante);
    printf("Escolha o número do território defensor: ");
    scanf("%d", &iDefensor);

    // Executa o ataque
    atacar(&mapa[iAtacante - 1], &mapa[iDefensor - 1]);

    // Exibe situação final
    exibirTerritorios(mapa, n);

    // Liberação da memória
    liberarMemoria(mapa);

    return 0;
}
```

