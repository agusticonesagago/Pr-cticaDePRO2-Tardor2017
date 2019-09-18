
#include <iostream>
#include <vector>
#include <string>
#include "Par_Cromosomas.hh"


using namespace std;

Par_Cromosomas::Par_Cromosomas(){
}

void Par_Cromosomas::fusion(const Par_Cromosomas &nou){
    int t = (cromosoma.length())/2;
    for(int i = 0; i < t;++i){
        if((nou.consultar_posicio(i)==cromosoma[i]) and (nou.consultar_posicio(i+t)==cromosoma[i+t])){
            cromosoma[i]=nou.consultar_posicio(i);
            cromosoma[i+t]=nou.consultar_posicio(i+t);
        }
        else{
            cromosoma[i]='-';
            cromosoma[i+t]='-';
        }
    }
}

char Par_Cromosomas::consultar_posicio(int i) const{
     return cromosoma[i];
}

void Par_Cromosomas::leer(){
    cin >> cromosoma;
}

void Par_Cromosomas::escribir() const{
    int tamano = cromosoma.length();
    cout << "  ";
    for(int i= 0; i < tamano/2;++i){
        cout << cromosoma[i];
    }
    cout << endl << "  ";
    for(int i = tamano/2; i<tamano;++i){
        cout << cromosoma[i];
    }
    cout << endl;
}
