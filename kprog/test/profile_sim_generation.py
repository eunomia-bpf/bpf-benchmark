"""Report the live analysis worklist while replaying a retained request."""
import faulthandler
from pathlib import Path
import runpy
import signal
import sys


def snapshot(signum, frame):
    faulthandler.dump_traceback()
    while frame is not None:
        if frame.f_code.co_name == 'check_definedness':
            values = frame.f_locals
            state = values.get('incoming')
            print(dict(states=len(values['states']), pending=len(values['queue']),
                       addr=values.get('addr'), lowest_stack=values['lowest_stack'],
                       opaque=len(state.opaque), pointers=len(state.pointers),
                       instruction=values['insn'].raw,
                       alias_alternatives=[dict(register=values['regs'][i], count=len(a.offsets),
                           lowest=min(a.offsets) if a.offsets else None,
                           highest=max(a.offsets) if a.offsets else None, external=a.external)
                           for i,a in enumerate(state.aliases) if hasattr(a, 'offsets')]),
                  file=sys.stderr, flush=True)
            break
        frame = frame.f_back


signal.signal(signal.SIGALRM, snapshot)
signal.setitimer(signal.ITIMER_REAL, 15, 15)
runpy.run_path(str(Path(__file__).with_name('replay_relative_schedule.py')), run_name='__main__')
