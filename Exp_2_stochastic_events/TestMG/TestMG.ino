//initial value
int prev = 0; 
 //next value to compare to prev
int value_now = 0;
//counter for 100 data points
int i = 0; 
//counter for droplets
int lecture = 0; 
//Starting time of the program
unsigned long start_time = 0;
//Current time to compare with the starting time
unsigned long current_time = 0;
//control parameter for the timer
const unsigned long timer = 10*1000UL; 

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  prev = analogRead(A0);
  start_time = millis();
}

void loop() {
    current_time = millis();
    value_now = analogRead(A0);
    
    if (value_now - prev > 40){
    lecture = lecture + 1;
    }
    prev = value_now;
    delay(5);
    
    if (current_time - start_time >= timer){
      Serial.println(lecture);
      i = i+1;
      start_time = current_time;
      lecture = 0;
    }
    
    if (i == 100){
      while (1){
      Serial.println("Fin de programme");
      delay(500000);
    }
   }
}
