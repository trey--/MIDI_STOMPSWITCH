#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

//all arrays will be accessed i>= 0 && i< array.length
//buttonpint need to be initialized separately to correspond to their respective pins
//this can be done with a loop if the buttons are in line 
// or manually {2, 5 ,7, ...etc}

// constants won't change. They're used here to 
// set pin numbers:
const int NUMBER_OF_BUTTONS = 10;
int buttonPin[NUMBER_OF_BUTTONS];    // the number of the pushbutton pin //will need to initialize in setup with a for loop or manually here
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState[NUMBER_OF_BUTTONS]; // the current reading from the input pin - uninit to 0
int lastButtonState[NUMBER_OF_BUTTONS];   // the previous reading from the input pin
int offset = 2; // offset if buttons are initialized with loop


// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime[NUMBER_OF_BUTTONS];  // the last time the output pin was toggled
long debounceDelay[NUMBER_OF_BUTTONS];    // the debounce time; increase if the output flickers


void initPins(){
      for(int i=0; i < NUMBER_OF_BUTTONS; i++){ // initialize array pins ex: [0]=2 [1]=(ex pin 3) [2]=4 ...etc
       buttonPin[i] = i + offset;
  
       for(int i=0; i < NUMBER_OF_BUTTONS; i++){ // setup each button for input 
        pinMode(buttonPin[i], INPUT);
       }
      }
}// end initPins


void initStatesNTime(){
   for(int i=0; i < NUMBER_OF_BUTTONS; i++){
     lastButtonState[i] = LOW;
   }

   for(int i=0; i < NUMBER_OF_BUTTONS; i++){
     lastDebounceTime[i] = 0;
     debounceDelay[i]=50;
   }   
   

}//end initStates




void setup() {

  delay(5000);//delay for power to system
  
  initPins();
  initStatesNTime();
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  //serial monitor, comment when midi is connected
  //Serial.begin(31250); //uncomment when midi is connected 

  // set initial LED state
  digitalWrite(ledPin, ledState);
  Serial.println("system ready"); 
}

void loop() {
  // read the state of the switch into a local variable:
  
  int reading[NUMBER_OF_BUTTONS];
  
  //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  for(int i=0; i<NUMBER_OF_BUTTONS; i++){ 
  reading[i] = digitalRead(buttonPin[i]);

  
  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading[i] != lastButtonState[i]) {
    // reset the debouncing timer
    lastDebounceTime[i] = millis();
  }////////////////////////////////
  
  //---------------------------------------------------
  if ((millis() - lastDebounceTime[i]) > debounceDelay[i]) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    // if the button state has changed:
    if (reading[i] != buttonState[i]) {
      buttonState[i] = reading[i];


      
          // only toggle the LED if the new button state is HIGH
          //if (buttonState[i] == HIGH) {
            
            //--------------Trey------------------ // MIDI.sendNoteOn( control number, velocity, channel); 
               if(i == 0){
                  //ledState = !ledState;
                  MIDI.sendNoteOn( 16, 127, 1);
                  delay(10);
                  MIDI.sendNoteOff( 16, 127, 1);
                  Serial.println("0sdfasdfasdfasdfa"); //for testing

                  }
                  
               if(i == 1){
                  //ledState = !ledState;
                  MIDI.sendNoteOn( 17, 127, 1);
                  delay(10);
                  MIDI.sendNoteOff( 17, 127, 1);
                  Serial.println("1;ajds;flk"); //for testing
                  }
  
               if(i == 2){
                  //ledState = !ledState;
                  MIDI.sendNoteOn( 18, 127, 2);
                  delay(10);
                  MIDI.sendNoteOff( 18, 127, 2);
                  Serial.println("2"); //for testing
                  }
                  
                 if(i == 3){
                  //ledState = !ledState;
                  MIDI.sendNoteOn( 19, 127, 2);
                  delay(10);
                  MIDI.sendNoteOff( 19, 127, 2);
                  Serial.println("3"); //for testing
                  }
                  
                 if(i == 4){
                  //ledState = !ledState;
                  MIDI.sendNoteOn( 20, 127, 1);
                  delay(1);
                  MIDI.sendNoteOff( 20, 127, 1);
                  Serial.println("4"); //for testing
                  }
                  
              //----------------Leo-------------------    
                 if(i == 5){
                  //ledState = !ledState;
                  MIDI.sendNoteOn( 16, 127, 2);
                  delay(1);
                  MIDI.sendNoteOff( 16, 127, 2);
                  Serial.println("5"); //for testing
                  }
                 if(i == 6){
                  //ledState = !ledState;
                  MIDI.sendNoteOn( 17, 127, 2);
                  delay(1);
                  MIDI.sendNoteOff( 17, 127, 2);
                  Serial.println("6"); //for testing
                  }
                 if(i == 7){
                  //ledState = !ledState;
                  MIDI.sendNoteOn( 18, 127, 2);
                  delay(1);
                  MIDI.sendNoteOff( 18, 127, 2);
                  Serial.println("7"); //for testing
                  }
                 if(i == 8){
                  //ledState = !ledState;
                  MIDI.sendNoteOn( 19, 127, 2);
                  delay(1);
                  MIDI.sendNoteOff( 19, 127, 2);
                  Serial.println("8"); //for testing
                  }
                 if(i == 9){
                  //ledState = !ledState;
                  MIDI.sendNoteOn( 20, 127, 2);
                  delay(1);
                  MIDI.sendNoteOff( 20, 127, 2);
                  Serial.println("9"); //for testing
                  }                
          //  }///////////////////////////////
    }//=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-
    
  }//------------------------------------------------------
  
  // set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState[i] = reading[i];
  
  }//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  
}//
