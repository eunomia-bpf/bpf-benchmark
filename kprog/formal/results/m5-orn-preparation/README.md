# Original ninth ORN32 caller and fetched LNSym step

The actual source afterCneg sequence supplies all nine original ORN arguments:
opcode 53, destination7, source6/source3, sentinel255, width4, packed AUX65792
and immediate0. The proof executes source argument casts and the real target
binding, allocates the actual generic frame, and retains the original afterOrn
successor. The packed AUX expression derives modifier1 and shift1.

The native proof binds ORN W7,W6,W3,LSL1 to the pinned LNSym logical-shifted
register semantics, using the fetched decoder certificate. It proves W32
upper-word clearing and retains histories, PC+4, empty events and no fault.
Bit-width normalization reduces the imported native operation and the source
OR/NOT expression to the same value; architectural semantics remain imported.

Focused build 256 and seven public type/axiom queries pass at original
200000-heartbeat/512-depth caps, CPU 17, one worker, 32 GiB and shared timing
lock. Initial attempts exposed a dependent datasize instance during broad
simplification; first reducing the concrete imported width32 operation then
normalizing registers proves the result. Their logs remain. Native queries
report standard logic; source execution also carries the inherited external-
function/assembly assumptions.

The next components connect actual reader/modifier execution, ORN arithmetic,
scalar writer, complete handler and original ninth caller/native prefix.
The complete original program theorem currently reaches eight calls.
V coordinates whole confirmation. Raw evidence:
/workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
