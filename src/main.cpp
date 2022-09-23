#include <Arduino.h>

/**
 * StAuth10187: I Yongxing zhang, 000766325 certify that this material is my original work. 
 * No other person's work has been used without due acknowledgement. 
 * I have not made my work available to anyone else.
*/
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
  int iVal;
  iVal = analogRead(A0);

  // float oVal = map(iVal, 0, 1023.0000, 0, 50.00);
  float oVal = (iVal / 1024.00) * 50.00;
  String out;
  if (oVal < 10)
  {
    out = "Cold!";
  }
  else if (oVal <= 15)
  {
    out = "Cool!";
  }
  else if (oVal <= 25)
  {
    out = "Perfect!";
  }
  else if (oVal <= 30)
  {
    out = "Warm!";
  }
  else if (oVal <= 35)
  {
    out = "Hot!";
  }
  else if (oVal > 35)
  {
    out = "too Hot!";
  }

  Serial.println("Digitized output of " + String(iVal) + " is equivalent to a temputure input of " + String(oVal) + " deg. C, which is "+ out);
  delay(1000);
}