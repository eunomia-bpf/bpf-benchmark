from pathlib import Path
import subprocess,sys
b=Path(sys.argv[1]);root=Path(__file__).resolve().parents[5]
lines=['dir /'+n+' 0755 0 0' for n in ['dev','proc','sys','lib','proofs']]+['nod /dev/console 0600 0 0 c 5 1']
files={'/init':b/'init','/cases':b/'cases','/bound-probe':b/'bound-probe','/module.ko':b/'bpf_arm64_native_lab.ko','/native-link':b/'native-link','/companion.bpf.o':b/'companion.bpf.o'}
for p in (b/'fixtures').glob('*'):
 if p.suffix in {'.o','.json'}:files['/proofs/'+p.name]=p
for n in ['libc.so.6','ld-linux-aarch64.so.1','libgcc_s.so.1']:files['/lib/'+n]=Path('/usr/aarch64-linux-gnu/lib')/n
for n in ['libelf.so.1','libz.so.1','libzstd.so.1']:files['/lib/'+n]=root/'.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu'/n
for dest,src in files.items():
 if not src.is_file():raise FileNotFoundError(src)
 lines.append(f'file {dest} {src.resolve()} 0755 0 0')
spec=b/'initramfs.spec';spec.write_text('\n'.join(lines)+'\n')
with (b/'init.cpio').open('wb') as out:subprocess.run([str(root/'vendor/build/arm64/linux/usr/gen_init_cpio'),str(spec)],stdout=out,check=True)
