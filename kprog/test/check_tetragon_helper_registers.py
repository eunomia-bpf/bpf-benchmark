"""Execute compat helper calls against callees that destroy argument registers."""
import argparse
import ctypes
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]


def execute(library):
    dll = ctypes.CDLL(str(library))
    rows = []
    for arity in range(6):
        function = getattr(dll, 'check'+str(arity))
        function.argtypes, function.restype = [ctypes.c_ulong], ctypes.c_ulong
        for value in range(1,33):
            expected = 2*(11+arity*value+arity*(arity-1)//2)
            actual = function(value)
            if actual != expected:
                raise ValueError(f'arity{arity}: input{value}, actual{actual}, expected{expected}')
        rows.append(dict(arity=arity,cases=32))
    function = dll.check_void
    function.argtypes, function.restype = [ctypes.c_ulong], ctypes.c_ulong
    for value in range(1,33):
        if function(value) != 11+3*value+3:
            raise ValueError('Void helper lost arguments or its callable address')
    rows.append(dict(arity='void3',cases=32))
    print(json.dumps(dict(cases=224,rows=rows)))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--execute',type=Path)
    parser.add_argument('--build',type=Path)
    parser.add_argument('--output',type=Path)
    args = parser.parse_args()
    if args.execute:
        execute(args.execute)
    else:
        args.build.mkdir(parents=True,exist_ok=True)
        args.output.mkdir(parents=True,exist_ok=True)
        library = args.build/'helper-registers.so'
        release = Path('/workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release').read_text().strip()
        answers = ROOT/'vendor/build/native-bpf/x86'/release/'answers/tetragon.h'
        subprocess.run(['clang-18','-O3','-g','-shared','-fPIC','-mno-red-zone',
            '-mgeneral-regs-only','-I'+str(ROOT/'vendor/libbpf/include/uapi'),
            '-D__KPROG_CORE_ANSWERS='+json.dumps(str(answers)),
            ROOT/'kprog/test/tetragon_helper_registers.c','-o',library],check=True)
        result = subprocess.run([sys.executable,__file__,'--execute',str(library)],
                                text=True,capture_output=True)
        (args.output/'stdout.txt').write_text(result.stdout)
        (args.output/'stderr.txt').write_text(result.stderr)
        (args.output/'exit-code.txt').write_text(str(result.returncode)+'\n')
        result.check_returncode()
        (args.output/'result.json').write_text(result.stdout)
        print(result.stdout,end='')
