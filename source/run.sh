#!/bin/bash
make build-x86_64
qemu-system-x86_64 -cdrom x86_64/kernel.iso