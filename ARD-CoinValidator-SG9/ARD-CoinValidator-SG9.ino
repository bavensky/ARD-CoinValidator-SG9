/*
   CMMC
   Apirak Sang-ngenchai
*/

int pin = 3; // use interrupe pin 3
int sum = 0; // sum coin input
unsigned long duration;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT_PULLUP); // pull up signal 
  attachInterrupt(digitalPinToInterrupt(pin), coin, LOW); // detect low signal about 20 ms.
}

void loop() {
  Serial.print("Incoming coin = ");
  Serial.println(sum);
}

void coin() {
  for (int i = 0; i <= 5; i++)  {
    duration = pulseIn(pin, LOW, 1000000);
    float time = duration / 1000.00;
    //    Serial.print("DelT=");
    //    Serial.print(time);
    //    Serial.println(" ms");

    if (time > 2) {
      count = count + 1;
    }

    if (time == 0) {
      if (count > 0 && count < 3) {
        sum = sum + 1;
        //        Serial.println("1 Bath");
      }
      if (count > 3 && count < 7) {
        sum = sum + 5;
        //        Serial.println("5 Bath");
      }
      if (count > 7) {
        sum = sum + 10;
        //        Serial.println("10 Bath");
      }
      count = 0;
    }
  }
}

