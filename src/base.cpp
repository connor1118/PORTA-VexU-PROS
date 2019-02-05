#include "main.h"

static int maxBaseVelocity = 200;
static int highBaseVelocity = 150;
static int medBaseVelocity = 100;
static int slowBaseVelocity = 50;
static int brakeBaseVelocity = -20;

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

void left(int speed)
{
  leftDrive.move_velocity(speed);
  leftDrive1.move_velocity(speed);
}

void right(int speed)
{
  rightDrive.move_velocity(speed);
  rightDrive1.move_velocity(speed);
}

void leftSlew(int slewSpeed)
{
  int speed = 0;
  int steppingSpeed;
  int step = 5;

  if(speed < slewSpeed)
  {
    speed += step;
  }
  else if(speed > slewSpeed)
  {
    left(slewSpeed);
  }
}

//drive
void drive(int inches)
{
  resetDrive();
  int distance = inches*(360/14.125);

   if(distance > 0)
    {
      leftDrive.move_velocity(highBaseVelocity);
      leftDrive1.move_velocity(highBaseVelocity);
      rightDrive.move_velocity(highBaseVelocity);
      rightDrive1.move_velocity(highBaseVelocity);

      while(leftDrive.get_position() < distance-400)
      {
        delay(2);
      }
      leftDrive.move_velocity(slowBaseVelocity);
      leftDrive1.move_velocity(slowBaseVelocity);
      rightDrive.move_velocity(slowBaseVelocity);
      rightDrive1.move_velocity(slowBaseVelocity);


      while(leftDrive.get_position() < distance)
      {
        delay(2);
      }

      leftDrive.move_velocity(brakeBaseVelocity);
      leftDrive1.move_velocity(brakeBaseVelocity);
      rightDrive.move_velocity(brakeBaseVelocity);
      rightDrive1.move_velocity(brakeBaseVelocity);

      delay(10);

      leftDrive.move_velocity(0);
      leftDrive1.move_velocity(0);
      rightDrive.move_velocity(0);
      rightDrive1.move_velocity(0);
    }

    if(distance < 0)
    {
      leftDrive.move_velocity(-highBaseVelocity);
      leftDrive1.move_velocity(-highBaseVelocity);
      rightDrive.move_velocity(-highBaseVelocity);
      rightDrive1.move_velocity(-highBaseVelocity);

      while(leftDrive.get_position() > distance+400)
      {
        delay(2);
      }
      leftDrive.move_velocity(-slowBaseVelocity);
      leftDrive1.move_velocity(-slowBaseVelocity);
      rightDrive.move_velocity(-slowBaseVelocity);
      rightDrive1.move_velocity(-slowBaseVelocity);


      while(leftDrive.get_position() > distance)
      {
        delay(2);
      }

      leftDrive.move_velocity(-brakeBaseVelocity);
      leftDrive1.move_velocity(-brakeBaseVelocity);
      rightDrive.move_velocity(-brakeBaseVelocity);
      rightDrive1.move_velocity(-brakeBaseVelocity);

      delay(10);

      leftDrive.move_velocity(0);
      leftDrive1.move_velocity(0);
      rightDrive.move_velocity(0);
      rightDrive1.move_velocity(0);
    }
}

void drivePID(int inches)
{
  resetDrive();
    int distance = inches*(360/14.125);
    int prevError = 0;
    int sp = distance;

    double kp = .3;
    double kd = .5;

    while(leftDrive.get_position() < distance - 5 || leftDrive.get_position() > distance + 5)
    {
      int ls = leftDrive.get_position();
      int rs = rightDrive.get_position();
      int sv = ls;

      //speed
      int error = sp-sv;
      int derivative = error - prevError;
      prevError = error;
      int speed = error*kp + derivative*kd;

      if(speed > highBaseVelocity)
      {
        speed = highBaseVelocity;
      }
      if(speed < -highBaseVelocity)
      {
        speed = -highBaseVelocity;
      }

      left(speed);
      right(speed);

      delay(20);
    }
}

