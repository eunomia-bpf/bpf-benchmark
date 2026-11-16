"""Reconcile frozen Katran pktgen throughput with its own sent/error/XDP counters."""
import argparse
from datetime import datetime
import json
from pathlib import Path
import re
import shutil
import statistics


def phase(raw, stats=True):
    samples=[]
    for index, workload in enumerate(raw['workloads']):
        threads=[]
        for component in workload['components']:
            text=component['stdout']
            counts=re.search(r'pkts-sofar:\s*(\d+)\s+errors:\s*(\d+)',text)
            result=re.search(r'Result: OK:\s*(\d+).*?usec,\s*(\d+)',text)
            rate=re.search(r'\n\s*(\d+)pps\b',text)
            if counts is None or result is None or rate is None:
                raise ValueError('Missing original pktgen counters: '+str(component['config']))
            sent, errors, usec=int(counts[1]),int(counts[2]),int(result[1])
            if sent!=int(result[2]):
                raise ValueError('Pktgen Current/Result successful-send counters differ')
            threads.append(dict(thread=component['config']['thread_id'],sent=sent,errors=errors,
                attempts=sent+errors,usec=usec,reported_pps=int(rate[1]),
                sent_pps=sent*1e6/usec,attempt_pps=(sent+errors)*1e6/usec,
                config=component['config']))
        sent=sum(t['sent'] for t in threads)
        errors=sum(t['errors'] for t in threads)
        sent_rate=sum(t['sent_pps'] for t in threads)
        attempt_rate=sum(t['attempt_pps'] for t in threads)
        samples.append(dict(index=index,threads=threads,sent=sent,errors=errors,attempts=sent+errors,
            reported_pps=sum(t['reported_pps'] for t in threads),sent_pps=sent_rate,
            attempt_pps=attempt_rate,rate_acceptance=sent_rate/attempt_rate,
            count_acceptance=sent/(sent+errors),wall_seconds=workload['duration_s']))
    sent=sum(s['sent'] for s in samples);errors=sum(s['errors'] for s in samples)
    programs=list(raw['bpf'].values())
    runs=sum(p['run_cnt_delta'] for p in programs)
    nanos=sum(p['run_time_ns_delta'] for p in programs)
    middle=sorted(samples,key=lambda s:s['reported_pps'])[len(samples)//2]
    return dict(samples=samples,sent=sent,errors=errors,attempts=sent+errors,
        attempt_error_fraction=errors/(sent+errors),count_acceptance=sent/(sent+errors),
        xdp_runs=runs if stats else None,xdp_minus_sent=runs-sent if stats else None,
        bpf_time_ns=nanos if stats else None,ns_per_invocation=nanos/runs if stats else None,
        median_pps=statistics.median(s['reported_pps'] for s in samples),median_sample=middle['index'])


def profile(capture, run):
    data=json.loads((capture/'attribution.json').read_text())
    app=json.loads((run/'details/apps/katran.json').read_text())
    metadata=json.loads((run/'details/result.json').read_text())
    output={}
    for arm in ['baseline','post_rejit']:
        runs=sum(r['run_cnt_delta'] for r in app[arm]['bpf'].values())
        buckets=data[arm]['buckets']
        groups=dict(program_text=['program_text'],clock=['bpf_ktime_get_ns','ktime_get_mono_fast_ns'],
                    map_lookup=['bpf_map_lookup_elem','htab_lru_map_lookup_elem',
                                '__htab_map_lookup_elem','lookup_nulls_elem_raw'])
        output[arm]=dict(runs=runs,total_samples=data[arm]['samples'],bpf_samples=data[arm]['bpf_samples'],
            bpf_share_of_capture=data[arm]['bpf_share_of_all'],
            configured_warmups=metadata['warmups'],configured_samples=metadata['samples'],
            configured_workload_seconds=metadata['workload_seconds'],
            normalization_scope='Full profile capture divided by measured-only run_cnt_delta; not a matched counter window.',
            samples_per_million_runs={name:sum(buckets[k][0] for k in names if k in buckets)*1e6/runs
                                      for name,names in groups.items()})
    windows={}
    for kind,arm,clock in re.findall(r'perf (start|stop) (\w+) ([\dTZ:-]+)',
                                    (capture/'phase-profile.log').read_text()):
        windows.setdefault(arm,{})[kind]=clock
    for arm,window in windows.items():
        output[arm]['capture_clock']=window
        output[arm]['capture_wall_seconds']=(datetime.fromisoformat(window['stop'])-
                                            datetime.fromisoformat(window['start'])).total_seconds()
    return output


def main(args):
    args.output.mkdir(parents=True,exist_ok=True)
    source=args.run/'details/apps/katran.json'
    app=json.loads(source.read_text())
    arms={arm:phase(app[arm]) for arm in ['baseline','post_rejit']}
    a,b=arms['baseline'],arms['post_rejit']
    ma=a['samples'][a['median_sample']];mb=b['samples'][b['median_sample']]
    decomposition=dict(median_attempt_rate_ratio=mb['attempt_pps']/ma['attempt_pps'],
                       median_acceptance_ratio=mb['rate_acceptance']/ma['rate_acceptance'],
                       exact_sent_rate_ratio=mb['sent_pps']/ma['sent_pps'],
                       reported_pps_ratio=b['median_pps']/a['median_pps'])
    prof=profile(args.profile_capture,args.profile_run)
    speed=a['ns_per_invocation']/b['ns_per_invocation']
    f=prof['baseline']['bpf_share_of_capture']
    result=dict(run=str(args.run),profile_run=str(args.profile_run),profile_capture=str(args.profile_capture),
        app_status=app['status'],arms=arms,per_call_speedup=speed,decomposition=decomposition,
        aggregate_sent_ratio=b['sent']/a['sent'],aggregate_attempt_ratio=b['attempts']/a['attempts'],
        aggregate_acceptance_ratio=b['count_acceptance']/a['count_acceptance'],profile=prof,
        hypothetical_serial_model=dict(share=f,speedup=speed,throughput=1/(1-f+f/speed)),
        xdp_action_drop_counters=None,
        scope='Read-only accounting of retained frozen-workload results; no new run or causal speedup attribution.')
    (args.output/'accounting.json').write_text(json.dumps(result,indent=2)+'\n')
    shutil.copyfile(source,args.output/'app-raw.json')
    shutil.copyfile(args.run/'metadata.json',args.output/'metadata-raw.json')
    shutil.copyfile(args.profile_capture/'attribution.json',args.output/'profile-attribution-raw.json')
    shutil.copyfile(args.profile_run/'details/apps/katran.json',args.output/'profile-app-raw.json')
    shutil.copyfile(args.profile_run/'details/result.json',args.output/'profile-metadata-raw.json')
    lines=['# Katran C4 packet accounting','',
        f'Source `{args.run.name}`, status `{app["status"]}`, stats on, three180-second samples. '
        'No workload or runner change; this is retrospective analysis.','',
        '| counter | eBPF | native |','| --- | ---: | ---: |']
    for label,key in [('successful pktgen sends','sent'),('pktgen transmit errors','errors'),
                      ('send attempts = sends + errors','attempts'),('XDP invocations','xdp_runs'),
                      ('XDP minus successful sends','xdp_minus_sent')]:
        lines.append(f'| {label} | {a[key]:,} | {b[key]:,} |')
    lines += [f'| error fraction of attempts | {a["attempt_error_fraction"]:.4%} | {b["attempt_error_fraction"]:.4%} |',
              f'| median reported successful pps | {a["median_pps"]:,.0f} | {b["median_pps"]:,.0f} |',
              f'| BPF ns/invocation | {a["ns_per_invocation"]:.4f} | {b["ns_per_invocation"]:.4f} |','',
        f'The frozen throughput ratio is **{decomposition["reported_pps_ratio"]:.6f}x**; '
        f'per-call speedup is **{speed:.6f}x**. Successful sends and XDP invocations differ by one in '
        'each arm. The capture cannot identify that one invocation or its exact boundary.','',
        'In the sole kernel, net/core/pktgen.c:3654 increments sofar only for NETDEV_TX_OK. '
        'NET_XMIT_DROP/NET_XMIT_CN increment errors separately. Therefore errors are additional '
        'failed attempts, not a subset of pkts-sofar. Subtracting errors from successful sends '
        'would invent a forwarded-packet count. The earlier94.6%/86.3% figures were errors per '
        'successful send; the attempt error fractions above use the correct denominator.','',
        'The veth transmit path enqueues before receive-side XDP. A full XDP receive ring returns '
        'NETDEV_TX_BUSY; the no-qdisc transmit branch can turn it into NET_XMIT_DROP. The receive '
        'path separately records XDP_DROP in xdp_drops. The retained C4 result has pktgen errors '
        'and program run counters, but no XDP action-drop/ethtool snapshots. These errors cannot '
        'be called XDP return-action drops, and neither accepted sends nor runs establish '
        'forwarded application packets.','',
        'For the actual median samples (baseline index'+str(a['median_sample'])+', native index'+
        str(b['median_sample'])+'), recomputing rates from every thread\'s original usec gives:', '',
        f'- attempted-send rate ratio: {decomposition["median_attempt_rate_ratio"]:.9f}x;',
        f'- successful-admission fraction ratio: {decomposition["median_acceptance_ratio"]:.9f}x;',
        f'- product: {decomposition["exact_sent_rate_ratio"]:.9f}x, versus '
        f'{decomposition["reported_pps_ratio"]:.9f}x using pktgen\'s integer pps.','',
        'Thus more attempts and a higher successful fraction account for the observed packet-rate '
        'ratio. Aggregate counts decompose similarly, but their ratio is not the frozen median metric. '
        'This accounting does not determine how much of either factor was caused by native code.','',
        f'Using {f:.4%} as a hypothetical serial-work fraction and the C4 per-call speedup yields '
        f'{result["hypothetical_serial_model"]["throughput"]:.6f}x. That model is not a bound on this '
        'asynchronous, queue-limited multicore packet path: profile share is across the capture\'s '
        'CPUs, not a measured fraction of the limiting queue/CPU, and failed sends do not execute '
        'BPF. It also comes from a different run. Do not restore the withdrawn45% inference.','',
        'The profile\'s start/stop log spans '+str(prof['baseline']['capture_wall_seconds'])+'s baseline and '+
        str(prof['post_rejit']['capture_wall_seconds'])+'s native, while its one workload sample is '
        'configured60s. Its global sample share must retain that capture-window scope; it is not '
        'a direct C4 critical-path fraction.','',
        'There is also a counter-window mismatch: profile details/result.json records one warmup '
        'and one measured60-second sample. corpus/driver.py emits measurement_start before '
        'measure_app_phase; runner/libs/rejit.py:440 runs warmups before the shim measure_start. '
        'The profile observer brackets the outer event, so its samples include warmup while '
        'run_cnt_delta excludes warmup. The table below is the literal raw quotient, not a '
        'matched-window per-call cost. No exact matching invocation denominator can be recovered '
        'from the retained C4/profile counter deltas.','',
        '| full-capture samples per million measured-only runs (window mismatch) | eBPF | native |',
        '| --- | ---: | ---: |']
    for key in ['program_text','clock','map_lookup']:
        lines.append(f'| {key} | {prof["baseline"]["samples_per_million_runs"][key]:.3f} | '
                     f'{prof["post_rejit"]["samples_per_million_runs"][key]:.3f} |')
    lines += ['',
        'The raw profile JSON labels baseline208420472 invocations and native217104606, with '
        'JIT sizes13641/10196 respectively. The earlier217.1M/208.4M prose reverses those '
        'denominators. The corrected table does not support the quoted native-body6% slowdown '
        'or unchanged normalized clock samples. These are sampled observations from a different '
        'run, not a causal attribution of C4\'s per-call gain.','',
        'The program-text bucket includes logic moved into the program by helper inlining; '
        'it is not an isolated measurement of unchanged application-body code generation. '
        'The clock helper still calls the same implementation; reducing its wrapper remains '
        'a candidate rather than a predicted saving of the entire clock sample share.','',
        'Next in the authorized order: after the remaining OTel app, use C\'s existing producer '
        'switches for the18:40 target-CPU/CMOV/sibling-call configuration and every LTO piece, then '
        'subset-time Katran. After that baseline, bind the clock helper directly to the same '
        'ktime_get_mono_fast_ns implementation. No new timing or improvement is claimed here.','']
    (args.output/'report.md').write_text('\n'.join(lines))


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ['run','profile-run','profile-capture','output']:
        parser.add_argument('--'+name,type=Path,required=True)
    main(parser.parse_args())
