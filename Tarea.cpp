#include "Tarea.h"
#include <iostream>
#include <string>
using namespace std;

Tarea::Tarea(){
	
}
Tarea::Tarea(string descripcion, int nivel, int carga){
	this->Descripcion = descripcion;
	this->Nivel = nivel;
	this->Carga = carga;
}


void Tarea::setNivel(int nivel){
	this->Nivel = nivel;
}
int Tarea::getNivel(){
	return this->Nivel;
}
    	
void Tarea::setCarga(int Carga){
	this->Carga = Carga;
}
int Tarea::getCarga(){
	return this->Carga;
}
    	
void Tarea::setDescripcion(string Descripcion){
	this->Descripcion = Descripcion;
}
string Tarea::getDescripcion(){
	return this->Descripcion;
}


Tarea::~Tarea(){
	
}
