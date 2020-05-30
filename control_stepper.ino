#include <AccelStepper.h>
#define HALFSTEP 8

// Motor pin definitions
#define motorPin1  7     // IN1 on the ULN2003 driver 1
#define motorPin2  6     // IN2 on the ULN2003 driver 1
#define motorPin3  5     // IN3 on the ULN2003 driver 1
#define motorPin4  4     // IN4 on the ULN2003 driver 1

int position = 10000;

int i = 0;

int A[5] = {6400, 0, 150, 971, -12};

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(200.0);
  stepper1.setSpeed(400);
  Serial.begin(9600);
}

void loop() {
  stepper1.moveTo(position);
  stepper1.run();
  if(stepper1.distanceToGo() == 0 && i<5)
  {
    Serial.println("Vi tri tiep theo: ");
    position = A[i];
    Serial.println(position);
    i++;
  }
}
