#include <iostream>
#include "Cine.h"

using namespace std;

class Serie : public Cine{
    private:
        string titEpis;
        int temporada;

    public:
        Serie();
        Serie(int, string, int, string, int, string, int);
        void mostrar();
}; 

Serie::Serie(){

}

Serie::Serie(int _id, string _nombre, int _duracion, string _genero, int _calificacion, string _titEpis, int _temporada):Cine(_id,_nombre,_duracion,_genero, _calificacion){
    titEpis = _titEpis;
    temporada = _temporada;
}

void Serie::mostrar(){
    cout<<"Es una serie y tiene los siguientes datos:"<<endl;
    Cine::mostrar();
    cout<<"El titulo del episodio es '"<<titEpis<<"' y es la temporada "<<temporada<<endl;
}