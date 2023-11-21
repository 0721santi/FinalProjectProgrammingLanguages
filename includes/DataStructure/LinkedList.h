#ifndef LinkedList_H
#define LinkedList_H
#include <string>
#include "Nodo.h"

class LinkedList{
private:
    Nodo* cabeza;
    void agregaATexto(std::string msg);
public:
    LinkedList();

    void agregar(Dato* datos);
    void mostrar();
    void pop();
    Dato* getDatoHead();
    Nodo* getHead();
    int length();
};

#endif