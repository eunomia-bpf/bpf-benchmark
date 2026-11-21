import subprocess,glob,os,re,collections,sys
root=sys.argv[1]
for app in sorted(os.listdir(root)):
    d=os.path.join(root,app)
    if not os.path.isdir(d): continue
    cat=collections.Counter(); local=collections.Counter(); kprog=collections.Counter(); other=collections.Counter()
    defined_kprog=0; objs=glob.glob(d+'/*.native.o')
    for f in objs:
        out=subprocess.run(['llvm-objdump-18','-dr','--no-show-raw-insn',f],capture_output=True,text=True).stdout.splitlines()
        syms=subprocess.run(['llvm-nm-18','--defined-only',f],capture_output=True,text=True).stdout
        defined_kprog+=len(re.findall(r'\b[tT] __kprog_',syms))
        localfn=set(re.findall(r'\b[tT] (\S+)',syms))
        for i,l in enumerate(out):
            m=re.search(r'R_X86_64_(?:PLT32|PC32)\s+(\S+?)(?:-0x4)?$',l)
            if not m or i==0 or 'call' not in out[i-1]: continue
            t=m.group(1)
            if t.startswith('bpf_'): cat['helper']+=1
            elif t.startswith('__kprog'): cat['__kprog (should be inlined)']+=1; kprog[t]+=1
            elif t in ('memcpy','memset','memmove','__memcpy','__memset'): cat[t]+=1
            elif t in localfn or t.startswith('.text'): cat['local function']+=1; local[t]+=1
            else: cat['other']+=1; other[t]+=1
    print(f'== {app}: {len(objs)} objects, out-of-line __kprog_ definitions {defined_kprog}')
    print('   ', dict(cat))
    if kprog: print('    __kprog calls:', kprog.most_common(5))
    if local: print('    local calls:', local.most_common(6))
    if other: print('    other calls:', other.most_common(6))
