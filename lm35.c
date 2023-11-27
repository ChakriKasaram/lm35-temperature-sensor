// Include necessary libraries
//#include <Arduino.h>

// Define LM35 sensor pin
const int lm35Pin = A0;

// Define onboard LED pin
const int ledPin = 13;

// Function declarations
float readTemperature();
void controlLED(int interval);

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // For debugging, optional
}

void loop() {
  // Read temperature from LM35 sensor
  float temperature = readTemperature();
  
  // Print temperature for debugging, optional
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Check temperature conditions and control LED blink
  if (temperature < 30.0) {
    controlLED(250);
  } else if (temperature > 30.0) {
    controlLED(500);
  }
}

// Function to read temperature from LM35 sensor
float readTemperature() {
  // Read analog value from LM35 sensor
  int sensorValue = analogRead(lm35Pin);

  // Convert analog reading to temperature in degrees Celsius
  float tempCelsius = (sensorValue * 5.0 / 1023.0) * 100.0;

  return tempCelsius;
}

// Function to control onboard LED based on temperature
void controlLED(int interval) {
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    digitalWrite(ledPin, !digitalRead(ledPin)); // Toggle LED state
    previousMillis = currentMillis;
  }
}
