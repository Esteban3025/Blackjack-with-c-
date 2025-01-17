#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>

using namespace std;

std::random_device rd;
std::mt19937 gen(rd());

std::uniform_int_distribution<> dis(1, 13);

            
int clave, option;
int * puntero;

void menu();
void game();
void billetera();
void findmesa();
void lost();
void win();
void jugadorpedircarta();
void crupierpedircarta();

// CLASE PARA EL JUGADOR
class Player {
    public:
    int cash = 20000;
    vector<int> cartas;
    int numdecartas;
    Player(){}
};

// CLASE PARA LA BANCA
class Banca {
    public:
    int apuesta1 = 100, apuesta2 = 1000, apuesta3 = 10000;
    vector<int> cartas;
    int numdecartas;
    Banca(){}
};


// FUNCION DEL MENU DEL JUEGO
void menu() {
    std::cout << "\n" << "\t" << "==Lobby==" << std::endl;
    std::cout << "\n" << "1. Ver tu billetera." << std::endl;
    std::cout << "2. Buscar una mesa." << std::endl;
    std::cout << "3. Salir del casino." << std::endl;
    std::cout << "\n" << "Tu opcion: ";
    std::cin >> clave;
    if (clave == 1) {billetera();
    } else if (clave == 2) {game();
    } else if (clave == 3) {std::cout << "Haz salido del casino: Haces bien!!";
    } else {std::cout << "Opcion no valida, intenta de nuevo." << std::endl; menu();}
} 


//FUNCION PRINCIPAL DEL JUEGO
void game() {
    Banca crupier;
    Player jugador;
    int mesa = dis(gen);
    while (mesa > 5) {
        mesa = dis(gen);
    }
    std::cout << "\n" << "\t" << "==Mesa " << mesa << "==" << std::endl;
    findmesa();
    menu();
}


//FUNCION DE LA BILLETERA
void billetera() {
    Player jugador;
    std::cout << "\n" << "\t" << "==Billetera==" << std::endl;
    std::cout << "\n" << "El jugador tiene: " << jugador.cash << "$" << std::endl;
    string str;
    std::cout << "Escribe \"exit\" para volver al menu" << std::endl;
    do {
        getline(cin,str);
    } while (str != "exit" && str != "EXIT");
    menu();
}

void findmesa() {
    Player jugador;
    Banca crupier;
    std::cout << "Crupier: Bienvenido al blackjack, elige tu apuesta para comenzar:"<< std::endl;
    std::cout << "1. 100 $" << std::endl;
    std::cout << "2. 1000 $" << std::endl;
    std::cout << "3. 10000 $" << std::endl;
    std::cin >> option;

    for (int i = 0; i < 2; i++)
    {
        crupier.cartas.push_back(dis(gen));
        jugador.cartas.push_back(dis(gen));
    }
    cout << "Cartas del jugador: ";
    for (int i = 0; i < 2; i++)
    {
        cout << jugador.cartas[i] << " ";   
    }
    cout << "\n";
    cout << "Cartas de la banca: ";
    for (int i = 0; i < 2; i++)
    {
        cout << crupier.cartas[i] << " ";
    }
    cout << "\n";

    if (jugador.cartas[0] >= 21 || jugador.cartas[1] >= 21) lost();
    else if (crupier.cartas[0] >= 21 || crupier.cartas[1] >= 21) win();

    cout << "1. Pedir carta" << std::endl;
    cout << "2. Plantarse" << std::endl;
    cin >> option;

    if (option == 1) {
        jugadorpedircarta();
        crupierpedircarta();
        cout << "Cartas del jugador: ";
        for (int i = 0; i < 3; i++)
        {
            cout << jugador.cartas[i] << " ";   
        }
        cout << "\n";
        cout << "Cartas de la banca: ";
        for (int i = 0; i < 2; i++)
        {
            cout << crupier.cartas[i] << " ";
        }
        cout << "\n";
    }

}
  
void lost() {
    Player jugador;
    Banca crupier;
    puntero = &crupier.apuesta1;
    puntero = &crupier.apuesta2;
    puntero = &crupier.apuesta3;
    if (option == 1) {*puntero = crupier.apuesta1;
    puntero = &jugador.cash;
    *puntero = jugador.cash;
    jugador.cash -= crupier.apuesta2;
    cout << "Has perdido la apuesta, te quedas con: " << jugador.cash << "$" << endl;
    } else if (option == 2) {*puntero = crupier.apuesta2;
    puntero = &jugador.cash;
    *puntero = jugador.cash;
    jugador.cash -= crupier.apuesta3;
    cout << "Has perdido la apuesta, te quedas con: " << jugador.cash << "$" << endl;
    } else if (option = 3) { *puntero = crupier.apuesta3;
    puntero = &jugador.cash;
    *puntero = jugador.cash;
    jugador.cash -= crupier.apuesta3;
    cout << "Has perdido la apuesta, te quedas con: " << jugador.cash << "$" << endl;
    }
    menu();
}


void win() {
    Player jugador;
    Banca crupier;
    puntero = &crupier.apuesta1;
    puntero = &crupier.apuesta2;
    puntero = &crupier.apuesta3;
    if (option == 1) {*puntero = crupier.apuesta1;
    puntero = &jugador.cash;
    *puntero = jugador.cash;
    jugador.cash += crupier.apuesta2;
    cout << "Has perdido la apuesta, te quedas con: " << jugador.cash << "$" << endl;
    } else if (option == 2) {*puntero = crupier.apuesta2;
    puntero = &jugador.cash;
    *puntero = jugador.cash;
    jugador.cash += crupier.apuesta3;
    cout << "Has perdido la apuesta, te quedas con: " << jugador.cash << "$" << endl;
    } else if (option = 3) { *puntero = crupier.apuesta3;
    puntero = &jugador.cash;
    *puntero = jugador.cash;
    jugador.cash += crupier.apuesta3;
    cout << "Has perdido la apuesta, te quedas con: " << jugador.cash << "$" << endl;
    }
    menu();
}


/*Usar punteros para enviar el numeoro correcto en cartas, crear una funcion para pedir cartas para el jugador y la banca, usando punteros en vestores, y para en ves de poner un numero para recorrer el vector usar una funcion especial para que recorra todo el vector sin importar el tamaño */

void jugadorpedircarta() {
    Player jugador;
    for (int i = 0; i < 2; i++)
    {
        jugador.cartas.push_back(dis(gen));
    }
}


void crupierpedircarta() {
    Banca crupier;
    for (int i = 0; i < 2; i++)
    {
        crupier.cartas.push_back(dis(gen));
    }
}

//FUNCION PRINCIPAL DEL PROGRAMA
int main() {
    std::cout << "****************************************" << std::endl;
    std::cout << "            BIENVENIDOS           " << endl;
    std::cout << "****************************************"<< std::endl;
    Player jugador;
    Banca crupier;
    do {
        menu();
    } while (clave != 3);
    
}

/*
For para ver los datos de un vector
for (int j = 0; j < 3; ++j) {
        std::cout << jugador.cartas[j] << std::endl;
    }
*/


// Glory to God