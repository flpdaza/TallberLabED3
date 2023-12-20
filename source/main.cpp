//Autores: Felipe Daza, Miguel Galleguillos
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "Grafo.h"
#include "NodoServidores.h"
#include "Conexion.h"


#define CONEXIONES "archivos/conexiones.csv"
#define SERVIDORES "archivos/servidores.csv"

const int cantServidores = 299;
list <NodoServidores*> servers;
using namespace std;

void leerArchivos();
void menu();
void mostrarClientesPorServidor();
void crearGrafo(int);

int main() {
    crearGrafo(); 
    leerArchivos();    
    menu();
    return 0;
}

void menu(){
    int opcion;
    do{
        cout<<"Bienvenido al sistema de administracion de servidores"<<endl;
        cout<<"1. Mostrar clientes por servidor"<<endl;
        cout<<"Elija una opcion: "<<endl;
        cin>>opcion;
        if(opcion == 1){
            mostrarClientesPorServidor();
        }

    }while(opcion != 0);
    
}

void mostrarClientesPorServidor(){
    
    for(NodoServidores* server : servers){
        cout<<"Servidor: "<<server->getNombre()<<endl;
        cout<<"Clientes: "<<endl;
        server->getConexiones();                 
        cout<<endl;
        cout<<"---------------------------------"<<endl; 
    }
}

void crearGrafo(){
    Grafo* grafo = new Grafo();

}

void leerArchivos(){
    ifstream servidores(SERVIDORES);
    string linea;
    char delimitador = ',';
    // Leer la primera linea para ignorar los titulos
    getline(servidores, linea);
    //leemos todas las lineas
    NodoServidores* cabecera = new NodoServidores("","","");
    while(getline(servidores, linea)){
        stringstream stream(linea);
        string id,nombre,tipo;
        getline(stream, id, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, tipo, delimitador);

        if(cabecera->getId().empty()){
            cabecera = new NodoServidores(id,nombre,tipo);
            servers.push_back(cabecera);          
        }else{
            cabecera->setSiguiente(new NodoServidores(id,nombre,tipo));
            cabecera = cabecera->getSiguiente();
            servers.push_back(cabecera);
        }

        /*cout<<"Conexion "<<cantServidores<<endl;
        cabecera->imprimir();
        cout<<endl;
        cout<<"---------------------------------"<<endl;*/
    }
    servidores.close();
    
    ifstream conexiones(CONEXIONES);
    string linea2;
    char delimitador2 = ',';
    // Leer la primera linea para ignorar los titulos
    getline(conexiones, linea2);
    //leemos todas las lineas
    while(getline(conexiones, linea2)){
        stringstream stream(linea2);
        string idCliente,idServidor,velocidad,distancia;
        getline(stream, idCliente, delimitador2);
        getline(stream, idServidor, delimitador2);
        getline(stream, velocidad, delimitador2);
        getline(stream, distancia, delimitador2);
        Conexion conexion(idCliente,idServidor,stoi(velocidad),stoi(distancia));
        for(NodoServidores* server : servers){
            if(server->getId() == idServidor){
                server->agregarConexion(conexion);
            }
        }
    }
    conexiones.close();

 
}