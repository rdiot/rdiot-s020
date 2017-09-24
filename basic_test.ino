/* Analog Temperature Sensor (KY-013) [S020] : http://rdiot.tistory.com/48 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int pin = A0;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  pinMode(pin,INPUT);
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("S020:KY-013");
 
  lcd.setCursor(0,1);
  lcd.print("Signal=" + (String)analogRead(pin));
 
  lcd.setCursor(0,2);
  lcd.print("Temperature=" + (String)GetTemperature(analogRead(pin)) + "'C"); 
}
 
double GetTemperature(int v)
{
 double Temp;
 // Temp = log(10000.0*((1024.0 / v - 1)));// for pull-down configuration
 Temp = log(10000.0 / (1024.0 / v - 1)); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp))* Temp);
 Temp = Temp - 273.15; // Convert Kelvin to Celcius
 // Temp = (Temp * 9.0) / 5.0 + 32.0; // Convert Celcius to Fahrenheit
 return Temp;
}
