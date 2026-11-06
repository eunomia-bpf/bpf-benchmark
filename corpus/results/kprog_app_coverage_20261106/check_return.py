"""Load-only reproduction for an overwritten native outer return address."""
import importlib.util
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'kprog/fidelity'))
spec=importlib.util.spec_from_file_location('ret_negative',ROOT/'kprog/fidelity/negative.py')
neg=importlib.util.module_from_spec(spec);spec.loader.exec_module(neg)
neg.FIXTURES={'x86':{'outer_ret_zero':'mov QWORD PTR [rsp],0; mov eax,2; ret'}}
phase, mode=sys.argv[1:]
out=HERE/('ret-'+phase)
if mode=='build':
    neg.build('x86',out)
elif mode=='regression':
    sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
    import generate_micro_sim_proofs as g
    rows=[]
    def case(name,body,accepted):
        insns=[]
        for i,text in enumerate(body.split('; ')):
            op,_,args=text.partition(' ')
            insns.append(g.NativeInsn(i,text,op,g.split_operands(args)))
        try:g.check_definedness(insns,{},None,g)
        except ValueError as error:
            assert not accepted and 'return' in str(error).lower(),(name,str(error))
            rows.append(dict(name=name,accepted=False,message=str(error)))
        else:
            assert accepted,name
            rows.append(dict(name=name,accepted=True))
    case('intact','mov eax,2; ret',True)
    for instruction in ('mov QWORD PTR [rsp],0','mov BYTE PTR [rsp+7],0',
                        'add QWORD PTR [rsp],1','not QWORD PTR [rsp]'):
        case(instruction,instruction+'; mov eax,2; ret',False)
    case('saved_outer','mov rax,QWORD PTR [rsp]; push rax; pop rcx; mov QWORD PTR [rsp],rcx; mov eax,2; ret',True)
    case('exchanged_outer','mov rax,QWORD PTR [rsp]; xchg QWORD PTR [rsp],rbx; xchg QWORD PTR [rsp],rbx; mov eax,2; ret',True)
    case('partial_outer','mov rax,QWORD PTR [rsp]; mov eax,eax; mov QWORD PTR [rsp],rax; mov eax,2; ret',False)
    case('internal_call','call 3; mov eax,2; ret; mov eax,7; ret',True)
    case('internal_corrupt','call 3; mov eax,2; ret; mov QWORD PTR [rsp],0; ret',False)
    case('internal_saved_return','call 3; mov eax,2; ret; pop rax; push rax; ret',True)
    (HERE/'ret-regression.json').write_text(json.dumps(rows,indent=2)+'\n')
    print('return provenance constructor regressions:',len(rows),'passed')
elif mode=='bound':
    rc=neg.run_bound('x86',out,HERE/('ret-'+phase+'-bound'),
                     HERE/'indirect-build/bound-probe',HERE/'abi-definedness/companion.bpf.o')
    row=json.loads((HERE/('ret-'+phase+'-bound')/'outcomes.json').read_text())['cases'][0]
    if phase=='before':
        print('before outcome:',row['stage'],flush=True)
        assert row['stage'] in {'accepted_finding','verifier_rejected'},row
    else:
        assert rc==0 and row['stage']=='specialization_rejected',row
        assert 'return' in row['message'].lower(),row
        print('corrupted native return address rejected before upload')
else:
    raise SystemExit('expected before/after build/bound')
