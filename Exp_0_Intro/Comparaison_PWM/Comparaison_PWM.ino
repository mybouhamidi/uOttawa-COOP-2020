int digitalout = 5; //PWM pin 5 on the right side of the board in the digital section  
int analogin = A0;//The analog pin used to receive the PWM signal on the left side of the board
float output = 127.5; //Variable to store the PWM value that ranges from 0 to 255(0V to 5V)
int i = 0;
float input = 0.0;//Variable to store the input value after converting the range from 0-1023 to 0-255(0V to 5V)

void setup() {
  //Starting the serial monitor
  Serial.begin(9600); 
  Serial.print("The PWM value");
  Serial.print("\t");
  Serial.println("The input value");
  pinMode(digitalout, OUTPUT);
  pinMode(analogin, INPUT);
}

void loop() {
  analogWrite(digitalout, output); //Using the PWM pin to output a voltage
  for (i=0; i<1000; i++)
  {
    input += analogRead(A0)*(255.0/1023.0); //Analog pin have a range from 0 to 1023 and need to be converted to 0-255
  }
  input = input/1000.0;
  Serial.print(output);
  Serial.print(",");
  Serial.println(input);
  delay(500); //I used the delay to receive the PWM values over a defined time and then average over 10 values
}
