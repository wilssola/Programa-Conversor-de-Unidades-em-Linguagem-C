#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void converterVolume(float quantidade, int origem, int destino);

int main() {
    setlocale(LC_ALL, "");
    int origem, destino;
    float quantidade;

    printf("Conversor de Unidades de Volume\n");
    printf("Escolha a unidade de origem:\n");
    printf("1 - Litros (L)\n");
    printf("2 - Mililitros (mL)\n");
    printf("3 - Metros cúbicos (m³)\n");
    printf("Digite o número correspondente a unidade de origem: ");
    scanf("%d", &origem);

    printf("Digite a quantidade: ");
    scanf("%f", &quantidade);

    printf("Escolha a unidade de destino:\n");
    printf("1 - Litros (L)\n");
    printf("2 - Mililitros (mL)\n");
    printf("3 - Metros cúbicos (m³)\n");
    printf("Digite o número correspondente a unidade de destino: ");
    scanf("%d", &destino);

    converterVolume(quantidade, origem, destino);

    return 0;
}

void converterVolume(float quantidade, int origem, int destino) {
    float resultado = quantidade;

    // Converter a quantidade para Litros (L) como unidade intermediária
    switch (origem) {
        case 1: // Litros
            break;
        case 2: // Mililitros para Litros
            resultado = quantidade / 1000.0;
            break;
        case 3: // Metros cúbicos para Litros
            resultado = quantidade * 1000.0;
            break;
        default:
            printf("Unidade de origem inválida!\n");
            return;
    }

    // Converter de Litros (L) para a unidade de destino
    switch (destino) {
        case 1: // Litros
            printf("Resultado: %.2f Litros (L)\n", resultado);
            break;
        case 2: // Litros para Mililitros
            resultado = resultado * 1000.0;
            printf("Resultado: %.2f Mililitros (mL)\n", resultado);
            break;
        case 3: // Litros para Metros cúbicos
            resultado = resultado / 1000.0;
            printf("Resultado: %.6f Metros cúbicos (m³)\n", resultado);
            break;
        default:
            printf("Unidade de destino invalida!\n");
            return;
    }
}
