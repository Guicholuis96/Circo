//Proyecto Computacion Grafica Circo
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Quintero Torres Luis Leonardo	            ******//
//*************	Quintero Torres Luis Leonardo			******//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "windows.h"


//Solo para Visual Studio 2015 o mayor
#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CFiguras Carpa;
CFiguras f_Evans;
CTexture t_sinsajo;
CTexture T_Puerta; 

CTexture T_porche;
CTexture T_pasto;
CTexture T_P_Interna;
CTexture T_Piso_Cochera;


CTexture T_almo;
CTexture T_closet;
CTexture T_puerta_closet;
CTexture T_tubo;
CTexture T_puerta_regadera;
CTexture T_espejo;
CTexture T_coladera;
CTexture T_baniera;
CTexture T_anaquel;
CTexture T_puerta_doble;
CTexture T_sillon;
CTexture T_negro;
CTexture T_morado_claro;
CTexture T_morado;
CTexture T_morado_obs;
CTexture T_rojo;
CTexture T_blanco;
CTexture T_aspi;
CTexture ventp;
CTexture vent;
CTexture shrub;
CTexture orilla;
CTexture water;
CTexture po;
CTexture ti;
CTexture to;
CTexture grass;
CTexture tmesa;
CTexture pfuera;
CTexture text1;
CTexture tree;
CTexture pat;
CTexture text2;
CTexture text4;
CTexture PisoVerde;
CTexture PisoCafe;
CTexture PuertaEntrada;
CTexture Porche;
CTexture InteriorAzul;
CTexture ParedInterna;
CTexture Concreto;
CTexture Concreto2;
CTexture PisoConcreto;
CTexture roble;
CTexture madera2;
CTexture ParedExterior;
CFiguras sky;
CTexture ball;
CTexture text3;	
CTexture Concreto3;
CTexture Concreto4;
CTexture PisoConcreto2;
CTexture text41;
CTexture VentanaT;
CTexture TextPlasVerde;
CTexture AlmohadaLuis;
CTexture techo;
CTexture bird;
CTexture alaizq;
CTexture alader;
CTexture Sam1;
CTexture basquet;
CTexture base_C;
CTexture pasto;
CTexture entrada;
CTexture piso_int;
CTexture poste_text;
CTexture madera_text;
DWORD espera = 500;
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;
float Blanco[] = { 1,1,1 };
int sol = 0;
double i;
double ii = 1;

GLfloat luzPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat luzDiffuse[] = { 0.1f, 0.4f, 0.8f, 1.0f };			
GLfloat luzSpecular[] = { 0.1f, 0.4f, 0.8f, 1.0 };
GLfloat luzShininess[] = { 120 };
int luna_rot = 0;
///////////////////Animacion //////////////////////
bool luz = true;
float movaspX = 0;
float movaspy = 0;
float movaspZ = 0;
float rotasp = 0;
bool circuito = false;
bool g_avanza = false;
bool g_fanimacion = false;
bool recorrido1 = true;
bool recorrido2 = false;
bool recorrido3 = false;
bool recorrido4 = false;
bool recorrido5 = false;

///////////ANimacion balon
float rotball = 0.0;
float ballx = 3.0;
float trasball = 3.5;
float movball = 5.0;
bool auxball = false;


////////Animacion pajaro
float rotbird = 180;
float rotbird2 = 0;
float mov_alas;
float mov_alas2;
bool ani_pajaro = true;
bool reco = false;
bool aletear = true;
bool aletear2 = false;
bool recorrido = true;
bool reco_pajaro1 = true;
bool reco_pajaro2 = false;
bool reco_pajaro3 = false;
bool reco_pajaro4 = false;
bool reco_pajaro5 = false;
float mov_pajarox = 0;
float mov_pajaroy = 0;
float mov_pajaroz = 0;


////////////////////////Animacion Luis
static int Lmov = 0;
float a = 0, b = 0;
int movimiento_horiz = 0,movimiento_profundidad=0;
static float movhoriz = 0, moverti = 0;
static float movhoriz2 = 0, moverti2 = 0;

//NEW// Keyframes
float posX = 0, posY = 2.5, posZ = -3.5;
float giroMonito = 0;
float movBrazoDer = 0.0;

#define MAX_FRAMES 9
int i_max_steps = 90;
int i_curr_steps = 0;
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float giroMonito;
	float giroMonitoInc;




}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 5;			
bool play = false;
int playIndex = 0;



int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;
float r_puerta = 0;
CFiguras fig;
CFiguras fig7;
CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;   
GLfloat position[] = { 1,4,1 };
GLfloat spotposition[] = { 2,2,2,2 };
GLfloat spotexpo[] = { 3 };								
GLfloat angulo[] = { 45 };

GLfloat Ambient[] = {1,1,1,1};
GLfloat Diffuse[]= { 1,1,1,1};								
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			
GLfloat Material_Rojo_Amb[] = { 1,0,0 };
GLfloat Material_Rojo_dif[] = { 1,0,0 };
GLfloat Material_Rojo_Spe[] = { 1,0,0 };
GLfloat Material_Azul_dif[] = { 0,0,1 };
GLfloat Material_Blanco_dif[] = { 1,1,1 };
GLfloat Material_Negro[] = {0,0,0}; 
GLfloat Materia_Verde[] = {0,1,1};


void saveFrame(void)
{

	printf("frameindex %d\n", FrameIndex);

	KeyFrame[FrameIndex].posX = posX;
	KeyFrame[FrameIndex].posY = posY;
	KeyFrame[FrameIndex].posZ = posZ;

	KeyFrame[FrameIndex].giroMonito = giroMonito;

	FrameIndex++;
}

void resetElements(void)
{
	posX = KeyFrame[0].posX;
	posY = KeyFrame[0].posY;
	posZ = KeyFrame[0].posZ;

	giroMonito = KeyFrame[0].giroMonito;


}

