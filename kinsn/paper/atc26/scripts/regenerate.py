#!/usr/bin/env python3
"""Reproduce ATC26 artifacts and report discrepancies; never collect data."""
import csv
import difflib
import json
import math
import re
import shutil
import subprocess

import fitz
import metrics as m
import plots
import provenance
import verify_figures

BUNDLE = m.BUNDLE
PAPER = BUNDLE / 'inputs/paper'
OUT = BUNDLE / 'output'


def locate(row):
    """Bind audit claims to the pinned current paper, retaining audit references."""
    row = dict(row)
    rel = row['source_file'].removeprefix('paper/')
    lines = (PAPER / rel).read_text().splitlines()
    text = row['source_text']
    row['audit_source_line'] = row['source_line']
    row['audit_source_text'] = text
    exact = [i for i, line in enumerate(lines, 1) if line.strip() == text.strip()]
    if exact:
        line = min(exact, key=lambda i: abs(i-int(row['source_line'])))
    else:
        # The pinned commits differ in wording. Locate the same prose line;
        # preserve the original audit reference alongside its current location.
        candidates = [(i, s) for i, s in enumerate(lines, 1)
                      if s.strip() and not s.lstrip().startswith('%')
                      and not s.lstrip().startswith('\\input')]
        # Matching wording alone can confuse nearby RQs. Constrain scalar
        # locations by the printed value already present in the audited line.
        value = str(row['claimed_value']).replace('%', '').replace(' cases', '')
        if re.fullmatch(r'\d+(?:\.\d+)?(?:--\d+(?:\.\d+)?)?', value):
            pattern = r'(?<![\d.])' + re.escape(value) + r'(?![\d.])'
            if re.search(pattern, text):
                numeric = [(i, s) for i, s in candidates if re.search(pattern, s)]
                if numeric:
                    candidates = numeric
        if rel == 'sections/3-characterization.tex' and row['claim'] == '27 pure-bytecode computation benchmarks':
            candidates = [(i, s) for i, s in candidates if 'We use 27 microbenchmarks' in s]
        if rel == 'sections/1-introduction.tex' and row['claim'] == 'production throughput increase up to (%)':
            candidates = [(i, s) for i, s in candidates if 'On production applications' in s]
        scores = [(difflib.SequenceMatcher(None, text, s.strip()).ratio(), i) for i, s in candidates]
        score, line = max(scores)
        if row['claim'] == '27 pure-bytecode computation benchmarks' or (rel == 'sections/1-introduction.tex' and row['claim'] == 'production throughput increase up to (%)'):
            score = 1
        if score < .45 and '12--23' in text:
            candidates = [i for i, s in enumerate(lines, 1) if '12--23' in s and not s.lstrip().startswith('%')]
            if len(candidates) == 1:
                line = candidates[0]
                score = 1
        if score < .45 and 'Lean 4' in text:
            line = next(i for i, s in enumerate(lines, 1) if 'Lean 4' in s and not s.lstrip().startswith('%'))
            score = 1
        if score < .45 and text.startswith('The examples include'):
            row['source_file'] = row['source_file'].replace('paper/', 'audit-paper/', 1)
            row['scope'] = 'removed from current body; audit snapshot only'
            row['notes'] += ' This example sentence was removed in the current paper revision.'
            return row
        if score < .45:
            raise RuntimeError(f'Cannot map audit claim to current paper: {rel}: {text}')
    row['source_line'] = line
    row['source_text'] = lines[line-1].strip()
    return row


