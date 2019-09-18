
#include <iostream>
#include <vector>
#include <string>
#include "Individuo.hh"


using namespace std;

Individuo::Individuo(){
}

void Individuo::anadir_rasgo(const string &t){
    ind_rasgos.insert(t);
}

void Individuo::treure_rasgo(const string &t){
    set<string>::iterator it=ind_rasgos.find(t);
    ind_rasgos.erase(it);
}

bool Individuo::tiene_rasgo_ponerlo(const string &t){
    bool estaba = false;
    set<string>::iterator it=ind_rasgos.lower_bound(t);
    if(it != ind_rasgos.end() and *it == t) estaba = true;
    else{
        ind_rasgos.insert(it, t);
    }
    return estaba;
}

Par_Cromosomas Individuo::consulta_par_cromosomas() const{
    return crom;
}

bool Individuo::tiene_rasgo(const string &t) const{
    set<string>::const_iterator it=ind_rasgos.find(t);
    return (it!=ind_rasgos.end());
}

void Individuo::leer(){
    crom.leer();
}

void Individuo::escribir() const{
    crom.escribir();
    set<string>::const_iterator it = ind_rasgos.begin();
    while(it!=ind_rasgos.end()){
        cout << "  " << *it << endl;
        ++it;
    }
}
