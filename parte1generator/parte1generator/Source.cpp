#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

void geraPlano(float comp, float larg, char *file) {
	FILE *fp = fopen(file, "w");
	float x = comp / 2, y = larg / 2;
	fprintf(fp, "%f / %f / %f\n", x, -y, 0.0);
	fprintf(fp, "%f / %f / %f\n", x, y, 0.0);
	fprintf(fp, "%f / %f / %f\n", -x, -y, 0.0);
	fprintf(fp, "%f / %f / %f\n", -x, -y, 0.0);
	fprintf(fp, "%f / %f / %f\n", x, y, 0.0);
	fprintf(fp, "%f / %f / %f\n", -x, y, 0.0);
	fclose(fp);
}

void geraParalelepipedo(float larg, float comp, float alt, char* file) {
	FILE *fp = fopen(file, "w");
	float x = larg / 2, y = alt / 2, z = comp / 2;
	fprintf(fp, "%f / %f / %f\n", -x, -y, z);
	fprintf(fp, "%f / %f / %f\n", x, -y, z);
	fprintf(fp, "%f / %f / %f\n", x, y, z);
	fprintf(fp, "%f / %f / %f\n", -x, -y, z);
	fprintf(fp, "%f / %f / %f\n", x, y, z);
	fprintf(fp, "%f / %f / %f\n", -x, y, z);
	//frente
	fprintf(fp, "%f / %f / %f\n", x, -y, -z);
	fprintf(fp, "%f / %f / %f\n", -x, -y, -z);
	fprintf(fp, "%f / %f / %f\n", x, y, -z);
	fprintf(fp, "%f / %f / %f\n", -x, -y, -z);
	fprintf(fp, "%f / %f / %f\n", -x, y, -z);
	fprintf(fp, "%f / %f / %f\n", x, y, -z);
	//tras
	fprintf(fp, "%f / %f / %f\n", -x, -y, z);
	fprintf(fp, "%f / %f / %f\n", -x, y, z);
	fprintf(fp, "%f / %f / %f\n", -x, -y, -z);
	fprintf(fp, "%f / %f / %f\n", -x, -y, -z);
	fprintf(fp, "%f / %f / %f\n", -x, y, z);
	fprintf(fp, "%f / %f / %f\n", -x, y, -z);
	//esquerda
	fprintf(fp, "%f / %f / %f\n", x, y, z);
	fprintf(fp, "%f / %f / %f\n", x, -y, z);
	fprintf(fp, "%f / %f / %f\n", x, y, -z);
	fprintf(fp, "%f / %f / %f\n", x, y, -z);
	fprintf(fp, "%f / %f / %f\n", x, -y, z);
	fprintf(fp, "%f / %f / %f\n", x, -y, -z);
	//direita
	fprintf(fp, "%f / %f / %f\n", -x, y, z);
	fprintf(fp, "%f / %f / %f\n", x, y, z);
	fprintf(fp, "%f / %f / %f\n", -x, y, -z);
	fprintf(fp, "%f / %f / %f\n", -x, y, -z);
	fprintf(fp, "%f / %f / %f\n", x, y, z);
	fprintf(fp, "%f / %f / %f\n", x, y, -z);
	//cima
	fprintf(fp, "%f / %f / %f\n", -x, -y, z);
	fprintf(fp, "%f / %f / %f\n", x, -y, -z);
	fprintf(fp, "%f / %f / %f\n", x, -y, z);
	fprintf(fp, "%f / %f / %f\n", -x, -y, z);
	fprintf(fp, "%f / %f / %f\n", -x, -y, -z);
	fprintf(fp, "%f / %f / %f\n", x, -y, -z);
	//baixo
	fclose(fp);
}


