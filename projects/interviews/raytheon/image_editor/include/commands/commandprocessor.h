#ifndef CODESIGNAL_COMMANDPROCESSOR_H
#define CODESIGNAL_COMMANDPROCESSOR_H

#include <string>
#include <vector>

class CommandProcessor {
public:
    CommandProcessor() = default;
    virtual ~CommandProcessor() = default;

    virtual void execute(std::vector<std::string>& commandLine) = 0;
};
#endif