void driveHard(int inches)
{
  resetDrive();
  int distance = inches*(360/14.125);
  if(distance > 0)
  {
    leftDrive.move_velocity(maxBaseVelocity);
    leftDrive1.move_velocity(maxBaseVelocity);
    rightDrive.move_velocity(maxBaseVelocity);
    rightDrive1.move_velocity(maxBaseVelocity);

    while(leftDrive.get_position() < distance)
    {
      delay(2);
    }

    leftDrive.move_velocity(brakeBaseVelocity);
    leftDrive1.move_velocity(brakeBaseVelocity);
    rightDrive.move_velocity(brakeBaseVelocity);
    rightDrive1.move_velocity(brakeBaseVelocity);

    delay(10);

    leftDrive.move_velocity(0);
    leftDrive1.move_velocity(0);
    rightDrive.move_velocity(0);
    rightDrive1.move_velocity(0);
  }
  if(distance < 0)
  {
    leftDrive.move_velocity(-maxBaseVelocity);
    leftDrive1.move_velocity(-maxBaseVelocity);
    rightDrive.move_velocity(-maxBaseVelocity);
    rightDrive1.move_velocity(-maxBaseVelocity);

    while(leftDrive.get_position() > distance)
    {
      delay(2);
    }

    leftDrive.move_velocity(-brakeBaseVelocity);
    leftDrive1.move_velocity(-brakeBaseVelocity);
    rightDrive.move_velocity(-brakeBaseVelocity);
    rightDrive1.move_velocity(-brakeBaseVelocity);

    delay(10);

    leftDrive.move_velocity(0);
    leftDrive1.move_velocity(0);
    rightDrive.move_velocity(0);
    rightDrive1.move_velocity(0);
  }
}

void turn(int degrees)
{
  resetDrive();
  int target = degrees*2.35;



  /*  leftDrive.move_relative(target, slowBaseVelocity);
    leftDrive1.move_relative(target, slowBaseVelocity);
    rightDrive.move_relative(-target, slowBaseVelocity);
    rightDrive1.move_relative(-target, slowBaseVelocity);*/
    if(target > 0)
    {
      leftDrive.move_velocity(medBaseVelocity);
      leftDrive1.move_velocity(medBaseVelocity);
      rightDrive.move_velocity(-medBaseVelocity);
      rightDrive1.move_velocity(-medBaseVelocity);

      while(leftDrive.get_position() < target-300)
      {
        delay(2);
      }
      leftDrive.move_velocity(slowBaseVelocity);
      leftDrive1.move_velocity(slowBaseVelocity);
      rightDrive.move_velocity(-slowBaseVelocity);
      rightDrive1.move_velocity(-slowBaseVelocity);


      while(leftDrive.get_position() < target)
      {
        delay(2);
      }

      leftDrive.move_velocity(brakeBaseVelocity);
      leftDrive1.move_velocity(brakeBaseVelocity);
      rightDrive.move_velocity(-brakeBaseVelocity);
      rightDrive1.move_velocity(-brakeBaseVelocity);

      delay(10);

      leftDrive.move_velocity(0);
      leftDrive1.move_velocity(0);
      rightDrive.move_velocity(0);
      rightDrive1.move_velocity(0);
    }

    if(target < 0)
    {
      leftDrive.move_velocity(-medBaseVelocity);
      leftDrive1.move_velocity(-medBaseVelocity);
      rightDrive.move_velocity(medBaseVelocity);
      rightDrive1.move_velocity(medBaseVelocity);

      while(leftDrive.get_position() > target+300)
      {
        delay(2);
      }
      leftDrive.move_velocity(-slowBaseVelocity);
      leftDrive1.move_velocity(-slowBaseVelocity);
      rightDrive.move_velocity(slowBaseVelocity);
      rightDrive1.move_velocity(slowBaseVelocity);


      while(leftDrive.get_position() > target)
      {
        delay(2);
      }

      leftDrive.move_velocity(-brakeBaseVelocity);
      leftDrive1.move_velocity(-brakeBaseVelocity);
      rightDrive.move_velocity(brakeBaseVelocity);
      rightDrive1.move_velocity(brakeBaseVelocity);

      delay(10);

      leftDrive.move_velocity(0);
      leftDrive1.move_velocity(0);
      rightDrive.move_velocity(0);
      rightDrive1.move_velocity(0);
    }
  }
