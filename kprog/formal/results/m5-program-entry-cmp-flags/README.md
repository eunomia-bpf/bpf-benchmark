# Actual reached compare flag bytes and updated current packet

The SAME four actual stored bytes derive the new N/Z/C/V packet map from imported AddWithCarry. Source Z/N/C/V ordering and real masked-byte encodings are proved explicitly. Actual pointer reads from the reached heap yield these new bytes. The current packet retains GPR/tag pairs, vectors, ABI/is_xdp and all copied/source bytes, and represents the imported flag writer; its other native observations are preserved. This is a reached flag-state relation; native instruction/PC composition follows.

Focused build 516 and 8 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
