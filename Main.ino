#include <L298N.h>

const int buzzerPin = 7;

const unsigned int EN = 8;
const unsigned int IN1 = 9;
const unsigned int IN2 = 10;

const int buttonPin1 = 2;
const int buttonPin2 = 3; 

const int LedPin1 = 12;
const int LedPin2 = 13;

L298N motor(EN, IN1, IN2);

void setup()
{
  Serial.begin(9600);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  pinMode(LedPin1, OUTPUT);
  pinMode(LedPin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  motor.setSpeed(100);
}

void loop()
{
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);

  tone(buzzerPin, 329.63);

  if (buttonState1 == LOW) {
    Serial.println("버튼 : 가까워짐");  // Corrected to use double quotes for string
    digitalWrite(LedPin2, HIGH);
    motor.forward();
    delay(6000);
    motor.stop();
  } 
  else if (buttonState2 == LOW) {
    Serial.println("버튼 : 멀어짐");  // Corrected to use double quotes for string
    digitalWrite(LedPin1, HIGH);
    motor.backward();
    delay(6000);
    motor.stop();
  } 
  else {
    digitalWrite(LedPin1, LOW);  // Turn off both LEDs when neither button is pressed
    digitalWrite(LedPin2, LOW);
    motor.stop();
  }
}
