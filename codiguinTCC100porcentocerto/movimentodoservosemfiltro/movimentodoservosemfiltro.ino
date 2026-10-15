#include <Servo.h>
#include <Filters.h>

Servo Servo1; //dedao
Servo Servo5; //mindinho


FilterOnePole filtroSensor(LOWPASS, 0.45);   // Filtra o sinal do sensor
FilterOnePole filtroServo(LOWPASS, 0.80);    // Filtra o movimento do servo

void setup() {
  Serial.begin(115200);
 
  Servo1.attach(9);//pino dedao
  Servo5.attach(3);//pino mindinho
  Servo1.write(0);
  Servo5.write(0);

}

void loop() {
  
  Serial.print(" 0 1023 700 800 830 ");//valor de referencia
  
  float valor = (analogRead(A1)); //valor leitura sensor

  filtroSensor.input(valor);
  float sinalF = filtroSensor.output();//filtro do sensor

  Serial.println(sinalF);//sinal filtrado

  float sinalmin = 120;//sinal minimo

 float sinalmax = 200;//sinal maximo
  
  float sinalvar = sinalmax - sinalmin;//variacao do sinal

 Serial.println(sinalvar);

 float angulacaominimo = 110 + (sinalF - sinalmin) * (70.0 / sinalvar); 

  float angulacaopolegar = 60 + (sinalF - sinalmin) * (70.0 / sinalvar);

  angulacaominimo = round(angulacaominimo);
  angulacaopolegar = round(angulacaopolegar);

  angulacaominimo = constrain(angulacaominimo, 110, 180);
  angulacaopolegar = constrain(angulacaopolegar, 60, 180);

  filtroServo.input(angulacaominimo);
  filtroServo.input(angulacaopolegar);

 int servomexerminimo = filtroServo.output();
 int servomexerpolegar = filtroServo.output();


  Servo1.write(servomexerminimo);
  Serial.println(servomexerminimo);

  Serial.println(servomexerpolegar);
  Servo5.write(servomexerpolegar);
  
  delay(10);
}