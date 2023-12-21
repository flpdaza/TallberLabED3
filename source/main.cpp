//Autores: Felipe Daza, Miguel Galleguillos
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <cmath>
#include "Grafo.h"
#include "NodoServidores.h"
#include "Conexion.h"


#define CONEXIONES "archivos/conexiones.csv"
#define SERVIDORES "archivos/servidores.csv"

list <NodoServidores*> servers;
list <Conexion*> conections;

using namespace std;

void leerArchivos();
void menu();
void mostrarConexionesPorServidor();
void mostrarConexiones();
void calcularTiempo();

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
        cout<<"2. Mostrar conexiones"<<endl;
        cout<<"3. Calcular ruta"<<endl;
        cout<<"Elija una opcion: "<<endl;
        cin>>opcion;
        if(opcion == 1){
            mostrarConexionesPorServidor();
        }else if(opcion==2){
            mostrarConexiones();
        }else if(opcion == 3){
            calcularTiempo();
        }

    }while(opcion != 0);
    
}
//Funcion que muestra las conexiones puntuales de un servidor
void mostrarConexionesPorServidor(){
    string id;
    cout<<"Ingrese el id del servidor: "<<endl;
    cin>>id;
    for(NodoServidores* server : servers){
        if(server->getId() == id){
            cout<<endl;
            cout<<"Servidor: "<<server->getNombre()<<". Tipo: "<<server->getTipo()<<endl;
            cout<<"Conexiones del servidor: "<<endl;
            cout<<endl;
            server->imprimirNodos();                 
            cout<<endl;
            
        }
        
    }
}
//Funcion que calcula el tiempo de envio de un archivo y lo envía al grafo para calcular la ruta
void calcularTiempo(){
    int peso;
            string origen;
            string destino;
            cout<<"Ingrese peso archivo en MB: "<<endl;
            cin>>peso;
            cout<<"Ingrese el id del servidor de origen: "<<endl;
            cin>>origen;
            cout<<"Ingrese el id del servidor de destino: "<<endl;
            cin>>destino;
            double cantPartes;
            double velocidad;
            double distancia;
            double tiempo;
            double tiempoTotal = 0;
            bool encontrado = false;
            list<NodoServidores*> aux;
            for(NodoServidores* server: servers){
                if(server->getId() == origen && server->getTipo() == "cliente"){
                    aux = server->getNodos();
                    for(NodoServidores* server2: aux){
                        if(server2->getId() == destino){
                            encontrado = true;
                            for(Conexion* conect : conections){
                                if(conect->getIdCliente() == origen){

                                distancia = conect->getDistancia();
                                velocidad = conect->getVelocidad();
                                cantPartes = peso/velocidad;
                                }        
                            }   
                        }

                    }
                    
                }             
                        
            }
            
            if(encontrado){
                tiempo = (peso/velocidad)*distancia;
                Grafo* grafo = new Grafo();
                grafo->agregarConexion(origen,destino,tiempo);
                grafo -> mostrarCamino(origen, destino, cantPartes);
            }else{
                cout<<endl;
                cout<<"No se puede enviar el archivo"<<endl;
                cout<<endl;
            }
}

//Funcion que muestra detalladamente las conexiones de un servidor, es decir incluye velocidad, distancia, etc.
void mostrarConexiones(){
    string id;
    cout<<"Ingrese el id del servidor: "<<endl;
    cin>>id;
    for(Conexion* conect : conections){
        if(conect->getIdCliente() == id){
            cout<<"Servidor: "<<conect->getIdCliente()<<endl;
            cout<<"Conexiones: "<<endl;
            conect->imprimir();                 
            cout<<endl;
            cout<<"---------------------------------"<<endl; 
        }
        
    }
}

//Funcion que lee los archivos y los guarda en listas
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
        Conexion* conexion = new Conexion(idCliente,idServidor,stoi(velocidad),stoi(distancia));
        conections.push_back(conexion);
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