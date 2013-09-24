// 5 white LEDs, analog pins: 5,6 ; digital pins: A2, A4, A3
int LED[] = {5, 6, A2, A4, A3};
int brightness = 0;
int fadeAmount = 5;
boolean unfinished = true; 
boolean DEBUG = false;

void setup(){
    // digital pins need to be declared as output
    pinMode(LED[2], OUTPUT); 
    pinMode(LED[3], OUTPUT);
    pinMode(LED[4], OUTPUT);
    // debug mode on/off 
    if (DEBUG){               
        Serial.begin(9600);
    }
}

void loop() {
    for (int i = 0; i<= 4; i++){ 
        while (unfinished){
            // routine for analog pins
            if(i == 0 || i == 1){ 
                analogWrite(LED[i], brightness);
                brightness = brightness + fadeAmount;
                if (brightness == 255) {
                    fadeAmount = -fadeAmount ; 
                }
                if (brightness == 0){
                    unfinished = false;
                    fadeAmount = -fadeAmount;
                    analogWrite(LED[i], LOW);
                }
                delay (10);
            }
            // routine for digital pins
            else{
                digitalWrite(LED[i], HIGH);
                delay (500);
                digitalWrite(LED[i], LOW);
                unfinished = false;
            }
            // debug mode writer
            if (DEBUG){
                Serial.print("loop_nr: "); 
                Serial.print(i);  
                Serial.print("\t"); 
                Serial.print("brightness: ");   
                Serial.print(brightness);
                Serial.print("\t"); 
                Serial.print("loop finished: ");   
                Serial.println(unfinished);
            }
        }
        unfinished = true;
    }
  
}
