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
        list <Conexion> conexiones;
    public:
        NodoServidores(string id, string nombre, string tipo);
        string getId();
        string getNombre();
        string getTipo();
        NodoServidores* getSiguiente();
        void setSiguiente(NodoServidores* siguiente);
        void imprimir();
        void agregarConexion(Conexion conexion);
        void getConexiones();
};

NodoServidores::NodoServidores(string id, string nombre, string tipo) {
    this->id = id;
    this->nombre = nombre;
    this->tipo = tipo;
    this->siguiente = NULL;
    this->conexiones = list<Conexion>();
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

void NodoServidores::agregarConexion(Conexion conexion) {
    this->conexiones.push_back(conexion);
}

void NodoServidores::getConexiones() {
    for(Conexion conexion : this->conexiones) {
        conexion.imprimir();
    }
}