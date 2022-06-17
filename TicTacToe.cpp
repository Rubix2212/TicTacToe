#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::system;

void inicializar_tablero(char tablero[][3]);
void mostrar_tablero(char tablero[][3]);
bool verificar(char tablero[][3], char ficha);
int colocarficha(char tablero[][3], char ficha, int huecos);

int main() {
  bool pos = 0;
  char ficha;
  char tablero[3][3];
  int nhuecos = 9;
  bool gana = false;
  char fichas[] = {'X', 'O'};

  inicializar_tablero(tablero);

  do {
    ficha = fichas[pos];
    mostrar_tablero(tablero);
    colocarficha(tablero, ficha, nhuecos);
    pos = !pos;
    gana = verificar(tablero, ficha);
  } while (!gana && nhuecos != 0);

  if (gana) puts("Gano");
  else puts("Hubo tablas");
  return 0;
}

int colocarficha(char tablero[][3], char ficha, int huecos) {
  int x, y;

  do {
    cout << "Turn of " << ficha << endl
         << "Coordinate Y:";
    cin >> x;
    cout << "Coordinate X:";
    cin >> y;
    if (tablero[x - 1][y - 1] != '_')
      cout << "Position occupied, try again" << endl;
  } while (x < 1 || x > 3 || y < 1 || y > 3 || tablero[x - 1][y - 1] != '_');

  tablero[x - 1][y - 1] = ficha;
  huecos--;
  return huecos;
}

void inicializar_tablero(char tablero[][3]) {
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      tablero[x][y] = '_';
    }
  }
}

void mostrar_tablero(char tablero[][3]) {
  system("cls");

  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      cout << tablero[x][y] << "  ";
    }
    cout << endl
         << endl;
  }
}

bool verificar(char tablero[][3], char ficha) {
  bool retval = false;

  for (int a = 0; a < 3; a++) {
    if (tablero[0][a] == ficha && tablero[0][a] == tablero[1][a] && tablero[1][a] == tablero[2][a]) {
      retval = true;
      break;
    }
  }

  for (int a = 0; a < 3; a++) {
    if (tablero[a][0] == ficha && tablero[a][0] == tablero[a][1] && tablero[a][1] == tablero[a][2]) {
      retval = true;
      break;
    }
  }

  if (tablero[0][0] == ficha && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
    retval = true;
  }

  if (tablero[0][2] == ficha && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
    retval = true;
  }
  return retval;
}