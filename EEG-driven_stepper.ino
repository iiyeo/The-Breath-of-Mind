// Arduino Brain Library - Brain SoftSerial Test

// Description: Grabs brain data from software serial on pin 10 and sends CSV out over the hardware serial
// More info: https://github.com/kitschpatrol/Arduino-Brain-Library
// Author: Eric Mika, 2014

#include <SoftwareSerial.h>
#include <Brain.h>

// Set up the software serial port on pins 10 (RX) and 11 (TX). We'll only actually hook up pin 10.
SoftwareSerial softSerial(10, 11);

// Set up the brain reader, pass it the software serial object you want to listen on.
Brain brain(softSerial);

String a,a1;
int v = 0;
int z=0,output1;

uint32_t num1=0;
uint32_t num1_=0;

#include <Stepper.h>
#define STEPS 200

//int speed1 = 3;

//int direction1 = 12;

Stepper stepper (STEPS, 6, 7, 8, 9);

void setup() {
  softSerial.begin(9600);
    
    // Start the hardware serial. 
  Serial.begin(9600);
  
  //pinMode (speed1, OUTPUT);
  //pinMode (dirention1, OUTPUT);


}

void loop() {

  if (brain.update()) {
        Serial.print(brain.readErrors());
        a = brain.readCSV();
        v = a.indexOf(',');
        z = a.indexOf(',',v+1);

        a1 = a.substring(v+1,z);
        num1 = a1.toInt();
         
        v = a.indexOf(',',z+1);
        
        a = a.substring(z+1,v);
         
        num1_ = a.toInt();
        Serial.print("attention = ");
        Serial.println(num1_);

        
        //delay(100);
        
  if ((num1_ > 0) && (num1_ < 30)) {
  stepper.setSpeed(20);
  stepper.step(-50);
  delay(100);
   }
   
   if ((num1_ >= 30) && (num1_ < 60)) {
  stepper.setSpeed(60);
  stepper.step(200);
  delay(100);

  }

  if ((num1_ >= 60) && (num1_ < 90)) {
  stepper.setSpeed(40);
  stepper.step(100);
  delay(100);

  }

  if ((num1_ >= 90) && (num1_ < 120)) {
  stepper.setSpeed(10);
  stepper.step(-100);
  delay(100);

  }

  if ((num1_ >= 120) && (num1_ < 150)) {
  stepper.setSpeed(60);
  stepper.step(200);
  delay(100);

  }

  if ((num1_ >= 150) && (num1_ < 180)) {
  stepper.setSpeed(90);
  stepper.step(-10);
  delay(100);

  }

  }
}
  

