
#include <Servo.h>

int F=2, B=3, R=4, L=5;
char command=0;
int pulse_time=50, cam_angle = 90;

Servo cam_servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  cam_servo.attach(6);

  pinMode(F, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(L, OUTPUT);

  cam_servo.write(cam_angle);
  delay(1000);
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

    case 'f':
      cam_angle -= 2;
    break;
    case 'b':
      cam_angle += 2;
    break;
  }

  cam_servo.write(cam_angle);

 if(cam_angle < 0){
  cam_angle = 0;
 }
 if(cam_angle > 180){
  cam_angle = 180;
 }
 
  
}
