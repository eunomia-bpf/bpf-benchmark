#!/usr/bin/env python3
"""Preserve F evidence before removing completed raw files and duplicate builds."""
from pathlib import Path
import collections,gzip,hashlib,json,os,shutil,subprocess,tarfile
R=Path('/workspaces/repository');S=Path('/workspaces/.agent-state/kprog-lanes/F');OUT=R/'kprog/results/kprog_fidelity_20261107/cleanup'
roots=[R/'kprog/results/kprog_fidelity_20261106',R/'kprog/results/kprog_fidelity_20261107']
assert (S/'local-sp-v3-cpu.exit').read_text().strip()=='0'
assert (S/'sp-v3c-full.exit').read_text().strip()=='2'
tracked=set(subprocess.check_output(['git','ls-files','--with-tree=HEAD','--','kprog/results','kprog/fidelity'],text=True).splitlines())
untracked=set(subprocess.check_output(['git','ls-files','--others','--exclude-standard','--',*[str(p.relative_to(R)) for p in roots]],text=True).splitlines())
# Include ignored raw intermediates; never remove a tracked artifact.
for root in roots:
 for p in root.rglob('*'):
  if p.is_file() and p.name in ['cpu-states.bin','reference','reference.bin']:
   rel=str(p.relative_to(R))
   if rel not in tracked:untracked.add(rel)
keep=set();remove=[];records=[];groups=collections.defaultdict(list)
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(4*1024*1024),b''):h.update(b)
 return h.hexdigest()
def gzip_sha(p):
 h=hashlib.sha256()
 with gzip.open(p,'rb') as f:
  for b in iter(lambda:f.read(4*1024*1024),b''):h.update(b)
 return h.hexdigest()
for index,rel in enumerate(sorted(untracked)):
 p=R/rel
 if OUT in p.parents:continue
 if not p.exists():continue
 digest=sha(p);record=dict(path=rel,bytes=p.stat().st_size,sha256=digest)
 group=R/Path(*Path(rel).parts[:5]);groups[group].append(record)
 if p.name in ['cpu-states.bin','reference','reference.bin']:
  record['action']='delete completed raw trace or rebuildable reference executable';remove.append(rel)
 elif p.suffix=='.jsonl' or p.name.endswith('.trace.txt'):
  dst=Path(str(p)+'.gz')
  if dst.exists():assert gzip_sha(dst)==digest,str(dst)
  else:
   with p.open('rb') as fi,gzip.open(dst,'wb',compresslevel=6) as fo:shutil.copyfileobj(fi,fo,4*1024*1024)
  assert gzip_sha(dst)==digest,str(dst)
  record.update(action='retain lossless gzip; delete raw',retained=str(dst.relative_to(R)),retained_sha256=sha(dst));keep.add(str(dst.relative_to(R)));remove.append(rel)
 else:
  record['action']='retain small evidence or source';keep.add(rel)
 records.append(record)
 if index%35==0:print('preserved',index,'/',len(untracked),flush=True)
for group,rows in groups.items():
 p=group/'README.md'
 if not p.exists():
  p.write_text('# Retained experiment records\n\nThese are completed F experiment records retained during the operator-ordered\ncleanup. Per-form TSVs, outcome JSON and logs retain their measured outcomes;\nthis archival step makes no additional correctness claim. Counterexamples are\nlossless gzip streams. Rebuildable reference executables and raw CPU traces\nare removed only after publication. See `../../cleanup/README.md` and its\nretention manifest for file hashes and deletion provenance.\n')
  keep.add(str(p.relative_to(R)))
# Exact late FULL failure and broad real-CPU success, not a stale running claim.
dst=R/'kprog/results/kprog_fidelity_20261107/differential/x86-sp-native64-candidate'
for suffix in ['log','exit','sources.json']:
 p=S/('sp-v3c-full.'+suffix);out=dst/(p.name+'.gz')
 with p.open('rb') as fi,gzip.open(out,'wb') as fo:shutil.copyfileobj(fi,fo)
 keep.add(str(out.relative_to(R)))
p=dst/'README.md';t=p.read_text();t=t.replace('Its complete immutable FULL check was still running at this publication boundary.','Its complete immutable FULL check ended2 at the existing MULX route host oracle\n(1610 comparison failures): its raw tagged-cell expected values do not yet\nmaterialize native stack bits. The exact failure is retained; the runtime fix\nis still private. The later full1077-form CPU matrix finished1102848cases with\nzero differences (separate per-form data in ../x86-sp-v3-full/).');p.write_text(t);keep.add(str(p.relative_to(R)))
with tarfile.open(OUT/'broad-cpu-harness.tar.gz','w:gz') as ar:
 build=R/'kprog/fidelity/build-sp-v3-cpu'
 for n in ['generated.c','native.S','native.asm','native.o','coverage.json','cpu-differential']:
  if (build/n).exists():ar.add(build/n,arcname=n)
# Preserve old candidate inputs needed to reproduce the new v2 summary, while
# retiring all expanded private source trees. v3/v3c already published at eb0fa77d8.
source=R/'kprog/fidelity/build-sp-v2/source';pins=json.loads((S/'sp-v2-source-pins.json').read_text())
with tarfile.open(OUT/'v2-source.tar.gz','w:gz') as ar:
 for rel,digest in pins['files'].items():
  p=source/rel;assert sha(p)==digest,rel;ar.add(p,arcname=rel)
