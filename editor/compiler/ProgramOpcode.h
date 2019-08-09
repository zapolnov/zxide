#ifndef COMPILER_PROGRAMOPCODE_H
#define COMPILER_PROGRAMOPCODE_H

#include <QtGlobal>
#include <vector>

class File;

class ProgramOpcode
{
public:
    ProgramOpcode(File* file, int line);
    virtual ~ProgramOpcode();

    File* file() const { return mFile; }
    int line() const { return mLine; }

    virtual unsigned lengthInBytes() const = 0;
    virtual unsigned tstatesIfNotTaken() const = 0;
    virtual unsigned tstatesIfTaken() const = 0;

    virtual void emit(std::vector<unsigned char>& out) const = 0;

private:
    File* mFile;
    int mLine;

    Q_DISABLE_COPY(ProgramOpcode)
};

#endif