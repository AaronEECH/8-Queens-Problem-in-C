#include <stdio.h>
#include <stdlib.h>  // Necesario para la función abs()
#include <time.h>    // Necesario para obtener la fecha y hora

#define N 8  // Tamaño del tablero de ajedrez

int tablero[N];  // Representa el tablero, donde tablero[columna] = fila
int conteo_soluciones = 0;  // Contador de soluciones encontradas
FILE *archivo;  // Archivo para guardar los resultados

// Función para imprimir el tablero en el archivo
void imprimir_tablero(const char *mensaje) {
    fprintf(archivo, "%s\n", mensaje);
    fprintf(archivo, "  +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < N; i++) {
        fprintf(archivo, "%d |", i + 1);  // Números de fila
        for (int j = 0; j < N; j++) {
            if (tablero[i] == j)
                fprintf(archivo, " R |");  // Reina representada por 'R'
            else
                fprintf(archivo, "   |");  // Espacios vacíos
        }
        fprintf(archivo, "\n  +---+---+---+---+---+---+---+---+\n");
    }
    fprintf(archivo, "    A   B   C   D   E   F   G   H  \n\n");  // Letras de columna en mayúsculas
}

// Función para verificar si es seguro colocar una reina en la fila y columna dadas
int es_seguro(int fila, int columna) {
    for (int i = 0; i < columna; i++) {
        if (tablero[i] == fila || abs(tablero[i] - fila) == abs(i - columna)) {
            return 0;  // No es seguro colocar la reina
        }
    }
    return 1;  // Es seguro colocar la reina
}

// Función recursiva para resolver el problema de las 8 reinas
void resolver(int columna) {
    if (columna == N) {
        conteo_soluciones++;
        fprintf(archivo, "SOLUCIÓN #%d:\n", conteo_soluciones);
        imprimir_tablero("TABLERO FINAL:");
        return;
    }

    for (int i = 0; i < N; i++) {
        if (es_seguro(i, columna)) {
            tablero[columna] = i;

            // Convertir la columna a una letra (A-H) y la fila a un número (1-8)
            char letra_columna = 'A' + columna;
            int numero_fila = i + 1;

            char mensaje[50];
            sprintf(mensaje, "COLOCANDO REINA EN %c%d", letra_columna, numero_fila);
            imprimir_tablero(mensaje);
            resolver(columna + 1);
            tablero[columna] = -1;  // Resetea la columna después de retroceder
        }
    }
}

int main() {
    // Inicializar el tablero con valores inválidos
    for (int i = 0; i < N; i++) {
        tablero[i] = -1;
    }

    // Obtener la fecha y hora actual
    time_t tiempo_actual = time(NULL);
    struct tm tiempo_local = *localtime(&tiempo_actual);

    // Formatear el nombre del archivo con la fecha y hora, usando guiones bajos
    char nombre_archivo[100];
    sprintf(nombre_archivo, "Solución_%d_%02d_%02d_%02d_%02d_%02d.txt",
            tiempo_local.tm_year + 1900, tiempo_local.tm_mon + 1, tiempo_local.tm_mday,
            tiempo_local.tm_hour, tiempo_local.tm_min, tiempo_local.tm_sec);

    archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escribir.\n");
        return 1;
    }

    resolver(0);

    fprintf(archivo, "TOTAL DE SOLUCIONES: %d\n", conteo_soluciones);
    fclose(archivo);

    printf("Soluciones encontradas: %d. Revisa el archivo %s para ver las soluciones.\n", conteo_soluciones, nombre_archivo);
    return 0;
}