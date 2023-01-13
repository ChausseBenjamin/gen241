
SHELL = /bin/bash

# c++ compiler flags that are used for all targets:
# they make binaries faster and smaller
# -s : strips the binary
# -O3 : optimizes the binary
# -Ofast : optimizes the binary
# -march=native : optimizes the binary for the current CPU
# -flto : link time optimization
CFLAGS = -Ofast -march=native -flto -s
