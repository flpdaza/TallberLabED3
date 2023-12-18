#include <iostream>
#include <fstream>
#include <sstream>

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

    while(getline(conexiones, linea)){

        stringstream stream(linea);
        string idCliente,idServidor,velocidad,distancia;
        getline(stream, idCliente, delimitador);
        getline(stream, idServidor, delimitador);
        getline(stream, velocidad, delimitador);
        getline(stream, distancia, delimitador);
        //imprimir
        cout<<"idCliente: "<<idCliente<<endl;
    }
    conexiones.close();
    string opcion;
    cin>>opcion;

    return 0;
}