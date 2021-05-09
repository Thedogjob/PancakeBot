#define UpPin 8
#define DownPin 3
int val = 0;

void setup() {
  pinMode(UpPin, INPUT);
  pinMode(DownPin, OUTPUT);
  
}

void loop() {
  val = digitalRead(UpPin);
  Serial.println(val);
  Serial.println("breh");
}
