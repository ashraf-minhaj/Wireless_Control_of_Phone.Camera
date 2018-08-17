/* Control any cell phone camera with Arduino Wirelessly******
   By Ashraf Minhaj. Find him at ashraf_minhaj@yahoo.com
  youTube channel www.youtube.com/c/fusebatti  */

 /* This is a demo code with a proximity sensor on how to Trigger 
    the camera of your cell Phone by Arduino. You can make Ultrasound
    Motion sensor or PIR sensor to work as a Motion sensing anti theft 
    Camera system.
  *  It's just an Idea , The Sky is the Limit */
  
int trig = 13;
void setup() 
{
  pinMode(trig,OUTPUT);
  Serial.begin(9600);   // initialize serial communication at 9600 bits per second:
}


void loop()                // the loop routine runs over and over again forever:
{
    int sensorValue = analogRead(A0);     // read the input on analog pin 0:
  Serial.println(sensorValue);        // print out the value you read:
  delay(1);        // delay in between reads for stability

  if(sensorValue > 900)      //Something is detected/ object has been stolen
  {
    digitalWrite(trig,HIGH);  //trigger the camera
    delay(100);
    digitalWrite(trig,LOW);
    delay(1000);            // delay 1 sec_Take a picture in every second
  }
  else
  {
    digitalWrite(trig,LOW);
    
  }
}
