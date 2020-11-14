/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// function definition
void BlinkLed();
void TestLora();
void setled();

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;

// finition variable
const int ledPin =  LED_BUILTIN;
unsigned long previousMillis = 0;  
const long interval = 200;  
int ledState = LOW;
bool ReadUartFlag = false; // status of new rx data
int ReadDataValue = 0;
static unsigned long TestVar = 0;

unsigned long CounterLoop = 0; // counter for the loop run

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
 //  pinMode(pushButton, INPUT);
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  CounterLoop = CounterLoop + 1;
  BlinkLed();
  TestLora();
  delay(2000);        // delay in between reads for stability
}

void BlinkLed()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}


void TestLora()
{
  if(TestVar < 20)
  {
    TestVar = TestVar + 1;
  }
  else
  {
    TestVar = 0;
  }
  Serial.println(TestVar);
}
