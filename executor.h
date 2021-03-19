#pragma once

#include <boost/filesystem.hpp>
#include <memory>
#include <thread>

#include "data_container.h"

namespace fs = boost::filesystem;

class Executor
{
public:
    Executor(const std::list<fs::path>& in_files, const fs::path& out_file);
    ~Executor();
//    void process_file(const std::string& file_to_process);
    void parse_files();

private:
    Executor(const Executor& other) = delete;
    Executor& operator =(const Executor& other) = delete;

    std::list<fs::path> files_;
    fs::path result_file_;
    std::shared_ptr<DataContainer> data_;
    std::vector<std::thread> threads_;
};

