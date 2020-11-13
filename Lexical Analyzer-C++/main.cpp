#include "classes/lexical.h"

int main() {
    Lexical *analyzer = new Lexical("/home/zeddling/Documents/School/4th Year/2nd Sem/Compiler Construction/Assignments/Lexical Analyzer-C++/test.zed");
    analyzer->saveTokens();
    return 0;
}