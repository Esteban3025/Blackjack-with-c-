#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>

using namespace std;

std::random_device rd;
std::mt19937 gen(rd());

std::uniform_int_distribution<> dis(1, 21);

            
int clave, option, option2;

void menu();
void game();
void billetera();
void findmesa();

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
    int bet[3] = {100, 1000, 10000};
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
    } else if (clave == 3) {std::cout << "Haz salido del casino: Haces bien!!";}
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
        std::getline(cin,str);
    } while (str != "exit" && str != "EXIT");
    menu();
}

void findmesa() {
    std::cout << "Crupier: Bienvenido al blackjack, elige tu apuesta para comenzar:"<< std::endl;
    int apuesta;
    std::cout << "1. 100 $" << std::endl;
    std::cout << "2. 1000 $" << std::endl;
    std::cout << "3. 10000 $" << std::endl;
    std::cin >> option;
    if (option == 1) {apuesta = 100;
    } else if (option == 2) {apuesta = 1000;
    } else if (option = 3) {apuesta = 10000;}
    
}
  

//FUNCION PRINCIPAL DEL PROGRAMA
int main() {
    std::cout << "****************************************" << std::endl;
    std::cout << "            ¡¡¡BIENVENIDOS!!!           " << endl;
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