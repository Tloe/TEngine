#ifndef TELUATABLE_H
#define TELUATABLE_H

#include "TEDataTypes.h"
#include "TELuaState.h"
#include "TELuaVariable.h"
#include "TEVariant.h"

#include <string>

namespace TE::Lua {
  class FileIO;

  class Table {
  public:
    Table(I32 luaReference, State &luaState);
    ~Table();

    Variable operator[](const std::string &key);
    Variable operator[](I32 key);
    void PushToStack();

  private:
    State &m_state;
    I32 m_luaReference;
  };

  Table FromFile(IO::FileIO &fileIO, std::string &filename, State &luaState);
  Table FromStack(State &luaState, I32 index = -1);
}

#endif
