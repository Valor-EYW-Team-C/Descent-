#include <EYW.h>
#include <Servo.h>
#include <Wire.h>


EYW:: Camera PayloadServo; 
EYW::RangeFinder rsensor;
int distance =0;

EYW:: Altimeter myaltimeter;
float current_height=0;


void setup() {
  // put your setup code here, to run once:
PayloadServo.begin();
PayloadServo.calibrate();
PayloadServo.alarm();
PayloadServo.beginTimer(10000); 

Serial.begin(9600);
rsensor.begin();
rsensor.alarm();
rsensor.calibrate(10);

Serial.begin(9600);
myaltimeter.begin();
myaltimeter.calibrate(100);
myaltimeter.alarm();
}

void loop() 
  // put your main code here, to run repeatedly:
{
if (PayloadServo.timerExpired()==true || PayloadServo.buttonPressed()==true)
 {
 PayloadServo.getPicture(); 
 PayloadServo.beginTimer(5000);
 }
distance = rsensor.getDistance();
Serial.print("Current Distance: ");
Serial.println(distance);

if (distance <30) {
  rsensor.alarm(2,2000, 1000);
}

current_height = myaltimeter. getHeightAvg (20);
Serial.print("Current Height: ");
Serial.println(current_height);


if(current_height>.5)

{
  myaltimeter.alarm(6,2000,500);
}

}

