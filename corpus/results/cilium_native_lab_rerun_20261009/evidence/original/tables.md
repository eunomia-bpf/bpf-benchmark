# Detailed post-hoc results

All completed scheduled phases are included. Ratios below are ratios of arm medians; paired-ratio distributions are also shown. PPS is the sum of the two kernel pktgen **generated** rates, not receiver goodput. Pooled ns/run is sum(run_time_ns_delta)/sum(run_cnt_delta) within each phase. Entry time includes its tail-call chain; zero run counts do not imply an unused tail program. No minimum-count filter is applied.

## Overall and restart controls

| Source / experiment | JIT ns/run | Second-arm ns/run | JIT/second ns ratio | JIT PPS | Second-arm PPS | Second/JIT PPS ratio |
|---|---|---|---|---|---|---|
| paper native-stats-1 | 1114.110 [1038.715, 1416.002]; IQR [1066.953, 1124.062] | 175.434 [172.777, 185.046]; IQR [174.620, 184.559] | 6.350578 | 1016065.000 [858973.000, 1063079.000]; IQR [1005734.000, 1042113.000] | 2270424.000 [2213827.000, 2301665.000]; IQR [2246594.000, 2292528.000] | 2.234526 |
| paper native-stats-0 | stats off | stats off | — | 1046645.000 [992362.000, 1076995.000]; IQR [1016598.000, 1067990.000] | 2407456.000 [2391813.000, 2427897.000]; IQR [2406882.000, 2411280.000] | 2.300165 |
| paper control-stats-1 | 1100.423 [1022.145, 1130.745]; IQR [1056.396, 1122.082] | 1076.998 [1056.553, 1198.628]; IQR [1063.459, 1169.235] | 1.021750 | 1025338.000 [1001578.000, 1067614.000]; IQR [1007437.000, 1054203.000] | 1034801.000 [962113.000, 1048292.000]; IQR [984644.000, 1042296.000] | 1.009229 |
| paper control-stats-0 | stats off | stats off | — | 1086240.000 [1061425.000, 1095746.000]; IQR [1073513.500, 1095139.250] | 1073646.000 [1052244.000, 1142018.000]; IQR [1060294.500, 1098740.000] | 0.988406 |

Median [min, max]; IQR [Q1, Q3]. Each group has five pairs. For controls, the second arm is JIT after the same stop/restart sequence.

| Source / experiment | Paired JIT/second ns ratios | Paired second/JIT PPS ratios |
|---|---|---|
| paper native-stats-1 | 6.110 [5.921, 7.652]; IQR [6.091, 6.448] | 2.234 [2.136, 2.577]; IQR [2.200, 2.265] |
| paper native-stats-0 | stats off | 2.300 [2.254, 2.410]; IQR [2.254, 2.372] |
| paper control-stats-1 | 0.967 [0.936, 1.022]; IQR [0.961, 1.000] | 0.983 [0.955, 1.009]; IQR [0.976, 0.994] |
| paper control-stats-0 | stats off | 0.996 [0.977, 1.042]; IQR [0.987, 1.012] |

## Per-program timing

Attachment keys identify the same endpoint/interface role across fresh starts; IDs change. Unbound-name rows combine same-name records and report their multiplicity. Full individual program IDs, names, raw counters, code sizes and dump coverage remain in programs.csv. No undefined ns/run is replaced by zero.

