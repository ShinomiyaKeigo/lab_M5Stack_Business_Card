#include <M5Stack.h>

void setup() {
    // setup
    M5.begin();
}

void loop() {
    M5.Lcd.println("Hello World!");
    delay(1000);
}