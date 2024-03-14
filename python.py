# Author: Kaibo Huang
# Description: Python-end code that uses Python's in-built speech recognition
# and audio libraries to convert user speech into strings that are transmitted
# into an Arduino UNO using the serial module.

import speech_recognition as sr
import serial
import time

# Set up serial communication with Arduino on COM3 at a baud rate of 9600
ser = serial.Serial('COM3', 9600, timeout=0)
recognizer = sr.Recognizer()

def recognize_speech():
    # Use the microphone as the audio source
    with sr.Microphone() as source:
  	println("-------------------------------------")
	println("");
        println("Setting up microphone...")
        recognizer.adjust_for_ambient_noise(source)  # Adjust for ambient noise
        print("Microphone ready. Say something:")
        
        # Listen for audio with a timeout of 15 seconds
        audio = recognizer.listen(source, timeout=15)

    try:
        # Recognize speech using Google Speech Recognition
        text = recognizer.recognize_google(audio)
        print("You said: " + text)
        return text
    except sr.UnknownValueError:
        print("Google Speech Recognition could not understand audio")
    except sr.RequestError as e:
        print("Could not request results from Google Speech Recognition service; {0}".format(e))

# Continuous loop for speech recognition and communication with Arduino
while True:
    # Get the recognized text from speech
    recognized_text = recognize_speech()

    if recognized_text:
        print("Sending text to Arduino...")
        # Encode the text and send it to Arduino via serial communication
        ser.write(recognized_text.encode())
        # Give some time for Arduino to process the message
        time.sleep(1)

# Close the serial connection when the loop is terminated
ser.close()
