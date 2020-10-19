#include "classes/lexical.h"

int main() {
    Lexical *analyzer = new Lexical("test.zed");
    std::cout<< analyzer->getFileStream();
    return 0;
}