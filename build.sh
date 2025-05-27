#!/bin/bash
libs=-luser32

warnings="-Wno-writable-strings -Wno-format-security"


clang++ src/Game/main.cpp -oengine.exe $libs $warnings