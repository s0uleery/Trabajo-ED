#include <iostream>
#include <fstream>
using namespace std;

int main (){
    string nombreArchivo;
    cout << "¿Cuál es el nombre y extensión de su archivo?: ";
    cin >> nombreArchivo;

    ifstream nuevoArchivo(nombreArchivo);
    if (!nuevoArchivo) {
        cerr << "¡ERROR! No se ha podido abrir el archivo" << endl;
        return 1;
    }

    int cantidadNodos;
    nuevoArchivo >> cantidadNodos;
    nuevoArchivo.ignore();

    int matrizAdy[cantidadNodos][cantidadNodos];

    char coma;

    for (int i = 0; i < cantidadNodos; ++i) {
        for (int j = 0; j < cantidadNodos; ++j) {
            nuevoArchivo >> matrizAdy[i][j];

         if (j < cantidadNodos - 1) {
                nuevoArchivo >> coma; 
            }
        }
    }
    nuevoArchivo.close();

    cout << "Matriz del grafo:" << endl;
    for (int i = 0; i < cantidadNodos; ++i) {
        for (int j = 0; j < cantidadNodos; ++j) {
            cout << matrizAdy[i][j] << " ";
        }
        cout << endl;
    }


}