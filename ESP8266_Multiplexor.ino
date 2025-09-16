// codigo que utilizamos para hacer que el wemos, a traves del multiplexor, pueda mostrarnos los valores de cada potenciometro: 
// Pines de control del multiplexor
#define S0 D1
#define S1 D2
#define S2 D3
#define S3 D4
#define SIG A0 // Señal que viene del multiplexor

// Función para leer un canal del multiplexor
int leerMux(byte canal) {
digitalWrite(S0, canal & 0x01);
digitalWrite(S1, (canal >> 1) & 0x01);
digitalWrite(S2, (canal >> 2) & 0x01);
digitalWrite(S3, (canal >> 3) & 0x01);
delayMicroseconds(5); // tiempo de estabilización
return analogRead(SIG);
}

void setup() {
Serial.begin(115200);
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);
}

void loop() {
int indice = leerMux(0);
int medio = leerMux(1);
int anular = leerMux(2);
int menique = leerMux(3);
int pulgar = leerMux(4);

Serial.print("Indice: "); Serial.print(indice);
Serial.print(" | Medio: "); Serial.print(medio);
Serial.print(" | Anular: "); Serial.print(anular);
Serial.print(" | Menique: "); Serial.print(menique);
Serial.print(" | Pulgar: "); Serial.println(pulgar);

delay(200); // Ajusta el tiempo de lectura
}
