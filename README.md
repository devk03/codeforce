# Competitive Programming Setup for C++

This directory contains a streamlined setup for competitive programming in C++, optimized for platforms like Codeforces, AtCoder, and other online judges.

## Files Overview

- `main.cpp` - Main template file with common includes and macros
- `compile.sh` - Script to compile your C++ code with optimizations
- `run.sh` - Script to compile and run your program
- `input.txt` - Sample input file for testing
- `output.txt` - Expected output file for verification

## Quick Start

1. **Write your solution** in `main.cpp` inside the `solve()` function
2. **Add test input** to `input.txt`
3. **Compile and run** using `./run.sh`
4. **Archive a solution** using `./run.sh -n`

## Usage

### Basic Workflow

```bash
# Edit your solution
code main.cpp

# Test with sample input
./run.sh

# Just compile (without running)
./compile.sh

# Archive a soluton
./run.sh -n
```

### Template Features

The `main.cpp` template includes:

- Fast I/O setup (`ios_base::sync_with_stdio(false)`)
- Common competitive programming headers (`#include <bits/stdc++.h>`)
- Useful macros and typedefs:
  - `ll` for `long long`
  - `vi`, `vll` for vectors
  - `pii`, `pll` for pairs
  - `pb`, `mp` for push_back and make_pair
  - `all(v)` for `v.begin(), v.end()`
  - `FOR` and `RFOR` loop macros
- Common constants (MOD, INF, LINF)

### Multiple Test Cases

For problems with multiple test cases, uncomment this line in `main.cpp`:

```cpp
cin >> t;  // Uncomment for multiple test cases
```

### Compilation Options

The compile script uses these flags:

- `-std=c++17` - C++17 standard
- `-O2` - Optimization level 2
- `-Wall -Wextra -pedantic` - Enable warnings

## Tips

1. **Fast Development**: Keep `input.txt` with sample test cases
2. **Debugging**: Add debug prints that you can easily remove
3. **Time Limits**: The template includes fast I/O for time-critical problems
4. **Memory**: Use appropriate data types (`int` vs `long long`)

## Example Problem

The sample `input.txt` contains:

```
5
1 2 3 4 5
```

You could solve this by finding the sum:

```cpp
void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum << endl;
}
```

Run `./run.sh` to test this solution.
