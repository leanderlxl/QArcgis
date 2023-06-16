#ifndef INVOKER_H
#define INVOKER_H

#include"command.h"
#include<QDebug>
class Invoker
{
public:
    Invoker():cmd(nullptr)
    {

    }
    void setCommad(Command* cmd)
    {
        this->cmd = cmd;
    }
    void invoke()
    {
        this->cmd->excute();
    }
    ~Invoker()
    {
        if(cmd)delete cmd;
    }
private:
    Command* cmd;
};

#endif // INVOKER_H
