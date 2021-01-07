
/*************************************
    ADAM'S ROBOT 2021
    STUDENT NUMBER ****807
 *************************************/

// import classes

#include "DC_Motors.h"

int PIN_IN1 = 2;
int PIN_IN2 = 3;
int PIN_IN3 = 5;
int PIN_IN4 = 4;

DCMotors dc_motors(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);

#include <Metro.h>
#include "GoBLE.h"

int joystickX, joystickY;
int buttonState[7];

void setup(){
  Goble.begin();
  Serial.begin(115200);
}

void loop() {  
  if (Goble.available()) { //check for a bluetooth connection to goBLE

    joystickX = Goble.readJoystickX(); //read joystick x value
    joystickY = Goble.readJoystickY(); //read joystick y value

    //use the serial monitor to debug
    //(x and y joystick values are from 0 - 255)


    //    Serial.print("Joystick Value: ");
    //    Serial.print(joystickX);
    //    Serial.print("  ");
    //    Serial.println(joystickY);

    if (joystickY > 196) { //if joystick y > 196 then turn right at speed 250
      Serial.println("turn right");
      dc_motors.Right(255);
    }
    else if (joystickY < 64) { // //if joystick y < 64 then turn left at speed 250
      Serial.println("turn left");
      dc_motors.Left(255);
    }
    else if (joystickX > 196) { //if joystick x > 196 then go forward at speed 500
      Serial.println("move forward");
      dc_motors.Forward(255);
    }
    else if (joystickX < 64) { //if joystick x <64 then go backward at speed 500
      Serial.println("move backward");
      dc_motors.Reverse(255);
    }
    else {
      dc_motors.Stop(); //or else stop
    }
  }
}
