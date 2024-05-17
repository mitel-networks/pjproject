#!/bin/bash
echo "##### Starting PJSIP build"

echo "##### cmd: make clean"
make clean

echo "##### cmd: ./configure"
./configure CFLAGS=-fPIC CXXFLAGS=-fPIC --enable-epoll
# ./configure

echo "##### cmd: make dep && make"
make dep && make

echo "##### cmd: cd pjsip-apps/src/swig"
cd pjsip-apps/src/swig

echo "##### cmd: make clean && make uninstall"
make clean && make uninstall

echo "##### cmd: make && make install"
make && make install

echo "##### PJSIP build completed!"