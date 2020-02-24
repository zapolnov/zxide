#ifndef COMPILER_MUSICCOMPILER_H
#define COMPILER_MUSICCOMPILER_H

#include <sstream>
#include <ayfly.h>

//
// Fast ZX AY-Dump Player (with PC Compiler)
//
// codename: ay_zip_player ver 1.2
//
// thx to Robus for cool idea'
// thx to GriV for optimization'
// thx to ayfly.dlls authors for cool stuff!
//
// (с)2010-2016 TmK^[deMarche]
//

/*
Введите максимальный размер блока для поиска повторений (2..256)
(Как правило это размер дампа наименьшего паттерна)
Например если в исходном треке минимальный размер паттерна = 32,
скорость = 4, то указываем размер блока 32*4 = 128,
если в исходном треке минимальный размер паттерна = 16,
скорость = 3, то указываем размер блока 16*3 = 48 и т.п.
Можно компилировать модули с плавающей скорость, но
эта скорость должна быть одинаковой для каждого паттерна, тогда
указываем сколько прерываний играется наименьший паттерн:
Например для постоянно меняющейся скорости 2-3-2-3...,
для размера паттерна 64 указываем 32*2+32*3=160
Будет произведена компиляция модуля с размерами:
для указанного размера блока, его половины, четверти и т.д.
Далее Вам остается выбрать подходящий вариант и сохранит результат
*/

namespace
{
    struct t_abs
    {
        uint8_t block_size;
        uint16_t player_size;
        uint16_t tbl_size;
        uint16_t trk_size;
        uint16_t p_size;
    };

    struct t_ay_dump_mask
    {
        int a_tone_mask;
        int b_tone_mask;
        int c_tone_mask;
        int env_per_mask;
    };

    struct t_ay_dump
    {
        uint8_t a_tone_low;
        uint8_t a_tone_hi;
        uint8_t b_tone_low;
        uint8_t b_tone_hi;
        uint8_t c_tone_low;
        uint8_t c_tone_hi;
        uint8_t noise;
        uint8_t control;
        uint8_t a_volume;
        uint8_t b_volume;
        uint8_t c_volume;
        uint8_t env_per_low;
        uint8_t env_per_hi;
        uint8_t env_form;
    };

    struct t_tonevol_patt
    {
        uint8_t index;
        uint8_t volume;
    };

    struct t_index_patt
    {
        uint8_t index;
    };

    struct t_reg_dump_patt
    {
        uint8_t noise;
        uint8_t control;
    };

    struct t_variants
    {
        uint8_t byte0; //tone_low  env_low  noise
        uint8_t byte1; //tone_hi   env_hi   control
        uint8_t byte2; //volume*   form
    };

    const int direction_a=1;
    const int direction_b=2;
    const int direction_c=3;
    const int direction_env=4;
    const int direction_reg=5;

    struct MusicCompiler
    {
        uint8_t dechex_view;

        uint8_t Song[65536];
        t_ay_dump ay_dump[65536];
        t_ay_dump_mask ay_dump_mask[65536];
        t_tonevol_patt temp_patt_tonevol[256];
        t_index_patt temp_patt_index[256];
        t_tonevol_patt cha_patt[1024][256];
        t_tonevol_patt chb_patt[1024][256];
        t_tonevol_patt chc_patt[1024][256];
        t_index_patt env_patt[1024][256];
        t_index_patt reg_patt[1024][256];
        uint32_t cha_patt_count;
        uint32_t chb_patt_count;
        uint32_t chc_patt_count;
        uint32_t env_patt_count;
        uint32_t reg_patt_count;
        uint16_t ay_dump_count;

        t_variants var_variants[5][16384];
        uint16_t var_variants_count[5];
        uint8_t var_tonevol_type[5]; //0-ToneVol 1-Tone
        //-- временный массив для слияния таблиц
        t_variants var_merge[16384];
        uint16_t var_merge_count;
        uint8_t var_merge_type;
        uint8_t index_from,index_to;
        //-- флаги слияния 0-норм, >0- перемещен в (индекс-1)
        uint8_t merge_tables[5];
        //-- смещения адресов таблиц
        uint16_t TBL_ADR[5];
        uint16_t TBL_SIZE;
        //--
        uint16_t channel_a_size;
        uint16_t channel_b_size;
        uint16_t channel_c_size;
        uint16_t channel_e_size;
        uint16_t channel_r_size;
        uint16_t track_a[4096];
        uint16_t track_b[4096];
        uint16_t track_c[4096];
        uint16_t track_e[4096];
        uint16_t track_r[4096];
        uint16_t track_a_count;
        uint16_t track_b_count;
        uint16_t track_c_count;
        uint16_t track_e_count;
        uint16_t track_r_count;
        t_abs arr_block_size[8];
        uint8_t abs_count;
        int temp_block_size;
        uint16_t trk_size,p_size;

        // Options
        uint8_t max_block_size = 2;
        int block_size_index = 0;
        bool flag_loop = false;
        bool flag_fixed_t = false;

        //---------------------------------- вычисляем длину и адреса таблиц
        void calc_adr_tbl()
        {
            uint16_t CURR_ADR;
            int i;

            //--- вычисляем смещения таблиц
            CURR_ADR = 0;
            for (i = 0; i < 5; i++) { //располагаем таблицы последовательно
                if (merge_tables[i] == 0) {
                    TBL_ADR[i] = CURR_ADR;
                    CURR_ADR = CURR_ADR + 768 - var_tonevol_type[i] * 256;
                }
            }

            TBL_SIZE = CURR_ADR;
            for (i = 0; i < 5; i++) { //настраиваем адреса влитых таблиц
                if (merge_tables[i] != 0)
                    TBL_ADR[i] = TBL_ADR[merge_tables[i] - 1];
            }
        }

