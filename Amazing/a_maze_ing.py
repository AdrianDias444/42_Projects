import sys
from mazegen import parser_to_class, algorithm, MazeGenerator


def main():
    if len(sys.argv) == 2:
        try:
            file = open(sys.argv[1], "r")
        except Exception as e:
            print (e)
            return 

        config = parser_to_class(file)

        if config == "Error":
            return

        mazegen = MazeGenerator(config)
        mazegen.run()

    else:
        print("incorrect number of parameters")


if __name__ == "__main__":
    main()
