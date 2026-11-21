import tarfile,json,io,collections,sys,os
def request_row(r,inner):
    names=set(inner.getnames())
    txt=inner.extractfile('request/verify.stderr').read().decode('utf-8','replace') if 'request/verify.stderr' in names else ''
    lines=[l for l in txt.splitlines() if l.strip()]
    failure=r.get('simulator_failure',{})
    if 'request/simulator-failure.json' in names:
        failure=json.load(inner.extractfile('request/simulator-failure.json'))
    path=r.get('execution_path')
    accepted=r.get('b_stock_passed')
    if 'request/checked-simulator-verification.json' in names:accepted=True
    return {'request_id':r['request_id'],'native_object_sha256':r['native_sha256'],
            'entry':inner.extractfile('request/kernel.entry').read().decode().strip(),
            'path':path,'installed':path=='checked-sim-c' and r['status']==0,
            'status':r['status'],'source_prog_id':r.get('source_prog_id'),
            'proof_generated':any(n.startswith('request/generated/trusted_') and n.endswith('.proof.o') for n in names),
            'b_generated':True if accepted else r.get('b_generated'),
            'b_stock_passed':accepted,'failure_stage':failure.get('stage'),
            'reason':lines[-2] if len(lines)>1 else failure.get('error',''),
            'error':r.get('error')}

def read(d):
    t=tarfile.open(os.path.join(d,'service.tar.gz')); names=set(t.getnames())
    rows=[json.loads(l) for l in t.extractfile('service/requests/requests.jsonl').read().decode().splitlines() if l.strip()]
    out=[]
    for r in rows:
        rid=r['request_id']
        cap='service/requests/%d.success.tar.gz'%rid
        if cap not in names: cap='service/requests/%d.failure.tar.gz'%rid
        inner=tarfile.open(fileobj=io.BytesIO(t.extractfile(cap).read()))
        out.append(request_row(r,inner))
    return out
if __name__=='__main__':
    rows=read(sys.argv[1])
    print(json.dumps(rows,indent=1))
