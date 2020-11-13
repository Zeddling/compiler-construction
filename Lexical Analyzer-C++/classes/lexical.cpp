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
        source.close();
    }
    
    this->filePath = filePath;
    
}

int Lexical::isKeyWord( char buffer[] ) {
    char keywords[33][10] = 
                        {"auto","break","case","char","const","continue","default",
                        "do","double","else","enum","extern","float","for","goto",
                        "if","int","long", "print", "register","return","short","signed",
                        "sizeof","static","struct","switch","typedef","union",
                        "unsigned","void","volatile", "while"};
    int i, flag = 0;

    for ( i = 0; i < 32; i++) {
        if ( strcmp( keywords[i], buffer ) == 0 ) {
            flag = 1;
            break;
        }
    }

    return flag;
}

void Lexical::saveTokens() {
    Symbol_Table st;
    char characters, buffer[15], operators[] = "+-*/%=";
    std::ifstream fin( filePath );
    int i, j = 0, currentLineNo = 1;
    if(!fin.is_open()) {
        std::cout << "error while opening file\n";
        exit(0);
    }

    while (!fin.eof()){
        characters = fin.get();

        for ( i = 0; i < 6; ++i){
            if ( characters == operators[i] ) {
                st.insert( getString( operators[i], 1 ) , "global", "operator", currentLineNo );
                currentLineNo++;
            }
        }
        
        if ( std::isalnum( characters ) ) { //  isalnum returns true if isdigit || isalpha is true
            buffer[j++] = characters;
        }

        else if ((characters == ' ' || characters == '\n') && ( j != 0 )) {
            buffer[j] = '\0';
            j = 0;

            if ( isKeyWord(buffer) == 1 ) {
                std::string word( buffer, buffer + 15 );
                st.insert( word, "global", "keyword", currentLineNo );
                currentLineNo++;
            } else {
                std::string word( buffer, buffer + 15 );
                st.insert( word, "global", "identifier", currentLineNo );
                currentLineNo++;
            }   
        }
    }
    fin.close();
}

std::string Lexical::getString( char x, int size ) {
    // string class has a constructor 
    // that allows us to specify size of 
    // string as first parameter and character 
    // to be filled in given size as second 
    // parameter. 
    std::string s(size, x); 
  
    return s;
}