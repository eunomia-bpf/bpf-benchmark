#!/usr/bin/env python3
"""Read selected Cilium config directives and model two concrete source consumers only."""
import json
from pathlib import Path
import re
import subprocess

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[2]
BPF = REPO / 'vendor/bpf/cilium/bpf'
RAW = Path('/workspaces/kprog-raw/perf/20261113-cilium-live-config/baseline-state/state')
wanted = {'MONITOR_AGGREGATION','CT_REPORT_FLAGS','CT_REPORT_INTERVAL','CT_CONNECTION_LIFETIME_TCP',
          'CT_SERVICE_LIFETIME_TCP','CT_SERVICE_CLOSE_REBALANCE','CT_SYN_TIMEOUT','IPV4_GATEWAY',
          'ENABLE_DSR','ENABLE_HOST_FIREWALL','ENABLE_NODEPORT_ACCELERATION','ENABLE_WIREGUARD',
          'TUNNEL_MODE','POLICY_AUDIT_MODE','TRACE_NOTIFY'}


def selected(path):
    rows = []
    for line_number,line in enumerate(path.read_text().splitlines(),1):
        match = re.match(r'\s*#\s*(define|undef)\s+(\w+)(?:\s+(.*))?$',line)
        if match and match[2] in wanted:
            rows.append(dict(line=line_number,action=match[1],name=match[2],value=match[3] or ''))
    return dict(path=str(path),directives=rows)


def monitor_level(cli, sample_node, endpoint_undef):
    level = cli
    if sample_node and level is None:
        level = 5
    if endpoint_undef:
        level = None
    return 0 if level is None else level


makefile=REPO/'vendor/bpf/Makefile'
text=makefile.read_text()
cli_monitor=re.search(r'-DMONITOR_AGGREGATION=(0x[0-9a-fA-F]+|[0-9]+)',text)
native_monitor=int(cli_monitor[1],0) if cli_monitor else None
cases = []
for label,cli,sample,ep_undef in [('current_native',native_monitor,True,False),
        ('remove_cli_define_only',None,True,False),('command_line_undef_only',None,True,False),
        ('explicit_numeric_zero',0,True,False),('agent_endpoint_undef',None,False,True)]:
    level=monitor_level(cli,sample,ep_undef)
    decisions=[]
    for rx in (False,True):
        for monitor in (0,128):
            decisions.append(dict(rx_observation=rx,monitor=monitor,
                emit=not ((level >= 1 and rx) or (level >= 3 and not monitor))))
    cases.append(dict(case=label,effective_monitor_level=level,trace_notify_enabled_decisions=decisions))
native_mask=int(re.search(r'-DCT_REPORT_FLAGS=(0x[0-9a-fA-F]+)',text)[1],0)
node=selected(RAW/'globals/node_config.h')
agent_mask=int(next(row['value'] for row in node['directives']
                    if row['action']=='define' and row['name']=='CT_REPORT_FLAGS'),0)
ct=[]
for flags in (0,1,2,4,0x10,0x11,0x12,0x14):
    results=[]
    for origin,mask in [('native',native_mask),('retained_agent',agent_mask)]:
        seen=flags & mask  # accumulated flags zero and report interval not elapsed
        results.append(dict(origin=origin,report_mask=mask,seen_flags=seen,
                            flags_and_last_report_writes=seen != 0,
                            emit_trace_notify_returns_true_at_none=True))
    ct.append(dict(tcp_flags=flags,results=results))
snapshots=[selected(BPF/'node_config.h'),selected(BPF/'ep_config.h'),node]
snapshots.extend(selected(path) for path in sorted((RAW/'templates').glob('*/ep_config.h')))
result=dict(recorded_utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),
    scope='Selected raw directives from current producer/sample sources and historical 2026-11-13 agent captures, plus finite models of lib/trace.h and conntrack.h. Not full preprocessing, current-run configuration proof, native/eBPF execution, dynamic frequency, packet parity or an admission check. No source header copied or edited.',
    makefile_source_revision=subprocess.check_output(['git','log','-1','--format=%h','--','vendor/bpf/Makefile'],cwd=REPO,text=True).strip(),
    selected_inputs=snapshots,monitor_cases=cases,
    ct_assumptions='TRACE_NOTIFY enabled; accumulated flags zero; last report within interval. Existing source branch writes flags and report time when new masked flags differ.',
    ct_report_mask_examples=ct)
(HERE/'cilium-config-inputs.json').write_text(json.dumps(result,indent=2)+'\n')
print('Monitor models:',{row['case']:row['effective_monitor_level'] for row in cases})
print('CT report masks:',hex(native_mask),hex(agent_mask),';',len(ct),'flag examples')
print('Retained endpoint snapshots:',len(snapshots)-3)
