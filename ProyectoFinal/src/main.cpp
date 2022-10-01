#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>
#include "Pelicula.h"
#include "Serie.h"

using namespace std;

int main(){
    int opcion, califser_input, califpel_input, califPel;
    string gen_input, ser_input, namePel;

    Cine* arr[8];

    ifstream datos;
    ifstream datos1;
    ifstream datos2;
    ifstream datos3;
    ifstream datos4;
    ofstream resultados;
    string linea, subs, line, lin, linea1;
    int lugar, id_convertido, duracion_convertida, temporada_convertida, numPelicula_convertido, calificacion_convertida, calificacion_nueva;
    string nombre_convertido, genero_convertido,nomEpis_convertido;
    int cont = 0;

    datos.open("datos.txt");
    datos1.open("datos.txt");
    datos2.open("datos.txt");
    datos3.open("datos.txt");
    datos4.open("datos.txt");
    resultados.open("resultados.txt");

    do{
        cout << "1) Mostrar series y peliculas en general con sus calificaciones" << endl;
        cout << "2) Mostrar las peliculas en general con un cierto género" << endl;
        cout << "3) Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
        cout << "4) Mostrar las películas con cierta calificacion" << endl;
        cout << "5) Calificar una pelicula" << endl;
        cout << "0) Salir" << endl;
        cin >> opcion;

        if(opcion==1){ 
            while (getline(datos, linea)){
                
                lugar = linea.find(" ");

                //Para el ID
                subs = linea.substr(0,lugar); 
                linea.erase(0,lugar+1);
                id_convertido = stoi(subs);
                resultados<<id_convertido<<" ";

                //Para el nombre
                lugar = linea.find(" ");
                subs = linea.substr(0,lugar);
                linea.erase(0,lugar+1);
                nombre_convertido = subs;
                resultados<<nombre_convertido<<" ";

                //Para la duracion
                lugar = linea.find(" ");
                subs = linea.substr(0,lugar);
                linea.erase(0,lugar+1);
                duracion_convertida = stoi(subs);
                resultados<<duracion_convertida<<" ";

                //Para el genero
                lugar = linea.find(" ");
                subs = linea.substr(0,lugar);
                linea.erase(0,lugar+1);
                genero_convertido = subs;
                resultados<<genero_convertido<<" ";

                //Para la calificacion
                lugar = linea.find(" ");
                subs = linea.substr(0,lugar);
                linea.erase(0,lugar+1);
                calificacion_convertida = stoi(subs);
                resultados<<calificacion_convertida<<" ";

                if(id_convertido%2 == 0){
                    lugar = linea.find(" ");
                    subs = linea.substr(0,lugar);
                    linea.erase(0,lugar+1);
                    nomEpis_convertido = subs;
                    resultados<<nomEpis_convertido<<" ";

                    //Para la temporada de la serie
                    lugar = linea.find(" ");
                    subs = linea.substr(0,lugar);
                    linea.erase(0,lugar+1);
                    temporada_convertida = stoi(subs);
                    resultados<<temporada_convertida<<endl;
                } else {
                    //Para el numero de la pelicula (Caso Pelicula)
                    lugar = linea.find(" ");
                    subs = linea.substr(0,lugar);
                    linea.erase(0,lugar+1);
                    numPelicula_convertido = stoi(subs);
                    resultados<<numPelicula_convertido<<endl;
                }
                
                if(id_convertido%2 == 0){
                    arr[cont] = new Serie(id_convertido,nombre_convertido,duracion_convertida,genero_convertido, calificacion_convertida,nomEpis_convertido, temporada_convertida);
                    arr[cont] -> mostrar();
                    cout<<endl;
                } else {
                    arr[cont] = new Pelicula(id_convertido, nombre_convertido, duracion_convertida,genero_convertido, calificacion_convertida,numPelicula_convertido);
                    arr[cont] -> mostrar();
                    cout<<endl;
                }
            }
        }else if(opcion == 2){  
            cout<<"Ingresa el genero de pelicula que quieres buscar: "<<endl;
            cin>>gen_input; //genero input
            while (getline(datos1, line)){
                lugar = line.find(" ");

                //Para el ID
                subs = line.substr(0,lugar);
                line.erase(0,lugar+1);
                id_convertido = stoi(subs);

                if(id_convertido%2!=0){
                    //Para el nombre
                    lugar = line.find(" ");
                    subs = line.substr(0,lugar);
                    line.erase(0,lugar+1);
                    nombre_convertido = subs;

                    //Para la duracion
                    lugar = line.find(" ");
                    subs = line.substr(0,lugar);
                    line.erase(0,lugar+1);
                    duracion_convertida = stoi(subs);

                    //Para el genero
                    lugar = line.find(" ");
                    subs = line.substr(0,lugar);
                    if(gen_input==subs){ 
                        line.erase(0,lugar+1);
                        genero_convertido = subs;

                        lugar = line.find(" ");
                        subs = line.substr(0,lugar);
                        line.erase(0,lugar+1);
                        numPelicula_convertido = stoi(subs);
                        cout<<id_convertido<<" "<<nombre_convertido<<" "<<duracion_convertida<<" "<<genero_convertido<<" "<<calificacion_convertida<<" "<<numPelicula_convertido<<endl;
                    }
                }
            }
        } else if(opcion ==3){
            cout<<"Escogiste la opcion 3, mostrar los episodios de una determinada serie con una calificacion determinada"<<endl;
            cout<<"Ingresa el nombre de la serie que quieres buscar: "<<endl;
            cin>>ser_input; //serie input 
            cout<<"¿Cual quieres que sea la calificacion minima para los episodios de "<<ser_input<<"?"<<endl;
            cin>>califser_input;
            while (getline(datos2, lin)){
                lugar = lin.find(" ");

                //Para el ID
                subs = lin.substr(0,lugar);
                lin.erase(0,lugar+1);
                id_convertido = stoi(subs);

                if(id_convertido%2==0){
                    //Para el nombre
                    lugar = lin.find(" ");
                    subs = lin.substr(0,lugar);
                    if(ser_input==subs){ 
                        lin.erase(0,lugar+1);
                        nombre_convertido = subs;

                        //Para la duracion
                        lugar = lin.find(" ");
                        subs = lin.substr(0,lugar);
                        lin.erase(0,lugar+1);
                        duracion_convertida = stoi(subs);

                        //Para el genero
                        lugar = lin.find(" ");
                        subs = lin.substr(0,lugar);
                        lin.erase(0,lugar+1);
                        genero_convertido = subs;

                        lugar = lin.find(" ");
                        subs = lin.substr(0,lugar);
                        lin.erase(0,lugar+1);
                        calificacion_convertida = stoi(subs);

                        if(califser_input >= calificacion_convertida){
                            lugar = lin.find(" ");
                            subs = lin.substr(0,lugar);
                            lin.erase(0,lugar+1);
                            nomEpis_convertido = subs;

                            //Para la temporada de la serie
                            lugar = lin.find(" ");
                            subs = lin.substr(0,lugar);
                            lin.erase(0,lugar+1);
                            temporada_convertida = stoi(subs);
                            //cout<<id_convertido<<" "<<nombre_convertido<<" "<<duracion_convertida<<" "<<genero_convertido<<" "<<calificacion_convertida<<" "<<nomEpis_convertido<<" "<<temporada_convertida<<endl;
                            cout<<"La serie "<<ser_input<<" tiene el episodio "<<nomEpis_convertido<<" con una calificacion de "<<calificacion_convertida<<endl;
                        }
                    }
                }
            }
        } else if(opcion ==4){
            cout<<"Escogiste la opcion 4, Mostrar las películas con cierta calificacion"<<endl;
            cout<<"¿A que calificacion quieres que sean mayores las peliculas?"<<endl;
            cin>>califpel_input;
            while (getline(datos3, linea1)){
                lugar = linea1.find(" ");

                //Para el ID
                subs = linea1.substr(0,lugar);
                linea1.erase(0,lugar+1);
                id_convertido = stoi(subs);

                if(id_convertido%2!=0){
                    //Para el nombre
                    lugar = linea1.find(" ");
                    subs = linea1.substr(0,lugar);
                    linea1.erase(0,lugar+1);
                    nombre_convertido = subs;

                    //Para la duracion
                    lugar = linea1.find(" ");
                    subs = linea1.substr(0,lugar);
                    linea1.erase(0,lugar+1);
                    duracion_convertida = stoi(subs);

                    //Para el genero
                    lugar = linea1.find(" ");
                    subs = linea1.substr(0,lugar);
                    linea1.erase(0,lugar+1);
                    genero_convertido = subs;

                    lugar = linea1.find(" ");
                    subs = linea1.substr(0,lugar);
                    linea1.erase(0,lugar+1);
                    calificacion_convertida = stoi(subs);
                    if(calificacion_convertida >= califpel_input){
                        lugar = linea1.find(" ");
                        subs = linea1.substr(0,lugar);
                        linea1.erase(0,lugar+1);
                        numPelicula_convertido = stoi(subs);
                        //cout<<id_convertido<<" "<<nombre_convertido<<" "<<duracion_convertida<<" "<<genero_convertido<<" "<<calificacion_convertida<<" "<<numPelicula_convertido<<endl;
                        cout<<"La pelicula "<<nombre_convertido<<" tiene una calificacion de "<<calificacion_convertida<<" "<<endl;
                    }
                }
            }            
        } else if(opcion==5){
            cout<<"¿Que pelicula deseas calificar?"<<endl;
            cin>>namePel;
            cout<<"¿Que calificacion le deseas dar?: "<<endl;
            cin>>califPel;
            while (getline(datos4, linea1)){
                lugar = linea1.find(" ");

                //Para el ID

                subs = linea1.substr(0,lugar);
                linea1.erase(0,lugar+1);
                id_convertido = stoi(subs);

                if(id_convertido%2!=0){
                    //Para el nombre
                    lugar = linea1.find(" ");
                    subs = linea1.substr(0,lugar);
                    linea1.erase(0,lugar+1);
                    nombre_convertido = subs;
                    if(nombre_convertido==namePel){
                        //Para la duracion
                        lugar = linea1.find(" ");
                        subs = linea1.substr(0,lugar);
                        linea1.erase(0,lugar+1);
                        duracion_convertida = stoi(subs);

                        //Para el genero
                        lugar = linea1.find(" ");
                        subs = linea1.substr(0,lugar);
                        linea1.erase(0,lugar+1);
                        genero_convertido = subs;

                        //Para la calificacion
                        lugar = linea1.find(" ");
                        subs = linea1.substr(0,lugar);
                        linea1.erase(0,lugar+1);
                        calificacion_convertida = stoi(subs);
                        calificacion_nueva = califPel;

                        //Para el numero de la pelicula
                        lugar = linea1.find(" ");
                        subs = linea1.substr(0,lugar);
                        linea1.erase(0,lugar+1);
                        numPelicula_convertido = stoi(subs);

                        //cout<<id_convertido<<" "<<nombre_convertido<<" "<<duracion_convertida<<" "<<genero_convertido<<" "<<calificacion_convertida<<" "<<numPelicula_convertido<<endl;
                        cout<<"A la pelicula "<<nombre_convertido<<" se le ha cambiado a una calificacion de "<<calificacion_nueva<<" "<<endl;
                    }
                }
            }            
        } else if(opcion == 0){
            cout<<"Hasta pronto"<<endl;
        } else{
            cout<<"Escoge una opcion valida"<<endl;
        }

    }while(opcion!=0);

    datos.close();
    datos1.close();
    datos2.close();
    datos3.close();
    datos4.close();
    resultados.close();

    return 0;
}
