/* * * * * * * * * * * 
 *  
 *  
 *  This codes is a modification of https://wiki.seeedstudio.com/Grove-125KHz_RFID_Reader/
 *  It uses the RFID reader 125kHz v1.0 from SeeedStudio
 *  CHECK THAT YOUR RFID TAGS ARE ALSO LABELED 125kHz
 *  
 *  Created on Dec 1, 2020
 *  Last Modified on Dec 6, 2021
 *  IMA @NYU SHANGHAI
 */
#include <SoftwareSerial.h> 
SoftwareSerial SoftSerial(2, 3);// RX, TX
unsigned char buffer[64];       // buffer array for data receive over serial port
int count = 0;                    // counter for buffer array
String player1 = "24851484866526551524953533";
String player2 = "24851484866657049526948543";
String card = "";
void setup()
{
  SoftSerial.begin(9600);     // the SoftSerial baud rate
  Serial.begin(9600);         // the Serial port of Arduino baud rate.
}
void loop()
{
  // if date is coming from software serial port ==> data is coming from SoftSerial shield
  if (SoftSerial.available())
  {
    while (SoftSerial.available())              // reading data into char array
    {
      buffer[count] = SoftSerial.read();      // writing data into array
      card += buffer[count];
      count++;
      if (count == 64)break;
    }
    //Serial.write(buffer, count);     // if no data transmission ends, write buffer to hardware serial port
    clearBufferArray();             // call clearBufferArray function to clear the stored data from the array
    count = 0;                      // set counter of while loop to zero
    if (card.length() >= 26) {
       Serial.println(card);      //for debugging, you can show the numbers
      if (card.equals(player1)) {
        Serial.println("1");
      } else if (card.equals(player2)) {
        Serial.println("2");
      } else {
        Serial.println("0");
      }
      card = "";
    }
  }
  if (Serial.available())             // if data is available on hardware serial port ==> data is coming from PC or notebook
    SoftSerial.write(Serial.read());    // write it to the SoftSerial shield
}
void clearBufferArray()                 // function to clear buffer array
{
  // clear all index of array with command NULL
  for (int i = 0; i < count; i++)
  {
    buffer[i] = NULL;
  }
}
void compArray()                 // function to clear buffer array
{
  // clear all index of array with command NULL
  for (int i = 0; i < count; i++)
  {
    buffer[i] = NULL;
  }
}
