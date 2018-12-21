// Variables for storing data
// The ints for the pins are for the mapping of the hardware
int connectionPin = 10;
int pulsePin = 11;

char shockData = 0;

void setup() {
    // Sets the baud for serial data transmission
    Serial.begin(9600);
    // Sets digital pin 13 as output pin
    pinMode(13, OUTPUT);
    // sets the digital pin as output
    pinMode(connectionPin, OUTPUT);
    // sets the digital pin as output
    pinMode(pulsePin, OUTPUT);
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    // Send data only when you receive data:
    if (Serial.available() > 0) { 
        // Read the incoming data & store into data
        shockData = Serial.read();
        // Print Value inside data in Serial monitor
        Serial.print(shockData);
        Serial.print("\n");
        // Checks whether value of data is equal to '1' or '0'
        if (shockData == '1') {
            //If value is 1 then LED turns ON
            digitalWrite(13, HIGH);
            // sets the Red LED on
            digitalWrite(connectionPin, HIGH);
        } else if (shockData == '0') {
            //If value is 0 then LED turns OFF
            digitalWrite(13, LOW);
            // sets the Red LED off
            digitalWrite(connectionPin, LOW);
        }
    }
    // Breadboard LEDs
    while(true) {
        // sets the Green LED on
        digitalWrite(pulsePin, HIGH);
        // waits for one and a half seconds
        delay(666);
        digitalWrite(connectionPin, HIGH);
        delay(200);
        // sets the Green LED off
        digitalWrite(pulsePin, LOW);
        delay(200);
        digitalWrite(connectionPin, LOW);
    }
    // Onboard LEDs
    while(true) {
        // turn the LED on (HIGH is the voltage level)
        digitalWrite(LED_BUILTIN, HIGH);
        delay(50);
        // turn the LED off by making the voltage LOW
        digitalWrite(LED_BUILTIN, LOW);
        delay(50);
    }
}
