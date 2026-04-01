#include <stdio.h>
#include <string.h>
#define MAX_MEDICAMENTOS 100 

struct Medicamento { /* estructura para la información de los medicamentos */
    char codigo[6];
    char nombre[50];
    char descripcion[100];
    char fecha_caducidad[11];
    int cantidad;
};

struct Medicamento medicamentos[MAX_MEDICAMENTOS]; /* arreglo de medicamentos */
int contador_medicamentos = 0; /* contador de medicamentos */

/* definición de los módulos */
void registrarMedicamentos();
void actualizarCaducidad();
void consultarStock();
void mostrarMenu();

int main() { /* función principal */
    int opcion; /* variable opción */
    do {
        /* Datos del estudiante */
        printf(" * * * Gestor Medicamentos* * *\n");
        
        mostrarMenu(); /* llamamos a la función mostrar menú */
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarMedicamentos();
                break;
            case 2:
                actualizarCaducidad();
                break;
            case 3:
                consultarStock();
                break;
            case 4:
                printf("Saliendo del sistema. Gracias por usar el programa.\n");
                break;
            default:
                printf("Opción inválida. Inténtalo de nuevo.\n");
        }
    } while (opcion != 4); /* final del ciclo */

    return 0;
}

void mostrarMenu() {
    /* esta función enlista las opciones del menú */
    printf("\n--- Menú de gestión de medicamentos ---\n");
    printf("1. Registrar medicamentos.\n");
    printf("2. Actualizar caducidad de medicamentos.\n");
    printf("3. Consultar stock de medicamentos.\n");
    printf("4. Salir.\n");
    printf("Selecciona una opción: ");
}

void registrarMedicamentos() {
    if (contador_medicamentos >= MAX_MEDICAMENTOS) {
        printf("No se pueden registrar más medicamentos. Límite alcanzado.\n"); /* este nos permite limitar el número de registros de medicamentos */
        return;
    }

    struct Medicamento nuevoMedicamento;
    printf("Ingrese el código del medicamento: ");
    scanf("%s", nuevoMedicamento.codigo);
    printf("Ingrese el nombre del medicamento: ");
    scanf("%s", nuevoMedicamento.nombre);
    printf("Ingrese una descripción del medicamento: ");
    scanf("%s", nuevoMedicamento.descripcion);
    printf("Ingrese la fecha de caducidad (DD/MM/AAAA): ");
    scanf("%s", nuevoMedicamento.fecha_caducidad);
    printf("Ingrese la cantidad en almacén: ");
    scanf("%d", &nuevoMedicamento.cantidad);

    medicamentos[contador_medicamentos++] = nuevoMedicamento; /* permite añadir un medicamento al arreglo y además se incrementa el contador */
    printf("Medicamento registrado exitosamente.\n");
}

void actualizarCaducidad() {
    char codigo[6];
    printf("Ingrese el código del medicamento: ");
    scanf("%s", codigo);
    int encontrado = 0;

    for (int i = 0; i < contador_medicamentos; i++) {
        if (strcmp(medicamentos[i].codigo, codigo) == 0) { 
            printf("Ingrese la nueva fecha de caducidad (DD/MM/AAAA): ");
            scanf("%s", medicamentos[i].fecha_caducidad);
            printf("Ingrese la nueva cantidad en almacén: ");
            scanf("%d", &medicamentos[i].cantidad);
            printf("Actualización realizada con éxito.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Medicamento no encontrado.\n");
    }
}

void consultarStock() {
    printf("\n--- Consultar stock de medicamentos ---\n");
    for (int i = 0; i < contador_medicamentos; i++) {
        printf("Código: %s, Nombre: %s, Descripción: %s, Fecha de caducidad: %s, Cantidad: %d\n", 
                medicamentos[i].codigo, medicamentos[i].nombre, 
                medicamentos[i].descripcion, medicamentos[i].fecha_caducidad, 
                medicamentos[i].cantidad);
    }
}
