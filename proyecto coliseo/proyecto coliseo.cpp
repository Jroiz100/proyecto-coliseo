#include <iostream>
#include <cstdlib>
#include <ctime>

struct Jugador {
    std::string nombre;
    int ataque;
    int defensa;
    int velocidad;
    std::string powerup;
};

void asignarPropiedades(Jugador& jugador) {
    jugador.ataque = rand() % 11;
    jugador.defensa = rand() % 11;
    jugador.velocidad = rand() % 11;

    int opcion = rand() % 3;
    if (opcion == 0) {
        jugador.powerup = "Ataque";
        jugador.ataque++;
    }
    else if (opcion == 1) {
        jugador.powerup = "Defensa";
        jugador.defensa++;
    }
    else {
        jugador.powerup = "Velocidad";
        jugador.velocidad++;
    }
}

int main() {
    srand(time(0)); // Inicializar la semilla para generar números aleatorios

    char opcion;

    do {
        Jugador jugadores[2];

        for (int i = 0; i < 2; i++) {
            std::cout << "Ingrese el nombre del Jugador " << i + 1 << ": ";
            std::cin >> jugadores[i].nombre;
            asignarPropiedades(jugadores[i]);
        }

        // Imprimir la información de cada jugador
        for (int i = 0; i < 2; i++) {
            std::cout << "Jugador " << jugadores[i].nombre << " - Ataque: " << jugadores[i].ataque
                << ", Defensa: " << jugadores[i].defensa
                << ", Velocidad: " << jugadores[i].velocidad
                << ", Powerup: " << jugadores[i].powerup << std::endl;
        }

        std::cout << "¿Iniciar una partida nueva? (S para seguir, X para salir): ";
        std::cin >> opcion;

    } while (opcion == 'S' || opcion == 's');

    std::cout << "Programa finalizado." << std::endl;

    return 0;
}
