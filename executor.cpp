#include <iostream>
#include <string>
#include <sstream>

#include <boost/algorithm/string.hpp>

#include "executor.h"
#include "line_container.h"

std::vector<std::string> split_lines(std::vector<std::string> substrings, const std::string& delim)
{
    std::cout << "split start " << std::endl;
//    for (auto& it: substrings)
//    {
//        std::cout << it << std::endl;
//    }
    std::vector<std::string> result;
    for (auto& it: substrings)
    {
        std::cout << it << std::endl;
        auto start = 0U;
        auto end = it.find(delim);
        while (end != std::string::npos)
        {
            result.push_back(it.substr(start, end - start));
            start = end + delim.length();
            end = it.find(delim, start);
        }
        if (end = std::string::npos)
        {
            std::cout << "_+_ no delims in substr" << std::endl;
            result.push_back(it);
            return

        }

    }
    return split_lines(result, delim);
//    for (auto& it: result)
//    {
//        std::cout << it << std::endl;
//    }
//    return result;
}

Executor::Executor(const std::list<boost::filesystem::path> &in_files, const fs::path& out_file)
    : files_(in_files),
      result_file_(out_file),
      data_(std::shared_ptr<DataContainer> (new DataContainer))
{
}

Executor::~Executor()
{
    for (auto& thread: threads_)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }
}


void Executor::parse_files()
{
    for (const auto& file: files_)
    {
        if (file == result_file_)
            continue;
        std::cout << file << std::endl;

//        threads_.push_back(std::thread(
//            [this](fs::path& file)
//            {
//                auto file_data = std::shared_ptr<DataContainer
//                std::ostringstream oss; fs::ifstream ifs{file};
//                std::string line;
//                std::getline(ifs, line);
//                std::string delim;
//                while (std::getline(ifs, delim))
//                {
//                    auto file_substrings = split_line(line, delim)
//                }

//                oss << "[" << file << "]:\n";
//                auto result = data_->get_strings();
//                for (const auto& substr: result)
//                {
//        //            oss << substr << "\n";
//                }
//            }));

//        std::ostringstream oss;
        fs::ifstream ifs{file};
        std::string line;
        std::getline(ifs, line);
        std::cout << line << std::endl;
        std::string delim;
        std::vector<std::string> substrings;

        while (std::getline(ifs, delim))
        {
            substrings = split_lines(substrings, delim);
//            std::cout << "_+_ local substrings: " << substrings_for_delim.size() << std::endl;
//            for (auto& it: substrings_for_delim)
//            {
//                std::cout << it << std::endl;
//            }
        }
//        std::cout << "_+_" << substrings.size() << std::endl;
        for (auto& it: substrings)
        {
            std::cout << it << std::endl;
        }
//        oss << "[" << file << "]:\n";
//        auto result = data_->get_strings();
    }

//    std::ofstream result(result_file_.c_str());
//    result << oss.str();

}



