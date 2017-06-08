unsigned long int counter = 0; //Create a variable that acts as a counter
//Unsigned: The number cannot be negative
//Long: Allows the number to be very large (up to 18446744073709551615)
//Int: The number can only be an integer (..., -2, -1, 0, 1, 2, ...)

void setup() {
  pinMode(11, OUTPUT);
}

void loop() {
  float value = (sin(counter/80.0) + 1.0) * 255.0 / 2.0; //This will result in a value between 0 and 255
  //Float: The number can be a decimal (1.234, 2.3, 3.14)
  analogWrite(11, value);
  counter++; //This increases the value of counter by 1
  delay(5); //Wait .002 seconds
}
