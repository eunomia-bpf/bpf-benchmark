"""Compare every data bar with the published PDF's vector geometry.

The PDFs outline some text, so extraction of printed text alone cannot verify
these plots. Rectangle heights and the 1x reference line recover the data.
"""
import json

import fitz
from metrics import BUNDLE

COLORS = {'native_kernel': (0.298, .471, .658), 'native': (.329, .635, .294),
          'llvmbpf': (.697, .475, .635), 'cost': (.820, .561, .184)}


def geometry(path):
    with fitz.open(path) as doc:
        drawings = doc[0].get_drawings()
    bars = {}
    for key, color in COLORS.items():
        bars[key] = sorted([d['rect'] for d in drawings if d['fill'] is not None
                            and max(abs(a-b) for a, b in zip(d['fill'], color)) < .003
                            and len(d['items']) == 1 and d['items'][0][0] == 're'
                            and d['rect'].height > 20], key=lambda r: (r.y1, r.x0))
    refs = sorted(set(d['rect'].y0 for d in drawings if d['fill'] is None
                      and d['rect'].width > 250 and d['rect'].height < .01
                      and d['dashes'] != '[] 0'))
    return bars, refs


def compare(points, output):
    checks = []
    def check(file, names, expected, rects, one, tolerance):
        if len(rects) != len(expected):
            raise RuntimeError(f'{file}: expected {len(expected)} PDF bars, found {len(rects)}')
        rects = sorted(rects, key=lambda r: r.x0)
        recovered = [(r.y1-r.y0)/(r.y1-one) for r in rects]
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
        bars, refs = geometry(root / file)
        for field, key in [('throughput', 'native_kernel'), ('cost', 'cost')]:
            values = points[file][field]
            check(file, [field+' '+n for n in values], list(values.values()), bars[key], refs[0], tolerance)
    (output / 'figure-checks.json').write_text(json.dumps(checks, indent=2)+'\n')
    (output / 'figure-checks.md').write_text(
        '# Published figure comparison\n\n'
        f'All {len(checks)//2} bars match both published and regenerated PDF vector geometry.\n\n'
        '162 characterization bars, 54 kinsn micro bars, and 8 policy bars.\n'
        'Tolerances: 0.0001 for published PDFs (coordinate quantization), '
        '0.000002 for regenerated PDFs. Policy heights use the published three-decimal '
        'rounding. `figure-checks.json` records each comparison.\n')
    return len(checks)//2
