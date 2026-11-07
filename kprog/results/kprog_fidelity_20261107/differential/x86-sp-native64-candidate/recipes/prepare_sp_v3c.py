from pathlib import Path
import json,hashlib
r=Path('/workspaces/repository');s=Path('/workspaces/.agent-state/kprog-lanes/F');old=r/'kprog/fidelity/build-sp-v3b/source';new=r/'kprog/fidelity/build-sp-v3c/source';new.mkdir(parents=True,exist_ok=True);pins=json.loads((s/'sp-v3b-source-pins.json').read_text())
for rel,sha in pins['files'].items():
 data=(old/rel).read_bytes();assert hashlib.sha256(data).hexdigest()==sha,rel;p=new/rel;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(data)
p=new/'kprog/formal/KProgFormal/CrossIsaStackArena.lean';t=p.read_text();marker='open KProgFormal\n';t=t.replace(marker,marker+'''
private theorem nativeWidth_restricts (v : BitVec 32) :
    v.toNat % 18446744073709551616 = v.toNat := by
  apply Nat.mod_eq_of_lt
  have := v.isLt
  omega
''');t=t.replace('simp [GeneratedArm64StackArena.','simp [nativeWidth_restricts, GeneratedArm64StackArena.');p.write_text(t)
(new/'vendor').symlink_to(r/'vendor',target_is_directory=True)
files={str(p.relative_to(new)):hashlib.sha256(p.read_bytes()).hexdigest() for p in new.rglob('*') if p.is_file() and not p.is_symlink()};(s/'sp-v3c-source-pins.json').write_text(json.dumps(dict(base=pins['base'],files=files),indent=2)+'\n')
t=(s/'local-sp-v3b-full.py').read_text().replace('sp-v3b','sp-v3c');(s/'local-sp-v3c-full.py').write_text(t)
t=(s/'local-sp-v3b-focused.sh').read_text().replace('sp-v3b','sp-v3c');t=t.replace('python3 "$state/local-sp-v3c-full.py"','printf "0\\n" > "$state/local-sp-v3c-focused.exit"\npython3 "$state/local-sp-v3c-full.py"');(s/'local-sp-v3c-focused.sh').write_text(t)
print('v3c: explicit BV32-to-native64 restriction proof, runtime unchanged')
