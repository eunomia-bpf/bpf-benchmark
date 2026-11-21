"""Run the existing recovery forms through the current stock ARM base."""
from pathlib import Path
import fcntl,json,os,subprocess,sys
R=Path('/workspaces/repository');S=Path(sys.argv[2]);SAFETY=len(sys.argv)>3 and sys.argv[3]=='safety';O=S/('safety' if SAFETY else 'guest')
FORMS=['entry','entry_byte','entry_half','entry_word','entry_signed_byte','entry_signed_half','entry_signed_word','entry_pair','entry_pre','entry_post','entry_d0','entry_q0','entry_d0_post','entry_q0_post']

def guest():
    O.mkdir(exist_ok=True)
    env=dict(os.environ,PYTHONPATH='/run/pydeps0:/run/pydeps1',KPROG_TRUSTED_COMPILE_STATE=str(S/('safety-broker' if SAFETY else 'broker')),
             BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',
             BPFREJIT_NATIVE_LINK_BINARY=str(S/'cargo/aarch64-unknown-linux-gnu/release/native-link'),
             PATH=str(R/'kprog/stock-path/bin')+':/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin')
    log=(O/'service.log').open('w')
    command=['/usr/bin/python3',str(R/'kprog/trusted_service.py'),'--arch','2','--endpoint','/sys/kernel/debug/bpf_arm64_native_lab/specializer','--state',str(O/'requests'),'--native-link',env['BPFREJIT_NATIVE_LINK_BINARY'],'--loader',str(S/'loader/trusted-native-loader')]
    service=subprocess.Popen(command,stdout=log,stderr=subprocess.STDOUT,env=env)
    rows=[]
    try:
        import time
        while '"ready"' not in (O/'service.log').read_text():
            if service.poll() is not None:raise RuntimeError('service startup exit '+str(service.returncode))
            time.sleep(.1)
        if SAFETY:
            import safety
            return safety.run(S,env)
        for symbol in FORMS:
            expected=0xffffffff if symbol in FORMS[-4:] else 0
            obj=S/('native.o' if symbol=='entry' else 'arm64.o')
            command=[str(S/'probe'),str(obj),str(S/'fixture-module/native_load_fault_module.ko'),symbol,str(expected)]
            p=subprocess.run(command,env=env,text=True,capture_output=True)
            row=dict(symbol=symbol,command=command,exit=p.returncode,stdout=p.stdout,stderr=p.stderr,expected_null=expected)
            rows.append(row);(O/'forms.json').write_text(json.dumps(rows,indent=2)+'\n')
            print(symbol,p.returncode,p.stdout.strip(),flush=True)
    finally:
        lock=O/'requests/request.lock'
        if lock.exists():
            with lock.open('rb') as f:
                fcntl.flock(f,fcntl.LOCK_EX);service.terminate()
        else:service.terminate()
        service.wait();log.close()
        dmesg=subprocess.run(['dmesg'],capture_output=True,text=True);(O/'dmesg').write_text(dmesg.stdout+dmesg.stderr)
    return int(len(rows)!=len(FORMS) or any(r['exit'] for r in rows))