shutil.copyfile(S/'sp-native64-runtime.patch',OUT/'sp-native64-runtime.patch')
shutil.copyfile(S/'sp-integrated-source-pins.json',OUT/'sp-integrated-source-pins.json')
# Historical lane recipes/checkpoints/logs become one archive, not live competing
# workspaces. Mechanical private indexes and rebuilt objects are discarded.
suffixes={'.py','.sh','.c','.cpp','.h','.S','.md','.json','.txt','.log','.exit','.state','.yaml','.mk','.patch'}
with tarfile.open(OUT/'lane-recipes-and-notes.tar.gz','w:gz') as ar:
 for p in sorted(S.rglob('*')):
  if not p.is_file() or p.is_symlink() or '.lake' in p.parts or '__pycache__' in p.parts:continue
  if p.suffix not in suffixes or p.stat().st_size>20*1024*1024:continue
  ar.add(p,arcname=str(p.relative_to(S)))
# Retain the old diagnostic ABI tools as an archive, not another live build.
with tarfile.open(OUT/'diagnostic-abi-tools.tar.gz','w:gz') as ar:
 ar.add(R/'kprog/fidelity/build-abi-fixed',arcname='build-abi-fixed',filter=lambda t:None if '/__pycache__/' in t.name else t)
# Retain authored application-negative preparation without executing it.
for n in ['application_negative.py','application_negative_proxy.cpp']:keep.add('kprog/fidelity/'+n)
# These source trees are lane-owned duplicates. The operator explicitly keeps
# shared vendor/build, native_link/target, formal/.lake and ccache untouched.
dirs=[str(p.relative_to(R)) for p in (R/'kprog/fidelity').glob('build*') if p.is_dir()]
(OUT/'retention.json').write_text(json.dumps(records,indent=2)+'\n')
(OUT/'remove-plan.json').write_text(json.dumps(dict(files=remove,build_dirs=dirs,lane_dir=str(S)),indent=2)+'\n')
(OUT/'README.md').write_text('''# F cleanup, 2026-11-07

Operator CLEANUP NOW: publish evidence first, remove completed raw outputs and
private duplicate builds, preserve shared incremental caches. `retention.json`
records every raw file's SHA256/size and retained compressed counterpart.
No invalid native body was executed during cleanup. No new compilation occurred.

Latest SP candidate:1077forms1102848realCPU/C cases ZERO;40sequences40960CPU/C/
canonical cases ZERO;25original+4high32 negatives all reject;6legitimate bound
executions return2. These remain diagnostic/private-candidate observations.
v3c complete check ends2 at MULX raw-cell oracle1610failures; its full log is
published in differential/x86-sp-native64-candidate/. Runtime is not promoted.

The candidate runtime patch and currentHEAD integration source pins retain the
unfinished repair. Old candidates/recipes/checkpoints are archival tar inputs,
not active alternative implementations. The old application-negative preparation
sources are retained without running them; they use the previous proof-upload
path and do not establish the new trusted-service path's safety.

Archives preserve the completed broad CPU harness, old v2 exact source, existing
ABI diagnostic tools, and historical lane recipes/notes. `remove-plan.json`
identifies only F result raws/builds/lane files. Deletion follows successful push
and a live process/open-file check. Shared vendor/build, native_link/target,
formal/.lake, ccache and Docker cache remain untouched. CPU matrix completed;
no F guest/compiler is intentionally stopped. Continue priority4 SP correctness
using the current source and shared incremental caches, then new reference-family
replay and negative-suite checks. The current failure needs an independent native
word interpretation in the existing MULX route expectation, not an ISA change.
''')
for p in OUT.rglob('*'):
 if p.is_file():keep.add(str(p.relative_to(R)))
# GitHub has a per-file cap: retain lossless byte-part files if a gzip exceeds it.
for rel in list(keep):
 p=R/rel
 if p.stat().st_size<=95*1024*1024:continue
 assert p.suffix=='.gz',rel
 parts=[]
 with p.open('rb') as f:
  for n in range(10000):
   b=f.read(64*1024*1024)
   if not b:break
   part=Path(str(p)+f'.part{n:03d}');part.write_bytes(b);parts.append(str(part.relative_to(R)));keep.add(str(part.relative_to(R)))
 keep.remove(rel);p.unlink();manifest=Path(str(p)+'.parts.json');manifest.write_text(json.dumps(dict(parts=parts,reconstruct='concatenate listed parts in order, then gunzip'),indent=2)+'\n');keep.add(str(manifest.relative_to(R)))
(OUT/'publish-paths.json').write_text(json.dumps(sorted(keep),indent=2)+'\n')
# Include the final path inventory itself.
keep.add(str((OUT/'publish-paths.json').relative_to(R)));(OUT/'publish-paths.json').write_text(json.dumps(sorted(keep),indent=2)+'\n')
print('READY',len(keep),'keep paths;',len(remove),'raw deletions;',len(dirs),'completed private build directories',flush=True)
