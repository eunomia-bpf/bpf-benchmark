"""Analyze retained Katran comparison cases without changing benchmark data."""
import argparse
import json
from pathlib import Path

from katran_counter_accounting import phase


def summarize(label, directory):
    run = Path(directory)
    app = json.loads((run/'details/apps/katran.json').read_text())
    meta = json.loads((run/'details/result.json').read_text())
    result = dict(label=label, run=str(run), status=app['status'], error=app['error'],
                  bpf_stats=meta['bpf_stats'], samples=meta['samples'],
                  workload_seconds=meta['workload_seconds'])
    if app['status'] != 'ok':
        return result
    arms = {name: phase(app[name], stats=meta['bpf_stats'])
            for name in ['baseline', 'post_rejit']}
    result['arms'] = arms
    result['throughput_native_over_bpf'] = (
        arms['post_rejit']['median_pps']/arms['baseline']['median_pps'])
    result['ordinal_sample_ratios'] = [b['reported_pps']/a['reported_pps']
        for a, b in zip(arms['baseline']['samples'], arms['post_rejit']['samples'])]
    result['per_call_bpf_over_native'] = (
        arms['baseline']['ns_per_invocation']/arms['post_rejit']['ns_per_invocation']
        if meta['bpf_stats'] else None)
    result['programs'] = {name: list(app[name]['bpf'].values())
                          for name in ['baseline', 'post_rejit']}
    result['installed_code_bytes'] = {name: sum(p['bytes_jited'] for p in programs)
                                      for name, programs in result['programs'].items()}
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run', nargs=2, action='append', required=True,
                        metavar=('LABEL', 'DIRECTORY'))
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    rows = [summarize(label, directory) for label, directory in args.run]
    result = dict(cases=rows, scope='Read-only analysis: median reported successful pktgen pps per arm; all recorded program code bytes. No run discarded. Stats-off per-call/body timing is not measured.')
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps([dict(label=r['label'], status=r['status'],
                          throughput=r.get('throughput_native_over_bpf'),
                          per_call=r.get('per_call_bpf_over_native')) for r in rows]))


if __name__ == '__main__':
    main()
