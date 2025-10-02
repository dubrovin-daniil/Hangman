cmake_minimum_required(VERSION 3.10)
project(Hangman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    Hangman/Hangman.cpp
    Hangman/HangmanGame.cpp
)

add_executable(hangman ${SOURCES})
