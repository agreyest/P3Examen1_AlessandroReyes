#include "Empleado.h"
#include <iostream>
#include <string>
using namespace std;
#define nullptr

Empleado::Empleado(){
	
}
Empleado::Empleado(string nombre, int edad, int nivel, int pereza, int habilidad){
	this->Nombre = nombre;
	this->Edad = edad;
	this->Nivel = nivel;
	this->Pereza = pereza;
	this->Habilidad = habilidad;
	this->tarea = NULL;
}


void Empleado::setEdad(int edad){
	this->Edad = edad;
}
int Empleado::getEdad(){
	return this->Edad;
}
    	
void Empleado::setNivel(int nivel){
	this->Nivel = nivel;
}
int Empleado::getNivel(){
	return this->Nivel;
}
    	
void Empleado::setHabilidad(int habilidad){
	this->Habilidad = habilidad;
}
int Empleado::getHabilidad(){
	return this->Habilidad;
}
    	
void Empleado::setPereza(int pereza){
	this->Pereza = pereza;
}
int Empleado::getPereza(){
	return this->Pereza;
}

void Empleado::setNombre(string nombre){
	this->Nombre = nombre;
}
string Empleado::getNombre(){
	return this->Nombre;
}

void Empleado::setTarea(Tarea* tarea){
	this->tarea = tarea;
}
Tarea* Empleado::getTarea(){
	return this->tarea;
}


Empleado::~Empleado(){
	
}





