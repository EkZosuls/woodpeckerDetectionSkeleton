#define WINDOW_LENGTH 600

long accelerometerOutput = 9.8;
int timingPin = 12;
long window[WINDOW_LENGTH] = {9.8};  //holds values to be averaged
int windowIndex = 0;  //where we are in the circular average buffer
long windowSum;   // sum of the values to be averaged
long initialCon = 0;  //this is our "zero" for the integrator reset
long signalAverage = 9.8; // this is the output of the long term average
long amplitude = 0;     // this is the amplitude of the signal with the
                        // background average subtracted off. It should be
                        // zero when it is quite.
long integratorLeak = 0.02;
long integrator = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(timingPin, OUTPUT);
}

void loop() {
  // read acceleration or acoustic sensor "current value"
  //accelerometerOutput = 
  //turn on LED or a pin for timing checking
digitalWrite(timingPin, HIGH);
  // write a point to our average vector
      window[windowIndex] = accelerometerOutput; //read the current MAF into averager
      windowIndex++;  //iterate the DC average index
      windowIndex = windowIndex % WINDOW_LENGTH; //mod math wrap
  
  //calculate the average of the average vector
        //calculate the long term moving average to find the 'zero'
        for(i = 0; i < WINDOW_LENGTH; i++) {
          windowSum = windowSum + window[i];
        }
        signalAverage = windowSum / WINDOW_LENGTH; //this is the new starting point of th
  // subtract this average from the current value and abs
        amplitude = abs(accelerometerOutput - signalAverage);
  //accumulate to the integrator
    //sum integrator and bleed off some of the integration
        integrator = integrator + amplitude - integratorLeak;


  // make a comparison to a threshold 
    //if integrator > some threshold... then scare!!!
      //{scare actions}
      integrator = 0.0;  //integrator and wait for another burst of peck

  // turn off timing LED and pin
digitalWrite(timingPin, HIGH);
  // tune this delay to set a reasonable sample rate
  delay(10);

  

}
