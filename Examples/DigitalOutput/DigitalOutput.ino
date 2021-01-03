#define D2 2
#define D4 4
#define D5 5
#define RX0 3
#define D12 12
#define D13 13
#define D14 14
#define D15 15
#define RX2 16
#define TX2 17
#define D18 18
#define D19 19
#define D21 21
#define D22 22
#define D23 23
#define D25 25
#define D26 26
#define D27 27
#define D32 32
#define D33 33

const int Dpin = D2;

bool LEDstate = false;

void setup() {
  Serial.begin(9600);
  pinMode(Dpin, OUTPUT);
}

void loop() {
  static unsigned long timer = millis();
  if (millis() - timer > 1000) {
    timer = millis();
    LEDstate = !(LEDstate);
  }

  digitalWrite(Dpin,LEDstate);
  Serial.print("GPIO" + String(Dpin) + " state: ");
  Serial.println(LEDstate);
}