        //-------------------------------------------- OPEN AY DUMP
        void open_ay_dump(void* musicHandle)
        {
            int i;
            int save_a_tone = 0, save_b_tone = 0, save_c_tone = 0, save_env_per = 0;
            int save_a_vol = 0, save_b_vol = 0, save_c_vol = 0;
            int check;

            ay_resetsong(musicHandle);
            unsigned long musicLen = ay_getsonglength(musicHandle);
            ay_dump_count = musicLen;
            for (i = 0; i < int(musicLen); i++) {
                ay_seeksong(musicHandle, ay_getelapsedtime(musicHandle) + 1);
                memcpy(&ay_dump[i], ay_getregs(musicHandle, 0), 14); //14
            }

            for (i = 0; i < 65536; i++) {
                ay_dump_mask[i].a_tone_mask = 0;
                ay_dump_mask[i].b_tone_mask = 0;
                ay_dump_mask[i].c_tone_mask = 0;
                ay_dump_mask[i].env_per_mask = 0;
            }

            uint8_t env_per_low = ay_dump[i].env_per_low;
            uint8_t env_per_hi = ay_dump[i].env_per_hi;
            uint8_t a_tone_low = ay_dump[i].a_tone_low;
            uint8_t a_tone_hi = ay_dump[i].a_tone_hi;
            uint8_t b_tone_low = ay_dump[i].b_tone_low;
            uint8_t b_tone_hi = ay_dump[i].b_tone_hi;
            uint8_t c_tone_low = ay_dump[i].c_tone_low;
            uint8_t c_tone_hi = ay_dump[i].c_tone_hi;

            // normalize registers
            for (i = 0; i < ay_dump_count; i++) {
                ay_dump[i].a_volume = ay_dump[i].a_volume & 31;
                ay_dump[i].b_volume = ay_dump[i].b_volume & 31;
                ay_dump[i].c_volume = ay_dump[i].c_volume & 31;
                ay_dump[i].control = ay_dump[i].control & 63;
                ay_dump[i].noise = ay_dump[i].noise & 31;
                ay_dump[i].env_form = ay_dump[i].env_form & 15;
                ay_dump[i].a_tone_hi = ay_dump[i].a_tone_hi & 15;
                ay_dump[i].b_tone_hi = ay_dump[i].b_tone_hi & 15;
                ay_dump[i].c_tone_hi = ay_dump[i].c_tone_hi & 15;
            }

            // check volumes
            for (i = 0; i < ay_dump_count; i++) {
                if (((ay_dump[i].a_volume & 16) != 0) && (ay_dump[i].a_volume != 16)) {
                    ay_dump[i].a_volume = 16;
                    save_a_vol++;
                }
                if (((ay_dump[i].b_volume & 16) != 0) && (ay_dump[i].b_volume != 16)) {
                    ay_dump[i].b_volume = 16;
                    save_b_vol++;
                }
                if (((ay_dump[i].c_volume & 16) != 0) && (ay_dump[i].c_volume != 16)) {
                    ay_dump[i].c_volume = 16;
                    save_c_vol++;
                }
            }

            // check tones and envelope
            for (i = 0; i < ay_dump_count; i++) {
                // check env
                check = int(ay_dump[i].a_volume/16) + int(ay_dump[i].b_volume/16) + int(ay_dump[i].c_volume/16);
                if (check == 0) {
                    ay_dump[i].env_per_low = env_per_low;
                    ay_dump[i].env_per_hi = env_per_hi;
                } else {
                    env_per_low = ay_dump[i].env_per_low;
                    env_per_hi = ay_dump[i].env_per_hi;
                    ay_dump_mask[i].env_per_mask = 1;
                    save_env_per++;
                }
                // check tone_a
                check = 1 - ay_dump[i].control & 1;
                if (check > 0)
                    check = ay_dump[i].a_volume & 31;
                if (check == 0) {
                    ay_dump[i].a_tone_low = 0;
                    ay_dump[i].a_tone_hi = 0;
                } else {
                    a_tone_low = ay_dump[i].a_tone_low;
                    a_tone_hi = ay_dump[i].a_tone_hi;
                    ay_dump_mask[i].a_tone_mask = 1;
                    save_a_tone++;
                }
                // check tone_b
                check = 2 - ay_dump[i].control & 2;
                if (check > 0)
                    check = ay_dump[i].b_volume & 31;
                if (check == 0) {
                    ay_dump[i].b_tone_low = 0;
                    ay_dump[i].b_tone_hi = 0;
                } else {
                    b_tone_low = ay_dump[i].b_tone_low;
                    b_tone_hi = ay_dump[i].b_tone_hi;
                    ay_dump_mask[i].b_tone_mask = 1;
                    save_b_tone++;
                }
                // check tone_c
                check = 4 - ay_dump[i].control & 4;
                if (check > 0)
                    check = ay_dump[i].c_volume & 31;
                if (check == 0) {
                    ay_dump[i].c_tone_low = 0;
                    ay_dump[i].c_tone_hi = 0;
                } else {
                    c_tone_low = ay_dump[i].c_tone_low;
                    c_tone_hi = ay_dump[i].c_tone_hi;
                    ay_dump_mask[i].c_tone_mask = 1;
                    save_c_tone++;
                }
            }
        }

        //-----------------------------------------------------------
        //--- вычисляем варианты значений
        void calc_var_tonevol_a()
        {
            int i, j;
            bool flag;

            var_variants_count[0] = 0;
            var_tonevol_type[0] = 0;
            memset(&var_variants[0], 0, sizeof(var_variants[0]));
            for (i = 0; i < ay_dump_count; i++) {
                j = 0;
                flag = false;
                while ((j < var_variants_count[0]) && !flag) {
                    if ((var_variants[0][j].byte0 == ay_dump[i].a_tone_low) &&
                        (var_variants[0][j].byte1 == ay_dump[i].a_tone_hi) &&
                        (var_variants[0][j].byte2 == ay_dump[i].a_volume))
                        flag = true;
                    j++;
                }
                if (!flag) {
                    var_variants[0][var_variants_count[0]].byte0 = ay_dump[i].a_tone_low;
                    var_variants[0][var_variants_count[0]].byte1 = ay_dump[i].a_tone_hi;
                    var_variants[0][var_variants_count[0]].byte2 = ay_dump[i].a_volume;
                    ++var_variants_count[0];
                }
            }
        }

        //---------------------------
        void calc_var_tonevol_b()
        {
            int i, j;
            bool flag;

            var_variants_count[1] = 0;
            var_tonevol_type[1] = 0;
            memset(&var_variants[1], 0, sizeof(var_variants[1]));
            for (i = 0; i < ay_dump_count; i++) {
                j = 0;
                flag = false;
                while ((j < var_variants_count[1]) && !flag) {
                    if ((var_variants[1][j].byte0 == ay_dump[i].b_tone_low) &&
                        (var_variants[1][j].byte1 == ay_dump[i].b_tone_hi) &&
                        (var_variants[1][j].byte2 == ay_dump[i].b_volume))
                        flag = true;
                    j++;
                }
                if (!flag) {
                    var_variants[1][var_variants_count[1]].byte0 = ay_dump[i].b_tone_low;
                    var_variants[1][var_variants_count[1]].byte1 = ay_dump[i].b_tone_hi;
                    var_variants[1][var_variants_count[1]].byte2 = ay_dump[i].b_volume;
                    ++var_variants_count[1];
                }
            }
        }

