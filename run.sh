#!/bin/bash

make iso
qemu-system-i386 -cdrom myos.iso
