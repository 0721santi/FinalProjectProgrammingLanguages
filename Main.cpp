#include <iostream>
#include "includes/Game.h"
#include "includes/DataStructure/LinkedList.h"
#include "includes/Persona.h"
using namespace std;

int main(){
    cout << "Bienvenido a quien quiere ser millonario." << endl;
    cout << "RESUMEN SEMANAL" << endl;
    // LinkedList lk;
    // lk.agregar(new Dato(Persona(), Persona(), 1));
    Game juego;
    juego.simularSemana();
    return 0;
}