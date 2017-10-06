/*
Instituto Politécnico Nacional
Unidad Profesional Interdisciplinaria en Ingeniería y Tecnologías Avanzadas
Ingeniería Mecatrónica
Introducción a la programación
Prof: Lamberto Maza Casas
1MV2
Gaitán Villegas Rodrigo Alejandro
Semestre 2017-18/A
Programa que recibe un entero de la forma 0x0000MNRS y devuelve un entero de la forma 0x0000RSMN
Lo imprime como un arreglo de caracteres formando una palabra e imprime las direcciones de cada caracter
*/

#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"  //Inclusión de librería creada con la funcion que intercambia los bits alto y bajo de los bytes alto y bajo

int intA,intBH,intBL,intByteH,intByteL,tmp,var,WordComplete, i;	//Declaración de variables

int main(int argc, char *argv[])
	{
	printf("Para un int se usan %i bytes\n",sizeof(int)); //Sizeof para saber numero de bytes que usa cierto tipo de dato para su almacenamiento
	printf("%c\t%i\t0x%x\n\n",0x48,0x48,0x48);/* imprime la letra H, el número decimal de la letra H y el número hexadecimal de la letraH */
	union {		//En una union se pueden almacenar distintas variables de distintos tipos de dato en una sola localidad de memoria
		int saludo;
		char c[4];
	} ache,*p;
	/*
	H 0x48, O 0x4f, L 0x4c, A  0x41, \0  0x00
	0x4f4c4100--->0x41004f4c--->0x00414c4f
	saludo=0x00414c4f
	*/
	intA=0x4f4c4100; 
	printf("intA=0x%x\n",intA);
	intBL=0x0000ffff&intA;
	intBH=0x0000ffff&(intA>>16);
	printf("intBH=0x%x\tintBL=0x%x\n",intBH,intBL);
	intBH=funciondenteros(intBH);
	intBL=funciondenteros(intBL);
	printf("intBH=0x%x\tintBL=0x%x\n",intBH,intBL);
	WordComplete=intBH|((intBL<<16)&0xffff0000);
	printf("WordComplete=0x%x\n",WordComplete);
	p=&ache;
	p->saludo=WordComplete;
	printf("p->saludo=0x%x\n",p->saludo);
	printf("H%s\n",p->c);
	for(i=31;i>=0;i=i-1)
		{
		printf("%i",(WordComplete>>i)&0x1);
			switch(i)
			{case 28:
				printf("\t");		
				brake;
			case 24:
				printf("\t");		
				brake;
			case 20:
				printf("\t");		
				brake;
			case 16:
				printf("\t");		
				brake;
			case 12:
				printf("\t");		
				brake;
			case 8:
				printf("\t");		
				brake;
			case 4:
				printf("\t");		
				brake;
			case 0:
				printf("\t");		
				brake;
			default:
				brake;}
		}



	printf("\n");
	printf("Para el int p->saludo se usan %i bytes\n",sizeof(p->saludo));
	printf("Para el arreglo  p->c se usan %i bytes\n",sizeof(p->c));
	printf("Pointer a p->saludo:%p\n",&p->saludo);
	for(i=0;i<=3;i++)
	{printf("Pointer a p->c[%i]:%p\n",i, &p->c[i]);
	}
	/*printf("Pointer a p->c[1]:%p\n",&p->c[1]);
	printf("Pointer a p->c[2]:%p\n",&p->c[2]);
	printf("Pointer a p->c[3]:%p\n",&p->c[3]);
	*/
	getch();
	return 0;
}/*end main()*/
