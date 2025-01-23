#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Nodo{
public:
    char letra;
    vector<pair<Nodo*, int>> ady;

    Nodo(char letra) : letra(letra) {
    }
    };

void dijkstra(vector<Nodo*>& grafo, Nodo* inicial, vector<int>& distancias, vector<char>& padres){
    int n = grafo.size();
    distancias.assign(n, -1);
    padres.assign(n, 0);

    vector<bool> visitado(n,false);
    distancias[inicial -> letra - 'A'] = 0;

    for (int i = 0; i < n; i++){
        int actual = -1;
        int masCorto = -1;
        for (int j = 0; j < n; j++){
            if (!visitado[j] && distancias[j] != -1 && (masCorto == -1 || distancias[j] < masCorto)){
                masCorto = distancias[j];
                actual = j;
            }
        }
        if (actual == -1) break;

        Nodo* nodoActual = grafo[actual];
        visitado[actual] = true;

        for (vector<pair<Nodo*, int>>:: iterator it = nodoActual -> ady.begin(); it != nodoActual -> ady.end(); it++ ){
            Nodo* adyacente = it -> first;
            int peso = it -> second;
            int distancia = distancias[actual] + peso;

            if (distancias[actual] != -1 && (distancias[adyacente -> letra - 'A'] == -1 || distancia < distancias [adyacente -> letra - 'A'])){
                distancias[adyacente -> letra - 'A'] = distancia;
                padres[adyacente -> letra - 'A'] = nodoActual -> letra;
            }
        }
    }
}

void imprimirCaminoCorto(char destino, vector <char>& padres){
    if (padres[destino - 'A'] == 0){
        cout << destino;
        return;
    }
    imprimirCaminoCorto(padres[destino - 'A'], padres);
    cout << " -> " << destino;
}

void imprimirArbol(char destino, vector<char>& padres){
    cout << "Arbol del camino más corto: " << endl;
    char actual = destino;
    vector<char> camino;

    while (actual != 0 ){
        camino.push_back(actual);
        actual = padres[actual - 'A'];
    }

    for (vector<char> :: reverse_iterator it = camino.rbegin(); it != camino.rend(); it++){
        if (it != camino.rbegin()) cout << " -> ";
        cout << *it;
    }
    cout << endl;
}

int main (){
    string nombreArchivo;
    cout << "¿Cuál es el nombre y extensión de su archivo?: ";
    cin >> nombreArchivo;

    ifstream nuevoArchivo(nombreArchivo);
    if (!nuevoArchivo) {
        cerr << "¡ERROR! No se ha podido abrir el archivo" << endl;
        return 1;
    }

    vector<Nodo*> grafo;
    int cantidadNodos;
    nuevoArchivo >> cantidadNodos;
    nuevoArchivo.ignore();

    for (int i = 0; i <cantidadNodos; i++){
        char letra = 'A' + i;
        grafo.push_back(new Nodo(letra));
    }

    int matrizAdy[cantidadNodos][cantidadNodos];
    char coma;

    for (int i = 0; i < cantidadNodos; i++) {
        for (int j = 0; j < cantidadNodos; j++) {
            nuevoArchivo >> matrizAdy[i][j];

           if (j < cantidadNodos - 1) {
                nuevoArchivo >> coma;
            }
            if (matrizAdy[i][j] == 0 && i != j) {
                matrizAdy[i][j] = -1; 
            }
        }
    }
    nuevoArchivo.close();

    for (int i = 0; i < cantidadNodos; i++){
        for (int j = 0; j < cantidadNodos; j++){
            if (matrizAdy[i][j] != -1){
                grafo[i] -> ady.push_back(make_pair(grafo[j], matrizAdy[i][j]));
            }
        }
    }




}