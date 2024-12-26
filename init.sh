#!/bin/sh

set -e

git submodule update --init
ls submodules | xargs -I {} sh -c "cd submodules/{} && sh build.sh"
mkdir -p lib

sh build/misc/compile_commands.json.init.sh