| Source | Control? | Arm | Attachment or name/type | Records | Median run count | Total run count | ns/run median [min, max]; IQR |
|---|---|---|---|---|---|---|---|
| paper | False | baseline | tc:bpfbench0:tcx/egress | 5 | 1 | 5 | 1521.000 [1295.000, 1843.000]; IQR [1516.000, 1791.000] |
| paper | False | baseline | tc:bpfbench0:tcx/ingress | 5 | 1 | 5 | 1084.000 [975.000, 1339.000]; IQR [1012.000, 1299.000] |
| paper | False | baseline | tc:cilium_host:tcx/egress | 5 | 1 | 5 | 1282.000 [1218.000, 1408.000]; IQR [1271.000, 1340.000] |
| paper | False | baseline | tc:cilium_host:tcx/ingress | 5 | 1 | 4 | 791.500 [726.000, 1172.000]; IQR [743.250, 918.500] |
| paper | False | baseline | tc:cilium_net:tcx/ingress | 5 | 1 | 5 | 753.000 [669.000, 1216.000]; IQR [684.000, 918.000] |
| paper | False | baseline | tc:lxcbench0:tcx/ingress | 5 | 15193477 | 74636822 | 1121.088 [1038.285, 1417.850]; IQR [1071.007, 1122.195] |
| paper | False | baseline | tc:lxcbench1:tcx/ingress | 5 | 15203540 | 74576943 | 1107.137 [1039.145, 1414.153]; IQR [1062.881, 1125.929] |
| paper | False | baseline | unbound-name:cil_from_host:sched_cls | 7 | 0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:cil_from_netdev:sched_cls | 4 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:cil_host_policy:sched_cls | 12 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:cil_lxc_policy:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:cil_lxc_policy_egress:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:cil_to_host:sched_cls | 4 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:cil_to_netdev:sched_cls | 4 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_drop_notify:sched_cls | 25 | 0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_handle_arp:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_handle_ipv4:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_handle_ipv4_cont:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_handle_ipv4_from_host:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_handle_ipv4_from_netdev:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_handle_snat_fwd_ipv4:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_ipv4_ct_egress:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_ipv4_ct_ingress:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_ipv4_policy:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_ipv4_to_endpoint:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_no_service_ipv4:sched_cls | 20 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_nodeport_nat_egress_ipv4:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_nodeport_nat_ingress_ipv4:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | False | baseline | unbound-name:tail_nodeport_rev_dnat_ipv4:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | baseline | xdp:bpfbench0:driver | 5 | 1 | 5 | 1059.000 [710.000, 1355.000]; IQR [893.000, 1119.000] |
| paper | False | post_rejit | tc:lxcbench0:tcx/ingress | 5 | 33895185 | 169339699 | 177.550 [171.424, 188.062]; IQR [176.152, 184.881] |
| paper | False | post_rejit | tc:lxcbench1:tcx/ingress | 5 | 34048895 | 169725775 | 174.141 [173.086, 184.238]; IQR [173.328, 182.061] |
| paper | False | post_rejit | unbound-name:cil_lxc_policy:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | post_rejit | unbound-name:cil_lxc_policy_egress:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | post_rejit | unbound-name:tail_drop_notify:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | post_rejit | unbound-name:tail_handle_arp:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | post_rejit | unbound-name:tail_handle_ipv:sched_cls | 20 | 0.0 | 0 | undefined (zero counts) |
| paper | False | post_rejit | unbound-name:tail_ipv4_ct_eg:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | post_rejit | unbound-name:tail_ipv4_ct_in:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | post_rejit | unbound-name:tail_ipv4_polic:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | post_rejit | unbound-name:tail_ipv4_to_en:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | post_rejit | unbound-name:tail_no_service:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | post_rejit | unbound-name:tail_nodeport_r:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | False | post_rejit | xdp:bpfbench0:driver | 5 | 1 | 5 | 963.000 [869.000, 1283.000]; IQR [938.000, 970.000] |
| paper | True | baseline | tc:bpfbench0:tcx/egress | 5 | 1 | 5 | 1314.000 [1059.000, 1399.000]; IQR [1189.000, 1368.000] |
| paper | True | baseline | tc:bpfbench0:tcx/ingress | 5 | 1 | 5 | 1210.000 [846.000, 1272.000]; IQR [1062.000, 1230.000] |
| paper | True | baseline | tc:cilium_host:tcx/egress | 5 | 1 | 5 | 1304.000 [1129.000, 1389.000]; IQR [1199.000, 1353.000] |
| paper | True | baseline | tc:cilium_host:tcx/ingress | 5 | 1 | 5 | 935.000 [572.000, 1480.000]; IQR [718.000, 1256.000] |
| paper | True | baseline | tc:cilium_net:tcx/ingress | 5 | 1 | 5 | 764.000 [691.000, 921.000]; IQR [755.000, 773.000] |
| paper | True | baseline | tc:lxcbench0:tcx/ingress | 5 | 15343750 | 77176960 | 1099.251 [1025.961, 1130.303]; IQR [1054.203, 1123.214] |
| paper | True | baseline | tc:lxcbench1:tcx/ingress | 5 | 15338602 | 77168873 | 1101.596 [1018.328, 1131.187]; IQR [1058.589, 1120.950] |
| paper | True | baseline | unbound-name:cil_from_host:sched_cls | 5 | 0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:cil_from_netdev:sched_cls | 3 | 0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:cil_host_policy:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:cil_lxc_policy:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:cil_lxc_policy_egress:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:cil_to_host:sched_cls | 3 | 0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:cil_to_netdev:sched_cls | 3 | 0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_drop_notify:sched_cls | 25 | 0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_handle_arp:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_handle_ipv4:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_handle_ipv4_cont:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_handle_ipv4_from_host:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_handle_ipv4_from_netdev:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_handle_snat_fwd_ipv4:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_ipv4_ct_egress:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_ipv4_ct_ingress:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_ipv4_policy:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_ipv4_to_endpoint:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_no_service_ipv4:sched_cls | 20 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_nodeport_nat_egress_ipv4:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_nodeport_nat_ingress_ipv4:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | True | baseline | unbound-name:tail_nodeport_rev_dnat_ipv4:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | baseline | xdp:bpfbench0:driver | 5 | 1 | 5 | 841.000 [760.000, 1088.000]; IQR [809.000, 896.000] |
| paper | True | post_rejit | tc:bpfbench0:tcx/egress | 5 | 1 | 5 | 1154.000 [1072.000, 1399.000]; IQR [1079.000, 1386.000] |
| paper | True | post_rejit | tc:bpfbench0:tcx/ingress | 5 | 1 | 5 | 1004.000 [971.000, 1274.000]; IQR [1004.000, 1008.000] |
| paper | True | post_rejit | tc:cilium_host:tcx/egress | 5 | 1 | 3 | 1546.000 [1041.000, 1724.000]; IQR [1293.500, 1635.000] |
| paper | True | post_rejit | tc:cilium_host:tcx/ingress | 5 | 1 | 4 | 1595.500 [1334.000, 1758.000]; IQR [1526.750, 1639.500] |
| paper | True | post_rejit | tc:cilium_net:tcx/ingress | 5 | 1 | 3 | 970.000 [805.000, 1587.000]; IQR [887.500, 1278.500] |
| paper | True | post_rejit | tc:lxcbench0:tcx/ingress | 5 | 15481550 | 75957063 | 1083.501 [1054.419, 1194.066]; IQR [1066.383, 1173.134] |
| paper | True | post_rejit | tc:lxcbench1:tcx/ingress | 5 | 15485638 | 75829477 | 1070.498 [1058.696, 1203.209]; IQR [1060.534, 1165.337] |
| paper | True | post_rejit | unbound-name:cil_from_host:sched_cls | 7 | 0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:cil_from_netdev:sched_cls | 4 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:cil_host_policy:sched_cls | 12 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:cil_lxc_policy:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:cil_lxc_policy_egress:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:cil_to_host:sched_cls | 4 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:cil_to_netdev:sched_cls | 4 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_drop_notify:sched_cls | 25 | 0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_handle_arp:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_handle_ipv4:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_handle_ipv4_cont:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_handle_ipv4_from_host:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_handle_ipv4_from_netdev:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_handle_snat_fwd_ipv4:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_ipv4_ct_egress:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_ipv4_ct_ingress:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_ipv4_policy:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_ipv4_to_endpoint:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_no_service_ipv4:sched_cls | 20 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_nodeport_nat_egress_ipv4:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_nodeport_nat_ingress_ipv4:sched_cls | 15 | 0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | unbound-name:tail_nodeport_rev_dnat_ipv4:sched_cls | 10 | 0.0 | 0 | undefined (zero counts) |
| paper | True | post_rejit | xdp:bpfbench0:driver | 5 | 1 | 5 | 853.000 [674.000, 918.000]; IQR [701.000, 865.000] |

