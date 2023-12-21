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
        list <NodoServidores*> conexiones;
    public:
        NodoServidores(string id, string nombre, string tipo);
        string getId();
        string getNombre();
        string getTipo();
        NodoServidores* getSiguiente();
        void setSiguiente(NodoServidores* siguiente);
        void imprimir();
        void agregarConexion(NodoServidores* conexion);
        list<NodoServidores*> getConexiones();
        void imprimirConexiones();
};

NodoServidores::NodoServidores(string id, string nombre, string tipo) {
    this->id = id;
    this->nombre = nombre;
    this->tipo = tipo;
    this->siguiente = NULL;
    this->conexiones = list<NodoServidores*>();
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
    this->conexiones.push_back(conexion);
}

void NodoServidores::imprimirConexiones() {
    for(NodoServidores* conexion : this->conexiones) {
        conexion -> imprimir();
    }
}

list<NodoServidores*> NodoServidores::getConexiones() {
    return this->conexiones;
}