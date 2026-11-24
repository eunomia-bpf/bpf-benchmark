#!/usr/bin/env python3
"""Finite XOR proof build, focused acceptance/publication, then prepared query."""
from pathlib import Path
import datetime, fcntl, gzip, json, os, resource, subprocess, sys, time
REPO=Path('/workspaces/repository')
FORMAL=REPO/'kprog/formal'
STATE=Path('/workspaces/.agent-state/kprog-lanes/V')
RAW=Path(sys.argv[1])
RECEIPT=FORMAL/'results/m5-x86-xor-byte-call-20261124'
NATIVE=FORMAL/'results/m5-x86-native-checked-resume-20261124'
SOURCE='kprog/formal/KProgFormal/ClightRefinement/X86AluXorByteCall.lean'
LIMIT=34359738368
resource.setrlimit(resource.RLIMIT_AS,(LIMIT,LIMIT))
os.environ['LEAN_NUM_THREADS']='1'
result={'status':'running','phase':'focused','raw_directory':str(RAW),
        'proof_limits':{'maxHeartbeats':200000,'maxRecDepth':512},
        'memory_limit':LIMIT,'cpus':'12-15','timing':'shared flock',
        'overall_instruction_goal':'open','accepted_steps':[]}

def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()

def save():
    RAW.joinpath('outcome.json').write_text(json.dumps(result,indent=2)+'\n')

def command(name,args,cwd=FORMAL):
    started=time.monotonic()
    with RAW.joinpath(name+'.txt').open('x') as log:
        process=subprocess.run(args,cwd=cwd,stdout=log,stderr=subprocess.STDOUT)
    meta={'command':args,'exit':process.returncode,'seconds':time.monotonic()-started,
          'memory_limit':LIMIT,'cpus':'12-15','shared_timing':True,'lean_num_threads':1}
    RAW.joinpath(name+'.json').write_text(json.dumps(meta,indent=2)+'\n')
    result[name]=meta
    save()
    if process.returncode:
        raise subprocess.CalledProcessError(process.returncode,args)
    return meta

def publish(name,paths,message):
    result['phase']='publish-'+name
    save()
    with open('/workspaces/.agent-state/kprog-lanes/locks/git','a') as lock:
        fcntl.flock(lock,fcntl.LOCK_EX)
        branch=subprocess.check_output(['git','branch','--show-current'],cwd=REPO,text=True).strip()
        if branch!='master':
            raise RuntimeError('publication requires current master; found '+branch)
        command(name+'-status',['git','status','--short','--branch'],REPO)
        command(name+'-diff',['git','diff','--check','--',*paths],REPO)
        command(name+'-add',['git','add','--',*paths],REPO)
        # --only retains every peer's unrelated staged and worktree change.
        command(name+'-commit',['git','commit','--only','-m',message,'--',*paths],REPO)
        revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=REPO,text=True).strip()
        result[name+'_committed']=revision
        save()
        command(name+'-push',['git','push','origin','master'],REPO)
        result[name+'_published']=revision
        save()

def journal():
    text=('# V finite task terminal '+now()+'\n\n'+
          'Outcome: '+result['status']+'; phase: '+result['phase']+'.\n'+
          'Actual results: '+str(RAW/'outcome.json')+'\n'+
          'Accepted steps: '+json.dumps(result['accepted_steps'])+'\n'+
          'XOR publication: '+str(result.get('xor_published',result.get('xor_committed','none')))+'\n'+
          'Native query publication: '+str(result.get('native_published',result.get('native_committed','none')))+'\n\n'+
          'Consume actual logs and JSON before further work. A failed focused step\n'+
          'requires correcting the actual source boundary and a fresh phase name;\n'+
          'keep every accepted result. The source draft and all raw evidence stay.\n'+
          'All existing formal/CNT work and peer index/worktree changes are retained.\n'+
          'No root/full make check was run. Original DIV fault-marker correction\n'+
          'and pointer-address correspondence remain open; all149-operation\n'+
          'handler/dispatcher objective is unfinished.\n\n---\n')
    for name in ['state.md','last.md']:
        path=STATE/name
        path.write_text(text+path.read_text())
    stop=STATE/'STOP'
    if stop.exists() and stop.read_text()==str(RAW)+'\n':
        stop.rename(STATE/('STOP.finished-'+RAW.name))

