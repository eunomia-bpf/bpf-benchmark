import tarfile,json,io,collections,sys,os
def read(d):
    t=tarfile.open(os.path.join(d,'service.tar.gz')); names=set(t.getnames())
    rows=[json.loads(l) for l in t.extractfile('service/requests/requests.jsonl').read().decode().splitlines() if l.strip()]
    out=[]
    for r in rows:
        rid=r['request_id']
        cap='service/requests/%d.success.tar.gz'%rid
        if cap not in names: cap='service/requests/%d.failure.tar.gz'%rid
        inner=tarfile.open(fileobj=io.BytesIO(t.extractfile(cap).read())); g=inner.getnames()
        txt=inner.extractfile('request/verify.stderr').read().decode('utf-8','replace') if 'request/verify.stderr' in g else ''
        lines=[l for l in txt.splitlines() if l.strip()]
        out.append({'request_id':rid,'native_object_sha256':r['native_sha256'],
                    'entry':inner.extractfile('request/kernel.entry').read().decode().strip(),
                    'path':r['execution_path'],
                    'installed':r['execution_path']=='checked-sim-c','status':r['status'],
                    'source_prog_id':r.get('source_prog_id'),
                    'reason':lines[-2] if len(lines)>1 else ''})
    return out
if __name__=='__main__':
    rows=read(sys.argv[1])
    print(json.dumps(rows,indent=1))
