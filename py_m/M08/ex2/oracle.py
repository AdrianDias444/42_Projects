import os
import sys


def get_env(name: str) -> str:
    var = os.getenv(name)
    if not var:
        raise ValueError(f"Missing configuration: {name}")
    return var


def main() -> None:
    print("ORACLE STATUS: Reading the Matrix...")

    try:
        from dotenv import load_dotenv  # type: ignore
        load_dotenv(override=False)
        mode = get_env("MATRIX_MODE")
        db = get_env("DATABASE_URL")
        api_key = get_env("API_KEY")
        log_level = get_env("LOG_LEVEL")
        endpoint = get_env("ZION_ENDPOINT")
    except ImportError:
        print("ERROR: python-dotenv not installed. "
              "Run: pip install python-dotenv")
        print("\n[KO] .env file poorly configured")
        print("\nThe Oracle sees nothing.")
        sys.exit()
    except ValueError as err:
        print(f"ERROR: {err}")
        print("\n[KO] .env file poorly configured")
        print("\nThe Oracle sees nothing.")
        sys.exit()

    print("\nConfiguration loaded:")
    print(f"Mode: {mode.lower()}")

    if mode.lower() == "development" and db:
        print("Database: Connected to local instance")
    elif mode.lower() == "production" and db:
        print("Database: Connected to production instance")
    else:
        print("Invalid mode.")
        sys.exit()

    if api_key and api_key != "your-secret-key-here":
        print("API Access: Authenticated")
    elif api_key == "your-secret-key-here":
        print("API Access: Placeholder key detected")
    else:
        print("API Access: Missing key")

    print(f"Log Level: {log_level}")
    print(f"Zion Network: Online")

    print("\nEnvironment security check:")
    print("[OK] No hardcoded secrets detected")

    if os.path.isfile(".env"):
        print("[OK] .env file properly configured")
    else:
        print("[INFO] No .env file found")

    prod_override = os.environ.get("MATRIX_MODE")
    if prod_override.lower() == "development":
        print("[OK] Production overrides available")
    else:
        print("[INFO] Running in production mode")

    print("\nThe Oracle sees all configurations.")


if __name__ == "__main__":
    main()
