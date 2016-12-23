// Color Detector

// Setup pins
#define pinS0 4
#define pinS1 5
#define pinS2 6
#define pinS3 7
#define pinOut 8

void setup() {

  // Setup output pins
  pinMode(pinS0, OUTPUT);
  pinMode(pinS1, OUTPUT);
  pinMode(pinS2, OUTPUT);
  pinMode(pinS3, OUTPUT);

  // Setup input pin
  pinMode(pinOut, INPUT);

  // Init color detector module
  digitalWrite(pinS0,HIGH);
  digitalWrite(pinS1,LOW);

  // Start serial line
  Serial.begin(9600);

}
void loop() {

  // Color frequences
  int freqRed, freqGreen, freqBlue;

  //// Red

  // Setup Red color detection
  digitalWrite(pinS2,LOW);
  digitalWrite(pinS3,LOW);

  // Delay for precise measurement
  delay(50);

  // Read Red freq value
  freqRed = pulseIn(pinOut, LOW);

  /// Green

  // Setup Green color detection
  digitalWrite(pinS2,HIGH);
  digitalWrite(pinS3,HIGH);

  // Delay for precise measurement
  delay(50);

  // Read Green freq value
  freqGreen = pulseIn(pinOut, LOW);

  //// Blue

  // Setup Blue color detection
  digitalWrite(pinS2,LOW);
  digitalWrite(pinS3,HIGH);

  // Delay for precise measurement
  delay(50);

  // Read Blue freq value
  freqBlue = pulseIn(pinOut, LOW);
  
  // Print frequences over serial line
  Serial.print("R: ");
  Serial.print(freqRed);
  Serial.print(" | G: ");
  Serial.print(freqGreen);
  Serial.print(" | B: ");
  Serial.print(freqBlue);

  // Detect exact color and print to serial line 
  if (freqRed < 60) {
    Serial.print(" | RED ");
        pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);
  }

  if (freqGreen < 60 ) {
    Serial.print(" | GREEN ");
    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);
  }
  
  if (freqBlue < 60) {
    Serial.print(" | BLUE ");
  }

  // Custom color detection
  if (freqRed < 60 & freqGreen < 60 ) {
    Serial.print(" | Detekce zlute. ");
  }

  // Serial new line
  Serial.println();

  // Delay for reading results
  delay(850);

  // Disable LEDs
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

}
