#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <string>
#include "base.hpp"
using namespace std;

void Director::agregar_pelicula(Pelicula *pelicula){
    // recorro peliculas una vez encuentro una pelicula del mismo director hago append a la lista enlazada de peliculas (lNodo)
    lNodo * peli = new lNodo;
    peli->val = pelicula;
    peli->sig = nullptr;

    if(tail != nullptr){
        tail->sig = peli;
    }

    tail = peli;

    if(head == nullptr){
        head = tail;
    }

    size++;
}

void Director::ordenar() {
    if (head == nullptr) {
        return;
    }

    bool flag;
    lNodo* previo = nullptr;

    do {
        flag = false;
        curr = head;
        while (curr->sig != previo) {
            if (curr->val->nombre > curr->sig->val->nombre) {
                Pelicula* nodoaux = curr->val;
                curr->val = curr->sig->val;
                curr->sig->val = nodoaux;
                flag = true;
            }
            curr = curr->sig;
        }
        previo = curr;
    } while (flag);
}

void Director::calcular_rating_promedio(){
    // recorrer todas las peliculas del director y anadir a size la cantidad, con este size calcular el rating promedio
    curr = head;
    float suma_rating = 0;
    int cant_movies = 0;
    if(curr==nullptr){
        return;
    }
    while (curr != nullptr){
        suma_rating += curr->val->rating;
        cant_movies++;
        curr=curr->sig;
    }
    if (cant_movies >0){
        rating_prom = suma_rating/cant_movies;
    }
}

void Director::mostrar_peliculas(){
    // recorrer todas las peliculas e ir imprimiendolas una por una
    if (head==nullptr){
        return;
    }
    curr= head;
    while(curr != nullptr){
        cout<< curr->val->nombre<<endl;
        curr=curr->sig;
    }
}

string Director::sacar_nombre(){
    return nombre_director;
}

float Director::sacar_ratingprom(){
    calcular_rating_promedio();
    return rating_prom;
}

size_t Director::sacar_largo(){
    return size;
}
void Director::print_pelis(){
    lNodo* actual = head;

    while (actual != nullptr){
        cout << actual->val->nombre << " / " << actual->val->rating << "\n";
        actual = actual->sig;
    }
}
string Director::sacar_titulo(){
    return head->val->nombre;
}
Pelicula * Director::buscar_pelicula_en_lista(string titulo){
    lNodo * actual = head;
    while (actual != nullptr){
        if(actual->val->nombre == titulo){
            return actual->val;
        }
        actual = actual->sig;
    }
    return nullptr; // -> esto es porsi no la encuentra xdd
}

void Director::borrar_peliculas(){
    lNodo * actual = head;
    lNodo* siguiente;
    while(actual != nullptr){
        siguiente = actual->sig;
        delete actual;
        actual = siguiente;
    }
    head = nullptr;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Arboles::insertar_pelicula(Pelicula * pelicula){
    root_1 = insertar_en_arbol(root_1, pelicula);
}


void Arboles::copiar_arbol(){
    conseguir_copiar_arbol(root_1,root_2);
}

Director * Arboles::buscar_director(string director){
    return buscar_director_aux(root_1, director);
}

Director * Arboles::buscar_director_aux(aNodo* nodo, string nombre_dir){
    if (nodo==nullptr){
        return nullptr;
    }
    if (nodo->val->sacar_nombre() == nombre_dir ){
        return nodo->val;
    }
    else if(nodo->val->sacar_nombre() > nombre_dir){
        return buscar_director_aux(nodo->izq, nombre_dir);
    }
    else{
        return buscar_director_aux(nodo->der, nombre_dir);
    }
}

Pelicula * Arboles::buscar_pelicula(string pelicula){
    return buscar_pelicula_aux(root_1, pelicula);
}

Pelicula * Arboles::buscar_pelicula_aux (aNodo * nodo, string titulo){
    if (nodo == nullptr){
        return nullptr;
    }
    Pelicula* peli_si = nodo->val->buscar_pelicula_en_lista(titulo);
    if(peli_si != nullptr){
        return peli_si;
    }

    Pelicula * peli_izq = buscar_pelicula_aux(nodo->izq, titulo);
    if(peli_izq != nullptr){
        return peli_izq;
    }
    return buscar_pelicula_aux(nodo->der, titulo);    
}

void Arboles::mejores_directores(int n){
    int cont = 1;
    mejores_directores_aux(root_2, n, cont);
}
void Arboles::mejores_directores_aux(aNodo *nodo, int& n, int &cont){
    if(nodo == nullptr || n==0){
        return;
    }

    mejores_directores_aux(nodo->der, n, cont);

    if(n > 0){
        cout << "(" << cont << ")" << " " << nodo->val->sacar_nombre() << endl;
        n--;
        cont++;
    }
    mejores_directores_aux(nodo->izq, n, cont);
}

void Arboles::peores_directores(int n){
    int cont = cant_directores; 
    peores_directores_aux(root_2, n, cont);
}
void Arboles::peores_directores_aux(aNodo *nodo, int &n,int &cont){
    if(nodo== nullptr || n==0){
        return;
    }
    peores_directores_aux(nodo->izq, n, cont);
    if(n > 0){
        cout<< "(" <<cont << ")" << " " << nodo->val->sacar_nombre() << endl;
        n--;
        cont--;
    }
    peores_directores_aux(nodo->der, n, cont);
}

void Arboles::limpiar_arbol(aNodo * nodo){
    if (nodo == nullptr ){
        return;
    }
    
    limpiar_arbol(nodo->izq);
    limpiar_arbol(nodo->der);
    nodo->val->borrar_peliculas();
    delete nodo->val;
    delete nodo;
}

void Arboles::insertar_rating(aNodo*& raiz, Director* director){
    if(raiz == nullptr){
        raiz = new aNodo;
        raiz->val = new Director(*director);
        raiz->izq = nullptr;
        raiz->der = nullptr;
    }
    else{
        if (director->sacar_ratingprom() < raiz->val->sacar_ratingprom()){
            insertar_rating(raiz->izq, director);
        }
        else{
            insertar_rating(raiz->der, director);
        }
    }
}


#endif