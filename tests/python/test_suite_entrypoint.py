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
