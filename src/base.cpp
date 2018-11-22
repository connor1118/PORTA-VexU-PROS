#include "main.h"

static int maxBaseVelocity = 200;
static int medBaseVelocity = 100;
static int slowBaseVelocity = 50;

//DEFINING MOTORS
Motor leftDrive(1, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);
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

void resetDrive()
{
  leftDrive.tare_position();
  leftDrive1.tare_position();
  rightDrive.tare_position();
  rightDrive1.tare_position();
}


//drive
void drive(int inches)
{
    int distance = inches*(360/14.125);
    leftDrive.move_relative(distance, medBaseVelocity);
    leftDrive1.move_relative(distance, medBaseVelocity);
    rightDrive.move_relative(distance, medBaseVelocity);
    rightDrive1.move_relative(distance, medBaseVelocity);
    int dist = distance;
    while(!((leftDrive.get_position() < dist+3) && (leftDrive.get_position() > dist-3)))
    {
      delay(2);
    }
  }


void turn(int degrees)
{
    //resetDrive();
    int target = degrees*2.5;

    leftDrive.move_relative(target, slowBaseVelocity);
    leftDrive1.move_relative(target, slowBaseVelocity);
    rightDrive.move_relative(-target, slowBaseVelocity);
    rightDrive1.move_relative(-target, slowBaseVelocity);
    while(!((leftDrive.get_position() < target+3) && (leftDrive.get_position() > target-3)))
    {
      delay(2);
    }
  }
