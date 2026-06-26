from .config import Config
from typing import Any


class EqualNotDefinedError(Exception):
    """
    Exception raised when a config line have no '=' assignment.
    """
    pass


class KeyNotExistError(Exception):
    """
    Exception raised when a config key is not in the expected keys list.
    """
    pass


class KeysConfigsError(Exception):
    """
    Exception raised when config keys are not the six mandatory.
    """
    pass


class ValueConfigsError(Exception):
    """
    Exception raised when config values are empty or full of spaces.
    """
    pass


def checker_configs_keys(lst_keys: list[str]) -> list[str] | str:
    """
    Filter and validate list keys against the expected.

    Args:
        lst_keys: List of key strings to check.

    Returns:
        List of valid uppercase keys if exactly 6 match, or "Error" string.
    """
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


def raise_equal_not_defined_error(file: str) -> None:
    """
    Raise EqualNotDefinedError if any non-comment line lacks '=' assignment.

    Args:
        file: File object to check.

    Raises:
        EqualNotDefinedError: If a line has no '=' and is not a comment.
    """
    for row in file:
        if row.strip() and not row.strip().startswith("#"):
            if "=" not in row:
                raise EqualNotDefinedError(
                    "Invalid Config File! Not a attribution definition")


def raise_key_not_exist(list_keys: list[str],
                        ideal_list_keys: list[str]) -> None:
    """
    Raise KeyNotExistError if any key is not in the ideal keys list.

    Args:
        list_keys: List of keys to validate.
        ideal_list_keys: List of allowed key strings.

    Raises:
        KeyNotExistError: If an invalid key is found.
    """
    for c in list_keys:
        if c not in ideal_list_keys:
            print(c)
            raise KeyNotExistError("Invalid Config File!")


def raise_keys_configs_error(lst_keys: list[str]) -> None:
    """
    Raise KeysConfigsError if config keys are not properly defined.

    Args:
        lst_keys: List of key strings to validate.

    Raises:
        KeysConfigsError: If keys do not match expected configuration.
    """
    checker = checker_configs_keys(lst_keys)
    if checker == "Error":
        raise KeysConfigsError("Invalid Config File! Keys not well defined")


def raise_value_configs_error(lst_values: list[str]) -> None:
    """
    Raise ValueConfigsError if any config value is empty.

    Args:
        lst_values: List of value strings to validate.

    Raises:
        ValueConfigsError: If any value is empty after removing spaces.
    """
    for c in lst_values:
        c = c.replace(" ", "")
        if c == "":
            raise ValueConfigsError("Invalid Config File!"
                                    "Values not well defined")


def order_values(lst_keys: list[str], lst_values: list[str]) -> list[str]:
    """
    Order config values according to the expected key sequence.

    Args:
        lst_keys: List of config keys.
        lst_values: List of corresponding config values.

    Returns:
        List of values ordered as: width, height,
        entry, exit, output_file, perfect.
    """
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


def pass_keys_and_values(file: str, lst_keys: list[str],
                         lst_values: list[str]) -> None:
    """
    Extract keys and values from a config file passing to their
    respective list, ignoring comment lines.

    Args:
        file: File object to read from.
        lst_keys: List to populate with extracted keys.
        lst_values: List to populate with extracted values.
    """
    for row in file:

        if not row.strip() or row.strip().startswith("#"):
            continue

        if not row[0] == "#":
            array = row.split("=", maxsplit=1)
            lst_keys.append(array[0].upper().replace(" ", ""))
            lst_values.append(array[1].replace(" ", ""))


def parser_to_class(file: Any) -> Config:
    """
    Parse a config file and return a validated Config object.

    Args:
        file: File object containing maze configuration.

    Returns:
        Config object if parsing succeeds,
        or "Error" string if validation fails.
    """
    lst_values: list[str] = []
    lst_keys: list[str] = []
    keys_ideal = ["WIDTH", "HEIGHT", "ENTRY", "EXIT", "OUTPUT_FILE", "PERFECT"]
    with open(file, "r") as file:
        try:
            raise_equal_not_defined_error(file)
        except EqualNotDefinedError as e:
            print(e)
            exit()
        file.seek(0)
        pass_keys_and_values(file, lst_keys, lst_values)
        try:
            raise_key_not_exist(lst_keys, keys_ideal)
            raise_keys_configs_error(lst_keys)
            raise_value_configs_error(lst_values)
        except (KeyNotExistError, KeysConfigsError,
                ValueConfigsError) as e:
            print(e)
            exit()
        lst_values = order_values(lst_keys, lst_values)
        inst = Config(lst_values)
        return inst
