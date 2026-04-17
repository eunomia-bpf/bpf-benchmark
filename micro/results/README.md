# Micro Results

Top-level `micro/results/` stores retained authoritative JSON files.
Timestamped run directories are transient session artifacts and should stay out of git.

- Keep flat `*_authoritative_*.json` files when they back documented numbers.
- Do not commit `micro/results/<run_type>_<timestamp>/` session directories.
- If a future run becomes authoritative, promote a concise top-level JSON artifact instead of committing the whole session directory.
