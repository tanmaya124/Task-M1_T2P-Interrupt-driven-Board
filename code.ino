const int pirSensorPin = 6;
const int ledPin = 8;
const int buttonPin = 2;
volatile bool buttonPressed = false;

void setup() {
  pinMode(pirSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonInterrupt, FALLING);
}

void loop() {
  if (isMotionDetected()) {
    Serial.println("Motion has been detected.");
    blinkLED();
  } else {
    Serial.println("No motion has been detected.");
  }

  if (buttonPressed) {
    Serial.println("You pressed a button");
    blinkLED();
    resetButtonState();
  }
}

void blinkLED() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
}

void handleButtonInterrupt() {
  buttonPressed = true;
}

bool isMotionDetected() {
  return digitalRead(pirSensorPin) == HIGH;
}

void resetButtonState() {
  buttonPressed = false;
}
