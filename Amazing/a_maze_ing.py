import sys

import dfs
import parser
from algorithm import algorithm
from config import Config, Grid



def config_class_checker(config_class: Config) -> int:
    if config_class.width == "Error":
        return -1
    if config_class.height == "Error":
        return -1
    if config_class.entry == "Error":
        return -1
    if config_class.exit == "Error":
        return -1
    if config_class.output_file == "Error":
        return -1
    if config_class.perfect == "Error":
        return -1
    return 0


def main():
    if len(sys.argv) == 2:
        try:
            file = open(sys.argv[1], "r")
        except Exception as e:
            print (e)
            return 
        config_class = parser.parser_to_class(file)
        if config_class == "Error":
            return
        if config_class_checker(config_class) == -1:
            return
        algorithm(config_class)

    else:
        print("incorrect number of parameters")


if __name__ == "__main__":
    main()
