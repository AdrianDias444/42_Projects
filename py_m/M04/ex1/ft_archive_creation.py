#!/usr/bin/python3

import sys


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_archive_creation.py <file>")
        sys.exit(1)

    filename = sys.argv[1]

    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    try:
        file_obj = open(filename, 'r')
        conteudo = file_obj.read()

        print("---\n")
        print(conteudo, end='')
        print("\n---\n")

        file_obj.close()
        print(f"File '{filename}' closed.")

        linhas = conteudo.split("\n")
        conteudo_transformado = ""
        for linha in linhas:
            nova_linha = linha + "#\n"
            conteudo_transformado += nova_linha

        print("Transform data:")
        print("---")
        print(conteudo_transformado, end='')
        print("---")

        novo_nome = input("Enter new file name (or empty): ")

        if novo_nome.strip() == "":
            print("Not saving data.")
        else:
            print(f"Saving data to '{novo_nome}'")
            novo_arquivo = open(novo_nome, 'w')
            novo_arquivo.write(conteudo_transformado)
            novo_arquivo.close()
            print(f"Data saved in file '{novo_nome}'.")

    except FileNotFoundError as e:
        print(f"Error opening file '{filename}': {e}")
        sys.exit(1)

    except PermissionError as e:
        print(f"Error opening file '{filename}': {e}")
        sys.exit(1)

    except IOError as e:
        print(f"Error opening file '{filename}': {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()
