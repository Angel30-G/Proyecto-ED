#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <windows.h>
#include <sstream>
#include <cctype>

#include "BSTreeDictionary.h"
#include "DLinkedList.h"
#include "Trie.h"

using namespace std;

void menu();
void lectura();
void separador(DLinkedList<string> *lista);
void consultarPrefijo();

Trie t;

int main(){
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);


//    cout<<"****************************************************************************************"<<endl;
//    cout<<"  Bienvenido al programa de indizaciÃ³n de texto con Tries."<<endl;
//    cout<<" ¡Este programa analiza archivos de texto para obtener informaciÃ³n relevante para ti!"<<endl;
//    cout<<"****************************************************************************************"<<endl;
    lectura(); cout<<endl;
    consultarPrefijo();
    //menu();


    return 0;
}
void menu(){
    cout<<"****************************************************************************************"<<endl;
    cout<<"  Menú: "<<endl; cout<<endl;
    cout<<" 1. Consulta por prefijo. \n 2. Buscar palabra.\n 3. Buscar por cantidad de letras. \n 4. Palabras mÃ¡s utilizadas. \n 5. Volver al inicio. \n 6.Salir."<<endl;
    int opcion;
    cout<<endl; cout<<"Elige una opciÃ³n: "; cin>>opcion;
    if(opcion==1){
        consultarPrefijo();
    }
    else if(opcion==2){

    }
    else if(opcion==3){

    }
    else if(opcion==4){
            int opcion2;
            cout<<" 1.Agregar palabra a ignorar. \n 2.Borrar palabra a ignorar.\n 3.Ver top.\n 4.Regresar."<<endl; cout<<"Elige una opciÃ³n: "; cout<<endl;
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
                cout<<"OpciÃ³n incorrecta."<<endl; menu();
            }

    }
    else if(opcion==5){

    }
    else if(opcion==6){
        exit(1);
    }
    else{
        cout<<"OpciÃ³n incorrecta. Por favor ingrese una opciÃ³n vÃ¡lida."<<endl; cout<<endl;
        menu();
    }

}

void lectura(){
            ifstream archivo; //para lectura
            string arch;
            cout<<"Ingrese el nombre del archivo que desea abrir: "; cin>>arch;
            string texto;
            DLinkedList<string> *lista=new DLinkedList<string>();
            Dictionary<int, string> *linea = new BSTreeDictionary<int, string>();

            archivo.open(arch,ios::in); //abriendo archivo modo lectura
            if(archivo.fail()){
                cout<<"No se pudo abrir el archivo."<<endl;
                exit(1);
            }
            while(!archivo.eof()){//mientras no sea el final del archivo
                    getline(archivo, texto);// Se copia lo del archivo
                    for(int i=0; i<texto.size();i++){
                        texto[i]=tolower(texto[i]);

                   /* linea->insert(line, texto);
                    cout<<line<<" "<<texto<<endl;
                    getline(archivo, texto);// Se copia lo del archivo
                    lista->insert(texto);
                    line++; */

                    }
                    lista->insert(texto);
            }
            //lista->print();
            archivo.close();
            separador(lista);
}

void separador(DLinkedList<string> *lista){
    DLinkedList<string> *palabras=new DLinkedList<string>();
    //Dictionary<int, string> *linea = new BSTreeDictionary<int, string>();
    string palabra;
    //int lineas;
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
                                                                while (getline(input_stringstream, palabra, '¡')){
                                                                    stringstream input_stringstream(palabra);
                                                                    while (getline(input_stringstream, palabra, '!')){
                                                                       stringstream input_stringstream(palabra);
                                                                      while (getline(input_stringstream, palabra, '¿')){
                                                                        stringstream input_stringstream(palabra);
                                                                        while (getline(input_stringstream, palabra, '?')){
                                                                          stringstream input_stringstream(palabra);
                                                                while (getline(input_stringstream, palabra, '_')){
                                                                        //linea->insert(lineas, palabra);
                                                                        //lineas++;
                                                                        cout<<palabra<<endl;

                                                                       /* linea->getKeys();
                                                                        linea->getValues();
                                                                        palabras->insert(palabra);
                                                                        List<int> *Keys = linea->getKeys();
                                                                        Keys->print();
                                                                        delete Keys;
                                                                        List<string> *Values = linea->getValues();
                                                                        Values->print();
                                                                        delete Values;*/

                                                                        t.insert(palabra);
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
    }
   }
  }
}


void consultarPrefijo(){
    string prefijo;
    cout<<"Ingrese el prefijo que desea consultar: "; cin>>prefijo;
    List<string> *resultados =t.getMatches(prefijo);
    cout<<"Palabras con ese prefijo: "; resultados->print();
    int cantidad=1;
    for(resultados->goToStart(); !resultados->atEnd(); resultados->next()){

    }
}

