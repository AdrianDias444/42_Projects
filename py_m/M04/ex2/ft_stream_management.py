#!/usr/bin/python3

import sys


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_stream_management.py <file>")
        sys.exit(1)

    filename = sys.argv[1]

    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    try:
        file_obj = open(filename, 'r')
        conteudo = file_obj.read()

        print("---")
        print(conteudo, end='')
        print("---")

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

        print("Enter new file name (or empty): ", end='')
        sys.stdout.flush()
        novo_nome = sys.stdin.readline().strip()

        if novo_nome == "":
            print("Not saving data.")
        else:
            print(f"Saving data to '{novo_nome}'")
            try:
                novo_arquivo = open(novo_nome, 'w')
                novo_arquivo.write(conteudo_transformado)
                novo_arquivo.close()
                print(f"Data saved in file '{novo_nome}'.")
            except (FileNotFoundError, PermissionError, IOError) as e:
                print(f"[STDERR] Error opening file '{novo_nome}': {e}", file=sys.stderr)
                print("Data not saved.")

    except FileNotFoundError:
        print(f"[STDERR] Error opening file '{filename}': "
              f"[Errno 2] No such file or directory: '{filename}'", file=sys.stderr)
        sys.exit(1)

    except PermissionError:
        print(f"[STDERR] Error opening file '{filename}': "
              f"[Errno 13] Permission denied: '{filename}'", file=sys.stderr)
        sys.exit(1)

    except IOError as e:
        print(f"[STDERR] Error opening file '{filename}': {e}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()