#include <stdio.h>
#include "filterTest.cpp"
#include "entityTest.cpp"

using namespace UnitTest;

void execute(std::string test)
{
    if (test.compare("entity") == 0) EntityTest::runTest();
    else if (test.compare("filter") == 0) FilterTest::runTest();
}

int main (int argc, char *argv[]) {
    for (int i = 0; i < argc; i ++)
        execute(argv[i]);
    return 0;
}


