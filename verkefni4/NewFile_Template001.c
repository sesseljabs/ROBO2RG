#pragma config(Sensor, in3,    lineFollowerRIGHT,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in4,    lineFollowerLEFT,    sensorLineFollower)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop, reversed)

task main()
{
  wait1Msec(1200);

  int threshold = 700;

  while(true)
  {
		if(vexRT[Btn8D] == 1 || SensorValue[button] == 0){
  		break;
  	}

    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      motor[leftMotor]  = 40;
      motor[rightMotor] = 0;
    }
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      motor[leftMotor]  = 40;
      motor[rightMotor] = 40;
    }
    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      motor[leftMotor]  = 0;
      motor[rightMotor] = 40;
    }
  }
}
