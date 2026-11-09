#!/usr/bin/env python3
"""Run the x86 native-only safety suite against the stock-path loader and module."""
from pathlib import Path
import importlib.util, shutil, sys

ROOT = Path('/workspaces/repository')
SUITE = ROOT / 'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp'
LOADER = Path('/var/tmp/kprog-tmp/CK/loader/build')

spec = importlib.util.spec_from_file_location('kprog_safety_check', SUITE / 'check.py')
check = importlib.util.module_from_spec(spec)
sys.argv = ['check', 'check'] if len(sys.argv) < 2 else sys.argv
spec.loader.exec_module(check)
check.loader_build = lambda: LOADER
out = Path(sys.argv[sys.argv.index('--out') + 1])
out.mkdir(parents=True, exist_ok=True)
shutil.copy2(SUITE / 'cases.json', out / 'cases.json')
check.OUT = out
check.check()
