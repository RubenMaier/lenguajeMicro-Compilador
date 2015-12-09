/* -------------------  COMPILADOR DE MICRO  ------------------- */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "headers/micro.h"
#include "headers/parser.h"

/* --------------  Declaramos las variables globales para el compilador =)  -------------- */
	FILE * in;
	FILE * out;
	RegTS TS[1000] = { {"inicio", INICIO}, {"fin", FIN}, {"leer", LEER}, {"escribir", ESCRIBIR}, {"$", 99} };
	char buffer[TamanioNombreLexema];
	TOKEN tokenActual;
	int flagToken = 0;


/* --------------  Creamos el programa comando con validaciones:  -------------- */
int main(int argc, char * argv[])
{
	printf("\033[34m===================================\033[37m\n");
	printf("       COMPILADOR DE MICRO\n");
	printf("\033[34m===================================\033[37m\n");
	int l = strlen(argv[1]);

    /* --------------  Hacemos las validaciones correspondientes:  -------------- */
	    if ( argc == 1 )
	    {
	        printf("Error. Ingresar el nombre del archivo fuente y el nombre del archivo de salida\n");
	        return -1;
	    }
	    if ( argc == 2 )
	    {
	        printf("Error. Falta ingresar el nombre del archivo de salida.\n");
	        return -1;
	    }
	    if ( argv[1][l-1] != 'm' || argv[1][l-2] != '.' )
	    {
	        printf("Error. El archivo fuente debe finalizar con \".m\"\n");
	        return -1;
	    }
	    if ( (in = fopen(argv[1], "r") ) == NULL )
	    {
	        printf("No se pudo abrir archivo fuente\n");
	        return -1;
	    }
		    if ( (out = fopen(argv[2], "w") ) == NULL)
	    {
	        printf("No se pudo abrir archivo de salida\n");
	        return -1;
	    }

    /* --------------  Iniciamos el proceso de compilacion:  -------------- */
    	Objetivo();
    
    /* --------------  Terminado el proceso, cerramos los archivos:  -------------- */
    	fclose(in);
    	fclose(out);

    return 0;
}