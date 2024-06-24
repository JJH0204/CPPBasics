cmake_minimum_required(VERSION 3.10)
project(Tetris)

# ncurses 라이브러리 찾기
find_package(Curses REQUIRED)

# src 디렉토리 내의 모든 소스 파일 수집
file(GLOB SOURCES "source/*.cpp")

# 실행 파일 생성 및 소스 파일 지정
add_executable(Tetris main.cpp ${SOURCES})

# ncurses 라이브러리 링크
target_link_libraries(Tetris PRIVATE ${CURSES_LIBRARIES})

# 추가 라이브러리 링크 혹은 옵션 지정
target_include_directories(Tetris PRIVATE ${CURSES_INCLUDE_DIR} include)

if(WIN32)
    # Windows 설정
    # include_directories("C:\\Program Files\\msys64\\mingw64\\include\\ncurses")

elseif(APPLE)
    # Mac 설정

endif()
