#include "DHT.h"
#define DHTPIN 5
# define  DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int IA = 31;  //  pin 31 connected to pin IA
const int IB = 30;  //  pin 30 connected to pin IB
byte speed = 255;  // change this (0-255) to control the speed of the motor
void setup() {
  Serial.begin(9600);
  pinMode(7,OUTPUT);//Yellow LED
  pinMode(4,OUTPUT);//Green LED
  dht.begin();
  pinMode(IA, OUTPUT); // set pins to output
  pinMode(IB, OUTPUT);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("% Temperature: ");
  Serial.print(t);
  while(t>=23.0){
  digitalWrite(7,HIGH);
  Serial.println("\nYellow LED allumée");
  Serial.println("Moteur activé");
  forward();
  delay(1000);
  backward();
  delay(1000);
  h = dht.readHumidity();                                                    
  t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("% Temperature: ");
  Serial.print(t);
    }
  analogWrite(IA, 0);
  analogWrite(IB, 0);
  digitalWrite(7,LOW);
  Serial.println("\n Yellow LED eteinte");
  if(h<50.00){
  digitalWrite(4,HIGH);
  Serial.println("Green LED  allumée");}
  else{
  digitalWrite(4,LOW);
  Serial.println("Green LED  eteinte");}
delay(1000);
}
void backward()
{
  analogWrite(IA, 0);
  analogWrite(IB, speed);
}

void forward()
{
  analogWrite(IA, speed);
  analogWrite(IB, 0);}
