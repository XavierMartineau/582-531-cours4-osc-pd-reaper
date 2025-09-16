#include <Arduino.h>
#include <MicroOscSlip.h>

#define MA_BROCHE_BOUTON 39
#define MA_BROCHE_ANGLE 32

// Le nombre 128 entre les < > ci-dessous est le nombre maximal d'octets réservés pour les messages entrants.
MicroOscSlip<128> monOsc(&Serial);

// Déclaration d'un tableau de LEDs

void setup()
{
  pinMode(MA_BROCHE_BOUTON, INPUT);
  Serial.begin(115200);
}

void loop()
{
  // Lecture de l'angle
  int maLectureAngle = analogRead(MA_BROCHE_ANGLE);
  monOsc.sendInt("/angle", maLectureAngle);

  // Lecture du bouton
  int maLectureBouton = digitalRead(MA_BROCHE_BOUTON);
  monOsc.sendInt("/Bouton", maLectureBouton);

  delay(1000); // Petite pause pour limiter la fréquence
}