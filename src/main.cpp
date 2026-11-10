#include <Arduino.h>
constexpr uint8_t WORKING_TIME = 10;
constexpr uint8_t IDLE_TIME = 30;

constexpr uint8_t CNTRL_PIN = 6;

hw_timer_t *timer_working = NULL;
hw_timer_t *timer_idle = NULL;

volatile bool isMotorWorking = true;

void IRAM_ATTR onWorkingTimer(){
  isMotorWorking = !isMotorWorking;
  timerWrite(timer_idle, 0);
  timerAlarmEnable(timer_idle);
}

void IRAM_ATTR onIdleTimer(){
  isMotorWorking = !isMotorWorking;
  timerWrite(timer_working, 0);
  timerAlarmEnable(timer_working);
}

void setup() {
  Serial.begin(115200);
  delay(50);
  pinMode(CNTRL_PIN, OUTPUT);

  timer_working = timerBegin(0, 80, true);
  timerAttachInterrupt(timer_working, &onWorkingTimer, true);
  timerAlarmWrite(timer_working, 1000000ULL*WORKING_TIME, false);
  timerAlarmEnable(timer_working);

  timer_idle = timerBegin(1, 80, true);
  timerAttachInterrupt(timer_idle, &onIdleTimer, true);
  timerAlarmWrite(timer_idle, 1000000ULL*IDLE_TIME, false);
}

void loop() {
  if (isMotorWorking)
  {
    digitalWrite(CNTRL_PIN, HIGH);
  }else{
    digitalWrite(CNTRL_PIN, LOW);
  }
  
}
