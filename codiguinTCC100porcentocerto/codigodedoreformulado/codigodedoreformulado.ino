
void setup() {
  Serial.begin(115200);
}

void loop() {
  float valorBruto = analogRead(A7);
  Serial.print(valorBruto);
  delay(10);
}