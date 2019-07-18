/*
  DS3231: Real-Time Clock. Initialization Example
  GIT: https://github.com/TheHowToBrainiac/DS3231
  (c) 2019 by The How To Brainiac

  Use this example to store the date and time on the DS3231 module.
  Make sure you use this only once if you want the DS3231 modue to safe the
  date and time.
*/

#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);

  // Initialize DS3231
  Serial.println("Initialized DS3231");
  clock.begin();
  //        (year month day hour minute second)
  // Manual (YYYY, MM, DD, HH, II, SS)
  clock.setDateTime(2019, 7, 18, 7, 00, 00);
}

void loop(){
  dt = clock.getDateTime();

  // For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
  delay(1000);
}
