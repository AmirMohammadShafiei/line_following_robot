

#define IN1 7 
#define IN2 6 
#define IN3 5 
#define IN4 4 
#define ENA 9 
#define ENB 10 

#define LEFT_SENSOR A2   
#define CENTER_SENSOR A1 
#define RIGHT_SENSOR A0  

const int threshold = 500; 

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(LEFT_SENSOR, INPUT);
  pinMode(CENTER_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  Serial.begin(9600);
}

void Forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200); 

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200); 
}

void Backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);
}

void TurnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); 

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200); 
  }
void TurnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200); 

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0); 
}

void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

void loop() {
  int leftValue = analogRead(LEFT_SENSOR);
  int centerValue = analogRead(CENTER_SENSOR);
  int rightValue = analogRead(RIGHT_SENSOR);

  Serial.print("Left: ");
  Serial.print(leftValue);
  Serial.print(" | Center: ");
  Serial.print(centerValue);
  Serial.print(" | Right: ");
  Serial.println(rightValue);

  if (centerValue > threshold) {
    Forward(); 
  } else if (leftValue > threshold) {
    TurnLeft(); 
  } else if (rightValue > threshold) {
    TurnRight(); 
  } else {
    Stop(); 
  }

  delay(100); 
}
