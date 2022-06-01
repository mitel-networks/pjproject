#!/bin/bash
echo "pjbuild starts!"

echo "cmd       : make clean"
make clean

echo "cmd       : ./configure CFLAGS=-fPIC CXXFLAGS=-fPIC --enable-epoll"
./configure CFLAGS=-fPIC CXXFLAGS=-fPIC --enable-epoll

echo "cmd       : make dep && make"
make dep && clean

echo "cmd       : cd pjsip-apps/src/swig"
cd pjsip-apps/src/swig

echo "cmd       : make clean && make uninstall"
make clean && make uninstall

echo "cmd       : make && make install"
make && make install
