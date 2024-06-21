# 프로젝트 설정
project(Tetris)

# 추가 라이브러리 링크 혹은 옵션 지정
include_directories(Tetris PRIVATE include)

# src 디렉토리 내의 모든 소스 파일 수집
file(GLOB SOURCES "source/*.cpp")

# ncurses 라이브러리 찾기
find_package(Curses REQUIRED)

# 소스 파일 지정
add_executable(Tetris
    main.cpp
    ${SOURCES}
)

target_link_libraries(Tetris ${CURSES_LIBRARIES})
target_include_directories(Tetris PRIVATE ${CURSES_INCLUDE_DIR})

if(WIN32)
    # windows 설정

elseif(APPLE)
    # mac 설정

endif()
