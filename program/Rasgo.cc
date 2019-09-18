
#include "Rasgo.hh"

using namespace std;

Rasgo::Rasgo(){
}


void Rasgo::inicializar_parcrom(Par_Cromosomas &p, int id){
    pc = p;
    rasg_indis.insert(id);
}

void Rasgo::actualizar(int id, Conj_Individuos& cindi) {
    rasg_indis.insert(id);
    Par_Cromosomas nou = cindi.consultar_individuo_par_cromosomas(id);
    pc.fusion(nou);
}

void Rasgo::recalcular(Conj_Individuos& cindi){
    set<int>::iterator it = rasg_indis.begin();
    pc = cindi.consultar_individuo_par_cromosomas(*it);
    ++it;
    while(it!=rasg_indis.end()){
        Par_Cromosomas nou = cindi.consultar_individuo_par_cromosomas(*it);
        pc.fusion(nou);
        ++it;
    }
}

int Rasgo::consultar_set(int id) {
     return rasg_indis.erase(id);
}

int Rasgo::tamany() const{
     return rasg_indis.size();
}

void Rasgo::escribir() const{
    pc.escribir();
    set<int>:: const_iterator it=rasg_indis.begin();
    while(it!=rasg_indis.end()){
        cout << "  " << *it << endl;
        ++it;
    }
}