## Program-set differences

Names below are the kernel BPF names (at most 15 characters), with program type. Name multiplicities are an inventory check, not proof of bytecode identity. all-loaded-end includes original/native copies and observer iterator programs. The exact difference for each pair and both snapshot times is in inventory-differences.csv; every inventory row is in inventories.csv.

| Source | Control? | Inventory | Name | Type | Observed (JIT, second) multiplicities when different |
|---|---|---|---|---|---|
| paper | False | all-loaded-end | cil_from_contai | sched_cls | (2, 4), (2, 5) |
| paper | False | all-loaded-end | cil_from_host | sched_cls | (1, 0), (1, 3), (2, 0), (3, 1), (3, 2), (3, 4) |
| paper | False | all-loaded-end | cil_from_netdev | sched_cls | (1, 2), (1, 5), (2, 1), (3, 2), (3, 6) |
| paper | False | all-loaded-end | cil_host_policy | sched_cls | (1, 0), (2, 0), (2, 1), (3, 0), (3, 1) |
| paper | False | all-loaded-end | cil_lxc_policy | sched_cls | (2, 4), (2, 5) |
| paper | False | all-loaded-end | cil_to_containe | sched_cls | (0, 2), (0, 3) |
| paper | False | all-loaded-end | cil_to_host | sched_cls | (2, 1), (2, 4), (3, 1), (3, 2) |
| paper | False | all-loaded-end | cil_to_netdev | sched_cls | (1, 0), (2, 0), (3, 0), (3, 1) |
| paper | False | all-loaded-end | cil_xdp_entry | xdp | (1, 3) |
| paper | False | all-loaded-end | tail_drop_notif | sched_cls | (5, 2) |
| paper | False | all-loaded-end | tail_handle_arp | sched_cls | (2, 4), (2, 5) |
| paper | False | all-loaded-end | tail_handle_ipv | sched_cls | (10, 9), (10, 11), (10, 12), (10, 15) |
| paper | False | all-loaded-end | tail_handle_sna | sched_cls | (3, 0), (3, 1) |
| paper | False | all-loaded-end | tail_ipv4_ct_eg | sched_cls | (2, 4), (2, 5) |
| paper | False | all-loaded-end | tail_ipv4_ct_in | sched_cls | (2, 4), (2, 5) |
| paper | False | all-loaded-end | tail_ipv4_polic | sched_cls | (2, 4), (2, 5) |
| paper | False | all-loaded-end | tail_ipv4_to_en | sched_cls | (2, 4), (2, 5) |
| paper | False | all-loaded-end | tail_no_service | sched_cls | (4, 5) |
| paper | False | all-loaded-end | tail_nodeport_n | sched_cls | (6, 0), (6, 1), (6, 2), (6, 3), (6, 4) |
| paper | False | all-loaded-end | tail_nodeport_r | sched_cls | (2, 4), (2, 5) |
| paper | False | shim-tracked | cil_from_host | sched_cls | (1, 0), (2, 0), (3, 0) |
| paper | False | shim-tracked | cil_from_netdev | sched_cls | (1, 0), (2, 0), (3, 0) |
| paper | False | shim-tracked | cil_host_policy | sched_cls | (1, 0), (2, 0), (3, 0) |
| paper | False | shim-tracked | cil_to_host | sched_cls | (2, 0), (3, 0) |
| paper | False | shim-tracked | cil_to_netdev | sched_cls | (1, 0), (2, 0), (3, 0) |
| paper | False | shim-tracked | tail_drop_notif | sched_cls | (5, 2) |
| paper | False | shim-tracked | tail_handle_ipv | sched_cls | (10, 4) |
| paper | False | shim-tracked | tail_handle_sna | sched_cls | (3, 0) |
| paper | False | shim-tracked | tail_no_service | sched_cls | (4, 2) |
| paper | False | shim-tracked | tail_nodeport_n | sched_cls | (6, 0) |
| paper | True | all-loaded-end | cil_from_host | sched_cls | (1, 3), (3, 1), (3, 2) |
| paper | True | all-loaded-end | cil_from_netdev | sched_cls | (1, 2), (2, 1), (2, 3), (3, 1) |
| paper | True | all-loaded-end | cil_host_policy | sched_cls | (1, 3), (3, 1), (3, 2) |
| paper | True | all-loaded-end | cil_to_host | sched_cls | (2, 3), (3, 2) |
| paper | True | all-loaded-end | cil_to_netdev | sched_cls | (1, 2), (2, 1), (2, 3), (3, 1) |
| paper | True | shim-tracked | cil_from_host | sched_cls | (1, 3), (3, 1), (3, 2) |
| paper | True | shim-tracked | cil_from_netdev | sched_cls | (1, 2), (2, 1), (2, 3), (3, 1) |
| paper | True | shim-tracked | cil_host_policy | sched_cls | (1, 3), (3, 1), (3, 2) |
| paper | True | shim-tracked | cil_to_host | sched_cls | (2, 3), (3, 2) |
| paper | True | shim-tracked | cil_to_netdev | sched_cls | (1, 2), (2, 1), (2, 3), (3, 1) |

