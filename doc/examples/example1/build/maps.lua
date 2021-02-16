
local maps = {
        ['maps/test.map'] = 0,
    }

local mapsTiles = {}

local function split(s, delimiter)
    local result = {}
    string.gsub(s, '[^'..delimiter..']+', function(x) table.insert(result, x) end)
    return result
end

local mapID = 0

local tileMap = {}
local tileMapIndex = {}
local mapTileMap = ''

local keys = {}
for key in pairs(maps) do table.insert(keys, key) end
table.sort(keys)
for _, mapName in ipairs(keys) do
    local bank = maps[mapName]
    local map = mapLoad(mapName)
    local mapW, mapH = mapGetSize(map)
    if mapW ~= 16 then
        error('Map "'..mapName..'" has invalid width (should be 16)')
    end
    if mapH ~= 10 then
        error('Map "'..mapName..'" has invalid height (should be 10)')
    end

    local tilesetName = mapGetTilesetFile(map)
    local tileset = tilesetLoad(tilesetName)

    local symbol = 'map_'..makeValidIdentifierFromFileName(mapName)
    local mapTiles = '\nconst const byte* '..symbol..'_tilemap_bank'..bank..'[] = {\n'
    local mapEnemyInfo = {}
    local mapExterns = ''

    for y = 0, mapH-1 do
        local bit = 0
        local byte = 0
        for x = 0, mapW-1 do
            local tile = mapGetTileAt(map, x, y)
            local mapEntity = mapGetEntityAt(map, x, y)
            local tileX = tile % 16
            local tileY = tile // 16

            local tileName, walkable, tileEntity = tilesetGetTileInfo(tileset, tileX, tileY)
            local gfx, gfxX, gfxY = tilesetGetTileGraphic(tileset, tileX, tileY)
            if not tileName or not gfx then
                error('Missing tile ('..tileX..','..tileY..') in tileset '..tilesetName..' (map '..mapName..')')
            end

            if mapEntity == '' and tileEntity ~= '' then
                mapEntity = tileEntity
            elseif mapEntity ~= '' and tileEntity ~= '' then
                error('Both map and tile entities are present at ('..x..','..y..') in map '..mapName)
            end

            if mapEntity ~= '' then
                for _, entity in ipairs(split(mapEntity, '\n')) do
                    local argv = split(entity, ':')
                    if argv[1] == 'spawn' then
                        --local id = argv[2]
                        --local playerPos = x * 2 + y * 2 * 256
                        --mapInit[#mapInit+1] = '    InitPlayer_bank0('..playerPos..');\n'
                    else
                        error('unknown entity "'..entity..'" in map "'..mapName..'".')
                    end
                end
            end

            local pixels = gfxGenerateZigZagAssembly2(gfx, true)
            pixels = pixels:gsub("db ", "    ")
            pixels = pixels:gsub("\n", ",\n")
            local pixels_md5 = md5(pixels)

            local index = tileMapIndex[pixels_md5]
            if index == nil then
                index = #tileMap + 1
                tileMap[index] = pixels_md5
                tileMapIndex[pixels_md5] = index
                mapTileMap = mapTileMap..'\nconst byte tilemap_anybank_'..index..'[] = {\n'
                mapTileMap = mapTileMap..'    '..pixels..' };\n'
            end

            mapTiles = mapTiles..'    tilemap_anybank_'..index..', // ('..x..','..y..') '..tileName..'\n'
        end
    end

    mapTiles = mapTiles..'};\n'

    local codeTiles =
        '\n//########################################################################'..
        '\n// '..mapName..
        '\n//########################################################################\n'..
        mapTiles

    mapsTiles[symbol] = codeTiles
    mapID = mapID + 1
end

for k,v in pairs(mapsTiles) do
    local code = '#include "common.h"\n\n'
    code = code..'extern const byte tilemap_anybank_1[];\n'
    code = code..'extern const byte tilemap_anybank_2[];\n'
    code = code..v
    writeFile(k..'_tilemap.c', code)
end

local code = '#include "common.h"\n\n'
code = code..mapTileMap
writeFile('tiles.c', code)
