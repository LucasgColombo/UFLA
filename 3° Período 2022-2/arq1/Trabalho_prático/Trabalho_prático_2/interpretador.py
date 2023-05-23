# Definindo dicionario de operações
dicionarioOperacaoTipo = {
    'add': 'R',
    'sub': 'R',
    'and': 'R',
    'or': 'R',
    'nor': 'R',
    'mult': 'R',
    'sll': 'R',
    'slr': 'R',
    'mul': 'R',
    'div': 'R',
    'jr': 'R',
    'addi': 'I',
    'lw': 'I',
    'sw': 'I',
    'bge': 'I',
    'slt': 'I',
    'beq': 'I',
    'bne': 'I',
    'j': 'J',
    'jal': 'J'
}

dicionarioOpcode = {
    'R': '000000',
    'J': {
        'j' : '000010',
        'jal': '000011'
    },
    'I': {
        'beq': '000100',
        'bne': '000101',
        'addi': '001000',
        'bge': '000001',
        'lw': '100011',
        'slt': '101010',
        'sw': '101011'
    }
}

# Mapeamento das instruções tipo R para funct
dicionarioFunct = {
    'add': '100000',
    'sub': '100010',
    'and': '100100',
    'or': '100101',
    'nor': '100111',
    'mult': '011000',
    'sll': '000000',
    'slr': '000010',
    'mul': '011100',
    'div': '011010',
    'jr': '001000'
}

# Mapeamento das instruções tipo I para rt
dicionarioRt = {
    'addi': '000000',
    'lw': '100011',
    'sw': '101011',
    'bge': '000001',
    'slt': '101010',
    'beq': '000100',
    'bne': '000101'
}

# Mapeamento das instruções tipo J para opcode
dicionarioJ = {
    'jump': '000010',
    'jal': '000011'
}



def interpretarInstrucao(instrucao: str) -> str:
    # Removendo as vírgulas e o quebra de linha no final
    # e separado cada bloco da instrucao
    instrucao = instrucao.replace(",", "")
    instrucao = instrucao.replace("\n","")
    if instrucao[-1] == ':':
        return 'Label'
    partes = instrucao.split()
    operador = partes[0]


    tipoInstrucao = dicionarioOperacaoTipo[operador]
        
    if tipoInstrucao == "R":
        opCode = dicionarioOpcode['R']
        funct = dicionarioFunct[operador]
        rs = format(int(partes[2][1:]), 'b').zfill(5)
        rt = format(int(partes[3][1:]), 'b').zfill(5)
        rd = format(int(partes[1][1:]), 'b').zfill(5)
        shamt = '00000' if operador != "slr" and operador != "sll" else format (int(partes[3]), 'b').zfill(5)
        instrucaoBinaria = opCode + rs + rt + rd + shamt + funct

        return instrucaoBinaria
    
    elif tipoInstrucao == "I":
        opCode = dicionarioOpcode['I'][operador]
        rt = format(int(partes[1][1:]), 'b').zfill(5)
        rs = format(int(partes[2][1:]), 'b').zfill(5)
        immediate = format(int(partes[3]), 'b').zfill(16)
        
        instrucaoBinaria = opCode + rs + rt + immediate
        return instrucaoBinaria
    
    elif tipoInstrucao == "J": 
        opCode = dicionarioOpcode['J'][operador]
        endereco = format(int(partes[1]), 'b').zfill(26)
        instrucaoBinaria = opCode + endereco
        return instrucaoBinaria
    
    else:
        return 'Instrução inválida'
