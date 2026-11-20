#!/usr/bin/env python3
"""Count `constant - scalar` sites whose scalar chain reaches the simulator alloca.

    ./trace.py <file.ll>
Every such site is a `scalar - stack_address` subtraction in B, which
adjust_ptr_min_max_vals refuses (see README).
"""
import re,sys
def main():
    src=open(sys.argv[1]).read().split('\n')
    defs={}
    for i,line in enumerate(src):
        m=re.match(r'\s*%(\w+) = (.*)',line)
        if m: defs[m.group(1)]=(i,m.group(2).rstrip(','))
    def reaches_alloca(v,depth=0,seen=frozenset()):
        if depth>5 or v in seen: return False
        body=defs.get(v)
        if not body: return False
        if 'ptrtoint ptr %13' in body[1]: return True
        return any(reaches_alloca(u,depth+1,seen|{v}) for u in re.findall(r'%(\w+)',body[1]))
    total=hits=0
    for i,line in enumerate(src):
        m=re.search(r'sub i64 \d+, %(\w+)',line)
        if not m: continue
        total+=1
        if reaches_alloca(m.group(1)): hits+=1
    print('const-minus-scalar sites: %d, reaching the alloca: %d'%(total,hits))
if __name__=='__main__': main()
