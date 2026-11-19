"""Catch classifier/asm/word-identity/headlen gaps and overbroad field matches."""
import json
from pathlib import Path
import re
import subprocess
import sys

root=Path('/workspaces/repository')
sys.path[0]=str(root/'kprog/x86')
import trusted_specializer as adapter
out=Path(sys.argv[1]); out.mkdir(parents=True,exist_ok=True)
mode=sys.argv[2]
assert mode in ('before','after'),mode
compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds')
commands=[]
def run(command):
    command=list(map(str,command))
    p=subprocess.run(command,text=True,capture_output=True)
    commands.append(dict(command=command,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    p.check_returncode()
    return p.stdout

release=Path('/workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release').read_text().strip()
run(['clang-18','-fsyntax-only','-I'+str(root/'vendor/bpf/targets/x86'/release),Path(__file__).with_name('layout.c')])
source=Path(__file__).with_name('fixture.c')
run([root/'kprog/stock-path/bin/clang',*adapter.COMPILE_FLAGS,'-DSELECTOR_CONTROLS',
     '-emit-llvm','-c',source,'-o',out/'controls.bc'])
controls=run(['llvm-dis-18',out/'controls.bc','-o','-'])
explicit=[]
# Clang canonicalizes C comparisons; keep the missing predicates and wide
# comparisons explicit so each new branch has an independent regression.
for width,predicates in [(32,['uge','ule']),(64,['ugt','uge','ult','ule'])]:
    for predicate in predicates:
        name=f'ir_{predicate}{width}';explicit.append(name)
        wide='  %wide = zext i32 %span to i64\n' if width==64 else ''
        operand='%wide' if width==64 else '%span'
        controls+=f'''\ndefine i32 @{name}(ptr %ctx) section "classifier" {{
  %kernel = call ptr @bpf_cast_to_kern_ctx(ptr %ctx)
  %len = call i64 asm sideeffect "$0 = *(u32 *)($1 + $2)", "=r,r,i,~{{memory}}"(ptr %kernel, i64 112)
  %data_len = call i64 asm sideeffect "$0 = *(u32 *)($1 + $2)", "=r,r,i,~{{memory}}"(ptr %kernel, i64 116)
  %left = trunc i64 %len to i32
  %right = trunc i64 %data_len to i32
  %span = sub i32 %left, %right
{wide}  %compare = icmp {predicate} i{width} {operand}, 42
  %result = zext i1 %compare to i32
  ret i32 %result
}}
'''
controls+='\ndeclare void @read_context(ptr) readonly\n'
controls+='\n@kprog_unspecified_input = external global i64, section ".ksyms"\n@foreign_input = external global i64\n'
boundary=['ir_edge_eq_lower','ir_edge_ne_lower','ir_edge_eq_upper','ir_edge_ne_upper']
for name in [*boundary,'ir_edge_nondominating']:
    guard='ule' if name.endswith('upper') else 'uge'
    predicate='ne' if '_ne_' in name else 'eq'
    split='  br i1 %choose, label %guarded, label %check\nguarded:\n' if name=='ir_edge_nondominating' else ''
    controls+=f'''\ndefine i32 @{name}(ptr %ctx, i1 %choose) section "classifier" {{
entry:
  %kernel = call ptr @bpf_cast_to_kern_ctx(ptr %ctx)
  %len = call i64 asm sideeffect "$0 = *(u32 *)($1 + $2)", "=r,r,i,~{{memory}}"(ptr %kernel, i64 112)
  %data_len = call i64 asm sideeffect "$0 = *(u32 *)($1 + $2)", "=r,r,i,~{{memory}}"(ptr %kernel, i64 116)
  %left = trunc i64 %len to i32
  %right = trunc i64 %data_len to i32
  %span = sub i32 %left, %right
{split}  %guard = icmp {guard} i32 %span, 42
  br i1 %guard, label %check, label %exit
check:
  %compare = icmp {predicate} i32 %span, 42
  %result = zext i1 %compare to i32
  ret i32 %result
exit:
  ret i32 0
}}
'''
data_controls = {'plain': True, 'readonly': True, 'private_store': True,
                 'mutating': False, 'identity_stale': False, 'cb_store': True,
                 'packet_data_store': False, 'cb_cross_end': False, 'foreign_cb_store': False,
                 'xdp_cb_store': False, 'private_choice': True, 'foreign_choice': False,
                 'class_store': True, 'class_choice': True, 'class_packet_store': False}
for name in data_controls:
    middle = {'plain': '', 'readonly': '  call void @read_context(ptr %ctx)\n',
              'private_store': '  store i8 7, ptr %local\n',
              'mutating': '  call void @mutate_context(ptr %ctx)\n',
              'identity_stale': '  call void @mutate_context(ptr %ctx)\n  %carried = call i64 asm sideeffect "", "=r,0"(i64 %first)\n'}.get(name, '')
    if name in {'private_choice','foreign_choice','class_choice'}:
        symbol = 'foreign_input' if name == 'foreign_choice' else 'kprog_unspecified_input'
        middle = f'  %choice = load volatile i64, ptr @{symbol}\n'
    if name in {'class_store','class_choice','class_packet_store'}:
        offset = 76 if name == 'class_packet_store' else 46
        middle += f'''  %kernel = call ptr @bpf_cast_to_kern_ctx(ptr %ctx)
  %class = getelementptr i8, ptr %kernel, i64 {offset}
  call void asm sideeffect "*(u16 *)($0 + 0) = $1", "r,r,~{{memory}}"(ptr %class, i64 0)
'''
    if name in {'cb_store','packet_data_store','cb_cross_end','foreign_cb_store','xdp_cb_store'}:
        offset = 76 if name == 'packet_data_store' else 66 if name == 'cb_cross_end' else 48
        pointer = '%local' if name == 'foreign_cb_store' else '%ctx'
        middle = f'''  %stored = call i64 asm sideeffect "$0 = $2\\0A*(u8 *)($1 + $3) = $0\\0A$0 >>= 8\\0A*(u8 *)($1 + $4) = $0\\0A$0 >>= 8\\0A*(u8 *)($1 + $5) = $0\\0A$0 >>= 8\\0A*(u8 *)($1 + $6) = $0", "=&r,r,r,i,i,i,i,~{{memory}}"(ptr {pointer}, i64 7, i64 {offset}, i64 {offset+1}, i64 {offset+2}, i64 {offset+3})\n'''
    left = '%carried' if name == 'identity_stale' else '%first'
    section = 'xdp' if name == 'xdp_cb_store' else 'classifier'
    result = '  %answer = xor i64 %value, %choice\n  ret i64 %answer' if name in {'private_choice','foreign_choice','class_choice'} else '  ret i64 %value'
    controls+=f'''\ndefine i64 @ir_data_{name}(ptr %ctx) section "{section}" {{
  %local = alloca [4 x i8]
  %first = call i64 asm sideeffect "$0 = *(u32 *)($1 + $2)", "=r,r,i,~{{memory}}"(ptr %ctx, i64 76)
{middle}  %second = call i64 asm sideeffect "$0 = *(u32 *)($1 + $2)", "=r,r,i,~{{memory}}"(ptr %ctx, i64 76)
  %value = add i64 {left}, %second
{result}
}}
'''
for name,callee in [('ir_readonly_loop','read_context'),('ir_mutating_loop','mutate_context')]:
    controls+=f'''\ndefine i32 @{name}(ptr %ctx) section "classifier" {{
entry:
  %kernel = call ptr @bpf_cast_to_kern_ctx(ptr %ctx)
  %len = call i64 asm sideeffect "$0 = *(u32 *)($1 + $2)", "=r,r,i,~{{memory}}"(ptr %kernel, i64 112)
  %data_len = call i64 asm sideeffect "$0 = *(u32 *)($1 + $2)", "=r,r,i,~{{memory}}"(ptr %kernel, i64 116)
  %left = trunc i64 %len to i32
  %right = trunc i64 %data_len to i32
  %span = sub i32 %left, %right
  br label %loop
loop:
  %iteration = phi i32 [0, %entry], [%next, %body]
  %again = icmp ult i32 %iteration, 3
  br i1 %again, label %body, label %check
body:
  call void @{callee}(ptr %ctx)
  %next = add i32 %iteration, 1
  br label %loop
check:
  %compare = icmp uge i32 %span, 42
  %result = zext i1 %compare to i32
  ret i32 %result
}}
'''
(out/'controls.explicit.ll').write_text(controls)
run([compiler,out/'controls.explicit.ll','-o',out/'controls.lowered.bc'])
lowered=run(['llvm-dis-18',out/'controls.lowered.bc','-o','-'])
(out/'controls.lowered.ll').write_text(lowered)
bodies={name:body for name,body in re.findall(r'define [^@]+@(\w+)\([^\n]*\).*?\{(.*?)^}',lowered,re.S|re.M)}
positive=['head_ge','head_not_lt','old_tc','old_xdp','asm_tc',*explicit,'ir_readonly_loop',*boundary]
negative=['wrong_root','wrong_offset','wrong_section','equality','signed_negative',
          'stale_call','stale_store','ir_mutating_loop']
observed={name:'packet_bound' in bodies[name] for name in positive+negative}
(out/'selection.json').write_text(json.dumps(observed,indent=2)+'\n')
data_observed = {}
for name, expected in data_controls.items():
    body = bodies['ir_data_'+name]
    arguments = re.search(r'%value = add i64 (%[\w.]+), (%[\w.]+)', body).groups()
    data_observed[name] = arguments[0] == arguments[1]
    assert data_observed[name] == (expected if mode == 'after' else False), (name, body)
    assert body.count('asm sideeffect "$0 = *(u32 *)($1 + $2)"') == 2, (name, body)
(out/'data-values.json').write_text(json.dumps(data_observed,indent=2)+'\n')
if mode=='before':
    assert not any(observed[name] for name in positive if name not in {'old_tc','old_xdp'}),observed
else:
    assert all(observed[name] for name in positive),observed
assert not any(observed[name] for name in negative),observed
assert all(observed[name] for name in ['old_tc','old_xdp']),observed
assert re.search(r'icmp eq i32 %span, 42',bodies['ir_edge_nondominating']),bodies['ir_edge_nondominating']
for name,predicate in zip(boundary,['ule','ugt','uge','ult']):
    expected=predicate if mode=='after' else ('ne' if '_ne_' in name else 'eq')
    assert re.search(r'icmp '+expected+r' i32 %span, 42',bodies[name]),(name,bodies[name])
    if mode=='after':
        assert not re.search(r'icmp (eq|ne) i32 %span, 42',bodies[name]),(name,bodies[name])
for name in positive:
    if observed[name]:
        bound=43 if name in {'ir_ule32','ir_ugt64','ir_ule64','ir_edge_eq_lower','ir_edge_ne_lower'} else 42
        assert re.search(r'packet_bound\w* = add i64 [^,\n]+, '+str(bound)+r'\b',bodies[name]),(name,bodies[name])
if mode=='after':
    run([root/'kprog/stock-path/bin/clang',*adapter.COMPILE_FLAGS,'-emit-llvm','-c',source,'-o',out/'fixture.frontend.bc'])
    run([compiler,out/'fixture.frontend.bc','-o',out/'fixture.bounds.bc'])
    adapter._compile_simulator_backend(root/'kprog/stock-path/bin/clang',out/'fixture.bpf.c',
        out/'fixture.bpf.o',run,compiled_input=out/'fixture.bounds.bc')
    (out/'b-disassembly.txt').write_text(run(['llvm-objdump-18','-dl',out/'fixture.bpf.o']))
(out/'result.json').write_text(json.dumps(dict(mode=mode,selection=observed,data_values=data_observed,
    b_emitted=mode=='after',scope='Actual IR selection boundaries and normal B emission; no stock or current-app pass.'),indent=2)+'\n')
print(json.dumps(observed),flush=True)
