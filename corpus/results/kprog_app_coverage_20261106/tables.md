| Application | Native artifacts | Generated | Compile done | Compiled | Artifact accepted | Verifier rejected | Load preparation failed |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| bcc | 34 | 34 | 34 | 10 | 0 | 0 | 10 |
| cilium | 82 | 82 | 82 | 2 | 0 | 0 | 0 |
| katran | 6 | 6 | 6 | 3 | 1 | 2 | 0 |
| otelcol-ebpf-profiler | 30 | 30 | 30 | 3 | 2 | 0 | 0 |
| tetragon | 809 | 809 | 84 | 12 | 0 | 0 | 0 |
| tracee | 175 | 175 | 0 | 0 | 0 | 0 | 0 |

Failure causes at this checkpoint:

- 182 × compile-failed: `A call to built-in function 'abort' is not supported.`
- 14 × compile-failed: `compiler exit 124`
- 10 × load-preparation-failed: `libbpf: failed to find BTF for extern 'stats': -3`
- 3 × compile-failed: `clang frontend command failed with exit code 135 (use -v to see invocation)`
- 2 × compile-failed: `clang frontend command failed with exit code 134 (use -v to see invocation)`
- 2 × compile-failed: `expected ';' after top level declarator`
- 1 × verifier-rejected: `invalid size of register fill`
- 1 × verifier-rejected: `math between fp pointer and 3769483511 is not allowed`
- 1 × compile-failed: `expected identifier or '('`
- 1 × compile-failed: `expected ';' after do/while statement`
- 1 × compile-failed: `clang frontend command failed with exit code 139 (use -v to see invocation)`
