# 🧪 Preparação para o Exame 03 da 42

Este repositório contém a minha preparação prática para o **Exame 03 da Escola 42**, focada nas funções `ft_printf` e `get_next_line`, que são dois exercícios muito frequentes.

---

## 📌 Objetivo

O objetivo foi treinar implementações simples e funcionais.

---

## 🖨️ `ft_printf`

### ✔️ Formatos suportados:
- `%s` → strings  
- `%d` → inteiros (com sinal)  
- `%x` → inteiros não assinados em hexadecimal (minúsculo)  

### 🧠 Como funciona:
- Uso de `va_list` para tratar os argumentos variádicos.
- Cada `%` é seguido por uma letra que indica o tipo.
- Funções auxiliares:
  - `putstr`: imprime strings (ou `(null)` se for `NULL`).
  - `putnbr`: imprime números recursivamente.
- A função percorre a string e imprime caractere a caractere ou formata quando encontra `%`.

### 📎 Exemplo:
```c
ft_printf("Olá %s, número: %d, hex: %x\n", "mundo", 42, 42);
```
## 📄 get_next_line
🧠 Objetivo:
Ler ficheiros linha a linha, mesmo que a linha seja maior que o BUFFER_SIZE.

⚙️ Como funciona:
Usa uma variável estática stash para guardar o que foi lido e ainda não devolvido.

Lê do fd até encontrar \n ou EOF.

Extrai a linha com rd_ln.

Atualiza a stash com up_ln.

Junta buffers com ft_strjoin e usa ft_strchr para encontrar \n.

🚨 Cuidados:
Liberta bem a memória (evita leaks).

Verifica se read() falha.

### 📎 Exemplo:
Trata ficheiros vazios e NULL.
```c
int fd = open("ficheiro.txt", O_RDONLY);
char *linha;
while ((linha = get_next_line(fd)))
{
    printf("%s", linha);
    free(linha);
}
close(fd);
```

## 🧠 Notas Pessoais
O mais importante no exame é ter código que compila, não dá leaks e faz o que pedem.

Não precisas de fazer um printf completo — só %s, %d e %x.

No get_next_line, stash é a alma da função. Cuida bem da gestão de memória dela.

Testei bastante com ficheiros pequenos e grandes para garantir que não quebra.

```c
cc -Wall -Wextra -Werror ft_printf.c
cc -Wall -Wextra -Werror get_next_line.c -D BUFFER_SIZE=42
```
## Author 👤
42 login: tfilipe-

GitHub: @TiagoDev88