void geraEsfera(float raio, int nFatias, int nCamadas, char* file) {
	FILE *fp = fopen(file, "w");
	float fatias = (float)nFatias, camadas = (float)nCamadas;
	float anguloX = (2 * M_PI) / fatias;
	float anguloY = M_PI / camadas;
	float x = 0.0, y = -M_PI / 2;;
	for (int i = 1; i<fatias + 1; i++) {

		fprintf(fp, "%f / %f / %f\n", 0.0, -raio, 0.0);
		fprintf(fp, "%f / %f / %f\n", raio*cos(y + anguloY)*sin(x + i*anguloX), raio*sin(y + anguloY), raio*cos(y + anguloY)*cos(x + i*anguloX));
		fprintf(fp, "%f / %f / %f\n", raio*cos(y + anguloY)*sin(x + (i - 1)*anguloX), raio*sin(y + anguloY), raio*cos(y + anguloY)*cos(x + (i - 1)*anguloX));


		for (int j = 2; j<camadas; j++) {
			fprintf(fp, "%f / %f / %f\n", raio*cos(y + (j - 1)*anguloY)*sin(x + (i - 1)*anguloX), raio*sin(y + (j - 1)*anguloY), raio*cos(y + (j - 1)*anguloY)*cos(x + (i - 1)*anguloX));
			fprintf(fp, "%f / %f / %f\n", raio*cos(y + (j - 1)*anguloY)*sin(x + i*anguloX), raio*sin(y + (j - 1)*anguloY), raio*cos(y + (j - 1)*anguloY)*cos(x + i*anguloX));
			fprintf(fp, "%f / %f / %f\n", raio*cos(y + j*anguloY)*sin(x + i*anguloX), raio*sin(y + j*anguloY), raio*cos(y + j*anguloY)*cos(x + i*anguloX));

			fprintf(fp, "%f / %f / %f\n", raio*cos(y + (j - 1)*anguloY)*sin(x + (i - 1)*anguloX), raio*sin(y + (j - 1)*anguloY), raio*cos(y + (j - 1)*anguloY)*cos(x + (i - 1)*anguloX));
			fprintf(fp, "%f / %f / %f\n", raio*cos(y + j*anguloY)*sin(x + i*anguloX), raio*sin(y + j*anguloY), raio*cos(y + j*anguloY)*cos(x + i*anguloX));
			fprintf(fp, "%f / %f / %f\n", raio*cos(y + j*anguloY)*sin(x + (i - 1)*anguloX), raio*sin(y + j*anguloY), raio*cos(y + j*anguloY)*cos(x + (i - 1)*anguloX));
		}

		fprintf(fp, "%f / %f / %f\n", raio*cos(y + (camadas - 1)*anguloY)*sin(x + (i - 1)*anguloX), raio*sin(y + (camadas - 1)*anguloY), raio*cos(y + (camadas - 1)*anguloY)*cos(x + (i - 1)*anguloX));
		fprintf(fp, "%f / %f / %f\n", raio*cos(y + (camadas - 1)*anguloY)*sin(x + i*anguloX), raio*sin(y + (camadas - 1)*anguloY), raio*cos(y + (camadas - 1)*anguloY)*cos(x + i*anguloX));
		fprintf(fp, "%f / %f / %f\n", 0.0, raio, 0.0);

	}
	fclose(fp);
}

void geraCone(float raio, float alt, int nFatias, int nCamadas, char* file) {
	FILE *fp = fopen(file, "w");
	float fatias = (float)nFatias, camadas = (float)nCamadas;
	double angulo = (2 * M_PI) / fatias;
	double razao, raio1, raio2 = raio;
	for (int i = 1; i<fatias + 1; i++) {
		fprintf(fp, "%f / %f / %f\n", 0.0, 0.0, 0.0);
		fprintf(fp, "%f / %f / %f\n", raio*sin(angulo*i), 0.0, raio*cos(angulo*i));
		fprintf(fp, "%f / %f / %f\n", raio*sin(angulo*(i - 1)), 0.0, raio*cos(angulo*(i - 1)));

		for (int j = 1; j<camadas; j++) {
			razao = (camadas - j) / camadas;
			raio1 = raio2;
			raio2 = raio*razao;

			fprintf(fp, "%f / %f / %f\n", raio1*sin(angulo*(i - 1)), alt*((j - 1) / camadas), raio1*cos(angulo*(i - 1)));
			fprintf(fp, "%f / %f / %f\n", raio1*sin(angulo*i), alt*((j - 1) / camadas), raio1*cos(angulo*i));
			fprintf(fp, "%f / %f / %f\n", raio2*sin(angulo*i), alt*(j / camadas), raio2*cos(angulo*i));

			fprintf(fp, "%f / %f / %f\n", raio1*sin(angulo*(i - 1)), alt*((j - 1) / camadas), raio1*cos(angulo*(i - 1)));
			fprintf(fp, "%f / %f / %f\n", raio2*sin(angulo*i), alt*(j / camadas), raio2*cos(angulo*i));
			fprintf(fp, "%f / %f / %f\n", raio2*sin(angulo*(i - 1)), alt*(j / camadas), raio2*cos(angulo*(i - 1)));
		}	
		fprintf(fp, "%f / %f / %f\n", raio2*sin(angulo*(i - 1)), alt*((camadas - 1) / camadas), raio2*cos(angulo*(i - 1)));
		fprintf(fp, "%f / %f / %f\n", raio2*sin(angulo*i), alt*((camadas - 1) / camadas), raio2*cos(angulo*i));
		fprintf(fp, "%f / %f / %f\n", 0.0, alt, 0.0);
		raio2 = raio;
	}
	fclose(fp);
}

int main(int argc, char** argv) {
	if (!strcmp(argv[1], "plano")) {
		geraPlano(atof(argv[2]), atof(argv[3]), argv[4]);
	}
	else if (!strcmp(argv[1], "paralelepipedo")) {
		geraParalelepipedo(atof(argv[2]), atof(argv[3]), atof(argv[4]), argv[5]);
	}
	else if (!strcmp(argv[1], "cone")) {
		geraCone(atof(argv[2]), atof(argv[3]), atoi(argv[4]), atoi(argv[5]), argv[6]);
	}
	else if (!strcmp(argv[1], "esfera")) {
		geraEsfera(atof(argv[2]), atoi(argv[3]), atoi(argv[4]), argv[5]);
	}
	else printf("Figura geométrica não reconhecida\n\n");
	return 0;
}