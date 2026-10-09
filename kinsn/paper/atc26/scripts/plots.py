"""Final 27-case plots reconstructed from the archived generators and audit.

Only data/ supplies measurements. The archived sources retain the naming and
plot conventions; final figure generators were not retained upstream.
"""
import ast

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import FuncFormatter

from metrics import BUNDLE, gm

source = ast.parse((BUNDLE / 'scripts/upstream/plot_evaluation_kinsn.py.txt').read_text())
SHORT_NAMES = ast.literal_eval(next(n.value for n in source.body
                                   if isinstance(n, ast.Assign)
                                   and any(isinstance(t, ast.Name) and t.id == 'SHORT_NAMES' for t in n.targets)))
plt.rcParams.update({'font.size': 9, 'pdf.fonttype': 42, 'axes.linewidth': .6,
                     'grid.alpha': .25, 'grid.linewidth': .5})
COLORS = ['#4C78A8', '#54A24B', '#B279A2']


def draw(chars, x86, arm64, policy, figures):
    points = {}
    fig, axes = plt.subplots(2, 1, figsize=(17, 9.4))
    for ax, arch, label in zip(axes, ['x86', 'arm'], ['x86-64', 'ARM64']):
        names = list(chars[arch, 'native_kernel'])
        # Use the original workload order, shared by both published panels.
        names = sorted(names, key=lambda n: list(SHORT_NAMES).index(n))
        x = np.arange(len(names))
        series = {}
        for i, (runtime, legend) in enumerate([('native_kernel', 'In-kernel native'),
                                              ('native', 'Userspace native'),
                                              ('llvmbpf', 'Userspace LLVM-BPF')]):
            values = [chars[arch, runtime][n] for n in names]
            series[runtime] = dict(zip(names, values))
            ax.bar(x + (i - 1) * .25, values, width=.25, color=COLORS[i],
                   edgecolor='#333333', linewidth=.3,
                   label=f'{legend} ({gm(values):.2f}x)')
        ax.axhline(1, color='#333333', linestyle='--', linewidth=.8)
        ax.set_xticks(x, [SHORT_NAMES[n] for n in names], rotation=50, ha='right')
        ax.set_ylim(0, 4.25)
        ax.set_yticks(np.arange(0, 4.5, .5))
        ax.yaxis.set_major_formatter(FuncFormatter(lambda v, _: f'{v:g}x'))
        ax.set_ylabel('Speedup over\nkernel eBPF JIT')
        ax.text(.005, .96, label, transform=ax.transAxes, va='top', weight='bold')
        ax.grid(axis='y')
        ax.legend(loc='lower center', bbox_to_anchor=(.5, 1.02), ncol=3, frameon=False)
        points[arch] = series
    fig.tight_layout(h_pad=2)
    fig.savefig(figures / 'sec-3-4config-percase.pdf')
    plt.close(fig)
    for arch, values, filename in [
        ('x86', x86, 'sec-6-x86-kinsn-micro-best-raw-27-20260608.pdf'),
        ('arm64', arm64, 'sec-6-arm64-kinsn-micro-rejit-27-20260608.pdf')]:
        names = sorted(x86, key=x86.__getitem__, reverse=True)
        ys = [values[n] for n in names]
        fig, ax = plt.subplots(figsize=(24, 4.8))
        bars = ax.bar(range(len(names)), ys, width=.82,
                      color=[(COLORS[0] if arch == 'x86' else COLORS[1]) if v >= 1 else COLORS[2] for v in ys],
                      edgecolor='#333333', linewidth=.3)
        ax.axhline(1, color='#333333', linestyle='--', linewidth=.8)
        ax.axhline(gm(ys), color='#777777', linestyle='-.', linewidth=.8)
        ax.text(.995, gm(ys), f'geomean {gm(ys):.2f}x', transform=ax.get_yaxis_transform(),
                ha='right', va='bottom', color='#555555')
        for bar, v in zip(bars, ys):
            if v >= 1.35 or v < .9:
                ax.text(bar.get_x() + bar.get_width()/2, v + .04, f'{v:.2f}x', ha='center')
        ax.set_ylabel('Speedup over stock')
        ax.set_xticks(range(len(names)), [SHORT_NAMES[n] for n in names], rotation=50, ha='right')
        ax.set_ylim(0, max(x86.values())*1.18)
        ax.yaxis.set_major_formatter(FuncFormatter(lambda v, _: f'{v:g}x'))
        ax.grid(axis='y')
        fig.tight_layout()
        fig.savefig(figures / filename)
        plt.close(fig)
        points[filename] = dict(zip(names, ys))
    # Policy inputs use median post/baseline, rounded to three decimals for plotting.
    # Declared site labels remain annotations, never treated as measured counts.
    names = ['Cilium Full', 'Cilium No Bulk', 'Katran Full', 'Katran Conservative']
    labels = ['Cilium\nFull\n4086 sites', 'Cilium\nNo Bulk\n3512 sites',
              'Katran\nFull\n62 sites', 'Katran\nConservative\n21 sites']
    fig, ax = plt.subplots(figsize=(8.15, 3.2))
    x = np.array([0, 1, 2.65, 3.65])
    pp = {}
    for offset, field, color, legend in [(-.195, 'throughput', COLORS[0], 'Workload throughput ↑'),
                                        (.195, 'cost', '#D18F2F', 'BPF cost ↓')]:
        ys = [round(policy[n][field], 3) for n in names]
        pp[field] = dict(zip(names, ys))
        bars = ax.bar(x+offset, ys, width=.39, color=color, edgecolor='#333333', linewidth=.3, label=legend)
        for bar, v in zip(bars, ys):
            ax.text(bar.get_x()+bar.get_width()/2, v+.004, f'{v:.3f}x', ha='center', fontsize=8)
    ax.axhline(1, color='#555555', linestyle='--', linewidth=.7)
    ax.set_ylim(.91, 1.195)
    ax.set_yticks([1, 1.1])
    ax.set_ylabel('Ratio to stock eBPF')
    ax.set_xticks(x, labels)
    ax.grid(axis='y')
    ax.legend(loc='upper center', ncol=2, frameon=False, fontsize=8)
    fig.tight_layout()
    fig.savefig(figures / 'sec-6-rq3-cilium-katran.pdf')
    plt.close(fig)
    points['sec-6-rq3-cilium-katran.pdf'] = pp
    return points
