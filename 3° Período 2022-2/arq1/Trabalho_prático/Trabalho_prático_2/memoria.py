from functions import lerArquivoBinario
from interpretador import interpretarInstrucao

class MemoriaMIPS:

    def __init__ (self, quantidadeInstrucoes: int) -> None:
        self.memoriaDados = [0] * (2**16)  # 64k endereços de 4 bytes cada
        self.memoriaInstrucao = [] * quantidadeInstrucoes

    def escritaInstrucoesMemoria (self) -> None:
        listaInstrucoes = lerArquivoBinario()
        for instrucaoTexto in listaInstrucoes:
            instrucaoEmBinario = interpretarInstrucao(instrucaoTexto)

            # Se a instrucao for um label, ela irá guardar a posição da memoria
            # da proxima instrução, que é obtida pelo len(memoriaInstrucao) + 1
            if instrucaoEmBinario == "Label":
                self.memoriaInstrucao.append(len(self.memoriaInstrucao) + 1)
            
            else:
                self.memoriaInstrucao.append(instrucaoEmBinario)

    def escritaMemoria (self, endereco: int, palavra: int) -> None:
        self.memoriaDados[endereco] = (palavra >> 24) & 0xff
        self.memoriaDados[endereco+1] = (palavra >> 16) & 0xff
        self.memoriaDados[endereco+2] = (palavra >> 8) & 0xff
        self.memoriaDados[endereco+3] = palavra & 0xff

    def leituraMemoria(self, endereco: int) -> int:
        palavra = (self.memoriaDados[endereco] << 24) | (self.memoriaDados[endereco+1] << 16) | \
            (self.memoriaDados[endereco+2] << 8) | self.memoriaDados[endereco+3]
        return palavra
    
    def lerInstrucao (self, valorPC: int) -> str:
        instrucao = self.memoriaInstrucao[valorPC // 4]

        

        return instrucao


class BancoRegistradores:
    def __init__(self) -> None:
        self.registradores = [0] * 32
        self.registradores[0] = 0