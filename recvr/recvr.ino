#include <SPI.h>
    #include <nRF24L01.h>
    #include <RF24.h>
    RF24 radio(7, 8); // CE, CSN
    const byte address[6] = "00001";
int Q1=2,Q2=3,Q3=4,Q4=5; //Output pins to be connected to 10, 11, 12, 13 of Decoder IC
void setup()
{
   Serial.begin(9600);
  pinMode(Q1,OUTPUT);
  pinMode(Q2,OUTPUT);
  pinMode(Q3,OUTPUT);
  pinMode(Q4,OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
 
 
}
void loop()
{
 if (radio.available()) {
        char text[32] = "";
        radio.read(&text, sizeof(text));
        Serial.println(text);
        if(text=="forward"){
          forward();
        }
        if(text=="backward"){
          backward();
        }
        if(text=="stop"){
          stop_();
        }
        if(text=="left"){
          left();
        }
        if(text=="right"){
          forward();
        }
 }
}
void stop_()
{
  Serial.println("");
  Serial.println("STOP");
//  digitalWrite(Q1,LOW);
//  digitalWrite(Q2,LOW);
//  digitalWrite(Q3,LOW);
//  digitalWrite(Q4,LOW);
}
void forward()
{
  Serial.println("");
  Serial.println("Forward");
//  digitalWrite(Q1,HIGH);
//  digitalWrite(Q2,LOW);
//  digitalWrite(Q3,HIGH);
//  digitalWrite(Q4,LOW);
}
void backward()
{
  Serial.println("");
  Serial.println("Backward");
//  digitalWrite(Q1,LOW);
//  digitalWrite(Q2,HIGH);
//  digitalWrite(Q3,LOW);
//  digitalWrite(Q4,HIGH);
}
void left()
{
  Serial.println("");
  Serial.println("Left");
//  digitalWrite(Q1,HIGH);
//  digitalWrite(Q2,LOW);
//  digitalWrite(Q3,LOW);
//  digitalWrite(Q4,LOW);
}
void right()
{
  Serial.println("");
  Serial.println("Right");
//  digitalWrite(Q1,LOW);
//  digitalWrite(Q2,LOW);
//  digitalWrite(Q3,HIGH);
//  digitalWrite(Q4,HIGH);
}
