#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#include "Empleado.h"
#include "Tarea.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu(){
	int retValue=0;
	while(retValue < 1 || retValue > 7){
		cout<<endl<<endl<<"***--------------------***"<<endl
			<<"  1.- Contratar empleado"<<endl
			<<"  2.- Despedir empleado"<<endl
			<<"  3.- Listar empleados"<<endl
			<<"  4.- Crear tarea"<<endl
			<<"  5.- Listar tareas"<<endl
			<<"  6.- Iniciar proyecto"<<endl
			<<"  7.- Salir"<<endl
			<<"-> Que opcion desea ver: ";
			
			cin>>retValue;
			
			if(retValue >= 1 && retValue <= 7){
				break;
			}else{
				cout<<endl<<"Opcion ingresada incorrecta, elija nuevamente"<<endl;
			}
			
			
	}//end while
	
	return retValue;
}//fin metodo de menu

vector <Empleado*> empleados; 
vector <Tarea*> backlog; 

int main(int argc, char** argv) {
	int  opcion = menu();
	int seguir = 1;
	
	while(seguir == 1){
		switch(opcion){
			case 1:{//contratar empleados
				int edad, nivel, porcen_habilidad, porcen_pereza;//nivel (1 == bajo)(2 == medio)(3 == alto)
				string nombre;
				
				cout<<endl<<"cual es el nombre del empleado: ";
				cin>>nombre;
				cout<<"cual es la edad del empleado: ";
				cin>>edad;
				
				cout<<"Cual es el nivel del empleado(1-3): ";
				cin>>nivel;
				while(nivel < 1 || nivel > 3){
					cout<<"Numero fuera de rango, intente de nuevo; cual es el nivel del empleado(1-3): ";
					cin>>nivel;
				}
				
				cout<<"cual es la porcentaje de habilidad del empleado(1-100): ";
				cin>>porcen_habilidad;
				while(porcen_habilidad < 1 || porcen_habilidad > 100){
					cout<<"Numero fuera de rango, intente de nuevo; cual es la porcentaje de habilidad del empleado(1-100): ";
					cin>>porcen_habilidad;
				}
				
				cout<<"cual es la porcentaje de pereza del empleado(1-100): ";
				cin>>porcen_pereza;
				while(porcen_pereza < 1 || porcen_pereza > 100){
					cout<<"Numero fuera de rango, intente de nuevo; cual es la porcentaje de pereza del empleado(1-100): ";
					cin>>porcen_pereza;
				}
				
				empleados.push_back(new Empleado(nombre, edad, nivel, porcen_pereza, porcen_habilidad));
				break;
			}
			case 2:{//despedir empleados
				int num_despido;
				
				for(int i = 0; i < empleados.size(); i++){
					cout<<endl<<(i+1)<<" "<<empleados[i]->getNombre();
				}
				
				cout<<endl<<"Ingrese el numero del empleado que desea despedir: ";
				cin>> num_despido;
				num_despido--;
				
				while(num_despido < 0 || num_despido >= empleados.size()){
					cout<<"Numero fuera de rango; intentelo de nuevo: ";
					cin>> num_despido;
					num_despido--;
				}
				
				empleados.erase(empleados.begin() + num_despido);
				break;
			}
			case 3:{//listar empleados
				for(int i = 0; i < empleados.size(); i++){
					cout<<endl<<(i+1)<<" "<<empleados[i]->getNombre();
				}
				break;
			}
			case 4:{//crear tareas
				int nivel, carga;//nivel (1 == bajo)(2 == medio)(3 == alto)
				string descripcion;
				
				cout<<endl<<"cual es la descripcion de la tarea: ";
				cin>>descripcion;
				
				cout<<"Cual es el nivel de la tarea(1-3): ";
				cin>>nivel;
				while(nivel < 1 || nivel > 3){
					cout<<"Numero fuera de rango, intente de nuevo; cual es el nivel de la tarea(1-3): ";
					cin>>nivel;
				}
				
				cout<<"Cual es la carga de la tarea: ";
				cin>>carga;
				while(carga < 1){
					cout<<"Numero menor a 1, intente de nuevo; cual es la carga de la tarea: ";
					cin>>carga;
				}
				
				backlog.push_back(new Tarea(descripcion, nivel, carga));
				break;
			}
			case 5:{//listar tareas
				for(int i = 0; i < backlog.size(); i++){
					cout<<endl<<(i+1)<<" "<<backlog[i]->getDescripcion();
				}
				break;
			}
			case 6:{//iniciar proyecto
				int dias_proyecto =0;//contador para ver en que dia va el proyecto
				int suma_cargas=0;//la suma de todas lar gargas
				for(int i = 0; i < backlog.size(); i++){
					suma_cargas =+ backlog[i]->getCarga();
				}
				dias_proyecto = suma_cargas + ( suma_cargas * (0.20) );
				
				//int dias_tarea;
				bool vive_proyecto=true;//para que siga mientras haya tareas en el backlog
				
				while(vive_proyecto){
					cout<<endl<<"****Dias para terminar el proyecto: "<<dias_proyecto<<" ****"<<endl;
					
					int tarea_progress=0;//cuenta las tareas en progreso
					for(int i = 0; i < backlog.size(); i++){//asignar tareas a los empleados
						for(int j = 0; j < empleados.size(); j++){
							if(empleados[j]->getTarea() == NULL){
								if(backlog[i]->getNivel() <= empleados[j]->getNivel() ){
									empleados[j]->setTarea(backlog[i]);
									tarea_progress++;
									break;
								}//fin if 2
							}//fin if1
						}//fin for 2
					}//fin for 1
					
					int pereza_cont=0;//cuenta los empleados que fallaron por pereza
					int fallos_cont=0;//cuenta los empleados que fallaron por habilidad
					int logro_cont=0;//cuenta los empleados que lograron hacer el dia
					int random = 0;
					for(int i = 0; i < empleados.size(); i++){
						if(empleados[i]->getTarea() != NULL){//para solo usar a los que tienen tarea
							random =(rand()%101);
							if(empleados[i]->getPereza() < random){//para chequear la pereza
								random =(rand()%101);
								if(empleados[i]->getHabilidad() > random){//para chequear si tiene la habilidad
									for(int j = 0; j < backlog.size(); j++){//para restarle dias a la tarea
										if(backlog[j]->getDescripcion() == empleados[i]->getTarea()->getDescripcion()){
											backlog[j]->setCarga(backlog[j]->getCarga()-1);
											logro_cont++;
											break;
										}
									}//fin for2
									
								}else{//fin if 3 y else para subir contador de que fallo por habilidad
									fallos_cont++;
								}
								
							}else{//fin if 2 y else para subir contador de que fallo por pereza
								pereza_cont++;
							}
							
						}//fin if1 
					}//fin for1
					
					//submenu
					bool vive_submenu = true;
					int opcion2;
					while(vive_submenu){
						cout<<endl<<"- - - - - - - -"<<endl
						<<"1.- Siguiente dia"<<endl
						<<"2.- Generar reporte"<<endl
						<<"3.- Salir"<<endl
						<<"Elija una opcion: ";
						cin>>opcion2;
						while(opcion2<1 || opcion2>3){
							cout<<endl<<"- - - - - - - -"<<endl
							<<"OPCION FUERA DE RANGO, TRATE DE NUEVO"<<endl
							<<"1.- Siguiente dia"<<endl
							<<"2.- Generar reporte"<<endl
							<<"3.- Salir"<<endl
							<<"Elija una opcion: ";
							cin>>opcion2;
						}//fin while validacion
						
						switch(opcion2){
							case 1:{
								vive_submenu = false;
								break;
							}
							case 2:{
								cout<<endl<<"Tareas en backlog: "<<(backlog.size() - tarea_progress)<<endl
								<<"Tareas en progeso: "<<tarea_progress<<endl
								<<"Empleados perezosos: "<<pereza_cont<<endl
								<<"Empleaodos que fallaron: "<<fallos_cont<<endl 
								<<"Empleados que lograron el dia: "<<logro_cont<<endl;
								break;
							}
							case 3:{
								vive_submenu = false;
								break;
							}
						}//fin switch para submenu
					}//fin del while submenu1
					
					for(int j = 0; j < backlog.size(); j++){//para chequear que tareas ya terminaron
						if(backlog[j]->getCarga() == 0){//if para check 
							for(int i = 0; i < empleados.size(); i++){
								if(backlog[j]->getDescripcion() == empleados[i]->getTarea()->getDescripcion()){
									empleados[i]->setTarea(NULL);
									break;
								}
							}//fin for 2
							backlog.erase(backlog.begin() + j);
						}
					}//fin for 1
					
					dias_proyecto--;
					if(backlog.size() < 1){
						vive_proyecto = false;
						cout<<"Fin del proyecto con "<<dias_proyecto<< " dias faltantes.";
					}
				}//fin while del proyecto
				break;
			}
			case 7:{//salir
				seguir = 0;
				break;
			}
		}//fin del switch
		if(seguir == 1){
			opcion = menu();
		}
	}//fin del while
		
	return 0;
}//fin del main






