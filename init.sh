#!/bin/sh

set -e

git submodule init
git submodule update
ls submodules | xargs -I {} sh -c "cd submodules/{} && make"
