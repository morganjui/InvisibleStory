// This sketch will send out 12 different IR signals installed inside each page of the InvisibleStory book

int IRledPins[12] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 44, 45};

// The setup() method runs once, when the sketch starts
 
void setup()   {                
  // initialize the IR digital pin as an output:
  for (int i = 0; i < sizeof(IRledPins); i ++){
    pinMode(IRledPins[i], OUTPUT);      
  }
 pinMode(13, OUTPUT);
 digitalWrite(13, HIGH);
  Serial.begin(9600);
}
 
void loop()                     
{
  Serial.println("Sending IR signal");
 
  SendCodes();
 
  delay(50);  // wait one minute (60 seconds * 1000 milliseconds)
}
 
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs, int pin) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPins[pin], HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IRledPins[pin], LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void SendCodes() {
  // This is the code for my particular Nikon, for others use the tutorial
  // to 'grab' the proper code from the remote
 
  // PIN 2
  // 581859881
  pulseIR(2080, 0);
  delay(27);
  pulseIR(440, 0);
  delayMicroseconds(1500);
  pulseIR(460, 0);
  delayMicroseconds(3440);
  pulseIR(480, 0);
  delay(65);
 
  // PIN 3
  // 3322665791
  pulseIR(1880, 1);
  delayMicroseconds(2222);
  pulseIR(400, 1);
  delayMicroseconds(1500);
  pulseIR(500, 1);
  delayMicroseconds(650);
  pulseIR(1088, 1);
  delay(45);

 // PIN 4
 // 1236334116
  pulseIR(1200, 2);
  delay(22);
  pulseIR(560, 2);
  delayMicroseconds(2500);
  pulseIR(320, 2);
  delayMicroseconds(2500);
  pulseIR(120, 2);
  delay(70); 

  // PIN 5
  // 286314110
  pulseIR(1250, 3);
  delayMicroseconds(2020);
  pulseIR(560, 3);
  delayMicroseconds(1100);
  pulseIR(440, 3);
  delayMicroseconds(1000);
  pulseIR(580, 3);
  delay(30);

  // PIN 6
  // 3977140024
  pulseIR(1220, 4);
  delayMicroseconds(2020);
  pulseIR(480, 4);
  delayMicroseconds(1080);
  pulseIR(422, 4);
  delayMicroseconds(1080);
  pulseIR(488, 4);
  delay(32);

  // PIN 7
  // 4163671451
  pulseIR(1440, 5);
  delayMicroseconds(1520);
  pulseIR(520, 5);
  delayMicroseconds(1620);
  pulseIR(480, 5);
  delayMicroseconds(1720);
  pulseIR(440, 5);
  delay(32);
  
  // PIN 8
  // 3559530070
  pulseIR(1280, 6);
  delayMicroseconds(1010);
  pulseIR(660, 6);
  delayMicroseconds(1010);
  pulseIR(460, 6);
  delayMicroseconds(808);
  pulseIR(360, 6);
  delay(32);
  
  // PIN 9
  // 2396927248
  pulseIR(1440, 7);
  delayMicroseconds(1020);
  pulseIR(800, 7);
  delayMicroseconds(2880);
  pulseIR(500, 7);
  delayMicroseconds(2880);
  pulseIR(800, 7);
  delay(44);
  
  // PIN 10
  // 3471340161
  pulseIR(520, 8);
  delayMicroseconds(400);
  pulseIR(2020, 8);
  delayMicroseconds(1000);
  pulseIR(2020, 8);
  delayMicroseconds(1000);
  pulseIR(520, 8);
  delay(32);
  
  // PIN 11
  // 539956008
  pulseIR(2100, 9);
  delayMicroseconds(1002);
  pulseIR(330, 9);
  delayMicroseconds(880);
  pulseIR(480, 9);
  delayMicroseconds(880);
  pulseIR(488, 9);
  delay(55);
  
  // PIN 44
  // 1763287871
  pulseIR(1080, 10);
  delayMicroseconds(450);
  pulseIR(880, 10);
  delayMicroseconds(620);
  pulseIR(1080, 10);
  delayMicroseconds(620);
  pulseIR(880, 10);
  delay(55);
   
  // PIN 45
  // 303091725
  pulseIR(1080, 11);
  delayMicroseconds(2080);
  pulseIR(808, 11);
  delayMicroseconds(560);
  pulseIR(404, 11);
  delayMicroseconds(200);
  pulseIR(1212, 11);
  delay(32);
  
}
