#include <iostream>
#include <thread>
#include <chrono>

class Timer {
    bool active = true;

    public:
        template<typename Function>
        void setTimeout(Function function, int delay);

        template<typename Function>
        void setInterval(Function function, int interval);

        void stop();
};

template<typename Function>
void Timer::setTimeout(Function function, int delay) {
    this->active = true;
    std::thread t([=]() {
        if(!this->active) return;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if(!this->active) return;
        function();
    });
    t.detach();
}


template<typename Function>
void Timer::setInterval(Function function, int interval) {
    this->clear = false;
    std::thread t([=]() {
        while(true) {
            if(!this->active) return;
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
            if(!this->active) return;
            function();
        }
    });
    t.detach();
}

void Timer::stop() {
    this->active= false;
}