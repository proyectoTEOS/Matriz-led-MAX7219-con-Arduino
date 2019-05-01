# Matriz led MAX7219 con Arduino
En esta entrada veremos como hacer un texto con efecto de barrido utilizando una matriz de leds con el integrado MAX7219 y Arduino.

### Requisitos
- Tener el IDE de [Arduino](https://www.arduino.cc/en/Main/Software) (o el de tu preferencia) con la versión más actual
- Contar con las librerías [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library) y [Max72xxPanel](https://github.com/markruys/arduino-Max72xxPanel)
- Tener el material para hacer el proyecto

### Código
**[Aqui](https://github.com/proyectoTEOS/Matriz-led-MAX7219-con-Arduino/blob/master/Matriz-led-MAX7219-con-Arduino.ino)** podrás obtener el link del código, también dejaremos
una vista previa aquí abajo.

```c++
/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  WEB https://www.proyecto-teos.com
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
```

### Diagrama
El siguiente esquemático muestra como se debe conectar todos los componentes con la placa.
![](https://github.com/proyectoTEOS/Matriz-led-MAX7219-con-Arduino/blob/master/matriz-led-max7219-con-arduino-5.jpg)
