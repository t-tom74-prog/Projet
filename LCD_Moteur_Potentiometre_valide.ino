#include<LiquidCrystal.h>
#define RS 8 // Register Select
#define E 9 // Enable
#define D4 4 // Ligne de données 4
#define D5 5 // Ligne de données 5
#define D6 6 // Ligne de données 6
#define D7 7
int motorPin1 = 11;
int motorPin2 = 12;
int pot = 1;
int valeurPot;
int vitesse;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);


void setup() {
  //Moteur
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  //Ecran
  lcd.begin(16,2);
  // Serial Monitor
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  Serial.println(valeurPot);
  valeurPot = analogRead(pot);

  if (valeurPot > 336) {  
    // sens normal
    vitesse = map(valeurPot, 336, 672, 255, 0);
    analogWrite(motorPin1, vitesse);
    digitalWrite(motorPin2, HIGH);
    lcd.setCursor(0,0);
        lcd.print("U:");
        lcd.print(valeurPot*3.28/672);
        lcd.print(" V");
  
    lcd.setCursor(0,1);
        lcd.print("SPEED :");
        lcd.print(255 - vitesse);
  }

  else if (valeurPot < 336) {  
    // sens inverse
    vitesse = map(valeurPot, 336, 0, 0, 255);
    analogWrite(motorPin1, vitesse);
    digitalWrite(motorPin2, LOW);
    lcd.setCursor(0,0);
        lcd.print("U:");
        lcd.print(valeurPot*3.28/672);
        lcd.print(" V");
  
    lcd.setCursor(0,1);
        lcd.print("SPEED :-");
        lcd.print(vitesse);
  }

  else {  
    // arrêt à 2.5V
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    lcd.setCursor(0,0);
        lcd.print("U:");
        lcd.print(valeurPot*3.28/672);
        lcd.print(" V");
  
    lcd.setCursor(0,1);
        lcd.print("SPEED : ");
        lcd.print(0);
  }
delay(50);
}