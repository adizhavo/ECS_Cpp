#include <stdio.h>
#include "filterTest.cpp"
#include "entityTest.cpp"
#include "entityMatcherTest.cpp"
#include "reactiveSystemTest.cpp"

using namespace UnitTest;

int execute(std::string test)
{
    if (test.compare("entity") == 0)
        return EntityTest::runTest();
    else if (test.compare("filter") == 0)
        return FilterTest::runTest();
    else if (test.compare("entityMatcher") == 0)
        return EntityMatcherTest::runTest();
    else if (test.compare("systems") == 0)
        return ReactiveSystemTest::runTest();
    else
    {
        std::cout << test << " - not a test case";
        return 1;
    }
}

int main (int argc, char *argv[]) {
    for (int i = 1; i < argc; i ++)
    {
        int result = execute(argv[i]);
        
        // Error, tests didnt pass
        if (result != 0)
            return result;
    }
    
    return 0;
}


