@echo off

if not exist build (
    mkdir build
) else (
    if exist build (
        if not exist build\NUL (
            del build
            mkdir build
        )
    )
)

cd build
cmake ..
cmake --build .

hangman.exe

cd ..
