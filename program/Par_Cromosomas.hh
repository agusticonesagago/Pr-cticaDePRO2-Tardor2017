/** @file Par_Cromosomas.hh
    @brief Especificación de la clase Par de Cromosomas
*/

#ifndef _PAR_CROMOSOMAS_HH_
#define _PAR_CROMOSOMAS_HH_

#ifndef NO_DIAGRAM // // esto hace que el Doxyfile de la sesión no incluya estas clases en los diagramas modulares, mientras que el compilador de c++ sí que las procesa correctamente
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#endif


/** @class Par_Cromosomas
    @brief Representa un par de cromosomas

    Contiene un par de cromosomas.
*/
class Par_Cromosomas
{
public:
  //Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un par de cromosomas.
      \pre <em>cierto</em>
      \post El resultado es un par de cromosomas vacio
  */
  Par_Cromosomas();

  //Modificadoras

  /** @brief Operación de fusión

      \pre Par_Cromosomas nou lleno
      \post Hace una fusion del par de cromosomas que tenia con el nuevo para saber cuales siguen cada rasgo y guarda el resultado en el parametro implicito
  */
   void fusion(const Par_Cromosomas &nou);

  //Consultoras

  /** @brief Te devuelve el caracter de la posicion i del string(cromosoma)

      \pre i no vacio, i valido (0<=i<=cromosoma.length()-1)
      \post El resultado es el caracter de la posicion buscada
  */
  char consultar_posicio(int i) const;

  //Lecturas

  /** @brief Rellena el par de cromosomas con toda su información

      \pre El canal de entrada te entra un string que es el par de cromosomas
      \post El parámetro implícito pasa a contener su informacion
  */
  void leer();

  // Escrituras

  /** @brief Operación de escritura de un par de cromosomas

      \pre <em>cierto</em>
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida
  */
  void escribir() const;

private:

  /** @brief Un par de cromosomas

      Representa un par de cromosomas, hecho de 1 y 0.
  */
  string cromosoma;
};
#endif
