#!/usr/bin/env python3
"""Run the x86 native-only safety suite against the stock-path loader and module."""
from pathlib import Path
import shutil, sys, types

ROOT = Path('/workspaces/repository')
SUITE = ROOT / 'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp'
BUILD = Path('/mnt')

# The prebuilt probe predates the current source; use the stock-path build.
source = (SUITE / 'check.py').read_text()
assert "str(BUILD/'bound-probe')" in source
source = source.replace("str(BUILD/'bound-probe')", repr(str(BUILD / 'bp/bound-probe')))
check = types.ModuleType('kprog_safety_check')
check.__file__ = str(SUITE / 'check.py')
exec(compile(source, check.__file__, 'exec'), check.__dict__)
check.loader_build = lambda: BUILD / 'loader/build'

out = Path(sys.argv[sys.argv.index('--out') + 1])
out.mkdir(parents=True, exist_ok=True)
shutil.copy2(SUITE / 'cases.json', out / 'cases.json')
check.OUT = out
check.check()
