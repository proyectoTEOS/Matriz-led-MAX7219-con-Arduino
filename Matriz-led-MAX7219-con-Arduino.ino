/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

#include <SPI.h>
#include <Adafruit_GFX.h> //https://github.com/adafruit/Adafruit-GFX-Library
#include <Max72xxPanel.h> //https://github.com/markruys/arduino-Max72xxPanel

const int spiPinsT = 10;
int spaceT = 1;
int broadnessT = 5 + spaceT;

const int horizontalDisplaysT = 1;
const int verticalDisplaysT = 1;
const String textT = "< TEOS >";
const int sweepSpeedT = 100;
Max72xxPanel ledMatrixT = Max72xxPanel(spiPinsT, horizontalDisplaysT, verticalDisplaysT);

void setup() {
  ledMatrixT.setIntensity(10);
}

void loop() {
  for ( int iT = 0 ; iT < broadnessT * textT.length() + ledMatrixT.width() - 1 - spaceT; iT++ ) {
    ledMatrixT.fillScreen(LOW);
    int letterT = iT / broadnessT;
    int axisXT = (ledMatrixT.width() - 1) - iT % broadnessT;
    int axisYT = (ledMatrixT.height() - 8) / 2;
    while ( axisXT + broadnessT - spaceT >= 0 && letterT >= 0 ) {
      if ( letterT < textT.length() ) {
        ledMatrixT.drawChar(axisXT, axisYT, textT[letterT], HIGH, LOW, 1);
      }
      letterT--;
      axisXT -= broadnessT;
    }
    ledMatrixT.write();
    delay(sweepSpeedT);
  }
}

