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

list <NodoServidores*> servers;
using namespace std;

void leerArchivos();
void menu();
void mostrarConexionesPorServidor();

int main() {    
    leerArchivos();    
     
    menu();
    return 0;
}

void menu(){
    int opcion;
    do{
        cout<<"Bienvenido al sistema de administracion de servidores"<<endl;
        cout<<"1. Mostrar conexiones por servidor"<<endl;
        cout<<"2. Calcular ruta"<<endl;
        cout<<"Elija una opcion: "<<endl;
        cin>>opcion;
        if(opcion == 1){
            mostrarConexionesPorServidor();
        }else if(opcion==2){

        }

    }while(opcion != 0);
    
}

void mostrarConexionesPorServidor(){
    
    for(NodoServidores* server : servers){
        if(server->getId() == "0"){
            cout<<"Servidor: "<<server->getNombre()<<endl;
        cout<<"Clientes: "<<endl;
        server->imprimirNodos();                 
        cout<<endl;
        cout<<"---------------------------------"<<endl; 
        }
        
    }
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

        if(cabecera->getId()==""){
            cabecera = new NodoServidores(id,nombre,tipo);
            servers.push_back(cabecera);          
        }else{
            cabecera->setSiguiente(new NodoServidores(id,nombre,tipo));
            cabecera = cabecera->getSiguiente();
            servers.push_back(cabecera);
        }
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
        
        for(NodoServidores* server : servers){
            if(server->getId() == idCliente && server->getTipo() == "cliente"){
                for(NodoServidores* server2 : servers){
                    if(server2->getId() == idServidor && server2->getTipo() == "router"){
                        server->agregarConexion(server2);
                    }
                }
            }else if(server->getId() == idCliente){
                for (NodoServidores* server2: servers){
                    if(server2->getId() == idServidor){
                        server->agregarConexion(server2);
                    }
                    
                }
                
            }
        }
         for(NodoServidores* server : servers){
            if(server->getId() == idServidor && server->getTipo() == "cliente"){
                for(NodoServidores* server2 : servers){
                    if(server2->getId() == idCliente && server2->getTipo() == "router"){
                        server->agregarConexion(server2);
                    }
                }
            }else if(server->getId() == idServidor){
                for(NodoServidores* server2:servers){
                    if(server2->getId() == idCliente){
                        server->agregarConexion(server2);
                    }
                }
                
            }
        }
    }
    conexiones.close();

 
}