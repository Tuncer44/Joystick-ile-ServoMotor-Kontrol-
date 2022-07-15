//Tuncer Yılmaz--Arduino UNO ile-Joystick ile Servo Motor

#include <LiquidCrystal.h> //LCD kütüphanesini kodumuza dahil ediyoruz
#include <Servo.h> //Servo kütüphanesini kodumuza dahil ediyoruz

int ydir = A0; //Bağladığımız pinlere göre tanımlamalarımızı yapıyoruz
int xdir = A1;

int xposit = 0;
int yposit = 0;

 int ileri ;
 int geri;
Servo servoom; // motora isim veriyoruz
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //LCD pinlerini tanımlıyoruz


void setup() 
{
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(xdir, INPUT); //buzzer pinini INPUT olarak tanımlıyoruz
  pinMode(ydir, INPUT);
  servoom.attach(11); //motorun bağlı olduğu pin 11
  
  
  
}

void loop() {
 
  xposit=map(analogRead(xdir),0,1023,0,180);
  yposit=map(analogRead(ydir),0,1023,0,180);
  
  
  Serial.print("  ");
  
  lcd.print("  ");
  
  
  lcd.setCursor(0, 0);
  delay(1000); //1000 milisaniye bekle
  // değerleri 1 saniye boyunca ekranda göreceğiz
  
  
  lcd.clear(); //Ekranı temizle
  delay(150); //150 milisaniye bekle
  //----------------------------------------------------------------------
  ileri = digitalRead(xdir);
  geri= digitalRead(ydir);

  if (ileri==HIGH) //
  {
    
    servoom.write(180);
    delay(750);
    Serial.print("MOTOR ILERI");
    lcd.setCursor(0, 0);   //İmleci 1. sütuna al .birinci değer sütun
    lcd.print("DURUM");
    lcd.setCursor(0, 1);   //İmleci 1. sütuna al .birinci değer sütun
    lcd.print("Motor Ileri");
    delay(1000);
  } 
  else if(geri==HIGH)
  {
    servoom.write(0); // motoru hareket ettirmek için
    delay(1000);
    
    Serial.println("MOTOR GERİ"); //Belirlediğimiz kıstaslara uymayan diğer değerler
    lcd.setCursor(0, 0);   //İmleci 1. sütun 1.satıra al .birinci değer sütun ikinci değer satır
    lcd.print("DURUM");
    lcd.setCursor(0, 1); //İmleci 2. satır 1. sütuna al
    lcd.print("MOTOR GERİ");
    delay(1000);
  }
   
  else {

    Serial.print("hareketyok");
    lcd.print("hareketyok");
    delay(500);
  }
  
  Serial.println(); //Serial monitörde bir satır aşağı geç
  delay(1000); //1000 milisaniye bekle
  lcd.clear(); //LCD ekranı temizle
  delay(1000);

}
