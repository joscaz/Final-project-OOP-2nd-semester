#include <iostream>
#include <stdlib.h>
#include <string>
#pragma once

using namespace std;

class Cine{
    protected:
        int id;
        string nombre;
        int duracion;
        string genero;
        int calificacion;
    public:
        Cine();
        Cine(int, string, int, string, int);
        virtual void mostrar();
};

Cine::Cine(){

}

Cine::Cine(int _id, string _nombre, int _duracion, string _genero, int _calificacion){
    id = _id;
    nombre = _nombre;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}


void Cine::mostrar(){
    cout<<"Tiene un ID "<<id<<", el nombre es "<<nombre<<", dura "<<duracion<<" minutos, el genero es de "<<genero<<" y tiene una calificacion de "<<calificacion<<"."<<endl;
}