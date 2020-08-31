//Including the time library to use predefined functions
#include <TimeLib.h>
void setup()
{
  Serial.begin(9600);  //start Serial in case we need to print debugging info
}
//Arduino's clock is set at 16MHz and my processor's clock is at 2.5 GHz at 1% usage


void loop()
{
timer(); //calling the function to start the timer
}

void timer()
{
static unsigned long start_time = millis(); //saving the starting time of the program in the first loop

if (millis() - start_time >= 1000) //creating a 1 sec delay without using the delay() function to avoid any timing issues and avoid recording too much information
{
start_time = millis(); //saving the new loop starting time
time_t t = now(); 
short hours = hour(t);
short minutes = minute(t);
short seconds = second(t);

//printing in the Arduino serial the time that is computed
Serial.print(hours);
Serial.print(":");
Serial.print(minutes);
Serial.print(F(":"));
Serial.print(seconds);
Serial.println();
}
}
