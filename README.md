ZX Spectrum IDE
===============

This is a simple Integrated Development Environment for assembler (and, to the limited extent, BASIC)
programming for ZX Spectrum.

It includes its own assembler to provide advanced debugging and code browsing facilities.

Simple code editor, graphic editor and level editor are provided by the IDE.

Lua scripts can be run during compilation to preprocess or generate code and data.

Compiler for BASIC code (based on bas2tape) and audio file generator (based on tape2wav) are also included.

**NOTE: this software is of alpha quality. Expect bugs and make frequent backups of your projects! If you find
any bugs please report them through the GitHub issue system.**

Compiling
---------

You will need CMake and Qt 5. Any decent compiler supporting C++17 should work.
Author uses CMake 3.15.1 with Visual Studio Community 2017 and Qt 5.13.0 on Windows 10 as the primary
development environment. Also periodically the code is tested for compilability on MacOS and Linux. YMMV.
Please create a GitHub issue if you have problems compiling the code.

On Linux you may also need to install ALSA and PulseAudio development packages. All other libraries are
included alongside the project.

Just use the normal CMake flow for compilation. Depending on your system configuration you could have to
specify path to the Qt distribution. For example, the following commands will create a Visual Studio 2017
project if Qt is installed at `C:\Qt\5.13.0`:

```
mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_PREFIX_PATH=C:/Qt/5.13.0/msvc2017_64 ..
```

For Linux and Mac OS it is the same, but in those cases the generator should be `Unix Makefiles` or `Xcode`.
Also specifying `CMAKE_PREFIX_PATH` is usually not required for those operating systems.

For more information please consult CMake documentation.

Documentation and examples
--------------------------

You can find documentation in the `doc` directory in the repository in the Markdown format. The exact same
documentation is also available from the `Help` menu in the IDE.

Some examples are provided in the `doc/examples` directory.

License
-------

License is GNU GPL v2 or any later version.

    Copyright (c) 2019 Nikolay Zapolnov

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

Please note that the license covers only the IDE itself. Any programs you would create with the IDE belong to you
and maybe distributed under your own terms. As a special exception GPL Author explicitly gives permission to use
any source files that IDE may create in the project directory (for example, the default `loader.bas` or files in
the `generated` directory) for any purpose, including (but not limited to) personal, commercial and educational use,
modification and redistribution, without time and territory limitations.

This software also includes a bunch of 3rd party software. Please consult licensing for this software in the
corresponding directories inside `editor/3rdparty`.
