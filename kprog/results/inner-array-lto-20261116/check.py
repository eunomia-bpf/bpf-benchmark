"""Exercise real lowered ARRAY machine code and the captured OTel inner shapes."""
import copy
import json
from pathlib import Path
import re
import subprocess
import sys
from elftools.elf.elffile import ELFFile

ROOT = Path('/workspaces/repository')
raw, tmp = map(Path, sys.argv[1:])
tool = ROOT / 'vendor/build/native-bpf/x86/stage/kprog-perf-context-lto'
kernel = Path('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')
linker = ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link'
previous = Path('/workspaces/kprog-raw/perf/20261116-known-lookup-targets/unwinder')
layout = json.loads((previous/'captured-named-facts/plan.json').read_text())['kernel_layout']['array']

def run(args, name):
    child = subprocess.run(list(map(str,args)),capture_output=True,text=True)
    (raw/(name+'.log')).write_text(child.stdout+child.stderr)
    child.check_returncode()
    return child.stdout+child.stderr

facts = {name:dict(type=13,inner_type=2) for name in ['outer_a','outer_b','outer_c']}
mixed=copy.deepcopy(facts); mixed['outer_b']['inner_type']=1
unknown=copy.deepcopy(facts); del unknown['outer_c']
uniform=copy.deepcopy(facts)
for value in uniform.values(): value['inner_value_size']=8
rows=[]
for name, symbol, values, count in [
    ('table','entry',facts,1), ('select','entry_select',facts,1),
    ('numeric','entry_numeric',facts,1), ('mixed','entry',mixed,0),
    ('unknown','entry',unknown,0), ('mutable','entry_mutable',facts,0),
    ('arithmetic','entry_arithmetic',facts,0),
    ('barrier','entry_barrier',facts,1),
    ('nonempty-barrier','entry_nonempty_barrier',facts,0),
    ('narrow','entry_narrow_handle',facts,0),
    ('value-size','entry',uniform,1),
]:
    path=raw/(name+'.json'); path.write_text(json.dumps(values,indent=2)+'\n')
    output=tmp/(name+'.native.o')
    log=run([tool,tmp/'fixture.native.o','--symbol',symbol,'--prog-type',5,
             '--kernel-btf',kernel,'--map-types',path,'-o',output],name)
    actual=int(re.search(r'typed ARRAY lookups lowered: (\d+)',log)[1])
    assert actual==count,(name,actual,count)
    # Numeric helper calls intentionally retain ID1 for the outer lookup;
    # source arithmetic is a static negative case, not an executable map ABI.
    vectors=0
    if name not in ['numeric','arithmetic','nonempty-barrier','narrow']:
        driver=tmp/(name+'-check')
        run(['clang-18','-O2','-Wall','-Wextra','-Werror','-DENTRY='+symbol,
             '-DEXPECT_CALLS='+str(1 if count else 2),'-DSELECT_ENTRY='+str(int(name=='select')),
             '-DUNIFORM_STRIDE='+str(int(name=='value-size')),
             '-DLIMIT_OFFSET='+str(layout['max_entries']),'-DSTRIDE_OFFSET='+str(layout['elem_size']),
             '-DMASK_OFFSET='+str(layout['index_mask']),'-DVALUE_OFFSET='+str(layout['value']),
             ROOT/'kprog/results/inner-array-lto-20261116/driver.c',output,'-o',driver],name+'-driver')
        result=run([driver],name+'-execution'); vectors=int(result.split()[0])
    rows.append(dict(name=name,symbol=symbol,lowered=actual,execution_vectors=vectors))

metadata=json.loads((previous/'generation.metadata.json').read_text())
types={m['name']:dict(type=m['map_type'],inner_type=m['inner_map']['map_type'] if 'inner_map' in m else 0)
       for m in metadata['maps'] if m['value_offset'] is None}
for m in metadata['maps']:
    if m['name'] in types:
        types[m['name']]['value_size']=m['value_size']
        types[m['name']]['inner_value_size']=m['inner_map']['value_size'] if 'inner_map' in m else 0
path=raw/'otel-map-types.json'; path.write_text(json.dumps(types,indent=2)+'\n')
otel=ROOT/'vendor/build/native-bpf/x86/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o'
real={}
for name, extra in [('baseline',[]),('typed',['--map-types',path])]:
    output=tmp/('otel-'+name+'.native.o')
    log=run([tool,otel,'--symbol','perf_unwind_native','--prog-type',7,
             '--kernel-btf',kernel,*extra,'-o',output],'otel-'+name)
    with output.open('rb') as stream:
        elf=ELFFile(stream)
        symbol=next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name=='perf_unwind_native')
        size=symbol['st_size']
    proof=tmp/('otel-'+name+'.proof.o')
    run([linker,'--input',output,'--symbol','perf_unwind_native','--mode','proof',
         '--preserve-entry-abi','--output',proof],'otel-'+name+'-proof')
    run([linker,'--input',proof,'--symbol','perf_unwind_native','--mode','kernel',
         '--link-plan',previous/'captured-named-facts/plan.json','--output',raw/('otel-'+name+'.blob'),
         '--output-relocs',raw/('otel-'+name+'.relocs'),'--output-map-patches',raw/('otel-'+name+'.maps'),
         '--output-abi',raw/('otel-'+name+'.abi'),'--show'],'otel-'+name+'-kernel')
    real[name]=dict(selected_function_bytes=size,payload_bytes=(raw/('otel-'+name+'.blob')).stat().st_size,
                   lowered=int(re.search(r'typed ARRAY lookups lowered: (\d+)',log)[1]) if name=='typed' else 0)
report=dict(scope=__doc__,fixture=rows,otel=real,
    fact_provenance='Captured checked-six-apps OTel request 3 inner shapes, not current FD-query execution',
    installed_bytes='unmeasured',per_call_body_helpers_maps='pending publication')
(raw/'report.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report,indent=2))