try:
    result['started_at']=now()
    result['head_at_start']=subprocess.check_output(['git','rev-parse','HEAD'],cwd=REPO,text=True).strip()
    save()
    focused=command('focused-02',['lake','build','KProgFormal.ClightRefinement.X86AluXorByteCall'])
    result['accepted_steps'].append('focused XOR module build')
    save()
    result['phase']='xor-focused-query'
    public=command('xor-public-02',['lake','env','lean','-j1','results/m5-x86-xor-byte-call-20261124/Query.lean'])
    result['accepted_steps'].append('XOR execute focused type/axiom query')
    RECEIPT.joinpath('focused.txt.gz').write_bytes(gzip.compress(RAW.joinpath('focused-02.txt').read_bytes(),mtime=0))
    RECEIPT.joinpath('public.txt').write_bytes(RAW.joinpath('xor-public-02.txt').read_bytes())
    RECEIPT.joinpath('validation.json').write_text(json.dumps({'focused':focused,'public':public,
        'proof_limits':result['proof_limits'],'raw_directory':str(RAW),'root_integration':'pending',
        'complete_instruction_families':0},indent=2)+'\n')
    RECEIPT.joinpath('README.md').write_text(
        'The genuine scalar/tag0 XOR byte call executes original entry, both\n'
        'readers, numerical helper, flags, byte writeback and actual local release\n'
        'through the void return. Initial source observations and permissions\n'
        'derive every intermediate heap, helper observation and store/free success.\n'
        'The stated domain retains ordinary registers, distinct register/lane\n'
        'pairs, shift bounds, source layouts/bindings and caller-owned storage.\n'
        'The final GPR/five-flag views, caller loads and revoked locals are explicit.\n\n'
        'Focused module build and execute type/axiom query pass at original\n'
        '200000/512 budgets, one worker and32GiB inside shared timing. Legal lane\n'
        'and canonical-instruction/dispatcher composition continue next.\n')
    publish('xor',[SOURCE,'kprog/formal/results/m5-x86-xor-byte-call-20261124'],
            'formal: compose genuine scalar XOR byte call through actual return')
    result['phase']='prepared-native-checked-query'
    NATIVE.mkdir()
    native=command('native-public-02',['lake','env','lean','-j1',
                   'results/m5-x86-logic-native-checked/Query.lean'])
    result['accepted_steps'].append('prepared Native/Checked type/axiom query')
    NATIVE.joinpath('public.txt').write_bytes(RAW.joinpath('native-public-02.txt').read_bytes())
    NATIVE.joinpath('validation.json').write_text(json.dumps({'public':native,
        'proof_limits':result['proof_limits'],'raw_directory':str(RAW),
        'query':'results/m5-x86-logic-native-checked/Query.lean',
        'complete_instruction_families':0},indent=2)+'\n')
    NATIVE.joinpath('README.md').write_text(
        'After accepting and publishing the genuine XOR source call, the\n'
        'prepared Native/Checked public query passes against the current\n'
        'formal line. It checks the numerical step record, represented source\n'
        'postconditions and original checked-register delegation.\n\n'
        'This is a focused query; whole confirmation remains separate.\n')
    publish('native',['kprog/formal/results/m5-x86-native-checked-resume-20261124'],
            'formal: confirm prepared native checked interfaces after XOR call')
    result['phase']='done'
    result['status']='accepted'
except Exception as error:
    result['status']='failed'
    result['error']=str(error)
    raise
finally:
    result['ended_at']=now()
    save()
    journal()
