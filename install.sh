#!/bin/bash

rm build -rf
meson setup build --buildtype=release &&
meson compile -C build -v &&
meson install -C build