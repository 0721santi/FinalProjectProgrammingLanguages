#include "Persona.h"
#include <vector>
#include <string>
#include <random>

using namespace std;

//Funcion que sintetiza la clase random y la generacion de numeros aleatorios en pro del codigo limpio.
int randomGen(int lwrIdx, int highIdx){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> random(lwrIdx,highIdx);
    return random(rng);
}

//Genera nombre aleatorio
string Persona::creaNombre(){
    vector<string> nombres = {"Santiago", "Juan", "Andres", "Edison", "Oscar", "Eduardo", "Felipe", "Samuel", "Mateo", "Sofia","Salome","Andrea","Susana","Juliana","Maria","Nelly","Anderson","Jesus", "Jose", "Bernardo","Daniel", "Miguel", "Edwin", "Diego", "Cecilia", "Roberto", "Carolina", "Franciso", "Leidy", "Mauicio", "Jacobo", "Leon", "Alejandra", "Catalina", "Nidia", "Cristiano"};
    vector<string> apellidos = {"Idarraga", "Cardona", "Escobar", "Valencia", "Garcia", "Solis", "Usma", "Villa", "Garcia", "Ceballos", "Duarte", "Rojas", "Arcila", "Alzate", "Lopez", "Carrero", "Duque", "Mier", "Castillo", "Aguirre", "Zapata", "Ocampo", "Salazar", "Mosquera", "Candelo", "Andrade", "Alvez", "Angel", "Mejia", "Ronaldo", "Barrera", "Burgos", "Hincapie", "Sepulveda", "Padilla", "Uribe"};
    return nombres[randomGen(0, nombres.size())] + "_" + apellidos[randomGen(0, apellidos.size())];
}

//Genera nombre aleatorio a partir del nombre
string Persona::creaMail(string nombre){
    vector<string> mail = {"@gmail.com", "@hotmail.com", "@eafit.edu.co", "@yahoo.com"};
    return nombre + mail[randomGen(0, mail.size())];
}

//Genera numero de telefono alateorio
string Persona::creaTelefono(){
    string telefonoContacto = "";
    for(int i=0; i<=10; i++){
        telefonoContacto = telefonoContacto + to_string(randomGen(0,9));
    }
    return telefonoContacto;
}

Persona::Persona(){
    this->nombre = creaNombre();
    this->email = creaMail(this->nombre);
    this->numTelefono = creaTelefono();
    this->llamada = false;
    this->fifthyFifthy = false;
    this->publico = false;
    this->tiempoClasificacion = randomGen(1, 60);
}

string Persona::getNombre(){
    return this->nombre;
}

string Persona::getEmail(){
    return this->email;
}

string Persona::getNumTelefono(){
    return this->numTelefono;
}

bool Persona::getFifthyFifthy(){
    return this->fifthyFifthy;
}

bool Persona::getLlamada(){
    return this->llamada;
}

bool Persona::getPublico(){
    return this->publico;
}

int Persona::getDineroAsegurado(){
    return this->dineroAsegurado;
}

int Persona::getUltimaPregunta(){
    return this->ultimaPregunta;
}

int Persona::getTiempoClasificacion(){
    return this->tiempoClasificacion;
}

void Persona::setLlamada(bool llamada){
    this->llamada = llamada;
}

void Persona::setPublico(bool publico){
    this->publico = publico;
}

void Persona::setFifthyFifthy(bool fifthyFifthy){
    this->fifthyFifthy = fifthyFifthy;
}

void Persona::setUltimaPregunta(int ultimaPregunta){
    this->ultimaPregunta = ultimaPregunta;
}

void Persona::setDineroAsegurado(int dineroAsegurado){
    this->dineroAsegurado = dineroAsegurado;
}