void interpolation(void)
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;
	KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;


}
void lampar(void) {
	glPushMatrix();
	glTranslatef(0, 2, 0);	
	glLightfv(GL_LIGHT2, GL_POSITION, luzPosition);
	glDisable(GL_LIGHTING);
	fig.esfera(0.5, 50, 50, PisoVerde.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}
void lampara(void) {
	glPushMatrix();
	lampar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -1, 0);
	fig.prismaLuis(5, 0.4, 0.4,Concreto3.GLindex,1,1);
	glPopMatrix();
}
void mago2() {
	
	glRotatef(luna_rot, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 2.5, 0);
	glColor3f(0.6, 0.6, 0.6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, luzDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, luzSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, luzShininess);
	glutSolidSphere(0.4, 20, 20); 
	glPopMatrix();
}
void monito()
{
	
	glPushMatrix();
	glPushMatrix();
	//Cuerpo
	glTranslatef(14, -2.5, 0.0);
	glPushMatrix();
	glScalef(8.0, 8.0, 8.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//patadelanteraD
	glPushMatrix();
	glTranslatef(3.0, -6.0, 3.0);
	glScalef(2.0, 4.0, 2.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//patadelanteraI
	glPushMatrix();
	glTranslatef(-3.0, -6.0, 3.0);
	glScalef(2.0, 4.0, 2.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//pataTraseraI
	glPushMatrix();
	glTranslatef(-3.0, -6.0, -3.0);
	glScalef(2.0, 4.0, 2.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//pataTraseraD
	glPushMatrix();
	glTranslatef(3.0, -6.0, -3.0);
	glScalef(2.0, 4.0, 2.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//PesuÃ±aTraseraD
	glPushMatrix();
	glTranslatef(3.0, -9.0, -2.5);
	glScalef(2.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado.GLindex, T_morado.GLindex);
	glPopMatrix();

	//PesuÃ±aDescoloridaTraseraD
	glPushMatrix();
	glTranslatef(3.0, -9.0, -3.5);
	glScalef(2.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//PesuÃ±aTraseraI
	glPushMatrix();
	glTranslatef(-3.0, -9.0, -2.5);
	glScalef(2.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado.GLindex, T_morado.GLindex);
	glPopMatrix();

	//PesuÃ±aDescoloridaTraseraI
	glPushMatrix();
	glTranslatef(-3.0, -9.0, -3.5);
	glScalef(2.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//PesuÃ±adelanteraD
	glPushMatrix();
	glTranslatef(3.0, -9.0, 3.5);
	glScalef(2.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado.GLindex, T_morado.GLindex);
	glPopMatrix();

	//PesuÃ±aDescoloridaDelanteraD
	glPushMatrix();
	glTranslatef(3.0, -9.0, 2.5);
	glScalef(2.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//PesuÃ±adelanteraI
	glPushMatrix();
	glTranslatef(-3.0, -9.0, 3.5);
	glScalef(2.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado.GLindex, T_morado.GLindex);
	glPopMatrix();

	//PesuÃ±aDescoloridaDelanteraI
	glPushMatrix();
	glTranslatef(-3.0, -9.0, 2.5);
	glScalef(2.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//CaraAbajo
	glPushMatrix();
	glTranslatef(0.0, -4.0, 4.0);
	glScalef(6.0, 1.0, 4.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//CuerpoAbajo
	glPushMatrix();
	glTranslatef(0.0, -5.0, 0.0);
	glScalef(8.0, 2.0, 4.0);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	glTranslatef(0.0, 0.0, 4.0);

	//CaraArriba
	glPushMatrix();
	glScalef(6.0, 7.0, 4.0);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//SoporteOrejaD
	glPushMatrix();
	glTranslatef(3.5, 2.0, 1.0);
	glScalef(1.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//SoporteOrejaI
	glPushMatrix();
	glTranslatef(-3.5, 2.0, 1.0);
	glScalef(1.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//OrejaID
	glPushMatrix();
	glTranslatef(-4.5, 3.0, 1.0);
	glScalef(1.0, 4.0, 1.0);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//OrejaIMedio
	glPushMatrix();
	glTranslatef(-5.5, 3.0, 1.0);
	glScalef(1.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado.GLindex, T_morado.GLindex);
	glPopMatrix();

	//OrejaII
	glPushMatrix();
	glTranslatef(-6.5, 3.0, 1.0);
	glScalef(1.0, 4.0, 1.0);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//OrejaDD
	glPushMatrix();
	glTranslatef(4.5, 3.0, 1.0);
	glScalef(1.0, 4.0, 1.0);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//OrejaDMedio
	glPushMatrix();
	glTranslatef(5.5, 3.0, 1.0);
	glScalef(1.0, 2.0, 1.0);
	f_Evans.prisma2(T_morado.GLindex, T_morado.GLindex);
	glPopMatrix();

	//OrejaDI
	glPushMatrix();
	glTranslatef(6.5, 3.0, 1.0);
	glScalef(1.0, 4.0, 1.0);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//OrejaDMedioAbajo
	glPushMatrix();
	glTranslatef(5.5, 1.5, 1.0);
	glScalef(1.0, 1.0, 1.0);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//OrejaDMedioArriba
	glPushMatrix();
	glTranslatef(5.5, 4.5, 1.0);
	glScalef(1.0, 1.0, 1.0);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//OrejaDMedioAbajo
	glPushMatrix();
	glTranslatef(-5.5, 1.5, 1.0);
	glScalef(1.0, 1.0, 1.0);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//OrejaDMedioArriba
	glPushMatrix();
	glTranslatef(-5.5, 4.5, 1.0);
	glScalef(1.0, 1.0, 1.0);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//Nuevo punto
	glTranslatef(0.0, -1.0, 2.5);

	//CaraArribaArriba
	glPushMatrix();
	glScalef(4.0, 4.5, 1.0);
	f_Evans.prisma2(T_morado_claro.GLindex, T_morado_claro.GLindex);
	glPopMatrix();

	//OjoD
	glPushMatrix();
	glTranslatef(1.2, 3.5, 0);
	glScalef(0.8, 0.5, 1.0);
	f_Evans.prisma2(T_blanco.GLindex, T_blanco.GLindex);
	glPopMatrix();

	//OjoDI
	glPushMatrix();
	glTranslatef(1.5, 3, 0);
	glScalef(0.2, 1.5, 1.0);
	f_Evans.prisma2(T_blanco.GLindex, T_blanco.GLindex);
	glPopMatrix();

	//OjoDD
	glPushMatrix();
	glTranslatef(0.9, 3, 0);
	glScalef(0.2, 1.5, 1.0);
	f_Evans.prisma2(T_blanco.GLindex, T_blanco.GLindex);
	glPopMatrix();

	//OjoDAdentro
	glPushMatrix();
	glTranslatef(1.2, 2.5, 0);
	glScalef(0.4, 1.5, 1.0);
	f_Evans.prisma2(T_negro.GLindex, T_negro.GLindex);
	glPopMatrix();


	//OjoI
	glPushMatrix();
	glTranslatef(-1.2, 3.5, 0);
	glScalef(0.8, 0.5, 1.0);
	f_Evans.prisma2(T_blanco.GLindex, T_blanco.GLindex);
	glPopMatrix();

	//OjoII
	glPushMatrix();
	glTranslatef(-1.5, 3, 0);
	glScalef(0.2, 1.5, 1.0);
	f_Evans.prisma2(T_blanco.GLindex, T_blanco.GLindex);
	glPopMatrix();

	//OjoID
	glPushMatrix();
	glTranslatef(-0.9, 3, 0);
	glScalef(0.2, 1.5, 1.0);
	f_Evans.prisma2(T_blanco.GLindex, T_blanco.GLindex);
	glPopMatrix();

	//OjoIAdentro
	glPushMatrix();
	glTranslatef(-1.2, 2.5, 0);
	glScalef(0.4, 1.5, 1.0);
	f_Evans.prisma2(T_negro.GLindex, T_negro.GLindex);
	glPopMatrix();


	//Labio
	glPushMatrix();
	glTranslatef(0.0, -3.0, 1.5);
	glScalef(6.0, 1.0, 2.0);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//Diente
	glPushMatrix();
	glTranslatef(-1.5, -2.0, 1.5);
	glScalef(1.0, 1.0, 1.5);
	f_Evans.prisma2(T_blanco.GLindex, T_blanco.GLindex);
	glPopMatrix();

	//Diente
	glPushMatrix();
	glTranslatef(1.5, -2.0, 1.5);
	glScalef(1.0, 1.0, 1.5);
	f_Evans.prisma2(T_blanco.GLindex, T_blanco.GLindex);
	glPopMatrix();

	//lengua
	glPushMatrix();
	glTranslatef(0.0, -2.0, 1.5);
	glScalef(2.0, 1.0, 1.5);
	f_Evans.prisma2(T_rojo.GLindex, T_rojo.GLindex);
	glPopMatrix();

	//Nuevo punto
	glTranslatef(0.0, 0.5, 1.2);

	//Trompa
	glPushMatrix();
	//glTranslatef(0.0, 0.5, 1.5);
	glScalef(6.0, 3.5, 1.5);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//trompacuadrobajo
	glPushMatrix();
	glTranslatef(0.0, -0.75, 1);
	glScalef(6.0, 2, 0.5);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//trompacuadroBajoM
	glPushMatrix();
	glTranslatef(0, 1.0, 1);
	glScalef(1.0, 1.5, 0.5);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//trompacuadroBajoD
	glPushMatrix();
	glTranslatef(2.5, 1.0, 1);
	glScalef(1.0, 1.5, 0.5);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//trompacuadroBajoD
	glPushMatrix();
	glTranslatef(-2.5, 1.0, 1);
	glScalef(1.0, 1.5, 0.5);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//trompacuadroObsD
	glPushMatrix();
	glTranslatef(1.2, 1.0, 1);
	glScalef(1.0, 1.5, 0.5);
	f_Evans.prisma2(T_morado.GLindex, T_morado.GLindex);
	glPopMatrix();

	//trompacuadroObsI
	glPushMatrix();
	glTranslatef(-1.2, 1.0, 1);
	glScalef(1.0, 1.5, 0.5);
	f_Evans.prisma2(T_morado.GLindex, T_morado.GLindex);
	glPopMatrix();


	//trompaARRIBAOBSCURO
	glPushMatrix();
	glTranslatef(1.2, 2.0, 1);
	glScalef(1.5, 0.5, 0.5);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	//trompacuadroObsI
	glPushMatrix();
	glTranslatef(-1.2, 2.0, 1);
	glScalef(1.5, 0.5, 0.5);
	f_Evans.prisma2(T_morado_obs.GLindex, T_morado_obs.GLindex);
	glPopMatrix();

	glPopMatrix();


	glPopMatrix();
	//glEndList();
}
void pajaro() {
	glPushMatrix();
		glTranslatef(-8.0 + mov_pajarox, -0.72 + mov_pajaroy, -10.0 + mov_pajaroz);
		glRotatef(rotbird2, 1.0, 0.0, 0.0);
		glRotatef(rotbird, 0.0, 1.0, 0.0);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			glPushMatrix();
			glRotated(-55, 0.0, 1.0, 0.0);
			fig.esfera(0.3, 20, 20, bird.GLindex);
			glPopMatrix();

		glPushMatrix();
			glRotatef(mov_alas, 0.0, 0.0, 1.0);
			glPushMatrix();
			glTranslatef(0.5, 0.0, 0.10);
			fig.piso(0.5, 0.3, alader.GLindex, 1);
			glPopMatrix();
		glPopMatrix();

		glRotatef(mov_alas2, 0.0, 0.0, 1.0);
		glPushMatrix();
			glTranslatef(-0.5, 0.0, 0.10);
			fig.piso(0.5, 0.3, alaizq.GLindex, 1);
		glPopMatrix();
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();
}
void aspiradora()
{
	glPushMatrix();
	glScalef(1, 0.1, 1);
	f_Evans.prisma2(T_negro.GLindex, T_negro.GLindex);

	glPopMatrix();
}
void tocado_banio()
{
	glPushMatrix();

	glPushMatrix();
	glTranslatef(30.55, 1.25, -13.9);
	glScalef(1.1, 2.5, 3.8);
	f_Evans.prisma2(T_tubo.GLindex, T_baniera.GLindex);
	glPopMatrix();

	glPushMatrix();//Espejo baño
	glBindTexture(GL_TEXTURE_2D, T_espejo.GLindex);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(30.01, 3.5, -12.3);
	glTexCoord2f(1, 0); glVertex3f(30.01, 3.5, -15.7);
	glTexCoord2f(1, 1); glVertex3f(30.01, 5.5, -15.7);
	glTexCoord2f(0, 1); glVertex3f(30.01, 5.5, -12.3);
	glEnd();
	glPopMatrix();

	glPushMatrix();//Coladera regadera
	glBindTexture(GL_TEXTURE_2D, T_coladera.GLindex);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(35, 0.01, -10.5);
	glTexCoord2f(1, 0); glVertex3f(35, 0.01, -11.5);
	glTexCoord2f(1, 1); glVertex3f(36, 0.01, -11.5);
	glTexCoord2f(0, 1); glVertex3f(36, 0.01, -10.5);
	glEnd();
	glPopMatrix();



	glPopMatrix();
}
void banio_base(void)
{
	glScalef(1.0f, 1.0f, 1.0f);
	f_Evans.cilindro(0.15f, 0.2, 10, T_baniera.GLindex);


}
void banio_taza(void)
{
	glScalef(1.0f, 0.66f, 0.8f);
	f_Evans.esfera(0.3f, 10, 10, T_baniera.GLindex);
}
void banio_caja(void)
{
	glScalef(0.15f, 0.5f, 0.8f);
	f_Evans.prisma2(T_baniera.GLindex, T_baniera.GLindex);
}
void banio(float rotar)
{
	glPushMatrix();
	glRotatef(rotar, 0.0, 1.0, 0.0);

	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.05f, 0.52f, 0.0f);
	//banio_tapa();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.35f, 0.0f);
	banio_taza();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.24f, 0.57f, 0.0f);
	banio_caja();
	glPopMatrix();

	banio_base();
	glPopMatrix();
}
void sillaLuis(float a, GLuint m, float x, float y)
{
	glTranslatef(0.0, 0.18, 0.0);
	glScalef(a, a, a);
	glPushMatrix();
	fig.prismaLuis(3.0, 0.2, 0.2, m, x, y);
	fig.prismaLuis(2.8, 0.2, 0.2, m, x, y);
	glTranslatef(1.0, 0.0, 0.0);
	fig.prismaLuis(3.0, 0.2, 0.2, m, x, y);
	fig.prismaLuis(2.8, 0.2, 0.2, m, x, y);
	glTranslatef(0.0, 0.0, 1.0);
	fig.prismaLuis(3.0, 0.2, 0.2, m, x, y);
	fig.prismaLuis(2.8, 0.2, 0.2, m, x, y);
	glTranslatef(-1.0, 0.0, 0.0);
	fig.prismaLuis(3.0, 0.2, 0.2, m, x, y);
	fig.prismaLuis(2.8, 0.2, 0.2, m, x, y);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.5, 1.5, 0.5);
	fig.prismaLuis(0.2, 1.2, 1.2, m, x, y);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.5, 2.2, 1.2);
	glRotatef(90, 1.0, 0.0, 0.0);
	fig.prismaLuis(0.2, 1.2, 1.2, m, x, y);
	glPopMatrix();

}
void lanzador()
{
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.0, 5, 0);
	glRotatef(45, 1, 0, 0);
	fig.cilindro(0.5, 4, 10, AlmohadaLuis.GLindex);

	glPopMatrix();
	glPopMatrix();

}
void persona()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
	glScalef(0.5, 0.5, 0.5);
	fig7.prisma(2.0, 2.0, 1, text2.GLindex);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.0, 0.0);
	fig7.cilindro(0.25, 0.25, 15, 0);
	glPushMatrix();//Cabeza
	glTranslatef(0, 1.0, 0);
	fig7.esfera(0.75, 15, 15, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glRotatef(-45, 0, 1, 0);
	glTranslatef(0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(45, 0, 1, 0);
	glRotatef(25, 0, 0, 1);
	glRotatef(25, 1, 0, 0);
	glTranslatef(-0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(0, 0, 1);
	glTranslatef(0, -1.5, 0);
	fig7.prisma(1, 2, 1, 0);

	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	glRotatef(-5, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 , 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}
void mago(void) {
	glPushMatrix();
	glTranslatef(-25, 2, -4.8);
	mago2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-25, 1.5, -10);
	persona();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-26, 2, -9);
	glRotatef(45, 1, 0, 0);
	fig.prismaLuis(3, 0.2, 0.2, Concreto4.GLindex, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-24, 2, -9);
	glRotatef(45, 1, 0, 0);
	fig.prismaLuis(3, 0.2, 0.2, Concreto4.GLindex, 1, 1);
	glPopMatrix();
}
void ventanaLuis(float x, float y, float z, CTexture ven, float r, float s) {
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	fig.prismavar(x, y, z, ven.GLindex, r, s);
	glDisable(GL_BLEND);
	glPopMatrix();
}
void silla(float a, GLuint m) {
	glTranslatef(0.0, 0.18, 0.0);
	glScalef(a, a, a);
	glPushMatrix();
	fig.prisma(2.8, 0.2, 0.2, m);
	glTranslatef(1.0, 0.0, 0.0);
	fig.prisma(2.8, 0.2, 0.2, m);
	glTranslatef(0.0, 0.0, 1.0);
	fig.prisma(2.8, 0.2, 0.2, m);
	glTranslatef(-1.0, 0.0, 0.0);
	fig.prisma(2.8, 0.2, 0.2, m);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.5, 1.5, 0.5);
	fig.prisma(0.2, 1.2, 1.2, m);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.5, 2.2, 1.2);
	glRotatef(90, 1.0, 0.0, 0.0);
	fig.prisma(0.2, 1.2, 1.2, m);
	glPopMatrix();
}
void patio(GLuint p, GLuint g, GLuint tin, GLuint tout,GLuint pout, GLuint wat,GLuint or,GLuint pat) {
	fig.prisma(0.1,18.0,16.0,p);
	
	glPushMatrix();//pasto
		glTranslatef(3.0, 0.0, -12.0);
		fig.prismavar(0.1, 12.0, 8.0, g,1,2);
	glPopMatrix();
	glPushMatrix();//piso madera
		glTranslatef(-6.0, 0.0, -12.0);
		fig.prisma(0.1, 6.0, 8.0, pout);
	glPopMatrix();
	glPushMatrix();//pasto largo
		glTranslatef(-13.0, 0.0, -9.0);
		fig.prismavar(0.1, 8.0, 14.0, g,2,2);
	glPopMatrix();
	glPushMatrix();//piso madera largo
		glTranslatef(-26.0, 0.0, 1.0);
		fig.prismavar(0.1, 34.0, 6.0, pout,.5,1);
	glPopMatrix();
	glPushMatrix();//pasto largo fuera
		glTranslatef(-26.0, 0.0, 6.0);
		fig.prismavar(0.1, 34.0, 4.0, g,.5,4);
	glPopMatrix();
	glPushMatrix();//piso madera pequeño fuera
		glTranslatef(-19.0, 0.0, -9.0);
		fig.prisma(0.1, 4.0, 14.0, pout);
	glPopMatrix();
	glPushMatrix();//alberca
		glTranslatef(-32.0, 0.0, -9.0);
		fig.prisma(0.1,19.5,12.0, wat);
	glPopMatrix();
	glPushMatrix();//inferior orilla alberca
		glTranslatef(-21.62, 0.0, -9.0);
		fig.prismavar(0.1, 1.26, 14.0, or,1,.1);
	glPopMatrix();
	glPushMatrix();//superior orilla alberca
		glTranslatef(-42.39, 0.0, -9.0);
		fig.prismavar(0.1, 1.26, 14.0, or,1,.1);
	glPopMatrix();
	glPushMatrix();//derecha orilla alberca
		glTranslatef(-32.0, 0.0, -15.5);
		fig.prismavar(0.1, 19.5, 1.0, or,.1,1);
	glPopMatrix();
	glPushMatrix();//izquierda orilla alberca
		glTranslatef(-32.0, 0.0, -2.5);
		fig.prismavar(0.1, 19.5, 1.0, or,.1,1);
	glPopMatrix();
	glPushMatrix();//pasto patio
		glTranslatef(-26.0, 0.0, -38.0);
		fig.prismavar(0.1, 34.0, 44.0, g,4,4);
	glPopMatrix();
	glPushMatrix();//pasto patio2
	glTranslatef(0.0, 0.0, -38.0);
	fig.prismavar(0.1, 34.0, 44.0, g, 4, 4);
	glPopMatrix();
	glPushMatrix();//pasto patio2.1
	glTranslatef(31.5, 0.0, -26.0);
	fig.prismavar(0.1, 45.0, 68.0, g, 4, 4);
	glPopMatrix();

	glPushMatrix();//pasto patio2.2
	glTranslatef(5, 0.0, 35.5);
	fig.prismavar(0.1, 96.0, 55.0, g, 4, 4);
	glPopMatrix();


	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glTranslatef(15, 1.5, -85);
	//glRotatef(45, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-8.1, -1, 50.0);
	glTranslatef(posX, posY, posZ);
	glRotatef(giroMonito, 0, 1, 0);
	glScalef(0.4, 0.2, 0.33);
	monito();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30, 1.5, -50);
	//glRotatef(45, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-8.1, -1, 50.0);
	glTranslatef(posX, posY, posZ);
	glRotatef(giroMonito, 0, 1, 0);
	glScalef(0.4, 0.2, 0.33);
	monito();
	glPopMatrix();
	glPopMatrix();


	//glPushMatrix();
	//glRotatef(90, 0, 1, 0);
	//glTranslatef(7.0, 2.5, 10); //abajo
	//ventanaLuis(5, 50, 0.01, VentanaT, 1, 1);
//	glPopMatrix();

	//glPushMatrix();
	//glRotatef(90, 0, 1, 0); /////arriba
	//glTranslatef(7.0, 2.5, 65);
	//ventanaLuis(5, 50, 0.01, VentanaT, 1, 1);
	//glPopMatrix();

	//glPushMatrix();
	//glRotatef(0, 0, 1, 0);    //izq
	//glTranslatef(37.5, 2.5, -32);
	//ventanaLuis(5, 55, 0.01, VentanaT, 1, 1);
	//glPopMatrix();

	//glPushMatrix();
	//glRotatef(0, 0, 1, 0);   //der
	//glTranslatef(37.5, 2.5, 18);
	//ventanaLuis(5, 55, 0.01, VentanaT, 1, 1);
	//glPopMatrix();
	

	
	glPushMatrix();
	glTranslatef(40,0,-50);
	glRotatef(270, 0, 1, 0);
	glPushMatrix();
	glRotatef(30, 0, 1, 0);
	glTranslatef(0, -4.5, 3);
	lanzador();
	glPopMatrix();
	glTranslatef(ballx, 0 + trasball, movball);//Animacion Pelota
	glPushMatrix();
	glRotatef(rotball, 0.0, 0.0, 1.0);
	fig.esfera(0.5, 10, 10, ball.GLindex);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10, 0, 0);
	glPushMatrix();
	glScalef(0.8, 0.8, 0.8);
	glTranslatef(-2.0, 3.0, 0.0);
	persona();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(12, 0, 20);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(16, 0, 20);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(19, 0, 20);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(22, 0, 20);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(25, 0, 20);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(28, 0, 20);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(32, 0, 20);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix(); glPushMatrix();
	glTranslatef(35, 0, 20);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(12, 0, 25);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(16, 0, 25);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(19, 0, 25);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(22, 0, 25);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(25, 0, 25);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(28, 0, 25);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(32, 0, 25);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix(); glPushMatrix();
	glTranslatef(35, 0, 25);
	sillaLuis(1.0, TextPlasVerde.GLindex, 1, 1);
	glPopMatrix();

	//banio
	glPushMatrix();
	glTranslatef(-39.5, 0, 68.5);
	//glScalef(2.7, 2.7, 2.7);
	tocado_banio();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15, 0, 52.5);
	glScalef(2.7, 2.7, 2.7);
	banio(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-20, 3, 50);
	glRotatef(270, 0, 1, 0);

	glPushMatrix();										//Pared2
	glTranslatef(4.0, 0.0, -4.05);
	fig.prismaLuis(6.0, 8.0, 0.01, T_morado_obs.GLindex, 1, 1);
	glPopMatrix();

	glPushMatrix();										//Pared1
	glTranslatef(8.0, 0.0, -8);
	glRotated(90, 0.0, 1.0, 0.0);
	fig.prismaLuis(6.0, 8.0, 0.1, T_morado_obs.GLindex, 1.2, 1);
	glPopMatrix();
	glPushMatrix();										//Textura
	glTranslatef(8.0, 0.0, -8);
	glRotated(90, 0.0, 1.0, 0.0);
	fig.prismaLuis(6.0, 8.0, 0.01, T_morado_obs.GLindex, 1, 1);
	glPopMatrix();

	glPushMatrix();										//Pared1
	glTranslatef(0.0, 0.0, -6.5);
	glRotated(90, 0.0, 1.0, 0.0);
	fig.prismaLuis(6.0, 5.0, 0.1, T_morado_obs.GLindex, 1.2, 1);
	glPopMatrix();
	glPushMatrix();										//Textura
	glTranslatef(0.05, 0.0, -6.5);
	glRotated(90, 0.0, 1.0, 0.0);
	fig.prismaLuis(6.0, 5.0, 0.01, T_morado_obs.GLindex, 1, 1);
	glPopMatrix();


	glPushMatrix();										//Puerta
	glTranslatef(0.0, 0.0, -10.5);
	glRotated(90, 0.0, 1.0, 0.0);
	fig.prismaLuis(6.0, 3.0, 0.1, PuertaEntrada.GLindex, 1, 1);
	glPopMatrix();

	glPushMatrix();										//Puerta2
	glTranslatef(0.05, 0.0, -10.5);
	glRotated(180, 1.0, 0.0, 1.0);
	fig.prismaLuis(6.0, 3.0, 0.01, PuertaEntrada.GLindex, 1, 1);
	glPopMatrix();

	glPushMatrix();										//Pared4
	glTranslatef(4, 0.0, -12.0);
	fig.prismaLuis(6.0, 8.08, 0.1, T_morado_obs.GLindex, 1, 1);
	glPopMatrix();
	glPushMatrix();										//Textura
	glTranslatef(4.0, 0.0, -11.95);
	fig.prismaLuis(6.0, 8.08, 0.01, T_morado_obs.GLindex, 1, 1);
	glPopMatrix();

	glPushMatrix();										//Suelo
	glTranslatef(4, -3.0, -8.0);
	glRotated(90, 1.0, 0.0, 0.0);
	fig.prismaLuis(8.0, 8.0, 0.01, PisoConcreto.GLindex, 1, 1);
	glPopMatrix();

	glPushMatrix();										//techo
	glTranslatef(4, 3.0, -8.0);
	glRotated(90, 1.0, 0.0, 0.0);
	fig.prismaLuis(8.0, 8.0, 0.01, T_morado_obs.GLindex, 1, 1);
	glPopMatrix();

	glPopMatrix();

}
void arbol()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	
	glAlphaFunc(GL_GREATER, 0.1);
	
	glBindTexture(GL_TEXTURE_2D, tree.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.5, 10.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.5, 10.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.5, 10.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.5, 10.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.5, 10.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.5, 10.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.5, 10.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.5, 10.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);

	glPopMatrix();
}
//
void dibujarCirco() {
	glPushMatrix();
	//lado derecho
	glPushMatrix();
	glTranslatef(0.0, 5.0, -53.2);
	Carpa.prismaInc(10.0, 30.4, 0.2, base_C.GLindex);
	glPopMatrix();

	glPushMatrix();//panel 2
	glTranslatef(28.5, 5.0, -36.1);
	glRotatef(-52.13, 0.0, 1.0, 0.0);
	Carpa.prismaInc(10.0, 43.3, 0.2, base_C.GLindex);
	glPopMatrix();

	glPushMatrix();//panel 3
	glTranslatef(41.8, 5.0, -1.9);
	glRotatef(-90.0, 0.0, 1.0, 0.0);
	Carpa.prismaInc(10.0, 34.2, 0.2, base_C.GLindex);
	glPopMatrix();

	glPushMatrix();//panel 4
	glTranslatef(28.5, 5.0, 32.3);
	glRotatef(-127.88, 0.0, 1.0, 0.0);
	Carpa.prismaInc(10.0, 43.3, 0.2, base_C.GLindex);
	glPopMatrix();

	//lado izquierdo

	glPushMatrix();//panel 5
	glTranslatef(-28.5, 5.0, -36.1);
	glRotatef(52.13, 0.0, 1.0, 0.0);
	Carpa.prismaInc(10.0, 43.3, 0.2, base_C.GLindex);
	glPopMatrix();

	glPushMatrix();//panel 6
	glTranslatef(-41.8, 5.0, -1.9);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	Carpa.prismaInc(10.0, 34.2, 0.2, base_C.GLindex);
	glPopMatrix();

	glPushMatrix();//panel 7
	glTranslatef(-28.5, 5.0, 32.3);
	glRotatef(127.8, 0.0, 1.0, 0.0);
	Carpa.prismaInc(10.0, 43.3, 0.2, base_C.GLindex);
	glPopMatrix();

	//pasto lado derecho
	//glPushMatrix();
	//glTranslatef(53.2, -0.2, 0.0);
	//Carpa.prisma(0.4, 22.8, 130.0, pasto.GLindex);
	//glPopMatrix();

	//pasto lado izquierdo
	//glPushMatrix();
	//glTranslatef(-53.2, -0.2, 0.0);
	//Carpa.prisma(0.4, 22.8, 130.0, pasto.GLindex);
	//glPopMatrix();

	//pasto enmedio norte
	//glPushMatrix();
	//glTranslatef(0.0, -0.2, -58.9);
	//Carpa.prisma(0.4, 83.6, 11.8, pasto.GLindex);
	//glPopMatrix();

	//Entrada
	glPushMatrix();
	glTranslatef(0.0, -0.2, 57.0);
	Carpa.prisma(0.4, 30.4, 15.5, entrada.GLindex);
	glPopMatrix();

	////pasto sureste
	//glPushMatrix();
	//glTranslatef(28.5, -0.2, 57);
	//Carpa.prisma(0.4, 26.6, 15.5, pasto.GLindex);
	//glPopMatrix();

	//pasto sureste
	//glPushMatrix();
	//glTranslatef(-28.5, -0.2, 57);
	//Carpa.prisma(0.4, 26.6, 15.5, pasto.GLindex);
	//glPopMatrix();

	//pista
	glPushMatrix();
	glTranslatef(0.0, -0.2, 0.0);
	Carpa.torus(43.5, 41.8, 55, 15);
	glPopMatrix();

	/*gradas norte
	glPushMatrix();
	glTranslatef(0.0, 4.0, -49.4);
	Carpa.prisma(8, 30.4, 0.5, madera_text.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.25, 4.0, -45.6);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	Carpa.prisma(8, 22.8, 0.5, madera_text.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.25, 4.0, -45.6);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	Carpa.prisma(8, 22.8, 0.5, madera_text.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 8.5, -45.6);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	Carpa.prisma(8, 22.8, 0.5, madera_text.GLindex);
	glPopMatrix();*/

	//POSTE CENTRAL
	glPushMatrix();
	glTranslatef(-5.0, 0.0, 0.0);
	Carpa.cilindro(.55, 26.0, 80.0, poste_text.GLindex);
	glPopMatrix();

	//POSTE CENTRAL
	glPushMatrix();
	glTranslatef(0.0, 26.0, 0.0);
	Carpa.cilindro(.05, 8.0, 50.0, poste_text.GLindex);
	glPopMatrix();


	glPopMatrix();

	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	/* GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA, GL_CONSTANT_COLOR, GL_ONE_MINUS_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA, and GL_SRC_ALPHA_SATURATE*/
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, pasto.GLindex);
	glBegin(GL_QUADS);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Blanco);
	glNormal3f(0.0, 0.0, 1.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(-41.8, 0.1, 49.4);
	glTexCoord2f(1.0, 0.0); glVertex3f(-15.2, 0.1, 49.4);
	glTexCoord2f(1.0, 1.0); glVertex3f(-15.2, 0.1, 49.4);
	glTexCoord2f(0.0, 1.0); glVertex3f(-41.8, 0.1, 15.2);

	glTexCoord2f(0.0, 0.0); glVertex3f(-41.8, 0.1, -19.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(-15.2, 0.1, -53.2);
	glTexCoord2f(1.0, 1.0); glVertex3f(-15.2, 0.1, -53.2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-41.8, 0.1, -53.2);

	glTexCoord2f(0.0, 0.0); glVertex3f(41.8, 0.1, 49.4);
	glTexCoord2f(1.0, 0.0); glVertex3f(15.2, 0.1, 49.4);
	glTexCoord2f(1.0, 1.0); glVertex3f(15.2, 0.1, 49.4);
	glTexCoord2f(0.0, 1.0); glVertex3f(41.8, 0.1, 15.2);

	glTexCoord2f(0.0, 0.0); glVertex3f(41.8, 0.1, -19.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(15.2, 0.1, -53.2);
	glTexCoord2f(1.0, 1.0); glVertex3f(15.2, 0.1, -53.2);
	glTexCoord2f(0.0, 1.0); glVertex3f(41.8, 0.1, -53.2);

	glEnd();
	glPopMatrix();

	/////
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, piso_int.GLindex);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);//piso de la pista
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.2, 0.1, 49.4);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(15.2, 0.0, 49.4);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(15.2, 0.1, -53.2);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.2, 0.1, -53.2);
	glEnd();
	glPopMatrix();
	////

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, piso_int.GLindex);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);//piso de la pista oeste
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-41.8, 0.1, 15.2);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-15.2, 0.0, 49.4);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-15.2, 0.1, -53.2);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-41.8, 0.1, -19);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, piso_int.GLindex);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);//piso de la pista este
	glTexCoord2f(0.0f, 0.0f); glVertex3f(41.8, 0.1, 15.2);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(15.2, 0.0, 49.4);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(15.2, 0.1, -53.2);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(41.8, 0.1, -19);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, base_C.GLindex);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);//carpa sup secc a
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-14.3, 10.2, 48.9);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(14.3, 10.2, 48.9);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, base_C.GLindex);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);//carpa sup secc b
	glTexCoord2f(0.0f, 0.0f); glVertex3f(14.3, 10.2, 48.9);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(41.3, 10.2, 14.7);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, base_C.GLindex);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);//carpa sup secc c
	glTexCoord2f(0.0f, 0.0f); glVertex3f(41.3, 10.2, 14.7);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(41.3, 10.2, -18.5);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, base_C.GLindex);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);//carpa sup secc d
	glTexCoord2f(0.0f, 0.0f); glVertex3f(41.3, 10.2, -18.5);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(14.7, 10.2, -52.7);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, base_C.GLindex);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);//carpa sup secc e
	glTexCoord2f(0.0f, 0.0f); glVertex3f(14.7, 10.2, -52.7);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-14.7, 10.2, -52.7);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, base_C.GLindex);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);//carpa sup secc f
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-41.3, 10.2, -18.5);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-14.7, 10.2, -52.7);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, base_C.GLindex);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);//carpa sup secc g
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-41.3, 10.2, 14.7);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-41.3, 10.2, -18.5);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, base_C.GLindex);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);//carpa sup secc h
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-14.3, 10.2, 48.9);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-41.3, 10.2, 14.7);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 26.5, 0.0);
	glEnd();
	glPopMatrix();


	glPopMatrix();
}
//
void arbusto()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, shrub.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.5, 3.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.5, 3.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.5, 3.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.5, 3.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.5, 3.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.5, 3.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.5, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.5, 3.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.5, 3.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);

	glPopMatrix();
}
void ventana(float x,float y, float z,CTexture ven,float r,float s) {
	glPushMatrix();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			fig.prismavar(x, y, z, ven.GLindex,r,s);
		glDisable(GL_BLEND);
	glPopMatrix();
}
void pat_trasero() {

	
	glPushMatrix();
		glTranslatef(0.0, -1.0, 0.0);
		patio(pfuera.GLindex, grass.GLindex, ti.GLindex, to.GLindex, po.GLindex, water.GLindex, orilla.GLindex,ParedInterna.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0, -1.0, -11.5);
		arbol();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30.0, -1.0, 30.0);
	arbol();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-39.0, -1.0, 39.0);
	arbol();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35.0, -1.0, 45.0);
	arbusto();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(30.0, -1.0, 45.0);
	arbusto();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(25.0, -1.0, 45.0);
	arbusto();
	glPushMatrix();
	glTranslatef(-10, 0, 10);
	pajaro();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(10.0, -1.0, 45.0);
	arbusto();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(5.0, -1.0, 45.0);
	arbusto();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, -1.0, 45.0);
	arbusto();
	glPopMatrix();


	glPushMatrix();
		glTranslatef(-42.0, -1.0, -58.0);
		arbol();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-11.0, -1.0, -15.0);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-11.0, -1.0, -11.0);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-14.0, -1.0, -15.0);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-14.0, -1.0, -11.0);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-11.0, -1.0, -7.0);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-11.0, -1.0, -3.0);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-14.0, -1.0, -7.0);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-14.0, -1.0, -3.0);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-12.0, -1.0, 5.75);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-17.0, -1.0, 5.75);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-22.0, -1.0, 5.75);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-27.0, -1.0, 5.75);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-32.0, -1.0, 5.75);
		arbusto();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-37.0, -1.0, 5.75);
		arbusto();
	glPopMatrix();
	
	
}
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	
	GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			
	GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				
	//GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	glLightfv(GL_LIGHT2, GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, SunSpecular);




	glLightfv(GL_LIGHT1, GL_AMBIENT, Ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Specular);
	//////////////////////////////////////////////////////////////////
	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);								
	glEnable(GL_DEPTH_TEST);							
	glDepthFunc(GL_LEQUAL);								
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	techo.LoadTGA("Texturas/techo.tga");
	techo.BuildGLTexture();
	techo.ReleaseImage();
	
	t_sinsajo.LoadTGA("Texturas/alfombra.tga");
	t_sinsajo.BuildGLTexture();
	t_sinsajo.ReleaseImage();

	T_Puerta.LoadTGA("Texturas/puerta.tga");
	T_Puerta.BuildGLTexture();
	T_Puerta.ReleaseImage();


	T_porche.LoadTGA("Texturas/porche.tga");
	T_porche.BuildGLTexture();
	T_porche.ReleaseImage();

	T_pasto.LoadTGA("Texturas/pasto.tga");
	T_pasto.BuildGLTexture();
	T_pasto.ReleaseImage();

	T_P_Interna.LoadTGA("Texturas/pared_interna.tga");
	T_P_Interna.BuildGLTexture();
	T_P_Interna.ReleaseImage();

	T_Piso_Cochera.LoadTGA("Texturas/piso_cochera.tga");
	T_Piso_Cochera.BuildGLTexture();
	T_Piso_Cochera.ReleaseImage();



	T_almo.LoadTGA("Texturas/almo.tga");
	T_almo.BuildGLTexture();
	T_almo.ReleaseImage();

	T_closet.LoadTGA("Texturas/closet.tga");
	T_closet.BuildGLTexture();
	T_closet.ReleaseImage();

	T_puerta_closet.LoadTGA("Texturas/puerta_closet.tga");
	T_puerta_closet.BuildGLTexture();
	T_puerta_closet.ReleaseImage();

	T_tubo.LoadTGA("Texturas/tubo.tga");
	T_tubo.BuildGLTexture();
	T_tubo.ReleaseImage();

	T_puerta_regadera.LoadTGA("Texturas/puerta_regadera.tga");
	T_puerta_regadera.BuildGLTexture();
	T_puerta_regadera.ReleaseImage();

	T_espejo.LoadTGA("Texturas/espejo.tga");
	T_espejo.BuildGLTexture();
	T_espejo.ReleaseImage();

	T_coladera.LoadTGA("Texturas/coladera.tga");
	T_coladera.BuildGLTexture();
	T_coladera.ReleaseImage();

	T_baniera.LoadTGA("Texturas/baniera.tga");
	T_baniera.BuildGLTexture();
	T_baniera.ReleaseImage();

	T_anaquel.LoadTGA("Texturas/anaquel.tga");
	T_anaquel.BuildGLTexture();
	T_anaquel.ReleaseImage();

	T_puerta_doble.LoadTGA("Texturas/puerta_doble.tga");
	T_puerta_doble.BuildGLTexture();
	T_puerta_doble.ReleaseImage();

	T_sillon.LoadTGA("Texturas/azul.tga");
	T_sillon.BuildGLTexture();
	T_sillon.ReleaseImage();

	T_morado_claro.LoadTGA("Texturas/morado_claro.tga");
	T_morado_claro.BuildGLTexture();
	T_morado_claro.ReleaseImage();

	T_morado.LoadTGA("Texturas/morado.tga");
	T_morado.BuildGLTexture();
	T_morado.ReleaseImage();

	T_morado_obs.LoadTGA("Texturas/morado_obs.tga");
	T_morado_obs.BuildGLTexture();
	T_morado_obs.ReleaseImage();

	T_rojo.LoadTGA("Texturas/rojo.tga");
	T_rojo.BuildGLTexture();
	T_rojo.ReleaseImage();

	T_blanco.LoadTGA("Texturas/blanco.tga");
	T_blanco.BuildGLTexture();
	T_blanco.ReleaseImage();

	T_aspi.LoadTGA("Texturas/aspiradora_arriba.tga");
	T_aspi.BuildGLTexture();
	T_aspi.ReleaseImage();

	T_negro.LoadTGA("Texturas/negro.tga");
	T_negro.BuildGLTexture();
	T_negro.ReleaseImage();

	pat.LoadTGA("Texturas/paredInterna.tga");
	pat.BuildGLTexture();
	pat.ReleaseImage();

	ParedInterna.LoadTGA("Texturas/paredInterna.tga");
	ParedInterna.BuildGLTexture();
	ParedInterna.ReleaseImage();

	vent.LoadTGA("Texturas/ventana.tga");
	vent.BuildGLTexture();
	vent.ReleaseImage();

	ventp.LoadTGA("Texturas/ventanapatio.tga");
	ventp.BuildGLTexture();
	ventp.ReleaseImage();

    text1.LoadBMP("Texturas/01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();
		
	tmesa.LoadTGA("Texturas/mesa.tga");
	tmesa.BuildGLTexture();
	tmesa.ReleaseImage();

	pfuera.LoadTGA("Texturas/pfuera.tga");
	pfuera.BuildGLTexture();
	pfuera.ReleaseImage();

	tree.LoadTGA("Texturas/tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	grass.LoadTGA("Texturas/grass.tga");
	grass.BuildGLTexture();
	grass.ReleaseImage();

	ti.LoadTGA("Texturas/tin.tga");
	ti.BuildGLTexture();
	ti.ReleaseImage();
	
	to.LoadTGA("Texturas/tout.tga");
	to.BuildGLTexture();
	to.ReleaseImage();

	po.LoadTGA("Texturas/pout.tga");
	po.BuildGLTexture();
	po.ReleaseImage();

	water.LoadTGA("Texturas/water.tga");
	water.BuildGLTexture();
	water.ReleaseImage();

	shrub.LoadTGA("Texturas/shrub.tga");
	shrub.BuildGLTexture();
	shrub.ReleaseImage();

	orilla.LoadTGA("Texturas/orilla.tga");
	orilla.BuildGLTexture();
	orilla.ReleaseImage();

	ball.LoadTGA("Texturas/ball.tga");
	ball.BuildGLTexture();
	ball.ReleaseImage();

	text4.LoadTGA("Texturas/tout.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	PisoVerde.LoadTGA("Texturas/pisoverde.tga");
	PisoVerde.BuildGLTexture();
	PisoVerde.ReleaseImage();

	PisoCafe.LoadTGA("Texturas/pisocafe.tga");
	PisoCafe.BuildGLTexture();
	PisoCafe.ReleaseImage();

	PuertaEntrada.LoadTGA("Texturas/PuertaEntrada.tga");
	PuertaEntrada.BuildGLTexture();
	PuertaEntrada.ReleaseImage();

	Porche.LoadTGA("Texturas/porche.tga");
	Porche.BuildGLTexture();
	Porche.ReleaseImage();

	InteriorAzul.LoadTGA("Texturas/InteriorAzul.tga");
	InteriorAzul.BuildGLTexture();
	InteriorAzul.ReleaseImage();

	ParedInterna.LoadTGA("Texturas/paredInterna.tga");
	ParedInterna.BuildGLTexture();
	ParedInterna.ReleaseImage();

	Concreto.LoadTGA("Texturas/Concreto.tga");
	Concreto.BuildGLTexture();
	Concreto.ReleaseImage();

	Concreto2.LoadTGA("Texturas/Concreto2.tga");
	Concreto2.BuildGLTexture();
	Concreto2.ReleaseImage();

	PisoConcreto.LoadTGA("Texturas/PisoConcreto.tga");
	PisoConcreto.BuildGLTexture();
	PisoConcreto.ReleaseImage();

	ParedExterior.LoadTGA("Texturas/tout.tga");
	ParedExterior.BuildGLTexture();
	ParedExterior.ReleaseImage();

	roble.LoadTGA("Texturas/roble.tga");
	roble.BuildGLTexture();
	roble.ReleaseImage();

	madera2.LoadTGA("Texturas/madera2.tga");
	madera2.BuildGLTexture();
	madera2.ReleaseImage();
	
	text3.LoadTGA("Texturas/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();


	tree.LoadTGA("Texturas/tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	text4.LoadTGA("Texturas/tout.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text41.LoadTGA("Texturas/tout2.tga");
	text41.BuildGLTexture();
	text41.ReleaseImage();

	InteriorAzul.LoadTGA("Texturas/InteriorAzul.tga");
	InteriorAzul.BuildGLTexture();
	InteriorAzul.ReleaseImage();

	ParedInterna.LoadTGA("Texturas/paredInterna.tga");
	ParedInterna.BuildGLTexture();
	ParedInterna.ReleaseImage();


	Concreto3.LoadTGA("Texturas/Concreto3.tga");
	Concreto3.BuildGLTexture();
	Concreto3.ReleaseImage();

	Concreto4.LoadTGA("Texturas/Concreto4.tga");
	Concreto4.BuildGLTexture();
	Concreto4.ReleaseImage();

	PisoConcreto.LoadTGA("Texturas/PisoConcreto.tga");
	PisoConcreto.BuildGLTexture();
	PisoConcreto.ReleaseImage();

	PisoConcreto2.LoadTGA("Texturas/PisoConcreto2.tga");
	PisoConcreto2.BuildGLTexture();
	PisoConcreto2.ReleaseImage();

	VentanaT.LoadTGA("Texturas/ventana.tga");
	VentanaT.BuildGLTexture();
	VentanaT.ReleaseImage();

	TextPlasVerde.LoadTGA("Texturas/TextPlasVerde.tga");
	TextPlasVerde.BuildGLTexture();
	TextPlasVerde.ReleaseImage();

	AlmohadaLuis.LoadTGA("Texturas/TextAlmohada.tga");
	AlmohadaLuis.BuildGLTexture();
	AlmohadaLuis.ReleaseImage();

	bird.LoadTGA("Texturas/bird.tga");
	bird.BuildGLTexture();
	bird.ReleaseImage();

	alaizq.LoadTGA("Texturas/ala2.tga");
	alaizq.BuildGLTexture();
	alaizq.ReleaseImage();

	alader.LoadTGA("Texturas/ala1.tga");
	alader.BuildGLTexture();
	alader.ReleaseImage();

	Sam1.LoadTGA("Texturas/sam1.tga");
	Sam1.BuildGLTexture();
	Sam1.ReleaseImage();

	Sam1.LoadTGA("Texturas/basquet.tga");
	Sam1.BuildGLTexture();
	Sam1.ReleaseImage();

	entrada.LoadTGA("Texturas/entrada.tga");
	entrada.BuildGLTexture();
	entrada.ReleaseImage();

	base_C.LoadTGA("Texturas/Carpa.tga");
	base_C.BuildGLTexture();
	base_C.ReleaseImage();

	piso_int.LoadTGA("Texturas/piso_int.tga");
	piso_int.BuildGLTexture();
	piso_int.ReleaseImage();

	poste_text.LoadTGA("Texturas/poste_text.tga");
	poste_text.BuildGLTexture();
	poste_text.ReleaseImage();

	madera_text.LoadBMP("Texturas/madera.bmp");
	madera_text.BuildGLTexture();
	madera_text.ReleaseImage();


	objCamera.Position_Camera(0,2.5,3, 0,2.5f,0, 0, 1, 0);

	/////////////////////////////////////////////////////////////////


	KeyFrame[0].posX = -8.1;
	KeyFrame[0].posY = 2;
	KeyFrame[0].posZ = 0;
	KeyFrame[0].giroMonito = 90;


	KeyFrame[1].posX = 20;
	KeyFrame[1].posY = 2;
	KeyFrame[1].posZ = 0;
	KeyFrame[1].giroMonito = 90;

	KeyFrame[2].posX = 40;
	KeyFrame[2].posY = 2;
	KeyFrame[2].posZ = 0;
	KeyFrame[2].giroMonito = 90;


	KeyFrame[3].posX = 40;
	KeyFrame[3].posY = 2;
	KeyFrame[3].posZ = 00;
	KeyFrame[3].giroMonito = 270;


	KeyFrame[4].posX = 12;
	KeyFrame[4].posY = 2;
	KeyFrame[4].posZ = 5;
	KeyFrame[4].giroMonito = 0;


}
void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		//Camara Sintetica

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	
		  
		glPushMatrix();	

		if (luz){
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				glColor3f(1.0, 1.0, 1.0);
				sky.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
				glColor3f(1.0,1.0,1.0);
			glPopMatrix();
			glEnable(GL_LIGHT1);
			}

		if (luz == false) {
			glDisable(GL_LIGHT1);
		}
	
			
				glPushMatrix();
				glTranslatef(45, 0.0, -15.0);
				glTranslatef((GLfloat)movhoriz + movhoriz2, 0, (GLfloat)moverti + moverti2);
				glRotatef((GLfloat)movimiento_horiz, 0.0, 1.0, 0.0);
				glTranslatef(3.0, 0.0, 0.0);
				glPushMatrix();
				glScalef(0.8, 0.8, 0.8);
				glTranslatef(0.0, 2.5, 0.0);
				persona();
				glPopMatrix();
				glTranslatef(0, 0, 0);
				fig.esfera(0.4, 50, 50, Porche.GLindex);
				glPopMatrix();
				movhoriz = (movhoriz + 0.0016);
				moverti = (moverti - 0.0009);
				movimiento_horiz = (movimiento_horiz + 1) % 360;
				glutPostRedisplay();
			
		
			glPushMatrix();
				glTranslatef(0.0, 0.0, -7.0);
				glRotatef(-90.0,0.0,1.0,0.0);
				pat_trasero();
				pajaro();
			glPopMatrix();

				glPushMatrix();
				glTranslatef(5, 3, -15);
				
				lampara();
				glPopMatrix();

				glPushMatrix();
				mago();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(3.6, -1.7, 30);
				glScalef(1.6, 2.6, 0.6);
				glRotatef(180, 0, 1, 0);
				dibujarCirco();
				glPopMatrix();

		glPopMatrix();
		
	glPopMatrix();

	glutSwapBuffers ( );

}
void animacion()
{
	//Movimiento del monito
	if (play)
	{
		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();
			}
		}
		else
		{
			//Draw animation
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			giroMonito += KeyFrame[playIndex].giroMonitoInc;


			i_curr_steps++;
		}

	}

	if (g_fanimacion)
	{
		if (g_avanza)
		{
			movaspZ += 0.00000003;

			if (movaspZ>130)
				g_avanza = false;
		}
		else
		{
			movaspZ -= 0.00000003;
			if (movaspZ<0)
				g_avanza = true;
		}
	}

	if (circuito)
	{
		if (recorrido1)
		{
			movaspX++;
			if (movaspX > 4)
			{
				recorrido1 = false;
				recorrido2 = true;
			}
		}
		if (recorrido2)
		{
			movaspZ--;
			if (movaspZ < -4)
			{
				recorrido2 = false;
				recorrido3 = true;

			}
		}
		if (recorrido3)
		{
			movaspX--;
			if (movaspX < 0)
			{
				recorrido3 = false;
				recorrido4 = true;

			}
		}
		if (recorrido4)
		{
			movaspX++;
			if (movaspX >4)
			{
				recorrido4 = false;
				recorrido5 = true;
			}
		}
		if (recorrido5)
		{
			movaspZ--;
			if (movaspZ < -15)
			{
				recorrido5 = false;
			}
		}

	}

	if (auxball)
	{
		if (ballx<8.5)
		{
			ballx += .2;
			movball += .2;
			rotball += 2;
		}
		if (ballx>8.5&&ballx<9)
		{
			ballx += .2;
			trasball += .1;
			movball += .2;
			rotball += 2;
		}
		if (trasball>0.6 && ballx>9)
		{
			ballx += .2;
			trasball -= .2;
			movball += .5;
			rotball += 2;
		}
	}

	if (ani_pajaro) {
		if (aletear) {
			mov_alas += 4.0;
			mov_alas2 -= 4.0;
			if (mov_alas >= 56 & mov_alas2 <= -58) {
				aletear = false;
				aletear2 = true;
			}
		}
		if (aletear2) {
			mov_alas -= 4.0;
			mov_alas2 += 4.0;
			if (mov_alas <= -56 & mov_alas2 >= 58) {
				aletear = true;
				aletear2 = false;
			}
		}

	}

	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;
	if (dwElapsedTime >= 30)
	{
		sol = (sol + 5) % 360;
		luna_rot = (luna_rot + 7) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (recorrido) {
		if (reco_pajaro1) {
			rotbird = 90;
			mov_pajarox += 0.3675;
			mov_pajaroy += 0.25;
			if (mov_pajaroy > 6.05) {
				reco_pajaro1 = false;
				reco_pajaro2 = true;
			}

		}
		if (reco_pajaro2) {
			mov_pajarox -= 0.15;
			if (mov_pajarox <= -10) {
				reco_pajaro2 = false;
				reco_pajaro3 = true;
			}
		}
		if (reco_pajaro3) {
			mov_pajaroy -= 0.15;
			if (mov_pajaroy <= 1.5) {
				reco_pajaro3 = false;
				reco_pajaro4 = true;
			}
		}
		if (reco_pajaro4) {
			rotbird = -115;
			mov_pajaroz += 0.15;
			mov_pajarox += 0.0999;
			if (mov_pajaroz >= 10) {
				reco_pajaro4 = false;
				reco_pajaro5 = true;
			}

		}
		if (reco_pajaro5) {
			rotbird = 90;
			mov_pajaroz -= 0.15;
			if (mov_pajaroz <= -5) {
				reco_pajaro5 = false;
				reco_pajaro1 = true;
				mov_pajarox = 0;
				mov_pajaroy = 0;
				mov_pajaroz = 0;

			}
		}
	}


	if (reco) {
		objCamera.Position_Camera(0, 2.5, 3, 0, 2.5f, 0, 0, 1, 0);

		for (i = 0; i < 10; i++) {
			objCamera.Position_Camera(0 + ii, 2.5, 3, 0, 2.5f, 0, 0, 1, 0);

		}
	}

	glutPostRedisplay();
}
void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}
void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'Z':
			luz = true;
			break;

		case 'z':
			luz = false;
			break;


		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera(-(CAMERASPEED - 0.4));
			break;

		case 'o'://///vista cuidador elefantes
		case 'O':
			objCamera.Position_Camera(0, 2.5, 3, 0, 2.5f, 0, 0, 1, 0);
			break;
		case 'p'://///vista elefantes
		case 'P':
			objCamera.Position_Camera(20, 2.5, 40, 0, 2.5f, 0, 0, 1, 0);
			break;
		case 'u'://////entrada
		case 'U':
			objCamera.Position_Camera(-1, 2.5, -45, 0, 2.5f,0, 0, 1, 0);
			break;

		case 'R'://////entrada
		case 'r':
		 

			objCamera.Position_Camera(0, 2.5, 3, 0, 2.5f, 0, 0, 1, 0);
		
			break;

		case 'X'://////entrada
		case 'x':
			reco ^= true;
			
			
			break;
		

		case 'm':
		case 'M':
			ani_pajaro ^= true;
			recorrido ^= true;
			break;

			break;
		case 'i':		//  
		case 'I':
			circuito ^= true; //Activamos/desactivamos la animacÃ­on
			g_fanimacion = false;
			break;
		case 'l':
		case 'L':      //animacion elefantes
			if (play == false && (FrameIndex>1))
			{

				resetElements();
							
				interpolation();

				play = true;
				playIndex = 0;
				i_curr_steps = 0;
			}
			else
			{
				play = false;
			}
			break;
		case 'b':   //animacion bola canon
		case 'B':
			auxball ^= true;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}
void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex<MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex >1)
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}

int main ( int argc, char** argv )   // Main Function
{
	

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (2000, 2000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Circo"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     (arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );

  PlaySound(TEXT("muscirco.wav"), NULL, SND_LOOP || SND_SYNC); //sonido de fondo
  glutMainLoop        ( );          // 

  return 0;
}
