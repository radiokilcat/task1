#include "line_container.h"

void LineContainer::LineContainer::add_substr(std::string str)
{
    const std::lock_guard<std::mutex> lock(mutex_);
//    data_.push_back(str);

};

std::string LineContainer::get_string()
{
    const std::lock_guard<std::mutex> lock(mutex_);
    return data_;
};

