const int trigPin =4 ;
const int echoPin =2 ;
const int led=13;
const int buzzer=11;                   
void setup() {  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.41; 
  if (distance > 400 || distance <0)
  {
    Serial.println("Out of range");
  }
  else
  {
   Serial.print(distance); 
   Serial.println(" cm");
  }
  if(distance<=80)
  {
    digitalWrite(led,HIGH);
    delay(50);
   // Serial.println("LED on");
    digitalWrite(led,LOW);
    delay(50);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  if (distance<=40){
    digitalWrite(buzzer,HIGH);
    delay(50);
    //Serial.println("BUZZER on");
    digitalWrite(buzzer,LOW);
    delay(50);
  }
  else
  {
    digitalWrite(buzzer,LOW);
  }
 }
