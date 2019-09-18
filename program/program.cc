/**
    *@mainpage

En este archivo se construye un programa modular que ofrece un menú de opciones para gestionar un laboratorio. Se introducen las clases <em>Conj_Individuos</em>, <em>Conj_Rasgos</em>, <em>Individuo</em>, <em>Rasgo</em> y <em>Par_Cromosomas</em>.


*/

/** @file program.cc
    @brief Programa principal para el ejercicio <em>Aplicació per a un laboratori de biologia</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.

#include "Conj_Individuos.hh"
#include "Conj_Rasgos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
using namespace std;
#endif

int main ()
{
    Conj_Individuos cindi;
    Conj_Rasgos crasgos;
    string opcion;
    cin >> opcion;
    while(opcion!="fi"){
        if(opcion == "experiment"){
            int n, m; // n = nombre individus i m = nombre gens
            cin >> n >> m;
            cout << "experiment " << n << ' ' << m << endl;
            cindi.inicializar_conjunt(n);
            crasgos.inicializar_conj_rasgos();
        }
        else if(opcion == "afegir"){
            string t; // t = tret = rasgo
            int id; // 1 <= id <= n
            cin >> t >> id;
            cout << "afegir " << t << ' ' << id << endl;
            bool saber_esta_rasgo = crasgos.anadir_rasgo(id,t,cindi);
            if(saber_esta_rasgo) cout << "  error" << endl;
        }

        else if( opcion == "treure"){
            string t; // t = tret = rasgo
            int id; // 1 <= id <= n
            cin >> t >> id;
            cout << "treure " << t << ' ' << id << endl;
            bool saber_esta_rasgo = crasgos.treure_rasgo(id,t,cindi);
            if(not saber_esta_rasgo) cout << "  error" << endl;
        }

        else if( opcion == "consulta_tret"){
            string t; // t = tret = rasgo
            cin >> t;
            cout <<"consulta_tret " << t << endl;
            bool saber_esta_tret = crasgos.escribir_rasgo(t);
            if(not saber_esta_tret) cout << "  error" << endl;
        }

        else if( opcion == "consulta_individu"){
            int id; // 1 <= id <= n
            cin >> id;
            cout << "consulta_individu " << id << endl;
            cindi.escribir_informacio_id(id);
        }

        else if( opcion == "distribucio_tret"){
            string t; // t = tret = rasgo
            cin >> t;
            cout << "distribucio_tret " << t << endl;
            bool saber_existir_rasgo = crasgos.existe(t, cindi);
            if(not saber_existir_rasgo) cout << "  error" << endl;
        }
        cin >> opcion;
    }
    cout << "fi" << endl;
}
