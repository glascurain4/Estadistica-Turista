# PROYECTO: ESTADÍSTICA CON TURISTA MUNDIAL

## Autor
**Gabriel Lascurain Flores**

## Fecha
20/03/2025

## Versión
1.0

## Descripción
Este proyecto simula un juego basado en "Turista Mundial", en el cual un jugador recorre un tablero de 40 casillas utilizando dos dados. El propósito es generar estadísticas sobre las casillas más visitadas, los mensajes obtenidos, las deportaciones y los correos recibidos.

## Funcionamiento
1. Se solicita al usuario el número de vueltas a recorrer en el tablero.
2. Se simulan los lanzamientos de dos dados en cada turno para determinar el movimiento del jugador.
3. Se registran las visitas a cada casilla en un vector.
4. Se activan eventos especiales según la casilla en la que caiga el jugador:
   - **Tarjetas de mensaje**: En casillas 9, 19 y 38, el jugador puede recibir instrucciones especiales como ser deportado o enviado a Australia.
   - **Tarjetas de correo**: En casillas 14, 28 y 34, el jugador puede recibir un mensaje que lo envía a Alemania.
   - **Casillas de aerolíneas**: En casillas 6, 16, 26 y 36, se registra la visita a una aerolínea.
5. Se registran estadísticas de las visitas a diferentes regiones del tablero (África, Asia, América del Norte, Centroamérica, Sudamérica y Europa).
6. Al final del juego, se despliegan las estadísticas de visitas en forma de histograma.

## Salida del programa
El programa muestra:
- Cantidad de mensajes y correos obtenidos.
- Número de deportaciones y sus detalles.
- Visitas a diferentes regiones del tablero.
- Histograma con la cantidad de visitas por casilla.

## Compilación y Ejecución
Para compilar el programa en un entorno con **g++**, utilizar el siguiente comando:
```sh
 g++ turista_mundial.cpp -o turista_mundial
```
Para ejecutarlo:
```sh
 ./turista_mundial
```

## Posibles Mejoras
- Implementación de múltiples jugadores.
- Visualización gráfica de los resultados.
- Guardado de estadísticas en un archivo de texto o base de datos.
- Interfaz interactiva para una mejor experiencia del usuario.

