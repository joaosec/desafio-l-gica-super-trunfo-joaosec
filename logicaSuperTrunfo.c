#include <stdio.h>

// Estrutura para representar uma carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função que calcula os campos derivados
void calcularIndicadores(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função que exibe os dados da carta
void exibirCarta(struct Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nomeCidade, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("--------------------------\n");
}

// Função principal
int main() {
    // Criando duas cartas com dados fictícios
    struct Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.0, 2300.0, 20};
    struct Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6710000, 1182.3, 600.0, 15};

    // Calculando densidade populacional e PIB per capita
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibindo os dados
    printf("Carta 1:\n");
    exibirCarta(carta1);

    printf("Carta 2:\n");
    exibirCarta(carta2);

    // Comparação por atributo escolhido: PIB per capita
    printf("Comparação de cartas (Atributo: PIB per capita):\n\n");

    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pibPerCapita);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);

    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
