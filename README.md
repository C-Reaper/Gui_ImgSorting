## Overview
The project appears to be a simple GUI application for image sorting. The main functionality is to display an input image and sort its pixels based on mouse movements.

## Features
- Displays an input image.
- Sorts the pixels of the image in real-time based on mouse movements.
- Supports different build targets: Linux, Windows, Wine (Windows cross-compilation), and WebAssembly.

## Project Structure
```
<Project>/
├── src/                
│   ├── Main.c          
│   └── *.h             
├── Makefile.linux      
├── Makefile.windows    
├── Makefile.wine       
├── Makefile.web        
└── README.md           
└── LICENCE
└── .gitignore
```

### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools
- Libraries needed:
  - For Linux: X11, PNG, JPEG
  - For Windows: WINAPI (User32, GDI32, Winmm)
  - For Wine: API for running Windows applications on Linux
  - For WebAssembly: Emscripten

## Build & Run
To build the project:
- Navigate to the project directory.
- Run `make -f Makefile.(os) all` where `(os)` is one of `linux`, `windows`, `wine`, or `web`.

For example, to build for Linux:
```sh
cd <Project>
make -f Makefile.linux all
```

To execute the built application:
- Run `make -f Makefile.(os) exe` where `(os)` is one of `linux`, `windows`, `wine`, or `web`.

For example, to run the Linux build:
```sh
make -f Makefile.linux exe
```

This setup ensures that the project can be built and executed across different platforms using specific configurations.