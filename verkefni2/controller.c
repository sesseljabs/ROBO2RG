#pragma config(Motor,  port2,	rightMotor,	tmotorNormal, openLoop)
#pragma config(Motor,  port3, leftMotor,	tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6, clawMotor,	tmotorNormal, openLoop)
#pragma config(Motor,  port7, armMotor,		tmotorVex393, openLoop, reversed)
#pragma config(Sensor, in8,  armPot, sensorPotentiometer)
#pragma config(Sensor, dgtl11,  button,        sensorDigitalIn)

// remote controller

task main()
{
	while(1 == 1)
	{
  	if(vexRT[Btn8D] == 1 || SensorValue[button] == 0){
  		break;
  	}
   	// driving and turning
    motor[leftMotor]  = (vexRT[Ch3] + vexRT[Ch1])/2;
    motor[rightMotor] = (vexRT[Ch3] - vexRT[Ch1])/2;
    //writeDebugStreamLine("%d", vexRT[Ch3]);

    //Arm Control
    // klibba
    if(vexRT[Btn6U] == 1)
    {
      motor[clawMotor] = 40;
    }
    else if(vexRT[Btn6D] == 1)
    {
      motor[clawMotor] = -40;
    }
    else
    {
      motor[clawMotor] = 0;
    }
    //upp og nidur hond
    if(vexRT[Ch2]>0){
    	motor[armMotor] = vexRT[Ch2];
    }
    else if(vexRT[Ch2]<0){
    	motor[armMotor] = vexRT[Ch2]/3;
    }
	}
}
