#!/usr/bin/env python3
"""Exercise native stack scalar observation across a real map helper call."""
import argparse,importlib.util,json,sys
from pathlib import Path
R=Path('/workspaces/repository');O=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('trusted_negative_replay',R/'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/check.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
p=argparse.ArgumentParser();p.add_argument('mode',choices=['build','check']);p.add_argument('phase',choices=['before','after']);a=p.parse_args()
m.OUT=O/a.phase;m.OUT.mkdir(exist_ok=True);m.BUILD=R/'kprog/formal/build/fidelity-projection-order'
m.cases=lambda:[dict(name='stack_alias_map_value_compare',assembly='push r14; sub rsp,16; mov QWORD PTR [rsp],0; lea r14,[rsp+8]; lea rsi,[rsp]; mov rdi,QWORD PTR [rip+neg_map@GOTPCREL]; call bpf_map_lookup_elem; cmp rax,r14; jne 1f; xor eax,eax; jmp 2f; 1: mov eax,2; 2: add rsp,16; pop r14; ret',negative=False)]
(m.build if a.mode=='build' else m.check)()
