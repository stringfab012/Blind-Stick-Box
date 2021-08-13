 
const int water=7;
const int trigpin=13;
const int echopin1=8;
const int echopin2=9;
const int echopin3=10;
const int buzz=12;
const int mot=5;
const int pushbutton=11;
int buttonstate=0;
int check=0;

//check variable is included to neglect the output of upper ultrasonic sensor while both obstacle detecting and upper gives their output as high


void setup()
{
pinMode(trigpin,OUTPUT);
pinMode(echopin1,INPUT);
pinMode(echopin2,INPUT);
pinMode(echopin3,INPUT);
pinMode(buzz,OUTPUT);
pinMode(mot,OUTPUT);
pinMode(pushbutton,INPUT);
pinMode(water,INPUT);
Serial.begin(9600);
}




//function for obstacle avoiding ultrasonic sensor
void ultrasonic1()
{
  int distance1;
  int duration1;
  digitalWrite(trigpin,LOW);
  delayMicroseconds(20);


  digitalWrite(trigpin,HIGH);
  delay(100);
  digitalWrite(trigpin,LOW);

  duration1=pulseIn(echopin1,HIGH);

  distance1=duration1*0.034/2;
  if(distance1)
  {  check=HIGH;
  }
  else
  {
    check=LOW;
  }

buttonstate=digitalRead(pushbutton);
  
if(pushbutton==LOW)
{
  if(distance1<=200)
  {
    digitalWrite(buzz,HIGH);
    tone(2000,400);
    delay(1000);
    digitalWrite(buzz,LOW);
    
  }
}

//codeblock for vibrating motor
  else
  {
     digitalWrite(mot,HIGH);
    delay(1000);
    digitalWrite(mot,LOW);
    delay(1000);
  }
}






//function for pothole detection  ultrasonic sensor
void ultrasonic2()
{

  int distance2;
  int duration2;


  
  digitalWrite(trigpin,LOW);
  delayMicroseconds(20);


  digitalWrite(trigpin,HIGH);
  delay(100);
  digitalWrite(trigpin,LOW);



  
  duration2=pulseIn(echopin2,HIGH);

  distance2=duration2*0.034/2;

  buttonstate=digitalRead(pushbutton);


  if(buttonstate==LOW)
  {
  if(distance2>=147)
  {
     digitalWrite(buzz,HIGH);
    tone(2500,400);
    delay(1000);
    digitalWrite(buzz,LOW);
    
}
  }
  
  
//codeblock for vibrating motor
else
{
  
  
    digitalWrite(mot,HIGH);
    delay(500);
    digitalWrite(mot,LOW);
    delay(500);
  }
}






//function for water detection sensor

void water1()
{
 if(digitalRead(water)==HIGH )
{  
  digitalWrite(buzz,HIGH);
  tone(700,4000,1000);
  digitalWrite(buzz,LOW);
}
else{
  digitalWrite(buzz,LOW);
}



  
 //codeblock for vibrating motor
  buttonstate=digitalRead(pushbutton);
  if(buttonstate==HIGH)
  {
    digitalWrite(mot,HIGH);
    delay(1000);
    digitalWrite(mot,LOW);
    delay(1000);
  }



}







//function for upper hindrance

void ultrasonic3()
{

  int distance3;
  int duration3;
  digitalWrite(trigpin,LOW);
  delayMicroseconds(20);


  digitalWrite(trigpin,HIGH);
  delay(100);
  digitalWrite(trigpin,LOW);

  duration3=pulseIn(echopin3,HIGH);

  distance3=duration3*0.034/2;

  buttonstate=digitalRead(pushbutton);

 
if(buttonstate==LOW)
{

  if(distance3>=176&&distance3<=180)
  {
    digitalWrite(buzz,HIGH);
    tone(4000,200);
    delay(1000);
    digitalWrite(buzz,LOW);
  }

}
  //codeblock for vibrating motor
  else
  {
  
    digitalWrite(mot,HIGH);
    delay(1500);
    digitalWrite(mot,LOW);
    delay(500);
  }
  
}



 


//function for repetitive output

void loop() 
{
  ultrasonic1();
  ultrasonic2();
  if(check==LOW)
  {
    ultrasonic3;
  }
  water1();
}



 
  
