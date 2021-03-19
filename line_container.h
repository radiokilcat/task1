#pragma once

#include <string>
#include <mutex>

class LineContainer
{
public:
    LineContainer() = default;
    ~LineContainer() = default;

    void add_substr(std::string str);
    std::string get_string();

private:
    std::string data_;
    std::mutex mutex_;
};

