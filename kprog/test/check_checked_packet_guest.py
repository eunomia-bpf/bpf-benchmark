"""Run packet cases independently and retain actual verifier-before-compile refusal."""
import io
import json
from pathlib import Path
import subprocess
import sys
import tarfile

output=Path(sys.argv[1])
root=Path(__file__).resolve().parents[2]
rows=[]
for case in ['xdp','tc','reject']:
    directory=output/case
    directory.mkdir()
    command=['make','-C',str(root/'kprog/libnativeloader'),'guest-checked-packet-case',
        'CHECKED_PACKET_KERNEL_OUTPUT='+str(output),'CHECKED_PACKET_CASE='+case]
    result=subprocess.run(command,capture_output=True,text=True)
    (directory/'stdout').write_text(result.stdout)
    (directory/'stderr').write_text(result.stderr)
    record=dict(case=case,command=command,make_exit=result.returncode)
    try:
        result.check_returncode()
        if case=='reject':
            with tarfile.open(directory/'service.tar.gz') as service:
                failure=next(m for m in service.getmembers() if m.name.endswith('.failure.tar.gz'))
                with tarfile.open(fileobj=io.BytesIO(service.extractfile(failure).read())) as request:
                    names=request.getnames()
                    stderr=request.extractfile('request/verify.stderr').read().decode()
                    assert 'service simulator verification failed before native compilation' in stderr,stderr
                    assert 'request/generated/checked-simulator.i' not in names
                    assert 'request/generated/native-commands.jsonl' not in names
                    assert 'request/load.stdout' not in names
                    record['stock_rejected_before_compile']=True
        record['ok']=True
    except Exception as error:
        record.update(ok=False,error=str(error))
    rows.append(record)
    (output/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
    print(json.dumps(record),flush=True)
raise SystemExit(0 if all(r['ok'] for r in rows) else 1)
