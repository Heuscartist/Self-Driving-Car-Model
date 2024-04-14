uint8_t RightbackwardPin = 11;
uint8_t RightforwardPin = 12;
uint8_t rightSpeedPin = 5;

uint8_t LeftbackwardPin = 9;
uint8_t LeftforwardPin = 10;
uint8_t leftSpeedPin = 6;

const uint8_t triggerPin = 8;
const uint8_t echoPin = 7;

uint8_t threshold = 20;
long duration;
long cm;

uint8_t irRight = 13;
uint8_t irRightVal;

uint8_t irLeft = 4;
uint8_t irLeftVal;


uint8_t slowPin = 3;
uint8_t slowPinVal;
uint8_t stopPin = 2;
uint8_t stopPinVal;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RightbackwardPin, OUTPUT);
  pinMode(RightforwardPin, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);

  pinMode(LeftbackwardPin, OUTPUT);
  pinMode(LeftforwardPin, OUTPUT);
  pinMode(leftSpeedPin, OUTPUT);

  pinMode(irRight, INPUT);
  pinMode(irLeft, INPUT);

  moveForward(225, 225);

}

void loop() {

  
  ultraSonicReading();
  laneDetection();
  cameraDetection();

  if (cm < threshold || stopPinVal == HIGH)
    stopMotor();
  else
  {
    if (slowPinVal == HIGH)
      moveForward(150, 150);
    else
      moveForward(225, 225);
  }
  delay(100);
}



void moveForward(int leftSpeed, int rightSpeed) {
  analogWrite(rightSpeedPin, rightSpeed);
  digitalWrite(RightforwardPin, HIGH);
  digitalWrite(RightbackwardPin, LOW);

  analogWrite(leftSpeedPin, leftSpeed);
  digitalWrite(LeftforwardPin, HIGH);
  digitalWrite(LeftbackwardPin, LOW);  
}

void moveBackward() {
  digitalWrite(RightforwardPin, LOW);
  digitalWrite(RightbackwardPin, HIGH);

  digitalWrite(LeftforwardPin, LOW);
  digitalWrite(LeftbackwardPin, HIGH);
}

void moveLeft(int speed) {
  analogWrite(rightSpeedPin, speed);
  digitalWrite(RightforwardPin, HIGH);
  digitalWrite(RightbackwardPin, LOW);

  digitalWrite(LeftforwardPin, LOW);
  digitalWrite(LeftbackwardPin, LOW);
  delay(200);
}


void moveRight(int speed) {
  analogWrite(leftSpeedPin, speed);
  digitalWrite(RightforwardPin, LOW);
  digitalWrite(RightbackwardPin, HIGH);

  digitalWrite(LeftforwardPin, LOW);
  digitalWrite(LeftbackwardPin, LOW);
  delay(200);
}


void stopMotor() {

  digitalWrite(RightforwardPin, LOW);
  digitalWrite(RightbackwardPin, LOW);

  digitalWrite(LeftforwardPin, LOW);
  digitalWrite(LeftbackwardPin, LOW);
}


void ultraSonicReading() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = duration/58;

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
}


void laneDetection() {
  irRightVal = digitalRead(irRight);
  irLeftVal = digitalRead(irLeft);
  if (irRightVal == LOW && irLeftVal == HIGH) {
    Serial.print("Right Line Detected");
    Serial.println();
    moveLeft(150);
    delay(100);
  }
  else if (irRightVal == HIGH && irLeftVal == LOW)
  {
    moveRight(150);
    delay(100);
  }
  else if (irRightVal == HIGH && irLeftVal == HIGH){
    stopMotor();
    delay(5000);
  }
  else {
    moveForward(200, 200);
  }

}

void rightLineDetected() {
    irRightVal = digitalRead(irRight);
  if (irRightVal == HIGH) {
    Serial.print("Right Line Detected");
    Serial.println();
    moveLeft(255);
  }
    else {
    Serial.print("Right Line not Detected");
    Serial.println();
    }
}

void leftLineDetected() {
    irLeftVal = digitalRead(irLeft);
  if (irLeftVal == HIGH) {
    Serial.print("Left Line Detected");
    Serial.println();
    moveRight(255);
  }
    else {
    Serial.print("Left Line not Detected");
    Serial.println();
    }
}

void cameraDetection() {
  stopPinVal = digitalRead(stopPin);
  slowPinVal = digitalRead(slowPin);
}