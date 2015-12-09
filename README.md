README
======
Basado en el capítulo 2 del libro de Charles Fischer, “Crafting a Compiler with C” (1991).

El lenguaje Micro, es un lenguaje muy simple diseñado específicamente, para poseer un LP concreto sobre el que se pueda analizar la construcción de un compilador básico.

DESCRIPCIÓN INFORMAL DEL LENGUAJE:
-----------------
- El único tipo de dato es entero. 
- Todos los identificadores son declarados implícitamente y con una longitud máxima de 32 caracteres. 
- Los identificadores deben comenzar con una letra y están compuestos de letras y dígitos. 
- Las constantes son secuencias de dígitos. 
- Hay dos tipos de sentencias: 
  
  1) Asignación.
  
  ```
    ID := Expresión;
  ```
  
  "Expresión es infija y se construye con identificadores, constantes y los operadores + y –; los paréntesis están permitidos."

  2) Entrada/Salida.
  
  ```
    leer (lista de IDs);
  
    escribir (lista de Expresiones);
  ```
- Cada sentencia termina con un "punto y coma" (;). El cuerpo de un programa está delimitado por inicio y fin. 
- inicio, fin, leer y escribir son palabras reservadas y deben escribirse en minúscula.


Gramática Léxica:
-----------------
```
<token> -> uno de <identificador> <constante> <palabraReservada>

<operadorAditivo> <asignación> <carácterPuntuación>

<identificador> -> <letra> {<letra o dígito>}

<constante> -> <dígito> {<dígito>}

<letra o dígito> -> uno de <letra> <dígito>

<letra> -> una de a-z A-Z

<dígito> -> uno de 0-9

<palabraReservada> -> una de inicio fin leer escribir

<operadorAditivo> -> uno de + -

<asignación> -> :=

<carácterPuntuación> -> uno de ( ) , ;
```

Gramática Sintáctica:
-----------------
```
<programa> -> inicio <listaSentencias> fin

<listaSentencias> -> <sentencia> {<sentencia>}

<sentencia> -> <identificador> := <expresión> ; | 
              leer ( <listaIdentificadores> ) ; |
              escribir ( <listaExpresiones> ) ;

<listaIdentificadores> -> <identificador> {, <identificador>}

<listaExpresiones> -> <expresión> {, <expresión>}

<expresión> -> <primaria> {<operadorAditivo> <primaria>}

<primaria> -> <identificador> | <constante> | (<expresión>)
```

Gramática Sintáctica (Ampliada con símbolos de acción):
-----------------
```
<objetivo> -> <programa> FDT #terminar

<programa> -> #comenzar inicio <listaSentencias> fin

<listaSentencias> -> <sentencia> {<sentencia>}

<sentencia> -> <identificador> := <expresión> #asignar ; |
              leer ( <listaIdentificadores> ); |
              escribir ( <listaExpresiones> );

<listaIdentificadores> -> <identificador> #leer_id {, <identificador> #leer_id}

<listaExpresiones> -> <expresión> #escribir_exp {, <expresión> #escribir_exp}

<expresión> -> <primaria> {<operadorAditivo> <primaria> #gen_infijo}

<primaria> -> <identificador> |
              CONSTANTE #procesar_cte |
              ( <expresión> )

<operadorAditivo> -> SUMA #procesar_op | RESTA #procesar_op

<identificador> -> ID #procesar_id
```
