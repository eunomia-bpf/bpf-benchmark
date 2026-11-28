from pathlib import Path
import collections,hashlib,json,re,subprocess,tarfile
root=Path.cwd();out=root/'kprog/results/native-ebpf-alignment-20261128/arithmetic/shifts/otel-vm';prep=json.loads((out/'preparation.json').read_text());d=json.loads((out/'controller.json').read_text());sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
assert d['controller_status']==0 and len(d['objects'])==len(d['commands'])==2 and all(c['exit']==0 for c in d['commands'])
for n,h in prep['source_sha256'].items():assert sha(root/n)==h,n
for o in prep['objects']:assert sha(root/o['object'])==o['sha256']
calls=[];site_counts=collections.Counter()
for o in d['objects']:
 assert sha(out/o['file'])==o['sha256'];a=json.loads((out/o['file']).read_text())
 for s in a['original_review_sites']:site_counts[re.sub(r'\.\d+$','',s['function'])]+=1
 for name,rows in a['target_functions'].items():
  text='\n'.join(x['ir'] for x in rows)
  if name.startswith('pid_event_ratelimit'):assert re.search(r'and i64 %\d+, 15',text) and re.search(r'shl i64 100000000,',text)
  if name=='dotnet_find_code_start':assert re.search(r'urem i64 %\d+, 8',text) and re.search(r'udiv i64 %\d+, 32',text)
 for c in a['direct_callers']:
  if 'unwinder_argument' in c:calls.append(dict(architecture=a['architecture'],**c))
assert sum(site_counts.values())==42
constant=[c for c in calls if c['unwinder_integer'] is not None];dynamic=[c for c in calls if c['unwinder_integer'] is None];assert len(constant)==10 and len(dynamic)==14 and {c['unwinder_integer'] for c in constant}=={3,4,5}
producers=[]
repo=root/'vendor/repos/opentelemetry-ebpf-profiler'
for p in sorted((repo/'interpreter').rglob('*.go')):
 if p.name.endswith('_test.go'):continue
 text=p.read_text()
 for m in re.finditer(r'\.UpdateInterpreterOffsets\(support\.(ProgUnwind\w+)',text):
  line=text[:m.start()].count('\n')+1;ls=text.splitlines();producers.append(dict(path=str(p.relative_to(root)),sha256=sha(p),line=line,index_constant=m[1],excerpt='\n'.join(f'{i+1}: {ls[i]}' for i in range(max(0,line-2),min(len(ls),line+3)))))
assert len(producers)==5 and {p['index_constant'] for p in producers}=={'ProgUnwindPerl','ProgUnwindPython','ProgUnwindPHP','ProgUnwindRuby','ProgUnwindV8'}
source=[]
for n,a,b in [('support/types.go',30,42),('processmanager/ebpfapi/ebpf.go',68,86),('processmanager/ebpf/ebpf.go',122,135),('interpreter/hotspot/instance.go',645,654),('interpreter/hotspot/instance.go',754,770),('interpreter/nodev8/v8.go',290,298),('interpreter/nodev8/v8.go',1878,1900),('interpreter/nodev8/v8.go',1794,1803),('interpreter/nodev8/v8.go',2041,2052)]:
 p=repo/n;ls=p.read_text().splitlines();source.append(dict(path=str(p.relative_to(root)),sha256=sha(p),first_line=a,last_line=b,excerpt='\n'.join(f'{i+1}: {ls[i]}' for i in range(a-1,b))))
copy=[]
for n in ['tracemgmt.h','dotnet_tracer.ebpf.c','go_labels.ebpf.c','hotspot_tracer.ebpf.c','v8_tracer.ebpf.c']:
 a=root/'vendor/bpf/otel/support/ebpf'/n;b=repo/'support/ebpf'/n;copy.append(dict(native_copy=str(a.relative_to(root)),native_sha256=sha(a),frozen_source=str(b.relative_to(root)),frozen_sha256=sha(b),whole_file_equal=a.read_bytes()==b.read_bytes()))
assert all(x['whole_file_equal'] for x in copy if not x['native_copy'].endswith('/tracemgmt.h'))
a=(root/'vendor/bpf/otel/support/ebpf/tracemgmt.h').read_text().splitlines();b=(repo/'support/ebpf/tracemgmt.h').read_text().splitlines();assert a[:755]==b[:755]
for obs in prep['artifact_kind_observations']:
 p=root/obs['path'];assert sha(p)==obs['sha256'];rel=str(p.relative_to(repo));assert subprocess.check_output(['git','-C',str(repo),'ls-files','--',rel],text=True)=='';assert subprocess.run(['git','-C',str(repo),'check-ignore','-q',rel]).returncode==0;assert obs['classification']=='LLVMbitcode'
