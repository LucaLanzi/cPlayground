# C++ Learning Progress — Luca

> **For the next Claude session:** Luca is a C++ novice learning through small guided
> exercises. Read this file to pick up where we left off. Key teaching preference:
> **when Luca is fixing their own code, give hints and guiding questions, not the
> corrected code.** Full examples are fine when introducing a *new* concept.
> Luca pastes terminal output + `cat` of the file for review.

- **Started:** 2026-10-17
- **Compiler:** g++ 15.2 on Ubuntu
- **Practice folder:** `~/Desktop/cPlayground/programs/`
  - `helloWorld/practice.cpp` — lesson 1
  - `tipCalculator/tipCalculator.cpp` — lessons 2–4 (current project)

---

## What we've covered

### Lesson 1 — First program
- `#include <iostream>`, `int main()`, `return 0;`
- Printing with `cout << ... << endl;`, chaining `<<` with text and math
- Semicolons end statements
- Compiling and running: `g++ file.cpp -o name` then `./name`
- `using namespace std;`: fine for practice, avoided in larger projects (name collisions)

### Lesson 2 — Variables, input, functions
- Types: `int`, `double`, `string` (`#include <string>`)
- Reading input with `cin >> variable`
- **Prefer `double` over `float`** (~15 vs ~7 significant digits)
- **Integer division gotcha:** `20 / 100` is `0` when both are ints
- Functions: writing one, **forward declarations/prototypes** above `main`
- **Avoid globals.** Keep variables local and pass parameters in / `return` results out
- **Calling vs naming a function:** `tipCalc(a, b)` runs it; bare `tipCalc` is the
  function itself (type `double (*)(double, double)`), not a number. Luca debugged this
  themselves from a hint.
- Formatting with `#include <iomanip>`: `cout << fixed << setprecision(2);`
  - `fixed`, `setprecision`, and `endl` are **manipulators**, separate items sent to `cout`
  - Without `fixed`, precision = significant digits; with `fixed`, it's digits after the decimal point
  - These settings are **sticky** (they apply to all later output)

### Lesson 3 — if statements
- `if` / `else if` / `else`: only the first true branch runs
- Comparison operators: `== != < > <= >=`
- Logical operators: `&&` (and), `||` (or)
- `=` vs `==` trap; `g++ -Wall` warns about it
- `return 1;` in `main` exits early and signals an error
- **Testing edge cases** (negative values, exact boundaries like 50 vs 50.01)

### Lesson 4 — Input validation (in progress)
- The **input buffer**: `cin >>` reads from it, and leftover characters stay there
- With `25abc`: the bill reads `25`, `abc` stays in the buffer, the tip read fails,
  the tip is set to `0`, and `cin` enters a **fail state** (later reads are ignored)
- Introduced `cin.fail()` and `if (!(cin >> x))` to detect failed reads

---

## Where we left off

The tip calculator currently:
- ✅ Rejects a bill `<= 0` with a specific error message and `return 1`
- ✅ Rejects a negative tip
- ✅ Prints a "generous" message for big tips (uses `>= 50`; the exercise said "over 50",
  which was pointed out, so it's Luca's call)
- ✅ Prints the tip and total to 2 decimal places
- ✅ `tipCalc` is self-contained (no globals touched)
- ❌ Doesn't detect non-numeric input yet

### Open exercise (pick up here)
1. **Predict, then run:** what happens if the bill is just `abc`? (Answer for the tutor:
   `dinnerCost` becomes 0, so the `<= 0` check catches it, but the message
   "negative or zero bill" is misleading. Let Luca discover this.)
2. Use `cin.fail()` (or `!(cin >> x)`) to print a proper "not a number" error for both inputs.
3. Note: `25abc` will still slip through, since the first read succeeds. Save that for later.

### Luca's longer-term goal
Get good at **pointers, memory, and data types** (understanding what's happening
under the hood). Rough path agreed on: loops → arrays → pass-by-value vs.
references → `sizeof` / how types are stored → pointers → stack vs. heap.
Look for chances to connect each lesson back to memory.

### Ideas for upcoming lessons
- Loops (`while`, `for`): re-prompt on bad input instead of exiting
  (needs `cin.clear()` + `cin.ignore(...)` to recover from the fail state)
- Bill-splitting bonus (ask how many people, print per-person amount;
  watch out for dividing by zero)
- `getline` for reading text with spaces (`cin >>` stops at whitespace)
- Catching `25abc`: read the whole line as a string, then convert it and validate
