int prev = 0;
int value_now = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  prev = analogRead(A0);
}

void loop() {
    value_now = analogRead(A0); 
    Serial.println(prev);
    prev = value_now;
}
