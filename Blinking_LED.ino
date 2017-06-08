//This program will make an LED connected to pin 11 flash on and off

void setup() {
  pinMode(11, OUTPUT); //This allows pin 11 to provide voltage to the LED
}

void loop() {
  digitalWrite(11, HIGH); //Turn the LED on
  delay(500); //Let it remain on for  0.5 seconds
  digitalWrite(11, LOW); //Turn it off
  delay(500); //Let it remain off for another 0.5 seconds
}
