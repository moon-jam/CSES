import os
from problem_order import folder_file_order

def generate_markdown(folder, file_order):
    markdown_content = f"# {folder}\n\n"
    not_found_files = []
    topics = {}
    
    # Traverse the folder and add the contents of the files starting with '_' to the dictionary
    if os.path.exists(folder):
        for file_name in os.listdir(folder):
            if file_name.startswith('_') and file_name.endswith('.cpp'):
                title, subtitle = file_name[1:-4].split('_', 1)
                with open(os.path.join(folder, file_name), 'r') as file:
                    file_content = file.read()
                if title not in topics:
                    topics[title] = ""
                topics[title] += f"### {subtitle}\n\n```c++ {title} - {subtitle}\n{file_content}\n```\n\n"

    for file_name in file_order:
        cpp_file_path = os.path.join(folder, file_name + ".cpp")
        if os.path.exists(cpp_file_path):
            with open(cpp_file_path, 'r', encoding='utf-8') as file:
                file_content = file.read()
                markdown_content += f"## {file_name}\n\n```c++ {file_name}\n{file_content}\n```\n\n"
                # Check if there are any topics for this title
                if file_name in topics:
                    markdown_content += topics[file_name]
                    del topics[file_name]
        else:
            markdown_content += f"## {file_name}\n\nFile not found.\n\n"
            not_found_files.append(file_name)
    
    if not_found_files:
        markdown_content += "## Files not found\n\n" + "\n".join(not_found_files)
        markdown_content += "\n"
    else :
        markdown_content = markdown_content[:-1]
    # Create a new directory for the markdown files
    if not os.path.exists('Markdown_Solutions'):
        os.mkdir('Markdown_Solutions')
    
    with open(os.path.join('Markdown_Solutions', f"{folder}.md"), 'w', encoding='utf-8')  as md_file:
        md_file.write(markdown_content)
    
    # Print not found files to the terminal
    if not_found_files:
        print(f"\nFiles in {folder} not found:")
        print("\n".join(not_found_files))

if __name__ == "__main__":
    # User input for folder and files
    folder = input("Enter the folder name: ")

    file_order_input = folder_file_order.get(folder)

    # print("Enter file names, one per line. Enter an empty line to finish:")
    # file_order_input = []
    # while True:
    #     line = input()
    #     if line == "":
    #         break
    #     file_order_input.append(line)

    if file_order_input is None:
        print(f"No file order found for folder {folder}")
    else:
        generate_markdown(folder, file_order_input)