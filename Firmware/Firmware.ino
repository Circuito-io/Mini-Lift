// Include Libraries
#include "Arduino.h"
#include "BTHC05.h"


// Pin Definitions
#define BTHC05_PIN_RXD	10
#define BTHC05_PIN_TXD	11
#define STEPPER_PIN_STEP	2
#define STEPPER_PIN_DIR	3

const int stepPeriod = 300;
const int liftHeightInSteps = 10000;
// Global variables and defines

// object initialization
BTHC05 bthc05(BTHC05_PIN_RXD,BTHC05_PIN_TXD);


/* This code sets up the essentials for your circuit to work. It runs first every time your circuit is powered with electricity. */
void setup() {
  // Setup Serial which is useful for debugging
  // Use the Serial Monitor to view printed messages
  Serial.begin(9600);
  Serial.println("start");

  pinMode(STEPPER_PIN_STEP,OUTPUT);
  pinMode(STEPPER_PIN_DIR,OUTPUT);

  
  //bthc05.begin(9600);
  //This example uses HC-05 Bluetooth to communicate with an Android device.
  //Download bluetooth terminal from google play store, https://play.google.com/store/apps/details?id=Qwerty.BluetoothTerminal&hl=en
  //Pair and connect to 'HC-05', the default password for connection is '1234'.
  //You should see this message from your arduino on your android device
  
  bthc05.println("Bluetooth On....");
}

/* This code is the main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop. */
void loop() {
  String bthc05Str = "";
  //Receive String from bluetooth device
  if (bthc05.available())
  {
    //Read a complete line from bluetooth terminal
    bthc05Str = bthc05.readStringUntil('\n');
    // Print raw data to serial monitor
    Serial.print("BT Raw Data: ");
    Serial.println(bthc05Str);
  }
  //Send sensor data to Bluetooth device
  //Serial.println("PUT YOUR SENSOR DATA HERE");

  if (bthc05Str == "u")
  {
    //Move stepper motor 250 steps relative to last position
    moveStepper(liftHeightInSteps, 1, stepPeriod );
  }
 
  if (bthc05Str == "d")
  {
    //Move stepper motor 250 steps relative to last position
    moveStepper(liftHeightInSteps, 0, stepPeriod );
  }
}


void moveStepper(int steps, bool dir, int timePeriod)
{
  digitalWrite(STEPPER_PIN_DIR,dir);
  for(int i=0 ; i< steps ; i++)
  {
    digitalWrite(STEPPER_PIN_STEP, HIGH);
    delayMicroseconds(timePeriod);
    digitalWrite(STEPPER_PIN_STEP, LOW);
    delayMicroseconds(timePeriod);
  }

  
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/
