#!/usr/bin/env python3
"""REP MOVS/STOS widths, overlap, address32, full counts and restart faults."""
import copy
import ctypes
import json
from pathlib import Path
import random
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64) - 1


def encoding(width, address32=False, segment=0):
    return bytes(([segment] if segment else []) + ([0x67] if address32 else []) +
        ([0x66] if width==2 else []) + [0xf3] + ([0x48] if width==8 else []) + [0xa4 if width==1 else 0xa5])


def expected(request):
    s = copy.deepcopy(request['state']); code = request['native_bytes']; width = request['_width']; a32 = request['_a32']
    events = []; cells = {c['address']:c for c in s['memory']}; narrow = (1<<32)-1 if a32 else MASK
    stos = request.get('_stos',False)
    for r in ((1,7) if stos else (1,6,7)): s['registers'][r] &= narrow
    bits=s.get('linear_address_bits',48)
    def canonical(address):
        return address >> bits == (((1 << (64-bits))-1) if address & (1 << (bits-1)) else 0)
    while s['registers'][1]:
        source = (request['_segment']+s['registers'][6])&MASK; dest = s['registers'][7]
        if stos:
            value = list((s['registers'][0]&((1 << (8*width))-1)).to_bytes(width,'little'))
        else:
            addresses = [(source+i)&MASK for i in range(width)]
            if not all(canonical(a) for a in addresses):
                fault = dict(kind='non_canonical',address=source);break
            if not all(a in cells and cells[a]['readable'] for a in addresses):
                fault = dict(kind='read',address=source,bytes=width);break
            value = [cells[a]['value'] for a in addresses]
            events.append(dict(kind='read',address=source,value=value,initialized=all(cells[a]['initialized'] for a in addresses)))
        addresses = [(dest+i)&MASK for i in range(width)]
        if not all(canonical(a) for a in addresses):
            fault = dict(kind='non_canonical',address=dest);break
        if not all(a in cells and cells[a]['writable'] for a in addresses):
            fault = dict(kind='write',address=dest,bytes=width);break
        events.append(dict(kind='write',address=dest,value=value,initialized=True))
        for a,b in zip(addresses,value): cells[a].update(value=b,initialized=True)
        stride = -width if s['flags']&0x400 else width
        for r in ((7,) if stos else (6,7)): s['registers'][r] = (s['registers'][r]+stride)&narrow
        s['registers'][1] = (s['registers'][1]-1)&narrow
    else: fault = None;s['pc'] = (s['pc']+len(code))&MASK
    if fault: events.append(dict(kind='fault',fault=fault))
    s.update(events=events,fault=fault,defined_flags=MASK)
    return s