if sys.argv[1]=='guest':raise SystemExit(guest())
if sys.argv[1]!='host':raise SystemExit('usage: guest.py host|guest OUT')
import hashlib,time
S.mkdir(exist_ok=True)
compiler_log=(S/('safety-compiler.log' if SAFETY else 'compiler.log')).open('w')
compiler=subprocess.Popen([sys.executable,str(R/'kprog/trusted_compile.py'),'serve','--scope',str(S),'--state',str(S/('safety-broker' if SAFETY else 'broker')),'--arm64-sysroot',str(R/'.cache/qemu-arm64-root'),'--clang',str(R/'kprog/stock-path/bin/clang')],stdout=compiler_log,stderr=subprocess.STDOUT)
qemu=None
report={}
try:
    while not (S/('safety-broker/ready.json' if SAFETY else 'broker/ready.json')).exists():
        if compiler.poll() is not None:raise RuntimeError('compiler startup exit '+str(compiler.returncode))
        time.sleep(.05)
    kernel=Path('/workspaces/.agent-state/kprog-ck/build-arm64/arch/arm64/boot/Image')
    root=R/'.cache/qemu-arm64-root'
    cmd=['qemu-system-aarch64','-M','virt','-cpu','max','-smp','2','-m','2048','-nographic','-no-reboot','-kernel',str(kernel),
         '-fsdev','local,id=rootfs,path='+str(root)+',security_model=none,readonly=on,multidevs=remap','-device','virtio-9p-device,fsdev=rootfs,mount_tag=rootfs',
         '-fsdev','local,id=repo,path='+str(R)+',security_model=none,readonly=on,multidevs=remap','-device','virtio-9p-device,fsdev=repo,mount_tag=repo',
         '-fsdev','local,id=run,path='+str(S)+',security_model=none,multidevs=remap','-device','virtio-9p-device,fsdev=run,mount_tag=run',
         '-append','console=ttyAMA0 root=rootfs rootfstype=9p rootflags=trans=virtio,version=9p2000.L ro init=/bin/sh loglevel=4 panic=1 oops=panic']
    import elftools,yaml
    deps=sorted({str(Path(x.__file__).resolve().parent.parent) for x in [elftools,yaml]})
    for i,dep in enumerate(deps):cmd += ['-fsdev','local,id=pydeps'+str(i)+',path='+dep+',security_model=none,readonly=on,multidevs=remap','-device','virtio-9p-device,fsdev=pydeps'+str(i)+',mount_tag=pydeps'+str(i)]
    files=[kernel,S/'module/bpf_arm64_native_lab.ko',S/'fixture-module/native_load_fault_module.ko',S/'native.o',S/'arm64.o',S/'probe',S/'loader/trusted-native-loader',S/'cargo/aarch64-unknown-linux-gnu/release/native-link',R/'kprog/arm64/arm64_sim_local_bpf.h',R/'kprog/arm64/arm64_sim_direct.h',R/'kprog/arm64/micro-prog/generate_micro_sim_proofs.py']
    report=dict(command=cmd,hashes_before={str(p):hashlib.sha256(p.read_bytes()).hexdigest() for p in files})
    (S/('safety-launch.json' if SAFETY else 'guest-launch.json')).write_text(json.dumps(report,indent=2)+'\n')
    qemu=subprocess.Popen(cmd,stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    booted=False;tail=b''
    with (S/('safety-qemu.log' if SAFETY else 'qemu.log')).open('wb') as log:
        while True:
            data=os.read(qemu.stdout.fileno(),4096)
            if not data:break
            log.write(data);log.flush();tail=(tail+data)[-8192:]
            if not booted and tail.endswith(b'# '):
                commands=['mount -t proc proc /proc','mount -t sysfs sysfs /sys','mount -t tmpfs tmpfs /run','mount -t tmpfs tmpfs /tmp','mount -t tmpfs tmpfs /var/tmp',
                          'mount -t 9p -o trans=virtio,version=9p2000.L repo '+str(R),'mkdir -p '+str(S),'mount -t 9p -o trans=virtio,version=9p2000.L run '+str(S),
                          'mount -t debugfs debugfs /sys/kernel/debug','mount -t bpf bpffs /sys/fs/bpf','ulimit -l unlimited','insmod '+str(S/'module/bpf_arm64_native_lab.ko'),
                          'PYTHONDONTWRITEBYTECODE=1 /usr/bin/python3 '+str(Path(__file__).resolve())+' guest '+str(S)+(' safety' if SAFETY else '')]
                for i in range(len(deps)):
                    commands[-1:-1]=['mkdir -p /run/pydeps'+str(i),'mount -t 9p -o trans=virtio,version=9p2000.L pydeps'+str(i)+' /run/pydeps'+str(i)]
                qemu.stdin.write((' && '.join(commands)+'; rc=$?; echo $rc > '+str(S/('safety.exit' if SAFETY else 'guest.exit'))+'; echo o > /proc/sysrq-trigger\n').encode());qemu.stdin.flush();booted=True
    report.update(qemu_exit=qemu.wait(),booted=booted,guest_exit=int((S/('safety.exit' if SAFETY else 'guest.exit')).read_text()) if (S/('safety.exit' if SAFETY else 'guest.exit')).exists() else None)
    report['hashes_after']={str(p):hashlib.sha256(p.read_bytes()).hexdigest() for p in files}
    if (O/('outcomes.json' if SAFETY else 'forms.json')).exists():report['forms']=json.loads((O/('outcomes.json' if SAFETY else 'forms.json')).read_text())
finally:
    if qemu is not None and qemu.poll() is None:qemu.terminate();qemu.wait()
    compiler.terminate();report['compiler_exit']=compiler.wait();compiler_log.close()
    (S/('safety-summary.json' if SAFETY else 'guest-summary.json')).write_text(json.dumps(report,indent=2)+'\n')
raise SystemExit(int(report.get('guest_exit')!=0 or len(report.get('forms',[]))!=(34 if SAFETY else len(FORMS))))
