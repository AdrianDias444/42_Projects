def ft_harvest_total() -> None:
    lst = [1, 2, 3]
    total_harvest = 0
    for i in lst:
        day = int(input(f"Day {i} harvest:"))
        total_harvest += day
    print(f"Total harvest: {total_harvest}")
