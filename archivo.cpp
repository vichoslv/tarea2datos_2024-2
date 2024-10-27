#include "funciones.hpp"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int cantidad_lineas;
    ifstream archivo("Peliculas.txt");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    archivo>>cantidad_lineas;
    archivo.ignore();
    Pelicula* peliculas = new Pelicula[cantidad_lineas];

    for(int i=0; i<cantidad_lineas; i++){
        string linea;
        getline(archivo,linea);
        int pos1 = linea.find(';');
        string titu = linea.substr(0,pos1);
        //cout << titu << endl;
        string aux = linea.substr(pos1 + 1);
        int pos2 = aux.find(';');
        string dire = aux.substr(0,pos2);
        //cout << dire <<endl;
        string rat = aux.substr(pos2 + 1);
        //cout << rat << endl;
        peliculas[i].nombre = titu;
        peliculas[i].director = dire;
        peliculas[i].rating = stof(rat);
    }

    Arboles arbol;
    for (int i = 0; i < cantidad_lineas; i++) {
       arbol.insertar_pelicula(&peliculas[i]);  // Insertar cada película y crear el árbol
    }
    arbol.copiar_arbol();
    string comando;
    bool activo = true;

    while(activo == true){
        getline(cin,comando);
        if (comando.substr(0, 3) == "sd "){
            string director_aux = comando.substr(3);
            Director* director = arbol.buscar_director(director_aux);

            if (director != nullptr){
                director->ordenar();
                director->print_pelis();
            }
        }
        else if (comando.substr(0, 3) == "sm "){
            string pelicula_aux = comando.substr(3);
            Pelicula* pelicula = arbol.buscar_pelicula(pelicula_aux);

            if(pelicula != nullptr){
                cout << pelicula->nombre << " / " << pelicula->director << " / " << pelicula->rating << endl;
            }
        }
        else if (comando.substr(0, 3) == "br "){
            int mejor_aux = stoi(comando.substr(3));
            arbol.mejores_directores(mejor_aux);
        }
        else if (comando.substr(0, 3) == "wr "){
            int peor_aux = stoi(comando.substr(3));
            arbol.peores_directores(peor_aux);
        }
        else if (comando == "e"){
            activo = false;
            break;
        }
    }

    delete[] peliculas;
    archivo.close();
    return 0;
}