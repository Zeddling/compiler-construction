#ifndef LEXICAL_H
#define LEXICAL_H
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

class Lexical {
private:
    std::string file_stream;

public:
    Lexical( std::string file_path );
    ~Lexical();
    bool fileTypeCheck( std::string filePath );
    void setFileStream( std::string file_stream );
    std::string getFileStream();
};

#endif 