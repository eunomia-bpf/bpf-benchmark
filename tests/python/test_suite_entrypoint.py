from __future__ import annotations

from runner.libs import suite_entrypoint


def test_parse_shell_argv_handles_empty() -> None:
    assert suite_entrypoint._parse_shell_argv("") == []


def test_parse_shell_argv_round_trips_shell_escaped_tokens() -> None:
    serialized = "foo 'bar baz' --flag='quoted value'"
    assert suite_entrypoint._parse_shell_argv(serialized) == [
        "foo",
        "bar baz",
        "--flag=quoted value",
    ]


def test_env_csv_reads_comma_separated_contract_from_manifest(monkeypatch) -> None:
    monkeypatch.setenv("RUN_UPSTREAM_TEST_PROGS_FILTERS", "verifier,jit")
    monkeypatch.delenv("RUN_UPSTREAM_TEST_PROGS_DENY", raising=False)
    assert suite_entrypoint._env_csv("RUN_UPSTREAM_TEST_PROGS_FILTERS") == ["verifier", "jit"]
    assert suite_entrypoint._env_csv("RUN_UPSTREAM_TEST_PROGS_DENY") == []
