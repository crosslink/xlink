#!/bin/bash

FLAGS="-g -DDEBUG $1"
export CFLAGS=$FLAGS
export CXXFLAGS=$FLAGS
