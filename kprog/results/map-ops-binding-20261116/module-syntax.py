"""Use the sole saved module compiler command without rebuilding the image."""
import pathlib
import shlex
import subprocess

root = pathlib.Path('/workspaces/repository')
build = pathlib.Path('/workspaces/.agent-state/kprog-ck/verified-module')
saved = (build / '.kprog_stock.o.cmd').read_text().splitlines()[0]
args = shlex.split(saved.split(':=', 1)[1])
command = []
skip = False
for arg in args:
    if arg == ';':
        break
    if skip:
        skip = False
    elif arg == '-o':
        skip = True
    elif arg != '-c' and not arg.startswith('-Wp,-MMD,') and not arg.endswith('.c'):
        command.append(arg)
for source in ['kprog/stock-path/module/kprog_stock.c',
               'kprog/perf/direct-native/bpf_x86_native_lab.c']:
    print(source, flush=True)
    # The direct module's Kbuild supplies this include directory.
    includes = [] if source.startswith('kprog/stock-path') else ['-I' + str(root / 'kinsn/module/include')]
    subprocess.run(command[:1] + includes + command[1:] +
                   ['-fsyntax-only', str(root / source)], cwd=build, check=True)
