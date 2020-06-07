# TTGO-T-Beam-Blinking
LED Blinking example for TTGO T-Beam

Since I was struggeling a lot and it took me quite some hours to collect the necessary information and adapt it to bring up my TTGO T-Beam using the Arduino IDE I decided tho share my experience and results.

Ti works for my board and environment. However, USE AT YOUR OWN RISK!!

## Hardware
There are different versions of the TTGO T-Beam and I have the one with the three buttons next to the micro USB connector, I think it is version 1.0.

<img src="https://github.com/luckynrslevin/TTGO-T-Beam-Blinking/raw/master/images/TTGO-T-Beam.JPG" width="200">

## Arduino IDE
### Libraries
You have to add the AXP202X library to your Arduino IDE. On my mac I did this on the command line by changing to the Arduino library directory (usually <your user home directory>/Documents/Arduino/libraries ) and afterwards clone the git repository by

```
git clone https://github.com/lewisxhe/AXP202X_Library
```
Afterwards I think you have to restart Arduino IDE.

### Board settings
I use these board settings

![Arduino tools configuration settings](/images/LilyGO-T-Beam-Arduino%201.8.12.png)


### Compile and upload the sketch to your board
Push the "verify" button in Arduinoe IDE to check if everything compiles without errors.
Afterwards push "Upload" button to upload to your board.

If everything was sucessfull the blue led should start blinking. Maybe you have to unplug the power adapter (USB cable) and plug it in again.


## References
* The most important hint on the axp library I found in this issue within the official LilyGO repository:
  * https://github.com/LilyGO/TTGO-T-Beam/issues/22

* Additional information related to axp library:
  * https://github.com/lewisxhe/AXP202X_Library
  * https://platformio.org/lib/show/6657/AXP202X_Library

* In addition the hint in this issue on a new repository, where I found working binary firmware images I was able to flash with esptool.py and the related sample code
  * https://github.com/LilyGO/TTGO-T-Beam/issues/34
  * https://github.com/Xinyuan-LilyGO/LilyGO-T-Beam