        //---------------------------
        void calc_var_tonevol_c()
        {
            int i, j;
            bool flag;

            var_variants_count[2] = 0;
            var_tonevol_type[2] = 0;
            memset(&var_variants[2], 0, sizeof(var_variants[2]));
            for (i = 0; i < ay_dump_count; i++) {
                j = 0;
                flag = false;
                while ((j < var_variants_count[2]) && !flag) {
                    if ((var_variants[2][j].byte0 == ay_dump[i].c_tone_low) &&
                        (var_variants[2][j].byte1 == ay_dump[i].c_tone_hi) &&
                        (var_variants[2][j].byte2 == ay_dump[i].c_volume))
                        flag = true;
                    ++j;
                }
                if (!flag) {
                    var_variants[2][var_variants_count[2]].byte0 = ay_dump[i].c_tone_low;
                    var_variants[2][var_variants_count[2]].byte1 = ay_dump[i].c_tone_hi;
                    var_variants[2][var_variants_count[2]].byte2 = ay_dump[i].c_volume;
                    ++var_variants_count[2];
                }
            }
        }

        //-----------------------------
        void calc_var_tone_a()
        {
            int i, j;
            bool flag;

            var_variants_count[0] = 0;
            var_tonevol_type[0] = 1;
            memset(&var_variants[0], 0, sizeof(var_variants[0]));
            for (i = 0; i < ay_dump_count; i++) {
                j = 0;
                flag = false;
                while ((j < var_variants_count[0]) && !flag) {
                    if ((var_variants[0][j].byte0 == ay_dump[i].a_tone_low) &&
                        (var_variants[0][j].byte1 == ay_dump[i].a_tone_hi))
                        flag = true;
                    ++j;
                }
                if (!flag) {
                    var_variants[0][var_variants_count[0]].byte0 = ay_dump[i].a_tone_low;
                    var_variants[0][var_variants_count[0]].byte1 = ay_dump[i].a_tone_hi;
                    var_variants[0][var_variants_count[0]].byte2 = 0;
                    ++var_variants_count[0];
                }
            }
        }

        //---------------------------
        void calc_var_tone_b()
        {
            int i, j;
            bool flag;

            var_variants_count[1] = 0;
            var_tonevol_type[1] = 1;
            memset(&var_variants[1], 0, sizeof(var_variants[1]));
            for (i = 0; i < ay_dump_count; i++) {
                j = 0;
                flag = false;
                while ((j < var_variants_count[1]) && !flag) {
                    if ((var_variants[1][j].byte0 == ay_dump[i].b_tone_low) &&
                        (var_variants[1][j].byte1 == ay_dump[i].b_tone_hi))
                        flag = true;
                    ++j;
                }
                if (!flag) {
                    var_variants[1][var_variants_count[1]].byte0 = ay_dump[i].b_tone_low;
                    var_variants[1][var_variants_count[1]].byte1 = ay_dump[i].b_tone_hi;
                    var_variants[1][var_variants_count[1]].byte2 = 0;
                    ++var_variants_count[1];
                }
            }
        }

        //---------------------------
        void calc_var_tone_c()
        {
            int i, j;
            bool flag;

            var_variants_count[2] = 0;
            var_tonevol_type[2] = 1;
            memset(&var_variants[2], 0, sizeof(var_variants[2]));
            for (i = 0; i < ay_dump_count; i++) {
                j = 0;
                flag = false;
                while ((j < var_variants_count[2]) && !flag) {
                    if ((var_variants[2][j].byte0 == ay_dump[i].c_tone_low) &&
                        (var_variants[2][j].byte1 == ay_dump[i].c_tone_hi))
                        flag = true;
                    ++j;
                }
                if (!flag) {
                    var_variants[2][var_variants_count[2]].byte0 = ay_dump[i].c_tone_low;
                    var_variants[2][var_variants_count[2]].byte1 = ay_dump[i].c_tone_hi;
                    var_variants[2][var_variants_count[2]].byte2 = 0;
                    ++var_variants_count[2];
                }
            }
        }

        //------------------
        void calc_var_env()
        {
            int i, j;
            bool flag;

            var_variants_count[3] = 0;
            var_tonevol_type[3] = 0;
            memset(&var_variants[3], 0, sizeof(var_variants[3]));
            for (i = 0; i < ay_dump_count; i++) {
                j = 0;
                flag = false;
                while ((j < var_variants_count[3]) && !flag) {
                    if ((var_variants[3][j].byte0 == ay_dump[i].env_per_low) &&
                        (var_variants[3][j].byte1 == ay_dump[i].env_per_hi) &&
                        (var_variants[3][j].byte2 == ay_dump[i].env_form))
                        flag = true;
                    ++j;
                }
                if (!flag) {
                    var_variants[3][var_variants_count[3]].byte0 = ay_dump[i].env_per_low;
                    var_variants[3][var_variants_count[3]].byte1 = ay_dump[i].env_per_hi;
                    var_variants[3][var_variants_count[3]].byte2 = ay_dump[i].env_form;
                    ++var_variants_count[3];
                }
            }
        }

        //------------------
        void calc_var_reg()
        {
            int i, j;
            bool flag;

            var_variants_count[4] = 0;
            var_tonevol_type[4] = 1;
            memset(&var_variants[4], 0, sizeof(var_variants[4]));
            for (i = 0; i < ay_dump_count; i++) {
                j = 0;
                flag = false;
                while ((j < var_variants_count[4]) && !flag) {
                    if ((var_variants[4][j].byte0 == ay_dump[i].noise) &&
                        (var_variants[4][j].byte1 == ay_dump[i].control))
                        flag = true;
                    ++j;
                }
                if (!flag) {
                    var_variants[4][var_variants_count[4]].byte0 = ay_dump[i].noise;
                    var_variants[4][var_variants_count[4]].byte1 = ay_dump[i].control;
                    ++var_variants_count[4];
                }
            }
        }