def all_claims():
    chars, x86, arm, sizes = m.main_claims()
    # Metrics are freshly computed. Archived recomputed values are comparison
    # expectations only, never presented as output of this run.
    computed = {(r['source_file'], int(r['source_line']), r['claim']): r for r in m.ROWS}
    rows = []
    with (BUNDLE / 'inputs/inventory/paper-data.csv').open() as f:
        for old in csv.DictReader(f):
            if old['scope'] != 'body':
                continue
            key = old['source_file'], int(old['source_line']), old['claim']
            row = dict(old)
            if row['claim'] == 'five idiom-stress instruction-count expansion':
                ratios = []
                for name in ['rotate_dense', 'cond_select_dense', 'load_byte_recompose', 'extract_dense', 'endian_swap_dense']:
                    counts = []
                    for runtime in ['kernel', 'llvmbpf']:
                        assembly = (BUNDLE / 'inputs/idiom-disassembly' / f'{name}.{runtime}.asm').read_text()
                        counts.append(sum(bool(re.match(r'\s*[0-9a-f]+:\s+.*\t\s*[a-z][a-z0-9]*\b', line)) for line in assembly.splitlines()))
                    ratios.append(counts[0]/counts[1])
                row.update(recomputed_value=f'{min(ratios):.6f}--{max(ratios):.6f}',
                           verification='recomputed from retained disassembly', recomputable='yes')
            elif key in computed:
                row.update(computed[key])
                row['verification'] = 'recomputed from data/'
            else:
                row['recomputed_value'] = ''
                row['recomputable'] = 'no'
                row['verification'] = 'declaration or missing evidence; see cause'
                if row['version'] == 'revision':
                    row['match'] = 'no October EC2 raw data'
            rows.append(locate(row))
    # Some detailed audit metrics (e.g. the commented-out summary table) are
    # useful outputs even when the table is no longer included in the body.
    existing = {(r['source_file'], int(r['audit_source_line']), r['claim']) for r in rows}
    for key, row in computed.items():
        if key not in existing:
            row = dict(row, verification='recomputed from data/')
            rows.append(locate(row))
    # Report all numerical lines in current body files and the October revision,
    # including implementation counts not covered by the performance inventory.
    seen = {(r['source_file'], int(r['source_line'])) for r in rows}
    for prefix in ['', 'revision/']:
        base = PAPER / prefix
        for folder in ['sections', 'tables']:
            for path in sorted((base / folder).glob('*.tex')):
                rel = str(path.relative_to(PAPER))
                for line, text in enumerate(path.read_text().splitlines(), 1):
                    s = text.strip()
                    if not s or s.startswith('%') or (f'paper/{rel}', line) in seen:
                        continue
                    clean = re.sub(r'\\(?:cite|ref|label|input|begin|end|setlength|cmidrule)\{[^}]*\}', '', s)
                    clean = re.sub(r'x86-64|x86_64|ARM64|arm64|RQ[0-9]|#[0-9]', '', clean)
                    if s.startswith(('\\section', '\\subsection', '\\setlength', '\\renewcommand', '\\cmidrule', '\\begin')):
                        continue
                    nums = re.findall(r'(?<![A-Za-z_])\d[\d,]*(?:\.\d+)?(?:--\d+(?:\.\d+)?)?', clean)
                    if not nums:
                        continue
                    revision = bool(prefix)
                    rows.append(dict(claim_id=f'S{len(rows):04d}', version='revision' if revision else 'current',
                                     scope='body or retained table', kind='source declaration',
                                     source_file=f'paper/{rel}', source_line=line, source_text=s,
                                     claim='numerical source line: '+s, claimed_value='; '.join(nums),
                                     current_data_paths='', recomputed_value='', recomputable='no',
                                     match='no October EC2 raw data' if revision else 'source declaration; not independently measured',
                                     method='', notes='No October EC2 dataset or exact generator is retained.' if revision else
                                     'Preserved source values; instruction definitions/layout/version numerals are not benchmark measurements. '
                                     'Implementation LOC counts require the historical patch/base revisions, which are not recorded here.',
                                     verification='source reproduction only', audit_source_line='', audit_source_text=''))
    # Quantify convention differences, without altering the paper or its plots.
    for label, run, name, printed in [('Cilium tuned', m.CN, 'cilium__agent.json', 1.114),
                                      ('Katran conservative', m.KC, 'katran.json', 1.073),
                                      ('Katran coverage-max', m.KM, 'katran.json', .995)]:
        m.scalar('sections/7-evaluation.tex', 'reduces the number' if label == 'Cilium tuned' else
                 'conservative ARM64 policy' if label == 'Katran conservative' else 'throughput falls',
                 label+' throughput under stated median convention', printed,
                 m.throughput(run, name), [run], digits=3,
                 method='median post summed pktgen pps / median baseline summed pktgen pps',
                 notes='Body/plot uses a ratio of means for this policy; default stated convention is median.')
        rows.append(locate(dict(m.ROWS[-1], verification='recomputed from data/')))
    policy = {label: dict(throughput=m.throughput(run, name, agg), cost=m.paired_cost(counter, name)[0])
              for label, run, counter, name, agg in [
                  ('Cilium Full', m.CF, m.CFC, 'cilium__agent.json', m.statistics.median),
                  ('Cilium No Bulk', m.CN, m.CNC, 'cilium__agent.json', m.statistics.mean),
                  ('Katran Conservative', m.KC, m.KC, 'katran.json', m.statistics.mean),
                  ('Katran Full', m.KM, m.KM, 'katran.json', m.statistics.mean)]}
    vals = dict(characterization={a+' '+rt: m.gm(v) for (a, rt), v in chars.items()},
                micro_speedup=dict(x86=m.gm(x86), arm64=m.gm(arm)), code_size=sizes,
                Cilium_full=m.throughput(m.CF), Cilium_tuned_mean=m.throughput(m.CN, agg=m.statistics.mean),
                Cilium_tuned_median=m.throughput(m.CN),
                Katran_selected=m.throughput(m.KC, 'katran.json', m.statistics.mean),
                Katran_full=m.throughput(m.KM, 'katran.json', m.statistics.mean),
                native=m.throughput(m.NT),
                Cilium_full_paired_cost=m.paired_cost(m.CFC),
                Cilium_no_bulk_paired_cost=m.paired_cost(m.CNC))
    population = [b['name'] for b in m.data(m.LP)['benchmarks']]
    vals['load_time'] = {'population': len(population)}
    for field in ['object_load_ns', 'compile_ns']:
        ratios = []
        for path in m.LX:
            baseline, candidate = m.med(path, 'kernel', field), m.med(path, 'kernel_rejit', field)
            ratios.append(m.gm(candidate[n]/baseline[n] for n in population))
        vals['load_time'][field] = ratios
    vals['code_size_27_case_alternative'] = {}
    for label, path, baseline, runtime in [('x86', m.EX, m.BX, 'kernel'), ('arm64', m.EA, m.EA, 'kernel_rejit')]:
        a, b = m.med(path, runtime, 'size'), m.med(baseline, 'kernel', 'size')
        vals['code_size_27_case_alternative'][label] = m.gm(a[n]/b[n] for n in a if n not in ('simple', 'simple_packet'))
    vals['Katran_selected_median'] = m.throughput(m.KC, 'katran.json')
    vals['Katran_full_median'] = m.throughput(m.KM, 'katran.json')
    expected = m.js(BUNDLE / 'inputs/inventory/recomputed-metrics.json')
    def compare(actual, expected, name):
        if isinstance(expected, dict):
            for key, value in expected.items():
                compare(actual[key], value, name+'.'+key)
        elif isinstance(expected, list):
            for i, value in enumerate(expected):
                compare(actual[i], value, name+f'[{i}]')
        elif not math.isclose(actual, expected, rel_tol=1e-12, abs_tol=1e-12):
            raise RuntimeError(f'Inventory recomputation mismatch: {name}: {actual} != {expected}')
    compare(vals, expected, 'metrics')
    return rows, chars, x86, arm, policy, vals


