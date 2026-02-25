import sys
import math


class coord_error(Exception):
    pass

def raise_coord_error(string:str):
    splited = str.split(',')
    list = []
    for x in splited:
        try:
            nb = int(x)
            list.append(int(x))
        except ValueError:
            raise coord_error (f'\nParsing invalid coordinates: "{str}"')
    final = tuple(list)
    return final
    
if __name__ == "__main__":
    print("=== Game coordinate System ===")
    pos = (10, 20, 5)
    distance = math.sqrt((pos[0]-0)**2 + (pos[1]-0)**2 + (pos[2]-0)**2)
    print(f"Position created: {pos}")
    print(f"Distance between (0, 0, 0) and {pos}: {distance:.2f}")

    str = "3,4,0"

    try:
        final = raise_coord_error(str)
        print(f'\nParsing coordinates: "{str}"')
        print(f"Parsed position: {final}")
        distance = math.sqrt((final[0]-0)**2 + (final[1]-0)**2 + (final[2]-0)**2)
        print(f"Distance between (0, 0, 0) and {final}: {distance}")
        print("\nUnpacking demonstration:")
        print(f"Player at x={final[0]}, y={final[1]}, z={final[2]}")
        (x, y, z) = final
        print(f"Coordinates: X={x}, Y={y}, Z={z}")

    except coord_error as e:
        print(e)
        print(f"Error parsing coordinates: ", end="")
        print(f"invalid literal for int() with base 10: '{str.split(',')[0]}'")
        print(f"Error details -Type: ValueError", end="")
        print(f', Args: ("invalid literal for int() with base 10: ', end="")
        print(f"'{str.split(',')[0]}')")
