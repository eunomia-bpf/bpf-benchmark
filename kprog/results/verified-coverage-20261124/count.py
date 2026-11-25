import tarfile,io,json,collections,sys
for app in ("tetragon","tracee"):
    T=f"/workspaces/kprog-raw/omp/classfg-20261124T070800Z/{app}/service.tar.gz"
    tot=0; fail=0; stages=collections.Counter(); msgs=collections.Counter()
    with tarfile.open(T,"r:gz") as outer:
        for m in outer:
            if not (m.isfile() and m.name.endswith(".tar.gz") and "/requests/" in m.name): continue
            tot+=1
            data=outer.extractfile(m).read()
            with tarfile.open(fileobj=io.BytesIO(data),mode="r:gz") as inner:
                sf=[x for x in inner.getmembers() if x.name.endswith("simulator-failure.json")]
                if sf:
                    fail+=1
                    try:
                        d=json.load(inner.extractfile(sf[0])); stages[d.get("stage","?")]+=1
                        msg=str(d.get("message") or d.get("error") or "")[-80:]; msgs[msg.split(":")[-1].strip()[:50]]+=1
                    except Exception as e: stages["unreadable"]+=1
    print(f"{app}: requests={tot} simulator-failure={fail} checked-sim-c={tot-fail}", dict(stages))
    for k,v in msgs.most_common(5): print("   ",v,k)
