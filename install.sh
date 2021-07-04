#!/bin/bash

rm build -rf
meson build -Dbuildtype=release &&
meson compile -C build -v
meson install -C build