# GPA Calculator
>A simple command line GPA calculator written in C++ for students to track their academic performance and plan for future GPA goals.

[![License: MIT](https://img.shields.io/badge/License-MIT-inactive.svg)](LICENSE)

## Features

* Calculates the required semester GPA to reach a desired cumulative GPA.
* Calculates semester GPA from letter grades.
* Updates and displays the new cumulative GPA after adding a semester’s results.

## Option 1

* Inputs completed credits, current GPA, upcoming credits, and desired final GPA.
* Outputs the semester GPA required to achieve the desired final GPA.

## Option 2

* Inputs completed credits, current GPA, number of courses, course credits, and projected letter grades.
* Outputs the projected semester GPA and new cumulative GPA.

## How to Compile and Run
Clone this repository
```bash
git clone https://github.com/DavidSchineis/GPA-Calculator.git
```

Compile the program
```bash
clang++ -std=c++17 gpa_calculator.cpp -o gpa_calculator
```

Run the program
```bash
./gpa_calculator
```

## License

MIT — see [LICENSE](LICENSE).