def main():
    folder = ROOT/'build/rep-movs-reference';folder.mkdir(parents=True,exist_ok=True)
    source = [r'''
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/mman.h>
#include <ucontext.h>
#include <unistd.h>
void *arena(void) {return mmap(0,4096,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_32BIT,-1,0);}
int release(void *p) {return munmap(p,4096);}
''']
    for width,suffix in ((1,'b'),(2,'w'),(4,'l'),(8,'q')):
        for a32 in (False,True):
            name = f'f{width}_{int(a32)}';instruction = ('addr32 ' if a32 else '')+'rep movs'+suffix
            source.append(f'void {name}(const uint64_t *in,uint64_t *out){{uint64_t s=in[0],d=in[1],n=in[2],old=in[3],f;'
                f'__asm__ volatile("pushfq;pushq %[old];popfq;{instruction};pushfq;popq %[f];popfq"'
                ':[s]"+S"(s),[d]"+D"(d),[n]"+c"(n),[f]"=&r"(f):[old]"r"(old):"cc","memory");'
                'out[0]=s;out[1]=d;out[2]=n;out[3]=f;}')
    for width,suffix in ((1,'b'),(2,'w'),(4,'l'),(8,'q')):
        source.append(f'void g{width}(const uint64_t *in,uint64_t *out){{uint64_t s=in[0],d=in[1],n=in[2],old=in[3],a=in[4],f;'
            f'__asm__ volatile("pushfq;pushq %[old];popfq;rep stos{suffix};pushfq;popq %[f];popfq"'
            ':[s]"+S"(s),[d]"+D"(d),[n]"+c"(n),[f]"=&r"(f):[a]"a"(a),[old]"r"(old):"cc","memory");'
            'out[0]=s;out[1]=d;out[2]=n;out[3]=f;}')
    source.append(r'''
#ifdef FAULT_MAIN
static sigjmp_buf restart;
static uint64_t got[4];static unsigned char code[8];static volatile sig_atomic_t signum;
static void caught(int sig,siginfo_t *info,void *opaque){
 (void)info;ucontext_t *u=opaque;
 got[0]=u->uc_mcontext.gregs[REG_RSI];got[1]=u->uc_mcontext.gregs[REG_RDI];got[2]=u->uc_mcontext.gregs[REG_RCX];got[3]=u->uc_mcontext.gregs[REG_EFL];
 memcpy(code,(void*)u->uc_mcontext.gregs[REG_RIP],8);signum=sig;siglongjmp(restart,1);
}
static void hex(const unsigned char *s,size_t n){for(size_t i=0;i<n;i++)printf("%02x",s[i]);}
static int run(int w,int a32,int df,int write_fault,int completed,int stos){
 size_t page=sysconf(_SC_PAGESIZE),length=4*w;
 unsigned char *src=mmap(0,3*page,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_32BIT,-1,0);
 unsigned char *dst=mmap(0,3*page,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_32BIT,-1,0);
 if(src==MAP_FAILED || dst==MAP_FAILED)return 1;
 for(size_t i=0;i<3*page;i++){src[i]=i*13+5;dst[i]=i*17+11;}
 uintptr_t s=(uintptr_t)src+page+256,d=(uintptr_t)dst+page+256;
 uintptr_t edge=(uintptr_t)(write_fault?dst:src)+page;
 uintptr_t failed=df?edge+(completed-1)*w:edge+page-completed*w;
 if(write_fault)d=failed;else s=failed;
 uintptr_t slo=df?s-3*w:s,dlo=df?d-3*w:d;
 unsigned char sb[32],db[32];memcpy(sb,(void*)slo,length);memcpy(db,(void*)dlo,length);
 uint64_t in[5]={s,d,4,0xad7|(df?0x400:0),0x8123456789abcdefUL},unused[4];
 if(a32){in[0]|=1ul<<40;in[1]|=2ul<<40;in[2]|=3ul<<40;}
 if(mprotect(src,page,PROT_NONE)||mprotect(src+2*page,page,PROT_NONE)||mprotect(dst,page,PROT_NONE)||mprotect(dst+2*page,page,PROT_NONE))return 2;
 signum=0;
 if(sigsetjmp(restart,1)==0){
  if(stos){switch(w){case 1:g1(in,unused);break;case 2:g2(in,unused);break;case 4:g4(in,unused);break;case 8:g8(in,unused);break;default:return 3;}}
  else switch(w*2+a32){case 2:f1_0(in,unused);break;case 3:f1_1(in,unused);break;case 4:f2_0(in,unused);break;case 5:f2_1(in,unused);break;case 8:f4_0(in,unused);break;case 9:f4_1(in,unused);break;case 16:f8_0(in,unused);break;case 17:f8_1(in,unused);break;default:return 3;}
  return 4;
 }
 __asm__ volatile("cld":::"cc");
 if(signum!=SIGSEGV)return 5;
 if(mprotect(src,3*page,PROT_READ|PROT_WRITE)||mprotect(dst,3*page,PROT_READ|PROT_WRITE))return 6;
 printf("%d %d %d %d %d %d %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu ",w,a32,df,write_fault,completed,stos,in[0],in[1],in[2],got[0],got[1],got[2],got[3],slo,dlo,(uintptr_t)src+page,(uintptr_t)dst+page,page);
 hex(sb,length);printf(" ");hex(db,length);printf(" ");hex((void*)slo,length);printf(" ");hex((void*)dlo,length);printf(" ");hex(code,8);printf("\n");
 if(munmap(src,3*page)||munmap(dst,3*page))return 7;
 return 0;
}
int main(void){
 struct sigaction action={0};action.sa_sigaction=caught;action.sa_flags=SA_SIGINFO;
 if(sigaction(SIGSEGV,&action,0))return 8;
 for(int w=1;w<=8;w*=2)for(int a32=0;a32<2;a32++)for(int df=0;df<2;df++)for(int write=0;write<2;write++)for(int done=0;done<=2;done+=2){int rc=run(w,a32,df,write,done,0);if(rc)return rc;}
 for(int w=1;w<=8;w*=2)for(int df=0;df<2;df++)for(int done=0;done<=2;done+=2){int rc=run(w,0,df,1,done,1);if(rc)return rc;}
 return 0;
}
#endif
''')
    (folder/'cpu.c').write_text('\n'.join(source))
    subprocess.run(['cc','-O2','-shared','-fPIC','-mno-red-zone',folder/'cpu.c','-o',folder/'cpu.so'],check=True)
    subprocess.run(['cc','-O2','-mno-red-zone','-DFAULT_MAIN',folder/'cpu.c','-o',folder/'fault'],check=True)
    library = ctypes.CDLL(str(folder/'cpu.so'));library.arena.restype = ctypes.c_void_p
    library.release.argtypes = [ctypes.c_void_p];library.release.restype = ctypes.c_int
    address = library.arena();assert address not in (None,MASK) and address<1<<32
    rng = random.Random(0x524550);cases = [];cpu_cases = 0;total = 0
    def state():
        return dict(registers=[rng.getrandbits(64) for _ in range(16)],flags=0x202,pc=MASK-1,
            xmm0=rng.getrandbits(128),fs_base=0,gs_base=0,memory=[])
    def submit(code,s,width,a32=False,segment=0,cpu=None,stos=False):
        nonlocal total
        r=dict(isa='x86_64',native_bytes=list(code),state=s,_width=width,_a32=a32,_segment=segment,_stos=stos)
        e=expected(r)
        if cpu:
            regs,flags,image=cpu
            assert [e['registers'][i] for i in (6,7,1)]==regs,(r,e,regs)
            assert (e['flags']^flags)&0xcd5==0,(r,e,flags)
            assert bytes(c['value'] for c in e['memory'])==image,(r,e,image)
        for key in ('_width','_a32','_segment','_stos'): del r[key]
        cases.append((r,e));total+=1
        if len(cases)>=32: flush()
    def flush():
        if not cases:return
        result=subprocess.run([ROOT/'.lake/build/bin/reference'],input=''.join(json.dumps(r)+'\n' for r,_ in cases),text=True,capture_output=True,check=True)
        outputs=[json.loads(line) for line in result.stdout.splitlines()];assert len(outputs)==len(cases)
        for (r,e),a in zip(cases,outputs):assert a==e,(r,a,e)
        cases.clear()
    try:
        for width in (1,2,4,8):
            for a32 in (False,True):
                fn=getattr(library,f'f{width}_{int(a32)}');fn.argtypes=[ctypes.POINTER(ctypes.c_uint64)]*2;fn.restype=None
                for df in (False,True):
                    for count in (0,1,2,7,9,64,65):
                        for displacement in (-8,-1,0,1,128):
                            for flags in (0x202,0xad7):
                                image=rng.randbytes(1536);ctypes.memmove(address,image,len(image))
                                src=address+640;dst=src+displacement
                                regs=[src,dst,count];old=flags|(0x400 if df else 0)
                                if a32:regs=[src|(1<<40),dst|(2<<40),count|(3<<40)]
                                ins=(ctypes.c_uint64*4)(*regs,old);out=(ctypes.c_uint64*4)();fn(ins,out)
                                s=state();s['flags']=old;s['registers'][6],s['registers'][7],s['registers'][1]=regs
                                s['memory']=[dict(address=address+i,value=b,readable=True,writable=True,initialized=True) for i,b in enumerate(image)]
                                submit(encoding(width,a32),s,width,a32,cpu=(list(out)[:3],out[3],ctypes.string_at(address,len(image))))
                                cpu_cases+=1
        for width in (1,2,4,8):
            fn=getattr(library,f'g{width}');fn.argtypes=[ctypes.POINTER(ctypes.c_uint64)]*2;fn.restype=None
            for df in (False,True):
                for count in (0,1,2,64,65):
                    for value in (0,1,0x8123456789abcdef):
                        for flags in (0x202,0xad7):
                            image=rng.randbytes(1536);ctypes.memmove(address,image,len(image))
                            old=flags|(0x400 if df else 0);regs=[0xabcdef1234567890,address+640,count]
                            ins=(ctypes.c_uint64*5)(*regs,old,value);out=(ctypes.c_uint64*4)();fn(ins,out)
                            s=state();s['flags']=old;s['registers'][0]=value
                            s['registers'][6],s['registers'][7],s['registers'][1]=regs
                            s['memory']=[dict(address=address+i,value=b,readable=True,writable=True,initialized=True) for i,b in enumerate(image)]
                            code=bytes(([0x66] if width==2 else [])+[0xf3]+([0x48] if width==8 else [])+[0xaa if width==1 else 0xab])
                            submit(code,s,width,cpu=(list(out)[:3],out[3],ctypes.string_at(address,len(image))),stos=True)
                            cpu_cases+=1
    finally:assert library.release(address)==0
    fault_lines=subprocess.check_output([folder/'fault'],text=True).splitlines();assert len(fault_lines)==80
    (folder/'cpu-faults.log').write_text('\n'.join(fault_lines)+'\n')
    for line in fault_lines:
        fields=line.split();w,a32,df,write,done,stos=map(int,fields[:6]);raw=list(map(int,fields[6:18]))
        si,di,n,rs,rd,rn,flags,slo,dlo,smid,dmid,page=raw
        sb,db,sa,da,code=(bytes.fromhex(x) for x in fields[18:])
        end=0
        while code[end] in (0x66,0x67,0xf3,0x48):end+=1
        assert code[end]==((0xaa if w==1 else 0xab) if stos else (0xa4 if w==1 else 0xa5)),line
        s=state();s['flags']=0xad7|(0x400 if df else 0);s['registers'][6],s['registers'][7],s['registers'][1]=si,di,n
        if stos:s['registers'][0]=0x8123456789abcdef
        for low,data,mid in ((slo,sb,smid),(dlo,db,dmid)):
            s['memory'] += [dict(address=low+i,value=b,readable=mid<=low+i<mid+page,writable=mid<=low+i<mid+page,initialized=True) for i,b in enumerate(data)]
        submit(code[:end+1],s,w,bool(a32),cpu=([rs,rd,rn],flags,sa+da),stos=bool(stos))
    # Segment overrides affect only source. Address and PC wrapping, arbitrary
    # initialization, absent/unmapped bytes, overlap and counts beyond C's64 bound.
    for w in (1,2,4,8):
        for a32 in (False,True):
            for df in (False,True):
                for seg in (0,0x64,0x65):
                    for count in (0,1,2,65):
                        for bad in (None,'read','write'):
                            s=state();s['flags']=0xad7|(0x400 if df else 0);base=0x10000 if seg else 0
                            s['fs_base']=base if seg==0x64 else 0;s['gs_base']=base if seg==0x65 else 0
                            s['registers'][6]=0xfffffff8 if a32 else MASK-7;s['registers'][7]=0x3000;s['registers'][1]=count
                            if a32:
                                for r in (1,6,7):s['registers'][r]|=7<<40
                            cells={};delta=-w if df else w;mask=(1<<32)-1 if a32 else MASK
                            for j in range(count):
                                for source,start in ((True,(base+((s['registers'][6]+j*delta)&mask))&MASK),(False,(s['registers'][7]+j*delta)&mask)):
                                    for i in range(w):
                                        a=(start+i)&MASK;cells.setdefault(a,dict(address=a,value=rng.randrange(256),readable=True,writable=True,initialized=bool(i%2)))
                                        if j==min(count-1,1) and i==w-1 and bad==('read' if source else 'write'):cells[a]['readable' if source else 'writable']=False
                            s['memory']=list(cells.values());submit(encoding(w,a32,seg),s,w,a32,base)
    for w in (1,8):
        for df in (False,True):
            s=state();s['flags']|=0x400 if df else 0
            s['registers'][1]=3;s['registers'][6]=0x1000;s['registers'][7]=0x1001
            s['memory']=[dict(address=a,value=rng.randrange(256),readable=True,writable=True,initialized=bool(a%3)) for a in range(0xfe0,0x1020)]
            submit(encoding(w),s,w)
    for w in (1,2,4,8):
        for a32 in (False,True):
            s=state();s['registers'][1]=MASK
            submit(encoding(w,a32),s,w,a32)
    for width in (1,2,4,8):
        for df in (False,True):
            for count in (0,1,2,65,MASK):
                for bad in (None,0,1):
                    s=state();s['flags'] |= 0x400 if df else 0
                    s['registers'][1]=count;s['registers'][7]=0x3000;s['registers'][0]=0x8123456789abcdef
                    delta=-width if df else width
                    # The maximal count faults immediately; no artificial REP cap.
                    length=0 if count==MASK else count
                    cells={}
                    for j in range(length):
                        for i in range(width):
                            a=(0x3000+j*delta+i)&MASK
                            cells[a]=dict(address=a,value=rng.randrange(256),readable=False,writable=not(j==bad and i==width-1),initialized=False)
                    s['memory']=list(cells.values())
                    code=bytes(([0x66] if width==2 else [])+[0xf3]+([0x48] if width==8 else [])+[0xaa if width==1 else 0xab])
                    submit(code,s,width,stos=True)
    for length in (2,15):
        s=state();s['registers'][1]=0;submit(b'\x40'*(length-2)+b'\xf3\xa4',s,1)
    flush()
    for code in (b'\xa4',b'\xf2\xa4',b'\xf3',b'\x40'*14+b'\xf3\xa4'):
        r=dict(isa='x86_64',native_bytes=list(code),state=state())
        result=subprocess.run([ROOT/'.lake/build/bin/reference'],input=json.dumps(r)+'\n',text=True,capture_output=True)
        assert result.returncode==1 and result.stderr.startswith('reference:'),(r,result)
    print(f'x86 REP MOVS/STOS: {cpu_cases} CPU width/direction/overlap/address32 cases, {len(fault_lines)} CPU restart faults, {total} full-state transitions PASS')


if __name__=='__main__':main()
