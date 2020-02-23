#include "LuaMusic.h"
#include "LuaFiles.h"
#include "LuaVM.h"
#include "compiler/IO.h"
#include <string>
#include <sstream>
#include <ayfly.h>
#include <lua.hpp>

extern "C" {
#include <zx7.h>
}

namespace
{
    struct AYRegs
    {
        uint8_t regs[14];
    };

    struct AYRegs1
    {
        uint16_t values[10];
    };
}

#include <QEventLoop>
#include <QApplication>
#include <QWidget>
#include <unordered_map>

static int luaMusicProcess(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    const char* fileName = luaL_checkstring(L, 1);
    const QDir& dir = vm->projectDirectory();
    QString filePath = dir.absoluteFilePath(QString::fromUtf8(fileName));

    QByteArray data = loadFile(filePath);
    unsigned char* p = reinterpret_cast<unsigned char*>(data.data());
    unsigned long size = data.size();

    auto musicHandle = ay_initsongindirect(p, 44100, size, nullptr);
    if (!musicHandle)
        return luaL_error(L, "ay_initsongindirect() failed.");

    /*
    ay_sethwnd(musicHandle, (HWND)qApp->activeWindow()->winId());
    ay_startsong(musicHandle);
    QEventLoop eventLoop;
    eventLoop.exec();
    */

    std::vector<AYRegs1> regs;

    ay_resetsong(musicHandle);
    unsigned long musicLen = ay_getsonglength(musicHandle);
    for (unsigned long i = 0; i < musicLen; i++) {
        ay_seeksong(musicHandle, ay_getelapsedtime(musicHandle) + 1);
        AYRegs r;
        memcpy(&r, ay_getregs(musicHandle, 0), sizeof(AYRegs));

        Q_ASSERT(r.regs[1] < 0x10);
        Q_ASSERT(r.regs[3] < 0x10);
        Q_ASSERT(r.regs[5] < 0x10);
        Q_ASSERT(r.regs[6] < 0x20);
        Q_ASSERT(r.regs[8] < 0x20);
        Q_ASSERT(r.regs[9] < 0x20);
        Q_ASSERT(r.regs[10] < 0x20);
        Q_ASSERT(r.regs[13] < 0x10);

        AYRegs1 rr;
        rr.values[0] = r.regs[0];
        rr.values[1] = r.regs[2];
        rr.values[2] = r.regs[4];
        rr.values[3] = (r.regs[1] & 0x0f) | ((r.regs[8] & 0x1f) << 4);
        rr.values[4] = (r.regs[3] & 0x0f) | ((r.regs[9] & 0x1f) << 4);
        rr.values[5] = (r.regs[5] & 0x0f) | ((r.regs[10] & 0x1f) << 4);
        rr.values[6] = (r.regs[13] & 0x0f) | ((r.regs[6] & 0x1f) << 4);
        rr.values[7] = r.regs[7];
        rr.values[8] = r.regs[11];
        rr.values[9] = r.regs[12];

        regs.emplace_back(rr);
    }

    ay_closesong(&musicHandle);

    AYRegs1 prev = { {0} };

    std::unordered_map<std::string, size_t> map;
    std::vector<std::string> items;
    std::vector<size_t> music;

    FILE* f = fopen("D:/Work/_ZX_/metroidvania/ay.bin", "wb");
    for (const auto& it : regs) {
        uint8_t c1 = 0, c2 = 0;
        std::vector<uint8_t> values;
        for (size_t i = 0; i < 8; i++) {
            if (it.values[i] != prev.values[i]) {
                c1 |= 1 << i;
                values.emplace_back(it.values[i]);
                prev.values[i] = it.values[i];
                if (i == 3)
                    c2 |= ((it.values[3] & 0x100) >> 8) << 7;
                if (i == 4)
                    c2 |= ((it.values[4] & 0x100) >> 8) << 6;
                if (i == 5)
                    c2 |= ((it.values[5] & 0x100) >> 8) << 5;
                if (i == 6)
                    c2 |= ((it.values[6] & 0x100) >> 8) << 4;
            }
        }
        for (size_t i = 8; i < 10; i++) {
            if (it.values[i] != prev.values[i]) {
                c2 |= 1 << (i - 8);
                values.emplace_back(it.values[i]);
                prev.values[i] = it.values[i];
            }
        }

        std::vector<uint8_t> out;
        //if (c1 == 0 && c2 == 0) {
            //music.emplace_back(0);
            //continue;
            //out.emplace_back(c1);
            //fprintf(f, "%02X ", c1);
        //} else {
            out.emplace_back(c1);
            out.emplace_back(c2);
            //fprintf(f, "%02X %02X ", c1, c2);
        //}

        for (const auto& jt : values) {
            //fprintf(f, "%02X ", jt);
            out.emplace_back(jt);
        }
        //fputc('\n', f);

        std::string pattern = std::string((const char*)out.data(), out.size());
        auto it = map.find(pattern);
        size_t index;
        if (it != map.end())
            index = it->second;
        else {
            index = items.size();// +1;
            items.emplace_back(pattern);
            map[pattern] = index;
        }
        music.emplace_back(index);
    }
    //fwrite(regs.data(), 1, regs.size() * sizeof(AYRegs), f);

    std::vector<uint8_t> result;

    fprintf(f, "section music [compress=zx7]\nMusic:\n");
    for (auto it = music.begin(); it != music.end(); ) {
        if (*it == 0) {
            int count = -1;
            do {
                ++count;
                ++it;
            } while (it != music.end() && *it == 0);
            fprintf(f, "db %d\n", count);
            result.emplace_back(count);
        } else {
            fprintf(f, "dw @@%d\n", (int)*it);
            result.emplace_back(uint8_t(*it & 0xff));
            result.emplace_back(uint8_t((*it >> 8) & 0xff));
            ++it;
        }
    }

    int idx = 1;
    for (const auto& it : items) {
        fprintf(f, "@@%d: db ", idx);
        const char* prefix = "";
        for (const auto& jt : it) {
            fprintf(f, "%s0x%02X", prefix, (unsigned char)jt);
            result.emplace_back((unsigned char)jt);
            prefix = ", ";
        }
        fprintf(f, "\n");
        ++idx;
    }
    fclose(f);

    /*
    Optimal* optimal = nullptr;
    unsigned char* compressed = nullptr;
    size_t compressedSize = 0;
    std::vector<quint8> dst;

    try {
        optimal = zx7_optimize(result.data(), result.size());
        if (!optimal)
            throw std::bad_alloc();

        compressed = zx7_compress(optimal, result.data(), result.size(), &compressedSize);
        if (!compressed)
            throw std::bad_alloc();

        dst.reserve(dst.size() + compressedSize);
        dst.insert(dst.end(), compressed, compressed + compressedSize);
    } catch (...) {
        if (compressed)
            free(compressed);
        if (optimal)
            free(optimal);
        throw;
    }

    free(compressed);
    free(optimal);
    */

    //lua_pushlstring(L, reinterpret_cast<const char*>(dst.data()), dst.size());
    lua_pushlstring(L, reinterpret_cast<const char*>(result.data()), result.size());
    return 1;
}

const luaL_Reg LuaMusic[] = {
    { "musicProcess", luaMusicProcess },
    { nullptr, nullptr }
};
