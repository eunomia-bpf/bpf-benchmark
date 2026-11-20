"""Retain the four actual profiles, counters and current component receipts."""
import json
from pathlib import Path
import tarfile

root=Path('/workspaces/repository');here=Path(__file__).resolve().parent
base=Path('/workspaces/kprog-raw/perf/runtime-profile-20261120')
captures={'otel':base/'otel-20261120T003319Z',
          **{name:base/'remaining-20261120T003842Z'/name for name in ('bcc','katran','cilium')}}
rows=[]
for name,raw in captures.items():
    costs=json.loads((raw/'costs.json').read_text());run=Path(costs['run'])
    row=dict(app=name,raw=str(raw),run=str(run),collector_exit=int((raw/'exit-code').read_text()),
             phases=costs['phases'])
    rows.append(row)
    with tarfile.open(here/(name+'-evidence.tar.gz'),'w:gz') as archive:
        archive.add(raw,arcname='profile')
        archive.add(run/'details',arcname='corpus/details')
        archive.add(run/'metadata.json',arcname='corpus/metadata.json')
result=dict(image_source_revision='8f6ff5891',cpus='20-23',vcpus=4,memory='32G',
    event='cycles:G',frequency=199,samples=1,workload_seconds=60,requests=rows,
    scope='Diagnostic profiles. Program text includes inline helpers. External guest roots are not caller-owned costs. Tail-called program counters may be zero while their parent holds inclusive runtime. Cilium endpoint programs with different constants remain eBPF. No optimized-image measurement yet.')
(here/'profile-result.json').write_text(json.dumps(result,indent=2)+'\n')
receipts={'volatile_before':'private-gcc-before-20261120T003842Z',
          'volatile_after':'volatile-after-20261120T003933Z',
          'copy':'user-source-fixed-20261120T004942Z','link':'source-links-fixed-20261120T005500Z',
          'baseline_recovery_failure':'volatile-before-20261120T003528Z',
          'branch_probe':'branches-20261120T005341Z'}
with tarfile.open(here/'component-evidence.tar.gz','w:gz') as archive:
    for name,directory in receipts.items():archive.add(base/directory,arcname=name)
(here/'component-result.json').write_text(json.dumps(dict(raw={n:str(base/d) for n,d in receipts.items()},
    private_cases=1368,private_volatile_ir_before=24,private_volatile_ir_after=0,
    released_address_observations=48,ordinary_read_controls=8,physical_fault_controls=8,
    source_copy_cases=96,source_u32_lengths=2,source_compat_control=1,proof_and_kernel_links=4,
    baseline_recovery_make_exit=2,
    scope='Host UBSan/value/physical-fault checks and real-kernel-address linking, not kernel execution or speed. Baseline recovery_host aborted before changes. LBR probe captured host userspace branches on guest-root samples; no guest caller attribution is inferred.'),indent=2)+'\n')
print([(r['app'],r['collector_exit']) for r in rows],flush=True)
