#!/usr/bin/env python3
"""Explicit project TCB inventory: physical and nonblank lines, no semantic-size claim."""
import ast
import csv
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT/'kprog/results/kprog_fidelity_20261106/tcb'


def command(*args, cwd=ROOT):
    return subprocess.check_output(args, cwd=cwd, text=True).strip()


def includes(path, seen=None):
    seen = set() if seen is None else seen
    path = path.resolve()
    if path in seen:
        return seen
    seen.add(path)
    for name in re.findall(r'^\s*#include\s+"([^"]+)"', path.read_text(), re.M):
        child = (path.parent/name).resolve()
        if not child.is_file():
            raise FileNotFoundError(child)
        includes(child, seen)
    return seen


def imports(path, seen=None):
    seen = set() if seen is None else seen
    path = path.resolve()
    if path in seen:
        return seen
    seen.add(path)
    for node in ast.walk(ast.parse(path.read_text())):
        names = [node.module] if isinstance(node, ast.ImportFrom) and node.module else [x.name for x in node.names] if isinstance(node, ast.Import) else []
        for name in names:
            for base in [path.parent, ROOT/'kprog', ROOT]:
                child = base/(name.replace('.', '/')+'.py')
                if child.is_file():
                    imports(child,seen)
                    break
    return seen


def function_spans(path, names):
    text=path.read_text()
    scrub=re.sub(r'/\*[\s\S]*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"', lambda m: ''.join('\n' if c=='\n' else ' ' for c in m.group()), text)
    rows=[]
    for name in names:
        match=re.search(r'(?m)^(?:[A-Za-z_][\w:*<>]*[ \t*&]+)+'+re.escape(name)+r'\s*\(',scrub)
        if not match:raise RuntimeError(f'missing binding function {path}:{name}')
        begin=scrub.index('{',match.end()); depth=1; end=begin+1
        while depth:
            depth += (scrub[end]=='{')-(scrub[end]=='}');end+=1
        first=text.count('\n',0,match.start())+1;last=text.count('\n',0,end)+1
        rows.append(dict(path=str(path.relative_to(ROOT)),function=name,first_line=first,last_line=last,physical_lines=last-first+1))
    return rows


