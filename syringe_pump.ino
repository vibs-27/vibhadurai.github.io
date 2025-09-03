// Library
#include <AccelStepper.h>
#include <LiquidCrystal_I2C.h>

// pins
#define size 2 //interupt pin for changing size
#define step 10 // step pin for stepper controller
#define dir 11 // direction pin for stepper controller
#define emergency 3 // interput pin for stopping at end of travel path
#define controlbutton 4 // start pause
#define greenLED 5 // connected to green pin on led
#define redLED 6 // connected to red pin on led
#define esp 7 // connected to esp32 for remote control
#define flowrate_but 8 // controls whether flowrate is controlled by potentiometer
#define forward 12 // manual forward
#define backward 13 // manual reverse

int analog = A0; // reading potentiometer
int read = 0; // potentiometer value
double speed; // speed set by potentiometer
double speed_s; //set program speed
volatile bool sizeChangeFlag = false; //interupt contingency
volatile bool estop = false; // interupt contingency
unsigned long lastLCDUpdate = 0; // Variable to track the last update time
const unsigned long lcdInterval = 1000; // Update LCD every 1 second

// flowrate
#define flowrate 5 // mL
#define twenty_mL 2.28018 // volume pushed per revolution
#define ten_mL 1.40992 // volume pushed per revolution
#define microstep 3200.00 //microstep resolution

AccelStepper stepper(AccelStepper::DRIVER, step, dir); //initialize stepper motor

LiquidCrystal_I2C lcd(0x27,16,2); //contact lcd screen

