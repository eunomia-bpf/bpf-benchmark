import subprocess,glob,re,collections,os
d='/workspaces/repository/vendor/build/native-bpf/x86/stage/tetragon'
names=collections.Counter(); bpfsub=collections.Counter(); seen_obj=0
for f in sorted(glob.glob(d+'/*.native.o')):
    out=subprocess.run(['llvm-objdump-18','-dr','--no-show-raw-insn',f],capture_output=True,text=True).stdout.splitlines()
    syms=subprocess.run(['llvm-readelf-18','-sW',f],capture_output=True,text=True).stdout.splitlines()
    secs=subprocess.run(['llvm-readelf-18','-SW',f],capture_output=True,text=True).stdout
    m=re.search(r'\[\s*(\d+)\]\s+\.text\s',secs)
    if not m: continue
    tidx=m.group(1)
    fn={}
    for s in syms:
        p=s.split()
        if len(p)>=8 and p[3]=='FUNC' and p[6]==tidx: fn[int(p[1],16)]=p[7]
    hit=False
    for i,l in enumerate(out):
        mm=re.search(r'R_X86_64_(?:PLT32|PC32)\s+\.text(?:\+0x([0-9a-f]+))?',l)
        if mm and 'call' in out[i-1]:
            off=int(mm.group(1),16)+4 if mm.group(1) else 4
            names[fn.get(off, fn.get(off-4, hex(off)))]+=1; hit=True
    if hit:
        seen_obj+=1
        b=f.replace('.native.o','.o')
        if not os.path.exists(b):
            cand=glob.glob(d+'/'+os.path.basename(f).split('.')[0]+'*.bpf.o')
            b=cand[0] if cand else None
        if b:
            bs=subprocess.run(['llvm-readelf-18','-sW',b],capture_output=True,text=True).stdout.splitlines()
            bsecs=subprocess.run(['llvm-readelf-18','-SW',b],capture_output=True,text=True).stdout
            mb=re.search(r'\[\s*(\d+)\]\s+\.text\s',bsecs)
            if mb:
                for s in bs:
                    p=s.split()
                    if len(p)>=8 and p[3]=='FUNC' and p[6]==mb.group(1): bpfsub[p[7]]+=1
print('objects with local calls', seen_obj)
print('native local call targets', names.most_common(12))
print('eBPF .text subprograms (same objects)', bpfsub.most_common(12))
