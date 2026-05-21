#define VOUT_PIN A0
#define BUCK_PIN 9

const float VOUT_TARGET = 3.30;
const float VOUT_TOL    = 0.03;

// Divider: 6.8k + 10k
const float VOUT_SCALE  = (5.0 / 1023.0) / (10.0 / 16.8);
const float VIN_THRESHOLD = 1;  // minimum input to start regulating

int duty = 45;

void setup(){
  Serial.begin(115200);
  pinMode(BUCK_PIN, OUTPUT);

  TCCR1A = _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);
  ICR1  = 319;
  OCR1A = duty;
}

void loop(){
  long raw = 0;
  for (int i = 0; i < 16; i++) raw += analogRead(VOUT_PIN);
  float vout = (raw / 16.0) * VOUT_SCALE;

  if(vout < VIN_THRESHOLD){
    duty = 10;          // reset duty to low
    OCR1A = duty;
    delay(1);
    return;            
  }

  if(vout > VOUT_TARGET + VOUT_TOL){
    if(duty > 1) duty--;
  } 
  else if(vout < VOUT_TARGET - VOUT_TOL){
    if(duty < 200) duty++; // duty < 150 is another fix. try it once
  }

  OCR1A = duty;
  
  delay(1);
}