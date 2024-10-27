#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>
#include <string>
using namespace std;

struct Pelicula {
    string nombre ;
    string director ;
    float rating ;
};

class Director {
    private :
        struct lNodo {
            Pelicula * val ;
            lNodo * sig ;
        };
        lNodo * head ;
        lNodo * curr ;
        lNodo * tail ;
        size_t size ; // longitud lista
        string nombre_director ;
        float rating_prom ;
    public :
        Director (string nombre){ // constructor
            nombre_director=nombre;
            head = nullptr;
            tail = nullptr;
            size = 0;
        } ; 
        ~ Director (){
            borrar_peliculas();
        }; // destructor
        void agregar_pelicula ( Pelicula * pelicula ); // agrega pelicula al final de la lista enlazada
        void ordenar () ; // ordena la lista
        void calcular_rating_promedio () ;
        void mostrar_peliculas () ;
        string sacar_nombre(); // auxiliar
        float sacar_ratingprom();
        size_t sacar_largo();
        lNodo* sacar_lista(){
            return head;
        };
        void print_pelis();
        string sacar_titulo();
        Pelicula* buscar_pelicula_en_lista(string titulo);
        void borrar_peliculas();
};

class Arboles {
    private :
    struct aNodo {
        Director * val ;
        aNodo * izq ;
        aNodo * der ;
    };
    aNodo * root_1 ; // raiz arbol ordenado por directores
    aNodo * curr_1 ;
    size_t size_1 ;
    aNodo * root_2 ; // raiz arbol ordenado por rating
    aNodo * curr_2 ;
    size_t size_2 ;
    int cant_directores;
    
public :
    Arboles (){
        root_1 = nullptr;
        root_2 = nullptr;
        cant_directores = 0;
    } ; // constructor
    ~Arboles(){
        limpiar_arbol(root_1);
    }; // destructor
    void insertar_pelicula ( Pelicula * pelicula );
    void copiar_arbol ();
    aNodo* conseguir_copiar_arbol (aNodo *arbol, aNodo*&arbol2){
        if (arbol == nullptr){
            return nullptr;
        }
        cant_directores++;
        arbol->val->sacar_ratingprom();
        insertar_rating(arbol2, arbol->val);
        conseguir_copiar_arbol(arbol->izq,arbol2);
        conseguir_copiar_arbol(arbol->der,arbol2);

        return arbol2;
    };
    
    void insertar_rating(aNodo*& raiz, Director* director);
    aNodo* insertar_en_arbol(aNodo* nodo, Pelicula* pelicula) {
        // Si llegamos a un nodo vacío, creamos un nuevo nodo para el director
        if (nodo == nullptr) {
            Director* nuevo_director = new Director(pelicula->director);
            nuevo_director->agregar_pelicula(pelicula);  // Agregamos la película al director
            nodo = new aNodo;
            nodo->val = nuevo_director;
            nodo->izq = nullptr;
            nodo->der = nullptr;
            return nodo;  // Retornamos el nuevo nodo creado
        }

        // comparo alfabeticamente
        if (pelicula->director < nodo->val->sacar_nombre()) {
            // si es menor a la izquierda
            nodo->izq = insertar_en_arbol(nodo->izq, pelicula);
        } else if (pelicula->director > nodo->val->sacar_nombre()) {
            // si es mayor a la derecha
            nodo->der = insertar_en_arbol(nodo->der, pelicula);
        } else {
            // si ya existe append a la lista del director
            nodo->val->agregar_pelicula(pelicula);
        }

        return nodo;  // devuelve el nodo
    };
    Director * buscar_director ( string director ); // retorna arreglo de peliculas
    Director * buscar_director_aux(aNodo* nodo, string nombre); // auxiliar
    Pelicula * buscar_pelicula ( string pelicula ); // retorna peliculas
    Pelicula * buscar_pelicula_aux (aNodo * nodo, string titulo);
    void mejores_directores ( int n); // Muestra por pantalla los mejores n directores .Enumerando de 1 a n.
    void mejores_directores_aux (aNodo *nodo, int& n,int &cont);
    void peores_directores ( int n );
    void peores_directores_aux(aNodo *nodo, int& n, int &cont);
    void limpiar_arbol(aNodo * nodo); // Muestra por pantalla los peores n directores .Enumerando desde m ( cantidad de directores ) hasta m-n.

};

#endif