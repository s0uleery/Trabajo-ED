#include <iostream>
#include <fstream>
using namespace std;

int main (){
    string nombreArchivo;
    cout << "¿Cuál es el nombre de su archivo?: ";
    cin >> nombreArchivo;

    ifstream nuevoArchivo(nombreArchivo);
    if (!nuevoArchivo) {
        cerr << "¡ERROR! No se ha podido abrir el archivo" << endl;
        return 1;
    }
}