#include <Arduino.h>
constexpr uint8_t WORKING_TIME = 10;
constexpr uint8_t IDLE_TIME = 30;

constexpr uint8_t CNTRL_PIN = 6;

class Motor{
  private:
    bool isWorking = 0;
  public:
    void changeState(){
      isWorking = !isWorking;
    }
    bool getState(){
      return isWorking;
    }
};



void setup() {
  Serial.begin(115200);
  delay(50);
  pinMode(CNTRL_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
}
