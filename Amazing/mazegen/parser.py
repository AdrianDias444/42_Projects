from .config import Config


class Equal_Not_Defined_Error(Exception):
    pass


class Key_Not_Exist_Error(Exception):
    pass


class Keys_Configs_Error(Exception):
    pass


class Value_Configs_Error(Exception):
    pass


def checker_configs_keys(lst_keys):
    lista = []
    for c in lst_keys:
        c = c.upper()
        if c == "WIDTH":
            lista.append(c)
        elif c == "HEIGHT":
            lista.append(c)
        elif c == "ENTRY":
            lista.append(c)
        elif c == "EXIT":
            lista.append(c)
        elif c == "OUTPUT_FILE":
            lista.append(c)
        elif c == "PERFECT":
            lista.append(c)
    if not len(lista) == 6:
        return "Error"
    return lista


def raise_equal_not_defined_error(file):
    for row in file:
        if not row[0] == "#":
            if "=" not in row and row:
                raise Equal_Not_Defined_Error(
                    "Invalid Config File! Not a atribution definition"
                )


def raise_key_not_exist(list_keys, ideal_list_keys):
    for c in list_keys:
        if c not in ideal_list_keys:
            print(c)
            raise Key_Not_Exist_Error("Invalid Config File!")


def raise_keys_configs_error(lst_keys):
    checker = checker_configs_keys(lst_keys)
    if checker == "Error":
        raise Keys_Configs_Error("Invalid Config File! Keys not well defined")


def raise_value_configs_error(lst_values):
    for c in lst_values:
        c = c.replace(" ", "")
        if c == "":
            raise Value_Configs_Error("Invalid Config File!"
                                      "Values not well defined")


def order_values(lst_keys, lst_values):
    list_values_order = []

    width_index = lst_keys.index("WIDTH")
    list_values_order.append(lst_values[width_index])

    height_index = lst_keys.index("HEIGHT")
    list_values_order.append(lst_values[height_index])

    entry_index = lst_keys.index("ENTRY")
    list_values_order.append(lst_values[entry_index])

    exit_index = lst_keys.index("EXIT")
    list_values_order.append(lst_values[exit_index])

    output_file_index = lst_keys.index("OUTPUT_FILE")
    list_values_order.append(lst_values[output_file_index])

    perfect_index = lst_keys.index("PERFECT")
    list_values_order.append(lst_values[perfect_index])

    return list_values_order


def pass_keys_and_values(file, lst_keys, lst_values):
    for row in file:
        if not row[0] == "#":
            array = row.split("=", maxsplit=1)
            lst_keys.append(array[0].upper().replace(" ", ""))
            lst_values.append(array[1].replace(" ", ""))


def parser_to_class(file):
    lst_values = []
    lst_keys = []
    keys_ideal = ["WIDTH", "HEIGHT", "ENTRY", "EXIT", "OUTPUT_FILE", "PERFECT"]
    try:
        raise_equal_not_defined_error(file)
    except Equal_Not_Defined_Error as e:
        print(e)
        return "Error"
    file.seek(0)
    pass_keys_and_values(file, lst_keys, lst_values)
    try:
        raise_key_not_exist(lst_keys, keys_ideal)
        raise_keys_configs_error(lst_keys)
        raise_value_configs_error(lst_values)
    except (Key_Not_Exist_Error, Keys_Configs_Error, Value_Configs_Error) as e:
        print(e)
        return "Error"
    lst_values = order_values(lst_keys, lst_values)
    inst = Config(lst_values)
    return inst
