#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <string>
using namespace std;
#include "Tarea.h"

class Empleado
{
	public:
		Empleado();
		Empleado(string, int, int, int, int);
		
		void setEdad(int);
    	int getEdad();
    	
    	void setNivel(int);
    	int getNivel();
    	
    	void setHabilidad(int);
    	int getHabilidad();
    	
    	void setPereza(int);
    	int getPereza();
    	
    	void setNombre(string);
    	string getNombre();
    	
    	void setTarea(Tarea*);
    	Tarea* getTarea();
		
		~Empleado();
	protected:
		
		int Edad;
		int Nivel;//1 == bajo, 3==alto, 2 == medio
		int Habilidad;
		string Nombre;
		int Pereza;
		Tarea* tarea;
};

#endif
