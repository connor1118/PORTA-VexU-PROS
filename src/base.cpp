#include "main.h"

static int maxBaseVelocity = 200;
//DEFINING MOTORS
Motor leftDrive(1, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES);
Motor leftDrive1(2, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES);

Motor rightDrive(3, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);
Motor rightDrive1(4, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);

void driveOP()
{
  leftDrive.move(controller.get_analog(ANALOG_LEFT_Y));
  leftDrive1.move(controller.get_analog(ANALOG_LEFT_Y));
  rightDrive.move(controller.get_analog(ANALOG_RIGHT_Y));
  rightDrive1.move(controller.get_analog(ANALOG_RIGHT_Y));
}
//drive
void drive(int distance)
{
  leftDrive.move_relative(distance, maxBaseVelocity);
  leftDrive1.move_relative(distance, maxBaseVelocity);
  rightDrive.move_relative(distance, maxBaseVelocity);
  rightDrive1.move_relative(distance, maxBaseVelocity);

  while(!((leftDrive.get_position() < distance+3) && (leftDrive.get_position() > distance-3)))
  {
    delay(2);
  }
}

void turn(int degrees)
{
  double degreesToEncoder = 3.6;
  int target = degrees*degreesToEncoder;

  leftDrive.move_relative(target, maxBaseVelocity);
  leftDrive1.move_relative(target, maxBaseVelocity);
  rightDrive.move_relative(target, -maxBaseVelocity);
  rightDrive1.move_relative(target, -maxBaseVelocity);

  while(!((leftDrive.get_position() < target+3) && (leftDrive.get_position() > tarhet-3)))
  {
    delay(2);
  }
}
