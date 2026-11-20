"""Execute C-imported LPM machine code against an independent bitwise oracle."""
import json
from pathlib import Path
import re
import subprocess
import sys

ROOT=Path('/workspaces/repository')
raw,tmp=map(Path,sys.argv[1:])
tool=ROOT/'vendor/build/native-bpf/x86/stage/kprog-perf-context-lto'
kernel=Path('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')

def run(args,name):
    child=subprocess.run(list(map(str,args)),capture_output=True,text=True)
    text=child.stdout+child.stderr
    (raw/(name+'.log')).write_text(text)
    child.check_returncode()
    return text

# Read the actual sole kernel, so kernel member changes reach the test too.
dump=run(['bpftool','btf','dump','file',kernel,'format','raw'],'btf')
layout={}
for struct,fields in [('lpm_trie',{'root':'ROOT','data_size':'SIZE','max_prefixlen':'MAX'}),
                      ('lpm_trie_node',{'child':'CHILD','prefixlen':'PREFIX','flags':'FLAGS','data':'DATA'})]:
    block=re.search(r"^\[\d+\] STRUCT '"+struct+r"'[^\n]*\n((?:\t[^\n]*\n)+)",dump,re.M)[1]
    for field,name in fields.items():
        bits=int(re.search(r"'"+field+r"'[^\n]*bits_offset=(\d+)",block)[1]); assert bits%8==0
        layout[name+'_OFF']=bits//8
rows=[]
for name,types,lowered,extra,expected in [
    ('fixed',{'map_a':dict(type=11,inner_type=0,key_size=16),'map_b':dict(type=11,inner_type=0,key_size=16)},1,['-DFIXED_KEY'],0),
    ('dynamic',{'map_a':dict(type=11,inner_type=0),'map_b':dict(type=11,inner_type=0)},1,[],0),
    ('mixed',{'map_a':dict(type=11,inner_type=0),'map_b':dict(type=1,inner_type=0)},0,[],1),
    ('unknown',{},0,[],2),
]:
    facts=raw/(name+'.json'); facts.write_text(json.dumps(types,indent=2)+'\n')
    objects=[]
    for symbol in ['entry','entry_select']:
        obj=tmp/(name+'-'+symbol+'.o'); objects.append(obj)
        log=run([tool,tmp/'fixture.o','--symbol',symbol,'--prog-type',5,'--kernel-btf',kernel,
                 '--map-types',facts,'-o',obj],name+'-'+symbol)
        count=int(re.search(r'typed LPM lookups lowered: (\d+)',log)[1])
        target=1 if name=='mixed' and symbol=='entry' else lowered
        assert count==target,(name,symbol,count,target)
    # Each optimized module retains both public entry points. Choose one body
    # from each result to exercise each independently selected boundary.
    run(['llvm-objcopy-18','--localize-symbol=entry_select',objects[0]],name+'-localize-direct')
    run(['llvm-objcopy-18','--localize-symbol=entry',objects[1]],name+'-localize-select')
    exe=tmp/(name+'-execute')
    run(['clang-18','-O3','-march=native','-fsanitize=undefined','-fno-sanitize-recover=all',
         '-DEXPECTED_GENERIC='+str(expected),*extra,*['-D'+k+'='+str(v) for k,v in layout.items()],
         ROOT/'kprog/results/lpm-c-lto-20261120/driver.c',*objects,'-o',exe],name+'-driver')
    text=run([exe],name+'-execution')
    cases,calls=map(int,re.search(r'(\d+) cases, (\d+) generic calls',text).groups())
    assembly=run(['llvm-objdump-18','-dr',*objects],name+'-asm')
    rows.append(dict(name=name,cases=cases,generic_calls=calls,lpm_lowered_per_entry=lowered))
(raw/'report.json').write_text(json.dumps(dict(layout=layout,cases=rows,scope='host machine-code semantics; installed application performance pending'),indent=2)+'\n')
print(json.dumps(rows,indent=2))
