int val = 0;
void setup (void)
{
    Serial.begin (4800);
    pinMode (3, OUTPUT);
  }

void loop (void)
{
    val = (analogRead (A5));
    if (val < 512)
    {
        digitalWrite (3, HIGH);
        delay (1000);
      }
      else {digitalWrite (3, LOW);}

    Serial.println (val);
  }