def main():
    OUT.mkdir(parents=True,exist_ok=True)
    sim = {arch:includes(ROOT/f'kprog/{arch}/{arch}_sim_local_bpf.h') for arch in ['x86','arm64']}
    shared = sim['x86'] & sim['arm64']
    groups = {f'{arch} simulator (including ISA-specific generated C)':paths-shared for arch,paths in sim.items()}
    groups['shared simulator generated C'] = shared
    for arch in ['x86','arm64']:
        groups[f'{arch} native-to-proof generator (including local imports)'] = imports(ROOT/f'kprog/{arch}/micro-prog/generate_micro_sim_proofs.py')
    groups['proof build/load orchestration'] = {ROOT/'kprog/run_micro_sim_batch.py'}
    groups['native shared loader/linker integration'] = set((ROOT/'kprog/libnativeloader/src').glob('*.[ch]pp')) | set((ROOT/'kprog/libnativeloader/include').glob('*.hpp'))
    groups['native ELF linker (both ISAs)'] = set((ROOT/'kprog/x86/native_lab/native_link/src').glob('*.rs'))
    groups['standalone proof loader'] = {ROOT/'kprog/loader/src/main.rs'}
    groups['application syscall shim'] = {p for p in (ROOT/'bpfopt/shim').glob('*.c') if not p.name.startswith('selftest')} | set((ROOT/'bpfopt/shim').glob('*.h'))
    for arch in ['x86','arm64']:
        groups[f'{arch} native kernel module'] = {ROOT/f'kinsn/module/{arch}/bpf_{arch}_native_lab.c'}
    groups['shared binding wire contract'] = {ROOT/'kinsn/module/include/native_lab_binding.h',ROOT/'kinsn/module/include/native_lab_group.h'}
    groups['vendored helper declarations (ABI input, not project-owned)'] = {ROOT/'vendor/libbpf/src/bpf_helper_defs.h'}
    groups['formal model and proofs (Lean, including generated)'] = set((ROOT/'kprog/formal/KProgFormal').rglob('*.lean')) | {ROOT/'kprog/formal/KProgFormal.lean'}
    groups['formal contracts (JSON)'] = set((ROOT/'kprog/formal/contracts').glob('*.json'))
    groups['formal contract generators'] = set((ROOT/'kprog/formal/tools').glob('generate_*_spec.py'))
    groups['translation-validation model, checker and proofs (Lean)'] = set((ROOT/'kprog/tv').glob('*.lean'))
    groups['translation-validation ELF extraction'] = {ROOT/'kprog/tv/extract_blocks.py'}
    groups['constant-op dispatch generator'] = {ROOT/'kprog/arm64/generate_sim_dispatch.py'}
    groups['native-proof kernel patch and application (patch text, not SLOC)'] = {ROOT/'kprog/tv/native-proof-regions.patch',ROOT/'kprog/tv/apply_kernel_patch.py'}
    groups['existing verifier context (not incremental kernel changes)'] = {ROOT/'vendor/linux-framework/kernel/bpf/verifier.c',ROOT/'vendor/linux-framework/include/linux/bpf_verifier.h'}
    rows=[]
    for component,paths in groups.items():
        if not paths:
            raise RuntimeError(f'empty component: {component}')
        for path in sorted(paths):
            text=path.read_text()
            lines=text.splitlines()
            rows.append(dict(component=component,path=str(path.relative_to(ROOT)),physical_lines=len(lines),nonblank_lines=sum(bool(x.strip()) for x in lines)))
    with (OUT/'files.csv').open('w') as file:
        writer=csv.DictWriter(file,fieldnames=['component','path','physical_lines','nonblank_lines'],lineterminator='\n');writer.writeheader();writer.writerows(rows)
    totals=[]
    for component in groups:
        selected=[row for row in rows if row['component']==component]
        totals.append(dict(component=component,files=len(selected),physical_lines=sum(row['physical_lines'] for row in selected),nonblank_lines=sum(row['nonblank_lines'] for row in selected)))
    binding=[]
    for arch in ['x86','arm64']:
        binding += function_spans(ROOT/f'kinsn/module/{arch}/bpf_{arch}_native_lab.c', ['decode_native_lab_payload','native_lab_advance_generation','instantiate_native_lab','blob_write','relocs_write','proof_write','binding_write','generation_read'])
    binding += function_spans(ROOT/'kprog/libnativeloader/src/native_loader.cpp', ['bound_proof_sequence','upload_proof_chunk','read_blob_generation','seal_bound_chunk','upload_bound_proofs','open_simulator_proof','finish_simulator_proof'])
    (OUT/'binding-functions.json').write_text(json.dumps(binding,indent=2)+'\n')
    (OUT/'components.json').write_text(json.dumps(totals,indent=2)+'\n')
    kernel=ROOT/'vendor/linux-framework'
    base='6f0caf14e995^'
    diff=command('git','diff','--numstat',base,cwd=kernel)
    (OUT/'kernel-changes.tsv').write_text('added\tdeleted\tpath\n'+diff+'\n')
    (OUT/'provenance.txt').write_text('repository='+command('git','rev-parse','HEAD')+'\nkernel='+command('git','rev-parse','HEAD',cwd=kernel)+'\nkernel_base='+command('git','rev-parse',base,cwd=kernel)+'\n\n'+command('git','status','--short')+'\n\nkernel status:\n'+command('git','status','--short',cwd=kernel)+'\n')
    for row in totals:print(f"{row['component']}: {row['files']} files, {row['physical_lines']} physical, {row['nonblank_lines']} nonblank")


if __name__=='__main__':
    main()