        //-------------------------
        void create_temp_patt_a(int n, int pattsize)
        {
            int i;
            uint8_t j, index;
            uint8_t id;

            if (merge_tables[0] == 0)
                id = 0;
            else
                id = merge_tables[0]-1;

            for (i = 0; i < pattsize; i++) {
                //--- ищем индекс
                index = 255;
                for (j = 0; j < var_variants_count[id]; j++) {
                    if (var_tonevol_type[0] == 0) {
                        //проверка tonevol
                        if ((var_variants[id][j].byte0 == ay_dump[pattsize*n+i].a_tone_low) &&
                            (var_variants[id][j].byte1 == ay_dump[pattsize*n+i].a_tone_hi) &&
                            (var_variants[id][j].byte2 == ay_dump[pattsize*n+i].a_volume))
                            index = j;
                    }
                    if (var_tonevol_type[0] == 1) {
                        //проверка tone
                        if ((var_variants[id][j].byte0 == ay_dump[pattsize*n+i].a_tone_low) &&
                            (var_variants[id][j].byte1 == ay_dump[pattsize*n+i].a_tone_hi))
                            index = j;
                    }
                } //ищем индекс

                //--- сохраняем индекс
                temp_patt_tonevol[i].index = index;
                temp_patt_tonevol[i].volume = ay_dump[pattsize*n+i].a_volume;
            }
        }

        //-------------------------------------
        void create_temp_patt_b(int n, int pattsize)
        {
            int i;
            int j, index;
            uint8_t id;

            if (merge_tables[1] == 0)
                id = 1;
            else
                id = merge_tables[1]-1;

            for (i = 0; i < pattsize; i++) {
                //--- ищем индекс
                index = 256;
                for (j = 0; j < var_variants_count[id]; j++) {
                    if (var_tonevol_type[1] == 0) {
                        //проверка tonevol
                        if ((var_variants[id][j].byte0 == ay_dump[pattsize*n+i].b_tone_low) &&
                            (var_variants[id][j].byte1 == ay_dump[pattsize*n+i].b_tone_hi) &&
                            (var_variants[id][j].byte2 == ay_dump[pattsize*n+i].b_volume))
                            index = j;
                    }
                    if (var_tonevol_type[1] == 1) {
                        //проверка tone
                        if ((var_variants[id][j].byte0 == ay_dump[pattsize*n+i].b_tone_low) &&
                            (var_variants[id][j].byte1 == ay_dump[pattsize*n+i].b_tone_hi))
                            index = j;
                    }
                } //ищем индекс

                //--- сохраняем индекс
                temp_patt_tonevol[i].index = index;
                temp_patt_tonevol[i].volume = ay_dump[pattsize*n+i].b_volume;
            }
        }

        //-------------------------------------
        void create_temp_patt_c(int n, int pattsize)
        {
            int i;
            uint8_t j, index;
            uint8_t id;

            if (merge_tables[2] == 0)
                id = 2;
            else
                id = merge_tables[2]-1;

            for (i = 0; i < pattsize; i++) {
                //--- ищем индекс
                index = 255;
                for (j = 0; j < var_variants_count[id]; j++) {
                    if (var_tonevol_type[2] == 0) {
                        //проверка tonevol
                        if ((var_variants[id][j].byte0 == ay_dump[pattsize*n+i].c_tone_low) &&
                            (var_variants[id][j].byte1 == ay_dump[pattsize*n+i].c_tone_hi) &&
                            (var_variants[id][j].byte2 == ay_dump[pattsize*n+i].c_volume))
                            index = j;
                    }
                    if (var_tonevol_type[2] == 1) {
                        //проверка tone
                        if ((var_variants[id][j].byte0 == ay_dump[pattsize*n+i].c_tone_low) &&
                            (var_variants[id][j].byte1 == ay_dump[pattsize*n+i].c_tone_hi))
                            index = j;
                    }
                } //ищем индекс

                //--- сохраняем индекс
                temp_patt_tonevol[i].index = index;
                temp_patt_tonevol[i].volume = ay_dump[pattsize*n+i].c_volume;
            }
        }

        //---------------------------------------
        void create_temp_patt_env(int n, int pattsize)
        {
            int i;
            uint8_t j, index;
            uint8_t id;

            if (merge_tables[3] == 0)
                id = 3;
            else
                id = merge_tables[3]-1;

            for (i = 0; i < pattsize; i++) {
                //--- ищем индекс
                index = 255;
                for (j = 0; j < var_variants_count[id]; j++) {
                    //проверка env
                    if ((var_variants[id][j].byte0 == ay_dump[pattsize*n+i].env_per_low) &&
                        (var_variants[id][j].byte1 == ay_dump[pattsize*n+i].env_per_hi) &&
                        (var_variants[id][j].byte2 == ay_dump[pattsize*n+i].env_form))
                        index = j;
                } //ищем индекс
                //--- сохраняем индекс
                temp_patt_index[i].index = index;
            }
        }

        //---------------------------------------
        void create_temp_patt_reg(int n, int pattsize)
        {
            int i;
            uint8_t j, index;
            uint8_t id;

            if (merge_tables[4] == 0)
                id = 4;
             else
                id = merge_tables[4]-1;

            for (i = 0; i < pattsize; i++) {
                //--- ищем индекс
                index = 255;
                for (j = 0; j < var_variants_count[id]; j++) {
                    //проверка env
                    if ((var_variants[id][j].byte0 == ay_dump[pattsize*n+i].noise) &&
                        (var_variants[id][j].byte1 == ay_dump[pattsize*n+i].control))
                        index = j;
                } //ищем индекс
                //--- сохраняем индекс
                temp_patt_index[i].index = index;
            }
        }

        //---------------------------------------
        void calc_patterns_a(uint8_t pattsize)
        {
            uint16_t dump_patt_count;
            int i, j, k;
            bool flag;

            dump_patt_count = uint16_t(ay_dump_count/pattsize);
            track_a_count = 0;
            cha_patt_count = 0;
            memset(&cha_patt, 0, sizeof(cha_patt));
            for (i = 0; i < dump_patt_count; i++) {
                //--- создаем временный паттерн
                create_temp_patt_a(i, pattsize);
                //--- ищем подобный паттерн в уже созданных
                j = 0;
                flag = false;
                while ((j < int(cha_patt_count)) && !flag) {
                    flag = true;
                    for (k = 0; k < pattsize; k++) { // цикл по длине паттерна
                        if (var_tonevol_type[0] == 0) {
                            if (cha_patt[j][k].index != temp_patt_tonevol[k].index)
                                flag = false;
                        }
                        if (var_tonevol_type[0] == 1) {
                            if ((cha_patt[j][k].index != temp_patt_tonevol[k].index) ||
                                (cha_patt[j][k].volume != temp_patt_tonevol[k].volume))
                                flag = false;
                        }
                    } // цикл по длине паттерна
                    ++j;
                }
                //--- проверяем флаг поиска
                if (flag) {
                    //нашли (j-1)=номер найденного
                } else {
                    //новый
                    for (k = 0; k < pattsize; k++) {
                        cha_patt[cha_patt_count][k].index = temp_patt_tonevol[k].index;
                        cha_patt[cha_patt_count][k].volume = temp_patt_tonevol[k].volume;
                    }
                    ++cha_patt_count;
                    j = cha_patt_count;
                }
                //записываем трек
                if (var_tonevol_type[0] == 0)
                    track_a[track_a_count] = (j - 1) * pattsize;
                else
                    track_a[track_a_count] = 2 * (j - 1) * pattsize;
                ++track_a_count;
            }

            // вычисляем размеры
            channel_a_size = cha_patt_count * pattsize;
            if (var_tonevol_type[0] == 1)
                channel_a_size = channel_a_size * 2;
        }

