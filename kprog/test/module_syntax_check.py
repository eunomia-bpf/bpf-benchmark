#!/usr/bin/env python3
"""Syntax-check the module with its sole canonical build's saved compiler flags."""
import pathlib
import shlex
import subprocess
import sys

object_dir = pathlib.Path(sys.argv[1])
line = (object_dir / ".kprog_stock.o.cmd").read_text().splitlines()[0]
args = shlex.split(line.split(":=", 1)[1])
command = []
skip = False
for arg in args:
    if arg == ";":
        break
    if skip:
        skip = False
        continue
    if arg == "-o":
        skip = True
    elif arg != "-c" and not arg.startswith("-Wp,-MMD,"):
        command.append(arg)
command.append("-fsyntax-only")
subprocess.run(command, cwd=object_dir, check=True)
