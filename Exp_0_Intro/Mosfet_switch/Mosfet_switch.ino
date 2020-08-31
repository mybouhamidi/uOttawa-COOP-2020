void setup() {
  // initialize digital pin 2 as an output.
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);   //Give 5V to the gate of the Mosfet to turn it on
  delay(1000);                       // wait for a second
  digitalWrite(2, LOW);    //Give 0V to the gate of the Mosfet to turn it off
  delay(1000);                       // wait for a second
}