        //---------------------------------------
        void calc_patterns_b(uint8_t pattsize)
        {
            uint16_t dump_patt_count;
            int i, j, k;
            bool flag;

            dump_patt_count = uint16_t(ay_dump_count/pattsize);
            track_b_count = 0;
            chb_patt_count = 0;
            memset(&chb_patt, 0, sizeof(chb_patt));
            for (i = 0; i < dump_patt_count; i++) {
                //--- создаем временный паттерн
                create_temp_patt_b(i, pattsize);
                //--- ищем подобный паттерн в уже созданных
                j = 0;
                flag = false;
                while ((j < int(chb_patt_count)) && !flag) {
                    flag = true;
                    for (k = 0; k < pattsize; k++) { // цикл по длине паттерна
                        if (var_tonevol_type[1] == 0) {
                            if (chb_patt[j][k].index != temp_patt_tonevol[k].index)
                                flag = false;
                        }
                        if (var_tonevol_type[1] == 1) {
                            if ((chb_patt[j][k].index != temp_patt_tonevol[k].index) ||
                                (chb_patt[j][k].volume != temp_patt_tonevol[k].volume))
                                flag = false;
                        }
                    } // цикл по длине паттерна
                    ++j;
                }
                //--- проверяем флаг поиска
                if (flag) {
                    //нашли (j-1)=номер найденного
                } else {
                    //новый
                    for (k = 0; k < pattsize; k++) {
                        chb_patt[chb_patt_count][k].index = temp_patt_tonevol[k].index;
                        chb_patt[chb_patt_count][k].volume = temp_patt_tonevol[k].volume;
                    }
                    ++chb_patt_count;
                    j = chb_patt_count;
                }
                //записываем трек
                if (var_tonevol_type[1] == 0)
                    track_b[track_b_count] = (j - 1) * pattsize;
                else
                    track_b[track_b_count] = 2 * (j - 1) * pattsize;
                ++track_b_count;
            }

            // вычисляем размеры
            channel_b_size = chb_patt_count * pattsize;
            if (var_tonevol_type[1] == 1)
                channel_b_size = channel_b_size * 2;
        }

        //---------------------------------------
        void calc_patterns_c(uint8_t pattsize)
        {
            uint16_t dump_patt_count;
            int i, j, k;
            bool flag;

            dump_patt_count = uint16_t(ay_dump_count/pattsize);
            track_c_count = 0;
            chc_patt_count = 0;
            memset(&chc_patt, 0, sizeof(chc_patt));
            for (i = 0; i < dump_patt_count; i++) {
                //--- создаем временный паттерн
                create_temp_patt_c(i, pattsize);
                //--- ищем подобный паттерн в уже созданных
                j = 0;
                flag = false;
                while ((j < int(chc_patt_count)) && !flag) {
                    flag = true;
                    for (k = 0; k < pattsize; k++) { // цикл по длине паттерна
                        if (var_tonevol_type[2] == 0) {
                            if (chc_patt[j][k].index != temp_patt_tonevol[k].index)
                                flag = false;
                        }
                        if (var_tonevol_type[2] == 1) {
                            if ((chc_patt[j][k].index != temp_patt_tonevol[k].index) ||
                                (chc_patt[j][k].volume != temp_patt_tonevol[k].volume))
                                flag = false;
                        }
                    } // цикл по длине паттерна
                    ++j;
                }
                //--- проверяем флаг поиска
                if (flag) {
                    //нашли (j-1)=номер найденного
                } else {
                    //новый
                    for (k = 0; k < pattsize; k++) {
                        chc_patt[chc_patt_count][k].index = temp_patt_tonevol[k].index;
                        chc_patt[chc_patt_count][k].volume = temp_patt_tonevol[k].volume;
                    }
                    ++chc_patt_count;
                    j = chc_patt_count;
                }
                //записываем трек
                if (var_tonevol_type[2] == 0)
                    track_c[track_c_count] = (j - 1) * pattsize;
                else
                    track_c[track_c_count] = 2 * (j - 1) * pattsize;
                ++track_c_count;
            }

            // вычисляем размеры
            channel_c_size = chc_patt_count * pattsize;
            if (var_tonevol_type[2] == 1)
                channel_c_size = channel_c_size * 2;
        }

        //---------------------------------------
        void calc_patterns_env(uint8_t pattsize)
        {
            uint16_t dump_patt_count;
            int i, j, k;
            bool flag;

            dump_patt_count = uint16_t(ay_dump_count/pattsize);
            track_e_count = 0;
            env_patt_count = 0;
            memset(&env_patt, 0, sizeof(env_patt));
            for (i = 0; i < dump_patt_count; i++) {
                //--- создаем временный паттерн
                create_temp_patt_env(i, pattsize);
                //--- ищем подобный паттерн в уже созданных
                j = 0;
                flag = false;
                while ((j < int(env_patt_count)) && !flag) {
                    flag = true;
                    for (k = 0; k < pattsize; k++) { // цикл по длине паттерна
                        if (env_patt[j][k].index != temp_patt_index[k].index)
                            flag = false;
                    } // цикл по длине паттерна
                    ++j;
                }
                //--- проверяем флаг поиска
                if (flag) {
                    //нашли (j-1)=номер найденного
                } else {
                    //новый
                    for (k = 0; k < pattsize; k++)
                        env_patt[env_patt_count][k].index = temp_patt_index[k].index;
                    ++env_patt_count;
                    j = env_patt_count;
                }
                //записываем трек
                track_e[track_e_count] = (j - 1) * pattsize;
                ++track_e_count;
            }

            // вычисляем размеры
            channel_e_size = env_patt_count * pattsize;
        }