def tables(chars, policy):
    target = OUT / 'tables'
    target.mkdir(parents=True, exist_ok=True)
    # Static lookup tables are authored sources, not fresh empirical evidence.
    for path in (PAPER / 'tables').glob('*.tex'):
        shutil.copyfile(path, target / path.name)
    path = target / 'sec-3-micro-summary.tex'
    text = path.read_text()
    arch = 'x86'
    lines = []
    for line in text.splitlines():
        if 'ARM64' in line:
            arch = 'arm'
        if re.search(r'\d\.\d+\$.*\d+/27', line):
            runtime = 'native_kernel' if 'In-kernel' in line else 'llvmbpf' if 'LLVM-BPF' in line else 'native'
            vs = chars[arch, runtime]
            line = re.sub(r'\d\.\d+(?=\$)', f'{m.gm(vs):.2f}', line)
            line = re.sub(r'\d+/27', f'{sum(v>1/.98 for v in vs.values())}/27', line)
        lines.append(line)
    path.write_text('\n'.join(lines) + ('\n' if text.endswith('\n') else ''))
    # This retained table is a 29-case predecessor; its population is explicit.
    path = target / 'sec-6-kinsn-micro.tex'
    text = path.read_text()
    x29 = m.med(m.EX, 'kernel'); b29 = m.med(m.BX, 'kernel'); a29 = m.med(m.EA, 'kernel_rejit'); ab29 = m.med(m.EA, 'kernel')
    text = text.replace('1.216', f'{m.gm(b29[n]/x29[n] for n in x29):.3f}')
    text = text.replace('1.208', f'{m.gm(ab29[n]/a29[n] for n in a29):.3f}')
    path.write_text(text)
    path = target / 'sec-6-RQ2-RQ3.tex'
    text = path.read_text()
    for name, original in [('Cilium Full', '1.074'), ('Cilium No Bulk', '1.114'),
                           ('Katran Conservative', '1.073'), ('Katran Full', '0.995')]:
        text = text.replace(original+'$\\times$', f"{policy[name]['throughput']:.3f}"+'$\\times$')
    path.write_text(text)
    # Source-table verification: same printed values; computed replacements above
    # would expose any discrepancy instead of overwriting inputs/paper/.
    checks = []
    for path in sorted(target.glob('*.tex')):
        match = path.read_bytes() == (PAPER / 'tables' / path.name).read_bytes()
        checks.append(dict(table=path.name, matches_paper_source=match,
                           method='computed numeric cells' if path.name in
                           ['sec-3-micro-summary.tex', 'sec-6-kinsn-micro.tex', 'sec-6-RQ2-RQ3.tex'] else
                           'authored source reproduction; empirical counts not independently established'))
        if not match:
            raise RuntimeError(f'Table output differs from pinned paper: {path.name}')
    (OUT / 'table-checks.json').write_text(json.dumps(checks, indent=2)+'\n')


