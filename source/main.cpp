//Autores: Felipe Daza, Miguel Galleguillos
#include <iostream>
#include <fstream>
#include <sstream>
#include "NodoServidores.h"

#define CONEXIONES "archivos/conexiones.csv"
#define SERVIDORES "archivos/servidores.csv"

using namespace std;

int main() {
    ifstream servidores(SERVIDORES);
    string linea;
    char delimitador = ',';
    // Leer la primera linea para ignorar los titulos
    getline(servidores, linea);
    //leemos todas las lineas
    NodoServidores* servidor = new NodoServidores("","","");
    int count = 0;
    while(getline(servidores, linea)){
        stringstream stream(linea);
        string id,nombre,tipo;
        getline(stream, id, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, tipo, delimitador);

        if(servidor->getId().empty()){
            servidor = new NodoServidores(id,nombre,tipo);            
        }else{
            servidor->setSiguiente(new NodoServidores(id,nombre,tipo));
            servidor = servidor->getSiguiente();
        }
        cout<<"Conexion "<<count<<endl;
        servidor->imprimir();
        cout<<endl;
        cout<<"---------------------------------"<<endl;
        count++;
    }
    servidores.close();
    string opcion;
    cin>>opcion;

    return 0;
}