# Smart Safe
A scaled down miniature of a smart safe. With ability to open via a key pad and a fob/card.

## Getting Started

### Prerequisites

You will need the Arduino IDE, on windows it can be found in the [microsoft store](https://www.microsoft.com/en-ca/p/arduino-ide/9nblggh4rsd8?activetab=pivot:overviewtab). You will need two Arduino Unos, a lcd 2004a, Micro Servo 9g FS90, KeyPad (4x4),
RGB LED CNT1, RFID-RC522, two 9V Battery and wires of all types (m x m, f x f, m x f).

### Installing

To install just clone the repository, then upload main.ino to your primary arduino uno and rfid.ino to your secondary arduino uno. Next you will need to wire all the components.

Keypad Wiring (facing upwards from left to right):

| KeyPad(4x4) Pin | Arduino Pin |
| --- | --- |
| 1 | 11 |
| 2 | 2 |
| 3 | 3 |
| 4 | 4 |
| 5 | 5 |
| 6 | 6 |
| 7 | 7 |
| 8 | 10 |

Lcd Wiring:

| LCD2004a Pin | Arduino Pin |
| --- | --- |
| GND | GND |
| VCC | 5V |
| SCL | A5 |
| SCK | A4 |

Motor Wiring:

| Micro Servo 9g FS90 Pin | Arduino Pin |
| --- | --- |
| GNG | GND |
| VCC | 5V |
| Signal Pin | 9 |


RFID Wiring:

| RFID-RC522 Pin | Arduino Pin |
| --- | --- |
| SDA | Digital 10 |
| SCK | Digital 13 |
| MOSI | Digital 11 |
| MISO | Digital 12 |
| IRQ | unconnected |
| GND | GND |
| RST | Digital 9 |
| 3.3V | 3.3V |

LED Wiring:

| RGB LED CNT1 | Arduino Pin |
| --- | --- |
| R | A2 |
| G | A1 |
| B | A0 |
| Power | 5V |


## Authors

* **Dominic Humber** - *Initial work* - [gerauschlos](https://github.com/gerauschlos)
* **Daniel Grishanov** - *Initial work* - [TheDannyG](https://github.com/thedannyg)



