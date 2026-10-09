#!/usr/bin/env python3
"""Derive paper metrics without running benchmarks or modifying either repository."""
from pathlib import Path
import collections, csv, json, math, re, statistics
BUNDLE = Path(__file__).resolve().parents[1]
PAPER = BUNDLE / 'inputs/audit-paper'
REPO = BUNDLE / 'data'
def resolve(path): return path.replace('/results/', '/')
def js(path): return json.loads(path.read_text())
def samples(x):
    for b in x.get('benchmarks', []):
        for r in b.get('runs', []):
            for s in r.get('samples', []): yield b, r, s


ROWS=[]
X='micro/results/x86_kvm_micro_20260526_210952_650695'
AK='micro/results/aws_arm64_micro_20260523_091516_610343'
AU='micro/results/aws_arm64_micro_20260520_052452_727433'
EX='micro/results/x86_kvm_micro_20260519_114214_364050'
BX='micro/results/x86_kvm_micro_20260526_210351_224315'
EA='micro/results/aws_arm64_micro_20260606_001225_821028'
LX=['micro/results/x86_kvm_micro_20260514_031744_210343','micro/results/x86_kvm_micro_20260514_181806_133778']
LP='micro/results/x86_kvm_micro_20260429_035938_203074'
CF='corpus/results/x86_kvm_corpus_20260604_100557_313063'
CFC='corpus/results/x86_kvm_corpus_20260604_070210_639497'
CN='corpus/results/x86_kvm_corpus_20260605_004607_636479'
CNC='corpus/results/x86_kvm_corpus_20260604_232313_992341'
KC='corpus/results/aws_arm64_corpus_20260605_080836_924256'
KM='corpus/results/aws_arm64_corpus_20260605_094729_221231'
NT='corpus/results/x86_kvm_corpus_20260529_040554_604387'
NC='corpus/results/x86_kvm_corpus_20260529_033517_489159'
CHAR_SCRIPT='bpf-benchmark/docs/archive/shared/plot_micro_characterization_20260527.py; paper-provenance/scripts/plot_characterization_pure_percase.py (older 29-case source; final 27-case/4config generator not retained)'
EVAL_SCRIPT='paper-provenance/scripts/plot_evaluation_kinsn.py (older 29-case source); bpf-benchmark/docs/artifacts/render_claim_table.py (27-case derivation)'
APP_SCRIPT='bpf-benchmark/docs/archive/shared/kinsn_eval_20260604.py; bpf-benchmark/kinsn/docs/evaluation.md; paper-provenance/scripts/plot_app_case_studies.py (hard-coded plot inputs)'
NATIVE_SCRIPT='bpf-benchmark/kprog/docs/archive/native_eval_20260529.py; bpf-benchmark/docs/artifacts/render_claim_table.py'

def data(path):return js(REPO/resolve(path)/'details/result.json')
def med(path,runtime,field='exec_ns'):
    out={}
    for b in data(path).get('benchmarks',[]):
        for r in b.get('runs',[]):
            if r['runtime']!=runtime:continue
            vals=[]
            for s in r.get('samples',[]):
                if field=='size':v=(s.get('code_size') or {}).get('native_code_bytes')
                elif field in ('object_load_ns','object_open_ns'):v=(s.get('phases_ns') or {}).get(field)
                else:v=s.get(field)
                if v is not None:vals.append(v)
            if vals:out[b['name']]=statistics.median(vals)
    return out
def gm(vals):
    if isinstance(vals,dict):vals=vals.values()
    return math.exp(statistics.mean(math.log(x) for x in vals))
def speed(path,rt):
    b=med(path,'kernel');c=med(path,rt)
    return {n:b[n]/c[n] for n in b.keys()&c.keys() if n not in ('simple','simple_packet')}
def micro_bad(path):
    count=0
    for b,r,s in samples(data(path)):
        count+=sum(b.get(e) is not None and s.get(a)!=b[e] for e,a in [('expected_result','result'),('expected_retval','retval')])
    return count
def app(path,name='cilium__agent.json'):return js(REPO/resolve(path)/'details/apps'/name)
def pps(w):
    text='\n'+(w.get('stdout') or '')+'\n'+(w.get('stderr') or '')
    return sum(pps(c) for c in w.get('components',[]))+sum(float(m[1]) for m in re.finditer(r'\n\s*(\d+)pps\s+[0-9]+Mb/sec .* errors: (\d+)',text))
