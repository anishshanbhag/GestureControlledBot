/*
* Gesture Recognition Robot
* This program lets you to control your robot with gesture made by your hand
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

int GNDPin=A5; //Set Analog pin 4 as GND
int VccPin=A1; //Set Analog pin 5 as VCC
int xPin=A2; //X axis input
int yPin=A3; //Y axis input
int zPin=A4; //Z axis input(not used)
long x; //Variable for storing X coordinates
long y; //Variable for storing Y coordinates
long z; //Variable for storing Z coordinates
void setup()
{
  Serial.begin(9600);

  pinMode(GNDPin, OUTPUT);
  pinMode(VccPin, OUTPUT);
  digitalWrite(GNDPin, LOW); //Set A4 pin LOW
  digitalWrite(VccPin, HIGH); //Set A5 pin HIGH
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop()
{ 
  x = analogRead(xPin); //Reads X coordinates
  y = analogRead(yPin); //Reads Y coordinates
  z = analogRead(zPin); //Reads Z coordinates

    if(x<280)       
    {
    Serial.print("f"); 
    forward();
    }
    else if(x>350) 
    {
      Serial.print("b"); 
      backward();
     }
     if(y>350) 
    {
      Serial.print("r"); 
      right();
     }
    else if(y<290) 
    {
      Serial.print("l"); 
      left();
     }
    else
      stop_();
}
void stop_()
{
  const char text[] = "stop";
  radio.write(&text, sizeof(text));
}
void forward()
{
  const char text[] = "forward";
  radio.write(&text, sizeof(text));
}
void backward()
{
  const char text[] = "backward";
  radio.write(&text, sizeof(text));
}
void left()
{
  const char text[] = "left";
  radio.write(&text, sizeof(text));
}
void right()
{
  const char text[] = "right";
  radio.write(&text, sizeof(text));
}
