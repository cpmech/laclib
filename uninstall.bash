#!/bin/bash

read -p "Are you sure [y/n]? " -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]]
then
    echo "sudo rm -rf /usr/local/include/laclib"
    sudo rm -rf /usr/local/include/laclib

    echo "sudo rm -rf /usr/local/lib/liblaclib*.so"
    sudo rm -rf /usr/local/lib/liblaclib*.so

    echo "sudo ldconfig"
    sudo ldconfig

    echo "DONE"
else
    echo "..cancelled.."
fi