#include <LiquidCrystal.h>

LiquidCrystal lcd( 9, 8, 4, 5, 6, 7); //(Rs,E,D4,D5,D6,D7)
int inputPin = A0;
int sensorRead;
float temperature;
float volt;
void setup()
{
pinMode(12, OUTPUT);
pinMode(inputPin,INPUT);
Serial.begin(9600);  
 lcd.begin(16,2);
 lcd.setCursor(4,0);
 lcd.print("Welcome");
 pinMode(12, OUTPUT);
}
void loop()
{
   sensorRead = analogRead(inputPin);
   volt= sensorRead *(5.0/1023);
   temperature=volt/0.01;
    delay(500);
    bool flag = false;
    
    if(temperature >= 40){
      flag = true;
      digitalWrite(12, HIGH); 
    }
    if(temperature <= 30){
      flag = false;
      digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    }
    if(temperature >= 30 && temperature <= 40 && flag){
             digitalWrite(12, HIGH);
    }
        if(flag = false){
      digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    }
    lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(temperature);
          Serial.println(temperature);
    }
