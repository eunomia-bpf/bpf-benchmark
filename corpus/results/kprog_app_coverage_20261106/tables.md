| Phase | Application | Available artifacts | Generation attempted | Generated | Compile done | Compiled | Artifact accepted | Verifier rejected | Load preparation failed |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| baseline | bcc | 34 | 34 | 34 | 34 | 10 | 0 | 0 | 10 |
| baseline | cilium | 82 | 82 | 82 | 82 | 2 | 2 | 0 | 0 |
| baseline | katran | 6 | 6 | 6 | 6 | 3 | 1 | 2 | 0 |
| baseline | otelcol-ebpf-profiler | 30 | 30 | 30 | 30 | 3 | 3 | 0 | 0 |
| baseline | tetragon | 809 | 809 | 809 | 809 | 165 | 35 | 130 | 0 |
| baseline | tracee | 175 | 175 | 175 | 133 | 4 | 4 | 0 | 0 |
| unbounded | bcc | 34 | 34 | 34 | 34 | 10 | 0 | 0 | 0 |
| unbounded | cilium | 82 | 82 | 82 | 82 | 2 | 2 | 0 | 0 |
| unbounded | katran | 6 | 6 | 6 | 6 | 3 | 0 | 0 | 0 |
| unbounded | otelcol-ebpf-profiler | 30 | 30 | 30 | 30 | 3 | 0 | 0 | 0 |
| unbounded | tetragon | 809 | 809 | 807 | 509 | 100 | 0 | 0 | 0 |
| unbounded | tracee | 175 | 175 | 175 | 0 | 0 | 0 | 0 | 0 |
| label | bcc | 34 | 34 | 34 | 34 | 10 | 0 | 0 | 0 |
| label | cilium | 82 | 82 | 82 | 82 | 2 | 2 | 0 | 0 |
| label | katran | 6 | 6 | 6 | 6 | 3 | 0 | 0 | 0 |
| label | otelcol-ebpf-profiler | 30 | 30 | 30 | 30 | 3 | 0 | 0 | 0 |
| label | tetragon | 809 | 809 | 807 | 300 | 56 | 0 | 0 | 0 |
| label | tracee | 175 | 175 | 175 | 0 | 0 | 0 | 0 | 0 |

Failure causes at this checkpoint:

- 772 × baseline/compile-failed: `A call to built-in function 'abort' is not supported.`
- 440 × unbounded/compile-failed: `A call to built-in function 'abort' is not supported.`
- 311 × label/compile-failed: `A call to built-in function 'abort' is not supported.`
- 125 × baseline/compile-failed: `compiler exit 124`
- 121 × baseline/verifier-rejected: `invalid size of register fill`
- 95 × unbounded/compile-failed: `compiler exit 124`
- 66 × label/compile-failed: `compiler exit 124`
- 10 × baseline/load-preparation-failed: `libbpf: failed to find BTF for extern 'stats': -3`
- 10 × baseline/verifier-rejected: `R8 pointer arithmetic with <<= operator prohibited`
- 3 × baseline/compile-failed: `clang frontend command failed with exit code 135 (use -v to see invocation)`
- 3 × unbounded/compile-failed: `clang frontend command failed with exit code 135 (use -v to see invocation)`
- 2 × baseline/compile-failed: `clang frontend command failed with exit code 134 (use -v to see invocation)`
- 2 × baseline/compile-failed: `expected ';' after top level declarator`
- 2 × unbounded/compile-failed: `invalid suffix 'G_X86_DIV_ARM_B32) { ' on integer constant`
- 2 × unbounded/compile-failed: `expected ';' after do/while statement`
- 2 × unbounded/generation-failed: `Traceback (most recent call last):
  File "/workspaces/repository/kprog/x86/micro-prog/generate_micro_sim_proofs.py", line 1323, in <module>
    raise SystemExit(main())
                     ^^^^^^
  File "/workspaces/repository/kprog/x86/micro-prog/generate_micro_sim_proofs.py", line 1314, in main
    written.append(write_one(bench, source_dir, args.output_dir, args.proof_object_dir))
                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/workspaces/repository/kprog/x86/micro-prog/generate_micro_sim_proofs.py", line 1290, in write_one
    output.write_text(render_program(name, insns, subfunctions,
                      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/workspaces/repository/kprog/x86/micro-prog/generate_micro_sim_proofs.py", line 1253, in render_program
    append_branch_or_ret(lines, insn, addrs,
  File "/workspaces/repository/kprog/x86/micro-prog/generate_micro_sim_proofs.py", line 1104, in append_branch_or_ret
    raise ValueError(f"unsupported unresolved call target in {insn.raw}")
ValueError: unsupported unresolved call target in call   0 <try_preload_arg>`
- 2 × label/generation-failed: `Traceback (most recent call last):
  File "/workspaces/repository/kprog/x86/micro-prog/generate_micro_sim_proofs.py", line 1327, in <module>
    raise SystemExit(main())
                     ^^^^^^
  File "/workspaces/repository/kprog/x86/micro-prog/generate_micro_sim_proofs.py", line 1318, in main
    written.append(write_one(bench, source_dir, args.output_dir, args.proof_object_dir))
                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/workspaces/repository/kprog/x86/micro-prog/generate_micro_sim_proofs.py", line 1294, in write_one
    output.write_text(render_program(name, insns, subfunctions,
                      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/workspaces/repository/kprog/x86/micro-prog/generate_micro_sim_proofs.py", line 1257, in render_program
    append_branch_or_ret(lines, insn, addrs,
  File "/workspaces/repository/kprog/x86/micro-prog/generate_micro_sim_proofs.py", line 1108, in append_branch_or_ret
    raise ValueError(f"unsupported unresolved call target in {insn.raw}")
ValueError: unsupported unresolved call target in call   0 <try_preload_arg>`
- 1 × baseline/verifier-rejected: `math between fp pointer and 3769483511 is not allowed`
- 1 × baseline/compile-failed: `expected identifier or '('`
- 1 × baseline/compile-failed: `expected ';' after do/while statement`
- 1 × baseline/compile-failed: `clang frontend command failed with exit code 139 (use -v to see invocation)`
- 1 × unbounded/compile-failed: `use of undeclared identifier 'X86_WIDTH_33'`
- 1 × label/compile-failed: `use of undeclared identifier 'X86_WIDTH_33'`