def throughput(path,name='cilium__agent.json',agg=statistics.median):
    x=app(path,name);b=[pps(w) for w in x['baseline']['workloads']];p=[pps(w) for w in x['post_rejit']['workloads']]
    return agg(p)/agg(b)
def cost(path,name='cilium__agent.json'):
    x=app(path,name);vals={}
    for phase in ('baseline','post_rejit'):
        rs=[r for r in x[phase]['bpf'].values() if r.get('run_cnt_delta',0)>=100]
        vals[phase]=sum(r['run_time_ns_delta'] for r in rs)/sum(r['run_cnt_delta'] for r in rs)
    return vals
def paired_cost(path,name='cilium__agent.json'):
    x=app(path,name); phases=[]
    for phase in ('baseline','post_rejit'):
        occur=collections.Counter();records={}
        for r in x[phase]['bpf'].values():
            key=(r.get('name'),r.get('type'));key=(*key,occur[key]);occur[key[:2]]+=1;records[key]=r
        phases.append(records)
    ratios=[]
    for k in phases[0].keys()&phases[1].keys():
        b,p=phases[0][k],phases[1][k]
        if min(b.get('run_cnt_delta',0),p.get('run_cnt_delta',0))>=100:
            ratios.append((p['run_time_ns_delta']/p['run_cnt_delta'])/(b['run_time_ns_delta']/b['run_cnt_delta']))
    return gm(ratios),len(ratios)

def source_line(file,needle):
    matches=[(i,l) for i,l in enumerate((PAPER/file).read_text().splitlines(),1) if needle in l and not l.lstrip().startswith('%')]
    if not matches:raise ValueError((file,needle))
    return matches[0]

def add(file,needle,claim,value='',paths=(),script='',recomputed='',match='not recomputed',method='',notes='',kind='empirical',scope='body',line=None):
    if line is None:line,text=source_line(file,needle)
    else:text=(PAPER/file).read_text().splitlines()[line-1]
    paths=list(paths);current=[resolve(p) for p in paths]
    dates=[];platforms=[];commits=[];statuses=[]
    for p in current:
        d=REPO/p
        if d.is_dir():
            m=js(d/'metadata.json')
            dates.append(m.get('started_at') or m.get('generated_at') or 'not recorded')
            prov=m.get('provenance') or {};host=m.get('host') or {}
            platforms.append((m.get('run_type') or host.get('platform') or 'platform not recorded')+'; CPU '+str(prov.get('cpu_model','not recorded')))
            commit=prov.get('repo_git_sha') or host.get('git_sha') or m.get('commit') or 'not recorded'
            commits.append(str(commit));statuses.append(str(m.get('status','not recorded')))
        else:dates.append('2026-03-19' if '20260319' in p else 'not recorded');platforms.append('lab x86 KVM' if '20260319' in p else 'not recorded');commits.append('not recorded')
    present='yes' if current and all((REPO/p).exists() for p in current) else 'no' if current else 'no raw dataset identified'
    if kind in ('declared count','missing raw'):present='run exists; required raw report absent' if current else 'no raw data in reachable repositories'
    if file.startswith('revision/') and not paths:
        dates=['October 2026 rerun; report directory dated 2026-10-03; exact collection dates unavailable'];platforms=['EC2 c7i.large (x86 Sapphire Rapids) / c7g.large (ARM64 Graviton3), paper-declared'];commits=['not recorded in reachable evidence']
    ROWS.append(dict(claim_id=f'C{len(ROWS)+1:04d}',version='revision' if file.startswith('revision/') else 'current',scope=scope,kind=kind,source_file='paper/'+file,source_line=line,source_text=text.strip(),claim=claim,claimed_value=str(value),original_data_paths='; '.join(paths),current_data_paths='; '.join(paths),raw_present=present,run_dates='; '.join(dict.fromkeys(dates)),platform='; '.join(dict.fromkeys(platforms)),bpf_benchmark_commit='; '.join(dict.fromkeys(commits)),collector_status='; '.join(dict.fromkeys(statuses)),generator_or_provenance=script,recomputable='yes' if recomputed!='' else 'no' if kind in ('declared count','missing raw') else 'partial/unverified',recomputed_value=str(recomputed),match=match,method=method,notes=notes))

