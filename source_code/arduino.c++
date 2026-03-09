const int trigPin = 9;
const int echoPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // 1. 초음파 발사
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 2. 시간 측정 (돌아오는 시간)
  long duration = pulseIn(echoPin, HIGH);

  // 3. 거리 계산 (cm 단위)
  int distance = duration * 0.034 / 2;

  // 4. 시리얼로 값 송신 (라즈베리파이가 읽을 수 있게)
  Serial.println(distance);
  delay(500);
}
