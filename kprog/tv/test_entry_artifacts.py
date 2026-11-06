"""Kill changed accesses/spills/reloads in the actual extracted entry streams."""
from pathlib import Path
import os
import re
import subprocess

root=Path(__file__).resolve().parent
source=root/'build/simple-arm64'
cases=[('unchanged',None,0,b''),
       ('native-pair-width','native',3,b'\x29'),
       ('native-pair-register','native',1,b'\x28'),
       ('native-erased-pair','native',0,bytes.fromhex('1f2003d5')),
       ('physical-pointer-width','physical',0,b'\x61'),
       ('physical-end-offset','physical',18,b'\x04'),
       ('spill-other-slot','physical',10,b'\xf0'),
       ('reload-wrong-register','physical',41,b'\xa2'),
       ('erased-reload','physical',40,bytes.fromhex('bf11000000000000'))]
for name,stream,offset,replacement in cases:
    directory=root/'build/simple-entry-mutations'/name
    directory.mkdir(parents=True,exist_ok=True)
    for filename in ['SimpleCompiled.lean','SimplePlatform.lean']:
        text=(source/filename).read_text()
        if stream and ((stream=='native')==(filename=='SimpleCompiled.lean')):
            pattern=r'(def '+stream+r' : Array [^\n]*? := #\[)([^\]]+)(\])'
            found=re.search(pattern,text)
            if not found:raise ValueError('missing actual extracted byte array '+stream)
            data=bytearray(int(x,0) for x in found.group(2).split(','))
            if data[offset:offset+len(replacement)]==replacement:raise ValueError('mutation did not change bytes')
            data[offset:offset+len(replacement)]=replacement
            text=text[:found.start(2)]+','.join(hex(b) for b in data)+text[found.end(2):]
        (directory/filename).write_text(text)
    result=subprocess.run([os.environ.get('MAKE','make'),'--no-print-directory','simple-entry-certificate',
        'SIMPLE_ENTRY_DIR='+str(directory.relative_to(root))],cwd=root,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    (directory/'certificate.log').write_bytes(result.stdout)
    if stream is None:
        if result.returncode:raise RuntimeError('unchanged entry failed: '+str(directory))
        print('unchanged actual entry streams: PASS',flush=True)
    else:
        entry_reject = b'SimpleEntryCertificate.lean:' in result.stdout and b"tactic 'rfl' failed" in result.stdout and b'decode' in result.stdout
        body_reject = b'SimplePlatform.lean:' in result.stdout and b'BPF.decode' in result.stdout and b'error:' in result.stdout
        if not result.returncode or not (entry_reject or body_reject):
            raise RuntimeError('semantic rejection missing: '+str(directory))
        print(name+': REJECTED by canonical byte-decoded entry semantics',flush=True)
