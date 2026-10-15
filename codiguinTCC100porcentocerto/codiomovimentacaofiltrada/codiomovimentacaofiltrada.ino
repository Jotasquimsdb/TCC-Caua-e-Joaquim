#include <Servo.h>
#include <Filters.h>

int anguservo = 180;
FilterOnePole filtroSensor(LOWPASS, 0.60);   // Filtra o sinal do sensor
FilterOnePole filtroSensoreee(LOWPASS, 0.45);   // Filtra o sinal do sensor

FilterOnePole filtroServo(LOWPASS, 0.60);    // Filtra o movimento do servo

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  Serial.print(" 0 1023 700  800  ");
  
  float valor = (analogRead(A7));

  Serial.println(valor);



 

  filtroSensor.input(valor);
  float sinalF = filtroSensor.output();

  Serial.println(sinalF);

  float sinalmin = min(sinalmin, sinalF);

  float sinalmax = max(sinalmax, sinalF);
  
  float sinalvar = sinalmax - sinalmin;

  float angulacao = (sinalF - sinalmin) * (anguservo/sinalvar);

  angulacao = round(angulacao);

  angulacao = constrain(angulacao, 0, anguservo);

  filtroServo.input(angulacao);

  float angulacaoF = filtroServo.output();

  Serial.println(angulacaoF);


  delay(10);
}