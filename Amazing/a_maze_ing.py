import sys
from mazegen import parser_to_class, MazeGenerator


def main():
    if len(sys.argv) == 2:
        try:
            with open(sys.argv[1], "r") as file:

                config = parser_to_class(file)

                if config == "Error":
                    return

                mazegen = MazeGenerator(config)
                mazegen.run()
        except Exception as e:
            print(e)

    else:
        print("incorrect number of parameters")


if __name__ == "__main__":
    main()
