"""Compile the real helper-memory regression for execution by the stock kernel."""
import argparse
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'kprog/x86'))
import trusted_specializer as worker
from memory_b_pipeline import MemoryPipeline


def main(a):
    a.build.mkdir(parents=True, exist_ok=True)
    a.output.mkdir(parents=True, exist_ok=True)
    commands = []
    pipe = MemoryPipeline()

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True,
                                pass_fds=tuple(pipe.fds))
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (a.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()
        return result

    try:
        clang = str(ROOT/'kprog/stock-path/bin/clang')
        before = pipe.stage('.bounds-input.bc')
        run([clang, *worker.COMPILE_FLAGS, '-emit-llvm', '-c',
             ROOT/'kprog/test/b_helper_memory.bpf.c', '-o', before])
        after = pipe.stage('.bounds.bc')
        result = run([a.tool, before, '-o', after])
        if 'helper memory contracts described=4' not in result.stderr:
            raise ValueError('Expected lookup, faulting user read and two kernel reads')
        ir = run(['llvm-dis-18', after, '-o', '-']).stdout
        reads = [line for line in ir.splitlines()
                 if 'call i64 inttoptr (i64 11' in line]
        if len(reads)!=3 or any(line.count('nocapture')!=2 or
                               ' readonly ' not in line or ' writeonly ' not in line
                               for line in reads):
            raise ValueError('Helper input/output memory contract missing')
        outputs = []
        for label, source in [('original', before), ('normalized', after)]:
            def backend(command):
                command = list(map(str, command))
                if command[0].endswith('/clang'):
                    command[1:1] = ['-x', 'ir']
                elif command[0] == 'llc-18':
                    command[1:1] = ['-x=mir']
                elif len(command)>1 and command[1] == str(ROOT/'kprog/x86/whole_word_spills.py'):
                    command.extend(['--report', str(a.output/(label+'-lowering.json'))])
                return run(command)
            destination = a.build/(label+'.o')
            worker._compile_simulator_backend(clang, pipe, destination, backend,
                                               compiled_input=source)
            outputs.append(dict(variant=label, object=str(destination),
                                bytes=destination.stat().st_size))
        (a.output/'compile.json').write_text(json.dumps(dict(objects=outputs,
            helper_contracts=4, scope='Compilation only; kernel execution is separate.'), indent=2)+'\n')
    finally:
        pipe.close()


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    for name in ('tool', 'build', 'output'):
        p.add_argument('--'+name, type=Path, required=True)
    main(p.parse_args())
