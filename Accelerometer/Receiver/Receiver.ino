
int F=3, B=4, R=5, L=6;
char command=0;
int pulse_time=10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(F, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(L, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  command = Serial.read();

  switch(command){
    case 'F':
       digitalWrite(F, HIGH);
       delay(pulse_time);
       digitalWrite(F, LOW);
    break;
    case 'B':
       digitalWrite(B, HIGH);
       delay(pulse_time);
       digitalWrite(B, LOW);
    break;
    case 'R':
       digitalWrite(R, HIGH);
       delay(pulse_time);
       digitalWrite(R, LOW);
    break;
    case 'L':
       digitalWrite(L, HIGH);
       delay(pulse_time);
       digitalWrite(L, LOW);
    break;
  }
  
}
