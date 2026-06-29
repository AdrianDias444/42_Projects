import sys
import importlib
import importlib.metadata

REQUIRED = {
    "pandas": "pandas",
    "numpy": "numpy",
    "matplotlib": "matplotlib",
}


def check_dependencies() -> dict[str, tuple[str | None, bool]]:
    status: dict[str, tuple[str | None, bool]] = {}
    for pkg_name, import_name in REQUIRED.items():
        try:
            _ = importlib.import_module(import_name)
            ver = importlib.metadata.version(pkg_name)
            status[pkg_name] = (ver, True)
        except ImportError:
            status[pkg_name] = (None, False)
    return status


def show_install_instructions() -> None:
    print("\nSome dependencies are missing. Install them with:\n")
    print("pip install -r requirements.txt")
    print("  or")
    print("poetry install")
    sys.exit(1)


def generate_data(n: int = 1000) -> tuple:
    import numpy as np
    a = np.random.normal(10, 2, n)
    b = np.random.normal(5, 1.5, n)
    c = np.random.exponential(3, n)
    return a, b, c


def analyse_data(a, b, c):
    import pandas as pd
    df = pd.DataFrame({"Stream A": a, "Stream B": b, "Stream C": c})
    print("\nMatrix data analysis (first 5 rows):")
    print(df.head())
    print("\nSummary statistics:")
    print(df.describe())
    return df


def plot_data(df) -> None:
    import matplotlib.pyplot as plt
    df.hist(bins=30, figsize=(10, 6))
    plt.suptitle("Matrix Stream Distributions")
    plt.savefig("matrix_analysis.png")
    plt.close()
    print("\nVisualization saved to matrix_analysis.png")


def compare_pip_poetry() -> None:
    print("\n--- Pip vs Poetry ---")
    print("pip:      uses requirements.txt, installs globally"
          "or in active venv.")
    print("Poetry:   uses pyproject.toml + poetry.lock, manages its own venv.")
    print("Both can be used for this project.\n")


def main() -> None:
    print("LOADING STATUS: Checking dependencies...\n")
    deps = check_dependencies()

    all_ok = True
    for name, (ver, installed) in deps.items():
        if installed:
            print(f"[OK] {name} ({ver}) ready")
        else:
            print(f"[MISSING] {name} not installed")
            all_ok = False

    if not all_ok:
        show_install_instructions()

    a, b, c = generate_data(1000)
    df = analyse_data(a, b, c)
    plot_data(df)

    compare_pip_poetry()
    print("Analysis complete!")


if __name__ == "__main__":
    main()
