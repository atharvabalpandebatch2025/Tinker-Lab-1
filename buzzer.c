// C++ code
//

const int LM32_PIN = A0;
const int BUZZER_PIN = 8;
const int LED_PIN = 10;
float threshholdC = 30.0;
unsigned long readInterval = 2000;
unsigned long lastRead = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  Serial.println("LM32");
}

void loop() {
  unsigned long now = millis();
  if (now - lastRead >= readInterval) {
    lastRead = now;
    int raw = analogRead(LM32_PIN);
    float voltage = raw * (5.0 / 1023.0);
    float tempC = voltage / 0.01;
    if (tempC >= threshholdC) {
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);

    } else {
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
    }
  }

  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
