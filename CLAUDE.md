# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a competitive programming setup for C++ optimized for online judges like Codeforces and AtCoder. The repository uses a simple workflow where solutions are written in `main.cpp` and tested against `input.txt`.

## Development Workflow

### Compile and Run
```bash
./run.sh          # Compile, run with input.txt, then clean up executable
./compile.sh      # Compile only (creates 'main' executable)
./main < input.txt  # Run compiled executable with input
```

### Testing
- Add test cases to `input.txt`
- `run.sh` automatically uses `input.txt` as stdin and cleans up the executable after running
- Expected output can be stored in `output.txt` for verification

## Code Structure

### main.cpp
The primary solution file. Structure:
- `solve()` function: Contains the solution logic for a single test case
- `main()` function: Handles fast I/O setup and multiple test case loops

### template.cpp
Clean template for starting new problems. Copy to `main.cpp` when needed.

### Compilation Settings
- Standard: C++17 (`-std=c++17`)
- Optimization: O2 (`-O2`)
- Warnings: `-Wall -Wextra -pedantic`

## Important Notes

### File I/O vs Standard I/O
- The run.sh script redirects `input.txt` to stdin using `< input.txt`
- **Do NOT use `freopen()` for stdin** - it's unnecessary and causes conflicts
- Only use `freopen("output.txt", "w", stdout)` if you specifically want to redirect output to a file (and place it AFTER all input reading)
- For competitive programming submissions, remove all `freopen()` calls

### Template Macros & Typedefs
Available shortcuts:
- Types: `ll` (long long), `vi` (vector<int>), `vll` (vector<long long>), `pii`, `pll`
- Functions: `pb` (push_back), `mp` (make_pair), `fi`/`se` (first/second), `all(v)` (v.begin(), v.end()), `sz(v)` (size)
- Loops: `FOR(i, a, b)`, `RFOR(i, a, b)`
- Constants: `MOD` (1e9+7), `INF` (1e9), `LINF` (1e18)

### Multiple Test Cases
For problems with multiple test cases:
- Uncomment `cin >> t;` in main.cpp (currently on line 55)
- Default template has `t = 1` for single test case problems