        //---------------------------------------
        void calc_patterns_reg(uint8_t pattsize)
        {
            uint16_t dump_patt_count;
            int i, j, k;
            bool flag;

            dump_patt_count = uint16_t(ay_dump_count / pattsize);
            track_r_count = 0;
            reg_patt_count = 0;
            memset(&reg_patt, 0, sizeof(reg_patt));
            for (i = 0; i < dump_patt_count; i++) {
                //--- создаем временный паттерн
                create_temp_patt_reg(i, pattsize);
                //--- ищем подобный паттерн в уже созданных
                j = 0;
                flag = false;
                while ((j < int(reg_patt_count)) && !flag) {
                    flag = true;
                    for (k = 0; k < pattsize; k++) { // цикл по длине паттерна
                        if (reg_patt[j][k].index != temp_patt_index[k].index)
                            flag = false;
                    } // цикл по длине паттерна
                    ++j;
                }
                //--- проверяем флаг поиска
                if (flag) {
                    //нашли (j-1)=номер найденного
                } else {
                    //новый
                    for (k = 0; k < pattsize; k++)
                        reg_patt[reg_patt_count][k].index = temp_patt_index[k].index;
                     ++reg_patt_count;
                     j = reg_patt_count;
                }
                //записываем трек
                track_r[track_r_count] = (j - 1) * pattsize;
                ++track_r_count;
            }

            // вычисляем размеры
            channel_r_size = reg_patt_count * pattsize;
        }

        void compile()
        {
            //-- вычисляем длину и адреса таблиц
            calc_adr_tbl();
            //--------------------------------------------------
            //Шаг 3. - Создаем треки и паттерны для каналов
            //--------------------------------------------------
            temp_block_size = max_block_size * 2;
            abs_count = 0;
            while (temp_block_size == 2 * int(temp_block_size/2)) {
                temp_block_size = int(temp_block_size/2);
                calc_patterns_a(temp_block_size);
                calc_patterns_b(temp_block_size);
                calc_patterns_c(temp_block_size);
                calc_patterns_env(temp_block_size);
                calc_patterns_reg(temp_block_size);
                trk_size = 5 * track_a_count * 2 + 2;
                p_size = channel_a_size + channel_b_size + channel_c_size + channel_e_size + channel_r_size;
                arr_block_size[abs_count].block_size = temp_block_size;
                arr_block_size[abs_count].player_size = 512;
                arr_block_size[abs_count].tbl_size = TBL_SIZE;
                arr_block_size[abs_count].trk_size = trk_size;
                arr_block_size[abs_count].p_size = p_size;
                ++abs_count;
            }
        }