def illustrations():
    # These two illustrations survive as authoritative PDFs, without exact export
    # sources. Re-emit their vector content; do not fabricate original JIT dumps.
    for file in ['sec-2-ebpf-pipeline-fig.pdf', 'sec-3-jit-dump-fig.pdf']:
        with fitz.open(PAPER / 'figures' / file) as doc:
            doc.save(OUT / 'figures' / file, garbage=4, deflate=True)
        with fitz.open(PAPER / 'figures' / file) as a, fitz.open(OUT / 'figures' / file) as b:
            if a[0].get_pixmap().samples != b[0].get_pixmap().samples:
                raise RuntimeError(f'Illustration content differs: {file}')
    # Current design diagram is inline TikZ, unlike the older exported pipeline.
    section = (PAPER / 'sections/4-bpfext.tex').read_text()
    diagram = section[section.index('\\begingroup'):section.index('\\endgroup')+len('\\endgroup')]
    work = OUT / 'latex'
    work.mkdir(exist_ok=True)
    wrapper = ('\\documentclass[tikz,border=2pt]{standalone}\n'
               '\\usepackage[T1]{fontenc}\n\\usepackage{lmodern}\n'
               '\\usepackage{xspace}\n\\usetikzlibrary{arrows.meta,calc}\n'
               '\\newcommand{\\tool}{\\textsc{BPF-Ext}\\xspace}\n'
               '\\newcommand{\\lang}{\\textsc{Kinsn}\\xspace}\n'
               '\\begin{document}\n'+diagram+'\n\\end{document}\n')
    (work / 'sec-4-pipeline.tex').write_text(wrapper)
    result = subprocess.run(['pdflatex', '-interaction=nonstopmode', '-halt-on-error',
                             'sec-4-pipeline.tex'], cwd=work, text=True,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    if result.returncode:
        raise RuntimeError('TikZ generation failed; see output/latex/sec-4-pipeline.log\n'+result.stdout[-4000:])
    shutil.copyfile(work / 'sec-4-pipeline.pdf', OUT / 'figures/sec-4-pipeline.pdf')
    shutil.copyfile(work / 'sec-4-pipeline.tex', OUT / 'figures/sec-4-pipeline.tex')


def reports(rows, vals):
    fields = list(dict.fromkeys(k for r in rows for k in r))
    with (OUT / 'numbers.csv').open('w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)
    (OUT / 'metrics.json').write_text(json.dumps(vals, indent=2)+'\n')
    lines = ['# Numbers and evidence report', '',
             'Generated from immutable `data/` by `make`; no paper or result input is edited.',
             'Every archived claim and numerical line in the pinned body/revision has a row',
             'in `numbers.csv`. Empty regenerated cells mean missing evidence or source-only',
             'declarations, never a successful measurement. Table/figure prose is retained',
             'as source, and its unsupported numbers remain explicitly unsupported.', '',
             '## Regenerated headline values', '',
             '| Quantity | Regenerated |', '| --- | --- |']
    for key in ['micro_speedup', 'code_size', 'Cilium_full', 'Cilium_tuned_mean',
                'Cilium_tuned_median', 'Katran_selected', 'Katran_full', 'native']:
        lines.append(f'| {key} | {json.dumps(vals[key])} |')
    lines += ['', 'All metrics in `inputs/inventory/recomputed-metrics.json` match fresh',
              'recomputation within 1e-12. All 224 published data bars match PDF geometry;',
              'see `figure-checks.md` and `figure-checks.json`.', '',
              '## Differences and evidence gaps', '',
              f"- Load time: printed 0.99; bare `object_load_ns` gives {' / '.join(f'{v:.9f}' for v in vals['load_time']['object_load_ns'])} (both round to 1.00). "
              f"Open-plus-load `compile_ns` gives {' / '.join(f'{v:.9f}' for v in vals['load_time']['compile_ns'])} (both round to 0.99). "
              'These May14 runs use one sample and INNER_REPEAT=10, with the Apr29 62-name population.',
              f"- Tuned Cilium: printed 1.114 is the ratio of means ({vals['Cilium_tuned_mean']:.9f}); the stated median convention gives {vals['Cilium_tuned_median']:.9f}, or 1.119. Katran policies also use means; the default median gives {vals['Katran_selected_median']:.9f} / {vals['Katran_full_median']:.9f} instead of printed 1.073 / 0.995.",
              '- Native-gap recovery: printed 5.4%; raw ratios give '
              f"{(vals['Cilium_full']-1)/(vals['native']-1)*100:.7f}%. Rounded inputs 1.074 and 2.358 give 5.449189%, which rounds to 5.4% (raw inputs round to 5.5%).",
              '- Hardware: x86 micro metadata says Core Ultra 9 285K; paper says Xeon Silver 4210R. '
              'The claimed 8-vCPU/64-GB VM sizing is not established by the raw runs. ARM metadata says aarch64, '
              'without independently establishing t4g.small/Graviton2. Corpus metadata does not record CPU/source/kernel commits.',
              f"- Code-size population: the printed evaluation ratios 0.772/0.879 use all 29 raw cases, including the two controls. Using the 27-case runtime population gives {vals['code_size_27_case_alternative']['x86']:.9f}/{vals['code_size_27_case_alternative']['arm64']:.9f}. The characterization now says code size across all 27, but its printed 0.54/0.49 are unchanged by that distinction at two decimal places.",
              '- Protocol: ARM userspace characterization has one sample/INNER_REPEAT=10000; kernel-native has three/100000. '
              'Katran retained corpus runs have bpf_stats=true, despite RQ2 saying stats disabled.',
              '- Application sites: Cilium 4086/3512, family counts 2346/385/766/2/587, zero skips/report errors; '
              'Katran 21/62 have no original report streams. Plot annotations are declarations, not regenerated measurements.',
              '- Native loader: 113 replacements, 22 pass-throughs, 89 objects and 8 files lack original streams/sidecars. '
              'The native interpretation is traced through the paper-facing analysis; retained raw config alone does not establish native selection.',
              '- Recognizer-inclusive load time: the exact 1.4–2.4x/sub-millisecond campaign is absent. '
              'Retained compile_ns measures open+load; candidate measurements include multiple milliseconds.',
              '- Exact Linux 6.1 rotate dumps / ISA-gap counts are absent. The illustration and table can be reproduced '
              'from authored sources, but their original counts cannot be independently measured. Related March19 '
              'disassemblies only support the separate five-probe 1.25–2.7x expansion claim.',
              '- Implementation counts (929-line kernel patch, component splits, exclusions and recognizer LOC) are source '
              'declarations; exact historical patch/base references are not recorded in this bundle.',
              '- Every October EC2 c7i/c7g measurement is unsupported by retained raw data: 12-instance characterization, '
              'micro/ablation, application throughput/CIs, CPU profiles and preparation costs. All numerical revision '
              'lines/cells are listed below. Older May/June data cannot regenerate them. Revision headline 1.24x, '
              '+7.4%/+7.3% conflicts with revision evaluation 1.17x and 0.970x/0.993x.',
              '- Final 27-case/combined-policy generators were not retained. `scripts/plots.py` reconstructs them from '
              'the archived scripts, audit calculations and published populations. Earlier 29-case and June6 ARM '
              'characterization sources would give different aggregates. Figure dates are rendering dates.', '',
              '## Every comparison', '',
              '| Paper location | Claim | Printed | Regenerated | Status / cause |',
              '| --- | --- | --- | --- | --- |']
    def cell(s):
        return str(s).replace('|', '\\|').replace('\n', ' ')
    for r in rows:
        loc = r['source_file'].removeprefix('paper/')+':'+str(r['source_line'])
        cause = r['match']+'; '+r.get('method', '')+'; '+r.get('notes', '')
        lines.append('| '+' | '.join(cell(v) for v in [loc, r['claim'], r['claimed_value'],
                                                       r['recomputed_value'] or 'unknown / source only', cause])+' |')
    (OUT / 'numbers.md').write_text('\n'.join(lines)+'\n')


def main():
    for sub in ['figures', 'tables']:
        (OUT / sub).mkdir(parents=True, exist_ok=True)
    rows, chars, x86, arm, policy, vals = all_claims()
    points = plots.draw(chars, x86, arm, policy, OUT / 'figures')
    (OUT / 'figure-points.json').write_text(json.dumps(points, indent=2)+'\n')
    count = verify_figures.compare(points, OUT)
    tables(chars, policy)
    illustrations()
    prov = provenance.generate(rows, OUT)
    reports(rows, vals)
    print(f'Regenerated 7 figure PDFs, {len(list((OUT / "tables").glob("*.tex")))} table sources, '
          f'{len(rows)} claim/number rows, and provenance for {len(prov)} data directories.')
    print(f'PASS: {count} published PDF bars and inventory metric recomputations match.')
    print('See output/numbers.md for differences and missing raw evidence.')


if __name__ == '__main__':
    main()
