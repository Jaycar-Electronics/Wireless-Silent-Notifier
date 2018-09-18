

#define SIREN_TIME 4 //make siren/bell/strobe last for 4 seconds.


void setup() {
  // put your setup code here, to run once:
  pinMode(13,INPUT);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
  Serial.begin(9600);
}

void loop() {

  int count = 0;
  int state = digitalRead(13);
  
  while(state == digitalRead(13)){ //we read two bits being the same
    delayMicroseconds(100);        //quanitization; let's just sample every 0.1 millisconds
    count++;                      //increment the number of successive bits we've got.

    if(count > 400){              //if we've got more than 400 bits of the same value then it's our blasted signal

		/*
		* Here is where we would actively try to decode the signal if it was an intelligent signal
		* for instance, we could count the number of bits, or shift in the bits to make for a byte of data
		* There's possibly even libraries for that, but for our purposes, we're just blasting the airwaves with 
		* data.
		*/
      Serial.print(count,DEC);    //print output to serial if needed 
      Serial.println();
      digitalWrite(8,HIGH);       //turn on the siren
      delay(SIREN_TIME * 1000);   //wait SIREN_TIME amount of  seconds
      digitalWrite(8,LOW);        //turn siren off again
	  break; 					  //break from loop and restart
    }
  }
}
