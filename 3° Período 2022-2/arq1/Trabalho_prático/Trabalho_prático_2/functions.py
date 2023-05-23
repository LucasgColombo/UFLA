# Coletar dados do usuário
def digitarDados() -> str:
    entrada = input("Digite a instrucao: ")
    instrucao = entrada.split()
    instrucao = " ".join(instrucao)
    return instrucao

# -----+------+-----+-----+------+-----+-----+------+-----+-----

# Gerar o arquivo binário após a insterpretação
def gerarArquivoBinario(dados: str) -> None:
    with open("instrucoes.bin", "ab") as arquivoBinario:
        dados += "\n"
        arquivoBinario.write(dados.encode())

# -----+------+-----+-----+------+-----+-----+------+-----+-----

def lerArquivoBinario() -> list:
    instrucoes = []
    with open("instrucoes.bin", "rb") as arquivoBinario:
        instrucoesBinarias = arquivoBinario.readline()
        while instrucoesBinarias:
            instrucoes.append(instrucoesBinarias.decode())
            instrucoesBinarias = arquivoBinario.readline()
    # Esta retornando um vetor com [add $10 ...]
    return instrucoes

