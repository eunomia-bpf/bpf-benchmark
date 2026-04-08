from __future__ import annotations

from runner.libs.workload import parse_stress_ng_bogo_ops


def test_parse_stress_ng_bogo_ops_returns_first_metric() -> None:
    text = (
        "stress-ng: info:  [123] dispatching hogs: 2 exec\n"
        "stress-ng: metrc: [123] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\n"
        "stress-ng: metrc: [123] exec               456.78      5.01      4.89      1.23      91.17         74.71\n"
    )

    assert parse_stress_ng_bogo_ops(text, stressor="exec") == 456.78