## Verdicts and receiver counters

Cilium metrics reason 133 is DROP_POLICY. reason 0 contains both ingress and egress forwards, so it is not a single packet goodput total. Receiver count is the sum of eth0 RX packet deltas in bpfbench-cepa/cepb; the start snapshot follows warmup. Small residual counters can contain control packets. The metric key ABI and all packet/byte counters are preserved in verdicts.csv and map dumps.

| Source / experiment | JIT policy drops | Second policy drops | JIT receiver packets | Second receiver packets |
|---|---|---|---|---|
| paper native-stats-1 | 0.000 [0.000, 0.000]; IQR [0.000, 0.000] | 67944078.000 [66325203.000, 68855331.000]; IQR [67290304.000, 68650550.000] | 30397019.000 [25717233.000, 31779896.000]; IQR [30117794.000, 31201830.000] | 2.000 [2.000, 2.000]; IQR [2.000, 2.000] |
| paper native-stats-0 | 0.000 [0.000, 0.000]; IQR [0.000, 0.000] | 72140463.000 [71603673.000, 72685416.000]; IQR [72051009.000, 72275923.000] | 31356976.000 [29682930.000, 32255230.000]; IQR [30427897.000, 31980386.000] | 2.000 [1.000, 2.000]; IQR [1.000, 2.000] |
| paper control-stats-1 | 0.000 [0.000, 0.000]; IQR [0.000, 0.000] | 0.000 [0.000, 0.000]; IQR [0.000, 0.000] | 30682354.000 [29962556.000, 31943325.000]; IQR [30158204.000, 31599397.000] | 30967189.000 [28799975.000, 31391855.000]; IQR [29439654.000, 31187872.000] |
| paper control-stats-0 | 0.000 [0.000, 0.000]; IQR [0.000, 0.000] | 0.000 [0.000, 0.000]; IQR [0.000, 0.000] | 32543443.000 [31825153.000, 32862316.000]; IQR [32161482.250, 32825549.500] | 32177841.500 [31504665.000, 34232708.000]; IQR [31761870.000, 32939235.500] |

