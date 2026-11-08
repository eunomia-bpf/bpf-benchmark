# BCC/Katran after canonical stack spill representation

BCC/Katran original whole apps: generated26, compiled26, installed26, failures0; work status [["bcc/set", "ok"], ["katran", "ok"]].

| Application | Generated | Compiled | Installed | Failed |
| --- | ---: | ---: | ---: | ---: |
| BCC | 25 | 25 | 25 | 0 |
| Katran | 1 | 1 | 1 | 0 |

The original whole applications and two-second workload use the captured existing c-runner image, d963788c0 C model/generator, native-link015a and common loader7a39cbba. `inputs.json` pins the copied source and image. Per-program raw service records, native inputs, complete workload counters/errors and result archives retain their measured domains. The combined native records are grouped by Katran original entry balancer_ingress and the BCC entries. Original resident/runtime rows and terminal native requests remain separate. This is a functional replay; R retains timing and same-work attribution ownership. No runtime admission check, limit or per-program proof was added.

Work observations from the captured raw phase counters:

| Application/phase | Programs/positive | BPF calls | Work |
| --- | ---: | ---: | --- |
| bcc/set/baseline | 25/17 | 15375566 | stressor operations {"cap": 386837, "set": 27847, "sockfd": 160620, "syscall": 514} |
| bcc/set/post_rejit | 25/17 | 15792934 | stressor operations {"cap": 395159, "set": 28914, "sockfd": 165342, "syscall": 514} |
| katran/baseline | 1/1 | 2494748 | sent 2494748; VIP/LRU/TX 2494748/2494748/2494748; LRU miss 0; RX 2494529; LB TX drops 0; RX drops 219 |
| katran/post_rejit | 1/1 | 2500298 | sent 2500298; VIP/LRU/TX 2500298/2500298/2500298; LRU miss 0; RX 2499991; LB TX drops 40; RX drops 267 |

Packet receive counts and per-interface drop reasons remain raw observations. Cold BCC hooks remain named in work-observations.json; installed programs and observed execution retain separate counts. No workload, duration, pass criterion or program selection changed. R retains timing/attribution ownership.
