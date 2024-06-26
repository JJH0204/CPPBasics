#pragma once
#include <chrono>
#include <map>

#include "ObjectManager.hpp"

using namespace std::chrono;

namespace SysManager
{
    void setTerminal(void);
    int intRandom06(void);               /* 0~6 사이 임의의 int 값 반환 */
    void flushInputBuffer(void);         /* 입력 버퍼에 대기 중인 문자 제거 */
    void cleanScreen();                  /* 화면 청소 함수 */
    void pause(milliseconds msPerFrame); /* 프레임 당 로직처리 횟수 제어(시간) */
    std::string cleanLine(const std::string &line);
    int loadBlocksFromFile(const std::string &filename, std::map<char, obj::Block> &blockList);       /* 블록 정보를 가진 텍스트 파일을 열어 배열에 저장하는 함수, 성공 시 0 반환, 실패 시 0외에 다른 정수 반환 */
    std::vector<std::vector<int>> parseShape(const std::string &shapeStr);
}