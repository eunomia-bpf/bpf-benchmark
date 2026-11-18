ROOT := kprog/results/lpm-body-20261118
LINK := kprog/x86/native_lab/native_link
.PHONY: run
run:
	cargo test --release --manifest-path $(LINK)/Cargo.toml -- --test-threads=1 --nocapture > $(OUT)/tests.txt 2>&1
	cargo test --release --manifest-path $(LINK)/Cargo.toml --no-run --message-format=json > $(OUT)/test-build.json 2> $(OUT)/test-build.txt
	python3 -c 'import json; from pathlib import Path; rows=[json.loads(l) for l in Path("$(OUT)/test-build.json").read_text().splitlines()]; files=[r["executable"] for r in rows if r.get("reason")=="compiler-artifact" and r.get("profile",{}).get("test") and r.get("executable")]; assert len(files)==1,files; Path("$(OUT)/test-executable.txt").write_text(files[0]+"\n")'
	python3 kprog/results/link-entry-replay-20261117/replay.py --output $(OUT)/replay --test-executable "$$(cat $(OUT)/test-executable.txt)" > $(OUT)/replay.txt 2>&1
	python3 $(ROOT)/prepare.py --replay $(OUT)/replay/replay.json --output $(OUT)
	/workspaces/kprog-raw/perf/lpm-body-20261118/host-20261118T011625Z-2846223/driver $(OUT)/kernel-host.bin $(OUT)/native-host.bin > $(OUT)/samples.csv
