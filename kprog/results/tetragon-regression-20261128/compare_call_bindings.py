"""Compare side-band target names in two retained profile captures; no timing claim."""
from pathlib import Path
import collections,hashlib,json,struct
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;PROFILE=ROOT/'kprog/results/cmov-branches-20261126/post-branch-profiles-20261126T145836Z/tetragon-profile';CACHE=PROFILE/'linkcache/native_kernel_link_cache';sha=lambda b:hashlib.sha256(b).hexdigest()
def src(p):
 b=p.read_bytes();return dict(path=str(p.relative_to(ROOT)),bytes=len(b),sha256=sha(b))
symbols=collections.defaultdict(list);origins=[]
for p in [PROFILE/'kallsyms.txt',PROFILE/'kallsyms-bpf-411.78.txt']:
 origins.append(src(p))
 for l in p.read_text().splitlines():
  s=l.split()
  if len(s)>=3 and s[2] not in symbols[int(s[0],16)]:symbols[int(s[0],16)].append(s[2])
current=json.loads((OUT/'current-review.json').read_text());expected=[c['symbols'][0]['name'] for c in current['records'][0]['actual_sideband_calls']];old=[]
for key in ['45ba49203d276b52','5be2ee6f95ee536b']:
 p=CACHE/(key+'.relocs.bin');raw=p.read_bytes();assert len(raw)%16==0;calls=[]
 for at in range(0,len(raw),16):
  off,kind,addr=struct.unpack_from('<IIQ',raw,at);assert kind==1 and addr in symbols;calls.append(dict(offset=off,target=hex(addr),symbols=symbols[addr]))
 plan=next(CACHE.glob(key+'*.link-plan.json'));ps=json.loads(plan.read_text());old.append(dict(cache_key=key,inputs=[src(p),src(CACHE/(key+'.blob.bin')),src(CACHE/(key+'.proof.o')),src(plan)],calls=calls,const_values=ps['const_values'],same_target_name_sequence_as_current=[x['symbols'][0] for x in calls]==expected,scope='11-26 retained canonical link output, not a direct capture of11-23 installed bytes.'))
assert all(x['same_target_name_sequence_as_current'] for x in old)
result=dict(scope='Static target-name comparison; does not establish same called function bytes, frequency, map binding or equal work.',old_profile=str(PROFILE.relative_to(ROOT)),old_profile_image=(PROFILE/'profile-image.txt').read_text().strip(),old_profile_source=(PROFILE/'profile-source.txt').read_text().strip(),old_symbol_origins=origins,current_record=src(OUT/'current-review.json'),old_records=old,current_target_names=expected,interpretation=['Both11-26 and current candidate root entries have7external calls:2k4shared-C,2k8shared-C,2generic bpf_map_lookup_elem and1bpf_get_current_cgroup_id. No added root hash-call site is established.','Both have CONFIG_ITER_NUM1/PARENTS_MAP_ENABLED0. These two scalars do not prove all old/live map values or attach configuration.','The new remapping of direct branches is being replayed separately against exact old proof/plan inputs; no causal result from that pending replay is claimed here.'])
(OUT/'call-binding-comparison.json').write_text(json.dumps(result,indent=2)+'\n');print('Two historical entry records: same7call target-name sequence; branch replay uncollected')
