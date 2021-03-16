/* Include the HCPCA9685 library */
#include "HCPCA9685.h"

/* I2C slave address for the device/module. For the HCMODU0097 the default I2C address
   is 0x40 */
#define  I2CAdd 0x40

/* Create an instance of the library */
HCPCA9685 HCPCA9685(I2CAdd);

const int servo_gripper_parking_pos = 63;

const int claw = 0;
const int wrist = 1;
const int elbow = 2;
const int knee = 4;

const int base_left = 5;
const int base_right = 7;

int servo_gripper_min_pos = 50;//10
int servo_gripper_max_pos = 70;//120

void setup() {
  /* Initialise the library and set it to 'servo mode' */
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);
  park();
}

void loop() {
  // put your main code here, to run repeatedly:
//    HCPCA9685.Servo(claw, 160);//smaller to close 80 is close
//    HCPCA9685.Servo(1, 180);
//    HCPCA9685.Servo(2, 180);
//    HCPCA9685.Servo(4, 200);
//    HCPCA9685.Servo(base_left, 130);//130-- straight up
//    HCPCA9685.Servo(base_right, 150);//150++ straight up

    delay(250);
}

void park(){
  HCPCA9685.Servo(base_left, 1);//130 -- 
  HCPCA9685.Servo(base_right, 300);//150 ++ 
  delay(500);
  HCPCA9685.Servo(knee, -40);
  delay(500);
  HCPCA9685.Servo(elbow, -40);
  delay(500);
  HCPCA9685.Servo(wrist, 380);
  delay(500);
  HCPCA9685.Servo(claw, 380);
  delay(500);
  HCPCA9685.Servo(claw, 50);
}
