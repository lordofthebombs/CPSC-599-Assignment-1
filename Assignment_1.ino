// digital pin 2 has a pushbutton attached to it
int pushButton = 2;
int LED = LED_BUILTIN;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  // make LED's pin an output:
  pinMode(LED, OUTPUT);
}


// dot part of morse code
void dot() {
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);
}

// dash part of morse code
void dash() {
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
  delay(100);
}


// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);        // delay in between reads for stability


  // Spells out BADER in morse code
  // Need those delays of 200 since each space between letters is 3 time units
  if (buttonState == 1) {
    dash(); dot(); dot(); dot(); delay(200); dot(); dash(); delay(200); dash(); dot(); dot(); delay(100); dot(); delay(200); dot(); dash(); dot();
  }

}
