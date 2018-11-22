#include <Servo.h>
Servo s;
int trigPin = 8;
int echoPin = 9; 
long distance;
long duration;
int pos = 0;
int conv[] = {2,3,4,5};

void runconv() {
  analogWrite(conv[0],150);
  analogWrite(conv[1],0);
  analogWrite(conv[2], 150);
  analogWrite(conv[3], 0);
}

void stopconv() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(conv[i], LOW);
  }
}

void setup()
{
  for (int i = 0; i < 4; i++) {
    pinMode(conv[i], OUTPUT);
  }
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);// put your setup code here, to run once:
runconv();
delay(1000);
stopconv();
}

void loop() {

  
  runconv();
  ultra();
  if (distance <= 4 ) {
 
    stopconv();
    s.attach(7);
    delay(1000);
    s.write(100);
    delay(100);
    s.write(7);
    s.detach();
    runconv();
    delay(1000);
//    for (pos = 50; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
//      // in steps of 1 degree
//      servo.write(pos);              // tell servo to go to position in variable 'pos'
//      delay(150);                       // waits 15ms for the servo to reach the position
//    }
//    for (pos = 100; pos >= 50; pos -= 1) { // goes from 180 degrees to 0 degrees
//      servo.write(pos);              // tell servo to go to position in variable 'pos'
//      delay(150);                       // waits 15ms for the servo to reach the position
//    }

  }

}
void ultra() {
  s.detach();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  s.attach(7);
}
