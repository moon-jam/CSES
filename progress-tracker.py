import os
from generate_md import generate_markdown
from problem_order import folder_file_order

# Define your problem sets and their directories
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

# Count solved problems
solved_problems = {name: len([f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f)) and not f.startswith("_") and f.endswith(".cpp")]) if os.path.exists(path) else 0 for name, path in problem_sets.items()}

# Calculate total solved problems
total_solved = sum(solved_problems.values())

# Read the README.md file
with open("README.md", "r") as file:
    lines = file.readlines()

# Update the solved problems count
in_code_block = False
for i, line in enumerate(lines):
    if "```" in line:
        in_code_block = not in_code_block
    if not in_code_block:
        if "Solved Tasks:" in line:
            lines[i] = f"Solved Tasks: {total_solved}/300\n"
        for name, count in solved_problems.items():
            generate_markdown(name, folder_file_order[name])
            if name in line:
                lines[i] = f"|{name}| {count} |" + "|".join(line.split("|")[3:])

# Write the updated content back to README.md
with open("README.md", "w") as file:
    file.writelines(lines)