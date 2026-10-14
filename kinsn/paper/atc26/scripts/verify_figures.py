"""Compare every data bar with the published PDF's vector geometry.

The PDFs outline some text, so extraction of printed text alone cannot verify
these plots. Rectangle heights and the 1x reference line recover the data.
"""
import collections
import json

import fitz
from metrics import BUNDLE

COLORS = {'native_kernel': (0.298, .471, .658), 'native': (.329, .635, .294),
          'llvmbpf': (.697, .475, .635)}
# Figure 6 (RQ3, RQ4): bars have #3a3a3a outlines and start at y = 0.64.
POLICY_EDGE = (.227, .227, .227)
POLICY_Y_MIN = .64


def rects_of(drawings, color):
    return [d['rect'] for d in drawings if d['fill'] is not None
            and max(abs(a-b) for a, b in zip(d['fill'], color)) < .003
            and len(d['items']) == 1 and d['items'][0][0] == 're']


def geometry(path):
    with fitz.open(path) as doc:
        drawings = doc[0].get_drawings()
    bars = {key: sorted([r for r in rects_of(drawings, color) if r.height > 20], key=lambda r: (r.y1, r.x0))
            for key, color in COLORS.items()}
    refs = sorted(set(d['rect'].y0 for d in drawings if d['fill'] is None
                      and d['rect'].width > 250 and d['rect'].height < .01
                      and d['dashes'] != '[] 0'))
    return bars, refs


def policy_geometry(path):
    """Bars of Figure 6 by their #3a3a3a outlines on the y=0.64 axis floor.

    The hatched native bars are filled with a tiling pattern, so their outlines,
    not fill colors, identify them; legend swatches do not stand on the floor.
    Each case is a throughput bar followed by its BPF cost bar.
    """
    with fitz.open(path) as doc:
        drawings = doc[0].get_drawings()
    outlines = [d['rect'] for d in drawings if d.get('color') is not None
                and max(abs(a-b) for a, b in zip(d['color'], POLICY_EDGE)) < .003
                and len(d['items']) == 1 and d['items'][0][0] == 're' and d['rect'].width > 5]
    floor = collections.Counter(round(r.y1, 1) for r in outlines).most_common(1)[0][0]
    rects = sorted((r for r in outlines if round(r.y1, 1) == floor), key=lambda r: r.x0)
    bars = {'throughput': rects[0::2], 'cost': rects[1::2]}
    refs = sorted(set(d['rect'].y0 for d in drawings if d['fill'] is None
                      and d['rect'].width > 100 and d['rect'].height < .01
                      and d['dashes'] != '[] 0'))
    return bars, refs


def compare(points, output):
    checks = []
    def check(file, names, expected, rects, one, tolerance, base=0.0):
        if len(rects) != len(expected):
            raise RuntimeError(f'{file}: expected {len(expected)} PDF bars, found {len(rects)}')
        rects = sorted(rects, key=lambda r: r.x0)
        recovered = [base + (r.y1-r.y0)/(r.y1-one)*(1-base) for r in rects]
        for name, actual, pdf in zip(names, expected, recovered):
            delta = abs(actual-pdf)
            checks.append(dict(artifact=origin, figure=file, point=name, regenerated=actual,
                               pdf_value=pdf, absolute_difference=delta,
                               tolerance=tolerance, match=delta <= tolerance))
            if delta > tolerance:
                raise RuntimeError(f'{file}: {name}: {actual} differs from PDF {pdf}')
    for origin, root, tolerance in [('published', BUNDLE / 'inputs/paper/figures', 1e-4),
                                    ('regenerated', output / 'figures', 2e-6)]:
        file = 'sec-3-4config-percase.pdf'
        bars, refs = geometry(root / file)
        if len(refs) != 2:
            raise RuntimeError(f'{file}: expected two 1x reference lines')
        for panel, arch in enumerate(['x86', 'arm']):
            for runtime, values in points[arch].items():
                rects = bars[runtime][panel*27:(panel+1)*27]
                check(file, [arch+' '+runtime+' '+n for n in values], list(values.values()), rects, refs[panel], tolerance)
        for file in ['sec-6-x86-kinsn-micro-best-raw-27-20260608.pdf',
                     'sec-6-arm64-kinsn-micro-rejit-27-20260608.pdf']:
            bars, refs = geometry(root / file)
            # The lower of the two lines is 1x; the other is the >1x geomean.
            values = points[file]
            check(file, list(values), list(values.values()),
                  bars['native_kernel'] + bars['native'] + bars['llvmbpf'], max(refs), tolerance)
        file = 'sec-6-rq3-cilium-katran.pdf'
        bars, refs = policy_geometry(root / file)
        if len(refs) != 1:
            raise RuntimeError(f'{file}: expected one 1x reference line, found {len(refs)}')
        for field in ['throughput', 'cost']:
            values = points[file][field]
            check(file, [field+' '+n for n in values], list(values.values()), bars[field], refs[0],
                  tolerance, base=POLICY_Y_MIN)
    count = len(checks)//2
    policy = sum(1 for c in checks if c['figure'] == 'sec-6-rq3-cilium-katran.pdf')//2
    (output / 'figure-checks.json').write_text(json.dumps(checks, indent=2)+'\n')
    (output / 'figure-checks.md').write_text(
        '# Published figure comparison\n\n'
        f'All {count} regenerated bars match computed values and the vector geometry of both\n'
        'the published camera-ready PDFs and the regenerated PDFs.\n\n'
        f'162 characterization bars, 54 kinsn micro bars, and {policy} bars in Figure 6\n'
        '(throughput and BPF cost for Cilium full, Cilium without bulk copy, Cilium\n'
        'whole-program native, Katran full and Katran conservative). Figure 6 values are\n'
        'median post/baseline ratios rounded to three decimals: throughput\n'
        + '/'.join(f'{v:.3f}' for v in points[file]['throughput'].values()) + ' and BPF cost '
        + '/'.join(f'{v:.3f}' for v in points[file]['cost'].values()) + '.\n\n'
        'Tolerances: 0.0001 for published PDFs (coordinate quantization), '
        '0.000002 for regenerated PDFs. `figure-checks.json` records each comparison.\n')
    return count
