# CMake 최소 버전 설정
cmake_minimum_required(VERSION 3.11)

# 프로젝트 설정
project(CppProject VERSION 0.1 LANGUAGES CXX)

#c++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# UTF-8 인코딩을 위한 컴파일러 옵션 설정
add_compile_options(
    $<$<CXX_COMPILER_ID:GNU>:-finput-charset=UTF-8>
    $<$<CXX_COMPILER_ID:Clang>:-finput-charset=UTF-8>
)

# 디버그 모드 설정
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -g")

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring for macOS")
    # macOS-specific settings
    # 서브 프로젝트 추가: project_Basics
    add_subdirectory(Basics)
    add_subdirectory(OOP)
    add_subdirectory(Tetris)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring for Windows")
    # Windows-specific settings
    # 서브 프로젝트 추가: project_Basics
    add_subdirectory(Basics)
    add_subdirectory(OOP)
    add_subdirectory(Tetris)
else()
    message(STATUS "Configuring for Other OS")
    # 서브 프로젝트 추가: project_Basics
    add_subdirectory(Basics)
    add_subdirectory(OOP)
    add_subdirectory(Tetris)
endif()