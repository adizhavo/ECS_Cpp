#include <stdio.h>
#include "filterTest.cpp"
#include "entityTest.cpp"
#include "entityMatcherTest.cpp"

using namespace UnitTest;

void execute(std::string test)
{
    if (test.compare("entity") == 0) EntityTest::runTest();
    else if (test.compare("filter") == 0) FilterTest::runTest();
    else if (test.compare("entityMatcher") == 0) EntityMatcherTest::runTest();
}

int main (int argc, char *argv[]) {
    for (int i = 0; i < argc; i ++)
        execute(argv[i]);
    return 0;
}


