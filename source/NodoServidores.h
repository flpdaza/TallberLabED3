#pragma once
#include <iostream>
#include <list>
#include "Conexion.h"
using namespace std;

class NodoServidores {
    private:
        string id;
        string nombre;
        string tipo;
        NodoServidores* siguiente;
        list <NodoServidores*> Nodos;
        list <Conexion*> conexiones;
    public:
        NodoServidores(string id, string nombre, string tipo);
        string getId();
        string getNombre();
        string getTipo();
        NodoServidores* getSiguiente();
        void setSiguiente(NodoServidores* siguiente);
        void imprimir();
        void agregarConexion(NodoServidores* conexion);
        list<NodoServidores*> getNodos();
        void imprimirNodos();
};

NodoServidores::NodoServidores(string id, string nombre, string tipo) {
    this->id = id;
    this->nombre = nombre;
    this->tipo = tipo;
    this->siguiente = NULL;
    this->Nodos = list<NodoServidores*>();
}

string NodoServidores::getId() {
    return this->id;
}

string NodoServidores::getNombre() {
    return this->nombre;
}   

string NodoServidores::getTipo() {
    return this->tipo;
}

NodoServidores* NodoServidores::getSiguiente() {
    return this->siguiente;
}

void NodoServidores::setSiguiente(NodoServidores* siguiente) {
    this->siguiente = siguiente;
}

void NodoServidores::imprimir() {
    cout << "id: " << this->id << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Tipo: " << this->tipo << endl;
}

void NodoServidores::agregarConexion(NodoServidores* conexion) {
    this->Nodos.push_back(conexion);
}

void NodoServidores::imprimirNodos() {
    for(NodoServidores* conexion : this->Nodos) {
        conexion -> imprimir();
    }
}

list<NodoServidores*> NodoServidores::getNodos() {
    return this->Nodos;
}