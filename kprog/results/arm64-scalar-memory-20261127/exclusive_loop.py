"""Pin an exposed LL/SC retry refusal without restricting per-visit choices."""
import gzip
import hashlib
import json
from pathlib import Path
import subprocess
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
run=json.loads((LANE/'scalar-run.json').read_text());parent=Path(run['result']);raw=Path(run['raw']);case=raw/'49';compiled=json.loads((parent/'compile-controller.json').read_text());row=next(x for x in compiled['cases'] if x['index']==49)
now=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();token=now.replace('-','').replace(':','');OUT=HERE/('exclusive-loop-'+token);OUT.mkdir()
source=(case/'after.bpf.c').read_bytes();obj=(case/'after.bpf.o').read_bytes();log=(case/'stock-after.verifier.log').read_bytes();assembly=subprocess.check_output(['llvm-objdump-18','--source','--line-numbers','-d',str(case/'after.bpf.o')])
assert hashlib.sha256(obj).hexdigest()==row['object_sha256'];assert b'infinite loop detected at insn 1426' in log
for text in [b'0x280: ldaxr x9, [x8]',b'0x288: stlxr w10, x9, [x8]',b'0x28c: cbnz w10, 280']:assert text in source
assert b'if r4 != 0x0 goto -0x9' in assembly
files={'after.bpf.c':source,'after.bpf.o':obj,'stock-after.verifier.log':log,'after.disassembly':assembly};evidence={}
for name,data in files.items():
 packed=gzip.compress(data,mtime=0);(OUT/(name+'.gz')).write_bytes(packed);assert gzip.decompress(packed)==data;evidence[name]=dict(bytes=len(data),sha256=hashlib.sha256(data).hexdigest(),gzip_sha256=hashlib.sha256(packed).hexdigest())
paths=['kprog/arm64/arm64_sim_local_bpf.h','kinsn/module/include/native_lab_input.h','kprog/stock-path/include/stock_native_input.h','kprog/stock-path/bin/clang'];snippets=[];headers={}
for path in paths:
 data=(ROOT/path).read_bytes();headers[path]=hashlib.sha256(data).hexdigest();text=data.decode();lines=text.splitlines()
 if path.endswith('arm64_sim_local_bpf.h'):
  a=next(i for i,l in enumerate(lines) if l.startswith('/* The native input ABI supplies'));b=next(i for i,l in enumerate(lines[a:],a) if l.startswith('/* The dispatcher and direct path'));snippets.append(path+':'+str(a+1)+'\n'+'\n'.join(lines[a:b]))
 else:snippets.append(path+'\n'+text)
(OUT/'source-trace.txt').write_text('\n\n'.join(snippets)+'\n')
record=dict(utc=now,app='tetragon/observer',request=1,input_index=49,symbol=row['symbol'],original_family='scalar memory access',after_family='infinite loop',after_kernel_errno=22,failed_B_instruction=1426,evidence_files=evidence,source_sha256=headers,native_retry=dict(load_exclusive=640,store_exclusive=648,conditional_retry=652,target=640),source_steps=['0x280 LDAXR becomes ARM64_OP_LOAD','0x284 increments loaded value','0x288 STLXR requests explicit Boolean exclusive failure at site648; failure skips memory write and writes Wstatus1','0x28c CBNZ on Wstatus returns to0x280'],b_retry='B1418 reads private choice &1; B1420 branches back on failure; B1425 reads load-fault choice; B1426/B1428 reach the retry body. No monotonically bounded loop counter exists.',reason='The stock wrapper force-includes stock_native_input.h, translating private exclusive failure into volatile kprog_unspecified_input[0]&1. Each dynamic visit remains unknown to the verifier, so it can fail indefinitely. This is a native exclusive retry, not an unused choice that may be deleted.',proof_boundary='native_lab_input.h ABI2 and current Clight path require an explicit0/1 choice per dynamic visit. No constant success, fairness assumption, arbitrary retry cap, map-freeze-to-zero or per-program selection is justified. Any common atomic-loop lowering needs a semantics-preserving argument covering observed effects and failure visits; this report does not implement or prove it.',scope='One actual source/B/verifier refusal; no extrapolated family count. Read-only diagnosis during full145paired sweep, not a new compiler/guest/test or successful native install. Current scalar probe fixes one refusal then exposes this next one.',controller_status=0)
(OUT/'analysis.json').write_text(json.dumps(record,indent=2)+'\n')
(OUT/'README.md').write_text('''# Scalar repair exposes an exclusive retry loop

Tetragon request1 `event_exit_disassociate_ctty` (captured input49) now passes the original scalar load but is refused at B1426 for an infinite loop. The preserved C and source-annotated B disassembly identify the native operation: LDAXR at0x280, increment at0x284, STLXR at0x288, CBNZ retry at0x28c.

The exclusive-store body requests an explicit Boolean failure outcome on every dynamic visit. Failure skips the write and sets Wstatus1, which branches back to the load. The stock compiler's forced header represents the choice as a volatile ordinary-map read masked with1. The verifier may therefore follow a path that fails every time; there is no bounded progress counter. This is an actual native exclusive retry, rather than an unused private input.

The ABI2 header and Clight path deliberately retain per-visit choices and reject invalid values. A repair must preserve those semantics. This diagnosis does not force success, constrain choices, add a retry bound, or claim a proof for atomic-loop replacement. A common atomic-loop lowering would need to justify its relation to the original failed/successful visits and effects. FORMAL is notified of this boundary; its current proof files are untouched.

Four compressed evidence files preserve the exact source, compiled B, full verifier log and disassembly, with SHA256s in analysis.json. source-trace.txt includes the actual local exclusive-store body, private input ABI, stock choice replacement and forced-include compiler wrapper. The B hash matches the completed145-input compile receipt. No compiler, guest, kernel, flags, framework, current sweep input or native install changed. The full sweep and queued Tetragon stage2 remain the sources of complete cross-app outcomes; this single input establishes no family count or broader acceptance.
''')
(LANE/'exclusive-loop-diagnosis.json').write_text(json.dumps(dict(result=str(OUT)),indent=2)+'\n');print(json.dumps(dict(result=str(OUT),object_sha256=evidence['after.bpf.o']['sha256'],evidence_files=len(files))),flush=True)
