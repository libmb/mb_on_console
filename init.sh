#!/bin/sh

set -e

git submodule init
git submodule update
ls submodules | xargs -I {} sh -c "cd submodules/{} && sh build.sh"
mkdir -p lib

sh build/misc/compile_commands.json.init.sh
