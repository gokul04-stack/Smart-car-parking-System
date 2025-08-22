#define TRIG1 2
#define ECHO1 3
#define TRIG2 4
#define ECHO2 5
#define TRIG3 6
#define ECHO3 7

const int THRESHOLD = 15;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG1, OUTPUT); pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT); pinMode(ECHO2, INPUT);
  pinMode(TRIG3, OUTPUT); pinMode(ECHO3, INPUT);
}

void loop() {
  int dist1 = getDistance(TRIG1, ECHO1);
  checkSlot(1, dist1);

  int dist2 = getDistance(TRIG2, ECHO2);
  checkSlot(2, dist2);

  int dist3 = getDistance(TRIG3, ECHO3);
  checkSlot(3, dist3);

  Serial.println("-----------------------");
  delay(2000);
}

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

void checkSlot(int slot, int distance) {
  if (distance > 0 && distance < THRESHOLD) {
    Serial.print("Slot "); Serial.print(slot); Serial.println(": ENGAGED");
  } else {
    Serial.print("Slot "); Serial.print(slot); Serial.println(": AVAILABLE");
  }
}
