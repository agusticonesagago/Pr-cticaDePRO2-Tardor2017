/** @file Conj_Individuos.hh
    @brief Especificación de la clase Conjunto de Individuos
*/

#ifndef _CONJ_INDIVIDUOS_HH_
#define _CONJ_INDIVIDUOS_HH_

#include "Individuo.hh"

#ifndef NO_DIAGRAM // esto hace que el Doxyfile de la sesión no incluya estas clases en los diagramas modulares, mientras que el compilador de c++ sí que las procesa correctamente
#include <iostream>
#include <vector>
#include "BinTree.hh"
using namespace std;
#endif


/** @class Conj_Individuos
    @brief Representa un conjunto de individuos

    Contiene todos los individuos del laboratorio
*/
class Conj_Individuos
{
public:
  //Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un Conj_Individuos.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de individuos vacio
  */
  Conj_Individuos();

  //Modificadoras

  /** @brief Añade a un individuo del conjunto de individuos un rasgo

       \pre Conj_Individuos está inicializada y llena, id valida, existe individuo id y esta entre 1 <= id <= n, t llena
       \post Añade al individuo id el rasgo t
  */
  void anadir_rasgo_individuo(const string &t, int id);

  /** @brief Quita un rasgo a un individuo del conjunto de individuos

       \pre Conj_Individuos está inicializada y llena, id valido, existe individuo id y esta entre 1 <= id <= n y t no vacio
       \post Se ha quitado el rasgo al individuo id del conjunto de individuos
  */
  void treure_rasgo_individuo(const string &t, int id);

  /** @brief Rellena el Conj_Individuos con toda su información y también se crea el arbol lleno.

      \pre En el canal de entrada hay una n que significa que existen n individuos
      \post El parámetro implícito pasa a contener todos sus individuos y se crea el arbol con todos los individuos.
  */
  void inicializar_conjunt(int n);

  /** @brief Crea, modifica y escribe el subarbol resultado en inorden del rasgo

      \pre Conj_Individuos está inicializada y llena, t no vacio
      \post Se ha escrito todo el subarbol resultado en inorden del rasgo si t existe, si no error
  */
  void escribir_inorden(const string &t) const;

  /** @brief Consulta si un individuo tiene rasgo t,si no lo tenia lo añade

      \pre Conj_Individuos está inicializada y llena, string t llena, id valido, 1 <= id <= n, id valida, existe individuo id
      \post Devuelve true si tenia el rasgo, false si no lo estaba y entonces se añade el rasgo al individuo id
  */
  bool consultar_individuo_tiene_rasgo(int id,const string &t) ;

  //Consultoras

  /** @brief Devuelve el par de cromosomas de un individuo (id) del conjunto de individuos

      \pre Conj_Individuos está inicializada y llena, 1 <= id <= n llena con su correspondiente par_cromosomas lleno, id valido, existe individuo id
      \post Devuelve el par de cromosomas del individuo id del conjunto de individuos
  */
  Par_Cromosomas consultar_individuo_par_cromosomas(int id) const;

  // Escrituras

  /** @brief Escribe la información del individuo(id) del conjunto de individuos

      \pre Conj_Individuos está inicializada y llena,  1 <= id <= n, id valido, existe individuo id
      \post Se ha escrito en el canal estandard de salida toda la información del individuo id del conjunto de individuos; el par de cromosmas y los rasgos que tiene
  */
  void escribir_informacio_id(int id) const;

private:

  /** @brief Vector de individuos

      Tenemos un vector con todos los individuos del experimento, estos individuos estan guardados en el vector segun su identificador
  */
  vector<Individuo> indis;

  /** @brief Arbol de individuos

      Tenemos un arbol genealogico de los identificadores de los inidividuos
  */
  BinTree<int> arbol;

  // Modificadora

  /** @brief Modifica el arbol en inorden del rasgo
      \pre
      \post Se ha modificado todo un subarbol en inorden del rasgo t
  */
  void distribuidora(const BinTree<int> &arbol,BinTree<int> &dis, const string &t) const;

  // Lectura

  /** @brief Lee el subarbol en preorden
      \pre Arbol vacio y no se tiene en cuenta la marca 0
      \post Se ha leido todo el subarbol en preorden
  */
  static void llegir_arbre(BinTree <int> &a);

  // Escritura

  /** @brief Escribe el subarbol resultado en inorden del rasgo
      \pre Conj_Individuos está inicializada y llena, t no vacio
      \post Se ha escrito todo el subarbol resultado en inorden del rasgo
  */
  static void escriure_arbre_rec(const BinTree <int> a) ;
};
#endif
