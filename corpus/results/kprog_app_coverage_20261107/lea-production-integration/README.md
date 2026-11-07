# Shared LEA correction in the application producer

The x86 trusted producer now carries V154955ad9's shared LEA correction:
a unit-scale RCX index uses the equivalent ordinary base encoding, keeping the
readonly AUX marker distinct. Effective-address offset accumulation uses unsigned
64-bit addition and presents the resulting bit pattern as a signed offset.
The generator's overview follows that same C rule. The binary ELF readonly
reader and finite affine helper-stack origin transport remain in this epoch.

Local production checks pass: 8,401 effective-address cases under UBSan,
141 encoder/ABI cases, 3,072 CL host cases, 19 rendered MOVX host/BPF cases,
both packet-memory CL directions, five invalid width/REX controls and two
narrow XDP-context controls. V's published handoff preserves the 8,192-state
CPU/C/reference replay and BPF LLVM wrapping-add receipt. Universal refinement
and native-link obligations remain with the shared V/T laws.

Commands: `python3 kprog/formal/tools/generate_x86_mem_offset_spec.py --check`;
compile `kprog/formal/oracles/test_x86_mem_offset_route_host.c` with
`cc -O2 -g -fsanitize=undefined -fno-sanitize-recover=undefined -Ikprog/formal
-Ikprog/x86 -Ivendor/repos/bcc/src/cc/libbpf/src`, run its executable, then run
`python3 kprog/formal/tools/check_x86_flag_definedness.py`.
The raw archive includes exact commands, source snapshots and the first
header-search-path diagnostic followed by the completed invocation.
The serial whole Tetragon/Tracee application batch captures these source hashes.
