#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
LiquidCrystal_I2C lcd(0x27,16,2);  

int receptor = 11;
int led = 13;
String s="";
int a = 2;

IRrecv irrecv(receptor);
decode_results codigo;

//sus

void setup() {
  Serial.begin (9600);
  irrecv.enableIRIn ();
  lcd.init();
  lcd.clear();         
  lcd.backlight();     
  
  
  lcd.setCursor(2,0);   
  lcd.print("IR IR OK");
  
  lcd.setCursor(2,1);   
  lcd.print("decoder IR");
}

void loop() {
   if (irrecv.decode(&codigo)) {
      lcd.clear();

  //Serial.println (pin.results.value, HEX);
  lcd.setCursor(0,0);   
  lcd.print("CODE :");

  lcd.setCursor(7,0);   
  lcd.print(codigo.value,HEX);
  Serial.println(codigo.value,HEX);

  if(codigo.value==0xE0FA8FAC)
  {
    digitalWrite(led,HIGH);
  }
  else if(codigo.value==0xEE2F6BA6)
  {
    digitalWrite(led,LOW);
  }
  delay(500);
  irrecv.resume();

  
  
}

}
