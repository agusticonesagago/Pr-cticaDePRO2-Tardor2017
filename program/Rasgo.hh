/** @file Rasgo.hh
    @brief Especificación de la clase rasgo
*/

#ifndef _RASGO_HH_
#define _RASGO_HH_

#include "Par_Cromosomas.hh"
#include "Conj_Individuos.hh"

#ifndef NO_DIAGRAM // esto hace que el Doxyfile de la sesión no incluya estas clases en los diagramas modulares, mientras que el compilador de c++ sí que las procesa correctamente
#include <set>
#include <iostream>
#include <string>
using namespace std;
#endif


/** @class Rasgo
    @brief Representa un rasgo.

    Contiene un rasgo.
*/

class Rasgo
{
public:
  //Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un rasgo.
      \pre <em>cierto</em>
      \post El resultado es un rasgo vacio
  */
  Rasgo();

  //Modificadoras

  /** @brief Inicializa un rasgo

      \pre Par de cromsomas lleno, id valido, existe un inidividuo con identificador id, id no vacio (1 <= id <= n)
      \post El parametro implicito pasa a tener como par de cromosomas el p y con su primer identificador del individuo que lo tiene por primera vez
  */
  void inicializar_parcrom(Par_Cromosomas &p, int id);

  /** @brief Actualiza un rasgo

      \pre Conjunto de individuos lleno y inicializado, id valido, existe un inidividuo con identificador id, id no vacio (1 <= id <= n); el individuo tiene el rasgo
      \post El parametro implicito con su par de cromosomas actualizado (con la interesección de los que tenía con los cromosomas nuevos) y añadido el identificador del nuevo individuo que tiene ese rasgo
  */
  void actualizar(int id, Conj_Individuos& cindi);

  /** @brief Recalcula el par de cromosomas que sigue ese rasgo

      \pre Conjunto de individuos lleno y inicializado
      \post Rasgo con su par de cromosomas actualizado (con la interesección de los que tenía con los cromosomas nuevos)
  */
  void recalcular(Conj_Individuos& cindi);

  //Consultoras

  /** @brief Te borra del set el identificador id
     \pre Id valido (1 <= id <= n), existe un inidividuo con identificador id
     \post Devuelve un entero que puede ser 1 (si lo ha borrado) o 0(no lo ha borrado)
  */
  int consultar_set(int id) ;

  /** @brief Mira el tamaño del set de identificadores

      \pre <em>cierto</em>
      \post Se devuelve el tamaño del set
  */
  int tamany() const;

  // Escrituras

  /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida; el par de cromosomas con guiones en los genes que no coinciden de los par de cromosomas de los individuos; sino pone el que sigue; y los ids de los individuos
  */
  void escribir() const;

private:

  /** @brief Set de los identificadores que tienen ese rasgo

      Tenemos un set de enteros, donde cada uno de los enteros representa los identificadores de los individuos que tienen ese rasgo
  */
  set<int> rasg_indis;

  /** @brief Par de cromosomas que sigue ese rasgo; la intereseccion de los cromosomas de todos los individuos que tienen ese rasgo

      Tenemos un par de cromosomas que es el que sigue los individuos que tienen ese rasgo
  */
  Par_Cromosomas pc;
};
#endif
