#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <string>

int runTests(int argc, char *argv[], std::string const currentTestUnit);

int main(int argc, char* argv[])
{
    const std::string currentTestUnit = "09";
    return runTests(argc, argv, currentTestUnit);
}

int runTests(int argc, char *argv[], std::string const currentTestUnit) {
    Catch::Session session;
    int returnCode = session.applyCommandLine(argc, argv);
    if(returnCode != 0)
    {
        return returnCode;
    }
    session.configData().testsOrTags.push_back(currentTestUnit + "*");
    return session.run();
}

