//Define Variables we'll be connecting to
#define THERMISTORNOMINAL 100000      
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25   
// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3950
// the value of the 'other' resistor
#define SERIESRESISTOR 10000 
double Input, Output, Setpoint;

void Compute()
{
   double ITerm, lastInput;
   double kp = 15, ki = 3, kd = 0;
   double outMax = 255, outMin = 0;
   int SampleTime = 1000; //1 sec
   unsigned long lastTime;
   unsigned long now = millis();
   int timeChange = (now - lastTime);
   if(timeChange>=SampleTime)
   {
      /*Compute all the working error variables*/
      double error = Setpoint - Input;
      ITerm+= (ki * error);
      if(ITerm> outMax) ITerm= outMax;
      else if(ITerm< outMin) ITerm= outMin;
      double dInput = (Input - lastInput);
 
      /*Compute PID Output*/
      Output = kp * error + ITerm - kd * dInput;
      if(Output > outMax) Output = outMax;
      else if(Output < outMin) Output = outMin;
      /*Remember some variables for next time*/
      lastInput = Input;
      lastTime = now;
   }
}

double Thermistor(int RawADC) {
  // convert the value to resistance     
  double steinhart = (1023.0/RawADC) - 1;
  steinhart = SERIESRESISTOR / steinhart;
  steinhart = steinhart / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;    // convert to C
  return steinhart;
  }
          
void setup()
{
  Serial.begin(9600);
  //initialize the variables we're linked to
  Setpoint = 60;
}

void loop()
{
  //Read the temperature for the PID
  Input = Thermistor(analogRead(A0));
  //Perform the PID control functionn
  Compute();
  //Write the output to the PWM
  analogWrite(5,Output);
  Serial.print("Temperature: ");
  Serial.println(Input);
  delay(100);
  //The program is finished after 30 min
  if (millis() >= 1800001) {
    while(1){
      Serial.println("Done");
      delay(5000);
    }
  }
}
