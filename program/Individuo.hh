/** @file Individuo.hh
    @brief Especificación de la clase individuo
*/

#ifndef _INDIVIDUO_HH_
#define _INDIVIDUO_HH_

#include "Par_Cromosomas.hh"

#ifndef NO_DIAGRAM // esto hace que el Doxyfile de la sesión no incluya estas clases en los diagramas modulares, mientras que el compilador de c++ sí que las procesa correctamente
#include<set>
#include <list>
#include<iostream>
using namespace std;
#endif


/** @class Individuo
    @brief Representa un individuo

    Contiene un individuo con su par de cromosomas y rasgos.
*/
class Individuo
{
public:
  //Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un individuo.
      \pre <em>cierto</em>
      \post El resultado es un individuo vacio
  */
  Individuo();

  //Modificadoras

  /** @brief Añade un rasgo a un individuo

      \pre Individuo está inicializado y lleno, t no vacio
      \post Se ha añadido al individuo el rasgo t
  */
  void anadir_rasgo(const string &t);

  /** @brief Quita un rasgo a un individuo

      \pre Individuo está inicializado y lleno, t no vacio
      \post Se ha quitado al individuo el rasgo t
  */
  void treure_rasgo(const string &t);

  /** @brief Mira si un individuo tiene un rasgo o no, sino lo tiene lo pone

      \pre Individuo está inicializado y lleno, t no vacio
      \post Se ha devuelto true si tenia el rasgo, false sino lo tenia y además si este no tenia el rasgo, se le ha anadido
  */
  bool tiene_rasgo_ponerlo(const string &t);

  //Consultoras

  /** @brief Te dice cual es el conjunto de cromosomas del individuo

     \pre <em>cierto</em>
     \post El resultado es el par de cromosomas del individuo
  */
  Par_Cromosomas consulta_par_cromosomas() const;

  /** @brief Mira si un individuo tiene un rasgo o no

      \pre Individuo está inicializado y lleno, t no vacio
      \post Se ha devuelto true si tenia el rasgo, false sino lo tenia
  */
  bool tiene_rasgo(const string &t) const;

  //Lecturas

  /** @brief Rellena el Individuo con toda su información.

      \pre El canal de entrada hay preparadas una string de 2m de longitud con cada posicion un 0 o 1 que seran el par de cromosomas del individuo
      \post El individuo pasa a contener sus cromosomas
  */
  void leer();

  // Escrituras

  /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida; el par de cromosomas y los rasgos que tiene ese individuo
  */
  void escribir() const;

private:

  /** @brief El par de cromosomas de un individuo

      Tenemos el par de cromosomas de un individuo
 */
 Par_Cromosomas crom;// cromosomas;

 /** @brief Set de los nombres de los rasgos que ese idividuo tiene

     En todo momento, el set tiene todos los nombres de los rasgos que tiene ese individuo
 */
 set<string> ind_rasgos; //lista de rasgos del individuo
};
#endif
