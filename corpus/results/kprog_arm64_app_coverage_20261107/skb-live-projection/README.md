Generic ARM live skb context projection

The candidate gives the simulator the actual kernel-context address through
bpf_cast_to_kern_ctx. Packet and qdisc cb accesses select the corresponding live
BPF context fields; other accesses retain their native kernel address and width.
Derived bases contribute their actual byte delta. Native CB writes reach the
live context immediately, and return retains that state. The compiler erases
the earlier local mirror from this TC path.

Host UBSan checks pass142,080 width/alias/full-context observations:88,320 cb
reads/writes and53,760 packet-field lanes. The host packet values originate in
u32 context fields. The actual ARM full-system QEMU control passes guest0/QEMU0,
returns31 from the original five cb values, executes37 aligned cb store/read
pairs, and preserves the expected20cb bytes and64packet bytes. The verifier
records569processed instructions,28states and312B stack. The generic fixture
uses the ordinary BPF load/test-run interface; whole-application generation-bound
adoption and universal ISA/ABI/link composition retain their separate interfaces.

The source patch and complete kit accompany inputs.tar.gz. checks.log.gz and
qemu-raw.tar.gz preserve executed commands, compilers, source/image hashes,
original setup/addressing diagnostics and final kernel logs. A signed native
field displacement keeps the constant ctx offset inside the BPF instruction.

Actual control commands from the Workspace repository root:

~~~sh
make -f /workspaces/.agent-state/kprog-lanes/A/skb-live-projection/Makefile check
make -f /workspaces/.agent-state/kprog-lanes/A/skb-live-projection/Makefile qemu
~~~

A private header overlay reuses the existing ARM differential warm build.
The807-form/826,368-state native-QEMU/C phase has zero differences; canonical
replay continues in the detached fidelity job identified by summary.json.
Current application guests retain their source epoch while that review runs.

Completed differential collection: Make exit0, 807 forms/826368 canonical cases. Exact compiled sources/static ELF, every result row, diagnostics and trace identity accompany the fidelity archives. The current source epoch remains captured through adoption.

The production ARM simulator now adopts this live skb projection after the captured application sequence closes. The generic component uses the actual kernel-context address and live packet/cb access paths. Complete application successors consume this production source in their captured epochs.
