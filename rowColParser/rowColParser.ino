#include <Wire.h>
#include <Adafruit_IS31FL3731.h>
#include <Adafruit_GFX.h>

Adafruit_IS31FL3731 ledmatrix = Adafruit_IS31FL3731();

const int ROWS = 7;
const int COLS = 15;
int rowCount = 0;
int colCount = 0;
int brightness = 2;
int incomingByte=0;
int currByte = 0;
void setup() {
  Serial.begin(9600);
  if (! ledmatrix.begin()) {
    Serial.println("IS31 not found");
    while (1);
  }
  Serial.println("IS31 found!");
for (colCount=0; colCount<=COLS; colCount++) {
for (rowCount=0; rowCount<=ROWS; rowCount++) {
ledmatrix.drawPixel(colCount, rowCount, 10);
delay(10);
}
}
delay(1000);
ledmatrix.clear();
ledmatrix.setCursor(0,0);
ledmatrix.write('A');
delay(1000);
ledmatrix.clear();
}
void loop() {
  if(rowCount<ROWS){
    rowCount++;
  }else{
    rowCount = 0;
if(colCount<COLS){
  colCount++;
}else{
  colCount = 0;
  ledmatrix.clear();
}
  }
ledmatrix.drawPixel(colCount, rowCount, brightness);
delay(25);
}
