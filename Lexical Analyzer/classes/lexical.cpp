#include "lexical.h"

bool Lexical::fileTypeCheck(std::string filePath) {
    fs::path fpath = filePath;
    if(fpath.extension() == ".zed")
        return true;

    else
        return false;
}

Lexical::Lexical( std::string filePath ) {
    
    if ( fileTypeCheck(filePath) ) {
        std::ifstream source(filePath);
        while ( getline (source, file_stream) ) {
        }
        source.close();
    }
    this->file_stream = file_stream;
}

void Lexical::setFileStream( std::string file_stream ) {
    this->file_stream = file_stream;
}

std::string Lexical::getFileStream() {
    return file_stream;
}