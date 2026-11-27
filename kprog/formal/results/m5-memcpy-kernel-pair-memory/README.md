# Read back real STP bytes and prove split and single physical memory equal

Completed mature MemoryProofs supplies true wrapping adjacent-range separation and native write/read round trips. Both actual STP modes read back the exact high++low operand value across16 bytes, while every outside physical byte retains its original value. The actual state memory is the imported primitive write composition; initialization/profile/history/PC metadata leaves it intact. Imported bit-level reads identify each of the16 actual byte positions without a nonwrapping premise. Pointwise memory equality proves split write8/write8 and single write16 produce the same entire physical memory, including arbitrary original contents.

Focused build 96 and 8 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
