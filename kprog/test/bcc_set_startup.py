"""Run the existing eight-tool BCC functional startup under a registered service.

This is a diagnostic using unchanged corpus tool commands, not a benchmark.
The service supervisor owns compilation, kernel requests and evidence archival.
"""
import argparse
import json
import os
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]

def run_bcc_set(live,environment):
    # Reuse the unchanged corpus tool list, arguments and startup/stop paths.
    os.environ.update(environment)
    os.environ['BPFTOOL_BIN']=str(ROOT/'vendor/build/x86/bpftool/bin/bpftool')
    sys.path.insert(0,str(ROOT))
    from runner.libs.app_runners.bcc_set import BccSetRunner,BCC_SET_TOOL_SPECS
    from runner.libs.agent import bpftool_prog_show_records
    from runner.libs.rejit import wait_for_app_shim_programs
    runner=BccSetRunner(tool_binaries={s.name:ROOT/'vendor/build/x86/bcc/bin'/s.name for s in BCC_SET_TOOL_SPECS},
                        workload_spec={'kind':'stress_ng_bcc_hook_hot'})
    Path('/proc/sys/kernel/bpf_stats_enabled').write_text('1'+chr(10))
    try:
        # Coverage must observe the other tools even when one tool fails. Use
        # their existing spawn/readiness paths and preserve the frozen commands.
        startup={}
        for spec in BCC_SET_TOOL_SPECS:
            try:runner._spawn_child(runner._children[spec.name])
            except Exception as error:startup[spec.name]=dict(ready=False,error=str(error))
        for spec in BCC_SET_TOOL_SPECS:
            if spec.name in startup:continue
            child=runner._children[spec.name]
            try:
                wait_for_app_shim_programs(app_pid=int(child.session.process.pid),
                    process=child.session.process,
                    snapshot=lambda child=child:runner._child_output_snapshot(child),
                    process_name='BCC tool '+spec.name)
                startup[spec.name]=dict(ready=True)
            except Exception as error:startup[spec.name]=dict(ready=False,error=str(error))
        (live/'tool-startup.json').write_text(json.dumps(startup,indent=2))
        (live/'programs-after-startup.json').write_text(json.dumps(bpftool_prog_show_records(),indent=2))
        failures=[name for name,result in startup.items() if not result['ready']]
        if failures:raise RuntimeError('BCC tools failed startup: '+', '.join(failures))
        (live/'programs-before-work.json').write_text(json.dumps(bpftool_prog_show_records(),indent=2))
        completed=0
        for _ in range(10000):
            with open('/dev/null','wb') as output:output.write(b'x')
            completed+=1
        (live/'functional-work.json').write_text(json.dumps(dict(opens_completed=completed,writes_completed=completed,closes_completed=completed)))
        (live/'programs-after-work.json').write_text(json.dumps(bpftool_prog_show_records(),indent=2))
    finally:
        try:runner.stop()
        finally:
            (live/'runner.json').write_text(json.dumps(dict(output=runner.process_output,
                tools={name:dict(command=child.command_used,output=child.process_output) for name,child in runner._children.items()}),indent=2))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    run_bcc_set(args.output, dict(os.environ))
