#  Circuit Connections

---

##  Piezoelectric Transducers

- Used six 27mm Piezoelectric disks
- Connected all in series

---

##  Breadboard Connections

- Used 400 point mini breadboard

Connect components as follows:

### Diode Bridge

- Insert Diode at **e6 (silver part)** and **f6 (black part)**
- Insert Diode at **g6 (black part)** and **g9 (silver part)**
- Insert Diode at **d6 (black part)** and **d9 (silver part)**
- Insert Diode at **e9 (silver part)** and **f9 (black part)**

### Wiring

- Insert Hookup wire in **j6** and **j14**
- Insert Hookup wire in **b9** and **b14**

### Capacitor

- Negative in **g14**
- Positive in **d14**

### Resistors

- 100kΩ resistor in **a14** and **a19**
- 10kΩ resistor in **b19** and **b23**
- 10kΩ resistor in **e24** and **f24**

### Transistor (BC547)

- Collector in **a23**
- Base in **a24**
- Emitter in **a25**

### Additional Wiring

- Hookup wire in **e23** and **f23**
- Hookup wire in **i14** and **i23**
- Hookup wire in **j23** to **-ve (GND)**
- Piezo terminal 1 → **h9**
- Piezo terminal 2 → **b6**
- Hookup wire from **f24** to **a24**

---

##  Arduino Uno Connections

- **c19** → Analog pin **A0**
- **g24** → Digital pin **8**
- Breadboard Negative rail → **GND**
- Breadboard Positive rail → **VIN**

---

##  I2C LCD Display Connections

- LCD **GND** → Negative rail
- LCD **VCC** → 5V
- LCD **SDA** → Analog pin **A4**
- LCD **SCL** → Analog pin **A5**

---

##  RFID-RC522 Connections (SPI)

⚠️ Important: RFID works on **3.3V ONLY**

- RFID **SDA (SS)** → Digital pin **10**
- RFID **SCK** → Digital pin **13**
- RFID **MOSI** → Digital pin **11**
- RFID **MISO** → Digital pin **12**
- RFID **RST** → Digital pin **9**
- RFID **GND** → GND
- RFID **3.3V** → 3.3V (DO NOT connect to 5V)

To reduce signal interference:
- Keep SPI wires short
- Avoid crossing power lines
- Place RFID away from battery lines

---

##  Battery Connections

- Battery **+ve** → Positive rail
- Battery **-ve** → Negative rail

(Using two 18650 batteries connected in series for 7.4V nominal output)

---

##  LED Connections

- Insert **220Ω–330Ω resistor** in **a30** and **a31**
- LED Anode → **a31**
- LED Cathode → **a32**
- Hookup wire from **a32** → **a23** (Transistor Collector)
- Hookup wire from **a25** → **GND**
- Hookup wire from **a30** → Positive rail
