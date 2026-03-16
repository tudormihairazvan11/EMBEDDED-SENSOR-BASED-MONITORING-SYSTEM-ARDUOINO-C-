#define LED_PIN 13
#define BUZZER_PIN 8
#define SENSOR_PIN A0

#define OK 0
#define WARNING 1
#define ERROR 2

int read_sensor() {
return analogRead(SENSOR_PIN);
}

int determine_state(int sensor_value) {
// LOGICA INVERSATĂ:
if (sensor_value < 550) { // Dacă valoarea scade mult (LUMINĂ PUTERNICĂ) -> ERROR
return ERROR;
}
else if (sensor_value < 600) { // Dacă e valoare medie -> WARNING
return WARNING;
}
else { // Dacă valoarea e mare (ÎNTUNERIC/NORMAL) -> OK
return OK;
}
}

void apply_outputs(int state) {
if (state == OK) {
digitalWrite(LED_PIN, LOW);
digitalWrite(BUZZER_PIN, LOW);
}
else if (state == WARNING) {
digitalWrite(LED_PIN, HIGH);
digitalWrite(BUZZER_PIN, HIGH);
delay(200);
digitalWrite(LED_PIN, LOW);
digitalWrite(BUZZER_PIN, LOW);
delay(200);
}
else { // ERROR
digitalWrite(LED_PIN, HIGH);
digitalWrite(BUZZER_PIN, HIGH);
}
}

void setup() {
pinMode(LED_PIN, OUTPUT);
pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
int sensor_value = read_sensor();
int state = determine_state(sensor_value);
apply_outputs(state);
}