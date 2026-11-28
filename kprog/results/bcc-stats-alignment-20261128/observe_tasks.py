"""Read-only guest task CPU/wait snapshots; no BPF loads, map/code copying or sysctls."""
from pathlib import Path
import json,os,sys,time
OUT=Path(sys.argv[1]);PROC=Path('/proc');tools={'capable','biosnoop','vfsstat','opensnoop','syscount','tcpconnect','tcplife','runqlat'}
def read(p):
 try:return p.read_text()
 except OSError as e:return dict(errno=e.errno)
with OUT.open('x') as f:
 f.write(json.dumps(dict(kind='header',observer_pid=os.getpid(),clock_ticks=os.sysconf('SC_CLK_TCK'),boot_id=read(PROC/'sys/kernel/random/boot_id'),scope='All task stat/schedstat/wchan; extra stack/status/io for stress-ng and unchanged BCC tools. Read failures stay explicit; no scheduler/affinity/config writes.'))+'\n');f.flush()
 while True:
  row=dict(kind='snapshot',monotonic=time.monotonic(),uptime=read(PROC/'uptime'),cpu_stat=read(PROC/'stat'),cpu_pressure=read(PROC/'pressure/cpu'),observer_cpu=list(os.times()),tasks=[])
  for p in sorted(PROC.iterdir(),key=lambda p:p.name):
   if not p.name.isdigit():continue
   comm=read(p/'comm')
   if not isinstance(comm,str):continue
   name=comm.strip();task=dict(pid=int(p.name),comm=name,stat=read(p/'stat'),schedstat=read(p/'schedstat'),wchan=read(p/'wchan'))
   if name.startswith('stress-ng') or name in tools:task.update(stack=read(p/'stack'),status=read(p/'status'),io=read(p/'io'))
   row['tasks'].append(task)
  f.write(json.dumps(row)+'\n');f.flush();time.sleep(0.5)
