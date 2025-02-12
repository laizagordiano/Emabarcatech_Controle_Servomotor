# Controle de Servomotor com Raspberry Pi Pico W

Este projeto simula o controle do ângulo de um servomotor micro padrão utilizando o Raspberry Pi Pico W e o módulo PWM (Pulse Width Modulation), com a ferramenta Pico SDK. A simulação é realizada no simulador de eletrônica online Wokwi, e o sistema é projetado para controlar o movimento de um servomotor micro servo em ângulos específicos. Este exercício abrange o uso de PWM para controlar a posição do motor e a integração de LEDs RGB para observar comportamentos adicionais.

## Componentes Utilizados:
1. **Microcontrolador:** Raspberry Pi Pico W
2. **Servomotor:** Motor micro servo padrão (simulado no Wokwi)
3. **LED RGB:** Controlado pela GPIO 12 do Raspberry Pi Pico W

## Objetivos e Tarefas:

### 1. Definição de Frequência PWM
- **Requisito:** Configurar a GPIO 22 para gerar uma frequência de PWM de aproximadamente **50Hz** (período de 20ms).
- **Objetivo:** Definir a frequência do PWM para controlar o servomotor.

### 2. Ajuste do Ciclo de Trabalho (Duty Cycle)
- **Ciclo de Trabalho (Duty Cycle):**
  - Para **180 graus:** Ajustar o ciclo ativo para **2.400μs** (ciclo de trabalho de 0,12%).
  - **Pausa:** Manter o servomotor na posição de 180 graus por 5 segundos.
  - Para **90 graus:** Ajustar o ciclo ativo para **1.470μs** (ciclo de trabalho de 0,0735%).
  - **Pausa:** Manter o servomotor na posição de 90 graus por 5 segundos.
  - Para **0 graus:** Ajustar o ciclo ativo para **500μs** (ciclo de trabalho de 0,025%).
  - **Pausa:** Manter o servomotor na posição de 0 graus por 5 segundos.

### 3. Movimentação Suave entre 0 e 180 Graus
- **Requisito:** Criar uma rotina que movimente periodicamente o braço do servomotor entre **0 e 180 graus**.
- **Detalhe:** A movimentação deve ser suave, com incremento de **±5μs** no ciclo ativo a cada ajuste e um atraso de **10ms** entre cada movimento.

### 4. Experimento com LED RGB
- **Requisito:** Implementar um experimento usando o LED RGB na GPIO 12 e observar o comportamento da iluminação do LED.
- **Objetivo:** Analisar como o LED RGB responde às alterações de ciclo de trabalho e comportamento do servomotor.

## Passos Implementados:

### 1. Configuração do PWM
- O módulo PWM foi configurado para gerar o sinal necessário na GPIO 22, com a frequência ajustada para 50Hz, conforme especificado. O ciclo de trabalho foi definido para as posições de 0, 90 e 180 graus para controlar a posição do servomotor.

### 2. Rotina de Movimentação Suave
- Foi implementada uma rotina que movimenta o servomotor suavemente entre os ângulos de 0 e 180 graus. A cada ciclo, o ciclo de trabalho foi incrementado em **±5μs**, com um atraso de **10ms** para garantir uma transição suave e controlada.

### 3. Experimento com LED RGB
- O controle do LED RGB foi implementado na GPIO 12. O comportamento da iluminação do LED foi observado durante a movimentação do servomotor, permitindo analisar como a variação do ciclo de trabalho afeta o comportamento visual do LED RGB.

## Requisitos Técnicos:
- **Ambiente de Desenvolvimento:** VS Code
- **Linguagem de Programação:** C
- **Kit de Desenvolvimento:** Pico SDK
- **Simulador:** Wokwi (integrado ao VS Code)

## Link para Vídeo de Demonstração:
- [Clique aqui para assistir ao vídeo associado à simulação](https://drive.google.com/file/d/1bGVkbbWssJk0GG839TQ5k9uSJ8C0Eaag/view?usp=sharing)

----
**Autora:** Laiza Gordiano


