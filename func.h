#include <Servo.h>

// SERVOS: -----------------------------------
Servo l_arm;
Servo r_shoulder;
Servo r_elbow;
Servo nod;

// PINS: -------------------------------------
int l_arm_p     = 5;
int r_shoulder_p= 6;
int r_elbow_p   = 7;
int nod_p       = 8;

// DEGS: -------------------------------------
int nod_deg     = 5;
int shoulder_deg= 60;
int elbow_deg   = 22;
int z_deg       = 90;
int drink_deg   = -70;
int look_ahead  = -30;
int wave_deg    = -90;
int current_shoulder_deg  = z_deg;
int current_elbow_deg     = z_deg;


// SPEEDS: -----------------------------------
double eat_t = 2000; // ms used to lift arm
double look_t = 1000;
double wave_t = 1000;

// DELAY: ------------------------------------
int down_time = 120000; // 

// BOOL: -------------------------------------
bool food_in   = true;

// TIME: -------------------------------------
double began_eating = 0;
double began_eating_2 = 0;
double eating_duration = 10000;


void moveLimb(Servo aServo, double angle, double duration_ms){
  double to_delay = sqrt((duration_ms/angle)*(duration_ms/angle));
  if (angle >= 0){
    for (int i = z_deg; i < z_deg + angle; i++){
      aServo.write(i);
      delay(to_delay);
    }
  }else {
    for (int i = z_deg; i >= z_deg + angle; i--){
      aServo.write(i);
      delay(to_delay);
    }
  }
}

void removeLimb(Servo aServo, double angle, double duration_ms){
    double to_delay = sqrt((duration_ms/angle)*(duration_ms/angle));
  if (angle >= 0){
    for (int i = z_deg + angle; i >= z_deg; i--){
      aServo.write(i);
      delay(to_delay);
    }
  } else {
    for (int i = z_deg + angle; i < z_deg; i++){
      aServo.write(i);
      delay(to_delay);
    }
  }
}
