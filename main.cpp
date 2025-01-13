#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>

using namespace std;

int cash = 20000;
int clave;
int bet1 = 100;
int bet2 = 1000;
int bet3 = 10000;
int bet;

// FUNCION PARA EL juego y todo el menu
void game() {
    std::cout << "\n" << "\t" << "Lobby" << std::endl;
    std::cout << "\n" << "1. Ver tu billetera." << std::endl;
    std::cout << "2. Buscar una mesa." << std::endl;
    std::cout << "3. Salir del casino." << std::endl;
    std::cout << "\n" << "Tu opcion: ";
    std::cin >> clave;
    
    if (clave == 1) {
        //CODIGO PARA LA BILLETERA
        std::cout << "\n" << "\t" << "TU BILLETERA" << std::endl;
        std::cout << "Dinero actual en tu cuenta: " << cash << "$" << std::endl;
        game();
        
    
        
    } else if (clave == 2) {
        //CODIGO PRINCIPAL DEL JUEGO
        int option;
        std::cout << "El Crupier: " << "Selecciona tu apuesta..." << std::endl;
        std::cout << "1. " << bet1 << "$" << std::endl;
        std::cout << "2. " << bet2 << "$" << std::endl;
        std::cout << "3. " << bet2 << "$" << std::endl;
        cout << "Tu opcion: ";
        std::cin >> option;

        
        
        if (option == 1) {
            // APUESTA DE 100 DOLARES
            if (cash - bet1 <= 0) {
                std::cout << "Dinero insuficiente para apostar, consulta tu billetera antes de continuar. "<< std::endl;
                game();
            }

            std::random_device rd;
            std::mt19937 gen(rd());

            std::uniform_int_distribution<> dis(1, 10);

            int crupier_carta1 = dis(gen);
            int crupier_carta2 = dis(gen);

            int jugador_carta1 = dis(gen);
            int jugador_carta2 = dis(gen);
            
            cout << "\n";

            cout << "Cartas del Crupier: " << "[" << crupier_carta1 << "]" << "[" << crupier_carta2 << "]" <<endl;

            cout << "Tus cartas: " << "[" << jugador_carta1 << "]" << "[" << jugador_carta2 << "]" <<endl;

            int option2;
            cout << "1. Plantarse" << endl;
            cout << "2. Pedir otra carta" << endl;
            cin >> option2;

            if (option2 == 1) {
                int result = jugador_carta1 + jugador_carta2;
                int result2 = crupier_carta1 + crupier_carta2;
                if (result > result2 || result < 21) {    
                    
                }
            }

            /*
            for (int i = 1; i < 2; i++) {
            cout << dis(gen) << endl;
            }
            */ 
            
            
        } else if (option == 2) {
            // APUESTA DE 1000 DOLARES
            
            int bet;
            bet = bet2 + cash;
            if (cash - bet2 <= 0) {
                std::cout << "Dinero insuficiente para apostar, consulta tu billetera antes de continuar. "<< std::endl;
            }
            std::cout << cash << std::endl;
            game();
   
        } else if (option == 3) {
            // APUESTA DE 10000 DOLARES
            
            int bet;
            bet = bet3 + cash;
            if (cash - bet3 <= 0) {
                std::cout << "Dinero insuficiente para apostar, consulta tu billetera antes de continuar. "<< std::endl;
            }
            std::cout << cash << std::endl;
            game();
            
            
            
            
        }
    } else if (clave == 3) {
        //CODIGO DE SALIDA DEL JUEGO
        
        std::cout << " SALISTE DEL JUEGO :(" << std::endl;
        exit(0);
        
    } else {
        std::cout << "\n" << "Operacion no disponible" << std::endl;
        game();
    }
 
}


int main() {
    std::cout << "*************************************" << std::endl;
    std::cout<<"**** Bienvenido al blackjack ********" << endl;
    std::cout << "*************************************" << std::endl;
    
    game();
    
}

/*

// Codigo de encontrar un numero aleatorio

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, 21);

    for (int i = 1; i < 5; i++) {
        cout << dis(gen) << endl;
    }
*/

// Glory to God