int X=A0, Y=A1, Z=A2, th_pin=2, cam_pin=3;
int X_val=0, Y_val=0, Z_val=0;
int X_th=0, Y_th=0;

char buffer[50];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(Z, INPUT);
  pinMode(th_pin, INPUT);
  pinMode(cam_pin, INPUT);

  set_th(); 
  set_th(); 
}

void set_th(){
  X_th = analogRead(X);
  Y_th = analogRead(Y);
}

void loop() {
  // put your main code here, to run repeatedly:

  X_val = analogRead(X);
  Y_val = analogRead(Y);
  Z_val = analogRead(Z);

  if(X_val - X_th > 30){
    if(digitalRead(cam_pin)){
      Serial.print("F");
    }
    else{
      Serial.print("f");
    }
  }
  
  if(X_val - X_th < -30){
    
    if(digitalRead(cam_pin)){
     Serial.print("B");
    }
    else{
     Serial.print("b");
    }
  }

  if(Y_val - Y_th > 30){
  Serial.print("L");
  }
  if(Y_val - Y_th < -30){
  Serial.print("R");
  }
  
  sprintf(buffer, "%d  %d  %d  %d\n", X_val, Y_val, X_th, Y_th);
//  Serial.print(buffer);

  delay(100);
}
