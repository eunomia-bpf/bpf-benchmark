"""Exercise the existing kernel-compatible lifter before anonymous app integration."""
import ctypes
import json
from pathlib import Path
import re
import subprocess
import sys
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
OUT=HERE/'bpf-lift';OUT.mkdir(exist_ok=True)
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
import generate_micro_sim_proofs as gen
sys.path.insert(0,str(ROOT/'kprog'))
from helper_abi import helper_idents
CASES={'zero':0,'one':1,'clock':1}
def run(command):
    command=[str(arg) for arg in command]
    result=subprocess.run(command,text=True,capture_output=True,timeout=120)
    row=dict(command=command,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr)
    with (OUT/'commands.jsonl').open('a') as stream:stream.write(json.dumps(row)+'\n')
    if result.returncode:raise RuntimeError(row)
    return result
if sys.argv[1]=='prepare':
    (OUT/'source.bpf.c').write_text('''#include <linux/bpf.h>
#include <bpf_helpers.h>
SEC("xdp") int runtime_probe(struct xdp_md *ctx) {
#ifdef CLOCK
    return bpf_ktime_get_ns()!=0;
#else
    return VALUE;
#endif
}
char LICENSE[] SEC("license")="GPL";
''')
elif sys.argv[1]=='generate':
    for name in CASES:
        source=OUT/(name+'.source.bpf.o')
        with source.open('rb') as stream:
            elf=ELFFile(stream);bytecode=elf.get_section_by_name('xdp').data()
        raw=OUT/(name+'.bpf.bin');raw.write_bytes(bytecode)
        ir=OUT/(name+'.ll');optimized=OUT/(name+'.opt.ll')
        run([HERE/'lift-bpf-ir',raw,ir])
        def canonical(match):
            number=int(match[1]);names=helper_idents()
            if number not in names:raise ValueError(f'no Linux helper declaration for {number}')
            return names[number]
        ir.write_text(re.sub(r'_bpf_helper_ext_([0-9]+)',canonical,ir.read_text()))
        run(['opt-18','-O3','-S',ir,'-o',optimized])
        case=OUT/name;case.mkdir(exist_ok=True)
        native=case/(name+'.native.o')
        run(['llc-18','-mtriple=x86_64-pc-linux-gnu','-mcpu=x86-64','-filetype=obj','-O=3',
            '-relocation-model=pic',optimized,'-o',native])
        if name in {'zero','one'}:
            shared=OUT/(name+'.so');run(['cc','-shared',native,'-o',shared])
            function=ctypes.CDLL(str(shared)).bpf_main
            function.argtypes=[ctypes.c_void_p];function.restype=ctypes.c_uint64
            observed=function(None)
            if observed!=CASES[name]:raise RuntimeError((name,observed))
            print('actual CPU',name,observed,flush=True)
        # This is the exact native object used for both proof and kernel linking.
        proof=case/'bpf_main.proof.o'
        run([HERE/'native-dispatch-link/release/native-link','--input',native,'--symbol','bpf_main',
            '--mode','proof','--preserve-entry-abi','--output',proof])
        insns,subs,end,data=gen.parse_proof_object_program('bpf_main',case)
        text=gen.render_program(name,insns,subs,'raw',exit_addr=end,rodata16=data,program_section='xdp')
        (OUT/(name+'.bpf.c')).write_text(text.replace('#include "../x86_sim_local_bpf.h"',
            f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"'))
        socket_text=gen.render_program(name+'_socket',insns,subs,'raw',exit_addr=end,
            rodata16=data,program_section='socket')
        (OUT/(name+'.socket.bpf.c')).write_text(socket_text.replace('#include "../x86_sim_local_bpf.h"',
            f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"'))
        manifest=dict(objects=[dict(program='runtime_probe',native_object=str(native),symbol='bpf_main',
            simulator_object=str(OUT/(name+'.bpf.o')),simulator_program=name+'_x86_sim_xdp')])
        (OUT/(name+'.manifest.json')).write_text(json.dumps(manifest,indent=2)+'\n')
elif sys.argv[1]=='bound':
    for name,expected in CASES.items():
        files=[OUT/(name+'.bpf.bin'),OUT/(name+'.source.bpf.o'),
            OUT/name/(name+'.native.o'),OUT/name/'bpf_main.proof.o',OUT/(name+'.bpf.o')]
        (OUT/(name+'.inputs.json')).write_text(json.dumps({str(path):dict(size=path.stat().st_size)
            for path in files},indent=2)+'\n')
        result=run([HERE/'raw-context/bound-probe',OUT/(name+'.source.bpf.o'),
            OUT/(name+'.manifest.json'),0,expected])
        (OUT/(name+'.bound.json')).write_text(json.dumps(dict(stdout=result.stdout,stderr=result.stderr),indent=2)+'\n')
        print(name,result.stdout,result.stderr,flush=True)
else:raise SystemExit('expected prepare, generate or bound')
