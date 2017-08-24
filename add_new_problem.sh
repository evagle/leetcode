#!/bin/bash

title="$1"
lowercasename="$2"

if [ $lowercasename"x" == "x" ] || [ "$title""x" == "x" ] ; then
    echo "[ERROR] problem name empty."
    exit 1
fi

if [ -f analysis/$lowercasename.md ]; then
    echo "[ERROR] File exists: "analysis/$lowercasename.md
    exit 1
fi

if [ -f src/$lowercasename.cpp ]; then
    echo "[ERROR] File exists: "src/$lowercasename.cpp
    exit 1
fi

cp template.md analysis/$lowercasename.md
cp template.cpp src/$lowercasename.cpp

sed -i.bak "s:lowercasename:${lowercasename}:g"  analysis/$lowercasename.md
sed -i.bak "s:title:${title}:g"  analysis/$lowercasename.md
rm analysis/$lowercasename.md.bak
