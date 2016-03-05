#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "tinyxml\tinystr.h"
#include "tinyxml\tinyxml.h"
using namespace std;

TiXmlDocument file;
vector<float> triangulos;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if (h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);


	// put the geometric transformations here
	glutPostRedisplay();

	for (int i = 0; i < (triangulos.size()); i += 9) {
		glBegin(GL_TRIANGLES);
		glVertex3f(triangulos[i], triangulos[i + 1], triangulos[i + 2]);
		glVertex3f(triangulos[i + 3], triangulos[i + 4], triangulos[i + 5]);
		glVertex3f(triangulos[i + 6], triangulos[i + 7], triangulos[i + 8]);
		glEnd();
		// End of frame
	}


	// End of frame
	glutSwapBuffers();
}





// write function to process menu events

// Read file

void readfile(const char* filename) {
	char *token, *aux;
	string line;
	ifstream file;
	file.open(filename);
	while (getline(file, line)) {
		aux = new char[line.length() + 1];
		strcpy(aux, line.c_str());
		token = strtok(aux, " / ");
		while (token != NULL)
		{
			string str(token);
			triangulos.insert(triangulos.end(), stof(str));
			token = strtok(NULL, " / ");
		}
	}
}


int main(int argc, char **argv) {

	// Readfile
	file = TiXmlDocument(argv[1]);
	bool aux = file.LoadFile();
	TiXmlElement* modelo = file.FirstChildElement()->FirstChildElement();
	while (modelo) {
		readfile(modelo->Attribute("file"));
		modelo = modelo->NextSiblingElement();
	}


	// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("CG@DI-UM");


	// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	// put here the registration of the keyboard and menu callbacks



	// put here the definition of the menu 

	// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// hipotese de desenhar os dois lados do circulo.... rever mais tarde.

	//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// enter GLUT's main cycle

	glutMainLoop();

	return 1;
}
