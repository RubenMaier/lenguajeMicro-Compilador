#ifndef MICRO_H_
#define MICRO_H_
	
	#define FilasTS 15
	#define ColumnasTS 13
	#define TamanioNombreLexema 32+1

	typedef enum
	{
	    INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENIZQUIERDO, PARENDERECHO, PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT, ERRORLEXICO
	} TOKEN;

	typedef struct
	{
	    char identificadorDeLexema[TamanioNombreLexema];
	    TOKEN t;
	} RegTS;


	typedef struct
	{
	    TOKEN clase;
	    char nombre[TamanioNombreLexema];
	    int valor;
	} REG_EXPRESION;

#endif