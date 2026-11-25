import collections, glob, io, json, os, sys, tarfile

B = sys.argv[1] if len(sys.argv) > 1 else "/workspaces/kprog-raw/verified/checked-corpus-20261125-recheck"


def requests(app):
    outer = f"{B}/{app}/service.tar.gz"
    if os.path.exists(outer):
        with tarfile.open(outer, "r:gz") as t:
            for m in t:
                if m.isfile() and "/requests/" in m.name and m.name.endswith(".tar.gz"):
                    yield m.name, tarfile.open(fileobj=io.BytesIO(t.extractfile(m).read()), mode="r:gz")
    else:
        for p in glob.glob(f"{B}/{app}/state/session-*/requests/*.tar.gz"):
            yield p, tarfile.open(p)


for app in sorted(os.listdir(B)):
    if not os.path.isdir(f"{B}/{app}"):
        continue
    total = verified = failed = 0
    stages = collections.Counter()
    for name, inner in requests(app):
        total += 1
        failure = name.endswith(".failure.tar.gz")
        failed += failure
        sim = [m for m in inner.getmembers() if m.name.endswith("simulator-failure.json")]
        if sim:
            stages[json.load(inner.extractfile(sim[0])).get("stage")] += 1
        elif not failure:
            verified += 1
    print(app, "requests", total, "verified", verified, "fallback", dict(stages), "failed", failed)
