#include "data_container.h"

void DataContainer::push_string(std::string str)
{
    const std::lock_guard<std::mutex> lock(mutex_);
    data_.push(str);
}

std::queue<std::string> DataContainer::get_strings()
{
    const std::lock_guard<std::mutex> lock(mutex_);
    return data_;
}