void setup() {

  //pins
  pinMode(controlbutton, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(esp, INPUT_PULLUP);

  pinMode(emergency, INPUT_PULLUP);
  pinMode(flowrate_but, INPUT_PULLUP);
  pinMode(forward, INPUT_PULLUP);
  pinMode(backward, INPUT_PULLUP);
  pinMode(size, INPUT_PULLUP);

  //interupt
  attachInterrupt(digitalPinToInterrupt(emergency), eStopISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(size), sizeChangeISR, CHANGE);

  stepper.setMaxSpeed(1000); // set maximum stepper motor
  speed_s = (microstep/60) * (flowrate/twenty_mL);
  speed = speed_s;

  lcd.init();
  lcd.clear();
  lcd.backlight(); // Make sure backlight is on

  // Welcome message
  lcd.setCursor(3,0); //Set cursor to character 2 on line 0
  lcd.print("Welcome ||");
  lcd.setCursor(11,1); //Move cursor to character 2 on line 1
  lcd.print("_/");

  //Serial.begin(9600); // debugging purposes

  delay(5000); //start up
}

void loop() {
  int i = 0;
  int j;

  // start/pause function
  while (digitalRead(controlbutton) == LOW && digitalRead(emergency)==HIGH) {
    ++i;
    stepper.runSpeed();
    digitalWrite(greenLED, 1);
    digitalWrite(redLED, 0);
    if (i==1) {
      lcd.clear();
      lcd.setCursor(1,0); //Set cursor to character 2 on line 0
      lcd.print("Moving Forward");
    }
  }

  // start/pause function remote
  while (digitalRead(esp) == LOW && digitalRead(emergency)==HIGH) {
    ++i;
    stepper.runSpeed();
    digitalWrite(greenLED, 1);
    digitalWrite(redLED, 0);
    if (i==1) {
      lcd.clear();
      lcd.setCursor(1,0); //Set cursor to character 2 on line 0
      lcd.print("Moving Forward");
    }
  }

  // idle control, moving forward or backward
  if (digitalRead(esp) == HIGH && digitalRead(controlbutton) == HIGH &&
      digitalRead(emergency) == HIGH) {

    //idle
    digitalWrite(greenLED, 1);
    digitalWrite(redLED, 1);

    //manual forward control
    while (digitalRead(forward) == LOW && digitalRead(emergency)==HIGH) {
      ++i;
      stepper.setSpeed(600);
      stepper.runSpeed();
      digitalWrite(greenLED, 1);
      digitalWrite(redLED, 0);
      if (i==1) {
        lcd.clear();
        lcd.setCursor(4,0); //Set cursor to character 2 on line 0
        lcd.print("Forward");
      }
    }

    i=0;
    //manual reverse, capable of being enacted in emergency stop configuration for easy rewinding
    while (digitalRead(backward) == LOW) {
      ++i;
      stepper.setSpeed(-600);
      stepper.runSpeed();
      digitalWrite(greenLED, 1);
      digitalWrite(redLED, 0);
      if (i==1) {
        lcd.clear();
        lcd.setCursor(4,0); //Set cursor to character 2 on line 0
        lcd.print("Backward");
      }
    }

    unsigned long currentMillis = millis();
    if (currentMillis - lastLCDUpdate >= lcdInterval) {
      lcd.clear();
      lcd.setCursor(6,0); //Set cursor to character 2 on line 0
      lcd.print("Idle");
      lastLCDUpdate = currentMillis; // Reset the timer
    }
  }

  // control speed with potentiometer
  while(digitalRead(flowrate_but) == LOW && digitalRead(emergency)==HIGH) {
    read = analogRead(analog); //read potentiomter
    double temp = read / 1024.00 * 10.0 + 1; // translate reading into mL

    // use proper size
    if (size == HIGH) {
      speed = (microstep/60.0) * (temp/twenty_mL);
    } else {
      speed = (microstep/60.0) * (temp/ten_mL);
    }
    stepper.setSpeed(speed);

    // run speed if pressed
    if(digitalRead(controlbutton)==LOW) {
      stepper.runSpeed();
      digitalWrite(greenLED, 1);
      digitalWrite(redLED, 0);
    }
    unsigned long currentMillis = millis();
    if (currentMillis - lastLCDUpdate >= lcdInterval) {
      lcd.clear();
      lcd.setCursor(4, 0); // Set cursor position
      lcd.print("speed(mL)");
      lcd.setCursor(6, 1); // Set cursor position
      lcd.print(temp);
      lastLCDUpdate = currentMillis; // Reset the timer
    }
  }

  //go backward at any point including after an emergency stop
  i=0;
  while (digitalRead(backward) == LOW) {
    ++i;
    stepper.setSpeed(-600);
    stepper.runSpeed();
    digitalWrite(greenLED, 1);
    digitalWrite(redLED, 0);
    if (i==1) {
      lcd.clear();
      lcd.setCursor(4,0); //Set cursor to character 2 on line 0
      lcd.print("Backward");
    }
  }

  // return to embedded preset speed
  if(digitalRead(flowrate_but) == HIGH) {
    stepper.setSpeed(speed_s);
  }

  // interupt for size change
  if (sizeChangeFlag) {
    sizeChange(); // Call the function when the flag is set
    delay(3500);
    sizeChangeFlag = false; // Reset the flag
  }

  // interupt for emergency stop
  if (estop) {
    outOfLiquid();
    estop = false; // Reset the flag
  }
}

// reset interupt flags
void sizeChangeISR() {
  sizeChangeFlag = true; // Set the flag
}
void eStopISR() {
  estop = true; // Set the flag
}

// procedure for size change
void sizeChange() {

  if(digitalRead(size) == LOW && digitalRead(controlbutton)==HIGH &&
     digitalRead(esp)==HIGH) {
    speed_s = (microstep/60) * (flowrate/ten_mL);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("size(mL):");
    lcd.setCursor(7,1);
    lcd.print("10");
  }
  if (digitalRead(size) == HIGH && digitalRead(controlbutton)==HIGH &&
      digitalRead(esp)==HIGH){
    speed_s = (microstep/60) * (flowrate/twenty_mL);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("size(mL):");
    lcd.setCursor(7,1);
    lcd.print("20");
  }
}

// emergency stop
void outOfLiquid() {
  int i = 0;
  stepper.stop();
  digitalWrite(greenLED, 0);
  digitalWrite(redLED, 1);
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("STOP");
  lcd.setCursor(2,1);
  lcd.print("Out of Fluid"); // Call the function when the flag is set

  // stay trapped in emergency stop until system is paused
  // note that system can be reversed in this state
  while (digitalRead(esp) == LOW || digitalRead(controlbutton) == LOW) {
    stepper.stop();
    unsigned long currentMillis = millis();
    if (currentMillis - lastLCDUpdate >= lcdInterval) {
      lcd.clear();
      lcd.setCursor(6,0);
      lcd.print("STOP");
      lcd.setCursor(2,1);
      lcd.print("Out of Fluid"); // Call the function when the flag is set
      lastLCDUpdate = currentMillis; // Reset the timer
    }
  }
}
