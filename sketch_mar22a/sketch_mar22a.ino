
 // put your setup code here, to run once:
// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define relayPin1 5
#define relayPin2 6
#define relayPin3 10
#define relayPin4 11

// defines variables
long duration;
long duration2;// variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int distance2;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);
  
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
  digitalWrite(relayPin3, LOW);
  digitalWrite(relayPin4, LOW);
  delayMicroseconds(2);
  delay(700);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back) 
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
      if(distance > 5 && distance <= 20) {
         digitalWrite(relayPin1, HIGH);
         delay(200);
         Serial.println("Motion detected.");
         digitalWrite(relayPin1, LOW);
         delay(2);
      }
      if(distance > 20 && distance <= 35) {
         digitalWrite(relayPin2, HIGH);
         delay(200);
         Serial.println("Motion detected.");
         digitalWrite(relayPin2, LOW);
         delay(2);
      }
      if(distance > 35 && distance <= 50) {
         digitalWrite(relayPin3, HIGH);
         delay(200);
         Serial.println("Motion detected.");
         digitalWrite(relayPin3, LOW);
         delay(2);
      }
      if(distance > 50 && distance <= 65) {
         digitalWrite(relayPin4, HIGH);
         delay(200);
         Serial.println("Motion detected.");
         digitalWrite(relayPin4, LOW);
         delay(2);
      }
       
      if(distance > 0 && distance <= 5) {
         digitalWrite(relayPin1, HIGH);
         digitalWrite(relayPin2, HIGH);
         digitalWrite(relayPin3, HIGH);
         digitalWrite(relayPin4, HIGH);
         delay(2000);
         Serial.println("Restart");
      }//to make it restart

  do {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        delayMicroseconds(10);
        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration2 = pulseIn(echoPin, HIGH);
        // Calculating the distance
        distance2 = duration2 * 0.034 / 2; 
        delay(200);
  }while(distance2 >= 5 && distance2 <= 65);
}
      
