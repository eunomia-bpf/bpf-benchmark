"""Check that opting into zero comparisons leaves a retained real compiler input unchanged."""
import argparse
import json
from pathlib import Path
import subprocess


def main(args):
    args.output.mkdir(parents=True,exist_ok=True)
    results=[]
    controls=[]
    for enabled in [False,True]:
        report=args.output/('enabled.json' if enabled else 'default.json')
        command=[str(args.compiler),str(args.input),'--local-bpf',str(args.local),
                 '--target-btf',str(args.target),'--report',str(report),'-o','-']
        if enabled:command.append('--widen-zero-compare')
        result=subprocess.run(command,capture_output=True)
        results.append(dict(command=command,returncode=result.returncode,
                            stderr=result.stderr.decode(),bitcode_bytes=len(result.stdout)))
        (args.output/'commands.json').write_text(json.dumps(results,indent=2)+'\n')
        result.check_returncode()
        controls.append(result.stdout)
    if controls[0]!=controls[1]:
        raise ValueError('Optional zero-compare mode changed the control input bitcode')
    rows=json.loads((args.output/'enabled.json').read_text())
    (args.output/'result.json').write_text(json.dumps(dict(input=str(args.input),local_bpf=str(args.local),
        bitcode_bytes=len(controls[0]),default_enabled_bitcode_equal=True,queries=len(rows),
        zero_comparison_rewrites=sum(r['native_zero_comparisons'] for r in rows),
        scope='Retained real source compiler input; no native app installation or execution.'),indent=2)+'\n')


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ['compiler','input','local','target','output']:
        parser.add_argument('--'+name,type=Path,required=True)
    main(parser.parse_args())
