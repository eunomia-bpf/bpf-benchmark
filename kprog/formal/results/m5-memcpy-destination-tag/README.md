# The actual memcpy destination tag reads and current input interface

The original memcpy R0 selector,32/31 guards, tag-table/slot/byte reads, casts and actual tag assignment execute on the same heap. Current raw-16/tag4 comes from the same loop packet. The actual86-step destination setup plus20-step tag-reader/loop-exit route reaches the original writer-arm continuation in106 transitions. Its actual temps181/182/183/t18 and selector__3 retain original entry, counter, length and source tag; the next route reads the actual byte offset and exact tag bits. Current packet and all producer/callee memory resources remain on the same heap; actual source-byte read/store bodies follow.

Focused build 379 and 5 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
