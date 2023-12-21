#pragma once
#include <iostream>

using namespace std;

class Conexion {
    private:
        string idCliente;
        string idServidor;
        int velocidad;
        int distancia;
    public:
        Conexion(string idCliente, string idServidor, int velocidad, int distancia);
        string getIdCliente();
        string getIdServidor();
        int getVelocidad();
        int getDistancia();
        void imprimir();
};

Conexion::Conexion(string idCliente, string idServidor, int velocidad, int distancia) {
    this->idCliente = idCliente;
    this->idServidor = idServidor;
    this->velocidad = velocidad;
    this->distancia = distancia;
}

string Conexion::getIdCliente() {
    return this->idCliente;
}

string Conexion::getIdServidor() {
    return this->idServidor;
}

int Conexion::getVelocidad() {
    return this->velocidad;
}

int Conexion::getDistancia() {
    return this->distancia;
}
//Funcion que imprime los datos de una conexion
void Conexion::imprimir() {
    cout << "idCliente: " << this->idCliente << endl;
    cout << "idServidor: " << this->idServidor << endl;
    cout << "Velocidad: " << this->velocidad << endl;
    cout << "Distancia: " << this->distancia << endl;
}
