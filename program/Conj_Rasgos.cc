
#include <iostream>
#include <vector>
#include <string>
#include "Conj_Rasgos.hh"

using namespace std;

Conj_Rasgos::Conj_Rasgos(){
}

bool Conj_Rasgos::anadir_rasgo(int id, const string &t, Conj_Individuos& cindi){
    if(cindi.consultar_individuo_tiene_rasgo(id,t)) return true;
    else{
        map<string,Rasgo>::iterator it;
        it = mrasgos.find(t);
        if (it == mrasgos.end()) {
            Rasgo nuevo;
            Par_Cromosomas p = cindi.consultar_individuo_par_cromosomas(id);
            nuevo.inicializar_parcrom(p,id);
            mrasgos.insert(it, make_pair(t,nuevo));
        }
        else{
            (*it).second.actualizar(id, cindi);
        }
        return false;
    }
}

bool Conj_Rasgos::treure_rasgo(int id, const string &t, Conj_Individuos & cindi){
    map<string,Rasgo>::iterator it;
    it = mrasgos.find(t);
    if(it==mrasgos.end()) return false;
    else{
        bool esborrat = false;
        int size = (*it).second.consultar_set(id);
        if(size == 0) return false;
        else{
            cindi.treure_rasgo_individuo(t,id);
            if((*it).second.tamany()==0){
                mrasgos.erase(it);
                esborrat = true;
            }
        }
        if (not esborrat) {
            (*it).second.recalcular(cindi);
        }
        return true;
    }
}

void Conj_Rasgos::inicializar_conj_rasgos(){
    mrasgos.clear();
}

bool Conj_Rasgos::existe(const string &t,Conj_Individuos & cindi) const{
    map<string,Rasgo>::const_iterator it;
    it = mrasgos.find(t);
    if (it == mrasgos.end()) return false;
    else{
        cindi.escribir_inorden(t);
        return true;
    }
}

bool Conj_Rasgos::escribir_rasgo(const string &t) const{
    map<string,Rasgo>::const_iterator it;
    it = mrasgos.find(t);
    if (it == mrasgos.end()) return false;
    else{
        cout << "  " << t << endl;
        (*it).second.escribir();
        return true;
    }
}
