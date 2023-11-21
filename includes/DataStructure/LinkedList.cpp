#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

//Método de escritura en archivo:
void LinkedList::agregaATexto(string msg){
    ofstream outputFile("informe_urgencias.txt", ios::app);
    if(outputFile.is_open()){
        outputFile<<msg+"\n"<<endl;
        // cout << msg << endl;
    }
    outputFile.close();
}

LinkedList::LinkedList(){
    this->cabeza = nullptr;
}

void LinkedList::agregar(Dato* datos){
    Nodo* nuevoNodo = new Nodo(datos);
    if(!cabeza){
        cabeza = nuevoNodo;
    }else if (!cabeza->getSiguiente()){
        int codigoActual = cabeza->getDatos()->getCodigo();
        int codigo = datos->getCodigo();
        if(codigoActual > codigo){
            Nodo* aux = cabeza;
            cabeza = nuevoNodo;
            cabeza->setSiguiente(aux);
        }else{
            cabeza->setSiguiente(nuevoNodo);
        }
    }else{
        Nodo* actual = cabeza;
        Nodo* aux = nullptr;
        int codigoActual = actual->getDatos()->getCodigo();
        int codigo = datos->getCodigo();
        if(codigo < codigoActual){
            Nodo* aux = cabeza;
            cabeza = nuevoNodo;
            nuevoNodo->setSiguiente(aux);
        }else{
            while(actual->getSiguiente() && codigo >= codigoActual){
                aux = actual->getSiguiente();
                codigoActual = aux->getDatos()->getCodigo();
                if(codigo < codigoActual){
                    break;
                }
                actual = actual->getSiguiente();

            }
            if(actual->getSiguiente()){
                Nodo* aux = actual->getSiguiente();
                actual->setSiguiente(nuevoNodo);
                actual = actual->getSiguiente();
                actual->setSiguiente(aux);
            }else{
                actual->setSiguiente(nuevoNodo);
            }
        }
    }
}

void LinkedList::mostrar(){
    Nodo* actual = cabeza;
    string msg = "";
    while (actual) {
        msg = msg+actual->getDatos()->toString() + "-->";
        actual = actual->getSiguiente();
    }
    msg = msg + "[NULL]";
    this->agregaATexto(msg);
}

void LinkedList::pop(){
    if(!cabeza){
        return;
    }else{
        Nodo* aux = cabeza->getSiguiente();
        delete cabeza;
        cabeza = aux;
    }
}
Nodo* LinkedList::getHead(){
    return cabeza;
}
Dato* LinkedList::getDatoHead(){
    Dato* datos;
    if(cabeza){
        datos = cabeza->getDatos();
    }
    return datos;
}
int LinkedList::length(){
    int i = 0;
    if(cabeza){
        i++;
        Nodo* actual = cabeza;
        while(actual->getSiguiente()){
            actual = actual->getSiguiente();
            i++;
        }
    }
    return i;
}