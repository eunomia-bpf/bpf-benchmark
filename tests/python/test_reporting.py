from __future__ import annotations

from runner.libs.reporting import _perf_runtime_statistics


def test_perf_runtime_statistics_collects_medians() -> None:
    results = {
        "suite": "micro",
        "benchmarks": [
            {
                "name": "demo",
                "runs": [
                    {
                        "runtime": "llvmbpf",
                        "exec_ns": {"median": 10},
                        "samples": [{"exec_ns": 9}, {"exec_ns": 11}],
                        "baseline_adjustment": {"median_minus_baseline_ns": 5},
                        "derived_metrics": {
                            "ipc_median": 1.2,
                            "branch_miss_rate_median": 0.08,
                            "cache_miss_rate_median": 0.02,
                        },
                        "perf_counters_meta": {"hardware_counters_observed": True},
                    },
                    {
                        "runtime": "kernel",
                        "exec_ns": {"median": 20},
                        "samples": [{"exec_ns": 19}, {"exec_ns": 21}],
                        "baseline_adjustment": {"median_minus_baseline_ns": 10},
                        "derived_metrics": {
                            "ipc_median": 1.0,
                            "branch_miss_rate_median": 0.1,
                            "cache_miss_rate_median": 0.03,
                        },
                        "perf_counters_meta": {"hardware_counters_observed": True},
                    },
                ],
                "runtime_comparison": {
                    "llvmbpf_over_kernel_exec_ratio": 0.5,
                    "llvmbpf_over_kernel_adjusted_exec_ratio": 0.5,
                },
            }
        ],
    }

    perf_runtimes = _perf_runtime_statistics(results)

    assert len(perf_runtimes) == 2
    llvmbpf_runtime = next(runtime for runtime in perf_runtimes if runtime.runtime == "llvmbpf")
    assert llvmbpf_runtime.ipc_median == 1.2
    assert llvmbpf_runtime.branch_miss_rate_median == 0.08
    assert llvmbpf_runtime.cache_miss_rate_median == 0.02
