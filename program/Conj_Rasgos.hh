
/** @file Conj_Rasgos.hh
    @brief Especificación de la clase Conjunto de Rasgos
*/

#ifndef _CONJ_RASGOS_HH_
#define _CONJ_RASGOS_HH_

#include "Rasgo.hh"
#include "Conj_Individuos.hh"

#ifndef NO_DIAGRAM // esto hace que el Doxyfile de la sesión no incluya estas clases en los diagramas modulares, mientras que el compilador de c++ sí que las procesa correctamente
#include<iostream>
#include <map>
#include <string>
using namespace std;
#endif


/** @class Conj_Rasgos
    @brief Representa un conjunto de rasgos.

    Contiene todos los rasgos de todos los individuos en cada momento.
*/
class Conj_Rasgos
{
public:
  //Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un Conj_Rasgos
      \pre <em>cierto</em>
      \post El resultado es un conjunto de rasgos vacio
  */
  Conj_Rasgos();

  //Modificadoras

  /** @brief Añade un rasgo al conjunto de rasgos
      \pre 1 <= id <= n, id valido, existe individuo id, t lleno , Conj_Individuos inicializado y lleno
      \post El parámetro implícito pasa a contener sus rasgos originales más el nuevo, el añadido si este rasgo no estaba; esto sucede cuando el individuo no tenia ese rasgo y devolverá false. Sino devolverá true.
  */
  bool anadir_rasgo(int id, const string &t, Conj_Individuos& cindi);

  /** @brief Quita un rasgo al conjunto de rasgos
      \pre 1 <= id <= n, id valido,existe individuo id, t lleno , Conj_Individuos inicializado y lleno
      \post El parámetro implícito pasa a contener sus rasgos originales menos el rasgo quitado, esto pasa si el individuo tenia el rasgo y devuelve true. Sino delvolverá false.
  */
  bool treure_rasgo(int id, const string &t, Conj_Individuos & cindi);

  /** @brief Limpia el Conj_Rasgos de toda su información, dejandola vacía
      \pre <em> cierto </em>
      \post El parámetro implícito pasa a ser vacío
  */
  void inicializar_conj_rasgos();

  //Consultoras

  /** @brief Operación de escritura del subarbol resultado en inorden  del rasgo y mirar si esta o no ese rasgo en algun individuo del arbol

      \pre t no vacio, Conj_Individuos inicializado y lleno
      \post Si existe el rasgo se escribira el subarbol resultado en inorden, por el canal estándar de salida. Sino devolverá false.
  */
  bool existe(const string &t, Conj_Individuos & cindi) const;


  //Escrituras

  /** @brief Operación de escritura de un rasgo del conjunto de rasgos

      \pre t no vacio
      \post Escribe por el canal estandard el contenido del parámetro implícito ;el par de crom y los ids de los individuos del rasgo, si estaba el rasgo. Sino devuelve false.
  */
  bool escribir_rasgo(const string &t) const;

private:

  /** @brief Un map que guarda el nombre del rasgo y el Rasgo

      Este map en todo momento tiene el nombre del rasgo y el Rasgo en sí de cada uno de los rasgos existentes
  */
  map<string, Rasgo> mrasgos; //map que representa todos los rasgos
};
#endif
