
int ledR = 9;	// LED is connected to digital pin 9 
int ledB = 10;	// LED is connected to digital pin 10
int ledG = 11;	// LED is connected to digital pin 11
int sensorPin = A6;	// light sensor
int sensorValue;	// variable to store the value coming from the sensor
int brightnessR = 0;    // 0=max 255=min
int brightnessB = 0; 
int brightnessG = 0; 
int colourmode = 0;
void setup()	 
{	 
         pinMode(ledR, OUTPUT);	// sets the ledRed to be an output
         pinMode(ledB, OUTPUT);	// sets the ledBlue to be an output
         pinMode(ledG, OUTPUT);	// sets the ledGreen to be an output
         Serial.begin(9600);	//initialize the serial port
         analogWrite(ledR, brightnessR);    
         analogWrite(ledB, brightnessB);    
         analogWrite(ledG, brightnessG); 
         delay(500);
}	 
 	 
void loop()	// run over and over again
{	 
   // set the brightness of the led pin:
          sensorValue = analogRead(sensorPin);	// read the value from the sensor
          Serial.println(sensorValue);	// send that value to the computer
          
          if (sensorValue <= 1){
            switch (colourmode) {
                case 0:
                  brightnessR = 0;
                  brightnessB = 255;
                  brightnessG = 255;
                  break;
                case 1:
                  brightnessR = 255;
                  brightnessB = 0;
                  break;
                case 2:
                  brightnessB = 255;
                  brightnessG = 0;
                  break;
                  }        
              colourmode = (colourmode + 1) % 3;
          }
              analogWrite(ledR, brightnessR);    
              analogWrite(ledB, brightnessB);    
              analogWrite(ledG, brightnessG);  
          delay(500);	// delay for 1/10 of a second
}	 
 	 
