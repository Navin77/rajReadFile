!#/bin/bash

rm build -rf
meson build &&
meson compile -C build -v