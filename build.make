#!/bin/bash
set -euo pipefail
IFS=$'\n\t'

mkdir -p build-make
cd build-make
cmake -G "Unix Makefiles" ..
make
