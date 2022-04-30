#include <Servo.h>
#include <NewPing.h>
#include <TinyGPS.h>
TinyGPS gps;
int echoPinRight = 6;
int trigerPinRight = 7;
int echoPinMiddle = 8;
int trigerPinMiddle = 9;
int echoPinLeft = 13;
int trigerPinLeft = 10;
int motorA1 = 2;
int motorA2 = 3;
int motorB1 = 4;
int motorB2 = 5;
const int motorSpeed = 12;
double echoValueright, echoValuemiddle, echoValueleft;
float cmRight, cmMiddle, cmLeft;
Servo myservo;
float sensorRight()
{
digitalWrite(trigerPinRight, LOW);
delayMicroseconds(2);
digitalWrite(trigerPinRight, HIGH);
delayMicroseconds(10);
digitalWrite(trigerPinRight, LOW);
echoValueright = pulseIn(echoPinRight, HIGH);
cmRight = echoValueright / 650;
//inchesRight=cmRight/2.54;
//Serial.print(cmRight);
return (cmRight);
}
float sensorMiddle()
{
digitalWrite(trigerPinMiddle, LOW);
delayMicroseconds(2);
digitalWrite(trigerPinMiddle, HIGH);
delayMicroseconds(10);
digitalWrite(trigerPinMiddle, LOW);
echoValuemiddle = pulseIn(echoPinMiddle, HIGH);
cmMiddle = echoValuemiddle / 650;
//inchesMiddle=cmMiddle/2.54;
//Serial.print(cmMiddle);
return (cmMiddle);
}
float sensorLeft()
{
digitalWrite(trigerPinLeft, LOW);
delayMicroseconds(2);
digitalWrite(trigerPinLeft, HIGH);
delayMicroseconds(10);
digitalWrite(trigerPinLeft, LOW);
echoValueleft = pulseIn(echoPinLeft, HIGH);
cmLeft = echoValueleft / 650;
//inchesLeft=cmLeft/2.54;
//Serial.print(cmLeft);
return (cmLeft);
}
void setup()
{
Serial.begin(9600);
myservo.attach(12);
pinMode(echoPinLeft, INPUT);
pinMode(trigerPinLeft, OUTPUT);
pinMode(echoPinMiddle, INPUT);
pinMode(trigerPinMiddle, OUTPUT);
pinMode(echoPinRight, INPUT);
pinMode(trigerPinRight, OUTPUT);
pinMode(motorSpeed, OUTPUT);
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);
}
void loop()
{
float cmR, cmM, cmL;
int maxRange = 40;
//analogWrite(motorSpeed, 50);
digitalWrite(motorA1, HIGH);
digitalWrite(motorA2, LOW);
digitalWrite(motorB1, HIGH);
digitalWrite(motorB2, LOW);
cmR = sensorRight();
cmM = sensorMiddle();
cmL = sensorLeft();
Serial.println();
Serial.println("Distance from the object to each sensor");
Serial.println();
Serial.print(cmL);
Serial.print(" ");
Serial.print(cmM);
Serial.print(" ");
Serial.print(cmR);
if ((cmM > maxRange) )
{
digitalWrite(motorA1,HIGH);
digitalWrite(motorA2, HIGH);
digitalWrite(motorB1, HIGH);
digitalWrite(motorB2, HIGH);
Serial.println();
Serial.println("MOVE FORWARD");
}
if ((cmR < maxRange) && (cmL > maxRange) && (cmM < maxRange) )
{
digitalWrite(motorA1,LOW);
digitalWrite(motorA2, HIGH);
digitalWrite(motorB1, HIGH);
digitalWrite(motorB2, LOW);
Serial.println();
Serial.println("MOVE LEFT");
}
else if ((cmR > maxRange) && (cmL < maxRange) && (cmM < maxRange) )
{
digitalWrite(motorA1, HIGH);
digitalWrite(motorA2, LOW);
digitalWrite(motorB1, LOW);
digitalWrite(motorB2, HIGH);
Serial.println();
Serial.println("MOVE RIGHT");
}
else if ((cmR < maxRange) && (cmL < maxRange) && (cmM < maxRange) )
{
if (cmR>cmL && cmR>cmM)
{
  digitalWrite(motorA1, HIGH);
digitalWrite(motorA2, LOW);
digitalWrite(motorB1, LOW);
digitalWrite(motorB2, HIGH);
Serial.println();
Serial.println("MOVE RIGHT");
}
else if (cmR<cmL && cmL>cmM)
{
digitalWrite(motorA1, LOW);
digitalWrite(motorA2, HIGH);
digitalWrite(motorB1, HIGH);
digitalWrite(motorB2, LOW);
Serial.println();
Serial.println("MOVE LEFT");
}
else if(cmM>cmR && cmM>cmL)
{
digitalWrite(motorA1, HIGH);
digitalWrite(motorA2, HIGH);
digitalWrite(motorB1, HIGH);
digitalWrite(motorB2, HIGH);
Serial.println();
Serial.println("MOVE FORWARD");
}
else if (cmM == cmR == cmL )
{
digitalWrite(motorA1, LOW);
digitalWrite(motorA2, LOW);
digitalWrite(motorB1, LOW);
digitalWrite(motorB2, LOW);
Serial.println();
Serial.println("STOP");
}
}
else if ((cmR > maxRange) && (cmL > maxRange) && (cmM < maxRange) )
  {
if (cmL > cmR)
{
digitalWrite(motorA1, LOW);
digitalWrite(motorA2, HIGH);
digitalWrite(motorB1, HIGH);
digitalWrite(motorB2, LOW);
Serial.println();
Serial.println("MOVE LEFT");
}
else if (cmR > cmL)
{
digitalWrite(motorA1, HIGH);
digitalWrite(motorA2, LOW);
digitalWrite(motorB1, LOW);
digitalWrite(motorB2, HIGH);
Serial.println();
Serial.println("MOVE RIGHT");
}
}
bool newData = false;
unsigned long chars;
unsigned short sentences, failed;
// For one second we parse GPS data and report some key values
for (unsigned long start = millis(); millis() - start < 1000;)
{
while (Serial.available())
{
char c = Serial.read();
//Serial.print(c);
if (gps.encode(c))
newData = true;
}
}
if (newData) //If newData is true
  {
float flat, flon;
unsigned long age;
gps.f_get_position(&flat, &flon, &age);
Serial.print("Latitude = ");
Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
Serial.print(" Longitude = ");
Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
}
Serial.println(failed);
// if (chars == 0)
delay(2000);
}
