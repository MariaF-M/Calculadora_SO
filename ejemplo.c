#include <stdio.h>

int main() {
    float ladoBase, altura, volumen;

    printf("Ingrese el lado de la base de la piramide: ");
    scanf("%f", &ladoBase);

    printf("Ingrese la altura de la piramide: ");
    scanf("%f", &altura);

    volumen = (ladoBase * ladoBase * altura) / 3;

    printf("El volumen de la piramide es: %.2f\n", volumen);

    return 0;
}
