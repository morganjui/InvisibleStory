// This sketch receives and decodes pre-defined IR signals and then print the code out to the console, which will be caught by another python program 

#include <IRremote.h>

long pinCodes[12] = {581859881, 3322665791, 1236334116, 286314110, 3977140024, 4163671451, 3559530070, 2396927248, 3471340161, 539956008, 1763287871, 303091725};
boolean pinStatus[12] = {false};

int RECV_PIN = 0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
//    Serial.println(results.value);
    irrecv.resume(); // Receive the next value
  }
  
  int index = -1;
  for (int i = 0; i < 12; i ++){
    if (pinCodes[i] == results.value && !pinStatus[i]){
      for (int j = 0; j < 12; j ++){
        pinStatus[j] = false;
      }
      index = i;
      pinStatus[i] = true;
    }
  }
  
  if (index >= 0) {
//    Serial.print("status: ");
    Serial.println(index);
//    Serial.print(": ");
//    Serial.println(pinStatus[index]);
  }
  delay(10); //short delay for faster response to light.
}
