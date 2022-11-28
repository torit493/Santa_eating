#include "func.h"

void setup() {
  l_arm.attach(l_arm_p);
  r_shoulder.attach(r_shoulder_p);
  r_elbow.attach(r_elbow_p);
  nod.attach(nod_p);

  l_arm.write(z_deg);
  r_shoulder.write(z_deg);
  r_elbow.write(z_deg);

  Serial.begin(9600);
  began_eating    = millis();
  began_eating_2  = millis();

  
  current_shoulder_deg  = z_deg;
  current_elbow_deg     = z_deg;
}

void loop() {
  for (int i = 0; i < 2; i++){
    Serial.println("Eating");    
    while (current_shoulder_deg > z_deg){
      current_shoulder_deg -= 2;
      current_elbow_deg += 1;
      r_elbow.write(current_elbow_deg);
      r_shoulder.write(current_shoulder_deg);
      delay(eat_t/shoulder_deg);
    }
    delay(1000);
    while (current_shoulder_deg < shoulder_deg + z_deg){
      current_shoulder_deg += 2;
      current_elbow_deg -= 1;
      r_elbow.write(current_elbow_deg);
      r_shoulder.write(current_shoulder_deg);
      delay(eat_t/shoulder_deg);
    }
    delay(1000);
  }
  Serial.println("Wave");
  moveLimb(nod, look_ahead, look_t);
  delay(1000);
  for (int i = z_deg + look_ahead; i < z_deg + nod_deg; i++){
    nod.write(i);
    delay(20);
  }
  for (int i = z_deg + nod_deg; i > z_deg + look_ahead; i--){
    nod.write(i);
    delay(20);
  }
  delay(500);
  removeLimb(nod, look_ahead, look_t);
  began_eating = millis();
}
