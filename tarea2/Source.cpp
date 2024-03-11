//Practica2
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Jugador {
public:
    char opcion;

    void seleccionar(const string& nombre) {
        cout << "Ingrese su eleccion para " << nombre << " (Piedra[R], Papel[P] o Tijera[T]): ";
        cin >> opcion;
    }

    
    int getPuntaje() const {
        return puntaje;
    }

    void setPuntaje(int nuevoPuntaje) {
        puntaje = nuevoPuntaje;
    }

    // Método para evaluar
    void evaluarJugador(const string& nombre) {
        cout << nombre << " eligio: " << opcion << endl;
    }

private:
    int puntaje = 0;
};

void determinarGanadorJugador1(Jugador& jugador1, Jugador& jugador2, const string& nombreJugador1, const string& nombreJugador2) {
    if (jugador1.opcion == jugador2.opcion) {
        cout << "Empate para " << nombreJugador1 << "!" << endl;
    }
    else if ((jugador1.opcion == 'P' && jugador2.opcion == 'T') ||
        (jugador1.opcion == 'T' && jugador2.opcion == 'R') ||
        (jugador1.opcion == 'R' && jugador2.opcion == 'P')) {
        cout << nombreJugador2 << " gana para " << nombreJugador1 << "!" << endl;
        jugador2.setPuntaje(jugador2.getPuntaje() + 1);
    }
    else {
        cout << nombreJugador1 << " gana!" << endl;
        jugador1.setPuntaje(jugador1.getPuntaje() + 1);
    }
}

void determinarGanadorJugador2(Jugador& jugador1, Jugador& jugador2, const string& nombreJugador1, const string& nombreJugador2) {
    if (jugador1.opcion == jugador2.opcion) {
        cout << "Empate para " << nombreJugador2 << "!" << endl;
    }
    else if ((jugador1.opcion == 'P' && jugador2.opcion == 'T') ||
        (jugador1.opcion == 'T' && jugador2.opcion == 'R') ||
        (jugador1.opcion == 'R' && jugador2.opcion == 'P')) {
        cout << nombreJugador1 << " gana para " << nombreJugador2 << "!" << endl;
        jugador1.setPuntaje(jugador1.getPuntaje() + 1);
    }
    else {
        cout << nombreJugador2 << " gana!" << endl;
        jugador2.setPuntaje(jugador2.getPuntaje() + 1);
    }
}

int main() {
    srand(time(0));  

    // Ingresar nombres de jugadores
    string nombreJugador1, nombreJugador2;
    cout << "Ingrese el nombre del Jugador 1: ";
    cin >> nombreJugador1;
    cout << "Ingrese el nombre del Jugador 2: ";
    cin >> nombreJugador2;

    Jugador jugador1;
    Jugador jugador2;

    jugador1.seleccionar(nombreJugador1);
    jugador2.seleccionar(nombreJugador2);

    jugador1.evaluarJugador(nombreJugador1);
    jugador2.evaluarJugador(nombreJugador2);

    determinarGanadorJugador1(jugador1, jugador2, nombreJugador1, nombreJugador2);
    determinarGanadorJugador2(jugador1, jugador2, nombreJugador1, nombreJugador2);

    
    cout << "Puntajes finales:" << endl;
    cout << nombreJugador1 << ": " << jugador1.getPuntaje() << " puntos." << endl;
    cout << nombreJugador2 << ": " << jugador2.getPuntaje() << " puntos." << endl;

    return 0;
}

