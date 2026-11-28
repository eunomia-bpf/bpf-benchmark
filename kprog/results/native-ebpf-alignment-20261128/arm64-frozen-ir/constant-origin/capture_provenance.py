from pathlib import Path
import json,hashlib,subprocess
root=Path.cwd();out=root/'kprog/results/native-ebpf-alignment-20261128/arm64-frozen-ir/constant-origin';out.mkdir(exist_ok=True)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
rows=[]
for arch,elfsuffix in [('arm64','arm64'),('x86','amd64')]:
 host=root/'vendor/build'/arch/'otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler';image=root/'.cache/qemu-arm64-root/usr/local/bin/otelcol-ebpf-profiler' if arch=='arm64' else None;elf=root/'vendor/repos/opentelemetry-ebpf-profiler/support/ebpf'/('tracer.ebpf.'+elfsuffix);binary=host.read_bytes();data=elf.read_bytes();offset=binary.find(data);assert offset>=0
 r=dict(architecture=arch,binary=str(host),binary_bytes=len(binary),binary_sha256=sha(host),input_bpf_elf=str(elf),input_bpf_elf_bytes=len(data),input_bpf_elf_sha256=sha(elf),embedded_elf_exact_offset=offset,embedded_elf_exact_match=True)
 if image is not None:r['exported_image_binary']=str(image);r['exported_image_binary_sha256']=sha(image);assert r['binary_sha256']==r['exported_image_binary_sha256']
 build=subprocess.check_output(['go','version','-m',str(host)],text=True);(out/(arch+'-go-build-info.txt')).write_text(build);r['build_info_file']=arch+'-go-build-info.txt';rows.append(r)
 sources=['vendor/repos/opentelemetry-ebpf-profiler/tracer/tracer.go','vendor/repos/opentelemetry-ebpf-profiler/tracer/systemconfig.go','vendor/repos/cilium-ebpf/variable.go','vendor/repos/cilium-ebpf/map.go','vendor/repos/cilium-ebpf/collection.go','vendor/repos/cilium-ebpf/elf_reader.go']
r=dict(binaries=rows,dependencies={n:subprocess.check_output(['git','-C',str(root/'vendor/repos'/n),'rev-parse','HEAD'],text=True).strip() for n in ['opentelemetry-ebpf-profiler','cilium-ebpf']},source_sha256={n:sha(root/n) for n in sources},scope='Read-only actual canonical app binaries and their exact embedded original eBPF ELF. No app, image, program or setting changed.')
(out/'binary-provenance.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
