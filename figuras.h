//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void prisma_anun (GLuint text, GLuint text2);							//Funcíon creacion movimiento
	void prisma (float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma
	void prismavar(float altura, float largo, float profundidad, GLuint text,float r, float s);//Funcíon creacion prisma
	void prisma2 (GLuint text, GLuint text2);
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo
	void skybox2 (float altura, float largo, float profundidad, GLuint text);
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);
	void pared1(float altura, float largo, float profundidad, GLuint text, float repeticionhorizontal, float repeticionvertical);
	void piso(float largo, float profundidad, GLuint text, int repeticion);
	void puerta(float altura, float largo, float profundidad, GLuint text);
	void cilindro2(float radio, float altura, int resolucion, GLuint text,float tamano);
	///
	void prismaInc(float altura, float largo, float profundidad, GLuint text);
	void prismaLuis(float altura, float largo, float profundidad, GLuint text, float x, float y);//Funcíon creacion prisma
};
