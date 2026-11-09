from pathlib import Path
import subprocess,json,datetime,hashlib,tarfile,shutil,os,gzip,importlib.util,traceback,collections,io,select,signal,types
R=Path('/workspaces/repository');A=Path('/workspaces/.agent-state/kprog-lanes/A')
J=json.loads(Path('/var/tmp/kprog-tmp/A/publication/collector-handoff-input.json').read_text())['jobs'][int(__import__('sys').argv[1])]
D=Path('/var/tmp/kprog-tmp/A')/J['name'];G=D
O=R/'corpus/results/kprog_arm64_app_coverage_20261109'/('uniform-catalog' if J['name']=='uniform-catalog' else 'scalar-cell-adoption/application')
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def save(phase,**kw):(D/'status.json').write_text(json.dumps(dict(utc=now(),phase=phase)|kw,indent=2)+'\n')
try:
 fd=os.pidfd_open(J['driver']);select.select([fd],[],[]);os.close(fd)
 stat=(Path('/proc')/str(J['driver'])/'stat').read_text().rsplit(')',1)[1].split()
 code=os.waitstatus_to_exitcode(int(stat[49]))
 (D/'driver-exit.json').write_text(json.dumps(dict(utc=now(),driver=J['driver'],wait_status=int(stat[49]),returncode=code,original_collector=J['original_collector']),indent=2)+'\n')
 spec=importlib.util.spec_from_file_location('pub',A/'six-app-publish.py');pub=importlib.util.module_from_spec(spec);spec.loader.exec_module(pub)
 p=guest=types.SimpleNamespace(returncode=code)
 text=(D/'controller.py').read_text()
 if J['name']=='uniform-catalog':start=text.index(" Q=O/'trusted-arm64-service-result'")
 else:start=text.index(" Q=O/'application/trusted-arm64-bcc-result'")
 end=text.index("\nexcept BaseException",start)
 import textwrap
 exec(compile(textwrap.dedent(text[start:end]),str(D/'controller.py')+':terminal','exec'),globals())
 os.kill(J['original_collector'],signal.SIGKILL)
except BaseException as e:
 save('requires_continuation',error=str(e),traceback=traceback.format_exc(),handoff=J)
 raise
