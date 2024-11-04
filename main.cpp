#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <WiFiServer.h>
#include <ArduinoJson.h> // Dodanie biblioteki ArduinoJson
#include <Servo.h>       // Dodanie biblioteki Servo

int buttonPin1 = 12;
int buttonPin2 = 13;
int buttonState1 = HIGH;
int lastButtonState1 = HIGH;
int buttonState2 = HIGH;
int lastButtonState2 = HIGH;
int Value = 3;
int lastValue = Value;

void setup()
{
    Serial.begin(115200);
    Wire.begin();

    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
}

void loop()
{
    // Obsługa przycisków
    buttonState1 = digitalRead(buttonPin1);
    if (buttonState1 != lastButtonState1)
    {
        if (buttonState1 == LOW)
        {
            Value += 1;
            if (Value > 10)
            {
                Value = 10;
            }
        }
        lastButtonState1 = buttonState1;
    }

    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2 != lastButtonState2)
    {
        if (buttonState2 == LOW)
        {
            Value -= 1;
            if (Value < 3)
            {
                Value = 3;
            }
        }
        lastButtonState2 = buttonState2;
    }

    // Wyświetlanie Value na konsoli
    if (Value != lastValue)
    {
        Serial.println(Value);
        lastValue = Value;
    }

    delay(50);
}
