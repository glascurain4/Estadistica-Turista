/*
PROYECTO: ESTADISTICA CON TURISTA MUNDIAL
Autor: Gabriel Lascurain Flores
Fecha: 20/03/2025
versión 1.0
*/

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

// Generar número para los dados
int generarNumeroAleatorio(int n) {
		return (std::rand() % n) + 1;
}

// Inicializamos variables y el vector que representa al tablero
std::vector<int> casillas(40, 0);
int casillaActual = 0;
int casillaSiguiente;
int dado1;
int dado2;
int vueltas;
int vueltasInt = 0;
int deportados = 0;
int aerolineas = 0;
int mensajes = 0;
int correos = 0;
int MensajeSalida = 0;
int MensajeDeportado = 0;
int MensajeAustralia = 0;
int MensajeCarcel = 0;
int CorreoAlemania = 0;
//bloques
int Africa=0;
int Asia=0;
int AmericaNte = 0;
int CentroAmerica = 0;
int Sudamerica1 = 0;
int Sudamerica2 = 0;
int Europa1 = 0;
int Europa2 = 0;

int main() {
	std::srand(std::time(0));  // Semilla para números aleatorios

	std::cout << "Introduce el número de vueltas a dar: ";
	std::cin >> vueltas;

	// Simulamos las tiradas recorriendo el tablero
	while (vueltasInt < vueltas) {
		dado1 = generarNumeroAleatorio(6);
		dado2 = generarNumeroAleatorio(6);
		casillaSiguiente = casillaActual + dado1 + dado2;

		if (casillaSiguiente > 40) {
			casillaSiguiente = casillaSiguiente % 40;  
			vueltasInt += 1;
			}
		if (casillaSiguiente == 11) { //REGRESAMOS A LOS DEPORTADOS
			deportados+=1;
			casillaSiguiente = 1;
		}

		// Tarjeta de mensaje
		if (casillaActual == 9 || casillaActual == 19 || casillaActual == 38) {
			int mensaje = generarNumeroAleatorio(15);
			if (mensaje == 1) { // SALIDA
				casillaSiguiente = 1;
				MensajeSalida++;
				}
			else if (mensaje == 2) { // DEPORTADO
				casillaSiguiente = 1;
				MensajeDeportado++;
				deportados+=1;
				}
			else if (mensaje == 3) { // AUSTRALIA
				casillaSiguiente = 21;
				MensajeAustralia++;
				}
			else if (mensaje == 4) { // CARCEL
				casillaSiguiente = 31;
				MensajeCarcel++;
				}
			mensajes+=1;
			casillas[casillaSiguiente - 1] += 1;
			casillaActual = casillaSiguiente;
			}

		// Tarjeta de correo
			if (casillaActual == 14 || casillaActual == 28 || casillaActual == 34) {
				if (generarNumeroAleatorio(15) == 1) { // ALEMANIA
					casillaSiguiente = 40;
					CorreoAlemania++;
					}
				correos++;
				casillas[casillaSiguiente - 1] += 1;
				casillaActual = casillaSiguiente;
				}
			// Aerolineas
				if (casillaActual == 6 || casillaActual == 16 || casillaActual == 26 || casillaActual == 36) {
					aerolineas+=1;
				}

			// BLOQUES
		if (casillaActual == 2 || casillaActual == 3 || casillaActual == 5) { //AFRICA
			Africa+=1;
		}

		if (casillaActual == 7 || casillaActual == 8 || casillaActual == 10) { //ASIA
			Asia+=1;
		}

		if (casillaActual == 12 || casillaActual == 13 || casillaActual == 15) { //NORTE AMERICA
			AmericaNte+=1;
		}

		if (casillaActual == 17 || casillaActual == 18 || casillaActual == 20) { //CENTROAMERICA
			CentroAmerica+=1;
		}

		if (casillaActual == 22 || casillaActual == 24 || casillaActual == 25) { //SUDAMERICA VERDE
			Sudamerica1+=1;
		}

		if (casillaActual == 27 || casillaActual == 29 || casillaActual == 30) { //SUDAMERICA CAFÉ
			Sudamerica2+=1;
		}

		if (casillaActual == 32 || casillaActual == 33 || casillaActual == 35) { //EUROPA MORADO
			Europa1+=1;
		}

		if (casillaActual == 37 || casillaActual == 39 || casillaActual == 40) { //EUROPA VERDE
			Europa2+=1;
		}
			casillas[casillaSiguiente - 1] += 1;
			casillaActual = casillaSiguiente;
		}

		// Desplegamos los resultados
		std::cout << "Casilla actual: " << casillaActual << std::endl;
		std::cout << "Aerolineas visitadas: " << aerolineas << std::endl;
		std::cout << "Mensajes: " << mensajes << std::endl;
		std::cout << "Salida: " << MensajeSalida << std::endl;
		std::cout << "Deportado: " << MensajeDeportado << std::endl;
		std::cout << "Australia: " << MensajeAustralia << std::endl;
		std::cout << "Carcel: " << MensajeCarcel << std::endl;
		std::cout << "Correos: " << correos << std::endl;
		std::cout << "Correo Alemania: " << CorreoAlemania << std::endl;
		std::cout << "Deportados totales: " << deportados << std::endl;

		// Desplegamos las casillas visitadas con un histograma
		std::cout << "Casillas \n";
		for (int i = 0; i < 40; i++) {
				std::cout << i + 1 << ": ";
				if (i==10) {
					for (int j = 0; j < deportados; j++) {
						std::cout << "l";
					}
				}
				for (int j = 0; j < casillas[i]; j++) {
						std::cout << "l";
				}
				std::cout << "\n";
		}

		std::cout << "VISITAS POR BLOQUES: " << std::endl;
		std::cout << "Africa: " << Africa << std::endl;
		std::cout << "Asia: " << Asia << std::endl;
		std::cout << "America Norte: " << AmericaNte << std::endl;
		std::cout << "Centro America: " << CentroAmerica << std::endl;
		std::cout << "Sudamerica Verde: " << Sudamerica1 << std::endl;
		std::cout << "Sudamerica Café: " << Sudamerica2 << std::endl;
		std::cout << "Europa Morado: " << Europa1 << std::endl;
		std::cout << "Europa Verde: " << Europa2 << std::endl;
		return 0;
}
