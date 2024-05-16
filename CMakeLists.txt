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

# if(WIN32)
#     # windows 설정
#     set(BUILD_DIR "build/build_win")
# elseif(APPLE)
#     # mac 설정
#     set(BUILD_DIR "build/build_mac")
# else()
#     # unix 설정
#     set(BUILD_DIR "build/build_unix")
# endif()

# 빌드 디렉토리 지정
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR})
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR})
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})

# 서브 프로젝트 추가: project_Basics
add_subdirectory(project_Basics)


