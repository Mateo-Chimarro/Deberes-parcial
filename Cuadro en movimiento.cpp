#include <iostream>
#include <windows.h>
#include <time.h> // Librería para controlar el tiempo

void lineasV(int,int);
void lineasH(int,int);
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawBox(int x, int y, int width, int height) {
    for (int i = 0; i < height; ++i) {
        gotoxy(x, y + i);
        if (i == 0 || i == height - 1) {
            for (int j = 0; j < width; ++j) {
                std::cout << "-";
            }
        } else {
            std::cout << "|";
            gotoxy(x + width - 1, y + i);
            std::cout << "|";
        }
    }
}

void lineasV(int c,int f){
	int i;
	for(i=1;i<f;i++){
		gotoxy(c,i);
		printf("%c",186);
	}
}
void lineasH(int c,int f){
	int i;
	for(i=1;i<c;i++){
		gotoxy(i,f);
		printf("%c",205);
	}
}

int main() {
    int x = 10;         // Posición inicial en X
    int y = 5;          // Posición inicial en Y
    int width = 10;     // Ancho del cuadro
    int height = 5;     // Alto del cuadro
    int delay = 200;    // Retardo en milisegundos
    int step = 1;       // Paso de movimiento

    bool moveDown = true; // Indicador de movimiento hacia abajo
    bool moveRight = true; // Indicador de movimiento hacia la derecha

    while (true) {
    	lineasH(60,0);
		lineasH(60,19);
		lineasV(0,20);
		lineasV(59,20);
		gotoxy(0,0);
		printf("%c",201);
		gotoxy(0,19);
		printf("%c",200);
		gotoxy(59,0);
		printf("%c",187);
		gotoxy(59,19);
		printf("%c",188);
        drawBox(x, y, width, height);
        Sleep(delay); // Usar Sleep de la librería windows.h para el retraso en milisegundos

        if (moveDown) {
            y += step;
            if (y >= 20 - height) {
                moveDown = false;
            }
        } else {
            y -= step;
            if (y <= 0) {
                moveDown = true;
            }
        }

        if (moveRight) {
            x += step;
            if (x >= 60 - width) {
                moveRight = false;
            }
        } else {
            x -= step;
            if (x <= 0) {
                moveRight = true;
            }
        }

        system("cls"); // Limpiar la pantalla antes de redibujar
    }

    return 0;
}
