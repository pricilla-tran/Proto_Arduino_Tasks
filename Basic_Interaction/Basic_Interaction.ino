// Basic Interaction Tutorial

// Variables 
int potentiometerPin = A0; // pin used for the knob
int piezoPin = 3; // pin used for the buzzer 
//int threshold = 750;

void setup()
{
  // setting up pin
  pinMode(piezoPin, OUTPUT);
}

void loop()
{
  /*
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  */ 
  
  // Reading the value from the knob
  int analogValue = analogRead(potentiometerPin);  
  
  // If the value on the knob is even, turn on the buzzer 
  if(analogValue % 2 == 0){
    digitalWrite(piezoPin, HIGH); // activates buzzer
  }
  else {
    digitalWrite(piezoPin, LOW); // deactivates buzzer
  }
  
}
