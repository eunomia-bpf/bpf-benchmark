# CNT vector0 stores from original allocation permissions

The original 512-byte vector allocation supplies aligned writable access to vector0 offsets 0 and 8. Both actual Mint64 stores exist, and the first transports the second permission. Final reads recover both assigned words. All 31 other vectors and every chunk on other blocks retain their complete raw loads. The real access map and allocation frontier are preserved. Full CNT handler composition supplies these two assigned count results next.

Focused build 178 and 7 public type/axiom queries pass at the original 200000/512 proof caps, shared timing lock, CPU 17, one worker and 32 GiB. The public log records the imported axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
