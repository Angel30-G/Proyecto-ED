#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <windows.h>
#include <sstream>
#include "DLinkedList.h"
#include "Trie.h"

using namespace std;

void menu();
void lectura();
void separador(DLinkedList<string> *lista);

Trie t;

int main(){
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);


//    cout<<"****************************************************************************************"<<endl;
//    cout<<"  Bienvenido al programa de indización de texto con Tries."<<endl;
//    cout<<" ¡Este programa analiza archivos de texto para obtener información relevante para ti!"<<endl;
//    cout<<"****************************************************************************************"<<endl;
    lectura(); cout<<endl;
    //menu();


    return 0;
}
void menu(){
    cout<<"****************************************************************************************"<<endl;
    cout<<"  Menú: "<<endl; cout<<endl;
    cout<<" 1. Consulta por prefijo. \n 2. Buscar palabra.\n 3. Buscar por cantidad de letras. \n 4. Palabras más utilizadas. \n 5. Volver al inicio. \n 6.Salir."<<endl;
    int opcion;
    cout<<endl; cout<<"Elige una opción: "; cin>>opcion;
    if(opcion==1){

    }
    else if(opcion==2){

    }
    else if(opcion==3){

    }
    else if(opcion==4){
            int opcion2;
            cout<<" 1.Agregar palabra a ignorar. \n 2.Borrar palabra a ignorar.\n 3.Ver top.\n 4.Regresar."<<endl; cout<<"Elige una opción: "; cout<<endl;
            cin>>opcion2;
            if(opcion2==1){

            }
            else if(opcion2==2){

            }
            else if(opcion2==3){

            }
            else if(opcion2==4){
                    menu();
            }
            else{
                cout<<"Opción incorrecta."<<endl; menu();
            }

    }
    else if(opcion==5){

    }
    else if(opcion==6){
        exit(1);
    }
    else{
        cout<<"Opción incorrecta. Por favor ingrese una opción válida."<<endl; cout<<endl;
        menu();
    }

}

void lectura(){
            ifstream archivo; //para lectura
            string arch;
            cout<<"Ingrese el nombre del archivo que desea abrir: "; cin>>arch;
            string texto;
            DLinkedList<string> *lista=new DLinkedList<string>();

            archivo.open(arch,ios::in); //abriendo archivo modo lectura
            if(archivo.fail()){
                cout<<"No se pudo abrir el archivo."<<endl;
                exit(1);
            }
            while(!archivo.eof()){//mientras no sea el final del archivo
                    getline(archivo, texto);// Se copia lo del archivo
                    lista->insert(texto);
            }
            //lista->print();
            //cout<<"Archivo leído con exito."<<endl;
            //delete lista;
            archivo.close();
            separador(lista);
}

void separador(DLinkedList<string> *lista){
    DLinkedList<string> *palabras=new DLinkedList<string>();
    string palabra;
    for(lista->goToStart(); !lista->atEnd(); lista->next()){
        stringstream input_stringstream(lista->getElement());
        while (getline(input_stringstream, palabra, ' ')){
            stringstream input_stringstream(palabra);
            while (getline(input_stringstream, palabra, ',')){
                stringstream input_stringstream(palabra);
                while (getline(input_stringstream, palabra, ';')){
                    stringstream input_stringstream(palabra);
                    while (getline(input_stringstream, palabra, '.')){
                        stringstream input_stringstream(palabra);
                        while (getline(input_stringstream, palabra, '-')){
                            stringstream input_stringstream(palabra);
                            while (getline(input_stringstream, palabra, ':')){
                                stringstream input_stringstream(palabra);
                                while (getline(input_stringstream, palabra, '(')){
                                    stringstream input_stringstream(palabra);
                                    while (getline(input_stringstream, palabra, ')')){
                                        stringstream input_stringstream(palabra);
                                        while (getline(input_stringstream, palabra, '{')){
                                            stringstream input_stringstream(palabra);
                                            while (getline(input_stringstream, palabra, '}')){
                                                stringstream input_stringstream(palabra);
                                                while (getline(input_stringstream, palabra, '[')){
                                                    stringstream input_stringstream(palabra);
                                                    while (getline(input_stringstream, palabra, ']')){
                                                        stringstream input_stringstream(palabra);
                                                        while (getline(input_stringstream, palabra, '|')){
                                                            stringstream input_stringstream(palabra);
                                                            while (getline(input_stringstream, palabra, '/')){
                                                                stringstream input_stringstream(palabra);
                                                                while (getline(input_stringstream, palabra, '_')){
                                                                    if (!t.containsWord(palabra)){
                                                                        cout<<palabra<<endl;
                                                                        palabras->insert(palabra);
                                                                        t.insert(palabra);}
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

