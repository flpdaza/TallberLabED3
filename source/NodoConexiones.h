#pragma once
#include <iostream>

using namespace std;

class NodoConexiones {
    private:
        string idCliente;
        string idServidor;
        string velocidad;
        string distancia;
        NodoConexiones* siguiente;
    public:
        NodoConexiones(string idCliente, string idServidor, string velocidad, string distancia);
        string getIdCliente();
        string getIdServidor();
        string getVelocidad();
        string getDistancia();
        NodoConexiones* getSiguiente();
        void setSiguiente(NodoConexiones* siguiente);
        void imprimir();
};

NodoConexiones::NodoConexiones(string idCliente, string idServidor, string velocidad, string distancia) {
    this->idCliente = idCliente;
    this->idServidor = idServidor;
    this->velocidad = velocidad;
    this->distancia = distancia;
    this->siguiente = NULL;
}

string NodoConexiones::getIdCliente() {
    return this->idCliente;
}

string NodoConexiones::getIdServidor() {
    return this->idServidor;
}   

string NodoConexiones::getVelocidad() {
    return this->velocidad;
}

string NodoConexiones::getDistancia() {
    return this->distancia;
}

NodoConexiones* NodoConexiones::getSiguiente() {
    return this->siguiente;
}

void NodoConexiones::setSiguiente(NodoConexiones* siguiente) {
    this->siguiente = siguiente;
}

void NodoConexiones::imprimir() {
    cout << "idCliente: " << this->idCliente << endl;
    cout << "idServidor: " << this->idServidor << endl;
    cout << "velocidad: " << this->velocidad << endl;
    cout << "distancia: " << this->distancia << endl;
}

