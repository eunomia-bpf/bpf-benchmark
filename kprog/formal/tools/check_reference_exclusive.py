#!/usr/bin/env python3
"""Concrete byte/state regressions for the single canonical exclusive semantics."""
import copy
import json
from pathlib import Path
import subprocess

ROOT=Path(__file__).resolve().parent.parent
MASK=(1<<64)-1
base=dict(isa='aarch64',state=dict(registers=[0x100+i for i in range(31)]+[0x7000],
    flags=0xf0000000,vector0=0x1234,pc=0x1000,
    exclusive_monitor=dict(physical_start=0x9000,bytes=64),
    memory=[dict(address=0x2000+i,value=i+1,readable=True,writable=True,initialized=True) for i in range(16)]))
base['state']['registers'][4]=0x2000
base['state']['registers'][1]=0x8877665544332211
inputs=dict(physical_address=0x9010,reservation=dict(physical_start=0x9000,bytes=64),
    retain_local=True,virtual_pass=True,global_pass=True,commit_pass=True,abort_on_failure=False)
base['state']['exclusive_inputs']=inputs
cases=[]
def request(word):
    q=copy.deepcopy(base);q['native_bytes']=list(word.to_bytes(4,'little'));return q
def expected(q):
    s=copy.deepcopy(q['state']);s.pop('exclusive_inputs',None)
    s.update(pc=0x1004,defined_flags=MASK,events=[],fault=None);return s
def effect(action,width,order=False,success=True,address=0x2000):
    return dict(kind='exclusive',action=action,address=address,bytes=width,
        acquire=order if action=='reserve' else False,release=order if action=='attempt' else False,success=success)
for immediate in range(16):
    for monitor in (None,dict(physical_start=0x9000,bytes=64)):
        q=request(0xd503305f|(immediate<<8));q['state']['exclusive_monitor']=monitor
        q['state'].pop('exclusive_inputs')
        e=expected(q);e['exclusive_monitor']=None
        e['events']=[effect('clear',0,address=0)]
        cases.append((q,e))
for word,width,acquire in [(0x885f7c80,4,False),(0x885ffc80,4,True),
                           (0xc85f7c80,8,False),(0xc85ffc80,8,True)]:
    for zr in (False,True):
        q=request(word|31 if zr else word);q['state']['exclusive_monitor']=None
        e=expected(q)
        if not zr:e['registers'][0]=0x04030201 if width==4 else 0x0807060504030201
        e['exclusive_monitor']=dict(physical_start=0x9000,bytes=64)
        e['events']=[effect('reserve',width,acquire),dict(kind='read',address=0x2000,value=list(range(1,width+1)),initialized=True)]
        cases.append((q,e))
for word,width,release in [(0x88007c81,4,False),(0x8800fc81,4,True),
                           (0xc8007c81,8,False),(0xc800fc81,8,True)]:
    for mode in ['success','empty','interference','virtual','global','commit','range','physical_alias']:
        q=request(word)
        if mode=='empty':q['state']['exclusive_monitor']=None
        if mode=='interference':q['state']['exclusive_inputs']['retain_local']=False
        if mode=='virtual':q['state']['exclusive_inputs']['virtual_pass']=False
        if mode=='global':q['state']['exclusive_inputs']['global_pass']=False
        if mode=='commit':q['state']['exclusive_inputs']['commit_pass']=False
        if mode=='range':q['state']['exclusive_inputs']['physical_address']=0xa000
        if mode=='physical_alias':
            q['state']['registers'][4]=0x6000
            for c in q['state']['memory']:c['address']+=0x4000
        address=q['state']['registers'][4]
        success=mode in ['success','physical_alias']
        e=expected(q);e['registers'][0]=0 if success else 1
        if mode!='virtual':e['exclusive_monitor']=None
        e['events']=[effect('attempt',width,release,success,address)]
        if success:
            value=[0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88][:width]
            for c,b in zip(e['memory'],value):c['value']=b
            e['events'].append(dict(kind='write',address=address,value=value,initialized=True))
        cases.append((q,e))
# ASL translation permissions precede local-monitor checks. A successful VA
# check can therefore fault even with an empty monitor, before any attempt or
# clearing. Preserve both old abort-profile inputs as full fault cases.
for abort in (False,True):
    q=request(0xc8007c81);q['state']['exclusive_monitor']=None;q['state']['memory']=[]
    q['state']['exclusive_inputs']['abort_on_failure']=abort
    e=expected(q);fault=dict(kind='write',address=0x2000,bytes=8)
    e.update(fault=fault,pc=0x1000,events=[dict(kind='fault',fault=fault)])
    cases.append((q,e))
    # VA failure returns before translation. This is a separate input profile,
    # not a replacement for either permission-fault case above.
    q=request(0xc8007c81);q['state']['memory']=[]
    q['state']['exclusive_inputs'].update(virtual_pass=False,abort_on_failure=abort)
    e=expected(q);e['registers'][0]=1;e['events']=[effect('attempt',8,success=False)]
    cases.append((q,e))
for word,width in [(0x885f7c80,4),(0xc85f7c80,8),(0x88007c81,4),(0xc8007c81,8)]:
    q=request(word);q['state']['registers'][4]=0x2001
    e=expected(q);fault=dict(kind='alignment',address=0x2001,bytes=width)
    e.update(pc=0x1000,fault=fault,events=[dict(kind='fault',fault=fault)])
    cases.append((q,e))
for word in (0x885f7fe0,0xc85f7fe0,0x88007fe1,0xc8007fe1):
    q=request(word);q['state']['registers'][31]=0x7001
    e=expected(q);fault=dict(kind='sp_alignment',address=0x7001)
    e.update(pc=0x1000,fault=fault,events=[dict(kind='fault',fault=fault)])
    cases.append((q,e))
run=subprocess.run([str(ROOT/'.lake/build/bin/reference')],input=''.join(json.dumps(q)+'\n' for q,_ in cases),text=True,capture_output=True,check=True)
rows=[json.loads(x) for x in run.stdout.splitlines()]
assert len(rows)==len(cases)
for (q,e),actual in zip(cases,rows):
    assert actual.pop('reference_base') == 'LNSym'
    assert actual==e,(q,actual,e)
invalid=[]
for word in [0xc8017c81,0xc8047c81,0xc85f7880,0xc8007881]:invalid.append(request(word))
for field in ['exclusive_monitor','exclusive_inputs']:
    q=request(0xc85f7c80);q['state'].pop(field);invalid.append(q)
q=request(0xc85f7c80);q['state']['exclusive_inputs']['reservation']=None;invalid.append(q)
q=request(0xc85f7c80);q['state']['exclusive_inputs']['reservation']['bytes']=8;invalid.append(q)
q=request(0xc85f7c80);q['state']['exclusive_inputs']['physical_address']=1<<64;invalid.append(q)
q=request(0xc85f7c80);q['state']['exclusive_inputs']['commit_pass']=0;invalid.append(q)
for q in invalid:
    r=subprocess.run([str(ROOT/'.lake/build/bin/reference')],input=json.dumps(q)+'\n',text=True,capture_output=True)
    assert r.returncode==1 and r.stderr.startswith('reference:'),(q,r)
print(f'canonical exclusive: {len(cases)} full-state/effect/fault positives, {len(invalid)} precise encoding/input rejects')
