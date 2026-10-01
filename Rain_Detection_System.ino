#define BUZZER_PIN 3
#define LED_PIN 8

bool alarmStarted = false;
unsigned long alarmStartTime = 0;

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);

  Serial.println(sensorValue);

  // Rain detected
  if (sensorValue < 1000 && alarmStarted == false)
  {
    alarmStarted = true;
    alarmStartTime = millis();

    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  }

  // Turn OFF after 10 seconds
  if (alarmStarted == true &&
      millis() - alarmStartTime >= 10000)
  {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Reset when sensor becomes dry
  if (sensorValue >= 1000)
  {
    alarmStarted = false;
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(200);
}
