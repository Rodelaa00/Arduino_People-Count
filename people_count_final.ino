#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int ir = 8;
int ir2=9;
int led=10;
int count = 0;
void setup() {
  Serial.begin(9600);
  
  lcd.begin(16,2);
   lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0,1);
  lcd.print("0");
  pinMode(ir,INPUT);
    pinMode(ir2,INPUT);
    pinMode(led,OUTPUT);
    
  // put your setup code here, to run once:

}

void loop() {

int in = digitalRead(ir);

int out = digitalRead(ir2);
Serial.print("ir1");
Serial.println(in);
Serial.print("ir2");
Serial.println(out);

   lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    if(in==0){
      count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    
    delay(1000);
    }
    if(out==0 && count!=0){
      count--;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
    }
    if(count>0){
      digitalWrite(led, HIGH);
    }else{
      digitalWrite(led, LOW);
    }
    //delay(5000);
  // put your main code here, to run repeatedly:

}
