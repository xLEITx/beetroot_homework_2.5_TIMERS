#include <Arduino.h>
constexpr uint8_t WORKING_TIME = 10;
constexpr uint8_t IDLE_TIME = 30;

constexpr uint8_t CNTRL_PIN = 6;

hw_timer_t *timer_working = NULL;
hw_timer_t *timer_idle = NULL;

void IRAM_ATTR onWorkingTimer(){

}

void IRAM_ATTR onIdleTimer(){

}

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

  timer_working = timerBegin(0, 80000, true);
  timerAttachInterrupt(timer_working, &onWorkingTimer, true);
  timerAlarmWrite(timer_working, 1000*WORKING_TIME, false);
  timerAlarmEnable(timer_working);

  timer_idle = timerBegin(0, 80000, true);
  timerAttachInterrupt(timer_working, &onIdleTimer, true);
  timerAlarmWrite(timer_working, 1000*WORKING_TIME, false);
}

void loop() {
  // put your main code here, to run repeatedly:
}
