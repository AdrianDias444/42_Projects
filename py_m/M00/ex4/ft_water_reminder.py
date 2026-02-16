def ft_water_reminder():
    last = int(input("Days since last watering: "))
    if(last > 2):
        print("Water the plants!")
    else:
        print("Plans are fine")