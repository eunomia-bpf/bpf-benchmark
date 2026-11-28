from pathlib import Path
import subprocess,json,hashlib
root=Path.cwd();out=Path('kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir/constant-origin');rows=[]
for arch in ['arm64','x86']:
 binary=root/'vendor/build'/arch/'otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler';r=subprocess.run(['go','tool','objdump','-s',r'go.opentelemetry.io/ebpf-profiler/tracer\.loadAllMaps$',str(binary)],text=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE);assert r.returncode==0 and r.stdout
 (out/(arch+'-actual-loadAllMaps.dis')).write_text(r.stdout);calls=[s for s in r.stdout.splitlines() if 'cilium' in s and ('CALL' in s or 'BL ' in s)];rows.append(dict(architecture=arch,binary_sha256=hashlib.sha256(binary.read_bytes()).hexdigest(),library_calls=calls,disassembly_file=arch+'-actual-loadAllMaps.dis'))
(out/'actual-call-sites.json').write_text(json.dumps(rows,indent=2)+'\n');print(json.dumps(rows,indent=2))
