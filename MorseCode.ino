/*
 * Author: Kaibo Huang
 * Auduino-end code that receives input from Python's in-built speechrecognition and audio 
 * libraries and translates it with visual and auditory Morse code signals through an LED and speaker.
 */

#include <Arduino.h>

String receivedString;
int led8 = 8;        // Pin to control the LED
int audio6 = 6;      // Pin to control the speaker
int note = 1200;      // Music note/pitch

// Morse code timings
int dotLen = 100;     // Length of the morse code 'dot'
int dashLen = dotLen * 3;    // Length of the morse code 'dash'
int elemPause = dotLen;  // Length of the pause between elements of a character
int Spaces = dotLen * 3;     // Length of the spaces between characters
int wordPause = dotLen * 3;  // Length of the pause between words

void setup() {
  Serial.begin(9600); 
  //set pins 6 and 8 as output
  pinMode(led8, OUTPUT); 
  pinMode(audio6, OUTPUT); 
}

void loop() {
  // Read a line from the serial port
  receivedString = Serial.readStringUntil('\n');

  // Process the received Morse code string by looping through each character
  for (int i = 0; i < receivedString.length(); i++) {
    char tmpChar = receivedString[i];
    tmpChar = toLowerCase(tmpChar);
    GetChar(tmpChar);
  }
}

// Function to handle a Morse code dot
void MorseDot() {
  // LED
  digitalWrite(led8, HIGH);
  delay(dotLen);
  digitalWrite(led8, LOW);

  // Speaker
  tone(audio6, note, dotLen);
  delay(dotLen);
  noTone(audio6);
}

// Function to handle a Morse code dash
void MorseDash() {
  // LED
  digitalWrite(led8, HIGH);
  delay(dashLen);
  digitalWrite(led8, LOW);

  // Speaker
  tone(audio6, note, dashLen);
  delay(dashLen);
  noTone(audio6);
}

// Function to turn off LED and speaker 
void LightsOff(int delayTime) {
  digitalWrite(led8, LOW);
  noTone(audio6);
  delay(delayTime);
}

// Function to translate a character to Morse code
void GetChar(char tmpChar){
  switch (tmpChar) {
    case 'a': 
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'b':
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'c':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'd':
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'e':
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'f':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'g':
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'h':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'i':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'j':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
      case 'k':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'l':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
      case 'm':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'n':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'o':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'p':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'q':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'r':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 's':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 't':
      MorseDash();
    LightsOff(elemPause);
    break;
    case 'u':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'v':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'w':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'x':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'y':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'z':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    default: 
    LightsOff(Spaces);      
  }
}
