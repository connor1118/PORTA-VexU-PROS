#include "main.h"

Motor shooter(5, MOTOR_GEARSET_18 , 1, MOTOR_ENCODER_DEGREES);
Motor shooter1(7, MOTOR_GEARSET_18 , 0, MOTOR_ENCODER_DEGREES);

Motor adjuster(8, MOTOR_GEARSET_18 , 0, MOTOR_ENCODER_DEGREES);


void shooterMotors(int power)
{
  shooter.move_voltage(power);
  shooter1.move_voltage(power);
}

void shooterOP()
{
  if(controller.get_digital(DIGITAL_L1))
  {
    shooter.move_velocity(200);
    shooter1.move_velocity(200);
    delay(550);
    shooter.move_velocity(0);
    shooter1.move_velocity(0);
  }

}

bool adjPos;
void adjusterOP()
{
  if(controller.get_digital(DIGITAL_UP))
  {
    if(adjPos)
    {
      adjuster.move_velocity(200);
      delay(300);
      adjuster.move_velocity(0);
    }
    else
    {
      adjuster.move_velocity(-200);
      delay(300);
      adjuster.move_velocity(0);
    }
    adjPos = !adjPos;
  }
}

void shooterNoHold()
{
  shooter.set_brake_mode(MOTOR_BRAKE_COAST);
  shooter1.set_brake_mode(MOTOR_BRAKE_COAST);
}

void shoot()
{

  shooter.move_velocity(200);
  shooter1.move_velocity(200);
  delay(550);
  shooter.move_voltage(0);

  shooter.set_brake_mode(MOTOR_BRAKE_COAST);
  shooter1.set_brake_mode(MOTOR_BRAKE_COAST);

}

void adjust(bool up)
{
  if(up)
  {
    adjuster.move_velocity(-200);
    delay(300);
    adjuster.move_velocity(0);
  }
  else
  {
    adjuster.move_velocity(200);
    delay(300);
    adjuster.move_velocity(0);
  }
}
