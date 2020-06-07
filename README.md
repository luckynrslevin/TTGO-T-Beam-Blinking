# TTGO-T-Beam-Blinking
LED Blinking example for TTGO T-Beam

Since I was struggeling a lot and it took me quite some hours to collect the necessary information and adapt it to bring up my TTGO T-Beam using the Arduino IDE I decided tho share my experience and results.

## Hardware
There are different versions of the TTGO T-Beam and I have the one with the three buttons next to the micro USB connector, not sure which version number this is.

TODO: Add photo

## Arduino IDE configuration
### Libraries
You have to add the following depending libraries to your Arduino IDE:

TODO

### Board settings
![Arduino tools configuration settings](/images/LilyGO-T-Beam-Arduino%201.8.12.png)


## References
* The most important hint on the axp library I found in this issue within the official LilyGO repository:
  * https://github.com/LilyGO/TTGO-T-Beam/issues/22

* Additional information related to axp library:
  * https://github.com/lewisxhe/AXP202X_Library
  * https://platformio.org/lib/show/6657/AXP202X_Library

* In addition the hint in this issue on a new repository, where I found working binary firmware images I was able to flash with esptool.py and the related sample code
  * https://github.com/LilyGO/TTGO-T-Beam/issues/34
  * https://github.com/Xinyuan-LilyGO/LilyGO-T-Beam
