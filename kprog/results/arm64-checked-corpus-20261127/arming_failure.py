"""Separate native arming ioctl errors from missing captured ELF artifacts."""
from pathlib import Path
import hashlib
import io
import json
import subprocess
import sys
import tarfile

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
folder=HERE/('guest-'+sys.argv[1])
request_id=int(sys.argv[2])
controller=json.loads((folder/'controller.json').read_text())
case=Path(controller['raw'])/controller['app'].replace('/','-')
with tarfile.open(case/'service.tar.gz') as service:
    rows=[json.loads(s) for s in service.extractfile('service/service.log').read().decode().splitlines() if '"request_id"' in s]
    row=next(r for r in rows if r['request_id']==request_id)
    member='service/requests/'+str(request_id)+'.failure.tar.gz'
    with tarfile.open(fileobj=io.BytesIO(service.extractfile(member).read())) as archive:
        files={Path(m.name).name:m for m in archive if m.isfile()}
        stderr=archive.extractfile(files['load-direct.stderr']).read().decode()
        artifacts={name:dict(bytes=files[name].size,sha256=hashlib.sha256(archive.extractfile(files[name]).read()).hexdigest()) for name in ['request.native.o','kernel.native.o','trusted_arm64.bpf.o','trusted_arm64.proof.o'] if name in files}
with tarfile.open(case/'corpus.tar.gz') as corpus:
    metadata=next(m for m in corpus if m.name.endswith('/metadata.json'))
    metadata=json.loads(corpus.extractfile(metadata).read())
source_paths=['kprog/libnativeloader/src/native_loader_trusted.cpp','kinsn/module/arm64/bpf_arm64_native_lab.c','kinsn/module/include/native_lab_trusted.h']
result=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),request_id=request_id,
    service_started=row.get('started'),service_finished=row.get('finished'),service_status=row['status'],
    corpus_error_recorded=metadata.get('generated_at'),corpus_status=metadata.get('status'),
    stderr=stderr,captured_artifacts=artifacts,
    source_revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
    current_source_sha256={p:hashlib.sha256((ROOT/p).read_bytes()).hexdigest() for p in source_paths},
    source_trace=['Loader arm_and_load reports errno from ioctl(NATIVE_LAB_TRUSTED_CHUNK); this message is not a file-open failure.',
        'native_lab_store_chunk first calls native_lab_active_capsule; absent, abandoned or mismatched active job returns ENOENT.',
        'native_lab_store_chunk can also return ENOENT when a relocation map ID cannot be found; the stderr alone does not distinguish these branches.',
        'native_lab_trusted_release marks a closed request owner job abandoned.'],
    inference='Captured native ELF exists. Corpus error is recorded while this request remains in progress; timeout teardown abandoning the request is consistent with the later arming error. The active-capsule versus relocation-map kernel branch was not captured, so the cause is not proven.',
    scope='Archive and source diagnosis only. No new guest, kernel instrumentation, timeout change or successful-install claim.')
(folder/('arming-failure-'+str(request_id)+'.json')).write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
