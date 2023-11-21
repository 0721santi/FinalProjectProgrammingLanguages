#include "Game.h"
#include "DataStructure/LinkedList.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

//Funcion que sintetiza la clase random y la generacion de numeros aleatorios en pro del codigo limpio.
int randomGen(int lwrIdx, int highIdx){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> random(lwrIdx,highIdx);
    return random(rng);
}
//Funcion que genera un numero con coma flotante para el uso de comodines tipo publico y llamada
double ayudaComodin(double lwrIdx, double highIdx){
    random_device dev;
    mt19937 rng(dev());
    // uniform_real_distribution<mt19937::result_type> random(0.0f, 1.0f);
    uniform_real_distribution<double> random(lwrIdx, highIdx);
    return random(rng);
}

Game::Game(){
    LinkedList resumenSemanal;
}

void Game::simularSemana(){
    for(int i=0;i<5;i++){
        cout << "Dia "+to_string(i+1)+"." <<endl;
        Dato* emision = new Dato(Persona(), Persona(), i);
        cout << "Cree emision" << endl;
        juegoParticipante(emision->getParticipante1());
        cout << "juego 1" << endl;
        juegoParticipante(emision->getParticipante2());
        cout << "juego 2" << endl;
        emision->calculaPremio();
        cout << "Calcula premio" << endl;
        this->resumenSemanal->agregar(emision);
        cout << "Llegue aqui" << endl;
    }
}

void Game::juegoParticipante(Persona jugador){
    bool continua = true;
    int nivel = 0;
    while(continua && nivel < 15){
        if(jugador.getFifthyFifthy() && jugador.getLlamada() && jugador.getPublico()){
            continua = respondePregunta(4);
        }else{
        int opc1 = randomGen(0,1);
            if(opc1 == 0){
                if(!jugador.getLlamada()){
                    continua = respondePreguntaComodin();
                    jugador.setLlamada(true);
                }else if(!jugador.getPublico()){
                    continua = respondePreguntaComodin();
                    jugador.setPublico(true);
                }
                else{
                    continua = respondePregunta(2);
                    jugador.setFifthyFifthy(true);
                }
            }else{
                continua = respondePregunta(4);
            }
        }
        if(continua){
            nivel++;
            int plantar = randomGen(0,1);
            if(plantar == 1){
                jugador.setUltimaPregunta(nivel);
                jugador.setDineroAsegurado(determinarPremio(nivel));
                continua = false;
                return;
            }
        }else{
            jugador.setUltimaPregunta(nivel);
            if(nivel < 5){jugador.setDineroAsegurado(0);}
            else if(nivel < 10){jugador.setDineroAsegurado(1000000);}
            else {jugador.setDineroAsegurado(10000000);}
            continua = false;
            return;
        }
    }
    if(continua){
        jugador.setUltimaPregunta(nivel);
        jugador.setDineroAsegurado(300000000);
    }
}

bool Game::respondePregunta(int cantidad){
    int opcCorrecta = randomGen(1,cantidad);
    int opcParticipante = randomGen(1,cantidad);
    return opcCorrecta == opcParticipante;
}

bool Game::respondePreguntaComodin(){
    int opcCorrecta = randomGen(1,4);
    vector<double> posibilidades = {0.0, 0.0, 0.0, 0.0};
    double porcentajeAcumulado = 1.0;
    int posibleCorrecta = 0;
    double mayor = 0.0;
    for(int i=0;i<4;i++){
        posibilidades[i] = ayudaComodin(0.0, porcentajeAcumulado);
        porcentajeAcumulado-=posibilidades[i];
        if(posibilidades[i] > mayor){posibleCorrecta = i;}
        if(porcentajeAcumulado == 0.0){break;}
    }
    return (posibleCorrecta+1) == opcCorrecta;
}

int Game::determinarPremio(int nivel){
    switch (nivel){
    case 1:
        return 100000;
    case 2:
        return 200000;
    case 3:
        return 300000;
    case 4:
        return 500000;
    case 5:
        return 1000000;
    case 6:
        return 2000000;
    case 7:
        return 3000000;
    case 8:
        return 5000000;
    case 9:
        return 7000000;
    case 10:
        return 10000000;
    case 11:
        return 12000000;
    case 12:
        return 20000000;
    case 13:
        return 50000000;
    case 14:
        return 100000000;
    default:
        return 0;
    }
}

void Game::mostrarResultados() {
    this->resumenSemanal->mostrar();
}
