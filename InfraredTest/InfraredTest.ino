int infraVal1;
int infraVal2;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  infraVal1 = analogRead(A0);
  infraVal2 = analogRead(A1);
  Serial.print(infraVal1);Serial.print(" ");Serial.println(infraVal2);
}
