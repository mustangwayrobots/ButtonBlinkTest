// Define pin numbers
const int LED_PIN = 8;
const int BUTTON_PIN = 6;

// Timing variables for the normal blink (1 second interval: 500ms ON, 500ms OFF)
unsigned long previousMillis = 0;
const long normalInterval = 500; 

// Timing variables for the fast blink (fast interval: 100ms ON, 100ms OFF)
const long fastInterval = 100;

// State tracking for the LED
bool ledState = LOW;

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize the button pin with an internal pull-up resistor
  // (Pressing to GND pulls this LOW)
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Read the current state of the button
  int buttonState = digitalRead(BUTTON_PIN);
  
  // Determine which interval to use based on whether the button is pressed (LOW)
  long currentInterval = (buttonState == LOW) ? fastInterval : normalInterval;
  
  // Get the current time
  unsigned long currentMillis = millis();
  
  // Check if it's time to toggle the LED
  if (currentMillis - previousMillis >= currentInterval) {
    // Save the current time for the next toggle
    previousMillis = currentMillis;
    
    // Toggle the LED state
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }
}