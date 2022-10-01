#include <iostream>
#include "Cine.h"

using namespace std;

class Pelicula : public Cine{
    private:
        int numPelicula;
    public:
        Pelicula();
        Pelicula(int, string, int, string, int, int);
        void mostrar();
};

Pelicula::Pelicula(){

}

Pelicula::Pelicula(int _id, string _nombre, int _duracion, string _genero, int _calificacion, int _numPelicula):Cine(_id,_nombre,_duracion,_genero, _calificacion){
    numPelicula = _numPelicula;
}

void Pelicula::mostrar(){
    cout<<"Es una pelicula y tiene los siguientes datos:"<<endl;
    Cine::mostrar();
    cout<<"Es la pelicula numero "<<numPelicula<<" de su saga."<<endl;
}