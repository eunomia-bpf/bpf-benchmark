#!/usr/bin/env python3
"""Replay native safety fixtures through ordinary B and the stock-path loader."""
from pathlib import Path
import argparse
import json
import os
import shutil
import types

parser = argparse.ArgumentParser()
parser.add_argument('mode', choices=['build', 'check'])
parser.add_argument('--out', type=Path, required=True)
parser.add_argument('--arch', choices=['x86', 'arm64'], default='x86')
parser.add_argument('--inputs', type=Path,
                    default=Path('/workspaces/.agent-state/kprog-ck/verified-safety'))
parser.add_argument('--cases', type=Path)
args = parser.parse_args()
ROOT = Path('/workspaces/repository')
SUITE = ROOT / 'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp'
source = (SUITE / 'check.py').read_text()
source = source.replace("str(BUILD/'bound-probe')", repr(os.environ.get('KPROG_STOCK_BOUND_PROBE', str(args.inputs/'bound-probe'))))
check = types.ModuleType('kprog_safety_check')
check.__file__ = str(SUITE / 'check.py')
exec(compile(source, check.__file__, 'exec'), check.__dict__)
check.ARCH = args.arch
check.BUILD = args.inputs
check.loader_build = lambda: Path(os.environ.get('KPROG_STOCK_LOADER', '/workspaces/.agent-state/kprog-ck/verified-loader'))
check.native_link = lambda: Path(os.environ.get('KPROG_STOCK_NATIVE_LINK',
    str(ROOT/'kprog/x86/native_lab/native_link/target/release/native-link')))
args.out.mkdir(parents=True, exist_ok=True)
if args.mode == 'check':
    shutil.copy2(args.cases or args.inputs/'cases.json', args.out/'cases.json')
else:
    check.cases = lambda: json.loads((args.cases or SUITE/'cases.json').read_text())
check.OUT = args.out
getattr(check, args.mode)()
