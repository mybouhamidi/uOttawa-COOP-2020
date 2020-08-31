//initial value of the sensor
int prev = 0; 
//next value to compare with prev
int value_now =0; 
//counter for 100 data points
int i = 0; 
//Current time to compare with the starting time 
unsigned long current_time = 0; 
//Variable to help calculate the duration time
unsigned long prev_time = 0;
//Store the duration between two droplets
unsigned long duration = 0;

void setup() {
  //Start the serial monitor
  Serial.begin(9600);
  //Initialize the I/O pins
  pinMode(A0, INPUT);
  //Initialize the starting variables for sensor reading and time tracking
  prev = analogRead(A0);
}

void loop() {
    //Get the new readings of the sensor
    value_now = analogRead(A0);
    //Condition to detect the occurence of a droplet
    if (value_now - prev > 40){
    //Get the new reading of time and calculate the duration
    current_time = millis();
    duration = current_time - prev_time;
    prev_time = current_time;
    //Print the variables for monitoring and increment data count
    Serial.println(duration);
    i = i+1;
    }
    prev = value_now;
    delay(5);
   
    //Condition for reaching 100 data points
    if (i == 100){
      while (1){
        Serial.println("Fin de programme");
        delay(50000);
      }
    }
}
