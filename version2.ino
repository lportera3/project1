#define echoPin 12 // Echo Pin
#define trigPin 13 // Trigger Pin
#define basePin 10
#define buzzerPin 4 // Buzzer Pin
long duration;
int distance; // Duration used to calculate distance
int tries = 0;
int buzzerCount = 0;
void setup() 
{
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(basePin, OUTPUT);
 pinMode(buzzerPin, OUTPUT);
 digitalWrite(buzzerPin, LOW);
 digitalWrite(basePin, HIGH);//probably an error
 
 Serial.begin(9600);
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);

 if(tries == 3)
 {
  digitalWrite(basePin, LOW);
  delay(2000);
  digitalWrite(basePin, HIGH);
 }
 if(duration == 0)
 {
  tries++;
 }
 else
 {
  tries = 0;
 }
 //Calculate the distance (in cm) based on the speed of sound.

 distance = duration/58.2;
 if(distance > 15 || distance < 5)
 { 
  buzzerCount++;
 }
 else
 {
  buzzerCount = 0;
 }
 if(buzzerCount >= 4){
  digitalWrite(buzzerPin, HIGH);
 }
 else
 {
  digitalWrite(buzzerPin, LOW);
 }
 Serial.println(distance);
 
 //Delay 500ms before next reading.
 delay(500);

}
