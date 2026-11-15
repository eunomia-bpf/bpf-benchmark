"""Resume an owned paused compiler after timing, holding work/image leases.

pidfds preserve the explicitly supplied process identities. The lease lasts
until the existing Make launcher exits, including its later backend stages.
"""
import argparse
from datetime import datetime, timezone
import fcntl
import json
import os
from pathlib import Path
import select
import signal


def main(a):
    a.output.mkdir(parents=True,exist_ok=True)
    record=dict(compiler=a.compiler,launcher=a.launcher,events=[])
    def event(name):
        record['events'].append(dict(event=name,time=datetime.now(timezone.utc).isoformat()))
        (a.output/'events.json').write_text(json.dumps(record,indent=2)+'\n')
    compiler=os.pidfd_open(a.compiler)
    launcher=os.pidfd_open(a.launcher)
    try:
        event('waiting-for-timing-work-lease')
        with a.timing.open('a') as timing, a.image.open('a') as image:
            fcntl.flock(timing.fileno(),fcntl.LOCK_SH)
            event('timing-work-lease-acquired')
            fcntl.flock(image.fileno(),fcntl.LOCK_SH)
            event('image-shared-lease-acquired')
            if select.select([compiler],[],[],0)[0]:
                event('compiler-already-exited')
            else:
                signal.pidfd_send_signal(compiler,signal.SIGCONT)
                event('compiler-resumed')
            while not select.select([launcher],[],[],60)[0]:
                pass
            event('make-launcher-exited')
        event('leases-released')
    finally:
        os.close(compiler)
        os.close(launcher)


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('compiler','launcher'):p.add_argument('--'+name,type=int,required=True)
    for name in ('timing','image','output'):p.add_argument('--'+name,type=Path,required=True)
    main(p.parse_args())
