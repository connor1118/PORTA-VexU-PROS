#ifndef _BASE_H_
#define _BASE_H_






void driveOP();

void driveNoPID(int inches);
void drive(int inches);
void driveHard(int inches);
void turn(int degrees);
void turnNoPID(int degrees);

void brake();
void coast();

void resetDrive();


#endif
