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


//Final

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

    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("\n=== Batalha ===\n");
    printf("%s (Atacante) rolou: %d\n", atacante->nome, dadoAtacante);
    printf("%s (Defensor) rolou: %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("\n>> O atacante venceu a batalha!\n");
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas /= 2;
    } else {
        printf("\n>> O defensor resistiu ao ataque!\n");
        atacante->tropas--;
    }
}

// Função para atribuir missão ao jogador
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes;
    strcpy(destino, missoes[indice]);
}

// Verificar se missão foi cumprida (versão simplificada)
int verificarMissao(char* missao, char* corJogador, Territorio* mapa, int n) {
    if (strstr(missao, "Conquistar 3 territórios")) {
        int cont = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) cont++;
        }
        return (cont >= 3);
    }
    if (strstr(missao, "Eliminar cor vermelha")) {
        for (int i = 0; i < n; i++) {
            if (strcmp(mapa[i].cor, "vermelha") == 0) return 0;
        }
        return 1;
    }
    if (strstr(missao, "Controlar território 1")) {
        return (strcmp(mapa[0].cor, corJogador) == 0);
    }
    if (strstr(missao, "Ter mais de 10 tropas")) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) total += mapa[i].tropas;
        }
        return (total > 10);
    }
    if (strstr(missao, "Conquistar qualquer território")) {
        // Simples: se controla pelo menos 1, já venceu
        for (int i = 0; i < n; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) return 1;
        }
    }
    return 0;
}

// Função para liberar memória
void liberarMemoria(Territorio* mapa, char** missoesJogadores, int numJogadores) {
    free(mapa);
    for (int i = 0; i < numJogadores; i++) {
        free(missoesJogadores[i]);
    }
}

int main() {
    srand(time(NULL));

    int n, jogadores;
    printf("Digite o número de territórios a cadastrar: ");
    scanf("%d", &n);

    Territorio* mapa = (Territorio*) calloc(n, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    cadastrarTerritorios(mapa, n);
    exibirTerritorios(mapa, n);

    printf("\nDigite o número de jogadores: ");
    scanf("%d", &jogadores);

    // Definição de missões pré-definidas
    char* missoes[] = {
        "Conquistar 3 territórios",
        "Eliminar cor vermelha",
        "Controlar território 1",
        "Ter mais de 10 tropas",
        "Conquistar qualquer território"
    };
    int totalMissoes = 5;

    // Alocar missões dos jogadores
    char** missoesJogadores = (char**) malloc(jogadores * sizeof(char*));
    char** coresJogadores = (char**) malloc(jogadores * sizeof(char*));

    for (int i = 0; i < jogadores; i++) {
        missoesJogadores[i] = (char*) malloc(100 * sizeof(char));
        coresJogadores[i] = (char*) malloc(15 * sizeof(char));

        printf("\nDigite a cor do jogador %d: ", i + 1);
        scanf(" %[^\n]", coresJogadores[i]);

        atribuirMissao(missoesJogadores[i], missoes, totalMissoes);
        printf("Missão do jogador %d (%s): %s\n", i + 1, coresJogadores[i], missoesJogadores[i]);
    }

    // Simulação de um turno
    int iAtacante, iDefensor;
    printf("\nEscolha o número do território atacante: ");
    scanf("%d", &iAtacante);
    printf("Escolha o número do território defensor: ");
    scanf("%d", &iDefensor);

    atacar(&mapa[iAtacante - 1], &mapa[iDefensor - 1]);
    exibirTerritorios(mapa, n);

    // Verificar se algum jogador venceu
    for (int i = 0; i < jogadores; i++) {
        if (verificarMissao(missoesJogadores[i], coresJogadores[i], mapa, n)) {
            printf("\n=== FIM DE JOGO ===\n");
            printf("O jogador %d (%s) venceu cumprindo a missão: %s\n",
                   i + 1, coresJogadores[i], missoesJogadores[i]);
            break;
        }
    }

    liberarMemoria(mapa, missoesJogadores, jogadores);
    for (int i = 0; i < jogadores; i++) free(coresJogadores[i]);
    free(coresJogadores);

    return 0;
}
```

