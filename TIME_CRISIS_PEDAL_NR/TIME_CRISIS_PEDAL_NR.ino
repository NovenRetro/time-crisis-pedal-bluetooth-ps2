// Versión 0.1.0 TIME CRISIS PEDAL NovenRetro
// DEBE ESTAR INSTALADA LA VERSIÓN 2.0.11 DE PLACA ESP32 Y VERSIÓN 0.7.3 DE LIBRERÍA ESP32_BLE_Gamepad
#include <BleGamepad.h>

BleGamepad bleGamepad("TIME CRISIS PEDAL", "ESP32", 100);

// Pines
const int pinLed = 2;          // LED del ESP32 para indicar estado
const int pinPedal = 26;       // GPIO conectado al pin NO del microswitch del pedal

void setup() {
  Serial.begin(115200);
  bleGamepad.begin();

  pinMode(pinLed, OUTPUT);
  pinMode(pinPedal, INPUT_PULLUP); // Pull-up interno activado
}

void loop() {
  if (bleGamepad.isConnected()) {
    // LED fijo al estar conectado
    digitalWrite(pinLed, HIGH);

    // Leer pedal y controlar botón
    if (digitalRead(pinPedal) == LOW) {
      bleGamepad.press(BUTTON_1);  // BOTÓN X (Cross) — ¡RECONOCIMIENTO INMEDIATO!
    } else {
      bleGamepad.release(BUTTON_1);
    }

  } else {
    // LED titilando si no está conectado
    digitalWrite(pinLed, millis() % 1000 < 500 ? HIGH : LOW);
  }

  delay(10);
}
