const int buttonPin = 6; // The digital pin the push button is connected to
const int LED_BUILTIN = 13;   // The digital pin the built-in LED is connected to

const char* morseCode = "-.-- .- ... .... -- .. -"; // Morse code for "Yashmit"
const int dotDuration = 250; // Duration of a dot

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) 
  {
    blinkMorseCode();
    delay(1000); // Delay to prevent rapid re-triggering
  }
}

void blinkMorseCode()
 {
  for (int i = 0; morseCode[i] != '\0'; i++) 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    if (morseCode[i] == '.') 
    {
      delay(dotDuration);
    } 
    else if (morseCode[i] == '-') 
    {
      delay(dotDuration * 3); 
    }
    digitalWrite(LED_BUILTIN, LOW);
    delay(dotDuration); // Gap between dots and dashes
    delay(dotDuration); // Gap between characters
  }
  delay(dotDuration * 3); // Gap between words
}