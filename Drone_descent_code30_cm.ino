#include <EYW.h>


EYW::RangeFinder rsensor;
int distance =0;




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
rsensor.begin();
rsensor.alarm();
rsensor.calibrate(10);
}

void loop(){
distance = rsensor.getDistance();
Serial.print("Current Distance: ");
Serial.println(distance);

if (distance <30) {
  rsensor.alarm(2,2000, 1000);
}
  
}
