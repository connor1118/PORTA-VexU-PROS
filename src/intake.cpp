#include "main.h"

Motor rollers(7, MOTOR_GEARSET_36, 0, MOTOR_ENCODER_DEGREES);

void rollerMotor(int power)
{
  rollers.move(power)
}

void intakeOP()
{
  if(controller.get_digital(DIGITAL_R1))
  {
    rollerMotor(127);
  }
  else if(controller.get_digital(DIGITAL_R2))
  {
    rollerMotor(-127);
  }
  else
  {
    rollerMotor(0);
  }
}

void intake(int time)
{
  rollerMotor(127);
  delay(time);
}
