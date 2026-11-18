# Actual helper-macro argument evaluation

Scope: the actual core-compat.h helper expansion with an observable key
expression. The smallest fixture includes the existing header and compares
a direct C callback with bpf_map_lookup_elem. The native path is compiled
separately to LLVM IR with its actual selector. The host executable aliases
only the selector function after inclusion, preserving the macro's operand
evaluation while returning a safe real callback address.

MICRO_NATIVE_HELPER_MACROS and __KPROG_HELPERS_ARE_POINTERS match OTel's
producer mode. __KPROG_SCAN_ONLY__ bypasses unused CO-RE answer includes;
the tested helper definitions remain the actual header. The fixture uses
the native O3/ABI flags and adds normal diagnostics. Each helper argument
expression should execute once, like an ordinary C function call. The
counter and selected key pointer make that behavior observable. Exit1
records the header regression; exit2 records a control failure.

Run the committed wrapper with setsid nohup. It holds timing SH/image SH,
uses CPU19 and4GiB AS. Every compile/error/execution result stays under
/workspaces/kprog-raw/perf/helper-arguments-20261118. Producer/header source,
canonical CLI, current guest/base/image and benchmark remain in use.
An actual-header result establishes the macro contract; app work and
installed/per-call effects require caller evidence and the Omp all-LTO batch.

The first build exits2 because the unused scan-only CO-RE declaration
triggers -Wunused-function under the fixture's -Werror. Its raw compile log
stays in host-20261118T024305Z-2879253. The forward recipe adopts OTel's
existing -Wno-unused-function/-Wno-unused-variable diagnostics from its
actual producer command. Helper/source behavior and remaining diagnostics
retain their current settings.
