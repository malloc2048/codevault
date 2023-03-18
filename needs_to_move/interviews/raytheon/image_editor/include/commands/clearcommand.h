#ifndef CODESIGNAL_CLEARCOMMAND_H
#define CODESIGNAL_CLEARCOMMAND_H

#include "commandprocessor.h"

class ClearCommand : public CommandProcessor {
public:
    ClearCommand() = default;
    ~ClearCommand() override = default;

    void execute(std::vector<std::string> &commandLine) override;
};
#endif
