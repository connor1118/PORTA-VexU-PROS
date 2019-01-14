#include "main.h"

Motor rollers(6, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);

void rollerMotor(int power)
{
  rollers.move_velocity(power);
}

void intakeOP()
{
  if(controller.get_digital(DIGITAL_R1))
  {
    rollerMotor(200);
  }
  else if(controller.get_digital(DIGITAL_R2))
  {
    rollers.move_velocity(-200);
  }
  else
  {
    rollers.move_velocity(0);
  }
}

void intake()
{
  rollers.move_velocity(200);
}

void stopIntake()
{
  rollers.move_velocity(0);
}

void flip()
{
  rollers.move_velocity(-200);
}
void stopFlip()
{
  rollerMotor(0);
}
