#include <Wire.h>
#include <axp20x.h>

#define I2C_SDA 21
#define I2C_SCL 22
#define AXP192_SLAVE_ADDRESS 0x34

AXP20X_Class axp;

bool axp192_found = false;

void scanI2Cdevice(void)
{
    byte err, addr;
    int nDevices = 0;
    for (addr = 1; addr < 127; addr++) {
        Wire.beginTransmission(addr);
        err = Wire.endTransmission();
        if (err == 0) {
            Serial.print("I2C device found at address 0x");
            if (addr < 16)
                Serial.print("0");
            Serial.print(addr, HEX);
            Serial.println(" !");
            nDevices++;

            if (addr == AXP192_SLAVE_ADDRESS) {
                axp192_found = true;
                Serial.println("axp192 PMU found");
            }
        } else if (err == 4) {
            Serial.print("Unknow error at address 0x");
            if (addr < 16)
                Serial.print("0");
            Serial.println(addr, HEX);
        }
    }
    if (nDevices == 0)
        Serial.println("No I2C devices found\n");
    else
        Serial.println("done\n");
}

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);
  scanI2Cdevice();
    if (axp192_found) {
        if (!axp.begin(Wire, AXP192_SLAVE_ADDRESS)) {
            Serial.println("AXP192 Begin PASS");
            // power on device
            //axp.setPowerOutPut(AXP192_LDO2, AXP202_ON);
            //axp.setPowerOutPut(AXP192_LDO3, AXP202_ON);
            //axp.setPowerOutPut(AXP192_DCDC1, AXP202_ON);
            //axp.setPowerOutPut(AXP192_DCDC2, AXP202_ON);
            //axp.setPowerOutPut(AXP192_DCDC3, AXP202_ON);
            //axp.setPowerOutPut(AXP192_EXTEN, AXP202_ON);
            // this one seems to be enough to make the led work.
            axp.setDCDC1Voltage(3300); //Set Pin header 3.3V line to 3.3V. Processor is happy down to 1.8V which saves power
            
            // Set mode of blue onboard LED (OFF, ON, Blinking 1Hz, Blinking 4 Hz)
            // axp.setChgLEDMode(AXP20X_LED_OFF);
            //axp.setChgLEDMode(AXP20X_LED_LOW_LEVEL);
            axp.setChgLEDMode(AXP20X_LED_BLINK_1HZ);
            //axp.setChgLEDMode(AXP20X_LED_BLINK_4HZ);
        } else {
            Serial.println("AXP192 Begin FAIL");
        }
    } else {
        Serial.println("AXP192 not found");
    }
}

void loop() {
  // put your main code here, to run repeatedly
  // not required in our case.
}
