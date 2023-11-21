#include "Dato.h"
#include "../Persona.h"

using namespace std;

Dato::Dato(Persona participante1, Persona participante2, int totalPremio, int emision){
    this->participante1 = participante1;
    this->participante2 = participante2;
    this->totalPremio = totalPremio;
    this->emision = emision;
    this->codigo = codigo;
}

string Dato::toString(){
    return "Emision numero: "+ to_string(this->emision)+".\n Participante 1: "+this->participante1.toString()+".\n Participante 2: "+this->participante2.toString()+".\n Total de premios: "+to_string(this->totalPremio)+".";
}

Persona Dato::getParticipante1(){
    return this->participante1;
}

Persona Dato::getParticipante2(){
    return this->participante2;
}

int Dato::getTotalPremio(){
    return this->totalPremio;
}

int Dato::getEmision(){
    return this->emision;
}

void Dato::calculaPremio(){
    this->totalPremio = this->participante1.getDineroAsegurado() + this->participante2.getDineroAsegurado();
}