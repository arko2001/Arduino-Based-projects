#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

float firstNum;
float secNum;
float answer;
String op;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7); //creating liquidCrystal object we tell liquidCrystal library in the arduino how its connected so it knows what to do with what pins
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);//we have to start the lcd and what kind of lcd i.e 16 coloums and 2 rows
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);

lcd.print("Input 1st Number"); //ask
while (Serial.available()==0){
}//wait
firstNum=Serial.parseFloat(); //read
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Input 2nd Number"); //ask
while (Serial.available()==0){
}//wait
secNum=Serial.parseFloat(); //read

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Input(+,-,*,/)");//ask
while (Serial.available()==0){
}
op =Serial.readString(); //read

if (op=="+"){
  answer=firstNum+secNum;
}

if (op=="-"){
  answer=firstNum-secNum;
}

if (op=="*"){
  answer=firstNum*secNum;
}

if (op=="/"){
  answer=firstNum/secNum;
}
lcd.clear();
lcd.setCursor(0,0);
lcd.print(firstNum);
lcd.print(op);
lcd.print(secNum);
lcd.print(" = ");
lcd.print(answer);
lcd.setCursor(0,1);
lcd.print("Thank you");
delay(5000);
lcd.clear();


}
