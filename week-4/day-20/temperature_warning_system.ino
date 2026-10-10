int redLed = 9; // red led pin
int buzzer = 7; // buzzer pin
int tempSensor = A1; // temperature sensor pin
float tempLimit = 45.0; // temperature threshold in degree celsius

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(tempSensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the temperature sensor
  int sensorValue = analogRead(tempSensor);
  
  // Convert the analog reading to voltage, then to temperature in Celsius
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  // Print temperature value to the Serial Monitor
  Serial.print("Temperature is ");
  Serial.print(temperature);
  Serial.println(" deg C");

  // Check if the temperature exceeds the threshold limit
  if (temperature > tempLimit) {
    digitalWrite(redLed, HIGH); // Turn on red warning LED
    digitalWrite(buzzer, HIGH); // Turn on buzzer alarm
  } else {
    digitalWrite(redLed, LOW);  // Turn off red warning LED
    digitalWrite(buzzer, LOW);  // Turn off buzzer alarm
  }

  delay(500); // Wait 0.5 seconds before the next reading
}
