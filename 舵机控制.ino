#include <LiquidCrystal.h>
LiquidCrystal LCD(2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);

void setup(void)
{
    delay(100);
    LCD.begin(16, 2);
    LCD.clear();
    LCD.setCursor(0, 0);
    LCD.print("hello msaoding");
    delay(1000);
    pinMode(A1, INPUT_PULLUP);
    pinMode(A0, INPUT_PULLUP);
    pinMode(3, OUTPUT);
  }
void loop(void)
{
    LCD.setCursor(0, 1);
    if(digitalRead(A1) == LOW)
    {
        LCD.print("Left");
        digitalWrite(3, HIGH);
        delay(1);
        digitalWrite(3, LOW);
        delay(200);
        LCD.setCursor(0, 1);
      }
     else
     {
        digitalWrite(3, HIGH);
        delayMicroseconds(1500);
        digitalWrite(3, LOW);
        delay(20);
      }

     if(digitalRead(A0) == LOW)
     {
        LCD.print("Righ");
        digitalWrite(3, HIGH);
        delay(2);
        digitalWrite(3, LOW);
        delay(200);
        LCD.setCursor(0, 1);
      }
     else
     {
        digitalWrite(3, HIGH);
        delayMicroseconds(1500);
        digitalWrite(3, LOW);
        delay(20);
      }
  }
