// Code geklaut aus https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define LEDPin 6
#define PumpPin 7

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(LEDPin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

void loop() {
  Serial.print("Distance lol: ");
  Serial.print(measureDistance());
  Serial.println(" cm");
  if (measureDistance() <= 25){
    runPump();
   //delay(86400000 );                   // @TODO: wait for a day 60*60*24
   }
  else {
    //led anschalten
    //Wait for 1h
    //LED aus

  }
  //delay(200);
  digitalWrite(LEDPin, HIGH);           // turn the LED on (HIGH is the voltage level)
  delay(1000);                          // wait for a second
 
  digitalWrite(LEDPin, LOW);            // turn the LED off by making the voltage LOW
  delay(1000);
}

int measureDistance(){
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  return distance; 
}
void runPump(){

    //implementation to run Pump
  }