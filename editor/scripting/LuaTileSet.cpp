#include "LuaTileSet.h"
#include "LuaGfx.h"
#include "LuaFiles.h"
#include "LuaVM.h"
#include "compiler/TileSetFile.h"
#include "compiler/TileSetData.h"
#include "compiler/GfxData.h"
#include <string>
#include <sstream>
#include <map>
#include <memory>
#include <lua.hpp>

namespace
{
    struct TileData
    {
        QString name;
        std::unique_ptr<GfxData> gfx;
        int x;
        int y;
        bool walkable;
    };

    struct TileSetObject
    {
        TileSetData data;
        std::map<std::pair<int, int>, TileData> tiles;
    };
}

static int luaTilesetLoad(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    const char* fileName = luaL_checkstring(L, 1);
    const QDir& dir = vm->projectDirectory();
    QString filePath = dir.absoluteFilePath(QString::fromUtf8(fileName));

    QFile file(filePath);
    if (!file.open(QFile::ReadOnly)) {
        QString error = file.errorString();
        return luaL_error(L, "unable to open file '%s': %s", fileName, error.toUtf8().constData());
    }

    TileSetFile tileSetFile(file.readAll());
    file.close();

    TileSetObject* obj = vm->pushNew<TileSetObject>();
    if (!tileSetFile.deserializeFromJson(&obj->data)) {
        QString error = tileSetFile.lastError();
        return luaL_error(L, "unable to load file '%s': %s", fileName, error.toUtf8().constData());
    }

    int tileW = obj->data.tileWidth;
    int tileH = obj->data.tileHeight;

    for (int y = 0; y < TileSetData::GridHeight; y++) {
        for (int x = 0; x < TileSetData::GridWidth; x++) {
            QString tileName = obj->data.tileAt(x, y);
            if (tileName.isEmpty())
                continue;

            lua_pushcfunction(L, &luaGfxLoad);
            vm->pushString(tileName);
            lua_call(L, 1, 2);

            bool isWalkable = lua_toboolean(L, -1);
            GfxData& gfxData = vm->check<GfxData>(-2);

            int nx = (gfxData.width() + tileW - 1) / tileW;
            int ny = (gfxData.height() + tileH - 1) / tileH;
            for (int yy = 0; yy < ny; yy++) {
                for (int xx = 0; xx < nx; xx++) {
                    if (x + xx >= TileSetData::GridWidth || y + yy >= TileSetData::GridHeight)
                        continue;

                    TileData tileData;
                    tileData.name = tileName;
                    tileData.gfx = std::make_unique<GfxData>(tileW, tileH);
                    tileData.x = xx;
                    tileData.y = yy;
                    tileData.walkable = isWalkable;

                    for (int gfxY = 0; gfxY < tileH; gfxY++) {
                        for (int gfxX = 0; gfxX < tileW; gfxX++) {
                            int gfxRealX = xx * tileW + gfxX;
                            int gfxRealY = yy * tileH + gfxY;

                            char attr = 0, pixel = 7;
                            if (gfxData.isValidCoord(gfxRealX, gfxRealY)) {
                                pixel = gfxData.at(gfxRealX, gfxRealY);
                                attr = gfxData.attribAt(gfxRealX, gfxRealY, GfxColorMode::Multicolor);
                            }

                            tileData.gfx->at(gfxX, gfxY) = pixel;
                            tileData.gfx->attribAt(gfxX, gfxY, GfxColorMode::Multicolor) = attr;
                        }
                    }

                    obj->tiles.emplace(std::make_pair(x + xx, y + yy), std::move(tileData));
                }
            }

            lua_pop(L, 2);
        }
    }

    return 1;
}

static int luaTilesetGetTileInfo(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    TileSetObject& obj = vm->check<TileSetObject>(1);
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);

    if (x < 0 || x >= TileSetData::GridWidth)
        return luaL_error(L, "x coordinate is out of range.");
    if (y < 0 || y >= TileSetData::GridHeight)
        return luaL_error(L, "y coordinate is out of range.");

    auto it = obj.tiles.find(std::make_pair(x, y));
    if (it == obj.tiles.end())
        return 0;

    vm->pushString(it->second.name);
    lua_pushboolean(L, it->second.walkable);
    lua_pushinteger(L, it->second.x);
    lua_pushinteger(L, it->second.y);

    return 4;
}

static int luaTilesetGetTileGraphic(lua_State* L)
{
    LuaVM* vm = LuaVM::fromLua(L);

    TileSetObject& obj = vm->check<TileSetObject>(1);
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);

    if (x < 0 || x >= TileSetData::GridWidth)
        return luaL_error(L, "x coordinate is out of range.");
    if (y < 0 || y >= TileSetData::GridHeight)
        return luaL_error(L, "y coordinate is out of range.");

    auto it = obj.tiles.find(std::make_pair(x, y));
    if (it == obj.tiles.end())
        return 0;

    int w = it->second.gfx->width();
    int h = it->second.gfx->height();

    GfxData* gfxData = vm->pushNew<GfxData>(w, h);
    gfxData->setBytes(it->second.gfx->bytes());
    gfxData->setAttrib(0, 0, w, h, it->second.gfx->attrib(0, 0, w - 1, h - 1));
    return 1;
}

const luaL_Reg LuaTileSet[] = {
    { "tilesetLoad", luaTilesetLoad },
    { "tilesetGetTileInfo", luaTilesetGetTileInfo },
    { "tilesetGetTileGraphic", luaTilesetGetTileGraphic },
    { nullptr, nullptr }
};