files=[out/x['file'] for x in d['objects']]+[out/x['stderr'] for x in d['commands']]+[out/'controller.json'];assert len(files)==5;index=[dict(member=p.name,bytes=p.stat().st_size,sha256=sha(p)) for p in sorted(files)];archive=out/'otel-shift-records.tar.zst';assert not archive.exists();args=['tar','--zstd','-cf',str(archive),'-C',str(out),*[x['member'] for x in index]];subprocess.run(args,check=True)
p=subprocess.Popen(['zstd','-d','-c',str(archive)],stdout=subprocess.PIPE);wanted={x['member']:x for x in index};seen=set()
with tarfile.open(fileobj=p.stdout,mode='r|') as tf:
 for m in tf:
  assert m.isfile() and m.name in wanted and m.name not in seen;data=tf.extractfile(m).read();x=wanted[m.name];assert len(data)==x['bytes'] and hashlib.sha256(data).hexdigest()==x['sha256'];seen.add(m.name)
p.stdout.close();assert p.wait()==0 and seen==set(wanted)
arc=dict(path=archive.name,bytes=archive.stat().st_size,sha256=sha(archive),raw_bytes=sum(x['bytes'] for x in index),members=index,archive_command=args,all_members_verified=True,raw_copies_preserved_at_publication=True);(out/'otel-shift-archive.json').write_text(json.dumps(arc,indent=2)+'\n')
now=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();review=dict(reviewed_utc=now,controller_pid=d['pid'],started_utc=d['started_utc'],ended_utc=d['ended_utc'],controller_status=0,native_objects=2,mem2reg_commands=2,all_commands_exit_zero=True,original_review_sites=42,sites_by_function=dict(site_counts),classification=[dict(sites=12,kind='local-amount-bound',evidence='Rate-limit attempt comes from token&15, then trunc/zext; all12shift counts0..15 are below64.'),dict(sites=2,kind='local-amount-bound',evidence='Dotnet unsigned divide32/remainder8 gives0..7, multiply4 then28-minus gives0..28, below32.'),dict(sites=6,kind='recorded-literal-callers',evidence='Ten recorded mark-done calls across both modules pass only3/4/5;6helper shift sites below32.'),dict(sites=14,kind='standard-source-producer-bound-not-live-map-proof',evidence='is_done reads uint16 OffsetRange.Program_index from interpreter_offsets. Five standard production interpreter callers pass named constants3..7. API type itself is uint16 and doesnot validate index range; arbitrary map updates/live values remain unproved.'),dict(sites=2,kind='unresolved-process-input-range',evidence='Go labels reads an unsigned-byte hmap bucket log from process memory; native consumer shifts i32 then truncates to i8. Comment about16buckets and loop cap16 do not establish input<32. Admissible actual process bytes and corresponding installed traditional BPF behavior remain to join.'),dict(sites=4,kind='unresolved-VM-input-range',evidence='Hotspot reads uint32 _log2_segment_size from process heap then stores uint8 Segment_shift; reviewed path doesnot establish<64. Actual VM invariant/live bytes and matching BPF behavior remain unproved.'),dict(sites=2,kind='unresolved-VM-input-range',evidence='V8 FieldShift is uint8 loaded from v8dbg metadata and copied to process data, with a version fallback0. Reviewed path doesnot establish every live value<32. VM metadata validity/live bytes and matching BPF behavior remain unproved.')],unwinder_caller_records=calls,standard_offset_producers=producers,source_anchors=source,source_copy_comparisons=copy,tracemgmt_difference='Known MICRO_NATIVE sampled-context adapter at oldsource755+, outside all reviewed shift helpers; first755lines equal. No source edit thisturn.',artifact_kind_observations=prep['artifact_kind_observations'],artifact_diagnostic='llvm-objdump on current ignored go_labels.o returned1 because bytesare LLVMbitcode BCc0de, not an ELF. This isnot an installed-BPF or broken-loader result. No rebuild or app mutation used to repair the diagnostic assumption.',bounded_local_or_literal_sites=20,standard_producer_only_sites=14,unresolved_input_range_sites=8,input_source_sha256_reverified=prep['source_sha256'],native_object_sha256_reverified={x['object']:x['sha256'] for x in prep['objects']},archive={k:v for k,v in arc.items() if k not in ['members','archive_command']},conclusion='No new confirmed native/eBPF semantic mismatch. Bounds under local/literal or standard producer assumptions are not arbitrary-map invariants, VM path exercise or full source-C/kernel/native equivalence. Keep8input-dependent sites explicit; no speculative common guard/mask or frozen app change.',next='Tracee index controls and remaining probe/helper/attach/JIT dimensions can proceed independently. Revisit these8sites only with actual VM/process admissibility and traditional BPF artifact/installed evidence. No forced VM/workload, new benchmark setting or fixed-OTel activation.')
assert sum(x['sites'] for x in review['classification'])==42
(out/'collection-review.json').write_text(json.dumps(review,indent=2)+'\n')
(out/'README.md').write_text('''# OTel shift consumers and source producers

Follow newest resume COORDINATOR2026-11-28T07:17Z and frozen application2689a430. make inspect reads the two existing native ELF embedded frontend modules with mem2reg only onCPU16 under48GiB; metadata staysCPU19 under48GiB. Both short commands returned0, controller1433911 ended2026-11-28T11:01:29Z. No new native/P build, guest, image/root/app activation, flags or benchmark change.

The42prior review sites separate into20locally/literal bounded sites (12rate-limit attempts from token&15,2dotnet nibble positions0..28,6mark-done sites with recorded literal3/4/5 callers);14is-done sites read uint16 program indices from interpreter_offsets. Five standard interpreter producers supply constants3..7, but the generic API takes uint16 without an index-range check, so this is source-producer evidence rather than a live-map or arbitrary-update invariant. Exact call/SSA records and source excerpts are retained.

Eight input-dependent sites remain explicit:2Go-label bucket-log reads,4Hotspot segment shifts and2V8 code-kind shifts. Go's16-bucket comment/loop bound doesnot establish the raw input<32; Hotspot converts a remote heap uint32 to uint8 without a reviewed<64 proof; V8 copies uint8 debugger metadata with fallback0, without a reviewed general<32 proof. Neither an unknown byte range nor a sourceC/LLVM undefined edge alone proves a native/eBPF mismatch. Actual admissible VM/process inputs and matching traditional BPF/installed operations are still required. No speculative mask, guard or app fix is added, and VM features/workloads are not forced.

Current ignored support/ebpf/go_labels .o files in the app checkout contain LLVMbitcode, not ELF. The initial objdump1 diagnostic is an artifact-kind mismatch, not proof of a broken app or installed BPF. Four reviewed consumer files are byteequal to frozen source; tracemgmt differs only in the existing sampled-context native adapter after line755, outside these shift helpers. The fixed-app proposal remains held and2689is unchanged.

collection-review.json records these distinctions, exact source hashes, current artifact kinds and10unwinder literal/14map-derived caller records. otel-shift-records.tar.zst contains all5original native inspection/controller/stderr files; every member was decompressed and SHA/size compared with originals before publication. Use the archive/index for original records after verified duplicate cleanup. Continue Tracee controls and remaining probe/helper/attach/JIT alignment; revisit unknown inputs when actual admissibility/BPF evidence is available, without rerunning the114-object census.
''')
line=f'- LANE PERF {now}: Completed short OTel consumer/source audit (2mem2regcmd0,controller1433911 ended11:01:29Z), no detachedjob/guest.42prior sites=20local/literal bounds(12attemptmask15/2dotnet0..28/6markdone3-4-5),14is_done mapindices boundedONLYunder5standardproducerconstants3..7 (APIuint16 itselfunbounded),8Go-label/Hotspot/V8inputranges unresolved. Native/source/actualVM/BPFartifact gaps explicit; currentignored .o areLLVMbitcode, objdump1notbrokenapp proof.5rawrecords archived/allmemberSHAverified; no speculativeguard/mask/appchange. Frozen2689HOLD/x86owner/FORMALCPU17/STOP preserved; nextTraceecontrols independent, noforcedVM/workload.\n'
for p in [root/'COORDINATION.md',Path('/workspaces/.agent-state/kprog-lanes/COORDINATION.md')]:
 with p.open('a') as f:f.write('\n'+line)
print(json.dumps({k:review[k] for k in ['reviewed_utc','original_review_sites','bounded_local_or_literal_sites','standard_producer_only_sites','unresolved_input_range_sites','archive']},indent=2))
