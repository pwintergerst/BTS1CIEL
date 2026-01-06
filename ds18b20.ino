#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 3

// création des objets oneWire et sensors
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  sensors.setResolution(12);    // résolution du capteur, de 9 à 12 bits
}

// Debut du loop
void loop() {
  // demande les températures sur le 1-Wire
  sensors.requestTemperatures();
  // récupere la température sur le premier capteur qui répond
  float temp = sensors.getTempCByIndex(0);

  // affichage du temps de la mesure en seconde
  unsigned long temps = millis()/1000;

  if (temp != DEVICE_DISCONNECTED_C) {
    Serial.print(temps);
    Serial.print(",");
    Serial.println(temp);
  }
}
