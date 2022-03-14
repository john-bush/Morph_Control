#include <Arduino.h>

#include <TMCStepper.h>
#include <AccelStepper.h>
#include <DistanceStepper.h>

// #define EN_PIN 38	// Enable
// #define DIR_PIN 55	// Direction
// #define STEP_PIN 54 // Step
// #define CS_PIN 42	// Chip select
// #define SW_RX 63	// TMC2208/TMC2224 SoftwareSerial receive pin
// #define SW_TX 40	// TMC2208/TMC2224 SoftwareSerial transmit pin
//#define SERIAL_PORT Serial1 // TMC2208/TMC2224 HardwareSerial port

#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1


//#define R_SENSE 0.11f // Match to your driver
					  // SilentStepStick series use 0.11
					  // UltiMachine Einsy and Archim2 boards use 0.2
					  // Panucatt BSD2660 uses 0.1
					  // Watterott TMC5160 uses 0.075

//TMC2208Stepper driver = TMC2208Stepper(SW_RX, SW_TX, R_SENSE); // Software serial mode

//AccelStepper stepper = AccelStepper(stepper.DRIVER, STEP_PIN, DIR_PIN);

//constexpr uint32_t steps_per_mm = 80;

DistanceStepper stepper = DistanceStepper(motorInterfaceType, stepPin, dirPin);

void setup()
{
	// pinMode(CS_PIN, OUTPUT);
	// digitalWrite(CS_PIN, HIGH);
	// driver.begin();			 // Initiate pins and registeries
	
	// // ! Need to set this value
	// driver.rms_current(600); // Set stepper current to 600mA. The command is the same as command TMC2130.setCurrent(600, 0.11, 0.5);
	// driver.pwm_autoscale(1);
	// driver.microsteps(16);

	// stepper.setMaxSpeed(50 * steps_per_mm);		  // 100mm/s @ 80 steps/mm
	// stepper.setAcceleration(1000 * steps_per_mm); // 2000mm/s^2
	// stepper.setEnablePin(EN_PIN);
	// stepper.setPinsInverted(false, false, true);
	// stepper.enableOutputs();

	stepper.setMaxSpeed(1000);

}

void loop()
{
	//float t = millis() / 1000;
	
	// Step the motor with a constant speed as set by setSpeed():
	stepper.runSpeed();

	// put your main code here, to run repeatedly:

}