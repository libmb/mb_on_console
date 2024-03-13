#!/bin/sh

git submodule init
ls submodules | xargs -I {} sh -c "cd submodules/{} && make"
