#include "main.h"

Motor shooter(5, MOTOR_GEARSET_18 , 1, MOTOR_ENCODER_DEGREES);

void shooterMotors(int power)
{
  shooter.move_voltage(power);
}

void shooterOP()
{
  if(controller.get_digital(DIGITAL_L1))
  {
    shooter.move_velocity(100);
  }
  else
  {
    shooter.move_velocity(0);
  }
}

void shoot()
{
  shooter.move_voltage(10000);
  delay(850);
  shooter.move_voltage(0);
}
