# Derive real checked writes initialization and full physical frames

The actual mature checked-write body takes the original wrapping writable range and returns the genuine byte-store state. Its exact memory, ordered true-initialization write event and updated profile derive directly from that body. Every written byte is initialized even across wrap64; outside the actual range initialization remains. All architectural fields, program, monitors, atomic history and thread inputs remain. The helper only names imported effects and proves their frame; it implements no replacement memory interpreter.

Focused build 85 and 4 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
