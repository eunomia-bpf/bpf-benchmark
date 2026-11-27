# Share real byte-store proof across data registers while retaining the W1 interface

One imported checked STRB proof now covers every data register0..30 at X0, including actual base/data aliasing, with kernel-decoded real words. Existing STRB W1,[X0] execute/native/reference APIs are direct instances of the shared proof and keep their types and real39000001 word. Actual W3 uses39000003, so memcpy can retain source pointerX1 and store the just-loaded W3. Public queries check the two concrete encodings and generic/old native signatures; the focused build checks existing original memset physical clients. No numerical ISA or runtime body changes.

Focused build 337 and 5 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
