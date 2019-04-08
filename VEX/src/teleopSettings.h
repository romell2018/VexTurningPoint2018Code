#include <API.h>
#include <motors.h>
#include <joystick.h>

void ArcadeDrive(){
  //motor port,joystick value(controller port, axis) + joystick value(controller port, axis)
  motorSet(FRONT_LEFT, joystickGetAnalog(MAIN, AXIS_THREE) + joystickGetAnalog(MAIN, AXIS_ONE));
  motorSet(BACK_LEFT, joystickGetAnalog(MAIN, AXIS_THREE) + joystickGetAnalog(MAIN, AXIS_ONE));
  motorSet(FRONT_RIGHT, joystickGetAnalog(MAIN, AXIS_THREE) - joystickGetAnalog(MAIN, AXIS_ONE));
  motorSet(BACK_RIGHT, joystickGetAnalog(MAIN, AXIS_THREE) - joystickGetAnalog(MAIN, AXIS_ONE));
}
void Lift(){

  if(joystickGetDigital(MAIN, BUTTON_SEVEN, JOY_UP))
    {
      //motor port,speed
      motorSet(LIFT, 50);
    }
    else if(joystickGetDigital(MAIN, BUTTON_SEVEN, JOY_DOWN))
    {
      motorSet(LIFT, -50);
    }
  else
    {
      motorSet(LIFT, 0);
    }
}
