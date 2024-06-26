#include <iostream>
#include <chrono>
#include <random>       /* 임의의 난수 생성을 위한 라이브러리 */
#include <fstream>      /* 파일 입출력을 위한 라이브러리 */
#include <thread>
#include <ncurses.h>    /* 터미널 제어용 외부 라이브러리 */
#include "SystemManager.hpp"

using namespace std::chrono;
using namespace obj;

void SystemManager::setTerminal(void)
{
    initscr();             // ncurses 모드 시작
    cbreak();              // 버퍼링 없이 즉시 입력 받음
    noecho();              // 입력한 키를 화면에 표시하지 않음
    keypad(stdscr, TRUE);  // 특수 키 활성화
    nodelay(stdscr, TRUE); // getch()가 블로킹 되지 않도록 설정
}

int SystemManager::intRandom06()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // 현재 시간을 시드로 설정

    std::mt19937 gen(seed);                    // 시드값을 생성 함수에 전달
    std::uniform_int_distribution<> dis(0, 6); // 생성 범위 설정

    return dis(gen); // 값 생성(반환)
}

void SystemManager::flushInputBuffer()
{
    int ch;                       // 버퍼에 문자 값을 저장할 변수
    while ((ch = getch()) != ERR) // 버퍼에 저장된 값이 없을 때까지 값 읽기 반복
    {
        // 모든 대기중인 입력을 읽고 무시합니다.
    }
}

void SystemManager::cleanScreen()
{
#ifdef _WIN32
    std::system("cls"); // Windows 시스템에서 화면 클리어
#else
    std::system("clear"); // Unix/Linux/MacOS 시스템에서 화면 클리어
#endif
}

void SystemManager::pause(milliseconds msPerFrame)
{
    /* 현재 시간 기록 */
    auto frameStart = high_resolution_clock::now();
    /* 코드 실행 후 시간 기록 */
    auto frameEnd = high_resolution_clock::now();
    /* 경과 시간 계산 */
    auto elapsedTime = frameEnd - frameStart;
    // 프레임 시간을 유지하기 위해 필요하다면 대기
    if (elapsedTime < msPerFrame)
        std::this_thread::sleep_for(msPerFrame - elapsedTime);
}

/* 문자열의 모든 공백 문자 제거 함수 */
std::string SystemManager::cleanLine(const std::string &line)
{
    std::string clean;  // 공백 제거 결과 저장 변수
    for (char c : line) // 모든 문자(컨테이너)를 순회할 때까지 반복
    {
        if (!isspace(c)) // 문자(c)의 값이 공백인지 검사
            clean += c;  // 공백이 아닌 경우 문자열 끝에 저장
    }
    return clean; // 루프 종료 후 반환
}

int SystemManager::loadBlocksFromFile(const std::string &filename, std::map<char, Block> &blockList)
{
    /* 지정된 경로의 파일 열기 */
    std::ifstream file(filename);

    /* 제데로 열였는지 확인 */
    if (!file.is_open())
    {
        std::cerr << "파일을 여는데 실패했습니다." << filename << std::endl;
        return 1; // error code 1
    }

    /* 문자열 저장 변수 */
    std::string line;
    while (std::getline(file, line))    // 파일의 문자열 읽기
    {
        line = cleanLine(line);         // 문자열에 공백 제거
        if (line.empty())               // 읽은 문자열이 비어있는 경우 반복문 처음으로
            continue;
        char blockType = line[0];       // 블럭 모양 식별자 저장
        std::string shapeStr = line.substr(2);  // 식별자 이후 블럭 모양 데이터 저장
        blockList[blockType].setShape(parseShape(shapeStr));    // 저장된 블럭 모양 데이터를 vector<vector<int>> 형태로 변환
    }
}

/* 1차원 문자열 데이터를 가공해 vector<vector<int>> 형태로 변환 */
std::vector<std::vector<int>> SystemManager::parseShape(const std::string &shapeStr)
{
    // std::cout << shapeStr << std::endl;  // 데이터 확인 용 출력
    std::vector<std::vector<int>> shape;
    std::istringstream ss(shapeStr);
    std::string row;

    while (std::getline(ss, row, ';'))
    {
        std::vector<int> rowVector;
        std::istringstream rowStream(row);
        std::string cell;
        while (std::getline(rowStream, cell, ','))
        {
            rowVector.push_back(std::stoi(cell));
        }
        shape.push_back(rowVector);
    }

    return shape;
}
