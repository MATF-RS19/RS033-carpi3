#define FORWARD 40
#define LEFT 60
#define RIGHT 20

#define MOTOR_PIN 11
#define HEADLIGHT_PIN 4
#define SERVO_PIN 9
#define POSITION_PIN 2

#define SPEED 2
#define DIRECTION 8
#define HEADLIGHTS 16
#define POSITION 32

#include <Servo.h>

String inputString = "";
Servo directionServo;
bool stringComplete = false;
int value;
int command;

int servoPosition = FORWARD;
int currentSpeed = 0;

char buferCommand[10];
char buferValue[10];

void setup() {
  pinMode(POSITION_PIN, OUTPUT);
  pinMode(HEADLIGHT_PIN, OUTPUT);
  directionServo.attach(SERVO_PIN);
  Serial.begin(115200);
  inputString.reserve(200);
  
}

void loop() {
  if (stringComplete) {
    
    int index1 = inputString.indexOf('-');
    inputString.substring(0,index1).toCharArray(buferCommand, 10);

    int index2 = inputString.indexOf('\n');
    inputString.substring(index1+1,index2).toCharArray(buferValue, 10);

    command = atoi(buferCommand);
    value = atoi(buferValue);
    
    inputString = "";
    stringComplete = false;
  }

  if(command == SPEED) 
  {
      analogWrite(MOTOR_PIN, value);
      currentSpeed = value;
      delay(30);    
  }

  if(command == DIRECTION)
  {
      if(value == 0)
          directionServo.write(FORWARD);
      else if(value == 1)
          directionServo.write(LEFT);
      else if(value == 2)
          directionServo.write(RIGHT);
      delay(30);
  }

  if(command == POSITION)
  {
      if(value == 0)
        digitalWrite(POSITION_PIN, 0);
      if(value == 1)
        digitalWrite(POSITION_PIN, 1);
  }

  if(command == HEADLIGHTS)
  {
      if(value == 0)
        digitalWrite(HEADLIGHT_PIN, 0);
      if(value == 1)
        digitalWrite(HEADLIGHT_PIN, 1);
  }
  
  delay(100);
 
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
