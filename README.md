# Banker's Algorithm

### Deadlock을 회피하기 위한 방법

Safe State를 유지할 수 있는 요구만 수락, Unsafe State는 Safe State가 될 때까지 거절

Safe State: 안전상태
- Deadlock을 일으키지 않으면서 각 프로세스가 요구한 만큼 필요한 자원을 할당할 수 있는 상태

Unsafe State: 불안전상태
- Deadlock이 발생하기 위한 필요조건
- Unsafe여도 무조건 Deadlock이 발생하지는 않음

Max: 프로세스 별 최대 자원의 요구

Available: 사용 가능한 자원의 수

Need: 프로세스 별 남아있는 자원의 수

Allocation: 현재 프로세스 별 할당된 자원의 수


단점
- 할당할 수 있는 자원의 수가 일정해야 함
- 사용자 수가 일정해야 함
- 프로세스들이 유한한 시간 안에 자원을 반납해야 함