## Host load

Every phase has its own host CPU and pod data in host-load-by-pod.csv. Values use the measurement window and 2-second samples. Pod labels are unavailable inside this Workspace; raw cgroup UIDs identify the other Workspaces. One CPU core is one second of CPU use per second of wall time.

| Source | Cgroup / host core | Median CPU cores [min, max] |
|---|---|---|
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod09a1f228_eee8_4db1_ba06_eda6f3459d9e.slice | 0.000876 [0.000732, 0.001386] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod0ebc7f80_468a_4244_bca2_10a69c0014f4.slice | 0.000694 [0.000414, 0.001044] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod158a60d2_4265_408a_a712_68c9b50163e1.slice | 0.001517 [0.000769, 1.005978] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod4b367fae_37ba_42a8_a04c_99245d42236b.slice | 0.000844 [0.000730, 0.001121] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod5326e3d9_3d16_4888_9463_77e185cc9a7b.slice | 0.001994 [0.001569, 0.002345] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod608dccb2_0b1c_4443_9ca0_2c69f18653e8.slice | 0.000819 [0.000659, 0.001545] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod68a54e77_460d_4995_b662_8a01cb57744b.slice | 0.006558 [0.005815, 0.007393] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod6f271fa0_8126_4c91_8b50_4d566636efd8.slice | 0.009458 [0.000764, 0.196393] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod6f9c8ac5_5dd4_42d4_99b0_9d9ef6a8857e.slice | 0.003369 [0.002675, 0.004067] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod782196e8_2a76_4c02_b88b_b488f0284425.slice | 0.000841 [0.000684, 0.001040] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod7f4d85fa_75df_4128_b9c8_7995a457fee1.slice | 0.000873 [0.000704, 0.001777] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod85533a5d_8960_40c5_9dfd_d2fe9b04fd43.slice | 0.000879 [0.000733, 0.001167] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod8bba1cc5_dc51_4603_b05d_706ddb35f2f1.slice | 0.021450 [0.017916, 0.024623] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod901a2100_a80e_45e9_9fea_d320be468e69.slice | 2.041288 [2.001020, 3.089257] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod96620a8e_a43a_4613_901f_335046583190.slice | 0.000817 [0.000718, 0.001140] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod9d7c6613_be87_42e2_8461_b68790e1bb9c.slice | 0.000874 [0.000742, 0.001522] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-poda83f5cb6_8bc9_4861_9d52_1af80152a681.slice | 0.000156 [0.000063, 0.000355] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-podac5f277a_088e_479d_85a5_1109737b565f.slice | 0.005023 [0.004343, 0.005494] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-podb2d96190_595f_498f_9e65_0debb1e347bf.slice | 0.000832 [0.000705, 0.001024] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-poddda3a3d1_1259_4a82_8646_8906bb6e3b24.slice | 0.000005 [0.000004, 0.000006] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-podeda64bb2_a833_458d_9c05_e161063d5adf.slice | 0.000830 [0.000712, 0.001562] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-podf242bd50_3891_48a0_9346_7f126d8e2c12.slice | 0.001005 [0.000902, 0.001296] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-podf45864ba_a6df_41ca_b771_6dbe61f9d801.slice | 0.002091 [0.001503, 0.002393] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-burstable.slice/kubepods-burstable-pod0a2aeaa5_22e0_4230_9df1_d0958f36121c.slice | 0.047645 [0.042598, 0.351042] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-burstable.slice/kubepods-burstable-pod5583a5fc_b2b3_43ad_8b01_db85b53a4cab.slice | 0.000000 [0.000000, 0.000000] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-burstable.slice/kubepods-burstable-pod7bdd0377_05f5_429a_8e99_fce3f85a4f0a.slice | 0.001882 [0.001743, 0.002015] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-burstable.slice/kubepods-burstable-pod9153f998_2976_411b_b5b8_f506928592a4.slice | 0.000017 [0.000013, 0.000058] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-burstable.slice/kubepods-burstable-poda5646374_1aa4_48ad_b30e_2e8fac227e3a.slice | 0.000000 [0.000000, 0.000000] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-burstable.slice/kubepods-burstable-podb07d109d_04ba_45a8_b004_688eef085656.slice | 0.026521 [0.021214, 0.029702] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-burstable.slice/kubepods-burstable-podc07925e6_3532_498f_b53d_844cbc7d7b28.slice | 0.003618 [0.003275, 0.003948] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-burstable.slice/kubepods-burstable-podca355c33_8399_40a0_a321_6e1af6b5f729.slice | 0.000146 [0.000131, 0.000183] |
| paper | /sys/fs/cgroup/kubepods.slice/kubepods-burstable.slice/kubepods-burstable-pode31051f7_92f8_40b0_9141_076a4dd79e5e.slice | 0.001256 [0.000647, 0.001538] |
| paper | host:cpu0 | 0.099288 [0.047806, 0.266879] |
| paper | host:cpu1 | 0.990795 [0.959960, 1.000000] |
| paper | host:cpu10 | 0.035236 [0.022895, 0.104577] |
| paper | host:cpu11 | 0.037627 [0.024631, 0.092748] |
| paper | host:cpu12 | 0.037065 [0.024648, 0.090814] |
| paper | host:cpu13 | 0.037337 [0.017964, 0.086532] |
| paper | host:cpu14 | 0.034295 [0.019041, 0.087866] |
| paper | host:cpu15 | 0.033445 [0.021682, 0.080741] |
| paper | host:cpu16 | 0.033150 [0.020099, 0.101056] |
| paper | host:cpu17 | 0.037513 [0.027807, 0.091165] |
| paper | host:cpu18 | 0.038380 [0.022895, 0.095604] |
| paper | host:cpu19 | 0.034513 [0.021509, 0.085554] |
| paper | host:cpu2 | 0.137349 [0.084591, 0.482042] |
| paper | host:cpu20 | 0.033627 [0.020459, 0.096309] |
| paper | host:cpu21 | 0.036482 [0.021509, 0.105453] |
| paper | host:cpu22 | 0.034343 [0.019041, 0.087232] |
| paper | host:cpu23 | 0.034538 [0.021540, 0.085315] |
| paper | host:cpu3 | 0.123532 [0.077547, 0.264158] |
| paper | host:cpu4 | 0.989556 [0.957025, 1.000000] |
| paper | host:cpu5 | 0.123239 [0.072638, 0.263454] |
| paper | host:cpu6 | 0.108746 [0.046176, 0.267958] |
| paper | host:cpu7 | 0.080471 [0.046446, 0.258280] |
| paper | host:cpu8 | 0.039923 [0.021119, 0.993272] |
| paper | host:cpu9 | 0.037696 [0.022183, 0.095171] |
