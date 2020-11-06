#pragma config(Motor,  port2,	rightMotor,	tmotorNormal, openLoop)
#pragma config(Motor,  port3, leftMotor,	tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6, clawMotor,	tmotorNormal, openLoop)
#pragma config(Motor,  port7, armMotor,		tmotorVex393, openLoop, reversed)
#pragma config(Sensor, in8,  armPot, sensorPotentiometer)
#pragma config(Sensor, dgtl11,  button,        sensorDigitalIn)

// remote controller

task main()
{
	int prev=0;
	int new=0;
while(1 == 1)
	//if(vexRT[Btn8D] == 1 || SensorValue[button] == 0){
  //		break;
  //	}
	for(int i = 0; i<1000;i++){
		wait1Msec(1);

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
    //upp og nidur
    if(vexRT[Ch2]>0){
    	motor[armMotor] = vexRT[Ch2]/2;
    }
    else if(vexRT[Ch2]<0){
    	motor[armMotor] = vexRT[Ch2]/6;
    }

    new = SensorValue[armPot];

    //writeDebugStreamLine("new: %d", new);
    //writeDebugStreamLine("prev: %d", prev);

    //wait1Msec(5);


    /*if(vexRT[Ch1] < 5 && vexRT[Ch1] > -5 && new-prev != 0)
		{
			//motor[armMotor] = 127;
		}
		/*else if(vexRT[Btn5D] == 1)
		{
			motor[armMotor] = -127;
		}
		else
		{
			motor[armMotor] = 0;
		}*/


  }
  writeDebugStreamLine("%d", new-prev);
	prev = SensorValue[armPot];
	}
}
