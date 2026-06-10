#!/usr/bin/python3

def secure_archive(file: str, action: str = "r", content: str = "") -> tuple:
    if action == "r":
        try:
            with open(file, 'r') as file_obj:
                data = file_obj.read()
            return (True, data)
        except (FileNotFoundError, PermissionError, IOError) as e:
            return (False, str(e))

    elif action == "w":
        try:
            with open(file, 'w') as file_obj:
                file_obj.write(content)
            return (True, "Content successfully written to file")
        except (FileNotFoundError, PermissionError, IOError) as e:
            return (False, str(e))

    else:
        return (False, f"Unknown action: {action}")


def main() -> None:
    print("=== Cyber Archives Security ===")

    # Test 1: Read from non existent file
    print("Using 'secure_archive' to read from a nonexistent file:")
    result = secure_archive("/not/existing/file", "r")
    print(result)

    # Test 2: Read from inaccessible file
    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    result = secure_archive("/etc/master.passwd", "r")
    print(result)

    # Test 3: Read from regular file
    print("\nUsing 'secure_archive' to read from a regular file:")
    with open("ancient_fragment.txt", "w") as f:
        f.write("[FRAGMENT 001]")
        f.write("Digital preservation protocols established 2087\n")
        f.write("[FRAGMENT 002]")
        f.write("Knowledge must survive the entropy wars\n")
        f.write("[FRAGMENT 003]")
        f.write("Every byte saved is a victory against oblivion\n")

    result = secure_archive("ancient_fragment.txt", "r")
    print(result)

    # Test 4: Write content to a new file
    print("\nUsing 'secure_archive' to write previous content to a new file:")
    result = secure_archive(
        "new_fragment.txt",
        "w",
        "[FRAGMENT 001] Digital preservation protocols established 2087#\n"
        "[FRAGMENT 002] Knowledge must survive the entropy wars#\n"
        "[FRAGMENT 003] Every byte saved is a victory against oblivion#\n"
     )
    print(result)


if __name__ == "__main__":
    main()
