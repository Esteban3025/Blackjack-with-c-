#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>

using namespace std;

/*
std::random_device rd;
std::mt19937 gen(rd());

std::uniform_int_distribution<> dis(1, 21);
*/ 
            
int clave, option, option2;

void menu();
void game();
void billetera();

class Player {
    public:
    int cash = 20000;
    int bet[3] = {100, 1000, 10000};
    vector<int> cartas;
    int numdecartas;
    Player(){}
};



// FUNCION DEL MENU
void menu() {
    std::cout << "\n" << "\t" << "Lobby" << std::endl;
    std::cout << "\n" << "1. Ver tu billetera." << std::endl;
    std::cout << "2. Buscar una mesa." << std::endl;
    std::cout << "3. Salir del casino." << std::endl;
    std::cout << "\n" << "Tu opcion: ";
    std::cin >> clave;
    if (clave == 1) {billetera();}
} 




void game() {
    
}

void billetera() {
    Player jugador;
    std::cout << "\n" << "\t" << "Billetera" << std::endl;
    std::cout << "\n" << "El jugador tiene: " << jugador.cash << "$" << std::endl;
    string str;
    std::cout << "Escribe \"exit\" para volver al menu" << std::endl;
    do {
        std::getline(cin,str);
    } while (str != "exit" && str != "EXIT");
    menu();
}

int main() {
    std::cout << "*************************************" << std::endl;
    std::cout<<"**** Bienvenido al blackjack ********" << endl;
    std::cout << "*************************************" << std::endl;
    Player jugador;
    menu();

}


// Glory to God