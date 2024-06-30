#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_

class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

#endif //_ICOMMAND_H_