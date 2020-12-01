/* * * * * * * * * * * 
 *  
 *  
 *  This codes is a modification of https://wiki.seeedstudio.com/Grove-125KHz_RFID_Reader/
 *  It uses the RFID reader 125kHz v1.0 from SeeedStudio
 *  CHECK THAT YOUR RFID TAGS ARE ALSO LABELED 125kHz
 *  
 *  Modified on Dec 1, 2020
 *  IMA @NYU SHANGHAI
 */

#include <SoftwareSerial.h>
SoftwareSerial SoftSerial(2, 3);
unsigned char buffer[64];       // buffer array for data receive over serial port
int count = 0;                    // counter for buffer array
String rfid;
char c;
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
      c = SoftSerial.read();
      if ( (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')) {
        rfid += c;
      }
      buffer[count++] = c;      // writing data into array
      if (count == 64)break;
    }
    clearBufferArray();             // call clearBufferArray function to clear the stored data from the array
    count = 0;                      // set counter of while loop to zero
  }
  if (rfid.length() > 11) {
    if (rfid == "xxx") Serial.println("xxx");
    rfid = "";
  }
  //    if (Serial.available())             // if data is available on hardware serial port ==> data is coming from PC or notebook
  //    SoftSerial.write(Serial.read());    // write it to the SoftSerial shield
}
void clearBufferArray()                 // function to clear buffer array
{
  // clear all index of array with command NULL
  for (int i = 0; i < count; i++)
  {
    buffer[i] = NULL;
  }
}
