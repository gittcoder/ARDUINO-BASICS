int switch_pin = 8;
int led_pin = 13;
boolean last_button = LOW;
boolean led_on = false;
boolean current_button = LOW;



void setup()
{​​​​
pinMode(switch_pin, INPUT);
pinMode(led_pin, OUTPUT);
}​​​​



boolean debounce(boolean last)
{​​​​
boolean current = digitalRead(switch_pin);
if (last != current)
{​​​​
delay(5);
current = digitalRead(switch_pin);
}​​​​
return current;
}​​​​



void loop()
{​​​​
current_button = debounce(last_button)
if (last_button == LOW && current_button == HIGH)
{​​​​
led_on = !led_on;
}​​​​
last_button = current_button;
digitalWrite(led_pin, led_on);
}​​​​