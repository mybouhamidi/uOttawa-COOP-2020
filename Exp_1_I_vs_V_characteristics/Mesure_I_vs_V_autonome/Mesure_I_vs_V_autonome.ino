//Import libraries
#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;//Initialize the dac component
uint32_t counter; //I used a variable to change the DAC value that ranges from 0 to 4095(0V to 5V)
int DACpin = A0;//Read the DAC voltage for precision
int LEDpin = A1;//The analog pin used to receive the voltage of the DEL on the left side of the board
int resistance = 1000;
float input = 0;//Del voltage reading
float output = 0;//DAC voltage reading
float current = 0;//Del current

void setup() {
  //Starting the serial monitor
  Serial.begin(9600); 
  pinMode(LEDpin, INPUT);
  pinMode(DACpin, INPUT);
  dac.begin(0x62);
  Serial.print("The output voltage from DAC");
  Serial.print(",");
  Serial.print("The output voltage measured");
  Serial.print(",");
  Serial.print("The LED's voltage");
  Serial.print(",");
  Serial.print("The LED's current");
  Serial.println();
}

void loop() {
  while (counter <= 4095) {
    //Using the DACpin to output a voltage
    dac.setVoltage(counter, false); 
    //Converting to 5V
    float outputDac = counter*(5.0/4095.0);
    //Reading the DAC output and the voltage at the DEL
    output = analogRead(DACpin)*(5.0/1023.0);
    input = analogRead(LEDpin)*(5.0/1023.0);
  
    //Calculating the current
    current =((output - input)/resistance)*1000;
  
    Serial.print(outputDac);
    Serial.print(",");
    Serial.print(output);
    Serial.print(",");
    Serial.print(input);
    Serial.print(",");
    if (current <= 0.0){
      Serial.print(0.0);
      Serial.println();
    }
    else {
      Serial.print(current);
      Serial.println();
    }
    counter += 1;
    }
}
