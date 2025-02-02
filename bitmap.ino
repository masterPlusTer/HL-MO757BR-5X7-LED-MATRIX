

/*
tengo una matriz de 5x7 conectada a un arduino , las filas son los catodos y estan conectados asi fila 1 al D2 fila dos al D3 fila 3 al d4 fila 4 al d5 y fila 5 al d6 y las columnas son los anodos y estan conectados asi, columna uno al d7 columna dos al d8 columna 3 al d9 columna 4 al d10 columna 5 al d11 columna 6 al d 12 y columna 7 al d13 dame un codigo que me permita editando un bitmap de unos y ceros formar el dibujo que yo quiera en la matriz
*/


const int filas[5] = {2, 3, 4, 5, 6};      // Pines de las filas (Cátodos)
const int columnas[7] = {7, 8, 9, 10, 11, 12, 13}; // Pines de las columnas (Ánodos)

// Bitmap para dibujar una imagen en la matriz (1 = LED encendido, 0 = LED apagado)
byte bitmap[5][7] = {
  {0, 1, 1, 1, 1, 1, 0},  
  {1, 0, 0, 0, 0, 0, 1},  
  {1, 0, 1, 1, 1, 0, 1},  
  {1, 0, 0, 0, 0, 0, 1},  
  {0, 1, 1, 1, 1, 1, 0}
};

void setup() {
  // Configurar pines de filas como SALIDA
  for (int i = 0; i < 5; i++) {
    pinMode(filas[i], OUTPUT);
    digitalWrite(filas[i], HIGH); // Apagar inicialmente (Cátodo en HIGH)
  }
  
  // Configurar pines de columnas como SALIDA
  for (int i = 0; i < 7; i++) {
    pinMode(columnas[i], OUTPUT);
    digitalWrite(columnas[i], LOW); // Apagar inicialmente (Ánodo en LOW)
  }
}

void loop() {
  mostrarMatriz(); // Mostrar la imagen en la matriz
}

void mostrarMatriz() {
  for (int fila = 0; fila < 5; fila++) {
    digitalWrite(filas[fila], LOW);  // Activar fila (Cátodo a LOW)

    for (int col = 0; col < 7; col++) {
      digitalWrite(columnas[col], bitmap[fila][col] ? HIGH : LOW); // Encender/Apagar LED
    }

    delay(2);  // Pequeño retraso para evitar parpadeo
    digitalWrite(filas[fila], HIGH); // Desactivar fila (Cátodo a HIGH)
  }
}
