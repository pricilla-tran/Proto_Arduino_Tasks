// Variables
int forceSensorRead; 
int potentRead; 
int tiltSensorRead;
int buzzerPin = 4; 
int potentiometerPin = A0;
int knob2Pin = A2;
int FSPin = A1; 
int TSPin = 2;
//int ALSPin = A2;
int buzzFreq;
int buzzOnandOff;
int delayNoTone;
int buzzDelay;

// need to add tilt sensor for on and off
// Status: DONE! 
// use knob for volume of buzzer1
// Status: DONE!
// light sensor for buzz1Delay


void setup() {
  
  pinMode(A1, INPUT); // FS
  pinMode(4, OUTPUT); // Buzzer
  pinMode(2, INPUT);  // Tilt Sensor
  pinMode(A2, INPUT); // Knob2
  
}

void loop() {
  // Reading the value from the knob
  potentRead = digitalRead(potentiometerPin); 
  
  // Reading the value from the tilt sensor
  tiltSensorRead = digitalRead(TSPin);
  
  // Reading the value from knob2;
  delayNoTone = analogRead(knob2Pin);
  
  
  // Reading the value from the force sensor
  forceSensorRead = analogRead(FSPin);
  
  buzzFreq = map(forceSensorRead, 0, 1023, 0, 2093);
  //buzzOnandOff = map(tiltSensorRead, 0, 1, 0, 1023);
  buzzDelay = map(delayNoTone, 0, 1023, 0, 150);
  
  //delay(delayNoTone);
  // Tilt Sensor turns the sound on and off
  if (tiltSensorRead){
    digitalWrite(buzzerPin, LOW);
    digitalWrite(FSPin, LOW);
    forceSensorRead = 0;
    buzzDelay = 0;
    delayNoTone = 0;
    noTone(buzzerPin);
    noTone(FSPin);
  }

  // Force Sensor and Tilt Sensor in Operation
  else if (tiltSensorRead && forceSensorRead != 0 && buzzDelay != 0){
    digitalWrite(buzzerPin, LOW);
    digitalWrite(FSPin, LOW);
    forceSensorRead = 0;
    buzzDelay = 0;
    delayNoTone = 0;
    noTone(FSPin);
  }
  
  analogWrite(buzzerPin, forceSensorRead);
  tone(4, buzzFreq);
  noTone(8);
  delay(buzzDelay);
  
}
