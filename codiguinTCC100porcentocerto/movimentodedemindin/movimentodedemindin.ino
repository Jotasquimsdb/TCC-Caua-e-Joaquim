#include <Servo.h>
#include <Filters.h>

Servo Servo1; //dedao
Servo Servo5; //mindinho
Servo Servo2; //indicador
Servo Servo3; //médio
Servo Servo4; //anelar


FilterOnePole filtroSensor(LOWPASS, 0.45);   // Filtra o sinal do sensor
FilterOnePole filtroServo(LOWPASS, 0.80);    // Filtra o movimento do servo


void setup() {
  Serial.begin(115200);
 
  Servo5.attach(5);//pino minimo
  Servo4.attach(6);//pino anelar
  Servo3.attach(9);//pino medio
  Servo2.attach(10);//pino indicador
  Servo1.attach(11);//pino dedao
  Servo1.write(180);
  Servo2.write(80);
  Servo3.write(170);
  Servo4.write(170);
  Servo5.write(170);

}

void loop() {
  
  Serial.print(" 0 1023 700 800 830 ");//valor de referencia
  
  float valor = (analogRead(A7)); //valor leitura sensor

  filtroSensor.input(valor);
  float sinalF = filtroSensor.output();//filtro do sensor

  Serial.println(sinalF);//sinal filtrado

  float sinalmin = 130;//sinal minimo

 float sinalmax = 400;//sinal maximo
  
  float sinalvar = sinalmax - sinalmin;//variacao do sinal

 Serial.println(sinalvar);

  float angulacaopolegar = 110 + (sinalF - sinalmin) * (70.0 / sinalvar);

  float angulacaoindicador =  80 - (sinalF - sinalmin) * (70.0 / sinalvar) ; 

  float angulacaomedio =  100 + (sinalF - sinalmin) * (80.0 / sinalvar); 

  float angulacaoanelar =  110 + (sinalF - sinalmin) * (50.0 / sinalvar); 

  float angulacaominimo = 120 + (sinalF - sinalmin) * (50.0 / sinalvar); 

  angulacaopolegar = round(angulacaopolegar);
  angulacaoindicador = round(angulacaoindicador);
  angulacaomedio = round(angulacaomedio);
  angulacaoanelar = round(angulacaomedio);
  angulacaominimo = round(angulacaominimo);

  angulacaominimo = constrain(angulacaominimo, 110, 180);
  angulacaoindicador = constrain(angulacaoindicador, 0, 90);
  angulacaomedio = constrain(angulacaoindicador, 90, 180);
  angulacaoanelar = constrain(angulacaoindicador, 130, 180);
  angulacaopolegar = constrain(angulacaopolegar, 60, 180);

  filtroServo.input(angulacaominimo);
  filtroServo.input(angulacaoindicador);
  filtroServo.input(angulacaomedio);
  filtroServo.input(angulacaoanelar);
  filtroServo.input(angulacaopolegar);

 int servomexerminimo = filtroServo.output();
 int servomexerindicador = filtroServo.output();
 int servomexermedio = filtroServo.output();
 int servomexeranelar = filtroServo.output();
 int servomexerpolegar = filtroServo.output();


  Servo1.write(servomexerminimo);
 // Serial.println(servomexerminimo);

  Servo2.write(servomexerindicador);
 // Serial.println(servomexerindicador);

  Servo3.write(servomexermedio);
 // Serial.println(servomexermedio);

  Servo4.write(servomexeranelar);
//  Serial.println(servomexeranelar);

  Servo5.write(servomexerpolegar);
 // Serial.println(servomexerpolegar);
  
  delay(10);
}