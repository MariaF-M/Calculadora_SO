#include <stdio.h>
#include <math.h>

#define STACK_SIZE 8

float stack[STACK_SIZE];
int sp = 0;

void mostrar_pila();
void push(float x);
float pop();
void mover_pila();
void ingresar_numero();
void operar();
void borrar_ultimo();
void borrar_todo();
void menu();

int main() {
    int op;

    borrar_todo();

    do {
        mostrar_pila();
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                ingresar_numero();
                break;
            case 2:
                operar();
                break;
            case 3:
                borrar_ultimo();
                break;
            case 4:
                borrar_todo();
                printf("Pila limpia\n");
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }

        printf("\n-----------------\n");

    } while (op != 5);

    return 0;
}

void mostrar_pila() {
    int i;
    printf("\nCalculadora RPN\n");
    for (i = 0; i < STACK_SIZE; i++) {
        printf("%d: %.2f\n", STACK_SIZE - i, stack[i]);
    }
}

void push(float x) {
    if (sp < STACK_SIZE) {
        stack[sp] = x;
        sp++;
    } else {
        mover_pila();
        stack[STACK_SIZE - 1] = x;
    }
}

float pop() {
    float val;
    if (sp > 0) {
        sp--;
        val = stack[sp];
        stack[sp] = 0;
        return val;
    } else {
        printf("Pila vacia\n");
        return 0;
    }
}

void mover_pila() {
    int i;
    for (i = 0; i < STACK_SIZE - 1; i++) {
        stack[i] = stack[i + 1];
    }
}

void ingresar_numero() {
    float n;
    printf("Ingrese numero: ");
    scanf("%f", &n);
    push(n);
}

void operar() {
    char op;
    float a, b, r;

    printf("Operacion (+ - * / p r): ");
    scanf(" %c", &op);

    if (op == 'r') {
        if (sp < 1) {
            printf("No hay numeros suficientes\n");
            return;
        }
        a = pop();
        if (a < 0) {
            printf("No se puede raiz negativa\n");
            push(a);
            return;
        }
        push(sqrt(a));
        return;
    }

    if (sp < 2) {
        printf("No hay numeros suficientes\n");
        return;
    }

    b = pop();
    a = pop();

    switch (op) {
        case '+': r = a + b; break;
        case '-': r = a - b; break;
        case '*': r = a * b; break;
        case '/':
            if (b == 0) {
                printf("Division por cero\n");
                push(a);
                push(b);
                return;
            }
            r = a / b;
            break;
        case 'p': r = pow(a, b); break;
        default:
            printf("Operacion invalida\n");
            push(a);
            push(b);
            return;
    }

    push(r);
}

void borrar_ultimo() {
    if (sp > 0) {
        pop();
        printf("Ultimo borrado\n");
    } else {
        printf("Pila vacia\n");
    }
}

void borrar_todo() {
    int i;
    sp = 0;
    for (i = 0; i < STACK_SIZE; i++) {
        stack[i] = 0;
    }
}

void menu() {
    printf("\n1. Ingresar numero\n");
    printf("2. Operar\n");
    printf("3. Borrar ultimo\n");
    printf("4. Borrar todo\n");
    printf("5. Salir\n");
    printf("Opcion: ");
}
