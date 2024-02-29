# CSES code

## [CSES Problem Set](https://cses.fi/problemset/list/)

## [My CSES Profile](https://cses.fi/user/203349)

Solved Tasks: 68/300

| Problem Set | Solved | Total |
| ------- | ------ | ----- |
|Introductory Problems| 19 | 19 |
|Sorting and Searching| 35 | 35 |
|Dynamic Programming| 7 | 19 |
|Graph Algorithms| 7 | 45 |
|Range Queries| 0 | 22 |
|Tree Algorithms| 0 | 15 |
|Mathematics| 0 | 33 |
|String Algorithms| 0 | 18 |
|Geometry| 0 | 15 |
|Advanced Techniques| 0 | 59 |
|Additional Problems| 0 | 20 |

## CSES Problem Set Progress Tracker

This Python script, `progress-tracker.py`, is used to track the progress of solved problems in the [CSES Problem Set](https://cses.fi/problemset/).

### How it works

The script works by counting the number of files in each problem set directory. Each file represents a solved problem. The script assumes that any file that does not start with an underscore (`_`) is a solved problem.

The problem sets and their corresponding directories are defined in the `problem_sets` dictionary. If a directory does not exist, it is assumed that no problems have been solved in that set.

```python
problem_sets = {
|Additional Problems| 0 ||Sorting and Searching| 17 ||Dynamic Programming| 6 ||Graph Algorithms| 6 ||Range Queries| 0 ||Tree Algorithms| 0 ||Mathematics| 0 ||String Algorithms| 0 ||Geometry| 0 ||Advanced Techniques| 0 ||Additional Problems| 0 |}
```

The total number of solved problems is calculated and the information is written back to the `README.md` file. The script updates the "Solved Tasks" count and the count of solved problems for each problem set.
