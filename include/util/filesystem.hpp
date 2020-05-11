#pragma once
#if __has_include(<experimental/filesystem>)
    #include <experimental/filesystem>
    namespace filesystem = std::experimental::filesystem;
#elif __has_include(<filesystem>)
    #include <filesystem>
    namespace filesystem = std::filesystem;
#else
    #error "Couldn't find a standard 'filesystem' header."
#endif
