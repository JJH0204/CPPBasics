# 프로젝트 설정
project(project_Basics)

# 추가 라이브러리 링크 혹은 옵션 지정
include_directories(include)

# src 디렉토리 내의 모든 소스 파일 수집
file(GLOB SOURCES "source/*.cpp")

# 소스 파일 지정
add_executable(Cpp_example1
    example1.cpp
    ${SOURCES}
)

if(WIN32)
    # windows 설정

elseif(APPLE)
    # mac 설정

endif()
