# One generic GPR execution proof over actual stores

The existing nine-step returned-input and ten-step literal-zero proof bodies
are moved unchanged to declaration_return_body_stored/zero_body_stored.
They now take the actual world/function/environment,actual word/tag bindings,
and the SAME successful word/tag stores,without the old producer allocation
container. No instruction/expression/store/branch evaluator is added.

Both original mature APIs keep their complete types and delegate ONCE to the
same proof with their existing witness fields. Compatibility.lean states BOTH
full original types and is kernel-checked. Four type+axiom queries cover both
new and both old interfaces;all use standard Lean logic only.

This is an execution interface,not construction of actual caller storage.
The real795-local allocator must still derive the caller's two successful
stores,permissions/separation/readbacks/frame. Only then can its SAME witnesses
instantiate these helpers. No old/actual heap or entire composite environment
is equated,and no successful final reader or callback is introduced.
Actual caller source/callee preparation remains the previous accepted step;
full provider/writeback composition/native/global/universal/M6 remain open.

Focus/full default root,2complete old-type examples and4public queries use
CPU17/nice0/j1/32GiB/sharedtiming/heartbeat200000/recursion512;full also hasEXlock.
Preexisting simp warnings are retained with unchanged proof bodies.
V owns makecheck;runtime/kernel/framework/paper/design sources are untouched.
