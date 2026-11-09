#!/usr/bin/env python3
"""Recompile each retained Cilium source configuration with its saved BPF command."""
from pathlib import Path
import collections,datetime,hashlib,json,subprocess,sys,tarfile,time
from elftools.elf.elffile import ELFFile
R=Path("/workspaces/repository")
D=Path("/var/tmp/kprog-tmp/A/cilium-reference-rebuild")
O=R/"corpus/results/kprog_app_coverage_20261109/resident-census/cilium-reference-rebuild"
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def instructions(path):
    with path.open("rb") as fp:
        elf=ELFFile(fp)
        return {s.name:dict(bytes=s["sh_size"],sha256=hashlib.sha256(s.data()).hexdigest()) for s in elf.iter_sections() if s["sh_flags"]&4}
def maps(path):
    types=json.loads(subprocess.check_output([str(R/"vendor/build/x86/bpftool/bin/bpftool"),"-j","btf","dump","file",str(path),"format","raw"],text=True))["types"]
    ids={t["id"]:t for t in types}
    section=next(t for t in types if t["kind"]=="DATASEC" and t.get("name")==".maps")
    result={}
    for v in section["vars"]:
        variable=ids[v["type_id"]];t=ids[variable["type_id"]];fields={}
        for member in t.get("members",[]):
            value=ids[member["type_id"]]
            if value["kind"]=="PTR":
                value=ids[value["type_id"]]
                if value["kind"]=="ARRAY":fields[member["name"]]=value["nr_elems"]
        result[variable["name"]]=fields
    return result
def main():
    D.mkdir(exist_ok=True);rows=[]
    index=json.loads((R/"corpus/results/kprog_app_coverage_20261109/resident-census/resource-index.json").read_text())["programs"]
    groups=collections.defaultdict(list)
    for row in index:
        if row["application"]=="cilium/agent":groups[row["source_bpf"]].append(row)
    for source,instances in groups.items():
        original=Path(source);family=original.parent.parent.name;config=original.parent.name
        base=original.parents[3]/"parity"/family/config
        parity=json.loads((base/"parity.json").read_text())
        overlay=base/"native-abi-overlay";headers=base/"live-headers";args=[]
        for arg in parity["bpf_command"][1:]:
            if arg.startswith("-I/var/tmp/ciliumrunner_"):args.append("-I"+str(headers))
            elif arg.startswith("-I/var/lib/cilium/bpf"):args.append(arg.replace("/var/lib/cilium/bpf",str(overlay)))
            elif arg.startswith("/var/lib/cilium/bpf/"):args.append(str(overlay/Path(arg).relative_to("/var/lib/cilium/bpf")))
            else:args.append(arg)
        out=D/config/(family+".bpf.o");out.parent.mkdir(exist_ok=True);args[args.index("-o")+1]=str(out)
        command=["clang-18",*args];start=time.monotonic()
        with (out.parent/"compile.log").open("w") as log:p=subprocess.run(command,stdout=log,stderr=subprocess.STDOUT)
        row=dict(family=family,configuration=config,resident_instances=len(instances),source_object=source,source_sha256=sha(original),original_command=parity["bpf_command"],command=command,compiler_exit=p.returncode,wall_seconds=time.monotonic()-start,source_program_ids=[r["source_prog_id"] for r in instances])
        if p.returncode==0:
            before,after=instructions(original),instructions(out)
            row.update(reference_object=str(out),reference_sha256=sha(out),original_maps=maps(original),reference_maps=maps(out),original_instructions=before,reference_instructions=after,instruction_sections_equal=before==after)
        rows.append(row);(D/"result.json").write_text(json.dumps(dict(configurations=len(rows),resident_instances=sum(r["resident_instances"] for r in rows),native_execution_requests=0,programs=rows),indent=2)+"\n")
    shutil_result=O/"result.json";shutil_result.write_text((D/"result.json").read_text())
    with tarfile.open(O/"references.tar.gz","w:gz") as tf:
        tf.add(Path(__file__),arcname="compile.py");tf.add(D/"result.json",arcname="result.json")
        for row in rows:tf.add(D/row["configuration"],arcname=row["configuration"])
    sys.path.insert(0,"/var/tmp/kprog-tmp/A/publication");from publish import publish
    result=publish([str((O/n).relative_to(R)) for n in ["result.json","references.tar.gz"]],"Record Cilium reference ELF rebuilds from saved application compile inputs","resident-cilium-reference-terminal")
    (D/"publication.json").write_text(json.dumps(result,indent=2)+"\n")
    with Path("/workspaces/.agent-state/kprog-lanes/COORDINATION.md").open("a") as f:f.write("\n- LOCAL A FOR C/R/COORDINATOR "+datetime.datetime.now(datetime.timezone.utc).isoformat()+": PUSHED "+result["commit"]+" Cilium reference BPF rebuilds "+str([(r["family"],r["compiler_exit"],r.get("instruction_sections_equal")) for r in rows])+". All72residentinstances/3savedconfigurations, actualsource/archive/mapBTF/instructionhashes retained; source/nativeP/workload bytes retained, nativeexecutionrequests0. Resources fromthese references follow separate stock-kernel preparation.\n")
if __name__=="__main__":main()
