#!/usr/bin/env python3
import argparse,importlib.util
from pathlib import Path
R=Path('/workspaces/repository');O=Path(__file__).resolve().parent/'after/safety'
s=importlib.util.spec_from_file_location('trusted_safety',R/'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/check.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
m.OUT=O;m.OUT.mkdir(parents=True,exist_ok=True);m.BUILD=R/'kprog/formal/build/fidelity-projection-safety'
p=argparse.ArgumentParser();p.add_argument('mode',choices=['build','check']);a=p.parse_args();(m.build if a.mode=='build' else m.check)()
