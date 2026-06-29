import os
from sys import exit
from dotenv import load_dotenv


def get_env(name: str) -> str:
    var = os.getenv(name)
    if not var:
        raise ValueError("Configuration not found!")
    return var


def main():
    load_dotenv()
    try:
        mode = get_env("MATRIX_MODE")
        api_access = get_env("API_KEY")
        log_level = get_env("LOG_LEVEL")
    except ValueError as e:
        print(e)
        exit(-1)

    print(mode)
    print(api_access)
    print(log_level)


if __name__ == "__main__":
    main()
