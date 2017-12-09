#include <Easybot.h>
EasybotNano Robot; 
SoftwareSerial BT(BT_Rx_Pin,BT_Tx_Pin);
int data=0; 
int  Speed = 100;

void setup() {
  BT.begin(9600);         // HC05 Bluetooth baurate Speed is 9600 bps
  Serial.begin(9600);     //Serial Monitor baurate Speed is 9600;
  Serial.println(" Example for Testing HC05 Bluetooth Data ");
  delay(2000);
}

void loop() {
  if (BT.available()>0 ) {
    data = BT.read();
  }
  else data=0;
  switch (data)
  {
    case '0':
        Robot.stop();
        break;
     
    case '1':
         Robot.moveForward(Speed);
         break;
    case '2':
        Robot.moveRight(Speed);
        break;
    case '3':
        Robot.moveBack(Speed);
        break;
    case '4':
        Robot.moveLeft(Speed);
        break;
    case '5':
        Robot.stop();
        break;
  }
}
