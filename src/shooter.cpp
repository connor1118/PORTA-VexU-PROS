#include "main.h"

Motor shooter(5, MOTOR_GEARSET_36 , 0, MOTOR_ENCODER_DEGREES);
Motor shooter1(6, MOTOR_GEARSET_36, 0, MOTOR_ENCODER_DEGREES);

void shooterMotors(int power)
{
  shooter.move(power);
  shooter1.move(power);
}

void shooterOP()
{
  if(controller.get_digital(DIGITAL_L1))
  {
    shooterMotors(127);
  }
  else
  {
    shooterMotors(0);
  }
}

void shoot()
{
  shooterMotors(127);
  delay(.75);
}
