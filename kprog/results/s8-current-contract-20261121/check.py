"""S8 current-source host oracles and captured-source micro compilation."""
import argparse
import ctypes as C
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import tarfile

ROOT = Path('/workspaces/repository')
RAW = Path('/workspaces/kprog-raw/S8/20261121')
TMP = Path('/var/tmp/kprog-tmp/S8')
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT/'kprog'))
os.environ['PYTHONDONTWRITEBYTECODE'] = '1'

def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def save(name, value):
    (RAW/name).write_text(json.dumps(value, indent=2)+'\n')

def run(cmd):
    p = subprocess.run([str(x) for x in cmd], capture_output=True, text=True)
    with (RAW/'commands.jsonl').open('a') as f:
        f.write(json.dumps(dict(command=[str(x) for x in cmd], returncode=p.returncode,
                               stdout=p.stdout, stderr=p.stderr))+'\n')
    p.check_returncode()
    return p.stdout

def context():
    from trusted_generation import context_kind
    kernel = ROOT/'vendor/linux-framework'
    text = (kernel/'include/linux/bpf_types.h').read_text()
    enum = (kernel/'include/uapi/linux/bpf.h').read_text().split('enum bpf_prog_type {',1)[1].split('};',1)[0]
    names = re.findall(r'\bBPF_PROG_TYPE_(\w+)\b',enum)
    entries = re.findall(r'BPF_PROG_TYPE\(BPF_PROG_TYPE_(\w+),\s*(\w+),\s*([^,]+),\s*([^\)]+)\)',text)
    identity = {2,5,15,17,20,24,26,27,28,29,31,32}
    typed = {3:'tc',6:'xdp',8:'cgroup_skb'}
    rows=[]
    for name,handler,public,physical in entries:
        n=names.index(name)
        category='typed' if n in typed else 'identity' if n in identity else 'converted'
        try:
            actual=context_kind(n)
        except ValueError as error:
            assert category=='converted' and 'context layout handler required' in str(error)
            actual='generation-handler-required'
        assert actual == ('generation-handler-required' if category=='converted' else typed.get(n,'raw'))
        rows.append(dict(prog_type=n,name=name,handler=handler,public=public.strip(),physical=physical.strip(),
                         category=category,current_dispatch=actual,isas=['x86','arm64']))
    assert len(rows)==32
    ops = {}
    for file in ('net/core/filter.c','kernel/trace/bpf_trace.c','kernel/bpf/cgroup.c',
                 'kernel/bpf/bpf_lsm.c','kernel/bpf/bpf_struct_ops.c','kernel/bpf/syscall.c',
                 'kernel/bpf/trampoline.c','drivers/media/rc/bpf-lirc.c','net/netfilter/nf_bpf_link.c'):
        src=(kernel/file).read_text()
        for m in re.finditer(r'const struct bpf_verifier_ops (\w+)_verifier_ops\s*=\s*\{(.*?)^\};',src,re.S|re.M):
            converter=re.search(r'\.convert_ctx_access\s*=\s*(\w+)',m[2])
            ops[m[1]]=dict(source=file,line=src[:m.start()].count('\n')+1,
                           converter=converter[1] if converter else 'identity',body=m[0])
    for row in rows:
        row['stock_ops']=ops[row['handler']]
        assert (row['stock_ops']['converter']=='identity') == (row['category']=='identity'),row
    # Execute raw UAPI stores on local buffers against the two actual kernel layouts.
    c='#include <linux/bpf.h>\n#include <stddef.h>\nunsigned public_mark_offset(void) { return offsetof(struct __sk_buff,mark); }\nvoid raw_mark(void *p,unsigned v) { ((struct __sk_buff *)p)->mark=v; }\n'
    (TMP/'context.c').write_text(c)
    run(['cc','-O2','-shared','-fPIC','-I'+str(kernel/'tools/include/uapi'),TMP/'context.c','-o',TMP/'context.so'])
    lib=C.CDLL(str(TMP/'context.so'));lib.raw_mark.argtypes=[C.c_void_p,C.c_uint]
    public=lib.public_mark_offset();assert public==8
    layout=[]
    for arch in ('x86','arm64'):
        image=ROOT.parent/f'.agent-state/kprog-ck/build-{arch}/vmlinux'
        out=run(['pahole','-C','sk_buff',image]);(RAW/f'sk_buff-{arch}.txt').write_text(out)
        physical=int(re.search(r'__u32\s+mark;\s*/\*\s*(\d+)',out)[1])
        previous=int(re.search(r'struct sk_buff \* prev;\s*/\*\s*(\d+)',out)[1])
        buf=C.create_string_buffer(4096);lib.raw_mark(buf,0x12345678)
        assert C.c_uint.from_buffer(buf,previous).value==0x12345678
        assert C.c_uint.from_buffer(buf,physical).value==0
        C.c_uint.from_buffer(buf,physical).value=0x87654321
        assert C.c_uint.from_buffer(buf,physical).value==0x87654321
        layout.append(dict(arch=arch,public_mark_offset=public,kernel_mark_offset=physical,
                           kernel_prev_offset=previous,raw_store_changes_prev=True,converted_store_changes_mark=True))
    converter=(kernel/'net/core/filter.c').read_text().split('case offsetof(struct __sk_buff, mark):',1)[1].split('break;',1)[0]
    assert 'bpf_target_off(struct sk_buff, mark' in converter
    save('context-layout.json',dict(executions=layout,stock_mark_conversion=converter))
    for arch in ('x86','arm64'):
        src=(ROOT/f'kprog/{arch}/trusted_specializer.py').read_text()
        assert 'context_kind(metadata["prog_type"])' in src
    save('context.json',dict(rows=rows,typed=sorted(typed),identity=sorted(identity),
        handler_required=[r['prog_type'] for r in rows if r['category']=='converted'],
        current_source_sha256=sha(ROOT/'kprog/trusted_generation.py'),
        decision='Operator resumes prompt item3 after the recorded421c97bb8 RAW fallback; implemented handlers now select generation.'))


