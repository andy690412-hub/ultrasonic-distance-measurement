**Ultrasonic Physical Intrusion Detection System**

본 프로젝트는 아두이노와 초음파 센서를 활용하여 (거리 측정을 통해)물리적 침입을 감지하고, 라즈베리파이를 통해 실시간으로 데이터를 수집 및 로깅하는 시스템입니다.

**아키텍처 개요**

*1. 하드웨어 구성 (Firmware)*

센서의 Trig/Echo 핀을 활용하여 거리 데이터를 산출하고, 입력값 검증을 통해 오탐지(False Positive)를 차단합니다.
[Arduino Source Code](arduino 파일)


*2. 데이터 수집 체계 (Data Collector)*

라즈베리파이 환경에서 pyserial을 이용해 아두이노 데이터를 수신하고 타임스탬프를 포함한 로컬 로그 파일을 생성합니다.
[Python msrd Script](raspberrypi 파일)


*3. 기술적 특징*

가용성 확보: 브레드보드 없이 점퍼 와이어 직결을 통해 물리적 결합 안정성 제고.
데이터 신뢰성: 30ms 타임아웃 및 2~400cm 입력값 검증 로직 구현.
포렌식 가치: 수집되는 모든 데이터에 타임스탬프를 기록하여 침입 시점 증거 확보.

*4. 설치 방법*

위 코드를 각각 아두이노와 라즈베리파이에 배포.
sudo chmod 666 /dev/ttyUSB0 명령어로 접근 권한 부여.
python3 msrd.py로 데이터 수집
