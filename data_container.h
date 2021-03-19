#pragma once

#include <queue>
#include <string>
#include <mutex>

class DataContainer
{
public:
    DataContainer() = default;
    ~DataContainer() = default;

    void push_string(std::string str);
    std::queue<std::string> get_strings();
private:
    std::queue<std::string> data_;
    std::mutex mutex_;
};

