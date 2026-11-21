"""Preserve terminal component/guest evidence before rebuildable-output cleanup."""
from pathlib import Path
import collections,csv,gzip,hashlib,io,json,tarfile
R=Path('/workspaces/repository');S=Path('/var/tmp/kprog-tmp/S2/review-20261121');D=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads((S/p).read_text())
assert (S/'safety-driver.exit').exists()
guest=read('guest-summary.json');safety=read('safety-summary.json');outcomes=read('safety/outcomes.json')
assert len(outcomes)==34
for name in ['guest-summary.json','safety-summary.json','generator-inventory.json','generator-current.json','micro-compilation.json','hosts-current.json','metadata-final.json','code-publication.json','context-publication.json','replay-publication.json']:
    (D/name).write_bytes((S/name).read_bytes())
for name in ['hosts-current.log','hosts-diagnostics.json','generator-regression.log','safety-build.log','safety.log','safety-qemu.log','guest.log','qemu.log','micro.log']:
    (D/(name+'.gz')).write_bytes(gzip.compress((S/name).read_bytes(),mtime=0))
summary=dict(
    production_commits=[read('code-publication.json')['commit'],read('context-publication.json')['commit']],
    replay_commit=read('replay-publication.json')['commit'],
    host_oracles=dict(retained_compile_run_pairs=77,retired_source_paths=40,protected_read_states=6144,followup_checks=5720,followup_discrepancies=0),
    generator=dict(accepted_shapes=read('generator-current.json')['forms'],named_vector_shape_exclusions=read('generator-current.json')['excluded_forms'],broader_named_form_exclusions=len(read('generator-inventory.json')['named_exclusions'])),
    micro_compilation=dict(total=len(read('micro-compilation.json')),exit0=sum(r['exit']==0 for r in read('micro-compilation.json'))),
    guest=dict(total=len(guest['forms']),passed=sum(r['exit']==0 for r in guest['forms']),generation_exclusions=[r['symbol'] for r in guest['forms'] if r['exit']],driver_exit=int((S/'guest-driver.exit').read_text())),
    safety=dict(total=len(outcomes),stages=dict(collections.Counter(r['stage'] for r in outcomes)),driver_exit=int((S/'safety-driver.exit').read_text()),accepted_load_only=[r['name'] for r in outcomes if r['stage']=='accepted_load_only'],pipeline_outcomes=[r['name'] for r in outcomes if r['stage']=='pipeline_rejected_unclassified'],negative_native_executions=0),
    stable_guest_hashes=guest['hashes_before']==guest['hashes_after'],
    stable_safety_hashes=safety['hashes_before']==safety['hashes_after'],
    universal_composition='partial-C-model-component; current universal ISA/O2/compiler/physical recovery correspondence remains with formal/V')
(D/'final-summary.json').write_text(json.dumps(summary,indent=2)+'\n')
skip_dirs={'cargo','loader','module','fixture-module','hosts','micro-objects','negative-objects','sites'}
skip_files={'probe','safety-probe','read-followup','read-recovery','vmlinux.h'}
files=[];omitted=[]
for p in sorted(S.rglob('*')):
    if not p.is_file():continue
    rel=p.relative_to(S)
    if rel.parts[0] in skip_dirs or rel.name in skip_files or '.index' in rel.name:
        omitted.append(dict(path=str(rel),bytes=p.stat().st_size));continue
    files.append(dict(path=str(rel),bytes=p.stat().st_size,sha256=sha(p)))
archive=D/'terminal-raw.tar.gz'
with tarfile.open(archive,'w:gz') as t:
    for row in files:t.add(S/row['path'],arcname=row['path'],recursive=False)
with tarfile.open(archive) as t:
    members={m.name:m for m in t.getmembers() if m.isfile()}
    assert set(members)=={r['path'] for r in files}
    for row in files:
        assert hashlib.sha256(t.extractfile(members[row['path']]).read()).hexdigest()==row['sha256']
manifest=dict(archive=archive.name,archive_sha256=sha(archive),archive_bytes=archive.stat().st_size,files=files,rebuildable_outputs=omitted)
(D/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
# Row text is a handoff; formal/V owns coverage.tsv.
with (R/'kprog/results/kprog_arm64_read_recovery_20261109/coverage-row.tsv').open() as f:
    rows=list(csv.DictReader(f,delimiter='\t'));row=rows[0];fields=list(row)
row.update(scope='Current S2 H1/M1/M2/L1/L3 component replay; vector native generation follows deliberate scalar-only policy. Protected recovery holds in tested model states and ten actual fault fixtures; named producer exclusions and safety findings retain separate outcomes.',catalog_sha256=sha(R/'kprog/arm64/arm64_sim_local_bpf.h')+';'+sha(R/'kprog/arm64/micro-prog/generate_micro_sim_proofs.py'),o4_preservation_status='partial-C-model-component',o4_evidence='kprog/results/arm64-recovery-review-20261121/final-summary.json;kprog/results/arm64-recovery-review-20261121/manifest.json',o4_completion='5720followup+6144recovery states;77retained oracle pairs;156generator shapes+24SIMD exclusions;29+1compile;10nativefault forms+4SIMD exclusions;34safety outcomes with accepted_load_only/pipeline categories. Universal proof remains formal-owned.',o4_publication=summary['production_commits'][0],machine_reference_status='selected-current-base-observations',machine_reference_evidence='kprog/results/arm64-recovery-review-20261121/guest-summary.json')
with (D/'coverage-proposal.tsv').open('w') as f:
    w=csv.DictWriter(f,fieldnames=fields,delimiter='\t',lineterminator='\n');w.writeheader();w.writerow(row)
print(json.dumps(summary,indent=2));print('archive',archive.stat().st_size,'bytes',len(files),'files; every member hash reread')
