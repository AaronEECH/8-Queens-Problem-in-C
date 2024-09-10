# Resolución del Problema de las 8 Reinas

Este documento describe el algoritmo utilizado para resolver el problema de las 8 reinas utilizando una técnica de retroceso (backtracking). El objetivo es colocar 8 reinas en un tablero de ajedrez de 8x8 de manera que ninguna reina pueda atacar a otra.

## Algoritmo

### Inicialización del Tablero

1. **Crear una matriz de 8x8**: Representa el tablero de ajedrez.
2. **Inicializar todas las posiciones en la matriz a 0**: Indica que el tablero está vacío.

### Algoritmo de Colocación de Reinas

#### Orden de Colocación

1. **Priorizar la colocación de reinas en base a**:
   - **Columnas** (de izquierda a derecha)
   - **Filas** (de arriba hacia abajo)
   - **Diagonales** (para asegurar que las reinas no se ataquen en diagonales)

#### Función `es_seguro(fila, columna)`

- Verificar si es seguro colocar una reina en la fila y columna dadas.
- Verificar que no haya otras reinas en la misma fila o columna.
- Verificar que no haya otras reinas en las diagonales.

#### Función `resolver(columna)`

1. **Si la columna es igual a 8 (tablero completo)**:
   - Se ha encontrado una solución.
   - Contar y almacenar la solución.
   - Imprimir el estado actual del tablero.
   - Volver a la llamada anterior para probar nuevas posiciones.
2. **Para cada fila en la columna actual**:
   - Si `es_seguro(fila, columna)`:
     - Colocar una reina en `tablero[columna] = fila`.
     - Llamar recursivamente a `resolver(columna + 1)`.
     - Retirar la reina (`tablero[columna] = -1`) y probar la siguiente fila.

### Impresión de Resultados

- Imprimir cada estado del tablero cuando se encuentra una solución.
- Incluir coordenadas de las reinas en formato de letras (A-H para columnas) y números (1-8 para filas).
- Guardar cada solución en un archivo con formato de nombre que incluya la fecha y hora actual.

### Ejemplos de Estado del Tablero

- **Estado Inicial (E0)**:

    ```
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    ```

- **Estado con Primera Reina (E1)**:

    ```
    {R, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    ```

- **Estado con Segunda Reina (E2)**:

    ```
    {R, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, R, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    {0, 0, 0, 0, 0, 0, 0, 0}
    ```

### Resultado Final

- Continuar hasta encontrar todas las soluciones posibles.
- Imprimir el total de soluciones encontradas y guardar el archivo con el formato adecuado.

## Descripción del Algoritmo de Retroceso (Backtracking)

El algoritmo de retroceso utiliza una estrategia de búsqueda para encontrar soluciones al problema de las 8 reinas. Coloca una reina en una columna y luego verifica si la colocación es segura. Si es seguro, procede a la siguiente columna; si no, intenta otra posición en la columna actual. Este proceso se repite hasta encontrar todas las posibles configuraciones del tablero que cumplen con las reglas del juego.
