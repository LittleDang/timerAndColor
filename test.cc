#include "color.h"
#include "timer.h"
#include <functional>
#include <thread>
#include <vector>
using myTimer::Timer;
void sleep(int index, int mill)
{
    {
        lmicroTimer(std::to_string(index) + ":sleep " + std::to_string(mill * 1000) + " us",
                    myColor::RED, false);
        lmillTimer(std::to_string(index) + ":sleep " + std::to_string(mill) + " ms",
                   myColor::GREEN);
        lsecTimer(std::to_string(index) + ":sleep " + std::to_string(mill / 1000.0) + " s");
        std::this_thread::sleep_for(std::chrono::milliseconds(mill));
    }
}
template <int i1, int i2>
struct vec
{
    int x;
    int y;
    vec(int x, int y) : x(x), y(y) {}
    friend std::ostream &operator<<(std::ostream &os, const vec &v)
    {
        return os << v.x + i1 << ","
                  << v.y + i2;
    }
};

int main()
{
    myTimer::millTimer<>::type mT("begin to count time ");
    int ths = 1000;
    std::vector<std::thread> th(ths);
    mT.end("ini vec");
    for (int i = 0; i < ths; i++)
        th[i] = std::thread(std::bind(sleep, i, random() % 1000));
    for (int i = 0; i < ths; i++)
        th[i].join();
    mT.end("sleep sort");

    BLACK_INFO(false, "this is BLACK without bold " << std::endl);
    RED_INFO(false, "this is RED without bold " << std::endl);
    GREEN_INFO(false, "this is GREEN without bold " << std::endl);
    YELLOW_INFO(false, "this is YELLOW without bold " << std::endl);
    BLUE_INFO(false, "this is BLUE without bold " << std::endl);
    PURPLE_INFO(false, "this is PURPLE without bold " << std::endl);
    DGREEN_INFO(false, "this is DGREEN without bold " << std::endl);
    WHITE_INFO(false, "this is WHITE without bold " << std::endl);

    BLACK_INFO(true, "this is BLACK with bold " << std::endl);
    RED_INFO(true, "this is RED with bold " << std::endl);
    GREEN_INFO(true, "this is GREEN with bold " << std::endl);
    YELLOW_INFO(true, "this is YELLOW with bold " << std::endl);
    BLUE_INFO(true, "this is BLUE with bold " << std::endl);
    PURPLE_INFO(true, "this is PURPLE with bold " << std::endl);
    DGREEN_INFO(true, "this is DGREEN with bold " << std::endl);
    WHITE_INFO(true, "this is WHITE with bold " << std::endl);

    YELLOW_INFO(true, "this ,,,,,,, " << std::endl);

    DEFAULT_INFO(false, "this is DEFAULT  " << std::endl);
    int a = 180;
    SHOW_VAR(a);

    vec<0, 0> t(1, 2);
    YELLOW_INFO(true, vec<0, 0>(13, 52) << std::endl);

    SHOW_VAR(t);

    mT.end("output a lot", true);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    mT.end("refresh time,now time is 100ms,let s try:");

    // myTimer::microTimer<myColor::DGREEN, true>::type mT2("dgreen bold microTimer ");
    // std::this_thread::sleep_for(std::chrono::microseconds(8800));

    return 0;
}
