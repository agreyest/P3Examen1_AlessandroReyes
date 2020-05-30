#ifndef TAREA_H
#define TAREA_H
#include <iostream>
#include <string>
using namespace std;

class Tarea
{
	public:
		Tarea();
		Tarea(string, int, int);
		
		void setNivel(int);
    	int getNivel();
    	
    	void setCarga(int);
    	int getCarga();
    	
    	void setDescripcion(string);
    	string getDescripcion();
		
		~Tarea();
	protected:
		
		int Nivel;//1 == bajo, 3==alto, 2 == medio
		int Carga;
		string Descripcion;
};

#endif
