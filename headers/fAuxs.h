#ifndef FAUXS_H_
#define FAUXS_H_
	
	#include "micro.h"

	void Match(TOKEN t);
	TOKEN ProximoToken();
	void ErrorLexico();
	void ErrorSintactico();
	void Generar(char * co, char * a, char * b, char * c);
	char * Extraer(REG_EXPRESION * preg);
	int Buscar(char * id, TOKEN * t);
	void Colocar(char * id);
	void Chequear(char * s);
	void Comenzar(void);
	void Terminar(void);
	void Asignar(REG_EXPRESION izq, REG_EXPRESION der);


#endif