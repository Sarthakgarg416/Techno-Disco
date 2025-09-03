
# 🎶 Techno Disco with Arduino

Turn your Arduino into a **mini disco light system** that reacts to **motion, sound, and ambient light**. With PIR motion sensing, a sound detector, and an LDR, the LEDs light up and adapt brightness to the environment — creating a reactive **techno disco effect**.

---

## 🛠️ Components Used

* 1 × Arduino UNO
* 1 × PIR Motion Sensor
* 1 × Sound Sensor Module
* 1 × LDR (Photoresistor)
* 3 × LEDs (e.g., Red, Green, Blue)
* Resistors 
* 1 × Breadboard
* Jumper wires

---

## ⚡ Circuit Overview

* **Sound Sensor** → Digital Pin **3**
* **PIR Sensor** → Digital Pin **4**
* **LEDs** → PWM-capable Pin **9** (or expand to 9, 10, 11 for multicolor effects)
* **LDR** → Analog Pin **A0**
* **Resistors** → Each LED connected in series with a 220Ω resistor
* **Power**: Components powered by Arduino’s **5V** and **GND**

📷 *setup photo shows:*

* PIR sensor connected with 3 wires (VCC, GND, OUT → D4).
* Sound sensor connected with 3 wires (VCC, GND, OUT → D3).
* LDR + resistor forming a voltage divider to **A0**.
* 3 LEDs with resistors on the breadboard connected to Arduino PWM pin(s).

---

## 💡 How It Works

1. **PIR Sensor** detects motion → system activates.
2. **Sound Sensor** listens for beats/claps → triggers disco effect.
3. **LDR** adjusts brightness automatically (darker room = brighter LEDs).
4. **LEDs** light up and change brightness based on these inputs.
5. If there’s **no sound or no motion**, LEDs turn off.

---

## 📜 Arduino Code

```cpp
int soundsensor = 3;
int pirPin = 4;
int led = 9;
int ldrPin = A0;

void setup() {
  pinMode(soundsensor, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int motion = digitalRead(pirPin);            // PIR: HIGH if motion detected
  int sensorvalue = digitalRead(soundsensor);  // Sound: HIGH if sound detected
  int lightValue = analogRead(ldrPin);         // LDR: 0 (dark) → 1023 (bright)

  if (motion == HIGH && sensorvalue == HIGH) {
    int brightness = map(lightValue, 0, 1023, 255, 10);
    brightness = constrain(brightness, 10, 255);
    analogWrite(led, brightness);
  } else {
    analogWrite(led, 0);  // LED OFF if no sound or no motion
  }
}
```

---

## 🎛️ Possible Enhancements

* Use **3 LEDs (RGB)** on pins **9, 10, 11** for multicolor disco effects.
* Add a **potentiometer** to adjust sensitivity of the LDR or sound sensor.
* Implement **beat detection** for more realistic music synchronization.
* Replace LEDs with a **relay module** to control real disco lights.
* Add pattern of lights according to beat
---

## 📸 Demo

1. Place the setup in a **dim room**.
2. Play music or clap near the **sound sensor**.
3. Move in front of the **PIR sensor**.
4. LEDs will flash and pulse with brightness adapting to the room light → instant **techno disco!** 🎉

---


