#!/usr/bin/python

import sys
import math

class FormatError(Exception):
    pass
def raise_format_error(item):
    int_item = []
    if not len(item) == 3:
        raise FormatError()
    try:
        for c in item:
            nb = float(c)
            int_item.append(nb)
    except ValueError:
        raise FormatError()
    return (int_item)
    
def get_player_pos():
    while True:
        coordinates = input("Enter new coordinates as floats in format 'x,y,z': ")
        item = coordinates.split(",")
        try:
            item = raise_format_error(item)
            return (item[0], item[1], item[2])
        except FormatError:
            print("Invalid Sintax")
def calculate_distance(tup1, tup2):
    distance = math.sqrt((tup2[0]-tup1[0])**2 + (tup2[1]-tup1[1])**2 + (tup2[2]-tup1[2])**2)
    return round(distance,4)        

def main():
    print("=== Game Coordinate System ===")
    
    print("Get a first set of coordinates")
    tupple1 = get_player_pos()
    print(f"Got a first tupple: {tupple1}")
    print(f"It includes: X={tupple1[0]}, Y={tupple1[1]}, Z={tupple1[2]}")
    print(f"Distance to center: {calculate_distance(tupple1, (0,0,0))}")
    
    print()
    print("Get a second set of coordinates")
    tupple2 = get_player_pos()
    print(f"Distance between the 2 sets of coordinates: {calculate_distance(tupple1, tupple2)}")
    
if __name__ == "__main__":
    main()