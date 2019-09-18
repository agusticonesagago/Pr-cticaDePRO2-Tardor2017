
#include <iostream>
#include <vector>
#include <string>
#include "Conj_Individuos.hh"
#include "BinTree.hh"

using namespace std;

Conj_Individuos::Conj_Individuos(){
}

void Conj_Individuos::anadir_rasgo_individuo(const string &t, int id){
    indis[id-1].anadir_rasgo(t);
}

void Conj_Individuos::treure_rasgo_individuo(const string &t, int id){
    indis[id-1].treure_rasgo(t);
}

void Conj_Individuos::inicializar_conjunt(int n){
    indis = vector<Individuo> (n);
    llegir_arbre(arbol);
    for(int i = 0; i < indis.size(); ++i){
        indis[i].leer();
    }
}

void Conj_Individuos::escribir_inorden(const string &t) const{
    BinTree<int> dis;
    distribuidora(arbol, dis,t);
    cout << " ";
    escriure_arbre_rec(dis);
    cout << endl;
}

bool Conj_Individuos::consultar_individuo_tiene_rasgo(int id,const string &t) {
    return indis[id-1].tiene_rasgo_ponerlo(t);
}

Par_Cromosomas Conj_Individuos::consultar_individuo_par_cromosomas(int id) const{
    return indis[id-1].consulta_par_cromosomas();
}

void Conj_Individuos::escribir_informacio_id(int id) const{
    indis[id-1].escribir();
}

void Conj_Individuos::distribuidora(const BinTree<int> &arbol,BinTree<int> &dis, const string &t) const{
        BinTree<int> esq, dret;
        esq = arbol.left();
        dret = arbol.right();
        if(esq.empty() and dret.empty()){
            if(indis[arbol.value()-1].tiene_rasgo(t)) {
                 BinTree<int> esq_buit, dret_buit;
                 dis=BinTree<int>(arbol.value(),esq_buit,dret_buit);
             }
         }
         else {
             bool esta, esta_esq, esta_dre;
             BinTree<int> dis_esq, dis_dre;
             distribuidora(esq, dis_esq, t);
             distribuidora(dret,dis_dre, t);
             esta_esq = not dis_esq.empty();
             esta_dre = not dis_dre.empty();
             esta = indis[arbol.value()-1].tiene_rasgo(t);
             if(esta and (esta_esq or esta_dre)){
                 dis = BinTree<int>(arbol.value(),dis_esq,dis_dre);
             }
             else if (not esta and (esta_esq or esta_dre)) {
                 dis = BinTree<int>(arbol.value()*-1,dis_esq,dis_dre);
             }
             else if (esta and not esta_esq and not esta_dre) {
                 BinTree<int> esq_buit, dret_buit;
                 dis=BinTree<int>(arbol.value(),esq_buit,dret_buit);
             }
         }
}

void Conj_Individuos::llegir_arbre(BinTree <int> &a){
    int x;
    cin >> x;
    if( x != 0){
            BinTree <int> e,d;
            llegir_arbre(e);
            llegir_arbre(d);
            a = BinTree <int> (x,e,d);
    }
}

void Conj_Individuos::escriure_arbre_rec(const BinTree <int> a) {
    if(not a.empty()){
        int x = a.value();
        escriure_arbre_rec(a.left());
        cout << " " << x;
        escriure_arbre_rec(a.right());
    }
}
