#include <EYW.h>


EYW::Camera PayloadServo; 
EYW::RangeFinder rsensor;
int distance =0;

EYW:: Altimeter myaltimeter;
float current_height=0;

unsigned long timerstart=0;
unsigned long duration=0;

void beginTimer(int dur)
{
  timerstart = millis();
  duration = dur;
}

bool checkTimer()
{
  if ((millis()-timerstart) > duration){
    return true;
  } else {
    return false;
  }
}

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
current_height = myaltimeter.getHeightAvg (20);
if (PayloadServo.timerExpired()==true && current_height >= .4)
 {
 //PayloadServo.getPicture(); 
  PayloadServo.getPicture();

 }

 
distance = rsensor.getDistance();
Serial.print("Current Distance: ");
Serial.println(distance);

if (distance <30) {
  rsensor.alarm(2,1000, 250);
}

current_height = myaltimeter. getHeightAvg (20);
Serial.print("Current Height: ");
Serial.println(current_height);


if(current_height>                                                                                                  .4) {
  PayloadServo.getPicture();
  myaltimeter.alarm(6,4000,100);
   beginTimer (3000);
}

}
