# Original kernel C and Tetragon with precise RSP displacement

The private canonical model keeps the original RSP direct displacement expression visible to clang for MOV loads and stores. Raw address arithmetic, memory widths, operations and native branch values retain their original expressions. Other native-base compiler opacity retains its original path.

Actual compiler observations are in observations.json. The exact complete event_execve native object SHA25675318ea561e4c3ae7820a52871288cf57bb60a4111628b9988384ff4aa81f304 and original map metadata accompany the archive. Canonical baseline measures17118BPF instructions/frame1280. Kernel stock-verifier and whole-application outcomes retain their own stages. Host regressions and native safety replays occupy separate receipts. Source adoption0; runtime admission additions0.
