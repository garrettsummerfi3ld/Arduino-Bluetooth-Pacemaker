int pulsePin = 12;
// the setup function runs once when you press reset or power the board
void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    // initialize digital pin 12 as an output pin
    pinMode(pulsePin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    while(true){
        // turn the LED on (HIGH is the voltage level)
        digitalWrite(LED_BUILTIN, HIGH);
        delay(25);
        // turn the LED off by making the voltage LOW
        digitalWrite(LED_BUILTIN, LOW);
        delay(25);
    }
    while(true){
        // turn the LED on (HIGH is the voltage level)
        digitalWrite(pulsePin, HIGH);
        delay(666);
        // turn the LED off by making the voltage LOW
        digitalWrite(pulsePin, LOW);
        delay(666);
    }
}
