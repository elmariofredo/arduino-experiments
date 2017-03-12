/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}
 
void loop()
{
  
  setColor(0, 255, 0);  // Red
  delay(2000);

  setColor(0, 0, 255);  // Green
  delay(2000);

  setColor(255, 0, 0);  // Blue
  delay(2000);

  
//  delay(2000);
//  setColor(0, 0, 255);  // blue
//  delay(2000);
//  setColor(255, 255, 0);  // yellow
//  delay(2000);  
//  setColor(80, 0, 80);  // purple
//  delay(2000);
//  setColor(0, 255, 255);  // aqua
//  delay(2000);
}
 
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
