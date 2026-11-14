#!/usr/bin/env python3
"""Replay a retained Cilium BPF compile using unchanged canonical upstream source."""
import argparse
import hashlib
import json
from pathlib import Path
import shlex
import subprocess


def feature_flags(headers, output):
    """Use Clang itself to interpret upstream-generated capability macros."""
    base=['clang-18','-target','bpf','-undef','-dM','-E','-x','c','-']
    commands=[base,base+sum((['-include',str(path)] for path in headers),[])]
    results=[]
    for label,command in zip(['features-base','features'],commands):
        result=subprocess.run(command,input='',capture_output=True,text=True)
        output.with_suffix('.'+label+'.stdout').write_text(result.stdout)
        output.with_suffix('.'+label+'.stderr').write_text(result.stderr)
        result.check_returncode()
        results.append(dict(line[len('#define '):].split(' ',1) if ' ' in line[len('#define '):]
                            else (line[len('#define '):],'') for line in result.stdout.splitlines()))
    before,after=results
    flags=['-U'+name for name in before.keys()-after.keys()]
    flags += ['-D'+name+'='+value for name,value in after.items() if before.get(name)!=value]
    record=dict(commands=commands,headers=[dict(path=str(path),sha256=hashlib.sha256(path.read_bytes()).hexdigest()) for path in headers],flags=flags)
    output.with_suffix('.feature-defines.json').write_text(json.dumps(record,indent=2)+'\n')
    return flags,record


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--capture', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--state-root', type=Path)
    parser.add_argument('--state-object', type=Path)
    parser.add_argument('--feature-header', type=Path, action='append', default=[])
    args = parser.parse_args()
    if bool(args.state_root) != bool(args.state_object):
        parser.error('--state-root and --state-object are supplied together')
    record = json.loads((args.capture/'parity.json').read_text())
    repo = Path(__file__).resolve().parents[3]
    upstream = repo/'vendor/repos/cilium/bpf'
    original = record['bpf_command']
    state_object = args.state_root/args.state_object if args.state_root else None
    command = ['clang-18']
    sources = []
    i = 1
    while i < len(original):
        flag = original[i]
        if flag == '-o':
            command += ['-o', str(args.output.with_suffix('.bc'))]
            i += 2
            continue
        if flag.startswith('-I/var/lib/cilium/bpf'):
            flag = '-I'+str(upstream)+flag[len('-I/var/lib/cilium/bpf'):]
        elif flag.startswith('-I/var/tmp/'):
            # Use the original include ordering; endpoint templates stay separate.
            if args.state_root:
                directory = args.state_root/'state/globals' if flag.endswith('/globals') else state_object.parent
            else:
                directory = args.capture/'live-headers'
            flag = '-I'+str(directory)
        elif flag.startswith('/var/lib/cilium/bpf/') and flag.endswith('.c'):
            path = upstream/flag[len('/var/lib/cilium/bpf/'):]
            sources.append(dict(path=str(path), sha256=hashlib.sha256(path.read_bytes()).hexdigest()))
            flag = str(path)
        command.append(flag)
        i += 1
    command.append('-emit-llvm')
    if args.state_root:
        command += ['-MD', '-MF', str(args.output.with_suffix('.d'))]
    args.output.parent.mkdir(parents=True, exist_ok=True)
    features=None
    if args.feature_header:
        flags,features=feature_flags(args.feature_header,args.output)
        command += flags
    receipt = dict(capture=str(args.capture), original_command=original,
                   replay_command=command, sources=sources)
    if features is not None: receipt['generated_features']=features
    if not args.state_root:
        receipt['configuration']=[dict(path=str(args.capture/h['archive']),
                                       retained_sha256=h['sha256'],
                                       replay_path=str(args.capture/'live-headers'/Path(h['source']).name),
                                       replay_sha256=hashlib.sha256((args.capture/'live-headers'/Path(h['source']).name).read_bytes()).hexdigest())
                                  for h in record['headers']]
    else:
        receipt['runtime_object']=dict(path=str(state_object),sha256=hashlib.sha256(state_object.read_bytes()).hexdigest())
        receipt['flag_provenance']='Retained BPF command template; current generated state; validate against captured original ELF.'
    result = subprocess.run(command, capture_output=True, text=True)
    args.output.with_suffix('.stdout').write_text(result.stdout)
    args.output.with_suffix('.stderr').write_text(result.stderr)
    receipt['returncode'] = result.returncode
    direct_result = None
    if args.state_root and result.returncode == 0:
        dependencies = shlex.split(args.output.with_suffix('.d').read_text().replace('\\\n','').split(':',1)[1])
        receipt['dependencies']=[dict(path=path,sha256=hashlib.sha256(Path(path).read_bytes()).hexdigest()) for path in dependencies]
        receipt['configuration']=[item for item in receipt['dependencies'] if Path(item['path']).is_relative_to(args.state_root)]
        # A second -O2 pipeline over saved IR can change BPF instruction layout.
        # Also retain the original one-shot source->BPF path for byte comparison.
        direct = command.copy()
        direct.remove('-emit-llvm')
        direct[direct.index('-o')+1]=str(args.output.with_suffix('.direct.bpf.o'))
        direct[direct.index('-MF')+1]=str(args.output.with_suffix('.direct.d'))
        direct_result=subprocess.run(direct,capture_output=True,text=True)
        args.output.with_suffix('.direct.stdout').write_text(direct_result.stdout)
        args.output.with_suffix('.direct.stderr').write_text(direct_result.stderr)
        receipt['direct_bpf']=dict(command=direct,returncode=direct_result.returncode)
    args.output.with_suffix('.json').write_text(json.dumps(receipt, indent=2)+'\n')
    result.check_returncode()
    if direct_result is not None: direct_result.check_returncode()


if __name__ == '__main__':
    main()