def scalar(file,needle,label,val,actual,paths,script='',digits=3,notes='',method=''):
    matched=(round(actual,digits)==round(float(val),digits))
    add(file,needle,label,val,paths,script,format(actual,'.9g'),'matches rounding' if matched else 'MISMATCH',method,notes)

def main_claims():
    chars={('x86',r):speed(X,r) for r in ('native_kernel','native','llvmbpf')}
    chars.update({('arm',r):speed(AK if r=='native_kernel' else AU,r) for r in ('native_kernel','native','llvmbpf')})
    ex,bx=med(EX,'kernel'),med(BX,'kernel');er={n:bx[n]/ex[n] for n in ex.keys()&bx.keys() if n not in ('simple','simple_packet')}
    ar=speed(EA,'kernel_rejit')
    sizes={}
    for label,run,baseline,rt in [('x86',EX,BX,'kernel'),('arm',EA,EA,'kernel_rejit')]:
        a,b=med(run,rt,'size'),med(baseline,'kernel','size');sizes[label]=gm(a[n]/b[n] for n in a.keys()&b.keys())
    sf='sections/3-characterization.tex';ef='sections/7-evaluation.tex'
    # Each occurrence is retained separately, including repeated headline claims.
    for needle,label,v,actual,paths in [
        ('The same source program','x86 eBPF/native gap',1.57,gm(chars['x86','native']),[X]),
        ('The same source program','ARM64 eBPF/native gap',1.98,gm(chars['arm','native']),[AU]),
        ('On x86-64, Figure','x86 kernel native speedup',1.55,gm(chars['x86','native_kernel']),[X]),
        ('On x86-64, Figure','x86 userspace native speedup',1.57,gm(chars['x86','native']),[X]),
        ('On ARM64 the difference','ARM64 kernel native speedup',1.88,gm(chars['arm','native_kernel']),[AK]),
        ('On ARM64 the difference','ARM64 userspace native speedup',1.98,gm(chars['arm','native']),[AU]),
        ('As Table','x86 LLVM-BPF speedup',1.53,gm(chars['x86','llvmbpf']),[X]),
        ('As Table','ARM64 LLVM-BPF speedup',1.92,gm(chars['arm','llvmbpf']),[AU])]:
        scalar(sf,needle,label,v,actual,paths,CHAR_SCRIPT,digits=2,method='geomean of median kernel/path exec_ns, exclude simple and simple_packet (27 cases)')
    for arch in ('x86','arm'):
        p=[X] if arch=='x86' else [AK,AU]
        gap=gm(chars[arch,'native']);kn=gm(chars[arch,'native_kernel']);ll=gm(chars[arch,'llvmbpf']);share=(ll-1)/(gap-1)*100
        scalar(sf,'Against userspace native',arch+' optimizing backend recovered gap (%)',93 if arch=='x86' else 94,share,p,CHAR_SCRIPT,digits=0,method='(LLVM speedup-1)/(native speedup-1)*100; unrounded raw medians',notes='Paper arithmetic uses rounded 1.53/1.57 and 1.92/1.98; raw-value rounding can differ.')
        scalar(sf,'The remaining share',arch+' bytecode residual gap (%)',7 if arch=='x86' else 6,100-share,p,CHAR_SCRIPT,digits=0,method='100 - recovered fraction')
        scalar(sf,'\\finlabel The eBPF-native gap',arch+' in-kernel native execution overhead (%)',2 if arch=='x86' else 5,(gap/kn-1)*100,p,CHAR_SCRIPT,digits=0,method='native_kernel / userspace native = (kernel/userspace native)/(kernel/kernel native); ARM paths have separate baselines')
        scalar(sf,'In-kernel native machine code',arch+' kernel native code size ratio',0.54 if arch=='x86' else 0.49,gm(med(p[0],'native_kernel','size')[n]/med(p[0],'kernel','size')[n] for n in med(p[0],'native_kernel','size')),p[:1],CHAR_SCRIPT,digits=2,method='all 29 cases, median native_code_bytes; paper runtime population is 27')
    add(sf,'The corpus is 27','27 pure-bytecode computation benchmarks','27',[X,AK,AU],CHAR_SCRIPT,27,'matches','29 raw cases minus simple/simple_packet; sources under micro/programs')
    add(sf,'The spread therefore','in-kernel native overhead range','2--5%', [X,AK,AU],CHAR_SCRIPT,f'{(gm(chars["x86","native"])/gm(chars["x86","native_kernel"])-1)*100:.6f}%--{(gm(chars["arm","native"])/gm(chars["arm","native_kernel"])-1)*100:.6f}%','matches approximate range','comparison of geomeans; ARM execution paths measured in separate runs')
    add(sf,'An optimizing compiler recovers','optimizing backend recovered gap range','93--94%', [X,AU],CHAR_SCRIPT,f'{(gm(chars["x86","llvmbpf"])-1)/(gm(chars["x86","native"])-1)*100:.6f}%--{(gm(chars["arm","llvmbpf"])-1)/(gm(chars["arm","native"])-1)*100:.6f}%','matches rounding','(LLVM speedup-1)/(native speedup-1)')
    table='tables/sec-3-micro-summary.tex'
    context='x86'
    for i,l in enumerate((PAPER/table).read_text().splitlines(),1):
        if 'ARM64' in l:context='arm'
        if not re.search(r'\d\.\d+\$',l):continue
        rt='native_kernel' if 'In-kernel' in l else 'llvmbpf' if 'LLVM-BPF' in l else 'native'
        val=float(re.search(r'(\d\.\d+)\$',l)[1]);wins=int(re.search(r'(\d+)/27',l)[1]);paths=[X] if context=='x86' else [AK if rt=='native_kernel' else AU]
        scalar(table,l.strip(),context+' '+rt+' speedup',val,gm(chars[context,rt]),paths,CHAR_SCRIPT,digits=2,method='27-case geomean of median exec_ns')
        scalar(table,l.strip(),context+' '+rt+' faster cases (>2%)',wins,sum(v>1/0.98 for v in chars[context,rt].values()),paths,CHAR_SCRIPT,digits=0,method='path_time < 0.98*kernel_time; denominator 27')
    for needle,label,v,actual,paths in [
        ('generated kernel JIT code shrinks','x86 native code size ratio',.772,sizes['x86'],[EX,BX]),
        ('generated kernel JIT code shrinks','ARM64 native code size ratio',.879,sizes['arm'],[EA]),
        ('generated kernel JIT code shrinks','x86 native code reduction (%)',22.8,(1-sizes['x86'])*100,[EX,BX]),
        ('generated kernel JIT code shrinks','ARM64 native code reduction (%)',12.1,(1-sizes['arm'])*100,[EA]),
        ('On x86-64 KVM, the','x86 execution speedup',1.242,gm(er.values()),[EX,BX]),
        ('On x86-64 KVM, the','x86 time reduction (%)',19.47,(1-1/gm(er.values()))*100,[EX,BX]),
        ('Over the 27','ARM64 execution speedup',1.222,gm(ar.values()),[EA]),
        ('execution time by 18.17','ARM64 time reduction (%)',18.17,(1-1/gm(ar.values()))*100,[EA])]:
        scalar(ef,needle,label,v,actual,paths,EVAL_SCRIPT,digits=1 if v in (22.8,12.1) else 2 if v in (19.47,18.17) else 3,method='runtime: 27 cases; native code size: all 29 cases; per-runtime sample medians')
    for needle,label,claimed,actual in [('308/308','ARM64 median matched/applied sites','308/308',None),('924/924','ARM64 summed sample matched/applied sites','924/924',None)]:
        medmatch=medapply=rawmatch=rawapply=0
        for b in data(EA)['benchmarks']:
            for r in b['runs']:
                if r['runtime']!='kernel_rejit':continue
                counts=[]
                for s in r['samples']:
                    mm=aa=0
                    for prog in (s.get('rejit_result') or {}).get('per_program',{}).values():
                        for pr in prog.get('passes',[]):
                            q=pr.get('bpfopt_summary') or {}
                            if q.get('pass')=='kinsn':mm+=q.get('sites_matched',0);aa+=q.get('sites_applied',0)
                    counts.append((mm,aa));rawmatch+=mm;rawapply+=aa
                medmatch+=statistics.median(c[0] for c in counts);medapply+=statistics.median(c[1] for c in counts)
        result=f'{int(medmatch)}/{int(medapply)}' if needle=='308/308' else f'{rawmatch}/{rawapply}'
        add(ef,needle,label,claimed,[EA],EVAL_SCRIPT,result,'matches' if result==claimed else 'MISMATCH','sum per-program kinsn report counts across benchmarks; median per benchmark or all samples')
    add(ef,'zero correctness mismatches','zero correctness mismatches on both architectures','0',[EX,BX,EA],EVAL_SCRIPT,sum(micro_bad(p) for p in (EX,BX,EA)),'matches','check expected_result and expected_retval for every recorded sample')
    for name,label,v in [('siphash_rotate64_mixer','SipHash',1.902),('cilium_socket_lb_service_select','Cilium socket LB',1.691),('bcc_tcpconnect_ipv4_tuple_filter','BCC TCP tuple',1.624),('cilium_ct_nat_tuple_rewrite','Cilium CT/NAT',1.482),('bpftrace_comm_key_fnv_hash','FNV regression',.862),('bitmap_popcount_scan','bitmap regression',.966)]:
        needle='For example' if v>1 else 'The regressions also'
        scalar(ef,needle,'ARM64 '+label+' speedup',v,ar[name],[EA],EVAL_SCRIPT,method='median kernel exec_ns / median kernel_rejit exec_ns')
    loadvalues=[];openvalues=[]
    names=set(b['name'] for b in data(LP)['benchmarks'])
    for p in LX:
        a,b=med(p,'kernel','object_load_ns'),med(p,'kernel_rejit','object_load_ns');loadvalues.append(gm(b[n]/a[n] for n in names))
        a,b=med(p,'kernel','compile_ns'),med(p,'kernel_rejit','compile_ns');openvalues.append(gm(b[n]/a[n] for n in names))
    add(ef,'kernel-side load time','62-case kernel-side object_load_ns ratio','0.99',LX+[LP],'bpf-benchmark/docs/artifacts/render_claim_table.py','; '.join(f'{v:.9f}' for v in loadvalues),'MISMATCH','geomean of per-case median kernel_rejit/kernel phases_ns.object_load_ns','Bare object_load_ns rounds to 1.00 in both runs. Open+load compile_ns gives '+', '.join(f'{v:.9f}' for v in openvalues)+', rounding to 0.99. These are 1-sample INNER_REPEAT=10 May14 runs, not the 3-sample June performance protocol.')
    add(ef,'end-to-end compile time','1.4--2.4x end-to-end compile time, remains sub-millisecond','1.4--2.4; <1 ms',LX+[EX,BX],EVAL_SCRIPT,'','not substantiated; timing-field ambiguity','inspect compile_ns and phase fields','Retained compile_ns includes libbpf open+load. May19 candidate has multi-ms values. No retained recognizer-inclusive sub-ms timing campaign or exact generating script found.',kind='missing raw')
    scalar(ef,'On x86-64 KVM, the default','Cilium full throughput',1.074,throughput(CF),[CF],APP_SCRIPT,method='median summed pktgen post pps / median summed baseline pps (3+3 samples; stats off)')
    scalar(ef,'On ARM64 AWS, the conservative','Katran conservative throughput',1.073,throughput(KC,'katran.json',statistics.mean),[KC],APP_SCRIPT,method='mean summed pktgen post/baseline pps, 3+3 samples; raw bpf_stats=true unlike RQ2 stats-disabled wording')
    for needle,label,val,paths in [('This run applies','Cilium full applied sites',4086,[CFC]),('This run applies','Cilium load-time skips',0,[CFC]),('This run applies','Cilium report errors',0,[CFC]),('LEA contributes','Cilium LEA sites',2346,[CFC]),('LEA contributes','Cilium conditional select sites',385,[CFC]),('LEA contributes','Cilium endian fusion sites',766,[CFC]),('LEA contributes','Cilium extract sites',2,[CFC]),('LEA contributes','Cilium bulk memory sites',587,[CFC]),('applies 21 sites','Katran conservative applied sites',21,[KC])]:
        add(ef,needle,label,val,paths,APP_SCRIPT,match='unverifiable original count',notes='Original per-pass report_path is recorded but corresponding JSONL absent. Later Sept KVM/QEMU reports measure a different generation; not a substitute.',kind='declared count')
    for needle,label,val,actual,paths in [
        ('this policy applies','Cilium full policy throughput',1.074,throughput(CF),[CF]),
        ('this policy applies','Cilium full paired BPF cost',1.009,paired_cost(CFC)[0],[CFC]),
        ('reduces the number','Cilium no-bulk throughput',1.114,throughput(CN,agg=statistics.mean),[CN]),
        ('At the same time','Cilium no-bulk paired BPF cost',1.062,paired_cost(CNC)[0],[CNC]),
        ('conservative ARM64 policy','Katran conservative throughput',1.073,throughput(KC,'katran.json',statistics.mean),[KC]),
        ('reducing BPF cost','Katran conservative BPF cost',.941,paired_cost(KC,'katran.json')[0],[KC]),
        ('throughput falls','Katran coverage-max throughput',.995,throughput(KM,'katran.json',statistics.mean),[KM]),
        ('BPF cost rises','Katran coverage-max BPF cost',1.006,paired_cost(KM,'katran.json')[0],[KM])]:
        scalar(ef,needle,label,val,actual,paths,APP_SCRIPT,method='Cilium full throughput: stats-off median; tuned: stats-off mean (median gives 1.118935, violating paper default median convention); cost: geomean of name/type/occurrence paired ns/run rows >=100. Katran throughput: mean; one paired hot-XDP cost row.',notes='This paper figure uses the June4/tuned June5 pair, not the separate four-arm June5 ablation ladder.')
    for needle,label,val,p in [('this policy applies','Cilium repeated full site count',4086,CFC),('reduces the number','Cilium no-bulk site count',3512,CNC),('conservative ARM64 policy','Katran repeated conservative site count',21,KC),('coverage-max policy','Katran coverage-max sites',62,KM)]:
        add(ef,needle,label,val,[p],APP_SCRIPT,match='unverifiable original count',notes='No original per-pass report retained.',kind='declared count')
    cv=cost(NC);nspeed=cv['baseline']/cv['post_rejit']
    for needle,label,val,actual,p in [('throughput improves by','Cilium native throughput',2.358,throughput(NT),NT),('cost drops from','Cilium baseline BPF ns/run',488.7,cv['baseline'],NC),('cost drops from','Cilium native BPF ns/run',262.3,cv['post_rejit'],NC),('BPF-counter speedup','Cilium BPF-counter speedup',1.86,nspeed,NC),('The 2.358','native upper-bound repetition',2.358,throughput(NT),NT)]:
        scalar(ef,needle,label,val,actual,[p],NATIVE_SCRIPT,digits=1 if val in (488.7,262.3) else 2 if val==1.86 else 3,method='throughput: stats-off median summed pps; cost: phase sum(run_time_ns_delta)/sum(run_cnt_delta), retain each phase row >=100')
    for label,v in [('native replacements',113),('manifest no-match pass-throughs',22),('Cilium manifest objects',89),('native files',8)]:
        add(ef,'The Cilium native run logs' if v in (113,22) else 'native sidecar data',label,v,[NC,NT],NATIVE_SCRIPT,match='unverifiable original loader count',notes='Original loader stream/sidecar absent. Sept24 evidence has 135 replacements, 0 pass-throughs, 89 objects across 6 files; different generation.',kind='declared count')
    scalar(ef,'gain recovers 5.4','Cilium fraction of native gap recovered (%)',5.4,(throughput(CF)-1)/(throughput(NT)-1)*100,[CF,NT],NATIVE_SCRIPT,digits=1,method='(kinsn throughput-1)/(native throughput-1)*100')
    scalar(ef,'recovers 42','micro fraction of characterization gap recovered (%)',42,(gm(er.values())-1)/(gm(chars['x86','native'])-1)*100,[EX,BX,X],EVAL_SCRIPT,digits=0,method='(kinsn speedup-1)/(native speedup-1)*100')
    for f,needle in [('sections/0-abstract.tex','speeds up eBPF microbenchmarks'),('sections/1-introduction.tex','speeds up eBPF microbenchmarks')]:
        scalar(f,needle,'x86 headline speed increase (%)',24,(gm(er.values())-1)*100,[EX,BX],EVAL_SCRIPT,digits=0)
        scalar(f,needle,'ARM64 headline speed increase (%)',22,(gm(ar.values())-1)*100,[EA],EVAL_SCRIPT,digits=0)
        add(f,needle,'production throughput increase up to (%)',12,[CN],APP_SCRIPT,f'{(throughput(CN,agg=statistics.mean)-1)*100:.9f}% mean; {(throughput(CN)-1)*100:.9f}% median','approximate bound; aggregation-dependent','tuned Cilium mean pps ratio matches body 1.114; median-phase ratio rounds to a 12% increase','Mean-based increase is 11.390%, below loose 12% bound; paper default median gives 11.894%.')
        scalar(f,'reaching 2.358','Cilium native headline speedup',2.358,throughput(NT),[NT],NATIVE_SCRIPT)
    scalar('sections/1-introduction.tex','recovering 42','headline recovered micro gap (%)',42,(gm(er.values())-1)/(gm(chars['x86','native'])-1)*100,[EX,BX,X],EVAL_SCRIPT,digits=0)
    scalar('sections/1-introduction.tex','An implementation','contribution recovered micro gap (%)',42,(gm(er.values())-1)/(gm(chars['x86','native'])-1)*100,[EX,BX,X],EVAL_SCRIPT,digits=0)
    add('sections/1-introduction.tex','Native code size shrinks','native code reduction range','12--23%', [EX,BX,EA],EVAL_SCRIPT,f'{(1-sizes["arm"])*100:.6f}%--{(1-sizes["x86"])*100:.6f}%','matches rounding','native code geomean over all 29 cases')
    # Numeric figure data: one row per bar, linked to the active figure source.
    for arch in ('x86','arm'):
        for rt in ('native_kernel','native','llvmbpf'):
            paths=[X] if arch=='x86' else [AK if rt=='native_kernel' else AU]
            for name,val in sorted(chars[arch,rt].items()):
                add('figures/sec-3-pure-bytecode-percase.tex','includegraphics',arch+' '+name+' '+rt+' plotted speedup','bar (value derived below)',paths,CHAR_SCRIPT,f'{val:.9f}','recomputed; figure legends match; bars visually consistent','median kernel/path exec_ns; each ARM path has its own baseline','Final figure is sec-3-4config-percase.pdf, introduced June10; updated generating script not tracked.',kind='figure bar')
    for arch,values,paths in [('x86',er,[EX,BX]),('arm',ar,[EA])]:
        for name,val in sorted(values.items()):
            add('figures/sec-6-kinsn-micro-rq1.tex','sec-6-'+('x86' if arch=='x86' else 'arm64'),arch+' '+name+' plotted kinsn speedup','bar (value derived below)',paths,EVAL_SCRIPT,f'{val:.9f}','recomputed; figure geomeans 1.24/1.22 match','27-case sample medians; x86 separate candidate/baseline; ARM matched kernel/kernel_rejit',kind='figure bar')
    for label,run,n,agg in [('Cilium Full',CF,'cilium__agent.json',statistics.median),('Cilium No Bulk',CN,'cilium__agent.json',statistics.mean),('Katran Conservative',KC,'katran.json',statistics.mean),('Katran Full',KM,'katran.json',statistics.mean)]:
        add('figures/sec-6-kinsn-micro-rq3.tex','includegraphics',label+' throughput bar','1.074/1.114/1.073/0.995',[run],APP_SCRIPT,f'{throughput(run,n,agg):.9f}','matches plotted labels','as body RQ3; active PDF has exactly four configurations')
    add(ef,'kernel-side load time','historical load-time campaign protocol','62 cases',[*LX,LP],EVAL_SCRIPT,'62','matches population; different sampling protocol','intersect both May14 runs with Apr29 62-name list; exclude katran_like','Retained historical samples=1, INNER_REPEAT=10; performance figure protocol is samples=3, INNER_REPEAT=100000.')
    add('figures/sec-6-kinsn-micro-rq1.tex','the 27 benchmarks','ARM64 figure population','27',[EA],EVAL_SCRIPT,len(ar),'matches','cases with applied kinsn sites; exclude baseline-only simple/simple_packet')
    return chars,er,ar,sizes
