int val; //stores the value received from Soil moisture sensor.
const int trigPin = 9; //pin for ultra sonic out
const int echoPin = 10; //pin for ultra sonic in
float duration, distance; //stores the values received from ultra sonic sensor.

void setup() {
  pinMode(13,OUTPUT); //Set pin 13 as OUTPUT pin, to send signal to relay
  pinMode(8,INPUT); //Set pin 8 as input pin, to receive data from Soil moisture sensor.
  pinMode(trigPin, OUTPUT); //Set pin 9 as OUTPUT pin, to send signal from ultra sonic sensor
  pinMode(echoPin, INPUT); //Set pin 10 as input pin, to receive data from ultra sonic sensor.
  Serial.begin(9600); //start serial monitor
}

void loop() { 
  val = digitalRead(8); //Read data from soil moisture sensor  
  Serial.print("Moisture: "); //print
  Serial.println(val); //print
  if(val == LOW) {
    digitalWrite(13,LOW); //if soil moisture sensor provides LOW value send LOW value to relay
  } else {
    digitalWrite(trigPin, LOW); //set ultra sonic sensor to low
    delayMicroseconds(2); //delay
    digitalWrite(trigPin, HIGH); //set ultra sonic sensor to high
    delayMicroseconds(10); //delay
    digitalWrite(trigPin, LOW); //set ultra sonic sensor to low
    duration = pulseIn(echoPin, HIGH); //get the duration
    distance = (duration*0.0343)/2; //calculate the distance
    Serial.print("Distance: "); //print
    Serial.println(distance); //print
    if(distance < 20){
        digitalWrite(13,LOW); //if distance is lesser than the limit, send LOW value to relay
    } else {
        digitalWrite(13,HIGH); //if distance is greater than the limit, send HIGH value to relay
    }
  }
  delay(400); //Wait for few second and then continue the loop.
}