def flags():
    verifier=ROOT/'vendor/linux-framework/kernel/bpf/verifier.c'
    text=verifier.read_text()
    body=text.split('if (insn->imm == BPF_FUNC_get_route_realm)',1)[1].split('/* mark bpf_tail_call',1)[0]
    body='if (insn->imm == BPF_FUNC_get_route_realm)'+body+'}\n'
    c='''#include <linux/bpf.h>
#define MAX_BPF_STACK 512
#define MAX_PACKET_OFF 65535
struct aux { unsigned stack_depth, max_pkt_offset; };
struct prog { unsigned dst_needed, kprobe_override, cb_access; struct aux *aux; };
static unsigned rnd, allow;
static void bpf_user_rnd_init_once(void) { rnd++; }
static int allow_tail_call_in_subprogs(void *env) { return allow; }
void actual_flags(unsigned id, unsigned permitted, unsigned *out) {
 struct aux a={0}; struct prog p={.aux=&a}; struct prog *prog=&p;
 struct bpf_insn i={.imm=id}, *insn=&i; void *env=0; rnd=0; allow=permitted;
'''+body+'''
 out[0]=p.dst_needed; out[1]=rnd; out[2]=p.kprobe_override;
 out[3]=p.cb_access; out[4]=a.stack_depth; out[5]=a.max_pkt_offset;
}
'''
    (TMP/'flags.c').write_text(c)
    run(['cc','-O2','-shared','-fPIC',TMP/'flags.c','-o',TMP/'flags.so'])
    lib=C.CDLL(str(TMP/'flags.so'))
    expected={24:[1,0,0,0,0,0],7:[0,1,0,0,0,0],58:[0,0,1,0,0,0],12:[0,0,0,1,512,65535],0:[0]*6}
    rows=[]
    for helper,want in expected.items():
        out=(C.c_uint*6)(); lib.actual_flags(helper,0,out)
        assert list(out)==want,(helper,list(out),want)
        rows.append(dict(helper=helper,allow_subprogs=0,values=list(out)))
    out=(C.c_uint*6)();lib.actual_flags(12,1,out)
    assert list(out)==[0,0,0,1,0,65535]
    rows.append(dict(helper=12,allow_subprogs=1,values=list(out)))
    main=text[text.rindex('\nint bpf_check('):]
    order=[main.index(s) for s in ('ret = do_check_main(env)','ret = convert_ctx_accesses(env)','ret = do_misc_fixups(env)','ret = fixup_call_args(env)')]
    assert order==sorted(order)
    assert 'restore_kinsn_proof_regions' not in text
    save('flags.json',dict(executions=rows,source_sha256=sha(verifier),main_stage_order=order,
        scope='Executed actual stock helper metadata statements with local program/aux storage; stock pass ordering is a source correspondence check. Kernel attach behavior remains runtime evidence.'))


