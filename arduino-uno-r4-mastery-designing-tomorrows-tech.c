#include <stdio.h> // Illustrative serial

#define OUTPUT 1 // Output
#define INPUT 0 // Input

// Pins for LED and button on UNO R4 (use onboard LED at D13)
static const int LED_PIN = 13; // Onboard LED
static const int BUTTON_PIN = 7; // External button

// Stubs
void pinMode(int pin, int mode) { /* set */ } // Configure
void digitalWrite(int pin, int val) { /* write */ } // Write
int digitalRead(int pin) { return 1; } // Read
void delay(int ms) { /* wait */ } // Delay
void Serial_begin(long baud) { printf("Serial start %ld\n", baud); } // Serial
void Serial_println(const char *s) { printf("%s\n", s); } // Println
void analogWrite(int pin, int pwm) { /* pwm */ } // PWM

void setup(void) { // Initialize
  pinMode(LED_PIN, OUTPUT); // LED output
  pinMode(BUTTON_PIN, INPUT); // Button input
  Serial_begin(9600); // Serial
  Serial_println("UNO R4 Mastery ready"); // Status
}

void fadeLED(void) { // Fade LED using PWM
  for (int v = 0; v <= 255; ++v) { // Ramp up
    analogWrite(LED_PIN, v); // Set brightness
    delay(5); // Small delay
  } // End ramp up
  for (int v = 255; v >= 0; --v) { // Ramp down
    analogWrite(LED_PIN, v); // Set brightness
    delay(5); // Small delay
  } // End ramp down
}

void loop(void) { // Main loop
  int pressed = (digitalRead(BUTTON_PIN) == 0); // Read button
  if (pressed) { // If pressed
    Serial_println("Button pressed: LED fade"); // Feedback
    fadeLED(); // Run fade
  } else { // Not pressed
    digitalWrite(LED_PIN, 0); // LED off
  } // End condition
  delay(50); // Loop delay
}

int main(void) { // Entry point
  setup(); // Init
  for (int i = 0; i < 10; ++i) { // Simulated cycles
    loop(); // Execute
  } // End
  return 0; // Exit
}

