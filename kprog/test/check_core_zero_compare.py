"""Catch widened-field comparisons using C width instead of original BPF width."""
import argparse
import json
from pathlib import Path
import re
import subprocess
from audit_core_objects import ROOT, records


def main(args):
    args.build.mkdir(parents=True, exist_ok=True)
    args.output.mkdir(parents=True, exist_ok=True)
    commands=[]
    compiler=args.compiler
    source=args.build/'zero.bc'
    original=args.build/'zero.bpf.o'
    resolved=args.build/'zero.resolved.bc'

    def run(command, *, expected=0, keep_stdout=True):
        command=[str(v) for v in command]
        result=subprocess.run(command,cwd=ROOT,text=True,capture_output=True)
        commands.append(dict(command=command,returncode=result.returncode,
                             stdout=result.stdout if keep_stdout else None,
                             stdout_bytes=len(result.stdout),stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if result.returncode != expected:
            raise ValueError('Unexpected command status: '+str(commands[-1]))
        return result

    def frontend(fixture, *flags):
        run(['clang-18','-target','bpf','-O2','-g','-I/usr/include/x86_64-linux-gnu',
             *flags,'-emit-llvm','-c',fixture,'-o',source])
        run(['clang-18','-target','bpf','-O2','-g',*flags,'-c',source,'-o',original])

    def resolve(report, flags=(), expected=0):
        return run([compiler,source,'--local-bpf',original,'--target-btf',args.target,
                    '--report',report,'-o',resolved,*flags],expected=expected)

    if not args.kernel:
        # The old binary runs first. The source is rebuilt in the SAME product
        # location only after its baseline output has been retained in memory.
        baseline=[]
        fixtures=['test-core-ir.c','test-core-ir-ids.c']
        for fixture in fixtures:
            frontend(ROOT/'kprog/build'/fixture)
            report=args.output/'default.json';resolve(report)
            baseline.append((resolved.read_bytes(),report.read_bytes()))
        frontend(ROOT/'kprog/test/core_zero_compare.c')
        error=resolve(args.output/'disabled-before.json',expected=1)
        if 'native scalar access resizing remains required' not in error.stderr:
            raise ValueError('Old compiler did not exercise the widening rejection')
        disabled=(args.output/'disabled-before.json').read_bytes()
        run(['make','-f',ROOT/'kprog/test/core-audit.mk','core-compiler'])
        parity=[]
        for fixture,old in zip(fixtures,baseline):
            frontend(ROOT/'kprog/build'/fixture)
            report=args.output/'default.json';resolve(report)
            if (resolved.read_bytes(),report.read_bytes()) != old:
                raise ValueError('Default bitcode or report changed for '+fixture)
            parity.append(dict(fixture=fixture,bitcode_equal=True,report_equal=True))
        frontend(ROOT/'kprog/test/core_zero_compare.c')
        resolve(args.output/'disabled-after.json',expected=1)
        if (args.output/'disabled-after.json').read_bytes()!=disabled:
            raise ValueError('Disabled widening diagnostics changed')
        frontend(ROOT/'kprog/test/core_zero_compare.c','-DCOMPARE_NONZERO=1')
        error=resolve(args.output/'unsupported.json',['--widen-zero-compare'],expected=1)
        if 'native scalar access resizing remains required' not in error.stderr:
            raise ValueError('Nonzero comparison did not retain its explicit unsupported diagnostic')
        (args.output/'result.json').write_text(json.dumps(dict(default_parity=parity,
            disabled_rejection_unchanged=True,nonzero_comparison_still_explicit_error=True),indent=2)+'\n')
        return

    results=[]
    for cpu in ['v2','v3','v4']:
        for ne in [0,1]:
            name=cpu+('-ne' if ne else '-eq');out=args.output/name;out.mkdir()
            frontend(ROOT/'kprog/test/core_zero_compare.c','-mcpu='+cpu,'-DCOMPARE_NE='+str(ne))
            resolve(out/'compiler.json',['--widen-zero-compare'])
            blob=args.build/'zero.patched.bin'
            ref=run([args.build/'core-reference',original,args.target,'--patch-output',blob])
            (out/'reference.tsv').write_text(ref.stdout)
            rows=records(out/'reference.tsv')
            if len(rows)!=1 or rows[0]['original_bytes']!='2' or rows[0]['target_bytes']!='8':
                raise ValueError('Fixture did not patch an actual u16->u64 load')
            ir=run(['llvm-dis-18',resolved,'-o','-'],keep_stdout=False).stdout
            ir=re.sub(r'"target-(?:cpu|features)"="[^"]*"\s*','',ir)
            native_ir=args.build/'zero.native.ll';native_ir.write_text(ir)
            native=args.build/'zero.native.so'
            run(['clang-18','-target','x86_64-linux-gnu','-O2','-fPIC','-shared',native_ir,'-o',native])
            disassembly=run(['llvm-objdump-18','-d',native]).stdout
            (out/'native.disassembly').write_text(disassembly)
            execution=run([args.client,blob,native,rows[0]['resolved']])
            case=json.loads(execution.stdout)
            case.update(cpu=cpu,predicate='ne' if ne else 'eq',
                        compiler_rows=json.loads((out/'compiler.json').read_text()))
            results.append(case)
            (out/'result.json').write_text(json.dumps(case,indent=2)+'\n')
    (args.output/'result.json').write_text(json.dumps(dict(cases=results,
        total_executions=sum(r['executions'] for r in results),
        scope='Original ELF/libbpf-patched BPF on sole kernel versus emitted native IR code in userspace.'),indent=2)+'\n')


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ['build','output','target']:
        parser.add_argument('--'+name,type=Path,required=True)
    parser.add_argument('--kernel',action='store_true')
    parser.add_argument('--compiler',type=Path,default=Path('/var/tmp/kprog-tmp/perf/core-ir/core-ir-lower'))
    parser.add_argument('--client',type=Path)
    main(parser.parse_args())
