"""Plot Figure 6 (RQ3, RQ4): application throughput and BPF cost under Kinsn
policies, with the whole-program native upper bound for Cilium.

Values are the medians reported in Sections 6.3 and 6.4. The hatched native
bars trust the native code of whole programs, unlike the Kinsn bars. The style follows the original
figure, but the canvas is sized for one column of the ACM sigplan layout so
that its text is not scaled down in the paper.

Usage: python figures/scripts/plot_rq3_cilium_katran.py
Output: figures/sec-6-rq3-cilium-katran.pdf
"""

from pathlib import Path

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt

# (label, throughput ratio, BPF cost ratio, whole-program native)
CASES = [
    ("Cilium\nFull\n4086 sites", 1.074, 1.010, False),
    ("Cilium\nNo Bulk\n3512 sites", 1.119, 1.062, False),
    ("Cilium\nNative\nwhole program", 1.194, 0.704, True),
    ("Katran\nFull\n62 sites", 0.984, 1.006, False),
    ("Katran\nConservative\n21 sites", 1.065, 0.941, False),
]

COLUMN_WIDTH_IN = 241.14 / 72.27  # \columnwidth of acmart sigplan
HEIGHT_IN = 1.75
THROUGHPUT_COLOR = "#4C78A8"
COST_COLOR = "#D18F32"
EDGE_COLOR = "#3a3a3a"
Y_MIN, Y_MAX = 0.64, 1.34

plt.rcParams.update({
    "font.family": "DejaVu Sans",
    "font.size": 7.0,
    "axes.linewidth": 0.5,
    "xtick.major.width": 0.6,
    "ytick.major.width": 0.6,
    "xtick.major.size": 2.5,
    "ytick.major.size": 2.5,
    "hatch.linewidth": 0.5,
    "pdf.fonttype": 42,
    "ps.fonttype": 42,
})


def main() -> None:
    out = Path(__file__).resolve().parent.parent / "sec-6-rq3-cilium-katran.pdf"

    # Two bars per case, side by side, with a wider gap between Cilium and Katran.
    centers = [0.0, 1.07, 2.42, 3.92, 4.99]
    width = 0.44

    fig, ax = plt.subplots(figsize=(COLUMN_WIDTH_IN, HEIGHT_IN))
    ax.grid(axis="y", color="#e6e6e6", linewidth=0.5, zorder=0)
    for x, (_, thr, cost, native) in zip(centers, CASES):
        for dx, value, color in ((-width / 2, thr, THROUGHPUT_COLOR), (width / 2, cost, COST_COLOR)):
            ax.bar(x + dx, value - Y_MIN, width, bottom=Y_MIN, color=color,
                   edgecolor=EDGE_COLOR, linewidth=0.35, zorder=2,
                   hatch="////" if native else None)
            # Nudge each label outward so neighboring labels do not touch.
            ax.text(x + dx * 1.2, value + 0.003, f"{value:.3f}x", ha="center", va="bottom",
                    fontsize=5.6, zorder=4,
                    bbox=dict(boxstyle="square,pad=0.05", facecolor="white", edgecolor="none"))

    ax.axhline(1.0, color="#555555", linestyle="--", linewidth=0.6, zorder=3)
    ax.set_ylim(Y_MIN, Y_MAX)
    ax.set_yticks([0.7, 0.8, 0.9, 1.0, 1.1, 1.2])
    ax.set_ylabel("Ratio to original eBPF")
    ax.set_xticks(centers)
    ax.set_xticklabels([c[0] for c in CASES], linespacing=1.1, fontsize=6.6)
    ax.set_xlim(-0.55, 5.56)

    handles = [
        plt.Rectangle((0, 0), 1, 1, facecolor=THROUGHPUT_COLOR, edgecolor=EDGE_COLOR, linewidth=0.35),
        plt.Rectangle((0, 0), 1, 1, facecolor=COST_COLOR, edgecolor=EDGE_COLOR, linewidth=0.35),
    ]
    ax.legend(handles, ["Workload throughput ↑", "BPF cost ↓"], loc="upper center",
              ncol=2, frameon=False, fontsize=6.8, handlelength=1.8, handleheight=0.7,
              columnspacing=2.0, borderaxespad=0.3)

    fig.tight_layout(pad=0.2)
    fig.savefig(out, bbox_inches="tight", pad_inches=0.01)
    print(f"wrote {out}")


if __name__ == "__main__":
    main()
