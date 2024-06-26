# 테트리스 만들기
## [main.cpp](/Tetris/main.cpp)

## [ObjectManager.hpp](/Tetris/include/ObjectManager.hpp)
- 초기에 Block.hpp 와 Board.hpp 두 파일로 구분해서 관리되었으나 두 해더파일이 서로가 서로를 포함해야 하는(include) 상황에서 컴파일 순서에 따라 선언되 않은 객체 오류를 지속적으로 표시해 하나의 파일로 관리하는 것을 선택
- 하나의 파일로 관리하게 된 후 포워드 선언을 통해 에러를 해결할 수 있었다.

## [ObjectManager.cpp](/Tetris/source/ObjectManager.cpp)
- 각 객체의 기능을 정의 한 파일

## [SystemManager.hpp](/Tetris/include/SystemManager.hpp)
- 터미널을 제어하거나 의사난수를 생성하거나 입력 버퍼를 청소하는 등 시스템을 관리하는데 필요한 함수를 하나의 객체에 모아서 관리하기 위해 만든 파일

## [SystemManager.cpp](/Tetris/source/SystemManager.cpp)
- 파일 입출력 라이브러리 <fstream>을 활용해 블록 모양을 따로 텍스트 파일로 저장해 관리하는 시스템을 만들었다.

## [GameManager.hpp](/Tetris/include/GameManager.hpp)
- 게임 프로세스 전반에 필요한 기능과 객체를 관리하는 관리자 객체를 만들었다.

## [GameManager.cpp](/Tetris/source/GameManager.cpp)
- 관리자 객체에서 게임의 종료 조건 충돌 판정과 사용자의 입력 등 게임 진행에 필요한 제어관련 기능을 정의한 파일이다. 

## [Tetris](/build/Clang%2015.0.0%20arm64-apple-darwin23.4.0/Tetris/Tetris)
- 초기에 windows 버전과 mac 버전을 동시에 개발하고자 했지만 윈도우 컴파일러에서 꼭 필요한 라이브러리가 정상적으로 설치되지 않아 우선 mac 버전만 완성했다.
- 라이브러리 명칭은 'ncurses.h' 이고 추후에 윈도우 버전으로 컴파일 할 수 있도록 연구해볼 예정이다.

## 개선 목표
- 추후 아래 목표들을 해결할 예정
1. 블록 회전 시 충돌 판정 버그
2. 점수 출력
3. 게임 씬 확장 (로비 > 게임 > 종료)
4. 최적화