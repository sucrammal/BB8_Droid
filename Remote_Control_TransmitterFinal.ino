#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

//define the data pins
int joyX = A0;
int joyY = A1;

//define variable values
int dataX;
int dataY;

int data[2];

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  dataX = analogRead(joyX);
  dataY = analogRead(joyY);
  data[0] = dataX;
  data[1] = dataY;

  Serial.println(dataX);
  Serial.print(dataY);
  radio.write(data, sizeof(data));
  delay(5);
}