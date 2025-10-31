#include <stdio.h>

int main() {
    // ==== Declaração das variáveis da Carta 1 ====
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;

    // ==== Declaração das variáveis da Carta 2 ====
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;

    // ==== Entrada de dados da Carta 1 ====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a população: ");
    scanf("%lu", &populacao1);

    printf("Digite a área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // ==== Cálculos da Carta 1 ====
    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    superPoder1 = (float)populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1 / densidadePopulacional1);

    // ==== Entrada de dados da Carta 2 ====
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o código da carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a população: ");
    scanf("%lu", &populacao2);

    printf("Digite a área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // ==== Cálculos da Carta 2 ====
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    superPoder2 = (float)populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1 / densidadePopulacional2);

    // ==== Menu Interativo de Escolha de Atributos ====
    int opcao1, opcao2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;
    float soma1, soma2;

    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (menor vence)\n");
    printf("6 - PIB per Capita\n");

    // ==== Escolha do primeiro atributo ====
    printf("\nEscolha o PRIMEIRO atributo para comparar (1-6): ");
    scanf("%d", &opcao1);

    if (opcao1 < 1 || opcao1 > 6) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 1;
    }

    // ==== Escolha do segundo atributo ====
    printf("\nEscolha o SEGUNDO atributo para comparar (1-6), diferente do primeiro: ");
    scanf("%d", &opcao2);

    // Impede repetição de atributo
    while (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 6) {
        printf("Atributo inválido ou repetido! Escolha outro (1-6): ");
        scanf("%d", &opcao2);
    }

    // ==== Comparação dos dois atributos ====
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");

    // Função auxiliar inline (simulada com switch repetido)
    for (int i = 1; i <= 2; i++) {
        int opcaoAtual = (i == 1) ? opcao1 : opcao2;
        printf("\nAtributo %d: ", i);

        switch (opcaoAtual) {
            case 1: // População
                printf("População\n");
                valor1_carta1 = populacao1;
                valor1_carta2 = populacao2;
                break;

            case 2: // Área
                printf("Área\n");
                valor1_carta1 = area1;
                valor1_carta2 = area2;
                break;

            case 3: // PIB
                printf("PIB\n");
                valor1_carta1 = pib1;
                valor1_carta2 = pib2;
                break;

            case 4: // Pontos turísticos
                printf("Pontos Turísticos\n");
                valor1_carta1 = pontosTuristicos1;
                valor1_carta2 = pontosTuristicos2;
                break;

            case 5: // Densidade demográfica
                printf("Densidade Demográfica\n");
                valor1_carta1 = densidadePopulacional1;
                valor1_carta2 = densidadePopulacional2;
                break;

            case 6: // PIB per capita
                printf("PIB per Capita\n");
                valor1_carta1 = pibPerCapita1;
                valor1_carta2 = pibPerCapita2;
                break;
        }

        printf("%s: %.2f\n", nomeCidade1, valor1_carta1);
        printf("%s: %.2f\n", nomeCidade2, valor1_carta2);
    }

    // ==== Atribuir os valores reais dos atributos ====
    switch (opcao1) {
        case 1: valor1_carta1 = populacao1; valor1_carta2 = populacao2; break;
        case 2: valor1_carta1 = area1; valor1_carta2 = area2; break;
        case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; break;
        case 4: valor1_carta1 = pontosTuristicos1; valor1_carta2 = pontosTuristicos2; break;
        case 5: valor1_carta1 = densidadePopulacional1; valor1_carta2 = densidadePopulacional2; break;
        case 6: valor1_carta1 = pibPerCapita1; valor1_carta2 = pibPerCapita2; break;
    }

    switch (opcao2) {
        case 1: valor2_carta1 = populacao1; valor2_carta2 = populacao2; break;
        case 2: valor2_carta1 = area1; valor2_carta2 = area2; break;
        case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; break;
        case 4: valor2_carta1 = pontosTuristicos1; valor2_carta2 = pontosTuristicos2; break;
        case 5: valor2_carta1 = densidadePopulacional1; valor2_carta2 = densidadePopulacional2; break;
        case 6: valor2_carta1 = pibPerCapita1; valor2_carta2 = pibPerCapita2; break;
    }

    // ==== Cálculo da soma dos atributos ====
    // Regra: Densidade demográfica (menor vence), demais (maior vence)
    soma1 = ((opcao1 == 5) ? -valor1_carta1 : valor1_carta1) + ((opcao2 == 5) ? -valor2_carta1 : valor2_carta1);
    soma2 = ((opcao1 == 5) ? -valor1_carta2 : valor1_carta2) + ((opcao2 == 5) ? -valor2_carta2 : valor2_carta2);

    printf("\n=== SOMA DOS ATRIBUTOS ===\n");
    printf("%s: %.2f\n", nomeCidade1, soma1);
    printf("%s: %.2f\n", nomeCidade2, soma2);

    // ==== Determinar o vencedor ====
    if (soma1 > soma2)
        printf("\nVencedor: %s 🏆\n", nomeCidade1);
    else if (soma1 < soma2)
        printf("\nVencedor: %s 🏆\n", nomeCidade2);
    else
        printf("\nEmpate!\n");

    printf("\n=== Fim do programa ===\n");
    return 0;
}
