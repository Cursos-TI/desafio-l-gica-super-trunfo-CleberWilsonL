#include <stdio.h>
#include <string.h>

// Estrutura da carta (cidade)
struct CartaCidade {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para cadastro de uma carta
void cadastrarCarta(struct CartaCidade *carta) {
    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);
    printf("Código: ");
    scanf(" %[^\n]", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nome);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área: ");
    scanf("%f", &carta->area);
    printf("PIB: ");
    scanf("%f", &carta->pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função do nível Novato
void compararAtributoSimples(struct CartaCidade c1, struct CartaCidade c2) {
    int opcao;
    printf("\n[1] População\n[2] Área\n[3] PIB\n[4] Pontos Turísticos\nEscolha o atributo para comparar: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            if (c1.populacao > c2.populacao)
                printf("Vencedora: %s (População maior)\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("Vencedora: %s (População maior)\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        case 2:
            if (c1.area > c2.area)
                printf("Vencedora: %s (Área maior)\n", c1.nome);
            else if (c2.area > c1.area)
                printf("Vencedora: %s (Área maior)\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        case 3:
            if (c1.pib > c2.pib)
                printf("Vencedora: %s (PIB maior)\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("Vencedora: %s (PIB maior)\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        case 4:
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedora: %s (Mais pontos turísticos)\n", c1.nome);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Vencedora: %s (Mais pontos turísticos)\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        default:
            printf("Atributo inválido!\n");
    }
}

// Função do nível Mestre – comparação com dois atributos e operador ternário
void compararAtributosMestre(struct CartaCidade c1, struct CartaCidade c2) {
    int op1, op2;

    printf("\nEscolha dois atributos para comparar:\n");
    printf("[1] População\n[2] Área\n[3] PIB\n[4] Pontos Turísticos\n");
    printf("Primeiro atributo: ");
    scanf("%d", &op1);
    printf("Segundo atributo: ");
    scanf("%d", &op2);

    int pontos1 = 0, pontos2 = 0;

    int valores1[5] = {c1.populacao, (int)c1.area, (int)c1.pib, c1.pontosTuristicos};
    int valores2[5] = {c2.populacao, (int)c2.area, (int)c2.pib, c2.pontosTuristicos};

    pontos1 += (valores1[op1 - 1] > valores2[op1 - 1]) ? 1 : (valores1[op1 - 1] < valores2[op1 - 1]) ? 0 : 0;
    pontos2 += (valores2[op1 - 1] > valores1[op1 - 1]) ? 1 : (valores2[op1 - 1] < valores1[op1 - 1]) ? 0 : 0;

    pontos1 += (valores1[op2 - 1] > valores2[op2 - 1]) ? 1 : (valores1[op2 - 1] < valores2[op2 - 1]) ? 0 : 0;
    pontos2 += (valores2[op2 - 1] > valores1[op2 - 1]) ? 1 : (valores2[op2 - 1] < valores1[op2 - 1]) ? 0 : 0;

    if (pontos1 > pontos2)
        printf("Vencedora: %s\n", c1.nome);
    else if (pontos2 > pontos1)
        printf("Vencedora: %s\n", c2.nome);
    else
        printf("Empate!\n");
}

// Menu principal com seleção de níveis
int main() {
    struct CartaCidade carta1, carta2;

    printf("=== Cadastro da Primeira Cidade ===\n");
    cadastrarCarta(&carta1);
    printf("\n=== Cadastro da Segunda Cidade ===\n");
    cadastrarCarta(&carta2);

    int escolha;

    do {
        printf("\nEscolha o nível do desafio:\n");
        printf("[1] Nível Novato (1 atributo - if)\n");
        printf("[2] Nível Aventureiro (menu com switch)\n");
        printf("[3] Nível Mestre (2 atributos e ternário)\n");
        printf("[0] Sair\nOpção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                compararAtributoSimples(carta1, carta2);
                break;
            case 2:
                compararAtributoSimples(carta1, carta2);  // Mesma função, só mudando o menu
                break;
            case 3:
                compararAtributosMestre(carta1, carta2);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (escolha != 0);

    return 0;
}