        std::string save()
        {
            uint16_t ADR;
            uint8_t temp_block_size;
            int i, j;
            int takts_min, takts_max;

            //---
            takts_min = 24;
            if (var_tonevol_type[0] == 0)
                takts_min = takts_min + 189;
            else
                takts_min = takts_min + 191;
            if (var_tonevol_type[1] == 0)
                takts_min = takts_min + 192;
            else
                takts_min = takts_min + 194;
            if (var_tonevol_type[2] == 0)
                takts_min = takts_min + 192;
            else
                takts_min = takts_min + 194;
            takts_max = takts_min + 219 + 139 + 31 + 14 + (194 + 10);
            takts_min = takts_min + 192 + 139 + 31 + 14;
            if (flag_loop)
                takts_max = takts_max + 50;
            //---
            temp_block_size = arr_block_size[block_size_index].block_size;
            calc_patterns_a(temp_block_size);
            calc_patterns_b(temp_block_size);
            calc_patterns_c(temp_block_size);
            calc_patterns_env(temp_block_size);
            calc_patterns_reg(temp_block_size);
            calc_adr_tbl(); //tbl_size:=768+512+768*3-(256*(var_tonevol_type[0]+var_tonevol_type[1]+var_tonevol_type[2]));
            trk_size = 5 * track_a_count * 2 + 2;
            p_size = channel_a_size + channel_b_size + channel_c_size + channel_e_size + channel_r_size;
            //-------------------------
            std::stringstream ss;
            ss << "@@TABLES:\n";
            //Write table Ch_A
            if (merge_tables[0] == 0) {
                ss << "db ";
                const char* prefix = "";
                for (i = 0; i < 256; i++) {
                    ss << prefix << unsigned(var_variants[0][i].byte0);
                    prefix = ",";
                    if (i % 16 == 15)
                        prefix = "\ndb ";
                }
                for (i = 0; i < 256; i++) {
                    ss << prefix << unsigned(var_variants[0][i].byte1);
                    prefix = ",";
                    if (i % 16 == 15)
                        prefix = "\ndb ";
                }
                if (var_tonevol_type[0] == 0) {
                    for (i = 0; i < 256; i++) {
                        ss << prefix << unsigned(var_variants[0][i].byte2);
                        prefix = ",";
                        if (i % 16 == 15)
                            prefix = "\ndb ";
                    }
                }
                ss << "\n";
            }
            //Write table Ch_B
            if (merge_tables[1] == 0) {
                ss << "db ";
                const char* prefix = "";
                for (i = 0; i < 256; i++) {
                    ss << prefix << unsigned(var_variants[1][i].byte0);
                    prefix = ",";
                    if (i % 16 == 15)
                        prefix = "\ndb ";
                }
                for (i = 0; i < 256; i++) {
                    ss << prefix << unsigned(var_variants[1][i].byte1);
                    prefix = ",";
                    if (i % 16 == 15)
                        prefix = "\ndb ";
                }
                if (var_tonevol_type[1] == 0) {
                    for (i = 0; i < 256; i++) {
                        ss << prefix << unsigned(var_variants[1][i].byte2);
                        prefix = ",";
                        if (i % 16 == 15)
                            prefix = "\ndb ";
                    }
                }
                ss << "\n";
            }
            //Write table Ch_C
            if (merge_tables[2] == 0) {
                ss << "db ";
                const char* prefix = "";
                for (i = 0; i < 256; i++) {
                    ss << prefix << unsigned(var_variants[2][i].byte0);
                    prefix = ",";
                    if (i % 16 == 15)
                        prefix = "\ndb ";
                }
                for (i = 0; i < 256; i++) {
                    ss << prefix << unsigned(var_variants[2][i].byte1);
                    prefix = ",";
                    if (i % 16 == 15)
                        prefix = "\ndb ";
                }
                if (var_tonevol_type[1] == 0) {
                    for (i = 0; i < 256; i++) {
                        ss << prefix << unsigned(var_variants[2][i].byte2);
                        prefix = ",";
                        if (i % 16 == 15)
                            prefix = "\ndb ";
                    }
                }
                ss << "\n";
            }
            // Write table ENV
            if (merge_tables[3] == 0) {
                ss << "db ";
                const char* prefix = "";
                for (i = 0; i < 256; i++) {
                    ss << prefix << unsigned(var_variants[3][i].byte0);
                    prefix = ",";
                    if (i % 16 == 15)
                        prefix = "\ndb ";
                }
                for (i = 0; i < 256; i++) {
                    ss << prefix << unsigned(var_variants[3][i].byte1);
                    prefix = ",";
                    if (i % 16 == 15)
                        prefix = "\ndb ";
                }
                for (i = 0; i < 256; i++) {
                    ss << prefix << unsigned(var_variants[3][i].byte2);
                    prefix = ",";
                    if (i % 16 == 15)
                        prefix = "\ndb ";
                }
                ss << "\n";
            }
            // write table REG
            if (merge_tables[4] == 0) {
                ss << "db ";
                const char* prefix = "";
                for (i = 0; i < 256; i++) {
                    ss << prefix << unsigned(var_variants[4][i].byte0);
                    prefix = ",";
                    if (i % 16 == 15)
                        prefix = "\ndb ";
                }
                for (i = 0; i < 256; i++) {
                    ss << prefix << unsigned(var_variants[4][i].byte1);
                    prefix = ",";
                    if (i % 16 == 15)
                        prefix = "\ndb ";
                }
                ss << "\n";
            }
            //--------------
            ss << "@@TRACK:\n";
            for (i = 0; i < track_a_count; i++) {
                ADR = track_a[i];
                ss << "dw @@PATTERNS + " << ADR << "\n";
                ADR = track_b[i] + channel_a_size;
                ss << "dw @@PATTERNS + " << ADR << "\n";
                ADR = track_c[i] + channel_a_size + channel_b_size;
                ss << "dw @@PATTERNS + " << ADR << "\n";
                ADR = track_e[i] + channel_a_size + channel_b_size + channel_c_size;
                ss << "dw @@PATTERNS + " << ADR << "\n";
                ADR = track_r[i] + channel_a_size + channel_b_size + channel_c_size + channel_e_size;
                ss << "dw @@PATTERNS + " << ADR << "\n";
            }
            ss << "dw 0\n";
            //--------------------------------------------------------
            //-- ch_a
            ss << "@@PATTERNS:\ndb ";
            const char* prefix = "";
            for (i = 0; i < int(cha_patt_count); i++) {
                for (j = 0; j < temp_block_size; j++) {
                    ss << prefix << unsigned(cha_patt[i][j].index);
                    prefix = ",";
                    if (var_tonevol_type[0] == 1)
                        ss << prefix << unsigned(cha_patt[i][j].volume);
                }
            }
            //-- ch_b
            ss << "\ndb ";
            prefix = "";
            for (i = 0; i < int(chb_patt_count); i++) {
                for (j = 0; j < temp_block_size; j++) {
                    ss << prefix << unsigned(chb_patt[i][j].index);
                    prefix = ",";
                    if (var_tonevol_type[1] == 1)
                        ss << prefix << unsigned(chb_patt[i][j].volume);
                }
            }
            //-- ch_c
            ss << "\ndb ";
            prefix = "";
            for (i = 0; i < int(chc_patt_count); i++) {
                for (j = 0; j < temp_block_size; j++) {
                    ss << prefix << unsigned(chc_patt[i][j].index);
                    prefix = ",";
                    if (var_tonevol_type[2] == 1)
                        ss << prefix << unsigned(chc_patt[i][j].volume);
                }
            }
            //-- ch_env
            ss << "\ndb ";
            prefix = "";
            for (i = 0; i < int(env_patt_count); i++) {
                for (j = 0; j < temp_block_size; j++) {
                    ss << prefix << unsigned(env_patt[i][j].index);
                    prefix = ",";
                }
            }
            //-- ch_reg
            ss << "\ndb ";
            prefix = "";
            for (i = 0; i < int(reg_patt_count); i++) {
                for (j = 0; j < temp_block_size; j++) {
                    ss << prefix << unsigned(reg_patt[i][j].index);
                    prefix = ",";
                }
            }
            //---
            //--------------------------------------------------------
            ss << "\n@@PLAYER:\n";
            ss << "PATTSIZE EQU " << int(temp_block_size) << "\n"; // размер паттерна (block_size)
            ss << "CHA_TYPE EQU " << int(var_tonevol_type[0]) << "\n"; // Тип канала A
            ss << "CHB_TYPE EQU " << int(var_tonevol_type[1]) << "\n"; // Тип канала B ;0-громкость в таблице
            ss << "CHC_TYPE EQU " << int(var_tonevol_type[2]) << "\n"; // Тип канала C ;1-громкость в паттерне
            ss << "PL_CONST_T EQU " << int(flag_fixed_t) << "\n"; // Тип плеера: 0-простой, 1-фиксированный по тактам
            ss << "PL_LOOPFLAG EQU " << int(flag_loop) << "\n"; // Зацикливание 0-не надо, 1-надо зацикливать
            // FIXME ss << "PL_LOOP EQU " << int(loop_adr) << "\n"; // адрес в треке для зацикливания
            ss << "TBL_NV_A	EQU	@@TABLES + " << TBL_ADR[0] << "\n";
            ss << "TBL_NV_B	EQU	@@TABLES + " << TBL_ADR[1] << "\n";
            ss << "TBL_NV_C	EQU	@@TABLES + " << TBL_ADR[2] << "\n";
            ss << "TBL_ENV EQU @@TABLES + " << TBL_ADR[3] << "\n";
            ss << "TBL_REG EQU @@TABLES + " << TBL_ADR[4] << "\n";
            return ss.str();
        }

/*
ShowMessage ('Для вычисления данного параметра надо:'+#13#10+
'1. Вычислить длину в прерываниях до нужного вам паттерна'+#13#10+
'int_len = нужная позиция зацикливания * длину паттерна * скорость'+#13#10+
'2. Вычичислить параметр по формуле: 10 * int_len / Selected block_size'+#13#10+#13#10+
'Например:'+#13#10+
'Длина паттернов 64, скорость 3, хотим зациклить на позицию 4,'+#13#10+
'а выбранный при компиляции block_size = 24 тогда:'+#13#10+
'int_len = 4*64*3 = 768'+#13#10+
'Искомый адрес зацикливания: 10*768/24 = 320'
*/

