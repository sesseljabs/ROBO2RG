#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)


void clearEncoders(){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder]  = 0;
}
void wheel(int wheel, int deg){

		while(SensorValue[rightEncoder] < deg | SensorValue[leftEncoder] < deg)
	  {
	  	if (wheel == -1){
				motor[leftMotor]  = (deg/abs(deg))*(-32);
		}
		else if (wheel == 1){
				motor[rightMotor] = (deg/abs(deg))*(-32);
		}
  }
}
void drive(int dist){
	// 12 cm ummal
	dist*=(360*(100/12));

	clearEncoders();
	// tetta er til ad hann fari rolega af stad svo hann spoli ekki
	for(int i = 0; i>-127;i-=1){
  		motor[rightMotor] = (dist/abs(dist))*i;
    	motor[leftMotor]  = (dist/abs(dist))*i;
    	wait1Msec(10);
  	}
	while(SensorValue[rightEncoder] < dist)
  {
    motor[rightMotor] = (dist/abs(dist))*(-127);
    motor[leftMotor]  = (dist/abs(dist))*(-127);
  }

  motor[rightMotor] = 0;
  motor[leftMotor]  = 0;
}
void turn(int deg){
	// eg veit ekki hversu mikid hjolin turfa ad snuast til ad hann fari 90 gradur
	// Also debug stream virkar heldur ekki svo eg er bara ad vonast til ad tetta virki :3
	wheel(-1, deg);
	wheel(1, -deg);
}


task main()
{
	int listi[15] = {1, -1, -1, 1, 1, -1, 1,1, -1,1,1,-1,-1,1,0};
	for(int i = 0; i < 15; i++){
		drive(0.5);
		wait1Msec(100);
		turn(listi[i]*90);
	}

}
