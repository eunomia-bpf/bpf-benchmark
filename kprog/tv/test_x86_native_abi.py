"""Real ELF regression: native body writes must be preserved by the inline ABI."""
import argparse
import json
import subprocess
from pathlib import Path
from elftools.elf.elffile import ELFFile

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('linker', type=Path)
parser.add_argument('output', type=Path)
args = parser.parse_args()
linker = args.linker.resolve()
args.output.mkdir(parents=True, exist_ok=True)
CASES = [
    ('bare_rbx', 'mov rbx,0x123456789abcdef0; mov eax,2; ret', 1),
    ('bare_ebx', 'mov ebx,17; mov eax,2; ret', 1),
    ('bare_bl', 'mov bl,17; mov eax,2; ret', 1),
    ('bare_bh', 'mov bh,17; mov eax,2; ret', 1),
    ('bare_bx', 'mov bx,17; mov eax,2; ret', 1),
    ('bare_r13', 'mov r13,17; mov eax,2; ret', 2),
    ('bare_r14', 'mov r14,17; mov eax,2; ret', 4),
    ('bare_r15', 'mov r15,17; mov eax,2; ret', 8),
    ('all_four', 'mov ebx,1; mov r13d,2; mov r14d,3; mov r15d,4; mov eax,2; ret', 15),
    ('conditional_rbx', 'test edi,edi; je 1f; mov ebx,17; 1: mov eax,2; ret', 1),
    ('implicit_cpuid', 'cpuid; mov eax,2; ret', 1),
    ('read_rbx', 'mov rax,rbx; ret', 0),
    ('caller_saved', 'mov eax,2; ret', 0),
    ('stripped_save', 'push rbx; mov ebx,17; mov eax,2; pop rbx; ret', 1),
]

def command(argv, log):
    done = subprocess.run([str(x) for x in argv], stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    log.write_bytes(done.stdout)
    return done

def metadata(path):
    with path.open('rb') as stream:
        section = ELFFile(stream).get_section_by_name('.native_link_abi')
        if section is None:
            raise ValueError('missing producer ABI section')
        text = section.data().decode()
    return dict(line.split('\t', 1) for line in text.splitlines())

rows=[]
for name, assembly, mask in CASES:
    directory = args.output/name
    directory.mkdir(parents=True, exist_ok=True)
    source = directory/'entry.S'
    source.write_text('.intel_syntax noprefix\n.text\n.global entry\n.type entry,@function\nentry:\n'+
        assembly.replace('; ', '\n')+'\n.size entry,.-entry\n')
    subprocess.run(['cc','-c',source,'-o',directory/'entry.native.o'],check=True)
    proof = directory/'entry.proof.o'
    done = command([linker,'--input',directory/'entry.native.o','--symbol','entry','--mode','proof',
        '--output',proof],directory/'proof.log')
    if done.returncode:
        raise RuntimeError('proof producer failed: '+name+'\n'+done.stdout.decode())
    actual = int(metadata(proof)['callee_saved_mask'])
    if actual != mask:
        raise AssertionError(f'{name}: actual native writes need {mask:#x}, producer emitted {actual:#x}')
    def kernel(input, suffix):
        return command([linker,'--input',input,'--symbol','entry','--mode','kernel',
            '--output',directory/(suffix+'.bin'),'--output-relocs',directory/(suffix+'.relocs'),
            '--output-abi',directory/(suffix+'.abi')], directory/(suffix+'.log'))
    done = kernel(proof, 'kernel')
    if done.returncode:
        raise RuntimeError('kernel link failed: '+name+'\n'+done.stdout.decode())
    sideband = dict(line.split('\t',1) for line in (directory/'kernel.abi').read_text().splitlines())
    if int(sideband['callee_saved_mask']) != mask:
        raise AssertionError('kernel output overrode actual ABI: '+name)
    if mask:
        altered = directory/'cleared.abi'
        altered.write_text('version\tnative-link-abi-v2\ncallee_saved_mask\t0\n')
        forged = directory/'cleared.proof.o'
        subprocess.run(['objcopy','--update-section','.native_link_abi='+str(altered),proof,forged],check=True)
        rejected = kernel(forged, 'cleared')
        if not rejected.returncode or b'omits native writes' not in rejected.stdout:
            raise AssertionError('cleared proof ABI metadata accepted: '+name)
        altered.write_text('version\tnative-link-abi-v2\ncallee_saved_mask\t15\n')
        larger = directory/'superset.proof.o'
        subprocess.run(['objcopy','--update-section','.native_link_abi='+str(altered),proof,larger],check=True)
        if kernel(larger, 'superset').returncode:
            raise AssertionError('sound declared superset rejected: '+name)
    rows.append(dict(name=name, assembly=assembly, callee_saved_mask=mask,
        proof='passed', kernel='passed', cleared_metadata='rejected' if mask else 'not_applicable'))
    print(f'{name}: proof/kernel ABI={mask:#x}; '+('cleared metadata REJECTED' if mask else 'read-only/control retains zero'),flush=True)
# The whole reachable native image contributes, including a non-entry callee.
nested=args.output/'reachable_callee';nested.mkdir(parents=True,exist_ok=True)
(nested/'entry.S').write_text('''.intel_syntax noprefix
.text
.global entry
.type entry,@function
entry: call leaf
mov eax,2
ret
.size entry,.-entry
.type leaf,@function
leaf: mov r13,17
ret
.size leaf,.-leaf
''')
subprocess.run(['cc','-c',nested/'entry.S','-o',nested/'entry.native.o'],check=True)
done=command([linker,'--input',nested/'entry.native.o','--symbol','entry','--mode','proof',
    '--output',nested/'entry.proof.o'],nested/'proof.log')
if done.returncode or int(metadata(nested/'entry.proof.o')['callee_saved_mask']) != 2:
    raise AssertionError('non-entry callee clobber omitted')
rows.append(dict(name='reachable_callee',callee_saved_mask=2,proof='passed'))
print('reachable callee: ABI=0x2 PASS',flush=True)
(args.output/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
print('actual ELF native ABI preservation:15 cases PASS;12 cleared metadata REJECTED',flush=True)
