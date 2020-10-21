#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Moving Forward -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs your robot to move forward at full power for three seconds.  There is a    *|
|*  two second pause at the beginning of the program.                                                 *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Power levels that can be assigned to a motor port range from -127 (full reverse) to         *|
|*        127 (full forward).                                                                         *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor Port 2        rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor Port 3        leftMotor           VEX 3-wire module     Left side motor                   *|
\*-----------------------------------------------------------------------------------------------4246-*/


#define BASETIME 900
int power = -80;
void drive(int increment, int dir){
	motor[rightMotor] = power*dir;
	motor[leftMotor]  = power*dir;
	wait1Msec(BASETIME*increment);
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	writeDebugStream("drove %d m, in %d direction\n", increment*0.5, dir);
}

task main(){
	clearDebugStream();
	for(int i = 1; i<6;i++){
		drive(i, 1);
		wait1Msec(500);
		drive(i, -1);
		wait1Msec(500);
	}
	/*float dist=0.5;
	for(int i=1; i<5; i++){
		drive(dist*i, 1);
		drive(dist*i, -1);
	}*/
}
