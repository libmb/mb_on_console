#!/bin/sh

set -e

cd "$(dirname "$0")/.."

sh build/clean.sh
rm -f mb_on_console
