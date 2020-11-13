#ifndef LEXICAL_H
#define LEXICAL_H
#include <string>
#include <string.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "ctype.h"
#include "stdlib.h"
#include "symbol_table/symbol_table.h"

namespace fs = std::filesystem;

class Lexical {
private:
    std::string filePath;

public:
    Lexical( std::string file_path );
    ~Lexical();
    bool fileTypeCheck( std::string filePath ); //  Check file type
    std::string getFileStream();
    int isKeyWord( char buffer[] ); //  Create tokens
    void saveTokens();
    std::string getString( char x, int size );
    
};

#endif 