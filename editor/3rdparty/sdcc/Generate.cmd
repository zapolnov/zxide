@echo off

cd %~dp0src
if errorlevel 1 exit /b 1

flex -oSDCClex.c SDCC.lex
if errorlevel 1 exit /b 1

bison -y SDCC.y -o SDCCy.c --defines=SDCCy.h
if errorlevel 1 exit /b 1

gawk -f SDCCpeeph.awk z80/peeph.def > z80/peeph.rul
if errorlevel 1 exit /b 1

gawk -f SDCCpeeph.awk z80/peeph-z80.def > z80/peeph-z80.rul
if errorlevel 1 exit /b 1

cd %~dp0support\cpp
if errorlevel 1 exit /b 1

gawk -f opt-gather.awk sdcpp.opt > optionlist
if errorlevel 1 exit /b 1

gawk -f opt-functions.awk -f optc-gen.awk -v header_name="config.h system.h options.h" < optionlist > options.c
if errorlevel 1 exit /b 1

gawk -f opt-functions.awk -f opth-gen.awk < optionlist > options.h
if errorlevel 1 exit /b 1
