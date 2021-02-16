
                section     main

                ; Input:
                ;   None
                ; Returns:
                ;   None
                ; Preserves:
                ;   IX, IY
                ; Trashes:
                ;   A, BC, DE, HL

_DrawMap:       ld          hl, _map_test_tilemap_bank0
                ld          de, 0x80                    ; screen offset 0x0080, start at line 32
                call        @@doLoop
                ld          d, 8                        ; screen offset 0x0800
                call        @@doLoop
                ld          d, 16                       ; screen offset 0x1000
@@doLoop:       ld          a, 0x40                     ; screen address high byte
                add         a, d
                ld          d, a
@@loop:         call        DrawMapLine
                xor         a
                cp          e
                jr          nz, @@loop
                ret

                ; Input:
                ;   HL => tile data for the line
                ;   DE => target screen address
                ; Returns:
                ;   BC => attribute data for the sprite
                ;   DE => screen address usable for DrawMapTileAttributes
                ;   HL => tile data for the next line - 1
                ; Preserves:
                ;   IX, IY
                ; Trashes:
                ;   A

DrawMapTile:    ; read map tile address
                ld          c, (hl)
                inc         hl
                ld          b, (hl)
                ; copy pixels
                repeat      16, N
                ld          a, (bc)
                ld          (de), a
                inc         bc                          ; next tile byte
                if N != 15
                if N % 4 == 0
                inc         e
                endif
                if N % 4 == 2
                dec         e
                endif
                if N % 2 == 1
                inc         d                           ; next row
                endif
                endif
                endrepeat
                ld          a, e
                add         a, 0x20
                ld          e, a
                repeat      16, N
                ld          a, (bc)
                ld          (de), a
                inc         bc                          ; next tile byte
                if N != 15
                if N % 4 == 0
                inc         e
                endif
                if N % 4 == 2
                dec         e
                endif
                if N % 2 == 1
                dec         d                           ; next row
                endif
                endif
                endrepeat
                ret

                ; Input:
                ;   DE => target screen address from DrawMapTile
                ;   BC => attribute data for the sprite
                ; Preserves:
                ;   HL, A', BC', DE', HL', IX, IY
                ; Trashes:
                ;   A, BC, DE

DrawMapTileAttributes:
                ; calculate attribute address
                ld          a, d
                rrca
                rrca
                rrca
                and         3
                ld          d, a
@@1:            ld          a, 0x58                     ; screen attrib base high byte
                or          d
                ld          d, a
                ; copy attributes
                ld          a, (bc)
                inc         bc
                ld          (de), a
                inc         de
                ld          a, (bc)
                inc         bc
                ld          (de), a
                ld          a, e
                sub         a, 0x20
                ld          e, a
                ld          a, (bc)
                inc         bc
                ld          (de), a
                dec         de
                ld          a, (bc)
                ld          (de), a
                ret

                ; Input:
                ;   HL => tile data for the line
                ;   DE => target screen address
                ; Returns:
                ;   HL => tile data for the next line
                ;   DE => target screen address for the next line
                ; Preserves:
                ;   A', IX, IY
                ; Trashes:
                ;   A, BC

DrawMapLine:    push        de
                call        DrawMapTile
                call        DrawMapTileAttributes
                pop         de
                ; advance to the next column
                inc         hl
                inc         e
                ld          a, e
                inc         e
                and         0x1f
                cp          0x1f
                jp          nz, DrawMapLine
                ld          a, e
                add         a, 0x20                     ; next row
                ld          e, a
                ret
