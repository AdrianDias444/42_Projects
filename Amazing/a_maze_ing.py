import sys
from mazegen import parser_to_class, MazeGenerator


def main() -> None:
    if len(sys.argv) == 2:
        try:
            config = parser_to_class(sys.argv[1])

            mazegen = MazeGenerator(config)
            if mazegen.config_class_checker(config) == -1:
                sys.exit()
            mazegen.menu()
        except Exception as e:
            print(e)

    else:
        print("incorrect number of parameters")


if __name__ == "__main__":
    main()
