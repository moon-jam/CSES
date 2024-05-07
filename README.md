# CSES code

> Write CSES problems every day to keep myself familiar with algorithms.

## [CSES Problem Set](https://cses.fi/problemset/list/)

## [My CSES Profile](https://cses.fi/user/203349)

## [Generated Markdown Solutions](./Markdown_Solutions)

Solved Tasks: 133/300

| Problem Set | Solved | Total |
| ------- | ------ | ----- |
|Introductory Problems| 19 | 19 |
|Sorting and Searching| 35 | 35 |
|Dynamic Programming| 19 | 19 |
|Graph Algorithms| 36 | 36 |
|Range Queries| 19 | 19 |
|Tree Algorithms| 5 | 16 |
|Mathematics| 0 | 31 |
|String Algorithms| 0 | 17 |
|Geometry| 0 | 7 |
|Advanced Techniques| 0 | 24 |
|Additional Problems| 0 | 77 |

## CSES Problem Set Progress Tracker

This Python script, `progress-tracker.py`, is used to track the progress of solved problems in the [CSES Problem Set](https://cses.fi/problemset/). It also generates a markdown file for each problem set using the `generate_md.py` script.

### How it works

The script works by counting the number of files in each problem set directory. Each file represents a solved problem. The script assumes that any file that does not start with an underscore (`_`) is a solved problem.

The problem sets and their corresponding directories are defined in the `problem_sets` dictionary. If a directory does not exist, it is assumed that no problems have been solved in that set.

``` python
problem_sets = {
    "Introductory Problems": "./Introductory Problems",
    "Sorting and Searching": "./Sorting and Searching",
    "Dynamic Programming": "./Dynamic Programming",
    "Graph Algorithms": "./Graph Algorithms",
    "Range Queries": "./Range Queries",
    "Tree Algorithms": "./Tree Algorithms",
    "Mathematics": "./Mathematics",
    "String Algorithms": "./String Algorithms",
    "Geometry": "./Geometry",
    "Advanced Techniques": "./Advanced Techniques",
    "Additional Problems": "./Additional Problems",
}
```

The total number of solved problems is calculated and the information is written back to the `README.md` file. The script updates the "Solved Tasks" count and the count of solved problems for each problem set.

The script also generates a markdown file for each problem set using the [`generate_md.py`](./generate_md.py) script. The order of problems in each problem set is defined in the [`problem_order.py`](./problem_order.py) script. The generated markdown files are saved in the [Generated Markdown Solutions](./Markdown_Solutions/) directory.
