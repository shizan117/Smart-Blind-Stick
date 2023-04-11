#include <Servo.h>
Servo myservo;
//int pos = 0;

// left sensor
#define echoPin1 2
#define trigPin1 3

//front sensor
#define echoPin2 4
#define trigPin2 5

//right sensor
#define echoPin3 6
#define trigPin3 7

//dept sensor
#define echoPin4 8
#define trigPin4 9

int water = A4;

long duration1, duration2, duration3, duration4;
int distance1, distance2, distance3, distance4;

void setup() {
  // left sensor
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  // front sensor
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // right sensor
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  // dept sensor
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  myservo.attach(10);
  Serial.begin(9600);

}
void loop() {
  myservo.write(90);

  water_sense();
  delay(1000);
  left_sensor();
  delay(1000);
  front_sensor();
  delay(1000);
  right_sensor();
  delay(1000);
  dept_sensor();


}

void water_sense() {
  int a = 0;
  a = analogRead(water);
  if (a >= 30)
  {
    Serial.print("water level is:");
    Serial.println(a);
    myservo.write(180);
    delay(200);
    myservo.write(0);
    delay(200);

  }
}

void dept_sensor() {
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distance4 = duration4 * 0.034 / 2;

  if (distance4 >= 10) {
    Serial.print("dept in range:");
    myservo.write(180);
    delay(200);
    myservo.write(0);
    delay(200);
  }
  else {
    Serial.print ( "dept Sensor  ");
    Serial.print ( distance4);
    Serial.println("cm");
  }

}

void left_sensor() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  if (distance1 <= 30) {
    Serial.print("left in range:");
    myservo.write(180);
    delay(200);
    myservo.write(90);
    delay(200);
  }
  else {
    Serial.print ( "Left Sensor  ");
    Serial.print ( distance1);
    Serial.println("cm");
  }
}


void front_sensor() {
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  if (distance2 <= 28) {
    Serial.print("front in range:");
    myservo.write(80);
    delay(200);
    myservo.write(110);
    delay(200);
  }

  else {
    Serial.print("Front Sensor  ");
    Serial.print(distance2);
    Serial.println("cm");
  }

}
void right_sensor() {
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 * 0.034 / 2;

  if (distance3 <= 30) {
    Serial.print("right in range:");
    myservo.write(0);
    delay(500);
    myservo.write(90);
    delay(500);
  }
  else {
    Serial.print("Right Sensor  ");
    Serial.print(distance3);
    Serial.println("cm");
  }
}

