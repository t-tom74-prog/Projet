int motorPin1 = 11;
int motorPin2 = 12;
int pot = 1;

int valeurPot;
int vitesse;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(valeurPot);
  valeurPot = analogRead(pot);

  if (valeurPot > 336) {  
    // sens normal
    vitesse = map(valeurPot, 336, 672, 255, 0);
    analogWrite(motorPin1, vitesse);
    digitalWrite(motorPin2, HIGH);
  }

  else if (valeurPot < 336) {  
    // sens inverse
    vitesse = map(valeurPot, 336, 0, 0, 255);
    analogWrite(motorPin1, vitesse);
    digitalWrite(motorPin2, LOW);
  }

  else {  
    // arrêt à 2.5V
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }

}