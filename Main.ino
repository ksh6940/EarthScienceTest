#include <L298N.h>

const int buzzerPin = 13;

const int ledPin1 = 6; //적색편이
const int ledPin2 = 5; //청색편이

const unsigned int IN1 = 8;
const unsigned int IN2 = 9;
const unsigned int EN = 10;

const int buttonPin1 = 2;
const int buttonPin2 = 4; 
const int ledPin = 13;   

L298N motor(EN, IN1, IN2);

void setup()
{
  Serial.begin(9600);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  motor.setSpeed(100);
}

void loop()
{
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);

  tone(buzzerPin, 329.63);

 if (buttonState1 == HIGH){
   Serial.println("적색 편이");
   digitalWrite(ledPin1, HIGH);
   motor.forward();
   delay(6000);
   motor.stop();
 } else if (buttonState2 == HIGH) {
   Serial.println("청색 편이");
   digitalWrite(ledPin2, HIGH);
   motor.backward();
   delay(6000);
   motor.stop();
 } else {
   motor.stop();
   digitalWrite(ledPin1, LOW);
   digitalWrite(ledPin2, LOW);
 }
}
