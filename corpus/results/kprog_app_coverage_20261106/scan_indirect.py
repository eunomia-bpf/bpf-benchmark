import concurrent.futures,json,re,subprocess
from pathlib import Path
root=Path('/workspaces/repository')
files=list((root/'vendor/build/native-bpf/x86/stage').glob('*/*.proof.o'))
files+=list((root/'corpus/results/kprog_app_coverage_20261106/native-cilium').rglob('*.proof.o'))
def scan(p):
 s=subprocess.run(['objdump','-dr','-Mintel',str(p)],check=True,text=True,capture_output=True).stdout.splitlines()
 found=[]
 for i,l in enumerate(s):
  if re.search(r'\b(jmp|call)\s+(?:[a-z][a-z0-9]*|(?:QWORD|DWORD) PTR \[[^\]]+\])\s*(?:#.*)?$',l): found.append(s[max(0,i-5):i+1])
 return {'object':str(p),'sites':found} if found else None
with concurrent.futures.ThreadPoolExecutor(max_workers=6) as pool:
 records=[r for r in pool.map(scan,files) if r]
out=root/'corpus/results/kprog_app_coverage_20261106/indirect-sites.json'
out.write_text(json.dumps(records,indent=2)+'\n')
print(f'{len(files)} objects scanned, {len(records)} objects with register/memory indirect branches')
from collections import Counter
print(Counter(site[-1].split('\t')[-1] for r in records for site in r['sites']))
for r in records:
 jumps=[s for s in r['sites'] if re.search(r'\bjmp\s',s[-1])]
 if jumps:
  print(r['object'])
  for s in jumps[:3]: print('\n'.join(s))
