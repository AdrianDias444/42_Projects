#!/usr/bin/python3

def secure_archive(f: str, act: str = "r", cont: str = "") -> tuple[bool, str]:
    if act == "r":
        try:
            with open(f, 'r') as file_obj:
                data = file_obj.read()
            return (True, data)
        except (FileNotFoundError, PermissionError, IOError) as e:
            return (False, str(e))

    elif act == "w":
        try:
            with open(f, 'w') as file_obj:
                file_obj.write(cont)
            return (True, "Content successfully written to file")
        except (FileNotFoundError, PermissionError, IOError) as e:
            return (False, str(e))

    else:
        return (False, f"Unknown action: {act}")


def main() -> None:
    print("=== Cyber Archives Security ===")

    print("Using 'secure_archive' to read from a nonexistent file:")
    result = secure_archive("/not/existing/file", "r")
    print(result)

    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    result = secure_archive("/etc/master.passwd", "r")
    print(result)

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
