// Automated Irrigation System for Vegetable Plants (Simulation)
// Brgy. Union, Mahaplag Elementary School

const int SENSOR_PIN = A0;
const int RELAY_PIN  = 7;

// Potentiometer simulation: 1023 = very dry, 0 = very wet
const int DRY_VALUE = 1023;
const int WET_VALUE = 0;

const int START_BELOW_PERCENT = 40;   // pump ON below 40% moisture
const int STOP_ABOVE_PERCENT  = 60;   // pump OFF above 60% moisture
const unsigned long MAX_PUMP_TIME = 30000UL;  // safety: 30 seconds max

// If the LED behaves the opposite way, swap LOW and HIGH here
const int RELAY_ON  = HIGH;
const int RELAY_OFF = LOW;

bool pumpRunning = false;
unsigned long pumpStartTime = 0;

int readMoisturePercent() {
  long total = 0;
  for (int i = 0; i < 10; i++) {
    total += analogRead(SENSOR_PIN);
    delay(10);
  }
  int raw = total / 10;
  int percent = map(raw, DRY_VALUE, WET_VALUE, 0, 100);
  return constrain(percent, 0, 100);
}

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, RELAY_OFF);
  Serial.println("Irrigation system started.");
}

void loop() {
  int moisture = readMoisturePercent();
  Serial.print("Soil moisture: ");
  Serial.print(moisture);
  Serial.println("%");

  if (!pumpRunning && moisture < START_BELOW_PERCENT) {
    digitalWrite(RELAY_PIN, RELAY_ON);
    pumpRunning = true;
    pumpStartTime = millis();
    Serial.println("Soil is dry. Pump ON.");
  }

  if (pumpRunning) {
    bool wetEnough = moisture > STOP_ABOVE_PERCENT;
    bool timeUp = (millis() - pumpStartTime) > MAX_PUMP_TIME;

    if (wetEnough || timeUp) {
      digitalWrite(RELAY_PIN, RELAY_OFF);
      pumpRunning = false;
      Serial.println("Pump OFF.");
      delay(5000);
    }
  }

  delay(1000);
}