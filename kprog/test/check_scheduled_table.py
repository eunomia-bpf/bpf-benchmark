"""Execute scheduled table selection through the actual shared simulator and normal B."""
import argparse
import ctypes as c
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]

def main(args):
    args.output.mkdir(parents=True,exist_ok=True)
    sys.path[:0]=[str(ROOT/'kprog'),str(ROOT/'kprog/x86'),str(ROOT/'kprog/x86/micro-prog')]
    import trusted_specializer as worker
    gen=worker.gen
    commands=[]
    def run(command):
        result=subprocess.run(list(map(str,command)),capture_output=True,text=True)
        commands.append(dict(command=list(map(str,command)),returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        result.check_returncode()
    failures=[]
    # Full writes may replace private bases; flag reads and partial bases
    # still observe the removed table arithmetic and must be rejected.
    for name,diagnostic in [('flags','schedule observes or overwrites private results'),
                            ('partial','computation has live register or flag results')]:
        body,functions,exit_addr,data=gen.parse_proof_object_program(name,args.build)
        try:
            gen.render_program('negative_model',body,functions,kind='raw',program_section='kprobe/scheduled',exit_addr=exit_addr,rodata16=data)
        except ValueError as error:
            if diagnostic not in str(error): raise
            failures.append(str(error))
        else: raise ValueError('Observed private table state was removed: '+name)
    observations=[]
    artifacts=[]
    for variant in ('scheduled','base'):
        body,functions,exit_addr,data=gen.parse_proof_object_program(variant,args.build)
        source=gen.render_program('trusted_x86',body,functions,kind='raw',program_section='kprobe/scheduled',exit_addr=exit_addr,rodata16=data,
            source_prelude='''#if !defined(__bpf__) && !defined(__BPF__)
    extern void scheduled_unresolved(void);
    #define __x86_sim_unresolved_indirect_target scheduled_unresolved
    #endif''')
        generated=args.build/(variant+'.bpf.c')
        generated.write_text(source.replace('#include "../x86_sim_local_bpf.h"','#include '+json.dumps(str(ROOT/'kprog/x86/x86_sim_local_bpf.h'))))
        model_object=args.build/(variant+'.bpf.o')
        worker.compile_simulator(str(ROOT/'kprog/stock-path/bin/clang'),generated,model_object,run,bounds_compiler=args.bounds)
        adapter=args.build/'host-input.c'
        adapter.write_text('''#include <stdlib.h>
    void scheduled_unresolved(void) { abort(); }
    /* Fixture choices: zero native SP origin and zero free-input words. */
    unsigned long native_lab_entry_input(unsigned int kind) { if (kind == 1 || kind == 6) return 0; abort(); }
    ''')
        library=args.build/(variant+'-model.so')
        run(['clang-18','-shared','-fPIC','-O2','-w','-I'+str(ROOT/'vendor/libbpf/src'),generated,adapter,'-o',library])
        model=c.CDLL(str(library)).trusted_x86_x86_sim_xdp
        model.argtypes,model.restype=[c.c_void_p],c.c_uint32
        for index in range(64):
            selected=index&7
            expected=(selected+1)*10+10+(11 if variant=='base' else 0) if selected<4 else 0
            actual=model((c.c_uint64*1)(index))
            if actual!=expected:raise ValueError(f'Scheduled table {index}: {actual} != {expected}')
            observations.append(dict(variant=variant,index=index,actual=actual,expected=expected))
        artifacts.append(dict(variant=variant,
            proof_sha256=hashlib.sha256((args.build/(variant+'.proof.o')).read_bytes()).hexdigest(),
            bpf_sha256=hashlib.sha256(model_object.read_bytes()).hexdigest()))
    result=dict(b_compiled=True,shared_simulator_cases=observations,negative_diagnostics=failures,
        compiled_artifacts=artifacts,
        scope='Current native instruction schedule, normal B compiler and full shared simulator; no kernel acceptance or app execution')
    (args.output/'result.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(b_compiled=True,shared_simulator_cases=len(observations),negative_diagnostics=failures)))

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('build','output','bounds'):parser.add_argument('--'+name,type=Path,required=True)
    main(parser.parse_args())
