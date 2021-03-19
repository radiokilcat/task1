#include <iostream>
#include <boost/filesystem.hpp>

#include "executor.h"

namespace fs = boost::filesystem;

std::list<fs::path> get_all_files(const fs::path& path)
{
    std::list<fs::path> list;
    try
    {
        for (auto it = fs::directory_iterator(path); it != fs::directory_iterator(); ++it)
            if (boost::filesystem::is_regular_file(it->path()))
                list.push_back(it->path());
    }
    catch (const std::exception& e)
    {
        std::cout << "error checking directory: " << e.what() << std::endl;
        return {};
    }
    return list;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Working directory has not been specified." << std::endl;
    }

    fs::path working_dir = argv[1];
    fs::path out_file = argv[2];

    std::list<fs::path> files = get_all_files(working_dir);

    Executor executor(files, out_file);

    executor.parse_files();

    return 0;
}
