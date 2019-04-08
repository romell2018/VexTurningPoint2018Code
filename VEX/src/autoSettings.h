#include <API.h>
#include <motors.h>

#define IME_LEFT_MOTOR 0
#define IME_RIGHT_MOTOR 1

double leftPosition;
double rightPosition;

double errorL;
double errorR;
double sumErrorL;
double sumErrorR;
double kp = 0.0001;
double ki = 0.0000001;

void Output(double left, double right){
  motorSet(FRONT_LEFT, left);
  motorSet(BACK_LEFT, left);
  motorSet(FRONT_RIGHT, -right);
  motorSet(BACK_RIGHT, -right);
}

void DistancePIDDrive(double distance){
  imeGet(IME_LEFT_MOTOR, &leftPosition);
  imeGet(IME_RIGHT_MOTOR, &rightPosition);

  errorL = distance - leftPosition;
  errorR = distance - rightPosition;
  sumErrorL += errorL;
  sumErrorR += errorR;
  double outputL = (errorL * kp) + (sumErrorL * ki);
  double outputR = (errorR * kp) + (sumErrorR * ki);

  Output(outputL, outputR);
}
void ResetDriveEncoder(){
  imeReset(IME_LEFT_MOTOR);
  imeReset(IME_RIGHT_MOTOR);
}

void resetSensors(){}
void turn(int angle){}
void liftPID(){}
