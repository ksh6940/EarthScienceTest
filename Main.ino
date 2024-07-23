#include <L298N.h>

const int buzzerPin = 13;

const unsigned int IN1 = 8;
const unsigned int IN2 = 9;
const unsigned int EN = 10;

const int buttonPin1 = 2;
const int buttonPin2 = 4; 

L298N motor(EN, IN1, IN2);

void setup()
{
  Serial.begin(9600);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  pinMode(buzzerPin, OUTPUT);

  motor.setSpeed(100);
}

void loop()
{
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);

  tone(buzzerPin, 329.63);

 if (buttonState1 == HIGH){
   Serial.println('버튼 : 가까워짐');
   motor.forward();
   delay(6000);
   motor.stop();
 } else if (buttonState2 == HIGH) {
   Serial.println('버튼 : 멀어짐');
   motor.backward();
   delay(6000);
   motor.stop();
 } else {
   motor.stop();
 }
}
