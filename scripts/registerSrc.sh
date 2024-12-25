#!/usr/bin/env bash

srclist="./cmake/sourcelist.cmake"
headerlist="./cmake/headerlist.cmake"

echo "set(SOURCES \${SOURCES}">"$srclist"

find "src" -type f >> "$srclist"

echo ")">>"$srclist"

echo "set(HEADERS \${HEADERS}">"$headerlist"
find "include" -type f >> "$headerlist"
echo ")">>"$headerlist"