#include <iostream>
#include <fstream>
#include <sstream>
#include "NodoConexiones.h"

#define CONEXIONES "archivos/conexiones.csv"
#define SERVIDORES "archivos/servidores.csv"

using namespace std;

int main() {
    ifstream conexiones(CONEXIONES);
    string linea;
    char delimitador = ',';
    // Leer la primera linea para ignorar los titulos
    getline(conexiones, linea);
    //leemos todas las lineas
    NodoConexiones* conexion = new NodoConexiones("","","","");
    int count = 1;
    while(getline(conexiones, linea)){
        stringstream stream(linea);
        string idCliente,idServidor,velocidad,distancia;
        getline(stream, idCliente, delimitador);
        getline(stream, idServidor, delimitador);
        getline(stream, velocidad, delimitador);
        getline(stream, distancia, delimitador);

        if(conexion->getIdCliente().empty()){
            conexion = new NodoConexiones(idCliente,idServidor,velocidad,distancia);            
        }else{
            conexion->setSiguiente(new NodoConexiones(idCliente,idServidor,velocidad,distancia));
            conexion = conexion->getSiguiente();
        }
        cout<<"Conexion "<<count<<endl;
        conexion->imprimir();
        cout<<endl;
        cout<<"---------------------------------"<<endl;
        count++;
    }
    conexiones.close();
    string opcion;
    cin>>opcion;

    return 0;
}