        bool calctbl()
        {
            memset(merge_tables, 0, sizeof(merge_tables));
            //--------------------------------------------------
            //Шаг 1. - вычисляем варианты для каждого из каналов
            //--------------------------------------------------
            //--- Calc variants Channel_A
            calc_var_tonevol_a();
            if (var_variants_count[0] > 256)
                calc_var_tone_a();
            //--- Calc variants Channel_B
            calc_var_tonevol_b();
            if (var_variants_count[1] > 256)
                calc_var_tone_b();
            //--- Calc variants Channel_C
            calc_var_tonevol_c();
            if (var_variants_count[2] > 256)
                calc_var_tone_c();
            //--- Calc variants Channel_Env
            calc_var_env();
            //--- Calc variants Channel_Reg
            calc_var_reg();
            //--- Проверка возможности компиляции
            if ((var_variants_count[0] > 256) ||
                (var_variants_count[1] > 256) ||
                (var_variants_count[2] > 256) ||
                (var_variants_count[4] > 256) ||
                (var_variants_count[3] > 256))
                return false;

            calc_adr_tbl();
            return true;
        }

#if 0
procedure TForm1.Button_trymergeClick(Sender: TObject);
const ch_text:array[0..4]of string=('A','B','C','Env','Reg');
var from_size,to_size:integer;
  i,j,find_count:integer;
  merge_err,flag:boolean;
begin
merge_err:=false;
Button_confirmmerge.Enabled:=false;
//------------------------------------------
// 2.1 Ручная склейка таблиц для уменьшения
// занимаемого места
//------------------------------------------
index_from:=Form1.ComboBox_Merge_from.ItemIndex;
index_to:=Form1.ComboBox_Merge_to.ItemIndex;
//-- проверка слияния из уже соединенного канала (надо убрать возможность такого выбора)
if (merge_tables[index_from]<>0) then
  begin
  merge_err:=true;
  ShowMessage('ОШИБКА!!!'+#13#10+'Таблица этого канала уже слита в таблицу канала '+ch_text[merge_tables[index_from]]);
  end;
flag:=false;
for i:=0 to 4 do
  begin
  if (merge_tables[i]=index_from+1) then
    begin
    flag:=true;
    end;
  end;
if (flag=true) then
  begin
  merge_err:=true;
  ShowMessage('ОШИБКА!!!'+#13#10+'В эту таблицу канала '+ch_text[index_from]+' сливались другие, она может быть только приемником');
  end;
//-- проверка слияния в самого себя
if(Form1.ComboBox_Merge_from.ItemIndex=Form1.ComboBox_Merge_to.ItemIndex) then
  begin
  merge_err:=true;
  ShowMessage('ОШИБКА!!!'+#13#10+'Попытка слияния канала с самим собой');
  end;
//-- проверка размера слияния
  var_merge_type:=var_tonevol_type[index_to];
  to_size:=768-var_merge_type*256;
  var_merge_type:=var_tonevol_type[index_from];
  from_size:=768-var_merge_type*256;
if (to_size<from_size) then
  begin
  merge_err:=true;
  ShowMessage('ОШИБКА!!!'+#13#10+'Нельзя из большего размера делать слияние в меньший');
  end;
//-- если нет ошибок считаем слияние
if(merge_err=false) then
  begin
//-- очищаем
zeromemory (@var_merge,sizeof(var_merge));
//-- копируем TO массив
for i:=0 to var_variants_count[index_to]-1 do
  begin
  var_merge[i].byte0:=var_variants[index_to,i].byte0;
  var_merge[i].byte1:=var_variants[index_to,i].byte1;
  var_merge[i].byte2:=var_variants[index_to,i].byte2;
  end;
var_merge_count:=var_variants_count[index_to];
//-- сравниваем с FROM массивом
find_count:=0;
for i:=0 to var_variants_count[index_from]-1 do
  begin
  j:=0; flag:=false;
  While ( (j<var_variants_count[index_to]) and (flag=false) ) do
    begin
    if ((var_tonevol_type[index_from]=1) and (var_variants[index_from,i].byte0=var_variants[index_to,i].byte0) and (var_variants[index_from,i].byte1=var_variants[index_to,i].byte1)) then begin flag:=true; inc(find_count); end;
    if ((var_tonevol_type[index_from]=0) and (var_variants[index_from,i].byte0=var_variants[index_to,i].byte0) and (var_variants[index_from,i].byte1=var_variants[index_to,i].byte1) and (var_variants[index_from,i].byte2=var_variants[index_to,i].byte2)) then begin flag:=true; inc(find_count); end;
    inc (j);
    end;
  if not(flag) then
    begin
    var_merge[var_merge_count].byte0:=var_variants[index_from,i].byte0;
    var_merge[var_merge_count].byte1:=var_variants[index_from,i].byte1;
   if (var_tonevol_type[index_from]=0) then var_merge[var_merge_count].byte2:=var_variants[index_from,i].byte2;
    inc (var_merge_count);
    end;
  end;
  //--- результат
  Form1.Memo1.Lines.Add('');
  Form1.Memo1.Lines.Add('Calculate merge channels '+
  ch_text[index_from]+' => '+ch_text[index_to]
  +': size='+IntToStr(var_merge_count)+' (save '+IntToStr(find_count)+' values)');
  //--- реакция на кнопку подтвердить
  if (var_merge_count<=256) then
    begin
    Button_confirmmerge.Enabled:=true;
    end
  else Form1.Memo1.Lines.Add('overflow, merge impossible');
  end; //считаем слияние
end;

procedure TForm1.Button_confirmmergeClick(Sender: TObject);
const ch_text:array[0..4]of string=('A','B','C','Env','Reg');
var i,save_bytes:integer;
begin
Button_confirmmerge.Enabled:=false;
for i:=0 to var_merge_count-1 do
  begin
  var_variants[index_to,i].byte0:=var_merge[i].byte0;
  var_variants[index_to,i].byte1:=var_merge[i].byte1;
  var_variants[index_to,i].byte2:=var_merge[i].byte2;
  end;
var_variants_count[index_to]:=var_merge_count;  
merge_tables[index_from]:=index_to+1;
//---
save_bytes:=0;
Memo1.Lines.Add('');Memo1.Lines.Add('Merge tables ---------');
for i:=0 to 4 do
  begin
  if (merge_tables[i]=0) then
    begin
    Memo1.Lines.Add('Channel_'+ch_text[i]+' variants: '+IntToStr(var_variants_count[i])+' [size='+IntToStr(768-256*var_tonevol_type[i])+']');
    end
  else
    begin
    Memo1.Lines.Add('Channel_'+ch_text[i]+' => '+ch_text[merge_tables[i]-1]);
    save_bytes:=save_bytes+768-(256*var_tonevol_type[i]);
    end;
  end;
Calc_adr_tbl();
Form1.Memo1.Lines.Add('All tables size = '+IntToStr(TBL_SIZE));
Memo1.Lines.Add('Saved: '+IntToStr(save_bytes)+' bytes');
end;

end.
#endif

    };
}

#endif
