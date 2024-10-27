#ifndef COMENTARIOS_HPP
#define COMENTARIOS_HPP_HPP
/*****
 *
 * void agregar_pelicula
 *****
 *
 * Agrega una película a la lista enlazada de películas del director.
 *****
 *
 * Input:
 *
 * Pelicula* pelicula : Puntero a la película que se agregará a la lista.
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * void ordenar
 *****
 *
 * Ordena la lista de películas de un director en orden alfabético por nombre.
 *****
 *
 * Input:
 *
 * None
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * void calcular_rating_promedio
 *****
 *
 * Calcula el promedio de los ratings de todas las películas de un director.
 *****
 *
 * Input:
 *
 * None
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * void mostrar_peliculas
 *****
 *
 * Imprime en pantalla los nombres de todas las películas del director.
 *****
 *
 * Input:
 *
 * None
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * string sacar_nombre
 *****
 *
 * Devuelve el nombre del director.
 *****
 *
 * Input:
 *
 * None
 *****
 *
 * Returns:
 *
 * string, El nombre del director.
 *****/
/*****
 *
 * float sacar_ratingprom
 *****
 *
 * Calcula y devuelve el rating promedio del director.
 *****
 *
 * Input:
 *
 * None
 *****
 *
 * Returns:
 *
 * float, El rating promedio de todas las películas del director.
 *****/
/*****
 *
 * size_t sacar_largo
 *****
 *
 * Devuelve el número de películas del director.
 *****
 *
 * Input:
 *
 * None
 *****
 *
 * Returns:
 *
 * size_t, La cantidad de películas del director.
 *****/
/*****
 *
 * void print_pelis
 *****
 *
 * Imprime en pantalla el nombre y el rating de cada película del director.
 *****
 *
 * Input:
 *
 * None
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * string sacar_titulo
 *****
 *
 * Devuelve el título de la primera película de la lista.
 *****
 *
 * Input:
 *
 * None
 *****
 *
 * Returns:
 *
 * string, El nombre de la primera película en la lista.
 *****/
/*****
 *
 * Pelicula* buscar_pelicula_en_lista
 *****
 *
 * Busca una película en la lista de películas del director según el título.
 *****
 *
 * Input:
 *
 * string titulo : Título de la película a buscar.
 *****
 *
 * Returns:
 *
 * Pelicula*, Puntero a la película encontrada, o nullptr si no existe.
 *****/
/*****
 *
 * void borrar_peliculas
 *****
 *
 * Elimina todas las películas de la lista del director.
 *****
 *
 * Input:
 *
 * None
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * void insertar_pelicula
 *****
 *
 * Inserta una película en el árbol según el nombre del director.
 *****
 *
 * Input:
 *
 * Pelicula* pelicula : Puntero a la película a insertar.
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * void copiar_arbol
 *****
 *
 * Realiza una copia del árbol de directores en un segundo árbol.
 *****
 *
 * Input:
 *
 * None
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * Director* buscar_director
 *****
 *
 * Busca un director en el árbol por nombre.
 *****
 *
 * Input:
 *
 * string director : Nombre del director a buscar.
 *****
 *
 * Returns:
 *
 * Director*, Puntero al director encontrado, o nullptr si no existe.
 *****/
/*****
 *
 * Director* buscar_director_aux
 *****
 *
 * Función auxiliar para buscar un director en el árbol.
 *****
 *
 * Input:
 *
 * aNodo* nodo : Nodo del árbol para iniciar la búsqueda.
 * string nombre_dir : Nombre del director a buscar.
 *****
 *
 * Returns:
 *
 * Director*, Puntero al director encontrado, o nullptr si no existe.
 *****/
/*****
 *
 * Pelicula* buscar_pelicula
 *****
 *
 * Busca una película en el árbol de directores por título.
 *****
 *
 * Input:
 *
 * string pelicula : Título de la película a buscar.
 *****
 *
 * Returns:
 *
 * Pelicula*, Puntero a la película encontrada, o nullptr si no existe.
 *****/
/*****
 *
 * Pelicula* buscar_pelicula_aux
 *****
 *
 * Función auxiliar para buscar una película en el árbol.
 *****
 *
 * Input:
 *
 * aNodo* nodo : Nodo del árbol para iniciar la búsqueda.
 * string titulo : Título de la película a buscar.
 *****
 *
 * Returns:
 *
 * Pelicula*, Puntero a la película encontrada, o nullptr si no existe.
 *****/
/*****
 *
 * void mejores_directores
 *****
 *
 * Muestra en pantalla los mejores directores según su rating promedio.
 *****
 *
 * Input:
 *
 * int n : Número de directores a mostrar.
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * void mejores_directores_aux
 *****
 *
 * Función auxiliar para mostrar los mejores directores.
 *****
 *
 * Input:
 *
 * aNodo* nodo : Nodo del árbol para iniciar la búsqueda.
 * int& n : Número de directores restantes a mostrar.
 * int& cont : Contador de posición en la lista.
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * void peores_directores
 *****
 *
 * Muestra en pantalla los peores directores según su rating promedio.
 *****
 *
 * Input:
 *
 * int n : Número de directores a mostrar.
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * void peores_directores_aux
 *****
 *
 * Función auxiliar para mostrar los peores directores.
 *****
 *
 * Input:
 *
 * aNodo* nodo : Nodo del árbol para iniciar la búsqueda.
 * int& n : Número de directores restantes a mostrar.
 * int& cont : Contador de posición en la lista.
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * void limpiar_arbol
 *****
 *
 * Limpia el árbol, eliminando todos sus nodos y liberando memoria.
 *****
 *
 * Input:
 *
 * aNodo* nodo : Nodo inicial para empezar a limpiar.
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * void insertar_rating
 *****
 *
 * Inserta un director en el árbol de ratings de directores.
 *****
 *
 * Input:
 *
 * aNodo*& raiz : Referencia a la raíz del árbol.
 * Director* director : Puntero al director a insertar.
 *****
 *
 * Returns:
 *
 * void, No retorna un valor.
 *****/
/*****
 *
 * aNodo* insertar_en_arbol
 *****
 *
 * Inserta una película en el árbol de directores. Si el director ya existe en el árbol,
 * se agrega la película a su lista; de lo contrario, crea un nuevo nodo para el director.
 *****
 *
 * Input:
 *
 * aNodo* nodo : Nodo actual en el árbol en el cual se realizará la inserción.
 * Pelicula* pelicula : Puntero a la película que se desea insertar.
 *****
 *
 * Returns:
 *
 * aNodo*, Retorna el nodo actualizado en el árbol.
 *****/
 #endif