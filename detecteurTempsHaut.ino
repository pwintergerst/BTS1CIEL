const int pinLdr = 11;

int mesure1 = 0;
int mesureDuree = 0;

bool etatLdr = LOW;
bool etatLdrPrecedent = LOW;

void setup() {
  pinMode(pinLdr, INPUT);
  Serial.begin(9600);
}

void loop() {
etatLdr = digitalRead(pinLdr);

if (etatLdr != etatLdrPrecedent && etatLdr == 1) { // vers etat haut
  mesure1 = millis(); // on déclenche le chono
  Serial.println("vers haut");
}

if (etatLdr != etatLdrPrecedent && etatLdr == 0) { // vers etat bas
  mesureDuree = millis() - mesure1; // on stop le chrono
  Serial.print("Temps haut = "); 
  Serial.println(mesureDuree);
}

etatLdrPrecedent = etatLdr;

}
