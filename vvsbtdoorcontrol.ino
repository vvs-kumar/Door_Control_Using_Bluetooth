#define trigPin 7
#define echoPin 2
#define trigPin1 8
#define echoPin1 4
#define led 11

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT); 
  pinMode(12,OUTPUT);
  digitalWrite(13,HIGH);
   digitalWrite(12,HIGH);
  pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
 pinMode(led,OUTPUT);


}

void loop() {
  int data=0,duration,duration1,distance1, distance;

if(Serial.available() >0)
{
data=Serial.read();
  Serial.print(data);
  Serial.print("\n");
  delayMicroseconds(100);}

  digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) /29.1; 
    Serial.print (distance);
    Serial.println (" cm");
    delayMicroseconds(10);

 digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1=pulseIn(echoPin1,HIGH);
  distance1 = (duration1/2) /29.1;
  Serial.print (distance1);
  Serial.println (" cm-1");
  delayMicroseconds(10);

  if(distance < 2)
    {digitalWrite(13, HIGH);
    digitalWrite(11,LOW);}
  
  
   if(data == 49)
    {digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    }
     
  //backward motor
 else if(distance1 < 2)
    {
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    
    } 
 
 else if(data == 50)
 {
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
 }
 else if (data == 48)
 {digitalWrite(12,HIGH);
 digitalWrite(13,HIGH);
 digitalWrite(11,LOW);
 }
    
     
}