def tail():
    linker=Path(os.environ.get('KPROG_S8_LINKER',os.environ.get('KPROG_S8_LINKER',str(ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'))))
    plan={'version':1,'helpers':[{'name':'__native_x86_'+k,'addr':v} for k,v in (
        ('bpf_map_max_entries_offset',0),('bpf_array_ptrs_offset',8),('bpf_prog_bpf_func_offset',0),('tail_call_offset',0))]}
    (TMP/'tail-plan.json').write_text(json.dumps(plan))
    records=[]
    for depth,style in ((24,'canonical'),(64,'canonical'),(128,'canonical'),(24,'return-after-cleanup')):
        asm=f'''.intel_syntax noprefix
.text
.global entry
.type entry,@function
entry:
 inc QWORD PTR [rdi]
 sub rsp,{depth}
 mov QWORD PTR [rsp],37
 mov eax,12
 call rax
 cmp QWORD PTR [rsp],37
 jne bad
 mov eax,2
 add rsp,{depth}
 ret
bad:
 xor eax,eax
 add rsp,{depth}
 ret
.size entry,.-entry
.section .note.GNU-stack,"",@progbits
'''
        if style=='return-after-cleanup':
            asm=asm.replace(f' mov eax,2\n add rsp,{depth}',f' add rsp,{depth}\n mov eax,2').replace(f' xor eax,eax\n add rsp,{depth}',f' add rsp,{depth}\n xor eax,eax')
        (TMP/'tail.S').write_text(asm)
        run(['cc','-c',TMP/'tail.S','-o',TMP/'tail.o'])
        run([linker,'--input',TMP/'tail.o','--symbol','entry','--mode','proof','--output',TMP/'tail.proof.o'])
        run([linker,'--input',TMP/'tail.proof.o','--symbol','entry','--mode','kernel','--link-plan',TMP/'tail-plan.json',
             '--output',TMP/'tail.bin','--output-abi',TMP/'tail-abi.json','--output-relocs',TMP/'tail-relocs.bin','--show'])
        abi=dict(line.split('\t',1) for line in (TMP/'tail-abi.json').read_text().splitlines())
        mask=int(abi['callee_saved_mask'])
        regs=['rbx','r13','r14','r15']
        pushes='\n'.join('push '+r for bit,r in enumerate(regs) if mask&(1<<bit))
        pops='\n'.join('pop '+r for bit,r in reversed(list(enumerate(regs))) if mask&(1<<bit))
        wrapper=f'''.intel_syntax noprefix
.text
.global invoke
.type invoke,@function
invoke:
 push rbp
 mov rbp,rsp
 mov rax,rcx
.global tail_entry
tail_entry:
 cmp rsp,rbp
 jne frame_fault
 cmp rax,33
 ja pointer
 push rax
 mov rax,rsp
 jmp ready
pointer:
 push rax
ready:
 push rax
 {pushes}
 .incbin "{TMP/'tail.bin'}"
 {pops}
 leave
 ret
frame_fault:
 mov rsp,rbp
 pop rbp
 mov eax,99
 ret
.size invoke,.-invoke
.section .note.GNU-stack,"",@progbits
'''
        (TMP/'tail-wrapper.S').write_text(wrapper)
        run(['cc','-shared','-fPIC',TMP/'tail-wrapper.S','-o',TMP/'tail-wrapper.so'])
        # A fresh library pathname prevents dlopen caching when the next depth replaces the product.
        process=subprocess.run([sys.executable,str(HERE/'check.py'),'tail-execute',str(depth),style],capture_output=True,text=True)
        with (RAW/'tail-processes.jsonl').open('a') as f:f.write(json.dumps(dict(depth=depth,returncode=process.returncode,stdout=process.stdout,stderr=process.stderr))+'\n')
        process.check_returncode()
        records.extend(json.loads(process.stdout))
    save('tail.json',dict(records=records,linker_sha256=sha(linker),scope='Host execution of current linker kernel-mode bytes, native stacks24/64/128, and a zero-depth JIT-frame wrapper. A fresh tc guest remains separate.'))


def tail_execute(depth,style):
    lib=C.CDLL(str(TMP/'tail-wrapper.so'))
    class Prog(C.Structure): _fields_=[('fn',C.c_void_p)]
    class Map(C.Structure): _fields_=[('max',C.c_uint),('pad',C.c_uint),('target',C.POINTER(Prog))]
    prog=Prog(C.cast(lib.tail_entry,C.c_void_p).value)
    lib.invoke.argtypes=[C.POINTER(C.c_uint64),C.POINTER(Map),C.c_uint64,C.c_uint64]
    lib.invoke.restype=C.c_uint64
    rows=[]
    for start in (0,1,32,33):
        for mode in ('populated','empty','index'):
            count=C.c_uint64()
            m=Map(1,0,C.pointer(prog) if mode!='empty' else C.POINTER(Prog)())
            result=lib.invoke(C.byref(count),C.byref(m),int(mode=='index'),start)
            expected=1 if mode!='populated' else 34-start
            assert result==2 and count.value==expected,(depth,start,mode,result,count.value)
            rows.append(dict(native_depth=depth,style=style,initial_tail_count=start,mode=mode,retval=result,invocations=count.value,transfers=count.value-1,frame_mismatch_observed=False))
    print(json.dumps(rows))


def micro():
    rows=[]
    for arch,opt in (('x86','-O3'),('arm64','-O2')):
        import run_micro_sim_batch as batch
        names=[b.name for b in batch.load_benches(ROOT/'micro/config/micro_pure_jit.yaml')]+['unchecked_packet_read']
        sources=[ROOT/f'kprog/{arch}/micro-prog/{name}.bpf.c' for name in names]
        assert len(sources)==30,(arch,len(sources))
        for source in sources:
            cmd=['clang','-g',opt,'-mcpu=v4','-target','bpf','-mllvm','-bpf-stack-size=4096',
                 '-D__TARGET_ARCH_'+arch,'-I',str(ROOT/'vendor/libbpf/include/uapi'),
                 '-I',str(ROOT/'vendor/libbpf/src'),'-I','/usr/include/x86_64-linux-gnu','-c',str(source),'-o','/dev/null']
            before=sha(source)
            p=subprocess.run(cmd,capture_output=True,text=True)
            row=dict(arch=arch,name=source.stem,command=cmd,returncode=p.returncode,source_sha256=before,
                     source_after_sha256=sha(source),stdout=p.stdout,stderr=p.stderr)
            rows.append(row);save('micro.json',rows)
            print(arch,source.stem,p.returncode,flush=True)
    assert all(r['returncode']==0 for r in rows)


def proposals():
    linker=Path(os.environ.get('KPROG_S8_LINKER',os.environ.get('KPROG_S8_LINKER',str(ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'))))
    rows=[]
    for arch,compiler,asm,vector in (
        ('x86','cc','.intel_syntax noprefix\n.text\n.global entry\n.type entry,@function\nentry:\npxor xmm0,xmm0\nmov eax,2\nret\n.size entry,.-entry\n',bytes.fromhex('660fefc0')),
        ('arm64','aarch64-linux-gnu-gcc','.text\n.global entry\n.type entry,%function\nentry:\nmovi v0.16b,0\nmov w0,2\nret\n.size entry,.-entry\n',bytes.fromhex('00e4004f'))):
        src=TMP/f'simd-{arch}.S';obj=src.with_suffix('.o');proof=TMP/f'simd-{arch}.proof.o'
        src.write_text(asm);run([compiler,'-c',src,'-o',obj])
        run([linker,'--input',obj,'--symbol','entry','--mode','proof','--output',proof])
        from elftools.elf.elffile import ELFFile
        with proof.open('rb') as f: text=ELFFile(f).get_section_by_name('.text').data()
        assert vector in text,(arch,text.hex())
        rows.append(dict(arch=arch,vector_bytes=vector.hex(),retained_in_proof=True,text_bytes=len(text)))
    source=TMP/'hardening.c'
    source.write_text('long jump(long (*f)(long),long x) { return f(x); }\nlong value(long x) { return x+1; }\n')
    for arch,compiler,flags in (
        ('x86','cc',['-mindirect-branch=thunk-extern','-mfunction-return=thunk-extern','-fcf-protection=branch']),
        ('arm64','aarch64-linux-gnu-gcc',['-mbranch-protection=standard'])):
        for policy,extra in (('plain',[]),('hardened',flags)):
            obj=TMP/f'hardening-{arch}.o'
            run([compiler,'-O2','-mgeneral-regs-only',*extra,'-c',source,'-o',obj])
            from elftools.elf.elffile import ELFFile
            with obj.open('rb') as f:
                elf=ELFFile(f);syms=elf.get_section_by_name('.symtab')
                sizes={n:next(s['st_size'] for s in syms.iter_symbols() if s.name==n) for n in ('jump','value')}
                externs=[s.name for s in syms.iter_symbols() if s.name and s['st_shndx']=='SHN_UNDEF']
            rows.append(dict(arch=arch,policy=policy,flags=extra,function_bytes=sizes,externs=externs))
            disasm=run(['objdump' if arch=='x86' else 'aarch64-linux-gnu-objdump','-dr',obj])
            (RAW/f'hardening-{arch}-{policy}.txt').write_text(disasm)
    save('proposals.json',rows)


if __name__=='__main__':
    RAW.mkdir(parents=True,exist_ok=True);TMP.mkdir(parents=True,exist_ok=True)
    mode=sys.argv[1]
    if mode=='tail-execute':tail_execute(int(sys.argv[2]),sys.argv[3])
    elif mode=='host':context();flags();tail();print('context32 / flags6 / tail48 (36 canonical,12 return-after-cleanup) PASS',flush=True)
    elif mode=='context':context()
    elif mode=='micro':micro()
    elif mode=='proposals':proposals()
    elif mode=='tc-guest':
        import threading
        import tempfile
        state=Path(tempfile.mkdtemp(prefix='tc-requests-',dir=RAW))
        service=subprocess.Popen([sys.executable,str(ROOT/'kprog/trusted_service.py'),'--arch','1',
            '--endpoint','/sys/kernel/debug/bpf_x86_native_lab/specializer','--state',str(state),
            '--native-link',os.environ.get('KPROG_S8_LINKER',str(ROOT/'kprog/x86/native_lab/native_link/target/release/native-link')),
            '--loader','/workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader'],
            stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
        log=(state/'service.log').open('w');thread=None
        try:
            line=service.stdout.readline();log.write(line);log.flush();assert json.loads(line)['ready']
            def drain():
                for line in service.stdout:log.write(line);log.flush()
            thread=threading.Thread(target=drain);thread.start()
            inputs=Path(os.environ.get('KPROG_S8_INPUTS',str(TMP)))
            run([inputs/'tc-client',inputs/'tc.bpf.o',inputs/'tc.native.o',
                 os.environ['KPROG_S8_LINKER'],state/'jit.bin'])
        finally:
            service.terminate();service.wait()
            if thread:thread.join()
            log.close()
    elif mode=='safety-guest':
        import types
        import shutil
        source=ROOT/'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/check.py'
        text=source.read_text()
        fixture_import=next(line for line in text.splitlines() if "spec_from_file_location('fixture_data'" in line)
        text=text.replace(fixture_import,'# Runtime replay reads the existing cases.json and compiled inputs.')
        suite=types.ModuleType('s8_safety');suite.__file__=str(source)
        exec(compile(text,str(source),'exec'),suite.__dict__)
        suite.BUILD=ROOT.parent/'.agent-state/kprog-ck/verified-safety'
        import tempfile
        suite.OUT=Path(tempfile.mkdtemp(prefix='safety-final-',dir=RAW))
        suite.loader_build=lambda: ROOT.parent/'.agent-state/kprog-ck/verified-loader'
        suite.native_link=lambda: Path(os.environ['KPROG_S8_LINKER'])
        shutil.copy2(suite.BUILD/'cases.json',suite.OUT/'cases.json')
        suite.check()
    else:raise ValueError(mode)
