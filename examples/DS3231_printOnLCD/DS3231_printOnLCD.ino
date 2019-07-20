/*
* Arduino DS3231 Real Time Clock Module LCD Tutorial
*
* Crated by The How To Brainiac,
* https://www.youtube.com/channel/UCqml-glTpeFyFfwnE-xsV9g?view_as=subscriber
*
* DS3231 Library made by Korneliusz Jarzebski
*
*/
#include <Wire.h>
#include <DS3231.h>
#include <LiquidCrystal.h> // includes the LiquidCrystal Library 

DS3231 clock;
RTCDateTime dt;

LiquidCrystal lcd(A0, A1, A2, 9, 10, 11); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
void setup() { 
 clock.begin(); // Initialize the rtc object
 lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
}
void loop() {
 //TIME
 dt = clock.getDateTime(); 
 lcd.setCursor(0,0);
 lcd.print("Time:  ");
 if(dt.hour > 9){
  lcd.setCursor(5, 0);
 }else{
  lcd.setCursor(6, 0);
 }
 
 lcd.print(dt.hour);
 lcd.setCursor(7, 0);
 lcd.print(":");
 if(dt.minute > 9){
  lcd.setCursor(8, 0); 
 }else{
  lcd.setCursor(8, 0);
  lcd.print("0");
  lcd.setCursor(9, 0);
 }
 lcd.print(dt.minute);
 lcd.setCursor(10, 0);
 lcd.print(":");
 if(dt.second > 9){
  lcd.setCursor(11, 0);
 }else{
  lcd.setCursor(11, 0);
  lcd.print("0");
  lcd.setCursor(12, 0);
 }
 lcd.print(dt.second);
 lcd.setCursor(14, 0);
 if(dt.hour > 12){
  lcd.print("PM");
 }else{
  lcd.print("AM");
 }

 //DATE
 
 lcd.setCursor(0,1);
 lcd.print("Date: "); 
 if(dt.month > 9){
  lcd.setCursor(5, 1);
 }else{
  lcd.setCursor(5, 1);
  lcd.print("0");
  lcd.setCursor(6, 1);
 }
 lcd.print(dt.month);
 lcd.setCursor(7, 1);
 lcd.print("-");
 if(dt.day > 9){
  lcd.setCursor(8, 1);
 }else{
  lcd.setCursor(8, 1);
  lcd.print("0");
  lcd.setCursor(9, 1);
 }
 lcd.print(dt.day);
 lcd.setCursor(10, 1);
 lcd.print("-");
 lcd.setCursor(11, 1);
 lcd.print(dt.year);
 delay(999); 
 if(dt.hour = 10){
  lcd.clear();
 }
}
