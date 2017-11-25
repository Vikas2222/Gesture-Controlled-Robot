int X=A0, Y=A1, Z=A2;
int X_val=0, Y_val=0, Z_val=0;
char buffer[50];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(Z, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  X_val = analogRead(X);
  Y_val = analogRead(Y);
  Z_val = analogRead(Z);

  
  sprintf(buffer, "%d  %d  %d \n", X_val, Y_val, Z_val);
  Serial.print(buffer);
  delay(1000);
}
